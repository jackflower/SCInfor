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

		//Chroniony konstruktor kopiujący
		CUnit::CUnit(const CUnit & CUnitCopy)
		:
			Actor					(CUnitCopy),	//chroniony konstruktor kopiujący klasy bazowej
			m_strategy_controller	(CUnitCopy.m_strategy_controller)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		CUnit::~CUnit()
		{
			//m_strategy_controller	not edit
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CUnit::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Wirtualna metoda aktualizująca obiekt
		void CUnit::update(float dt)
		{
			Actor::update(dt);
		}

	}//namespace unit
}//namespace logic
