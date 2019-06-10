//  _____________________________________________
// | EngineTemplate.cpp - class implementation   |
// | Jack Flower - December 2013                 |
// |_____________________________________________|
//

#include "EngineTemplate.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../ResourceManager/ResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(EngineTemplate, ActorTemplate);

	//Konstruktor
	EngineTemplate::EngineTemplate()
	:
		ActorTemplate{},//konstruktor klasy bazowej
		m_templ_engine_name{},
		m_templ_fueltank_data{},
		p_templ_fuel_tank{ NULL },
		m_templ_percentage_reserve_fuel{ 0.0f },
		m_templ_fuel_consumption{ 0.0f },
		m_templ_fuel_consumption_move{ 0.0f },
		m_templ_tank_time_delayed{ 0.0f },
		m_templ_fuel_empty_message{ false },
		m_templ_engine_run{ false },
		m_templ_engine_rotation_speed{ 0.0f },
		m_templ_regeneration_time{ 0.0f }
	{
	}

	//Destruktor
	EngineTemplate::~EngineTemplate()
	{
		//~ActorTemplate()
		m_templ_engine_name = "";
		m_templ_fueltank_data;
		p_templ_fuel_tank = NULL;
		m_templ_percentage_reserve_fuel = 0.0f;
		m_templ_fuel_consumption = 0.0f;
		m_templ_fuel_consumption_move = 0.0f;
		m_templ_tank_time_delayed = 0.0f;
		m_templ_fuel_empty_message = false;
		m_templ_engine_run = false;
		m_templ_engine_rotation_speed = 0.0f;
		m_templ_regeneration_time = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EngineTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void EngineTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool EngineTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool EngineTemplate::load(Xml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej ActorTemplate
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie wartości konfiguracji engine
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "engine_config"))
		{
			m_templ_engine_name = xml.getString(node, "engine_name");
			m_templ_fueltank_data.setUseEquipment(xml.getBool(node, "use_fueltank"));
			m_templ_percentage_reserve_fuel = xml.getFloat(node, "percentage_reserve_fuel");
			m_templ_fuel_consumption = xml.getFloat(node, "fuel_consumption");
			m_templ_fuel_consumption_move = xml.getFloat(node, "fuel_consumption_move");
			m_templ_tank_time_delayed = xml.getFloat(node, "tank_time_delayed");
			m_templ_fuel_empty_message = xml.getBool(node, "fuel_empty_message");
			m_templ_engine_run = xml.getBool(node, "engine_run");
			m_templ_regeneration_time = xml.getFloat(node, "regeneration_time");
			m_templ_engine_rotation_speed = xml.getFloat(node, "engine_rotation_speed");
		}

		//ładowanie nazwy pliku z konfiguracją zbiornika paliwa
		if (xml_node<>*	node = xml.getChild(xml.getRootNode(), "engine_fueltank_config"))
		{
			//nazwa pliku z konfiguracją fueltank
			std::string fueltank_filename_tmp = xml.getString(node, "fueltank_filename");
			//emitery dla obiektu klasy FuelTank
			m_templ_fueltank_data.setEmiter(xml.getFloat(node, "fuel_tank_emiter_x"), xml.getFloat(node, "fuel_tank_emiter_y"));

			if(m_templ_fueltank_data.getUseEquipment())
				p_templ_fuel_tank = (FuelTankTemplate*)gResourceManager.getPhysicalTemplate(fueltank_filename_tmp);
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Engine
	Engine *EngineTemplate::create(std::wstring id)
	{
		Engine *engine = gPhysicalManager.createEngine(id);
		fill(engine);
		return engine;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void EngineTemplate::fill(Engine *p_engine)
	{
		if(p_engine)
		{
			ActorTemplate::fill(p_engine);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_engine->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->getEngineBodyDefaultAnim()!= NULL)
					p_engine->setAnimationBody(p_templ_animations->getEngineBodyDefaultAnim());

				//head
				if (p_templ_animations->getEngineHeadDefaultAnim()!= NULL)
					p_engine->setAnimationHead(p_templ_animations->getEngineHeadDefaultAnim());
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

			//jeśli obiekt posiada fueltank (zbiornik paliwa)
			if (m_templ_fueltank_data.getUseEquipment())
			{
				if(p_engine)
				{
					//pobieramy składową fueltank i wzorzec wypełnia wskaźnik danymi
					p_engine->setFuelTank(p_templ_fuel_tank->create(L""));
					//przekazanie wskaźnikowi na klasę FuelTank informacji o wzorcu
					p_engine->getFuelTank()->setTemplate(p_templ_fuel_tank);
					//decorator
					p_engine->getFuelTank()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
