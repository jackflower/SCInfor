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
		///Klasa reprezentuje fizyk� pod�o�a
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
			///Konstruktor kopiuj�cy
			///
			///@param CPhysicsGroundCopy - sta�a referencja na obiekt klasy CPhysicsGround
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
			///Metoda zwraca wsp�czynnik tarcia
			///
			const float getFriction() const;

			///
			///Metoda ustawia wsp�czynnik tarcia
			///
			///@param friction - wsp�czynnik tarcia
			///
			void setFriction(float friction);

			///
			///Metoda zwraca wsp�czynnik wilgotno�ci
			///
			const float getHumidity() const;

			///
			///Metoda ustawia wsp�czynnik wilgotno�ci
			///
			///@param humidity - wsp�czynnik wilgotno�ci
			///
			void setHumidity(float humidity);

			///
			///Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
			///
			const float getThermalTransmittance() const;

			///
			///Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
			///
			///@param thermal_transmittance - wsp�czynnik przenikalno�ci cieplnej
			///
			void setThermalTransmittance(float thermal_transmittance);

		private:
			
			float	m_friction;					//wsp�czynnik tarcia
			float	m_humidity;					//wsp�czynnik wilgotno�ci
			float	m_thermal_transmittance;	//przenikalno�� cieplna
		};
	}//namespace physicsground
}//namespace mapengine
#endif//H_PHYSICS_GROUND_JACK
