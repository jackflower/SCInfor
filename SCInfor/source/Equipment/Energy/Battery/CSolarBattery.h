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
		///Klasa reprezentruje funkcjonalnoœæ baterii s³onecznej
		///
		class CSolarBattery : public CBattery
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CSolarBattery, nale¿y wywo³aæ CPhysicalManager::CreateSolarBattery();

		protected:
			
			///
			///Konstruktor domyœlny chroniony
			///
			CSolarBattery(const std::wstring& uniqueId);

			///
			///Konstruktor kopiuj¹cy chroniony
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
			///Metoda zwraca wartoœæ spadku pojemnoœci baterii
			///
			const float getDecline() const;

			///
			///Metoda ustawia wartoœæ spadku pojemnoœci baterii
			///
			///@param decline - wartoœæ spadku pojemnoœci baterii
			///
			void setDecline(float decline);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		protected:

			float m_decline;	//wartoœæ spadku pojemnoœci przy ka¿dym cyklu prze³adowaniu (³adowanie/roz³adowanie)

		};
	}//namespace battery
}//namespace equipment

#endif//H_SOLAR_BATTERY_JACK