//  _____________________________________________________
// | CEquipmentEnergyTankData.cpp - class implementation |
// | Jack Flower - May 2016                              |
// |_____________________________________________________|
//

#include "CEquipmentEnergyTankData.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{

	RTTI_IMPL(CEquipmentEnergyTankData, EquipmentData);

	//Konstruktor
	CEquipmentEnergyTankData::CEquipmentEnergyTankData()
	:
		EquipmentData		(),//konstruktor klasy bazowej
		p_energytank		(NULL)
	{
	}

	//Konstruktor kopiujacy
	CEquipmentEnergyTankData::CEquipmentEnergyTankData(const CEquipmentEnergyTankData & CEquipmentEnergylTankDataDataCopy)
	:
		EquipmentData		(CEquipmentEnergylTankDataDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_energytank		(CEquipmentEnergylTankDataDataCopy.p_energytank)
	{
	}

	//Destruktor wirtualny
	CEquipmentEnergyTankData::~CEquipmentEnergyTankData()
	{
		//EquipmentData	not edit
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
