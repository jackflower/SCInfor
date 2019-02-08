//  ___________________________________
// | CUnit.cpp - class implementation  |
// | Jack Flower - May 2016            |
// |___________________________________|
//

#include "CUnit.h"

namespace logic
{
	namespace unit
	{
		RTTI_IMPL(CUnit, Actor);

		CUnit::CUnit(const std::wstring& uniqueId)
		:
			Actor					(uniqueId),//chroniony konstruktor klasy bazowej
			m_strategy_controller	()
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CUnit::CUnit(const CUnit & CUnitCopy)
		:
			Actor					(CUnitCopy),	//chroniony konstruktor kopiuj�cy klasy bazowej
			m_strategy_controller	(CUnitCopy.m_strategy_controller)
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CUnit::~CUnit()
		{
			//m_strategy_controller	not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CUnit::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CUnit::update(float dt)
		{
			Actor::update(dt);
		}

	}//namespace unit
}//namespace logic
