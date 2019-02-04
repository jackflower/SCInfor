//  ________________________________________________
// | CActorTechnicalData.cpp - class implementation |
// | Jack Flower - May 2016                         |
// |________________________________________________|
//

#include "CActorTechnicalData.h"

namespace physics
{
	namespace technical
	{
		RTTI_IMPL(CActorTechnicalData, CPhysicsData);

		//Konstruktor
		CActorTechnicalData::CActorTechnicalData()
		:
			CPhysicsData	(),//konstruktor klasy bazowej
			m_mass			(0.0f),
			m_temperature	(0.0f),
			m_speed			(0.0f),
			m_movabled		(true),
			m_is_move		(false)
		{
		}

		//Konstruktor kopiuj�cy
		CActorTechnicalData::CActorTechnicalData(const CActorTechnicalData & CActorTechnicalDataCopy)
		:
			CPhysicsData	(CActorTechnicalDataCopy),//konstruktor kopiuj�cy klasy bazowej
			m_mass			(CActorTechnicalDataCopy.m_mass),
			m_temperature	(CActorTechnicalDataCopy.m_temperature),
			m_speed			(CActorTechnicalDataCopy.m_speed),
			m_movabled		(CActorTechnicalDataCopy.m_movabled),
			m_is_move		(CActorTechnicalDataCopy.m_is_move)
		{
		}

		//Destruktor wirtualny
		CActorTechnicalData::~CActorTechnicalData()
		{
			//CPhysicsData	not edit
			m_mass			= 0.0f;
			m_temperature	= 0.0f;
			m_speed			= 0.0f;
			m_movabled		= true;
			m_is_move		= false;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CActorTechnicalData::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca mas� obiektu
		const float CActorTechnicalData::getMass() const
		{
			return m_mass;
		}

		//Metoda ustawia mas� obiektu
		const void CActorTechnicalData::setMass(float mass)
		{
			m_mass = mass;
		}

		//Metoda zwraca temperatur�
		const float CActorTechnicalData::getTemperature() const
		{
			return m_temperature;
		}

		//Metoda ustawia temperatur�
		const void CActorTechnicalData::setTemperature(float temperature)
		{
			m_temperature = temperature;
		}

		//Metoda zwraca pr�dko�� obiektu
		const float CActorTechnicalData::getSpeed() const
		{
			return m_speed;
		}

		//Metoda ustawia pr�dko�� obiektu
		const void CActorTechnicalData::setSpeed(float speed)
		{
			m_speed = speed;
		}

		//Metoda zwraca flag�, czy obiekt mo�e si� przemieszcza�
		const bool CActorTechnicalData::getIsMovabled() const
		{
			return m_movabled;
		}

		//Metoda ustawia flag�, czy obiekt mo�e si� przemieszcza�
		const void CActorTechnicalData::setIsMovabled(bool movabled)
		{
			m_movabled = movabled;
		}

		//Metoda zwraca flag�, czy obiekt si� porusza
		bool const CActorTechnicalData::getIsMove() const
		{
			return m_is_move;
		}

		//Metoda ustawia flag�, �e obiekt si� porusza
		const void CActorTechnicalData::setIsMove(bool is_move)
		{
			m_is_move = is_move;
		}

	}//namespace technical
}//namespace physics
