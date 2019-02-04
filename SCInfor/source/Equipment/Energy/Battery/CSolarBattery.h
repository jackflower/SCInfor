//  __________________________________________
// | CSolarBattery.h - class definition       |
// | Jack Flower May 2014                     |
// |__________________________________________|
//

#ifndef H_SOLAR_BATTERY_JACK
#define H_SOLAR_BATTERY_JACK

#include "CBattery.h"
#include "../../../RTTI/RTTI.h"

namespace equipment
{
	namespace battery
	{
		///
		///Klasa reprezentruje funkcjonalno�� baterii s�onecznej
		///
		class CSolarBattery : public CBattery
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CSolarBattery, nale�y wywo�a� CPhysicalManager::CreateSolarBattery();

		protected:
			
			///
			///Konstruktor domy�lny chroniony
			///
			CSolarBattery(const std::wstring& uniqueId);

			///
			///Konstruktor kopiuj�cy chroniony
			///
			///@param &CSolarBatteryCopy - obiekt klasy CSolarBattery
			///
			CSolarBattery(const CSolarBattery& CSolarBatteryCopy);

			///
			///Destruktor chroniony
			///
			~CSolarBattery(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca warto�� spadku pojemno�ci baterii
			///
			const float getDecline() const;

			///
			///Metoda ustawia warto�� spadku pojemno�ci baterii
			///
			///@param decline - warto�� spadku pojemno�ci baterii
			///
			void setDecline(float decline);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		protected:

			float m_decline;	//warto�� spadku pojemno�ci przy ka�dym cyklu prze�adowaniu (�adowanie/roz�adowanie)

		};
	}//namespace battery
}//namespace equipment

#endif//H_SOLAR_BATTERY_JACK