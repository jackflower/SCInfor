//  ____________________________________________
// | BatteryTemplate.cpp - class implementation |
// | Jack Flower - May 2014                     |
// |____________________________________________|
//

#include "BatteryTemplate.h"


namespace factory
{
	RTTI_IMPL(BatteryTemplate, ActorTemplate);

	//Konstruktor
	BatteryTemplate::BatteryTemplate()
	:
		ActorTemplate (),//konstruktor klasy bazowej
		m_templ_battery_name (""),
		m_templ_capacity (0.0f),
		m_templ_factory_capacity (0.0f),
		m_templ_particle_energy (0.0f),
		m_templ_battery_regeneration_duration(0.0f)
	{
	}

	//Destruktor
	BatteryTemplate::~BatteryTemplate()
	{
		//ActorTemplate
		m_templ_battery_name = "";
		m_templ_capacity = 0.0f;
		m_templ_factory_capacity = 0.0f;
		m_templ_particle_energy = 0.0f;
		m_templ_battery_regeneration_duration = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string BatteryTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void BatteryTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool BatteryTemplate::load(const std::string &name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool BatteryTemplate::load(Xml &xml)
	{
		//ładowanie danych klasy bazowej Actor
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie konfiguracji battery
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "battery_config"))
		{
			m_templ_battery_name = xml.getString(node, "battery_name");
			m_templ_capacity = xml.getFloat(node, "capacity");
			m_templ_factory_capacity = xml.getFloat(node, "factory_capacity");
			m_templ_particle_energy = xml.getFloat(node, "particle_energy");
			m_templ_battery_regeneration_duration = xml.getFloat(node, "battery_regeneration_duration");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Battery
	Battery* BatteryTemplate::create(std::wstring id)
	{
		Battery *battery = gPhysicalManager.createBattery(id);
		fill(battery);
		return battery;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void BatteryTemplate::fill(Battery *p_battery)
	{
		ActorTemplate::fill(p_battery);
		
		if(p_battery)
		{
			p_battery->setBatteryName(m_templ_battery_name);
			p_battery->setCapacity(m_templ_capacity);
			p_battery->setFactoryCapacity(m_templ_factory_capacity);
			p_battery->setParticleEnergy(m_templ_particle_energy);
			p_battery->setBatteryRegenerationDuration(m_templ_battery_regeneration_duration);
		}
	}
}//namespace factory
