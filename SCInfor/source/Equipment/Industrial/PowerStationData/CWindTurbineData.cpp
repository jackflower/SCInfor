//  _____________________________________________
// | CWindTurbineData.cpp - class implementation |
// | Jack Flower - May 2016                      |
// |_____________________________________________|
//

#include "CWindTurbineData.h"
#include "../PowerModuleType/WindTurbine.h"
#include "../../../Logic/CPhysicalManager.h"

namespace equipmentpowerstationdata
{
	RTTI_IMPL(CWindTurbineData, EquipmentData);

	//Konstruktor
	CWindTurbineData::CWindTurbineData()
	:
		EquipmentData	(),//konstruktor klasy bazowej
		p_turbine		(NULL)
	{
	}

	//Konstruktor kopiuj�cy
	CWindTurbineData::CWindTurbineData(const CWindTurbineData & CWindTurbineDataCopy)
	:
		EquipmentData	(CWindTurbineDataCopy),//konstruktor kopiuj�cy klasy bazowej
		p_turbine		(CWindTurbineDataCopy.p_turbine)
	{
	}

	//Destruktor wirtualny
	CWindTurbineData::~CWindTurbineData()
	{
		//EquipmentData	not edit
		if (p_turbine)
			gPhysicalManager.DestroyPhysical(p_turbine);
		p_turbine = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CWindTurbineData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wska�nik na obiekt klasy WindTurbine
	WindTurbine* CWindTurbineData::getTurbine()
	{
		return p_turbine;
	}

	//Metoda ustawia wska�nik na obiekt klasy WindTurbine
	void CWindTurbineData::setTurbine(WindTurbine* turbine)
	{
		p_turbine = turbine;
	}
}//namespace equipmentpowerstationdata
