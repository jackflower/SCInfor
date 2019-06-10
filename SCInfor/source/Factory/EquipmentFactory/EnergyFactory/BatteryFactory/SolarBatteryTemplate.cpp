//  __________________________________________________
// | SolarBatteryTemplate.cpp - class implementation |
// | Jack Flower - May 2014                           |
// |__________________________________________________|
//

#include "SolarBatteryTemplate.h"

namespace factory
{
	RTTI_IMPL(SolarBatteryTemplate, BatteryTemplate);

	//Konstruktor
	SolarBatteryTemplate::SolarBatteryTemplate()
	:
		BatteryTemplate{},//konstruktor klasy bazowej
		m_templ_decline{ 0.0f }
	{
	}

	//Destruktor
	SolarBatteryTemplate::~SolarBatteryTemplate()
	{
		//~BatteryTemplate()
		m_templ_decline = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string SolarBatteryTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void SolarBatteryTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool SolarBatteryTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool SolarBatteryTemplate::load(Xml & xml)
	{
		//ładowanie danych klasy bazowej BatteryTemplate
		if (!BatteryTemplate::load(xml)) return false;

		//ładowanie konfiguracji solarbattery
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "solar_battery_config"))
		{
			m_templ_decline = xml.getFloat(node, "decline");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy SolarBattery
	SolarBattery *SolarBatteryTemplate::create(std::wstring id)
	{
		SolarBattery *solar_battery = gPhysicalManager.createSolarBattery(id);
		fill(solar_battery);
		return solar_battery;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void SolarBatteryTemplate::fill(SolarBattery *p_solar_battery)
	{
		BatteryTemplate::fill(p_solar_battery);
		if(p_solar_battery)
		{
			p_solar_battery->setDecline(m_templ_decline);
		}
	}
}//namespace factory
