//  ________________________________________________
// | EquipmentEnergyData.cpp - class implementation |
// | Jack Flower - May 2016                         |
// |________________________________________________|
//

#include "EquipmentEnergyData.h"
#include "../Energy/Energy.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentEnergyData, EquipmentData);

	//Konstruktor
	EquipmentEnergyData::EquipmentEnergyData()
	:
		EquipmentData{},//konstruktor klasy bazowej
		p_energy{ NULL }
	{
	}

	//Konstruktor kopiujący
	EquipmentEnergyData::EquipmentEnergyData(const EquipmentEnergyData & EquipmentEnergyDataCopy)
	:
		EquipmentData{ EquipmentEnergyDataCopy },//konstruktor kopiujący klasy bazowej
		p_energy{ EquipmentEnergyDataCopy.p_energy }
	{
	}

	//Destruktor wirtualny
	EquipmentEnergyData::~EquipmentEnergyData()
	{
		//~EquipmentData()
		if (p_energy)
			gPhysicalManager.destroyPhysical(p_energy);
		p_energy = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentEnergyData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Energy
	Energy *EquipmentEnergyData::getEnergy()
	{
		return p_energy;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Energy
	void EquipmentEnergyData::setEnergy(Energy *energy)
	{
		p_energy = energy;
	}
}//namespace equipmentdata
