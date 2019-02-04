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

		//Konstruktor kopiuj�cy
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

		//Metoda zwraca wsp�czynnik tarcia
		const float CPhysicsGround::getFriction() const
		{
			return m_friction;
		}

		//Metoda ustawia wsp�czynnik tarcia
		void CPhysicsGround::setFriction(float friction)
		{
			m_friction = friction;
		}

		//Metoda zwraca wsp�czynnik wilgotno�ci
		const float CPhysicsGround::getHumidity() const
		{
			return m_humidity;
		}

		//Metoda ustawia wsp�czynnik wilgotno�ci
		void CPhysicsGround::setHumidity(float humidity)
		{
			m_humidity = humidity;
		}

		//Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
		const float CPhysicsGround::getThermalTransmittance() const
		{
			return m_thermal_transmittance;
		}

		//Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
		void CPhysicsGround::setThermalTransmittance(float thermal_transmittance)
		{
			m_thermal_transmittance = thermal_transmittance;
		}

	}//namespace physicsground
}//namespace mapengine
