//  ___________________________________________
// | CoalPowerPlant.cpp - class implementation |
// | Jack Flower - July 2014                   |
// |___________________________________________|
//

#include "CoalPowerPlant.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CoalPowerPlant, PowerStation);

		//Chroniony konstruktor domyślny
		CoalPowerPlant::CoalPowerPlant(const std::wstring& uniqueId)
		:
			PowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiujący
		CoalPowerPlant::CoalPowerPlant(const CoalPowerPlant & CoalPowerPlantCopy)
		:
			PowerStation(CoalPowerPlantCopy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		CoalPowerPlant::~CoalPowerPlant()
		{
			//~PowerStation()
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CoalPowerPlant::getType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
