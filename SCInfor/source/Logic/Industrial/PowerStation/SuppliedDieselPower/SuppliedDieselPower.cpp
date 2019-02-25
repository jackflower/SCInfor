//  ________________________________________________
// | SuppliedDieselPower.cpp - class implementation |
// | Jack Flower - August 2014                      |
// |________________________________________________|
//

#include "SuppliedDieselPower.h"

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(SuppliedDieselPower, PowerStation);

		//Chroniony konstruktor domyślny
		SuppliedDieselPower::SuppliedDieselPower(const std::wstring & uniqueId)
		:
			PowerStation(uniqueId)//konstruktor klasy bazowej
		{
		}

		//Chroniony konstruktor kopiujący
		SuppliedDieselPower::SuppliedDieselPower(const SuppliedDieselPower & SuppliedDieselPowerCopy)
		:
			PowerStation(SuppliedDieselPowerCopy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		SuppliedDieselPower::~SuppliedDieselPower(void)
		{
			//~PowerStation()
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string SuppliedDieselPower::getType() const
		{
			return rtti.getNameClass();
		}

	}//namespace powerstation
}//namespace logic
