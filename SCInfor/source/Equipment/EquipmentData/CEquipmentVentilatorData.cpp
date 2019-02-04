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
	RTTI_IMPL(CEquipmentVentilatorData, CEquipmentData);

	//Konstruktor
	CEquipmentVentilatorData::CEquipmentVentilatorData()
	:
		CEquipmentData	(),//konstruktor klasy bazowej
		p_ventilator	(NULL)
	{
	}

	//Konstruktor kopiuj�cy
	CEquipmentVentilatorData::CEquipmentVentilatorData(const CEquipmentVentilatorData & CEquipmentVentilatorDataCopy)
	:
		CEquipmentData	(CEquipmentVentilatorDataCopy),//konstruktor kopiuj�cy klasy bazowej
		p_ventilator	(CEquipmentVentilatorDataCopy.p_ventilator)
	{
	}

	//Destruktor wirtualny
	CEquipmentVentilatorData::~CEquipmentVentilatorData()
	{
		//CEquipmentData	not edit
		if (p_ventilator)
			gPhysicalManager.DestroyPhysical(p_ventilator);
		p_ventilator = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentVentilatorData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wska�nik na obiekt klasy CVentilator
	CVentilator* CEquipmentVentilatorData::getVentilator()
	{
		return p_ventilator;
	}

	//Metoda ustawia wska�nik na obiekt klasy CVentilator
	void CEquipmentVentilatorData::setVentilator(CVentilator* ventilator)
	{
		p_ventilator = ventilator;
	}
}//namespace equipmentdata
