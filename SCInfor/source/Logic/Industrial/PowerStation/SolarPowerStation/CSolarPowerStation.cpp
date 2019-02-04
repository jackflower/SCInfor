/*
 _______________________________________________
| CSolarPowerStation.cpp - implementacja klasy. |
| Jack Flower - July 2014.                      |
|_______________________________________________|

*/

#include "CSolarPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CSolarPowerStation, CPowerStation);

		//Chroniony konstruktor domy�lny
		CSolarPowerStation::CSolarPowerStation(const std::wstring& uniqueId)
		:
			CPowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CSolarPowerStation::CSolarPowerStation(const CSolarPowerStation &CSolarPowerStationCopy)
		:
			CPowerStation(CSolarPowerStationCopy)//konstruktor klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CSolarPowerStation::~CSolarPowerStation(void)
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CSolarPowerStation::GetType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
