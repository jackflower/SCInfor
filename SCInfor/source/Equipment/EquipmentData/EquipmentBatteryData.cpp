//  _________________________________________________
// | EquipmentBatteryData.cpp - class implementation |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#include "EquipmentBatteryData.h"
#include "../Energy/Battery/Battery.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentBatteryData, EquipmentData);

	//Konstruktor
	EquipmentBatteryData::EquipmentBatteryData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_battery(NULL)
	{
	}

	//Konstruktor kopiuj�cy
	EquipmentBatteryData::EquipmentBatteryData(const EquipmentBatteryData & EquipmentBatteryDataaCopy)
	:
		EquipmentData(EquipmentBatteryDataaCopy),//konstruktor kopiuj�cy klasy bazowej
		p_battery(EquipmentBatteryDataaCopy.p_battery)
	{
	}

	//Destruktor wirtualny
	EquipmentBatteryData::~EquipmentBatteryData()
	{
		//EquipmentData
		if (p_battery)
			gPhysicalManager.DestroyPhysical(p_battery);
		p_battery = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentBatteryData::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wska�nik na obiekt klasy CVentilator
	Battery *EquipmentBatteryData::getBattery()
	{
		return p_battery;
	}

	//Metoda ustawia wska�nik na obiekt klasy CVentilator
	void EquipmentBatteryData::setBattery(Battery* battery)
	{
		p_battery = battery;
	}
}//namespace equipmentdata
