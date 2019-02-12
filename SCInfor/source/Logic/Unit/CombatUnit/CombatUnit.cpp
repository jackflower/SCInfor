//  ________________________________________
// | CombatUnit.cpp - class implementation  |
// | Jack Flower - May 2016                 |
// |________________________________________|
//

#include "CombatUnit.h"

namespace logic
{
	namespace unit
	{
		RTTI_IMPL(CombatUnit, Unit);

		CombatUnit::CombatUnit(const std::wstring & uniqueId)
		:
			Unit(uniqueId)//chroniony konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiujący
		CombatUnit::CombatUnit(const CombatUnit & CombatUnitCopy)
		:
			Unit(CombatUnitCopy)//chroniony konstruktor kopiujący klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		CombatUnit::~CombatUnit()
		{
			//~Unit()
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CombatUnit::getType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		void CombatUnit::updateAnimations(float dt)
		{
			//
		}

		//Wirtualan metoda zabija obiekt klasy Actor i wywołuje odpowiednie czynności z tym związane
		void CombatUnit::kill()
		{
			//
		}

		//Wirtualna metoda aktualizująca obiekt
		void CombatUnit::update(float dt)
		{
			Actor::update(dt);
		}

	}//namespace unit
}//namespace logic
