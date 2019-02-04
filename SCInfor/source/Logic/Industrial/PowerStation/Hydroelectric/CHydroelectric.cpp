/*
 ___________________________________________
| CHydroelectric.cpp - implementacja klasy. |
| Jack Flower - July 2014.                  |
|___________________________________________|

*/

#include "CHydroelectric.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CHydroelectric, CPowerStation);

		//Chroniony konstruktor domy�lny
		CHydroelectric::CHydroelectric(const std::wstring& uniqueId)
		:
			CPowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CHydroelectric::CHydroelectric(const CHydroelectric &CHydroelectricCopy)
		:
			CPowerStation(CHydroelectricCopy)//konstruktor klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CHydroelectric::~CHydroelectric(void)
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CHydroelectric::GetType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
