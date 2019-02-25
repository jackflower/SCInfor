//  ______________________________________________
// | SolarPowerStation.h - class definition       |
// | Jack Flower - July 2014                      |
// |______________________________________________|
//


#ifndef H_SOLAR_POWER_STATION_JACK
#define H_SOLAR_POWER_STATION_JACK

#include "../PowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni słonecznej
		///
		class SolarPowerStation : public PowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;
			
			//Aby uzyskać obiekt SolarPowerStation, należy wywołać PhysicalManager::CreateSolarPowerStation();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			SolarPowerStation(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param SolarPowerStationCopy - obiekt klasy SolarPowerStation
			///
			SolarPowerStation(const SolarPowerStation & SolarPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~SolarPowerStation(void);

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

		private:
			
			//
			//[	w pliku graficznym jest elektrownia, która posiada	]
			//cztery (to się jeszcze zobaczy)moduły SolarCell, które ustawiają się automatyczne
			//w kierunku źródła energii solarnej
			//zatem: nie będzie to wektor, a cztery, ręcznie (być może jednak jakaś tablica)
			//zarządzane manualne.
			//uwaga, one już są przetestowane na scenie...

		};
	}//namespace powerstation
}//namespace logic
#endif//H_SOLAR_POWER_STATION_JACK
