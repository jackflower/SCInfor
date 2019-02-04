//  __________________________________________________
// | CEquipmentBatteryData.cpp - class implementation |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#include "CEquipmentBatteryData.h"
#include "../Energy/Battery/CBattery.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentBatteryData, CEquipmentData);

	//Konstruktor
	CEquipmentBatteryData::CEquipmentBatteryData()
	:
		CEquipmentData	(),//konstruktor klasy bazowej
		p_battery		(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentBatteryData::CEquipmentBatteryData(const CEquipmentBatteryData & CEquipmentBatteryDataaCopy)
	:
		CEquipmentData	(CEquipmentBatteryDataaCopy),//konstruktor kopiujπcy klasy bazowej
		p_battery		(CEquipmentBatteryDataaCopy.p_battery)
	{
	}

	//Destruktor wirtualny
	CEquipmentBatteryData::~CEquipmentBatteryData()
	{
		//CEquipmentData	not edit
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
	CBattery* CEquipmentBatteryData::getBattery()
	{
		return p_battery;
	}

	//Metoda ustawia wskaünik na obiekt klasy CVentilator
	void CEquipmentBatteryData::setBattery(CBattery* battery)
	{
		p_battery = battery;
	}
}//namespace equipmentdata
