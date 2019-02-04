//  ___________________________________________________
// | CEquipmentFuelTankData.cpp - class implementation |
// | Jack Flower - May 2016                            |
// |___________________________________________________|
//

#include "CEquipmentFuelTankData.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{

	RTTI_IMPL(CEquipmentFuelTankData, CEquipmentData);

	//Konstruktor
	CEquipmentFuelTankData::CEquipmentFuelTankData()
	:
		CEquipmentData		(),//konstruktor klasy bazowej
		p_fueltank			(NULL)
	{
	}

	//Konstruktor kopiujacy
	CEquipmentFuelTankData::CEquipmentFuelTankData(const CEquipmentFuelTankData & CEquipmentFuelTankDataCopy)
	:
		CEquipmentData		(CEquipmentFuelTankDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_fueltank			(CEquipmentFuelTankDataCopy.p_fueltank)
	{
	}

	//Destruktor wirtualny
	CEquipmentFuelTankData::~CEquipmentFuelTankData()
	{
		//CEquipmentData	not edit
		if (p_fueltank)
			gPhysicalManager.DestroyPhysical(p_fueltank);
		p_fueltank			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentFuelTankData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CFuelTank
	CFuelTank* CEquipmentFuelTankData::getFuelTank()
	{
		return p_fueltank;
	}

	//Metoda ustawia wskaünik na obiekt klasy CFuelTank
	void CEquipmentFuelTankData::setFuelTank(CFuelTank* fueltank)
	{
		p_fueltank = fueltank;
	}
}//namespace equipmentdata
