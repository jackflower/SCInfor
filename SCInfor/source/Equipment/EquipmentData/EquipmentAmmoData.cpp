//  ______________________________________________
// | EquipmentAmmoData.cpp - class implementation |
// | Jack Flower - May 2016                       |
// |______________________________________________|
//

#include "EquipmentAmmoData.h"
#include "../Weapon/Ammo/CAmmo.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentAmmoData, EquipmentData);

	//Konstruktor
	EquipmentAmmoData::EquipmentAmmoData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_ammo(NULL)
	{
	}

	//Konstruktor kopiujπcy
	EquipmentAmmoData::EquipmentAmmoData(const EquipmentAmmoData & EquipmentAmmoDataCopy)
	:
		EquipmentData(EquipmentAmmoDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_ammo(EquipmentAmmoDataCopy.p_ammo)
	{
	}

	//Destruktor wirtualny
	EquipmentAmmoData::~EquipmentAmmoData()
	{
		//EquipmentData
		if (p_ammo)
			gPhysicalManager.DestroyPhysical(p_ammo);
		p_ammo = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentAmmoData::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CAmmo
	CAmmo* EquipmentAmmoData::getAmmo()
	{
		return p_ammo;
	}

	//Metoda ustawia wskaünik na obiekt klasy CAmmo
	void EquipmentAmmoData::setAmmo(CAmmo* ammo)
	{
		p_ammo = ammo;
	}
}//namespace equipmentdata
