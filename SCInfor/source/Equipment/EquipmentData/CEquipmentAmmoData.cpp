//  _______________________________________________
// | CEquipmentAmmoData.cpp - class implementation |
// | Jack Flower - May 2016                        |
// |_______________________________________________|
//

#include "CEquipmentAmmoData.h"
#include "../Weapon/Ammo/CAmmo.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentAmmoData, EquipmentData);

	//Konstruktor
	CEquipmentAmmoData::CEquipmentAmmoData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_ammo			(NULL)
	{
	}

	//Konstruktor kopiuj�cy
	CEquipmentAmmoData::CEquipmentAmmoData(const CEquipmentAmmoData & CEquipmentAmmoDataCopy)
	:
		EquipmentData	(CEquipmentAmmoDataCopy),//konstruktor kopiuj�cy klasy bazowej
		p_ammo			(CEquipmentAmmoDataCopy.p_ammo)
	{
	}

	//Destruktor wirtualny
	CEquipmentAmmoData::~CEquipmentAmmoData()
	{
		//EquipmentData	not edit
		if (p_ammo)
			gPhysicalManager.DestroyPhysical(p_ammo);
		p_ammo			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentAmmoData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wska�nik na obiekt klasy CAmmo
	CAmmo* CEquipmentAmmoData::getAmmo()
	{
		return p_ammo;
	}

	//Metoda ustawia wska�nik na obiekt klasy CAmmo
	void CEquipmentAmmoData::setAmmo(CAmmo* ammo)
	{
		p_ammo = ammo;
	}
}//namespace equipmentdata
