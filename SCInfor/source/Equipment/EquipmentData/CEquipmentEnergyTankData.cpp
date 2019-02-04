//  _____________________________________________________
// | CEquipmentEnergyTankData.cpp - class implementation |
// | Jack Flower - May 2016                              |
// |_____________________________________________________|
//

#include "CEquipmentEnergyTankData.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{

	RTTI_IMPL(CEquipmentEnergyTankData, CEquipmentData);

	//Konstruktor
	CEquipmentEnergyTankData::CEquipmentEnergyTankData()
	:
		CEquipmentData		(),//konstruktor klasy bazowej
		p_energytank		(NULL)
	{
	}

	//Konstruktor kopiujacy
	CEquipmentEnergyTankData::CEquipmentEnergyTankData(const CEquipmentEnergyTankData & CEquipmentEnergylTankDataDataCopy)
	:
		CEquipmentData		(CEquipmentEnergylTankDataDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_energytank		(CEquipmentEnergylTankDataDataCopy.p_energytank)
	{
	}

	//Destruktor wirtualny
	CEquipmentEnergyTankData::~CEquipmentEnergyTankData()
	{
		//CEquipmentData	not edit
		if (p_energytank)
			gPhysicalManager.DestroyPhysical(p_energytank);
		p_energytank		= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentEnergyTankData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy EnergyTank
	EnergyTank* CEquipmentEnergyTankData::getEnergyTank()
	{
		return p_energytank;
	}

	//Metoda ustawia wskaünik na obiekt klasy EnergyTank
	void CEquipmentEnergyTankData::setEnergyTank(EnergyTank* energytank)
	{
		p_energytank = energytank;
	}
}//namespace equipmentdata
