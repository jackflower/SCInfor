//  _____________________________________________
// | CBatteryTemplate.cpp - class implementation |
// | Jack Flower - May 2014                      |
// |_____________________________________________|
//

#include "CBatteryTemplate.h"


namespace factory
{
	RTTI_IMPL(CBatteryTemplate, CActorTemplate);

	//Konstruktor
	CBatteryTemplate::CBatteryTemplate(void)
	:
		CActorTemplate							(),//konstruktor klasy bazowej
		m_templ_battery_name					(""),
		m_templ_capacity						(0.0f),
		m_templ_factory_capacity				(0.0f),
		m_templ_particle_energy					(0.0f),
		m_templ_battery_regeneration_duration	(0.0f)
	{
	}

	//Destruktor
	CBatteryTemplate::~CBatteryTemplate(void)
	{
		//CActorTemplate						not edit
		m_templ_battery_name					= "";
		m_templ_capacity						= 0.0f;
		m_templ_factory_capacity				= 0.0f;
		m_templ_particle_energy					= 0.0f;
		m_templ_battery_regeneration_duration	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CBatteryTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CBatteryTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CBatteryTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CBatteryTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CActor
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie konfiguracji battery
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "battery_config"))
		{
			m_templ_battery_name = xml.GetString(node, "battery_name");
			m_templ_capacity = xml.GetFloat(node, "capacity");
			m_templ_factory_capacity = xml.GetFloat(node, "factory_capacity");
			m_templ_particle_energy = xml.GetFloat(node, "particle_energy");
			m_templ_battery_regeneration_duration = xml.GetFloat(node, "battery_regeneration_duration");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CBattery
	CBattery* CBatteryTemplate::Create(std::wstring id)
	{
		CBattery* battery = gPhysicalManager.CreateBattery(id);
		Fill(battery);
		return battery;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CBatteryTemplate::Fill(CBattery *p_battery)
	{
		CActorTemplate::Fill(p_battery);
		
		if(p_battery)
		{
			p_battery->SetBatteryName(m_templ_battery_name);
			p_battery->setCapacity(m_templ_capacity);
			p_battery->setFactoryCapacity(m_templ_factory_capacity);
			p_battery->setParticleEnergy(m_templ_particle_energy);
			p_battery->setBatteryRegenerationDuration(m_templ_battery_regeneration_duration);
		}
	}
}//namespace factory