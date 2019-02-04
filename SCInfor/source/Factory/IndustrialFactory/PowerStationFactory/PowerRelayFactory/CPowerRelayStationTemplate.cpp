//  ______________________________________________________
// | CPowerRelayStationTemplate.cpp - class implementaion |
// | Jack Flower - July 2015                              |
// |______________________________________________________|
//

#include "CPowerRelayStationTemplate.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../ResourceManager/CResourceManager.h"
#include "../../../../Utilities/Random/CRandom.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(CPowerRelayStationTemplate, CRelayStationTemplate);

	//Konstruktor
	CPowerRelayStationTemplate::CPowerRelayStationTemplate()
	:
		CRelayStationTemplate				(),//konstruktor klasy bazowej
		m_templ_use_slots_rate				(false),
		m_templ_powerstations_capacity		(0),
		m_templ_state_time_range			(0.0f, 0.0f),
		m_templ_rotation_speed_range		(0.0f, 0.0f),
		m_templ_state_time					(0.0f),
		m_templ_rotation_speed				(0.0f),
		p_templ_slot_rate					(NULL),
		p_templ_battery						(NULL),
		m_templ_use_battery					(false),
		m_templ_time_to_start				(0.0f),
		m_templ_duration_disconnect			(0.0f)
	{
	}

	//Destruktor wirtualny
	CPowerRelayStationTemplate::~CPowerRelayStationTemplate()
	{
		//CRelayStationTemplate				not edit
		m_templ_use_slots_rate				= false;
		m_templ_powerstations_capacity		= 0;
		m_templ_state_time_range.first		= 0.0f;
		m_templ_state_time_range.second		= 0.0f;
		m_templ_rotation_speed_range.first	= 0.0f;
		m_templ_rotation_speed_range.second	= 0.0f;
		m_templ_state_time					= 0.0f;
		m_templ_rotation_speed				= 0.0f;
		p_templ_slot_rate					= NULL;
		p_templ_battery						= NULL;
		m_templ_use_battery					= false;
		m_templ_time_to_start				= 0.0f;
		m_templ_duration_disconnect			= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPowerRelayStationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CPowerRelayStationTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CPowerRelayStationTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CPowerRelayStationTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CRelayStationTemplate
		if (!CRelayStationTemplate::Load(xml)) return false;

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

		//³adowanie modu³u prezentacji slotów przekaŸnika
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "slots_rate_data"))
		{
			//flaga, czy obiekt posiada modu³ prezentacji stanu slotów
			m_templ_use_slots_rate = xml.GetBool(node, "use_slots_rate");
			//zapisujê do zmiennej nazwê pliku z konfiguracj¹ modu³u prezentacji stanu slotów
			std::string slots_rate_filename_tmp = xml.GetString(node, "slots_rate_filename");
			if (m_templ_use_slots_rate)
				p_templ_slot_rate = (CSlotsRateTemplate*)gResourceManager.GetPhysicalTemplate(slots_rate_filename_tmp);
		}

		//³adowanie modu³u baterii slotów przekaŸnika
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "battery_data"))
		{
			//flaga, czy obiekt posiada modu³ prezentacji stanu slotów
			m_templ_use_battery = xml.GetBool(node, "use_battery");
			//zapisujê do zmiennej nazwê pliku z konfiguracj¹ modu³u prezentacji stanu slotów
			std::string battery_filename_tmp = xml.GetString(node, "battery_filename");
			if (m_templ_use_battery)
				p_templ_battery = (CBatteryTemplate*)gResourceManager.GetPhysicalTemplate(battery_filename_tmp);
		}


		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CPowerRelayStation
	CPowerRelayStation* CPowerRelayStationTemplate::Create(std::wstring id)
	{
		CPowerRelayStation* power_relay_station = gPhysicalManager.CreatePowerRelayStation(id);
		Fill(power_relay_station);
		return power_relay_station;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CPowerRelayStationTemplate::Fill(CPowerRelayStation *p_power_relay_station)
	{
		if(p_power_relay_station)
		{
			CRelayStationTemplate::Fill(p_power_relay_station);

			//dane obiektu
			p_power_relay_station->setUseSlotsRate(m_templ_use_slots_rate);
			p_power_relay_station->setPowerstationsCapacity(m_templ_powerstations_capacity);
			p_power_relay_station->setStateTimeRange(m_templ_state_time_range);
			p_power_relay_station->setRotationSpeedRange(m_templ_rotation_speed_range);
			//losowanie czasu trwania stanu
			m_templ_state_time = gRandom.GetSingleton().Rndf(m_templ_state_time_range.first, m_templ_state_time_range.second);
			//losowanie prêdkoœci i kierunku rotacji
			m_templ_rotation_speed = gRandom.GetSingleton().Rndf(m_templ_rotation_speed_range.first, m_templ_rotation_speed_range.second);
			p_power_relay_station->setStateTime(m_templ_state_time);
			p_power_relay_station->setRotationSpeed(m_templ_rotation_speed);
			p_power_relay_station->setTimeToStart(m_templ_time_to_start);
			p_power_relay_station->setDurationDisconnect(m_templ_duration_disconnect);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_power_relay_station->SetAnimSet(p_templ_animations);
				//body
				if (p_templ_animations->GetPowerRelayStationBodyDefaultAnim()!= NULL)
					p_power_relay_station->SetAnimationBody(p_templ_animations->GetPowerRelayStationBodyDefaultAnim());
				//head
				if (p_templ_animations->GetPowerRelayStationHeadDefaultAnim()!= NULL)
					p_power_relay_station->SetAnimationHead(p_templ_animations->GetPowerRelayStationHeadDefaultAnim());
			}
			
			//jeœli obiekt posiada modu³ prezentacji stanu slotów
			if (m_templ_use_slots_rate)
			{
				if (p_templ_slot_rate)
				{
					//pobieramy sk³adow¹ modu³ prezentacji stanu slotów i wzorzec wype³nia wskaŸnik danymi
					p_power_relay_station->setSlotsRate(p_templ_slot_rate->Create(L""));
					//przekazanie wskaŸnikowi na klasê CPowerRelayStation informacji o wzorcu
					p_power_relay_station->getSlotsRate()->SetTemplate(p_templ_slot_rate);
				}
			}

			//jeœli obiekt posiada bateriê
			if(m_templ_use_battery)
				if (p_templ_battery)
				{
					//pobieramy sk³adow¹  wzorca baterii i wzorzec wype³niam wskaŸnik danymi
					p_power_relay_station->setBattery(p_templ_battery->Create(L""));
					//przekazanie wskaŸnikowi na klasê CPowerRelayStation informacji o wzorcu
					p_power_relay_station->getBattery()->SetTemplate(p_templ_battery);
					//decorator (ten kod bêdzie na poziomie CBatteryTemplate)
					p_power_relay_station->getBattery()->setSmoothing(true);
				}
			
			//decorate
			p_power_relay_station->setSmoothing(true);
		}
	}
}//namespace factory
