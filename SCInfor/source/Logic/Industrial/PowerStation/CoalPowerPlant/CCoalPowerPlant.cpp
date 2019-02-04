/*
 ____________________________________________
| CCoalPowerPlant.cpp - implementacja klasy. |
| Jack Flower - July 2014.                   |
|____________________________________________|

*/

#include "CCoalPowerPlant.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CCoalPowerPlant, CPowerStation);

		//Chroniony konstruktor domyœlny
		CCoalPowerPlant::CCoalPowerPlant(const std::wstring& uniqueId)
		:
			CPowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CCoalPowerPlant::CCoalPowerPlant(const CCoalPowerPlant &CCoalPowerPlantCopy)
		:
			CPowerStation(CCoalPowerPlantCopy)//konstruktor klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CCoalPowerPlant::~CCoalPowerPlant(void)
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CCoalPowerPlant::GetType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
