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
		///Klasa bazowa reprezentuje abstrakcyjny przekaünik
		///
		class CRelayStation : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaüni
			///
			friend class CPhysicalManager;

			//Aby uzyskaÊ obiekt CRelayStation, naleøy wywo≥aÊ CPhysicalManager::CreateRelayStation();

		protected:

			///
			///Chroniony konstruktor domyúlny
			///
			///@param &uniqueId - sta≥a referencja na obiekt klasy std::wstring
			///
			CRelayStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiujπcy
			///
			///@param CRelayStationCopy - obiekt klasy CRelayStation
			///
			CRelayStation(const CRelayStation &CRelayStationCopy);

			///
			///Chroniony destruktor wirtualny - uøywany wy≥πcznie przez CPhysicalManager
			///
			virtual ~CRelayStation();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazwÍ przekaünika energii
			///
			const std::string getRelayStationName() const;

			///
			///Metoda zwraca nazwÍ przekaünika energii
			///
			///@param &relay_station_name - nazwa przekaünika energii elektrycznej
			///
			void setRelayStationName(const std::string & relay_station_name);

			///
			///Metoda zwraca flagÍ, czy obiekt posiada modu≥ do komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flagÍ, czy obiekt posiada modu≥ do komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada modu≥ do komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Metoda zwraca wskaünik na obiekt klasy CCommunication
			///
			CCommunication* GetCommunication();

			///
			///Metoda ustawia wskaünik na obiekt klasy CCommunication
			///
			///@param *communication - wskaünik na obiekt klasy CCommunication
			///
			void SetCommunication(CCommunication* communication);

		protected:

			std::string			m_relay_station_name;	//nazwa przekaünika energii elektrycznej
			Switch				m_unit_controller;		//w≥πcznik, sterownik, modu≥ zarzπdzania, starter, stacyjka
			bool				m_use_communication;	//flaga, czy obiekt posiada modu≥ do komunikacji
			CCommunication*		p_communication;		//wskaünik na obiekt klasy Communication
		};
	}//namespace energetics
}//namespace logic
#endif//H_RELAY_STATION_JACK
