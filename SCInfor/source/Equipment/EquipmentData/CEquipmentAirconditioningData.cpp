//  __________________________________________________________
// | CEquipmentAirconditioningData.cpp - class implementation |
// | Jack Flower - May 2016                                   |
// |__________________________________________________________|
//

#include "CEquipmentAirconditioningData.h"
#include "../Thermodynamics//Airconditioning/CAirconditioning.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentAirconditioningData, CEquipmentData);

	//Konstruktor
	CEquipmentAirconditioningData::CEquipmentAirconditioningData()
	:
		CEquipmentData	(),//konstruktor klasy bazowej
		p_airconditiong	(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentAirconditioningData::CEquipmentAirconditioningData(const CEquipmentAirconditioningData & CEquipmentAirconditioningDataCopy)
	:
		CEquipmentData	(CEquipmentAirconditioningDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_airconditiong	(CEquipmentAirconditioningDataCopy.p_airconditiong)
	{
	}

	//Destruktor wirtualny
	CEquipmentAirconditioningData::~CEquipmentAirconditioningData()
	{
		//CEquipmentData	not edit
		if (p_airconditiong)
			gPhysicalManager.DestroyPhysical(p_airconditiong);
		p_airconditiong = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentAirconditioningData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CEngine
	CAirconditioning* CEquipmentAirconditioningData::getAirconditioning()
	{
		return p_airconditiong;
	}

	//Metoda ustawia wskaünik na obiekt klasy CEngine
	void CEquipmentAirconditioningData::setAirconditioning(CAirconditioning* airconditiong)
	{
		p_airconditiong = airconditiong;
	}
}//namespace equipmentdata
