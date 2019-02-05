//  _________________________________________________
// | CEquipmentEnergyData.cpp - class implementation |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#include "CEquipmentEnergyData.h"
#include "../Energy/Energy.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentEnergyData, EquipmentData);

	//Konstruktor
	CEquipmentEnergyData::CEquipmentEnergyData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_energy(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentEnergyData::CEquipmentEnergyData(const CEquipmentEnergyData & CEquipmentEnergyDataCopy)
	:
		EquipmentData(CEquipmentEnergyDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_energy(CEquipmentEnergyDataCopy.p_energy)
	{
	}

	//Destruktor wirtualny
	CEquipmentEnergyData::~CEquipmentEnergyData()
	{
		//EquipmentData	not edit
		if (p_energy)
			gPhysicalManager.DestroyPhysical(p_energy);
		p_energy = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentEnergyData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy Energy
	Energy* CEquipmentEnergyData::getEnergy()
	{
		return p_energy;
	}

	//Metoda ustawia wskaünik na obiekt klasy Energy
	void CEquipmentEnergyData::setEnergy(Energy* energy)
	{
		p_energy = energy;
	}
}//namespace equipmentdata
