//  _________________________________________________________
// | EquipmentAirconditioningData.cpp - class implementation |
// | Jack Flower - May 2016                                  |
// |_________________________________________________________|
//

#include "EquipmentAirconditioningData.h"
#include "../Thermodynamics//Airconditioning/Airconditioning.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentAirconditioningData, EquipmentData);

	//Konstruktor
	EquipmentAirconditioningData::EquipmentAirconditioningData()
	:
		EquipmentData{},//konstruktor klasy bazowej
		p_airconditiong{ nullptr }
	{
	}

	//Konstruktor kopiujący
	EquipmentAirconditioningData::EquipmentAirconditioningData(const EquipmentAirconditioningData & EquipmentAirconditioningDataCopy)
	:
		EquipmentData{ EquipmentAirconditioningDataCopy },//konstruktor kopiujący klasy bazowej
		p_airconditiong{ EquipmentAirconditioningDataCopy.p_airconditiong }
	{
	}

	//Destruktor wirtualny
	EquipmentAirconditioningData::~EquipmentAirconditioningData()
	{
		//~EquipmentData()
		if (p_airconditiong)
			gPhysicalManager.destroyPhysical(p_airconditiong);
		p_airconditiong = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentAirconditioningData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy Engine
	Airconditioning *EquipmentAirconditioningData::getAirconditioning()
	{
		return p_airconditiong;
	}

	//Metoda ustawia wskaźnik na obiekt klasy Engine
	void EquipmentAirconditioningData::setAirconditioning(Airconditioning *airconditiong)
	{
		p_airconditiong = airconditiong;
	}
}//namespace equipmentdata
