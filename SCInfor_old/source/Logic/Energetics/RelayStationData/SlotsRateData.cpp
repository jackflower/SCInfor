//  __________________________________________
// | SlotsRateData.cpp - class implementation |
// | Jack Flower - May 2016                   |
// |__________________________________________|
//

#include "SlotsRateData.h"
#include "../../PhysicalManager.h"
#include "../PowerRelay/SlotsRate.h"

namespace relaystationdata
{
	RTTI_IMPL(SlotsRateData, EquipmentData);

	//Konstruktor
	SlotsRateData::SlotsRateData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_slotsrate(NULL)
	{
	}

	//Konstruktor kopiujący
	SlotsRateData::SlotsRateData(const SlotsRateData & SlotsRateDataCopy)
	:
		EquipmentData(SlotsRateDataCopy),//konstruktor kopiujący klasy bazowej
		p_slotsrate(SlotsRateDataCopy.p_slotsrate)
	{
	}

	//Destruktor wirtualny
	SlotsRateData::~SlotsRateData()
	{
		//~EquipmentData()
		if (p_slotsrate)
			gPhysicalManager.destroyPhysical(p_slotsrate);
		p_slotsrate	= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string SlotsRateData::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy SlotsRate
	SlotsRate *SlotsRateData::getSlotsRate()
	{
		return p_slotsrate;
	}

	//Metoda ustawia wskaźnik na obiekt klasy SlotsRate
	void SlotsRateData::setSlotsRate(SlotsRate *slotsrate)
	{
		p_slotsrate = slotsrate;
	}
}//namespace relaystationdata
