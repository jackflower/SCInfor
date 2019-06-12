//  ____________________________________________
// | WindTurbineData.cpp - class implementation |
// | Jack Flower - May 2016                     |
// |____________________________________________|
//

#include "WindTurbineData.h"
#include "../PowerModuleType/WindTurbine.h"
#include "../../../Logic/PhysicalManager.h"

namespace equipmentpowerstationdata
{
	RTTI_IMPL(WindTurbineData, EquipmentData);

	//Konstruktor
	WindTurbineData::WindTurbineData()
	:
		EquipmentData{},//konstruktor klasy bazowej
		p_turbine{ nullptr }
	{
	}

	//Konstruktor kopiujący
	WindTurbineData::WindTurbineData(const WindTurbineData & WindTurbineDataCopy)
	:
		EquipmentData{ WindTurbineDataCopy },//konstruktor kopiujący klasy bazowej
		p_turbine{ WindTurbineDataCopy.p_turbine }
	{
	}

	//Destruktor wirtualny
	WindTurbineData::~WindTurbineData()
	{
		//~EquipmentData()
		if (p_turbine)
			gPhysicalManager.destroyPhysical(p_turbine);
		p_turbine = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string WindTurbineData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaźnik na obiekt klasy WindTurbine
	WindTurbine *WindTurbineData::getTurbine()
	{
		return p_turbine;
	}

	//Metoda ustawia wskaźnik na obiekt klasy WindTurbine
	void WindTurbineData::setTurbine(WindTurbine *turbine)
	{
		p_turbine = turbine;
	}
}//namespace equipmentpowerstationdata
