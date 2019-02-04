//  ___________________________________________
// | CPhysicsGround.cpp - class implementation |
// | Jack Flower - March 2015                  |
// |___________________________________________|
//

#include "CPhysicsGround.h"

namespace mapengine
{
	namespace physicsground
	{

		RTTI_IMPL_NOPARENT(CPhysicsGround);

		//Konstruktor
		CPhysicsGround::CPhysicsGround()
		:
			m_friction				(0.0f),
			m_humidity				(0.0f),
			m_thermal_transmittance	(0.0f)
		{
		}

		//Konstruktor kopiuj¹cy
		CPhysicsGround::CPhysicsGround(const CPhysicsGround & CPhysicsGroundCopy)
		:
			m_friction				(CPhysicsGroundCopy.m_friction),
			m_humidity				(CPhysicsGroundCopy.m_humidity),
			m_thermal_transmittance	(CPhysicsGroundCopy.m_thermal_transmittance)
		{
		}

		//Destruktor
		CPhysicsGround::~CPhysicsGround()
		{
			m_friction				= 0.0f;
			m_humidity				= 0.0f;
			m_thermal_transmittance	= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CPhysicsGround::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca wspó³czynnik tarcia
		const float CPhysicsGround::getFriction() const
		{
			return m_friction;
		}

		//Metoda ustawia wspó³czynnik tarcia
		void CPhysicsGround::setFriction(float friction)
		{
			m_friction = friction;
		}

		//Metoda zwraca wspó³czynnik wilgotnoœci
		const float CPhysicsGround::getHumidity() const
		{
			return m_humidity;
		}

		//Metoda ustawia wspó³czynnik wilgotnoœci
		void CPhysicsGround::setHumidity(float humidity)
		{
			m_humidity = humidity;
		}

		//Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
		const float CPhysicsGround::getThermalTransmittance() const
		{
			return m_thermal_transmittance;
		}

		//Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
		void CPhysicsGround::setThermalTransmittance(float thermal_transmittance)
		{
			m_thermal_transmittance = thermal_transmittance;
		}

	}//namespace physicsground
}//namespace mapengine
