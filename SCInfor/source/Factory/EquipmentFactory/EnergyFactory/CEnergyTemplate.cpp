//  ____________________________________________
// | CEnergyTemplate.cpp - class implementation |
// | Jack Flower - May 2014                     |
// |____________________________________________|
//

#include "CEnergyTemplate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../ResourceManager/CResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(CEnergyTemplate, CActorTemplate);

	//Konstruktor
	CEnergyTemplate::CEnergyTemplate(void)
	:
		CActorTemplate						(),//konstruktor klasy bazowej
		m_templ_energy_name					(""),
		m_templ_energytank_data				(),
		p_templ_energy_tank					(NULL),
		m_templ_battery_data				(),
		p_templ_battery						(NULL),
		m_templ_percentage_reserve_energy	(0.0f),
		m_templ_energy_time_delayed			(0.0f),
		m_templ_energy_empty_message		(false),
		m_templ_energy_regeneration			(0.0f),
		m_templ_regeneration_time			(0.0f),
		m_templ_energy_rotation_speed		(0.0f),
		m_templ_critical_duration			(0.0f),
		m_templ_damage_duration				(0.0f)
	{
	}

	//Destruktor
	CEnergyTemplate::~CEnergyTemplate(void)
	{
		//CActorTemplate					not edit
		m_templ_energy_name					= "";
		//m_templ_energytank_data			not edit
		p_templ_energy_tank					= NULL;
		//m_templ_battery_data				not edit
		p_templ_battery						= NULL;
		m_templ_percentage_reserve_energy	= 0.0f;
		m_templ_energy_time_delayed			= 0.0f;
		m_templ_energy_empty_message		= false;
		m_templ_energy_regeneration			= 0.0f;
		m_templ_regeneration_time			= 0.0f;
		m_templ_energy_rotation_speed		= 0.0f;
		m_templ_critical_duration			= 0.0f;
		m_templ_damage_duration				= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEnergyTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CEnergyTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CEnergyTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CEnergyTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie wartoœci konfiguracji energy
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

		//³adowanie nazwy pliku z konfiguracj¹ zbiornika paliwa
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "energy_tank_config"))
		{
			//flaga, czy obiekt posiada akumulator energii
			m_templ_energytank_data.setUseEquipment(xml.GetBool(node, "use_energytank"));

			//nazwa pliku z konfiguracj¹ fueltank
			std::string energytank_filename_tmp = xml.GetString(node, "energy_tank_filename");
			
			//emitery dla obiektu klasy EnergyTank
			m_templ_energytank_data.setEmiter(xml.GetFloat(node, "energytank_emiter_x"), xml.GetFloat(node, "energytank_emiter_y"));

			if(m_templ_energytank_data.getUseEquipment())
				p_templ_energy_tank = (CEnergyTankTemplate*)gResourceManager.GetPhysicalTemplate(energytank_filename_tmp);
		}

		//³adowanie konfiguracji battery
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "battery_config"))
		{
			//flaga, czy obiekt posiada bateriê
			m_templ_battery_data.setUseEquipment(xml.GetBool(node, "use_battery"));//dopisaæ do xml'a

			//nazwa pliku z konfiguracj¹ battery
			std::string battery_filename_tmp = xml.GetString(node, "battery_filename");

			//emitery dla obiektu klasy Battery (dopisaæ do pliku xml)
			m_templ_battery_data.setEmiter(xml.GetFloat(node, "battery_emiter_x"), xml.GetFloat(node, "battery_emiter_y"));

			if(m_templ_battery_data.getUseEquipment())
				p_templ_battery = (CBatteryTemplate*)gResourceManager.GetPhysicalTemplate(battery_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Engine
	Energy* CEnergyTemplate::Create(std::wstring id)
	{
		Energy* energy = gPhysicalManager.CreateEnergy(id);
		Fill(energy);
		return energy;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CEnergyTemplate::Fill(Energy *p_energy)
	{
		if(p_energy)
		{
			CActorTemplate::Fill(p_energy);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_energy->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetEnergyBodyDefaultAnim()!= NULL)
					p_energy->SetAnimationBody(p_templ_animations->GetEnergyBodyDefaultAnim());

				//head
				if (p_templ_animations->GetEnergyHeadDefaultAnim()!= NULL)
					p_energy->SetAnimationHead(p_templ_animations->GetEnergyHeadDefaultAnim());
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

			//jeœli obiekt posiada energytank (akumulator energii)
			if (m_templ_energytank_data.getUseEquipment())
			{
				if(p_energy)
				{
					//pobieramy sk³adow¹ fueltank i wzorzec wype³nia wskaŸnik danymi
					p_energy->setEnergyTank(p_templ_energy_tank->Create(L""));
					//przekazanie wskaŸnikowi na klasê EnergyTank informacji o wzorcu
					p_energy->getEnergyTank()->SetTemplate(p_templ_energy_tank);
					//decorator
					p_energy->getEnergyTank()->setSmoothing(true);
				}
			}

			//jeœli obiekt posiada bateriê
			if(m_templ_battery_data.getUseEquipment())
			{
				if(p_energy)
				{
					//pobieramy sk³adow¹ battery i wzorzec wype³nia wskaŸnik danymi
					p_energy->setBattery(p_templ_battery->Create(L""));
					//przekazanie wskaŸnikowi na klasê Battery informacji o wzorcu
					p_energy->getBattery()->SetTemplate(p_templ_battery);
					//decorator
					p_energy->getBattery()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
