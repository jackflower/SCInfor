//  _________________________________________
// | SolarBattery.h - class definition       |
// | Jack Flower May 2014                    |
// |_________________________________________|
//

#ifndef H_SOLAR_BATTERY_JACK
#define H_SOLAR_BATTERY_JACK

#include "Battery.h"
#include "../../../RTTI/RTTI.h"

namespace equipment
{
	namespace battery
	{
		///
		///Klasa reprezentruje funkcjonalność baterii słonecznej
		///
		class SolarBattery : public Battery
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt SolarBattery, należy wywołać PhysicalManager::CreateSolarBattery();

		protected:
			
			///
			///Konstruktor domyślny chroniony
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			SolarBattery(const std::wstring & uniqueId);

			///
			///Konstruktor kopiujący chroniony
			///
			///@param SolarBatteryCopy - obiekt klasy SolarBattery
			///
			SolarBattery(const SolarBattery & SolarBatteryCopy);

			///
			///Destruktor chroniony
			///
			~SolarBattery(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca wartość spadku pojemności baterii
			///
			const float getDecline() const;

			///
			///Metoda ustawia wartość spadku pojemności baterii
			///
			///@param decline - wartość spadku pojemności baterii
			///
			void setDecline(float decline);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			//wartość spadku pojemności przy każdym cyklu
			//przeładowaniu (ładowanie/rozładowanie)
			float m_decline;

		};
	}//namespace battery
}//namespace equipment

#endif//H_SOLAR_BATTERY_JACK