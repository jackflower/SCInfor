//  ___________________________________
// | CCombatUnit.cpp - class implementation  |
// | Jack Flower - May 2016            |
// |___________________________________|
//

#include "CCombatUnit.h"

namespace logic
{
	namespace unit
	{
		RTTI_IMPL(CCombatUnit, CUnit);

		CCombatUnit::CCombatUnit(const std::wstring& uniqueId)
		:
			CUnit(uniqueId)//,	//chroniony konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CCombatUnit::CCombatUnit(const CCombatUnit & CCombatUnitCopy)
		:
			CUnit(CCombatUnitCopy)//,	//chroniony konstruktor kopiuj�cy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CCombatUnit::~CCombatUnit()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CCombatUnit::GetType() const
		{
			return rtti.GetNameClass();
		}

		////Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		//void CCombatUnit::updateAnimations(float dt)
		//{
		//}

		////Wirtualan metoda zabija obiekt klasy CActor i wywo�uje odpowiednie czynno�ci z tym zwi�zane
		//void CCombatUnit::Kill()
		//{
		//}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CCombatUnit::update(float dt)
		{
			CActor::update(dt);
		}

	}//namespace unit
}//namespace logic
