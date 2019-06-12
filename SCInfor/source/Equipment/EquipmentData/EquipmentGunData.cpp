//  _____________________________________________
// | EquipmentGunData.cpp - class implementation |
// | Jack Flower - May 2016                      |
// |_____________________________________________|
//

#include "EquipmentGunData.h"
#include "../Weapon/Gun/Gun.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentGunData, EquipmentData);

	//Konstruktor
	EquipmentGunData::EquipmentGunData()
	:
		EquipmentData{},//konstruktor klasy bazowej
		p_gun{ nullptr }
	{
	}

	//Konstruktor kopiujπcy
	EquipmentGunData::EquipmentGunData(const EquipmentGunData & EquipmentGunDataCopy)
	:
		EquipmentData{ EquipmentGunDataCopy },//konstruktor kopiujπcy klasy bazowej
		p_gun{ EquipmentGunDataCopy.p_gun }
	{
	}

	//Destruktor wirtualny
	EquipmentGunData::~EquipmentGunData()
	{
		//~EquipmentData()
		if (p_gun)
			gPhysicalManager.destroyPhysical(p_gun);
		p_gun = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentGunData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy Gun
	Gun *EquipmentGunData::getGun()
	{
		return p_gun;
	}

	//Metoda ustawia wskaünik na obiekt klasy Gun
	void EquipmentGunData::setGun(Gun *gun)
	{
		p_gun = gun;
	}
}//namespace equipmentdata
