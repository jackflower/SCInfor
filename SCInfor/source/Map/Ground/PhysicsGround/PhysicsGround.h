//  __________________________________________
// | PhysicsGround.h - class definition       |
// | Jack Flower - March 2015                 |
// |__________________________________________|
//

#ifndef H_PHYSICS_GROUND_JACK
#define H_PHYSICS_GROUND_JACK

#include "../../../RTTI/RTTI.h"

namespace mapengine
{
	namespace physicsground
	{

		///
		///Klasa reprezentuje fizykę podłoża
		///
		class PhysicsGround
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			PhysicsGround();

			///
			///Konstruktor kopiujący
			///
			///@param PhysicsGroundCopy - stała referencja na obiekt klasy PhysicsGround
			///
			PhysicsGround(const PhysicsGround & PhysicsGroundCopy);

			///
			///Destruktor
			///
			~PhysicsGround();

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

		private:
			
			float m_friction; //współczynnik tarcia
			float m_humidity; //współczynnik wilgotności
			float m_thermal_transmittance; //przenikalność cieplna
		};
	}//namespace physicsground
}//namespace mapengine
#endif//H_PHYSICS_GROUND_JACK
