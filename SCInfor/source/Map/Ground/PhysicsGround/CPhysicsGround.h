//  ___________________________________________
// | CPhysicsGround.h - class definition       |
// | Jack Flower - March 2015                  |
// |___________________________________________|
//

#ifndef H_PHYSICS_GROUND_JACK
#define H_PHYSICS_GROUND_JACK

#include "../../../RTTI/RTTI.h"

namespace mapengine
{
	namespace physicsground
	{

		///
		///Klasa reprezentuje fizykê pod³o¿a
		///
		class CPhysicsGround
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			CPhysicsGround();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param CPhysicsGroundCopy - sta³a referencja na obiekt klasy CPhysicsGround
			///
			CPhysicsGround(const CPhysicsGround & CPhysicsGroundCopy);

			///
			///Destruktor
			///
			~CPhysicsGround();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca wspó³czynnik tarcia
			///
			const float getFriction() const;

			///
			///Metoda ustawia wspó³czynnik tarcia
			///
			///@param friction - wspó³czynnik tarcia
			///
			void setFriction(float friction);

			///
			///Metoda zwraca wspó³czynnik wilgotnoœci
			///
			const float getHumidity() const;

			///
			///Metoda ustawia wspó³czynnik wilgotnoœci
			///
			///@param humidity - wspó³czynnik wilgotnoœci
			///
			void setHumidity(float humidity);

			///
			///Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
			///
			const float getThermalTransmittance() const;

			///
			///Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
			///
			///@param thermal_transmittance - wspó³czynnik przenikalnoœci cieplnej
			///
			void setThermalTransmittance(float thermal_transmittance);

		private:
			
			float	m_friction;					//wspó³czynnik tarcia
			float	m_humidity;					//wspó³czynnik wilgotnoœci
			float	m_thermal_transmittance;	//przenikalnoœæ cieplna
		};
	}//namespace physicsground
}//namespace mapengine
#endif//H_PHYSICS_GROUND_JACK
