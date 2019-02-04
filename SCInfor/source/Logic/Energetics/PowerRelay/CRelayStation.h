//  __________________________________________
// | CRelayStation.h - class definition       |
// | Jack Flower - July 2015                  |
// |__________________________________________|
//

#ifndef H_RELAY_STATION_JACK
#define H_RELAY_STATION_JACK

#include "../../Actor/CActor.h"
#include "../../Industrial/PowerStation/CPowerStation.h"
#include "../../Communication/CCommunication.h"

using namespace logic::powerstation;
using namespace logic::communication;

namespace logic
{
	namespace energetics
	{
		///
		///Klasa bazowa reprezentuje abstrakcyjny przeka�nik
		///
		class CRelayStation : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CRelayStation, nale�y wywo�a� CPhysicalManager::CreateRelayStation();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param &uniqueId - sta�a referencja na obiekt klasy std::wstring
			///
			CRelayStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CRelayStationCopy - obiekt klasy CRelayStation
			///
			CRelayStation(const CRelayStation &CRelayStationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CRelayStation();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazw� przeka�nika energii
			///
			const std::string getRelayStationName() const;

			///
			///Metoda zwraca nazw� przeka�nika energii
			///
			///@param &relay_station_name - nazwa przeka�nika energii elektrycznej
			///
			void setRelayStationName(const std::string & relay_station_name);

			///
			///Metoda zwraca flag�, czy obiekt posiada modu� do komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada modu� do komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada modu� do komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Metoda zwraca wska�nik na obiekt klasy CCommunication
			///
			CCommunication* GetCommunication();

			///
			///Metoda ustawia wska�nik na obiekt klasy CCommunication
			///
			///@param *communication - wska�nik na obiekt klasy CCommunication
			///
			void SetCommunication(CCommunication* communication);

		protected:

			std::string			m_relay_station_name;	//nazwa przeka�nika energii elektrycznej
			Switch				m_unit_controller;		//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
			bool				m_use_communication;	//flaga, czy obiekt posiada modu� do komunikacji
			CCommunication*		p_communication;		//wska�nik na obiekt klasy Communication
		};
	}//namespace energetics
}//namespace logic
#endif//H_RELAY_STATION_JACK
