//  _______________________________________________
// | ActorTechnicalData.cpp - class implementation |
// | Jack Flower - May 2016                        |
// |_______________________________________________|
//

#include "ActorTechnicalData.h"

namespace physics
{
	namespace technical
	{
		RTTI_IMPL(ActorTechnicalData, PhysicsData);

		//Konstruktor
		ActorTechnicalData::ActorTechnicalData()
		:
			PhysicsData{},//konstruktor klasy bazowej
			m_mass{ 0.0f },
			m_temperature{ 0.0f },
			m_speed{ 0.0f },
			m_movabled{ true },
			m_is_move{ false }
		{
		}

		//Konstruktor kopiujący
		ActorTechnicalData::ActorTechnicalData(const ActorTechnicalData & ActorTechnicalDataCopy)
		:
			PhysicsData{ ActorTechnicalDataCopy },//konstruktor kopiujący klasy bazowej
			m_mass{ ActorTechnicalDataCopy.m_mass },
			m_temperature{ ActorTechnicalDataCopy.m_temperature },
			m_speed{ ActorTechnicalDataCopy.m_speed },
			m_movabled{ ActorTechnicalDataCopy.m_movabled },
			m_is_move{ ActorTechnicalDataCopy.m_is_move }
		{
		}

		//Destruktor wirtualny
		ActorTechnicalData::~ActorTechnicalData()
		{
			//~PhysicsData()
			m_mass = 0.0f;
			m_temperature = 0.0f;
			m_speed = 0.0f;
			m_movabled = true;
			m_is_move = false;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string ActorTechnicalData::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca masę obiektu
		const float ActorTechnicalData::getMass() const
		{
			return m_mass;
		}

		//Metoda ustawia masę obiektu
		const void ActorTechnicalData::setMass(float mass)
		{
			m_mass = mass;
		}

		//Metoda zwraca temperaturę
		const float ActorTechnicalData::getTemperature() const
		{
			return m_temperature;
		}

		//Metoda ustawia temperaturę
		const void ActorTechnicalData::setTemperature(float temperature)
		{
			m_temperature = temperature;
		}

		//Metoda zwraca prędkość obiektu
		const float ActorTechnicalData::getSpeed() const
		{
			return m_speed;
		}

		//Metoda ustawia prędkość obiektu
		const void ActorTechnicalData::setSpeed(float speed)
		{
			m_speed = speed;
		}

		//Metoda zwraca flagę, czy obiekt może się przemieszczać
		const bool ActorTechnicalData::getIsMovabled() const
		{
			return m_movabled;
		}

		//Metoda ustawia flagę, czy obiekt może się przemieszczać
		const void ActorTechnicalData::setIsMovabled(bool movabled)
		{
			m_movabled = movabled;
		}

		//Metoda zwraca flagę, czy obiekt się porusza
		bool const ActorTechnicalData::getIsMove() const
		{
			return m_is_move;
		}

		//Metoda ustawia flagę, że obiekt się porusza
		const void ActorTechnicalData::setIsMove(bool is_move)
		{
			m_is_move = is_move;
		}

	}//namespace technical
}//namespace physics
