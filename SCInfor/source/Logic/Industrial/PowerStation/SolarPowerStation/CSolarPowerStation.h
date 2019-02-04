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
		///Klasa reprezentuje funkcjonalno�� elektrowni s�onecznej
		///
		class CSolarPowerStation : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
			
			//Aby uzyska� obiekt CSolarPowerStation, nale�y wywo�a� CPhysicalManager::CreateSolarPowerStation();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CSolarPowerStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CSolarPowerStationCopy - obiekt klasy CSolarPowerStation
			///
			CSolarPowerStation(const CSolarPowerStation &CSolarPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			~CSolarPowerStation(void);

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

		private:
			
			//
			//[	w pliku graficznym jest elektrownia, kt�ra posiada	]
			//cztery (to si� jeszcze zobaczy)modu�y CSolarCell, kt�re ustawiaj� si� automatyczne
			//w kierunku �r�d�a energii solarnej
			//zatem: nie b�dzie to wektor, a cztery, r�cznie (by� mo�e jednak jaka� tablica)
			//zarz�dzane manualne.
			//uwaga, one ju� s� przsetestowane na scenie...


		};
	}//namespace powerstation
}//namespace logic

#endif//H_SOLAR_POWER_STATION_JACK