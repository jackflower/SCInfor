//  ______________________________________________
// | EquipmentAmmoData.cpp - class implementation |
// | Jack Flower - May 2016                       |
// |______________________________________________|
//

#include "EquipmentAmmoData.h"
#include "../Weapon/Ammo/Ammo.h"
#include "../../Logic/PhysicalManager.h"

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

	//Konstruktor kopiujący
	EquipmentAmmoData::EquipmentAmmoData(const EquipmentAmmoData & EquipmentAmmoDataCopy)
	:
		EquipmentData(EquipmentAmmoDataCopy),//konstruktor kopiujący klasy bazowej
		p_ammo(EquipmentAmmoDataCopy.p_ammo)
	{
	}

	//Destruktor wirtualny
	EquipmentAmmoData::~EquipmentAmmoData()
	{
		//EquipmentData
		if (p_ammo)
			gPhysicalManager.destroyPhysical(p_ammo);
		p_ammo = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentAmmoData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Ammo
	Ammo* EquipmentAmmoData::getAmmo()
	{
		return p_ammo;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Ammo
	void EquipmentAmmoData::setAmmo(Ammo* ammo)
	{
		p_ammo = ammo;
	}
}//namespace equipmentdata
