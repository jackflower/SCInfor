//  ___________________________________________
// | CSlotsRateData.cpp - class implementation |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#include "CSlotsRateData.h"
#include "../../CPhysicalManager.h"
#include "../PowerRelay/CSlotsRate.h"

namespace relaystationdata
{
	RTTI_IMPL(CSlotsRateData, EquipmentData);

	//Konstruktor
	CSlotsRateData::CSlotsRateData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_slotsrate		(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CSlotsRateData::CSlotsRateData(const CSlotsRateData & CSlotsRateDataCopy)
	:
		EquipmentData	(CSlotsRateDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_slotsrate		(CSlotsRateDataCopy.p_slotsrate)
	{
	}

	//Destruktor wirtualny
	CSlotsRateData::~CSlotsRateData()
	{
		//EquipmentData	not edit
		if (p_slotsrate)
			gPhysicalManager.DestroyPhysical(p_slotsrate);
		p_slotsrate	= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSlotsRateData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CSlotsRate
	CSlotsRate* CSlotsRateData::getSlotsRate()
	{
		return p_slotsrate;
	}

	//Metoda ustawia wskaünik na obiekt klasy CSlotsRate
	void CSlotsRateData::setSlotsRate(CSlotsRate* slotsrate)
	{
		p_slotsrate = slotsrate;
	}
}//namespace relaystationdata
