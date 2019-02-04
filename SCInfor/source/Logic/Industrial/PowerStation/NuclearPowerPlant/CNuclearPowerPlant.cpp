/*
 _______________________________________________
| CNuclearPowerPlant.cpp - implementacja klasy. |
| Jack Flower - July 2014.                      |
|_______________________________________________|

*/

#include "CNuclearPowerPlant.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CNuclearPowerPlant, CPowerStation);

		//Chroniony konstruktor domy�lny
		CNuclearPowerPlant::CNuclearPowerPlant(const std::wstring& uniqueId)
		:
			CPowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CNuclearPowerPlant::CNuclearPowerPlant(const CNuclearPowerPlant &CNuclearPowerPlantCopy)
		:
			CPowerStation(CNuclearPowerPlantCopy)//konstruktor klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CNuclearPowerPlant::~CNuclearPowerPlant(void)
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CNuclearPowerPlant::GetType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
