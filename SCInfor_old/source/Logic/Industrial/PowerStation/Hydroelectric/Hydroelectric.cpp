//  __________________________________________
// | Hydroelectric.cpp - class implementation |
// | Jack Flower - July 2014                  |
// |__________________________________________|
//

#include "Hydroelectric.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(Hydroelectric, PowerStation);

		//Chroniony konstruktor domyślny
		Hydroelectric::Hydroelectric(const std::wstring & uniqueId)
		:
			PowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiujący
		Hydroelectric::Hydroelectric(const Hydroelectric & HydroelectricCopy)
		:
			PowerStation(HydroelectricCopy)//konstruktor kopiujący klasy bazowej
		{
			//~PowerStation()
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		Hydroelectric::~Hydroelectric()
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Hydroelectric::getType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
