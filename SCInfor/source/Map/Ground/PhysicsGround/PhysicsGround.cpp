//  __________________________________________
// | PhysicsGround.cpp - class implementation |
// | Jack Flower - March 2015                 |
// |__________________________________________|
//

#include "PhysicsGround.h"

namespace mapengine
{
	namespace physicsground
	{

		RTTI_IMPL_NOPARENT(PhysicsGround);

		//Konstruktor
		PhysicsGround::PhysicsGround()
		:
			m_friction(0.0f),
			m_humidity(0.0f),
			m_thermal_transmittance(0.0f)
		{
		}

		//Konstruktor kopiujący
		PhysicsGround::PhysicsGround(const PhysicsGround & PhysicsGroundCopy)
		:
			m_friction(PhysicsGroundCopy.m_friction),
			m_humidity(PhysicsGroundCopy.m_humidity),
			m_thermal_transmittance(PhysicsGroundCopy.m_thermal_transmittance)
		{
		}

		//Destruktor
		PhysicsGround::~PhysicsGround()
		{
			m_friction = 0.0f;
			m_humidity = 0.0f;
			m_thermal_transmittance	= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string PhysicsGround::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca współczynnik tarcia
		const float PhysicsGround::getFriction() const
		{
			return m_friction;
		}

		//Metoda ustawia współczynnik tarcia
		void PhysicsGround::setFriction(float friction)
		{
			m_friction = friction;
		}

		//Metoda zwraca współczynnik wilgotności
		const float PhysicsGround::getHumidity() const
		{
			return m_humidity;
		}

		//Metoda ustawia współczynnik wilgotności
		void PhysicsGround::setHumidity(float humidity)
		{
			m_humidity = humidity;
		}

		//Metoda zwraca współczynnik przenikalności cieplnej
		const float PhysicsGround::getThermalTransmittance() const
		{
			return m_thermal_transmittance;
		}

		//Metoda ustawia współczynnik przenikalności cieplnej
		void PhysicsGround::setThermalTransmittance(float thermal_transmittance)
		{
			m_thermal_transmittance = thermal_transmittance;
		}

	}//namespace physicsground
}//namespace mapengine
