//  __________________________________________________
// | CEquipmentBatteryData.cpp - class implementation |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#include "CEquipmentBatteryData.h"
#include "../Energy/Battery/Battery.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentBatteryData, EquipmentData);

	//Konstruktor
	CEquipmentBatteryData::CEquipmentBatteryData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_battery		(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentBatteryData::CEquipmentBatteryData(const CEquipmentBatteryData & CEquipmentBatteryDataaCopy)
	:
		EquipmentData	(CEquipmentBatteryDataaCopy),//konstruktor kopiujπcy klasy bazowej
		p_battery		(CEquipmentBatteryDataaCopy.p_battery)
	{
	}

	//Destruktor wirtualny
	CEquipmentBatteryData::~CEquipmentBatteryData()
	{
		//EquipmentData	not edit
		if (p_battery)
			gPhysicalManager.DestroyPhysical(p_battery);
		p_battery = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentBatteryData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CVentilator
	Battery* CEquipmentBatteryData::getBattery()
	{
		return p_battery;
	}

	//Metoda ustawia wskaünik na obiekt klasy CVentilator
	void CEquipmentBatteryData::setBattery(Battery* battery)
	{
		p_battery = battery;
	}
}//namespace equipmentdata
