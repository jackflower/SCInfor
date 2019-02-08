//  __________________________________________
// | CRelayStation.cpp - class implementation |
// | Jack Flower - July 2015                  |
// |__________________________________________|
//
#include "CRelayStation.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../CPhysicalManager.h"

using namespace rendering::drawable;

namespace logic
{
	namespace energetics
	{
		RTTI_IMPL(CRelayStation, Actor);
	
		//Chroniony konstruktor domyœlny
		CRelayStation::CRelayStation(const std::wstring& uniqueId)
		:
			Actor						(uniqueId),//konstruktor klasy bazowej
			m_relay_station_name		(),
			m_unit_controller			(true),//urz¹dzenie w³¹czone
			m_use_communication			(false),
			p_communication				(NULL)
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CRelayStation::CRelayStation(const CRelayStation &CRelayStationCopy)
		:
			Actor						(CRelayStationCopy),//konstruktor kopiujacy klasy bazowej
			m_relay_station_name		(CRelayStationCopy.m_relay_station_name),
			m_unit_controller			(CRelayStationCopy.m_unit_controller),
			m_use_communication			(CRelayStationCopy.m_use_communication),
			p_communication				(CRelayStationCopy.p_communication)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CRelayStation::~CRelayStation()
		{
			//Actor					not edit
			m_relay_station_name		= "";
			//m_unit_controller			not edit
			m_use_communication			= false;
			if (p_communication)
				gPhysicalManager.DestroyPhysical(p_communication);
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CRelayStation::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazwê przekaŸnika energii
		const std::string CRelayStation::getRelayStationName() const
		{
			return m_relay_station_name;
		}

		//Metoda zwraca nazwê przekaŸnika energii
		void CRelayStation::setRelayStationName(const std::string & relay_station_name)
		{
			m_relay_station_name = m_relay_station_name;
		}

		//Metoda zwraca flagê, czy obiekt posiada modu³ do komunikacji
		const bool CRelayStation::getUseCommunication() const
		{
			return m_use_communication;
		}

		//Metoda ustawia flagê, czy obiekt posiada modu³ do komunikacji
		void CRelayStation::setUseCommunication(const bool use_communication)
		{
			m_use_communication = use_communication;
		}

		//Metoda zwraca wskaŸnik na obiekt klasy CCommunication
		CCommunication* CRelayStation::GetCommunication()
		{
			return p_communication;
		}

		//Metoda ustawia wskaŸnik na obiekt klasy CCommunication
		void CRelayStation::SetCommunication(CCommunication* communication)
		{
			p_communication = communication;
		}
	}//namespace energetics
}//namespace logic
