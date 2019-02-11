//  ______________________________________________
// | SolarPowerStation.cpp - class implementation |
// | Jack Flower - July 2014                      |
// |______________________________________________|
//

#include "SolarPowerStation.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(SolarPowerStation, PowerStation);

		//Chroniony konstruktor domyślny
		SolarPowerStation::SolarPowerStation(const std::wstring & uniqueId)
		:
			PowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiujący
		SolarPowerStation::SolarPowerStation(const SolarPowerStation & SolarPowerStationCopy)
		:
			PowerStation(SolarPowerStationCopy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		SolarPowerStation::~SolarPowerStation(void)
		{
			//~PowerStation()
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string SolarPowerStation::getType() const
		{
			return rtti.GetNameClass();
		}

	}//namespace powerstation
}//namespace logic
