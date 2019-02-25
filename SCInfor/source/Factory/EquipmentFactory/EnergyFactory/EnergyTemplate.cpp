//  ___________________________________________
// | EnergyTemplate.cpp - class implementation |
// | Jack Flower - May 2014                    |
// |___________________________________________|
//

#include "EnergyTemplate.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../ResourceManager/ResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(EnergyTemplate, ActorTemplate);

	//Konstruktor
	EnergyTemplate::EnergyTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_energy_name(""),
		m_templ_energytank_data(),
		p_templ_energy_tank(NULL),
		m_templ_battery_data(),
		p_templ_battery(NULL),
		m_templ_percentage_reserve_energy(0.0f),
		m_templ_energy_time_delayed(0.0f),
		m_templ_energy_empty_message(false),
		m_templ_energy_regeneration(0.0f),
		m_templ_regeneration_time(0.0f),
		m_templ_energy_rotation_speed(0.0f),
		m_templ_critical_duration(0.0f),
		m_templ_damage_duration(0.0f)
	{
	}

	//Destruktor
	EnergyTemplate::~EnergyTemplate()
	{
		//ActorTemplate
		m_templ_energy_name = "";
		//m_templ_energytank_data
		p_templ_energy_tank = NULL;
		//m_templ_battery_data
		p_templ_battery = NULL;
		m_templ_percentage_reserve_energy = 0.0f;
		m_templ_energy_time_delayed = 0.0f;
		m_templ_energy_empty_message = false;
		m_templ_energy_regeneration = 0.0f;
		m_templ_regeneration_time = 0.0f;
		m_templ_energy_rotation_speed = 0.0f;
		m_templ_critical_duration = 0.0f;
		m_templ_damage_duration = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EnergyTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void EnergyTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool EnergyTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool EnergyTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie wartości konfiguracji energy
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "energy_config"))
		{
			m_templ_energy_name = xml.GetString(node, "energy_name");
			m_templ_percentage_reserve_energy = xml.GetFloat(node, "percentage_reserve_energy");
			m_templ_energy_time_delayed = xml.GetFloat(node, "energy_time_delayed");
			m_templ_energy_empty_message = xml.GetBool(node, "energy_empty_message");
			m_templ_energy_regeneration = xml.GetFloat(node, "energy_regeneration");
			m_templ_regeneration_time = xml.GetFloat(node, "regeneration_time");
			m_templ_energy_rotation_speed = xml.GetFloat(node, "energy_rotation_speed");
			m_templ_critical_duration = xml.GetFloat(node, "critical_duration");
			m_templ_damage_duration = xml.GetFloat(node, "damage_duration");
		}

		//ładowanie nazwy pliku z konfiguracją zbiornika paliwa
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "energy_tank_config"))
		{
			//flaga, czy obiekt posiada akumulator energii
			m_templ_energytank_data.setUseEquipment(xml.GetBool(node, "use_energytank"));

			//nazwa pliku z konfiguracją fueltank
			std::string energytank_filename_tmp = xml.GetString(node, "energy_tank_filename");
			
			//emitery dla obiektu klasy EnergyTank
			m_templ_energytank_data.setEmiter(xml.GetFloat(node, "energytank_emiter_x"), xml.GetFloat(node, "energytank_emiter_y"));

			if(m_templ_energytank_data.getUseEquipment())
				p_templ_energy_tank = (EnergyTankTemplate*)gResourceManager.getPhysicalTemplate(energytank_filename_tmp);
		}

		//ładowanie konfiguracji battery
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "battery_config"))
		{
			//flaga, czy obiekt posiada baterię
			m_templ_battery_data.setUseEquipment(xml.GetBool(node, "use_battery"));//dopisać do xml'a

			//nazwa pliku z konfiguracją battery
			std::string battery_filename_tmp = xml.GetString(node, "battery_filename");

			//emitery dla obiektu klasy Battery (dopisać do pliku xml)
			m_templ_battery_data.setEmiter(xml.GetFloat(node, "battery_emiter_x"), xml.GetFloat(node, "battery_emiter_y"));

			if(m_templ_battery_data.getUseEquipment())
				p_templ_battery = (BatteryTemplate*)gResourceManager.getPhysicalTemplate(battery_filename_tmp);
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Engine
	Energy *EnergyTemplate::create(std::wstring id)
	{
		Energy *energy = gPhysicalManager.createEnergy(id);
		fill(energy);
		return energy;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void EnergyTemplate::fill(Energy *p_energy)
	{
		if(p_energy)
		{
			ActorTemplate::fill(p_energy);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_energy->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->getEnergyBodyDefaultAnim()!= NULL)
					p_energy->setAnimationBody(p_templ_animations->getEnergyBodyDefaultAnim());

				//head
				if (p_templ_animations->getEnergyHeadDefaultAnim()!= NULL)
					p_energy->setAnimationHead(p_templ_animations->getEnergyHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			p_energy->setEnergyName(m_templ_energy_name);
			p_energy->setUseEnergyTank(m_templ_energytank_data.getUseEquipment());
			p_energy->setEnergyTankTransformed(m_templ_energytank_data.getTransformed());
			p_energy->setPercentageReserveEnergy(m_templ_percentage_reserve_energy);
			p_energy->setEnergyTimeDelayed(m_templ_energy_time_delayed);
			p_energy->setEnergyEmptyMessage(m_templ_energy_empty_message);
			p_energy->setEnergyRegeneration(m_templ_energy_regeneration);
			p_energy->setEnergyRegenerationTime(m_templ_regeneration_time);
			p_energy->setEnergyRotationSpeed(m_templ_energy_rotation_speed);
			p_energy->setEnergyRotationSpeed(m_templ_energy_rotation_speed);
			p_energy->setUseBattery(m_templ_battery_data.getUseEquipment());
			p_energy->setCriticalDuration(m_templ_critical_duration);
			p_energy->setDamageDuration(m_templ_damage_duration);

			//jeśli obiekt posiada energytank (akumulator energii)
			if (m_templ_energytank_data.getUseEquipment())
			{
				if(p_energy)
				{
					//pobieramy składową fueltank i wzorzec wypełnia wskaźnik danymi
					p_energy->setEnergyTank(p_templ_energy_tank->create(L""));
					//przekazanie wskaźnikowi na klasę EnergyTank informacji o wzorcu
					p_energy->getEnergyTank()->setTemplate(p_templ_energy_tank);
					//decorator
					p_energy->getEnergyTank()->setSmoothing(true);
				}
			}

			//jeśli obiekt posiada baterię
			if(m_templ_battery_data.getUseEquipment())
			{
				if(p_energy)
				{
					//pobieramy składową battery i wzorzec wypełnia wskaźnik danymi
					p_energy->setBattery(p_templ_battery->create(L""));
					//przekazanie wskaźnikowi na klasę Battery informacji o wzorcu
					p_energy->getBattery()->setTemplate(p_templ_battery);
					//decorator
					p_energy->getBattery()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
