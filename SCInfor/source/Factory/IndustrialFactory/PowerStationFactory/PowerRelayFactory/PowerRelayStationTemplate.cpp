//  _____________________________________________________
// | PowerRelayStationTemplate.cpp - class implementaion |
// | Jack Flower - July 2015                             |
// |_____________________________________________________|
//

#include "PowerRelayStationTemplate.h"
#include "../../../../Rendering/Animations/AnimSet.h"
#include "../../../../ResourceManager/ResourceManager.h"
#include "../../../../Utilities/Random/CRandom.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(PowerRelayStationTemplate, RelayStationTemplate);

	//Konstruktor
	PowerRelayStationTemplate::PowerRelayStationTemplate()
	:
		RelayStationTemplate(),//konstruktor klasy bazowej
		m_templ_use_slots_rate(false),
		m_templ_powerstations_capacity(0),
		m_templ_state_time_range(0.0f, 0.0f),
		m_templ_rotation_speed_range(0.0f, 0.0f),
		m_templ_state_time(0.0f),
		m_templ_rotation_speed(0.0f),
		p_templ_slot_rate(NULL),
		p_templ_battery(NULL),
		m_templ_use_battery(false),
		m_templ_time_to_start(0.0f),
		m_templ_duration_disconnect(0.0f)
	{
	}

	//Destruktor wirtualny
	PowerRelayStationTemplate::~PowerRelayStationTemplate()
	{
		//RelayStationTemplate
		m_templ_use_slots_rate = false;
		m_templ_powerstations_capacity = 0;
		m_templ_state_time_range.first = 0.0f;
		m_templ_state_time_range.second = 0.0f;
		m_templ_rotation_speed_range.first = 0.0f;
		m_templ_rotation_speed_range.second	= 0.0f;
		m_templ_state_time = 0.0f;
		m_templ_rotation_speed = 0.0f;
		p_templ_slot_rate = NULL;
		p_templ_battery = NULL;
		m_templ_use_battery = false;
		m_templ_time_to_start = 0.0f;
		m_templ_duration_disconnect = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PowerRelayStationTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void PowerRelayStationTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool PowerRelayStationTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool PowerRelayStationTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy można załadować dane z klasy bazowej RelayStationTemplate
		if (!RelayStationTemplate::load(xml)) return false;

		//dane obiektu
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "power_relay_station_config"))
		{
			m_templ_powerstations_capacity = xml.GetInt(node, "powerstations_capacity");
			m_templ_state_time_range.first = xml.GetFloat(node, "state_time_range_first");
			m_templ_state_time_range.second = xml.GetFloat(node, "state_time_range_second");
			m_templ_rotation_speed_range.first = xml.GetFloat(node, "rotation_speed_range_first");
			m_templ_rotation_speed_range.second = xml.GetFloat(node, "rotation_speed_range_second");
			m_templ_time_to_start = xml.GetFloat(node, "time_to_start");
			m_templ_duration_disconnect = xml.GetFloat(node, "duration_disconnect");
		}

		//ładowanie modułu prezentacji slotów przekaźnika
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "slots_rate_data"))
		{
			//flaga, czy obiekt posiada moduł prezentacji stanu slotów
			m_templ_use_slots_rate = xml.GetBool(node, "use_slots_rate");
			//zapisuję do zmiennej nazwę pliku z konfiguracją modułu prezentacji stanu slotów
			std::string slots_rate_filename_tmp = xml.GetString(node, "slots_rate_filename");
			if (m_templ_use_slots_rate)
				p_templ_slot_rate = (SlotsRateTemplate*)gResourceManager.getPhysicalTemplate(slots_rate_filename_tmp);
		}

		//ładowanie modułu baterii slotów przekaźnika
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "battery_data"))
		{
			//flaga, czy obiekt posiada moduł prezentacji stanu slotów
			m_templ_use_battery = xml.GetBool(node, "use_battery");
			//zapisuję do zmiennej nazwę pliku z konfiguracją modułu prezentacji stanu slotów
			std::string battery_filename_tmp = xml.GetString(node, "battery_filename");
			if (m_templ_use_battery)
				p_templ_battery = (BatteryTemplate*)gResourceManager.getPhysicalTemplate(battery_filename_tmp);
		}


		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy PowerRelayStation
	PowerRelayStation *PowerRelayStationTemplate::create(std::wstring id)
	{
		PowerRelayStation *power_relay_station = gPhysicalManager.createPowerRelayStation(id);
		fill(power_relay_station);
		return power_relay_station;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void PowerRelayStationTemplate::fill(PowerRelayStation *p_power_relay_station)
	{
		if(p_power_relay_station)
		{
			RelayStationTemplate::fill(p_power_relay_station);

			//dane obiektu
			p_power_relay_station->setUseSlotsRate(m_templ_use_slots_rate);
			p_power_relay_station->setPowerstationsCapacity(m_templ_powerstations_capacity);
			p_power_relay_station->setStateTimeRange(m_templ_state_time_range);
			p_power_relay_station->setRotationSpeedRange(m_templ_rotation_speed_range);
			//losowanie czasu trwania stanu
			m_templ_state_time = gRandom.GetSingleton().Rndf(m_templ_state_time_range.first, m_templ_state_time_range.second);
			//losowanie prędkości i kierunku rotacji
			m_templ_rotation_speed = gRandom.GetSingleton().Rndf(m_templ_rotation_speed_range.first, m_templ_rotation_speed_range.second);
			p_power_relay_station->setStateTime(m_templ_state_time);
			p_power_relay_station->setRotationSpeed(m_templ_rotation_speed);
			p_power_relay_station->setTimeToStart(m_templ_time_to_start);
			p_power_relay_station->setDurationDisconnect(m_templ_duration_disconnect);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_templ_animations)
			{
				p_power_relay_station->setAnimSet(p_templ_animations);
				//body
				if (p_templ_animations->getPowerRelayStationBodyDefaultAnim()!= NULL)
					p_power_relay_station->setAnimationBody(p_templ_animations->getPowerRelayStationBodyDefaultAnim());
				//head
				if (p_templ_animations->getPowerRelayStationHeadDefaultAnim()!= NULL)
					p_power_relay_station->setAnimationHead(p_templ_animations->getPowerRelayStationHeadDefaultAnim());
			}
			
			//jeśli obiekt posiada moduł prezentacji stanu slotów
			if (m_templ_use_slots_rate)
			{
				if (p_templ_slot_rate)
				{
					//pobieramy składową moduł prezentacji stanu slotów i wzorzec wypełnia wskaźnik danymi
					p_power_relay_station->setSlotsRate(p_templ_slot_rate->create(L""));
					//przekazanie wskaźnikowi na klasę PowerRelayStation informacji o wzorcu
					p_power_relay_station->getSlotsRate()->setTemplate(p_templ_slot_rate);
				}
			}

			//jeśli obiekt posiada baterię
			if(m_templ_use_battery)
				if (p_templ_battery)
				{
					//pobieramy składową  wzorca baterii i wzorzec wypełniam wskaźnik danymi
					p_power_relay_station->setBattery(p_templ_battery->create(L""));
					//przekazanie wskaźnikowi na klasę PowerRelayStation informacji o wzorcu
					p_power_relay_station->getBattery()->setTemplate(p_templ_battery);
					//decorator (ten kod będzie na poziomie BatteryTemplate)
					p_power_relay_station->getBattery()->setSmoothing(true);
				}
			
			//decorate
			p_power_relay_station->setSmoothing(true);
		}
	}
}//namespace factory

