/*
 _________________________________________________
| CSuppliedDieselPower.cpp - implementacja klasy. |
| Jack Flower - August 2014.                      |
|_________________________________________________|

*/

#include "CSuppliedDieselPower.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CSuppliedDieselPower, CPowerStation);

		//Chroniony konstruktor domyœlny
		CSuppliedDieselPower::CSuppliedDieselPower(const std::wstring& uniqueId)
		:
			CPowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CSuppliedDieselPower::CSuppliedDieselPower(const CSuppliedDieselPower &CSuppliedDieselPowerCopy)
		:
			CPowerStation(CSuppliedDieselPowerCopy)//konstruktor klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CSuppliedDieselPower::~CSuppliedDieselPower(void)
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CSuppliedDieselPower::GetType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
