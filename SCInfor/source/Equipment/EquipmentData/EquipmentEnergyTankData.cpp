//  ____________________________________________________
// | EquipmentEnergyTankData.cpp - class implementation |
// | Jack Flower - May 2016                             |
// |____________________________________________________|
//

#include "EquipmentEnergyTankData.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{

	RTTI_IMPL(EquipmentEnergyTankData, EquipmentData);

	//Konstruktor
	EquipmentEnergyTankData::EquipmentEnergyTankData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_energytank(NULL)
	{
	}

	//Konstruktor kopiujacy
	EquipmentEnergyTankData::EquipmentEnergyTankData(const EquipmentEnergyTankData & EquipmentEnergylTankDataDataCopy)
	:
		EquipmentData(EquipmentEnergylTankDataDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_energytank(EquipmentEnergylTankDataDataCopy.p_energytank)
	{
	}

	//Destruktor wirtualny
	EquipmentEnergyTankData::~EquipmentEnergyTankData()
	{
		//EquipmentData
		if (p_energytank)
			gPhysicalManager.destroyPhysical(p_energytank);
		p_energytank = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentEnergyTankData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy EnergyTank
	EnergyTank* EquipmentEnergyTankData::getEnergyTank()
	{
		return p_energytank;
	}

	//Metoda ustawia wskaünik na obiekt klasy EnergyTank
	void EquipmentEnergyTankData::setEnergyTank(EnergyTank *energytank)
	{
		p_energytank = energytank;
	}
}//namespace equipmentdata
