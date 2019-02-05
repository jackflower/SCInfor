//  __________________________________________________
// | ThermalInsulationData.cpp - class implementation |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#include "ThermalInsulationData.h"
#include "../Thermodynamics//ThermalInsulation/CThermalInsulation.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(ThermalInsulationData, EquipmentData);

	//Konstruktor
	ThermalInsulationData::ThermalInsulationData()
	:
		EquipmentData(),//konstruktor klasy bazowej
		p_thermalinsulation(NULL)
	{
	}

	//Konstruktor kopiujący
	ThermalInsulationData::ThermalInsulationData(const ThermalInsulationData & ThermalInsulationDataCopy)
	:
		EquipmentData(ThermalInsulationDataCopy),//konstruktor kopiujący klasy bazowej
		p_thermalinsulation(ThermalInsulationDataCopy.p_thermalinsulation)
	{
	}

	//Destruktor wirtualny
	ThermalInsulationData::~ThermalInsulationData()
	{
		//EquipmentData	not edit
		if (p_thermalinsulation)
			gPhysicalManager.DestroyPhysical(p_thermalinsulation);
		p_thermalinsulation = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ThermalInsulationData::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy CThermalInsulation
	CThermalInsulation* ThermalInsulationData::getThermalInsulation()
	{
		return p_thermalinsulation;
	}

	//Metoda ustawia wskaźnik na obiekt klasy CThermalInsulation
	void ThermalInsulationData::setThermalInsulation(CThermalInsulation* thermalinsulation)
	{
		p_thermalinsulation = thermalinsulation;
	}
}//namespace equipmentdata
