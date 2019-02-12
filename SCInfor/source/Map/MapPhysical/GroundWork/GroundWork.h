//  _______________________________________
// | GroundWork.h - class definition       |
// | Jack Flower - March 2015              |
// |_______________________________________|
//

#ifndef H_GROUND_WORK_JACK
#define H_GROUND_WORK_JACK

#include "../MapPhysical.h"
#include "../../Ground/PhysicsGround/PhysicsGround.h"

using namespace mapengine::physicsground;

namespace mapengine
{
	namespace groundwork
	{
		///
		///Klasa reprezentuje rodzaj podłoża (grunt), po którym przemieszczają się obiekty
		///
		class GroundWork : public MapPhysical
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class MapPhysicalManager;

			//Aby uzyskać obiekt GroundWork, należy wywołać MapPhysicalManager::CreateGroundWork();

		protected:

			///
			///Chroniony konstruktor domyślny - używany wyłącznie przez MapPhysicalManager
			///
			///@param uniqueId - unikalny identyfikator (nadawany w MapPhysicalManager)
			///
			GroundWork(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param GroundWorkCopy - stała referencja na obiekt klasy GroundWork
			///
			GroundWork(const GroundWork & GroundWorkCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez MapPhysicalManager
			///
			~GroundWork(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca współczynnik tarcia
			///
			const float getFriction() const;

			///
			///Metoda ustawia współczynnik tarcia
			///
			///@param friction - współczynnik tarcia
			///
			void setFriction(float friction);

			///
			///Metoda zwraca współczynnik wilgotności
			///
			const float getHumidity() const;

			///
			///Metoda ustawia współczynnik wilgotności
			///
			///@param humidity - współczynnik wilgotności
			///
			void setHumidity(float humidity);

			///
			///Metoda zwraca współczynnik przenikalności cieplnej
			///
			const float getThermalTransmittance() const;

			///
			///Metoda ustawia współczynnik przenikalności cieplnej
			///
			///@param thermal_transmittance - współczynnik przenikalności cieplnej
			///
			void setThermalTransmittance(float thermal_transmittance);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			PhysicsGround m_physicsground; //wskaźnik na klasę opakowującą fizykę podłoża

		};
	}//namespace groundwork
}//namespace mapengine
#endif//H_GROUND_WORK_JACK
