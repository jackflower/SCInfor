//  __________________________________________________
// | ThermalInsulationData.cpp - class implementation |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#include "ThermalInsulationData.h"
#include "../Thermodynamics//ThermalInsulation/ThermalInsulation.h"
#include "../../Logic/PhysicalManager.h"

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
			gPhysicalManager.destroyPhysical(p_thermalinsulation);
		p_thermalinsulation = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ThermalInsulationData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy ThermalInsulation
	ThermalInsulation* ThermalInsulationData::getThermalInsulation()
	{
		return p_thermalinsulation;
	}

	//Metoda ustawia wskaźnik na obiekt klasy ThermalInsulation
	void ThermalInsulationData::setThermalInsulation(ThermalInsulation* thermalinsulation)
	{
		p_thermalinsulation = thermalinsulation;
	}
}//namespace equipmentdata
