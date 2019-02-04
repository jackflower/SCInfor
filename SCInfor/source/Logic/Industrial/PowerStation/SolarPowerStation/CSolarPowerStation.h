/*
 _______________________________________________
| CSolarPowerStation.h - definicja klasy.       |
| Jack Flower - July 2014.                      |
|_______________________________________________|

*/

#ifndef H_SOLAR_POWER_STATION_JACK
#define H_SOLAR_POWER_STATION_JACK

#include "../CPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalnoœæ elektrowni s³onecznej
		///
		class CSolarPowerStation : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CSolarPowerStation, nale¿y wywo³aæ CPhysicalManager::CreateSolarPowerStation();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CSolarPowerStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CSolarPowerStationCopy - obiekt klasy CSolarPowerStation
			///
			CSolarPowerStation(const CSolarPowerStation &CSolarPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CSolarPowerStation(void);

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		private:
			
			//
			//[	w pliku graficznym jest elektrownia, która posiada	]
			//cztery (to siê jeszcze zobaczy)modu³y CSolarCell, które ustawiaj¹ siê automatyczne
			//w kierunku Ÿród³a energii solarnej
			//zatem: nie bêdzie to wektor, a cztery, rêcznie (byæ mo¿e jednak jakaœ tablica)
			//zarz¹dzane manualne.
			//uwaga, one ju¿ s¹ przsetestowane na scenie...


		};
	}//namespace powerstation
}//namespace logic

#endif//H_SOLAR_POWER_STATION_JACK