//  _________________________________________
// | RelayStation.cpp - class implementation |
// | Jack Flower - July 2015                 |
// |_________________________________________|
//
#include "RelayStation.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/AnimationState.h"
#include "../../../Rendering/Displayable/Displayable.h"
#include "../../PhysicalManager.h"

using namespace rendering::drawable;

namespace logic
{
	namespace energetics
	{
		RTTI_IMPL(RelayStation, Actor);
	
		//Chroniony konstruktor domyślny
		RelayStation::RelayStation(const std::wstring & uniqueId)
		:
			Actor(uniqueId),//konstruktor klasy bazowej
			m_relay_station_name(),
			m_unit_controller(true),//urządzenie włączone
			m_use_communication(false),
			p_communication(NULL)
		{
		}

		//Chroniony konstruktor kopiujący
		RelayStation::RelayStation(const RelayStation & RelayStationCopy)
		:
			Actor(RelayStationCopy),//konstruktor kopiujacy klasy bazowej
			m_relay_station_name(RelayStationCopy.m_relay_station_name),
			m_unit_controller(RelayStationCopy.m_unit_controller),
			m_use_communication(RelayStationCopy.m_use_communication),
			p_communication(RelayStationCopy.p_communication)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		RelayStation::~RelayStation()
		{
			//~Actor()
			m_relay_station_name = "";
			//m_unit_controller
			m_use_communication = false;
			if (p_communication)
				gPhysicalManager.destroyPhysical(p_communication);
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string RelayStation::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazwę przekaźnika energii
		const std::string RelayStation::getRelayStationName() const
		{
			return m_relay_station_name;
		}

		//Metoda zwraca nazwę przekaźnika energii
		void RelayStation::setRelayStationName(const std::string & relay_station_name)
		{
			m_relay_station_name = m_relay_station_name;
		}

		//Metoda zwraca flagę, czy obiekt posiada moduł do komunikacji
		const bool RelayStation::getUseCommunication() const
		{
			return m_use_communication;
		}

		//Metoda ustawia flagę, czy obiekt posiada moduł do komunikacji
		void RelayStation::setUseCommunication(const bool use_communication)
		{
			m_use_communication = use_communication;
		}

		//Metoda zwraca wskaźnik na obiekt klasy Communication
		Communication *RelayStation::getCommunication()
		{
			return p_communication;
		}

		//Metoda ustawia wskaźnik na obiekt klasy Communication
		void RelayStation::setCommunication(Communication *communication)
		{
			p_communication = communication;
		}
	}//namespace energetics
}//namespace logic
