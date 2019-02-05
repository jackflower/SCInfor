//  _________________________________________________________
// | EquipmentAirconditioningData.cpp - class implementation |
// | Jack Flower - May 2016                                  |
// |_________________________________________________________|
//

#include "EquipmentAirconditioningData.h"
#include "../Thermodynamics//Airconditioning/CAirconditioning.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentAirconditioningData, EquipmentData);

	//Konstruktor
	EquipmentAirconditioningData::EquipmentAirconditioningData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_airconditiong	(NULL)
	{
	}

	//Konstruktor kopiujπcy
	EquipmentAirconditioningData::EquipmentAirconditioningData(const EquipmentAirconditioningData & EquipmentAirconditioningDataCopy)
	:
		EquipmentData(EquipmentAirconditioningDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_airconditiong(EquipmentAirconditioningDataCopy.p_airconditiong)
	{
	}

	//Destruktor wirtualny
	EquipmentAirconditioningData::~EquipmentAirconditioningData()
	{
		//EquipmentData
		if (p_airconditiong)
			gPhysicalManager.DestroyPhysical(p_airconditiong);
		p_airconditiong = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentAirconditioningData::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy Engine
	CAirconditioning* EquipmentAirconditioningData::getAirconditioning()
	{
		return p_airconditiong;
	}

	//Metoda ustawia wskaünik na obiekt klasy Engine
	void EquipmentAirconditioningData::setAirconditioning(CAirconditioning* airconditiong)
	{
		p_airconditiong = airconditiong;
	}
}//namespace equipmentdata
