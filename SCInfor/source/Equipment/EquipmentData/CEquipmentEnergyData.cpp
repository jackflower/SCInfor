//  _________________________________________________
// | CEquipmentEnergyData.cpp - class implementation |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#include "CEquipmentEnergyData.h"
#include "../Energy/CEnergy.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentEnergyData, CEquipmentData);

	//Konstruktor
	CEquipmentEnergyData::CEquipmentEnergyData()
	:
		CEquipmentData(),//konstruktor klasy bazowej
		p_energy(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentEnergyData::CEquipmentEnergyData(const CEquipmentEnergyData & CEquipmentEnergyDataCopy)
	:
		CEquipmentData(CEquipmentEnergyDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_energy(CEquipmentEnergyDataCopy.p_energy)
	{
	}

	//Destruktor wirtualny
	CEquipmentEnergyData::~CEquipmentEnergyData()
	{
		//CEquipmentData	not edit
		if (p_energy)
			gPhysicalManager.DestroyPhysical(p_energy);
		p_energy = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentEnergyData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CEngine
	CEnergy* CEquipmentEnergyData::getEnergy()
	{
		return p_energy;
	}

	//Metoda ustawia wskaünik na obiekt klasy CEngine
	void CEquipmentEnergyData::setEnergy(CEnergy* energy)
	{
		p_energy = energy;
	}
}//namespace equipmentdata
