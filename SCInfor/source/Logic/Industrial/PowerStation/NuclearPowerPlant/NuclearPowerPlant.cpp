//  _____________________________________________
// | NuclearPowerPlant.cpp - class implementatin |
// | Jack Flower - July 2014                     |
// |_____________________________________________|
//

#include "NuclearPowerPlant.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(NuclearPowerPlant, PowerStation);

		//Chroniony konstruktor domyślny
		NuclearPowerPlant::NuclearPowerPlant(const std::wstring & uniqueId)
		:
			PowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiujący
		NuclearPowerPlant::NuclearPowerPlant(const NuclearPowerPlant & NuclearPowerPlantCopy)
		:
			PowerStation(NuclearPowerPlantCopy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		NuclearPowerPlant::~NuclearPowerPlant()
		{
			//~PowerStation()
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string NuclearPowerPlant::getType() const
		{
			return rtti.getNameClass();
		}

	}//namespace powerstation
}//namespace logic
