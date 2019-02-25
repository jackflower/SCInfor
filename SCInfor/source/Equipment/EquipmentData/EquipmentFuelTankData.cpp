//  __________________________________________________
// | EquipmentFuelTankData.cpp - class implementation |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#include "EquipmentFuelTankData.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{

	RTTI_IMPL(EquipmentFuelTankData, EquipmentData);

	//Konstruktor
	EquipmentFuelTankData::EquipmentFuelTankData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_fueltank(NULL)
	{
	}

	//Konstruktor kopiujacy
	EquipmentFuelTankData::EquipmentFuelTankData(const EquipmentFuelTankData & EquipmentFuelTankDataCopy)
	:
		EquipmentData(EquipmentFuelTankDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_fueltank(EquipmentFuelTankDataCopy.p_fueltank)
	{
	}

	//Destruktor wirtualny
	EquipmentFuelTankData::~EquipmentFuelTankData()
	{
		//EquipmentData
		if (p_fueltank)
			gPhysicalManager.destroyPhysical(p_fueltank);
		p_fueltank = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentFuelTankData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy FuelTank
	FuelTank *EquipmentFuelTankData::getFuelTank()
	{
		return p_fueltank;
	}

	//Metoda ustawia wskaünik na obiekt klasy FuelTank
	void EquipmentFuelTankData::setFuelTank(FuelTank* fueltank)
	{
		p_fueltank = fueltank;
	}
}//namespace equipmentdata
