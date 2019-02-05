//  ______________________________________________
// | CEngineTemplate.cpp - class implementation   |
// | Jack Flower - December 2013                  |
// |______________________________________________|
//

#include "CEngineTemplate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../ResourceManager/CResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(CEngineTemplate, CActorTemplate);

	//Konstruktor
	CEngineTemplate::CEngineTemplate(void)
	:
		CActorTemplate							(),//konstruktor klasy bazowej
		m_templ_engine_name						(),
		m_templ_fueltank_data					(),
		p_templ_fuel_tank						(NULL),
		m_templ_percentage_reserve_fuel			(0.0f),
		m_templ_fuel_consumption				(0.0f),
		m_templ_fuel_consumption_move			(0.0f),
		m_templ_tank_time_delayed				(0.0f),
		m_templ_fuel_empty_message				(false),
		m_templ_engine_run						(false),
		m_templ_engine_rotation_speed			(0.0f),
		m_templ_regeneration_time				(0.0f)
	{
	}

	//Destruktor
	CEngineTemplate::~CEngineTemplate(void)
	{
		//CActorTemplate						not edit
		m_templ_engine_name						= "";
		//m_templ_fueltank_data					not edit
		p_templ_fuel_tank						= NULL;
		m_templ_percentage_reserve_fuel			= 0.0f;
		m_templ_fuel_consumption				= 0.0f;
		m_templ_fuel_consumption_move			= 0.0f;
		m_templ_tank_time_delayed				= 0.0f;
		m_templ_fuel_empty_message				= false;
		m_templ_engine_run						= false;
		m_templ_engine_rotation_speed			= 0.0f;
		m_templ_regeneration_time				= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEngineTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CEngineTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CEngineTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CEngineTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie wartoœci konfiguracji engine
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "engine_config"))
		{
			m_templ_engine_name = xml.GetString(node, "engine_name");
			m_templ_fueltank_data.setUseEquipment(xml.GetBool(node, "use_fueltank"));
			m_templ_percentage_reserve_fuel = xml.GetFloat(node, "percentage_reserve_fuel");
			m_templ_fuel_consumption = xml.GetFloat(node, "fuel_consumption");
			m_templ_fuel_consumption_move = xml.GetFloat(node, "fuel_consumption_move");
			m_templ_tank_time_delayed = xml.GetFloat(node, "tank_time_delayed");
			m_templ_fuel_empty_message = xml.GetBool(node, "fuel_empty_message");
			m_templ_engine_run = xml.GetBool(node, "engine_run");
			m_templ_regeneration_time = xml.GetFloat(node, "regeneration_time");
			m_templ_engine_rotation_speed = xml.GetFloat(node, "engine_rotation_speed");
		}

		//³adowanie nazwy pliku z konfiguracj¹ zbiornika paliwa
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "engine_fueltank_config"))
		{
			//nazwa pliku z konfiguracj¹ fueltank
			std::string fueltank_filename_tmp = xml.GetString(node, "fueltank_filename");
			//emitery dla obiektu klasy FuelTank
			m_templ_fueltank_data.setEmiter(xml.GetFloat(node, "fuel_tank_emiter_x"), xml.GetFloat(node, "fuel_tank_emiter_y"));

			if(m_templ_fueltank_data.getUseEquipment())
				p_templ_fuel_tank = (CFuelTankTemplate*)gResourceManager.GetPhysicalTemplate(fueltank_filename_tmp);
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Engine
	Engine* CEngineTemplate::Create(std::wstring id)
	{
		Engine* engine = gPhysicalManager.CreateEngine(id);
		Fill(engine);
		return engine;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CEngineTemplate::Fill(Engine *p_engine)
	{
		if(p_engine)
		{
			CActorTemplate::Fill(p_engine);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_engine->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetEngineBodyDefaultAnim()!= NULL)
					p_engine->SetAnimationBody(p_templ_animations->GetEngineBodyDefaultAnim());

				//head
				if (p_templ_animations->GetEngineHeadDefaultAnim()!= NULL)
					p_engine->SetAnimationHead(p_templ_animations->GetEngineHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			p_engine->setEngineName(m_templ_engine_name);
			p_engine->setUseFuelTank(m_templ_fueltank_data.getUseEquipment());
			p_engine->setFuelTankTransformed(m_templ_fueltank_data.getTransformed());
			p_engine->setPercentageReserveFuel(m_templ_percentage_reserve_fuel);
			p_engine->setFuelConsumption(m_templ_fuel_consumption);
			p_engine->setFuelConsumptionMove(m_templ_fuel_consumption_move);
			p_engine->setTankTimeDelayed(m_templ_tank_time_delayed);
			p_engine->setFuelEmptyMessage(m_templ_fuel_empty_message);
			p_engine->setRunEngine(m_templ_engine_run);
			p_engine->setEngineRegenerationTime(m_templ_regeneration_time);
			p_engine->setEngineRotationSpeed(m_templ_engine_rotation_speed);

			//jeœli obiekt posiada fueltank (zbiornika paliwa)
			if (m_templ_fueltank_data.getUseEquipment())
			{
				if(p_engine)
				{
					//pobieramy sk³adow¹ fueltank i wzorzec wype³nia wskaŸnik danymi
					p_engine->setFuelTank(p_templ_fuel_tank->Create(L""));
					//przekazanie wskaŸnikowi na klasê FuelTank informacji o wzorcu
					p_engine->getFuelTank()->SetTemplate(p_templ_fuel_tank);
					//decorator
					p_engine->getFuelTank()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
