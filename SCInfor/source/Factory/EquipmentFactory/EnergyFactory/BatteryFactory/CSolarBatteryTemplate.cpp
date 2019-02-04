//  __________________________________________________
// | CSolarBatteryTemplate.cpp - class implementation |
// | Jack Flower - May 2014                           |
// |__________________________________________________|
//

#include "CSolarBatteryTemplate.h"

namespace factory
{
	RTTI_IMPL(CSolarBatteryTemplate, CBatteryTemplate);

	//Konstruktor
	CSolarBatteryTemplate::CSolarBatteryTemplate(void)
	:
		CBatteryTemplate	(),//konstruktor klasy bazowej
		m_templ_decline		(0.0f)
	{
	}

	//Destruktor
	CSolarBatteryTemplate::~CSolarBatteryTemplate(void)
	{
		//CBatteryTemplate	not edit
		m_templ_decline		= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSolarBatteryTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CSolarBatteryTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CSolarBatteryTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CSolarBatteryTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CBatteryTemplate
		if (!CBatteryTemplate::Load(xml)) return false;

		//³adowanie konfiguracji solarbattery
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "solar_battery_config"))
		{
			m_templ_decline = xml.GetFloat(node, "decline");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CSolarBattery
	CSolarBattery* CSolarBatteryTemplate::Create(std::wstring id)
	{
		CSolarBattery* solar_battery = gPhysicalManager.CreateSolarBattery(id);
		Fill(solar_battery);
		return solar_battery;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CSolarBatteryTemplate::Fill(CSolarBattery *p_solar_battery)
	{
		CBatteryTemplate::Fill(p_solar_battery);
		if(p_solar_battery)
		{
			p_solar_battery->setDecline(m_templ_decline);
		}
	}
}//namespace factory
