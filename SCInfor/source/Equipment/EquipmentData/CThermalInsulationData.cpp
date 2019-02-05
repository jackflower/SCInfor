//  ___________________________________________________
// | CThermalInsulationData.cpp - class implementation |
// | Jack Flower - May 2016                            |
// |___________________________________________________|
//

#include "CThermalInsulationData.h"
#include "../Thermodynamics//ThermalInsulation/CThermalInsulation.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CThermalInsulationData, EquipmentData);

	//Konstruktor
	CThermalInsulationData::CThermalInsulationData()
	:
		EquipmentData		(),//konstruktor klasy bazowej
		p_thermalinsulation	(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CThermalInsulationData::CThermalInsulationData(const CThermalInsulationData & CThermalInsulationDataCopy)
	:
		EquipmentData		(CThermalInsulationDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_thermalinsulation	(CThermalInsulationDataCopy.p_thermalinsulation)
	{
	}

	//Destruktor wirtualny
	CThermalInsulationData::~CThermalInsulationData()
	{
		//EquipmentData	not edit
		if (p_thermalinsulation)
			gPhysicalManager.DestroyPhysical(p_thermalinsulation);
		p_thermalinsulation = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CThermalInsulationData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy CThermalInsulation
	CThermalInsulation* CThermalInsulationData::getThermalInsulation()
	{
		return p_thermalinsulation;
	}

	//Metoda ustawia wskaünik na obiekt klasy CThermalInsulation
	void CThermalInsulationData::setThermalInsulation(CThermalInsulation* thermalinsulation)
	{
		p_thermalinsulation = thermalinsulation;
	}
}//namespace equipmentdata
