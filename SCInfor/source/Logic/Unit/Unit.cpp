//  __________________________________
// | Unit.cpp - class implementation  |
// | Jack Flower - May 2016           |
// |__________________________________|
//

#include "Unit.h"

namespace logic
{
	namespace unit
	{
		RTTI_IMPL(Unit, Actor);

		Unit::Unit(const std::wstring & uniqueId)
		:
			Actor(uniqueId), //chroniony konstruktor klasy bazowej
			m_strategy_controller()
		{
		}

		//Chroniony konstruktor kopiujący
		Unit::Unit(const Unit & UnitCopy)
		:
			Actor(UnitCopy), //chroniony konstruktor kopiujący klasy bazowej
			m_strategy_controller(UnitCopy.m_strategy_controller)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		Unit::~Unit()
		{
			//~Actor()
			//m_strategy_controller
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Unit::getType() const
		{
			return rtti.getNameClass();
		}

		//Wirtualna metoda aktualizująca obiekt
		void Unit::update(float dt)
		{
			Actor::update(dt);
		}

	}//namespace unit
}//namespace logic
