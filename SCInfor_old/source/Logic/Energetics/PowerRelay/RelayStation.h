//  _________________________________________
// | RelayStation.h - class definition       |
// | Jack Flower - July 2015                 |
// |_________________________________________|
//

#ifndef H_RELAY_STATION_JACK
#define H_RELAY_STATION_JACK

#include "../../Actor/Actor.h"
#include "../../Industrial/PowerStation/PowerStation.h"
#include "../../Communication/Communication.h"

using namespace logic::powerstation;
using namespace logic::communication;

namespace logic
{
	namespace energetics
	{
		///
		///Klasa bazowa reprezentuje abstrakcyjny przekaźnik
		///
		class RelayStation : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt RelayStation, należy wywołać PhysicalManager::CreateRelayStation();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring
			///
			RelayStation(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param RelayStationCopy - stała referencja na obiekt klasy RelayStation
			///
			RelayStation(const RelayStation & RelayStationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~RelayStation();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca nazwę przekaźnika energii
			///
			const std::string getRelayStationName() const;

			///
			///Metoda zwraca nazwę przekaźnika energii
			///
			///@param &relay_station_name - nazwa przekaźnika energii elektrycznej
			///
			void setRelayStationName(const std::string & relay_station_name);

			///
			///Metoda zwraca flagę, czy obiekt posiada moduł do komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada moduł do komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada moduł do komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Metoda zwraca wskaźnik na obiekt klasy Communication
			///
			Communication *getCommunication();

			///
			///Metoda ustawia wskaźnik na obiekt klasy Communication
			///
			///@param *communication - wskaźnik na obiekt klasy Communication
			///
			void setCommunication(Communication *communication);

		protected:

			std::string m_relay_station_name; //nazwa przekaźnika energii elektrycznej
			Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
			bool m_use_communication; //flaga, czy obiekt posiada moduł do komunikacji
			Communication * p_communication; //wskaźnik na obiekt klasy Communication
		};
	}//namespace energetics
}//namespace logic
#endif//H_RELAY_STATION_JACK
