//  _____________________________________________________
// | CEquipmentVentilatorData.cpp - class implementation |
// | Jack Flower - May 2016                              |
// |_____________________________________________________|
//

#include "CEquipmentVentilatorData.h"
#include "../Thermodynamics/Ventilator/CVentilator.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentVentilatorData, EquipmentData);

	//Konstruktor
	CEquipmentVentilatorData::CEquipmentVentilatorData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_ventilator	(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentVentilatorData::CEquipmentVentilatorData(const CEquipmentVentilatorData & CEquipmentVentilatorDataCopy)
	:
		EquipmentData	(CEquipmentVentilatorDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_ventilator	(CEquipmentVentilatorDataCopy.p_ventilator)
	{
	}

	//Destruktor wirtualny
	CEquipmentVentilatorData::~CEquipmentVentilatorData()
	{
		//EquipmentData	not edit
		if (p_ventilator)
			gPhysicalManager.DestroyPhysical(p_ventilator);
		p_ventilator = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentVentilatorData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CVentilator
	CVentilator* CEquipmentVentilatorData::getVentilator()
	{
		return p_ventilator;
	}

	//Metoda ustawia wskaünik na obiekt klasy CVentilator
	void CEquipmentVentilatorData::setVentilator(CVentilator* ventilator)
	{
		p_ventilator = ventilator;
	}
}//namespace equipmentdata
