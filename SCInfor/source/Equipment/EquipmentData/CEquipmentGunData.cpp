//  ______________________________________________
// | CEquipmentGunData.cpp - class implementation |
// | Jack Flower - May 2016                       |
// |______________________________________________|
//

#include "CEquipmentGunData.h"
#include "../Weapon/Gun/CGun.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentGunData, EquipmentData);

	//Konstruktor
	CEquipmentGunData::CEquipmentGunData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_gun			(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentGunData::CEquipmentGunData(const CEquipmentGunData & CEquipmentGunDataCopy)
	:
		EquipmentData	(CEquipmentGunDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_gun			(CEquipmentGunDataCopy.p_gun)
	{
	}

	//Destruktor wirtualny
	CEquipmentGunData::~CEquipmentGunData()
	{
		//EquipmentData	not edit
		if (p_gun)
			gPhysicalManager.DestroyPhysical(p_gun);
		p_gun			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentGunData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CGun
	CGun* CEquipmentGunData::getGun()
	{
		return p_gun;
	}

	//Metoda ustawia wskaünik na obiekt klasy CGun
	void CEquipmentGunData::setGun(CGun* gun)
	{
		p_gun = gun;
	}
}//namespace equipmentdata
