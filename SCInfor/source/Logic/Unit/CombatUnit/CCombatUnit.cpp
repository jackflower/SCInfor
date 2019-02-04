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

		//Chroniony konstruktor kopiuj¹cy
		CCombatUnit::CCombatUnit(const CCombatUnit & CCombatUnitCopy)
		:
			CUnit(CCombatUnitCopy)//,	//chroniony konstruktor kopiuj¹cy klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CCombatUnit::~CCombatUnit()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CCombatUnit::GetType() const
		{
			return rtti.GetNameClass();
		}

		////Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		//void CCombatUnit::updateAnimations(float dt)
		//{
		//}

		////Wirtualan metoda zabija obiekt klasy CActor i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
		//void CCombatUnit::Kill()
		//{
		//}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CCombatUnit::update(float dt)
		{
			CActor::update(dt);
		}

	}//namespace unit
}//namespace logic
