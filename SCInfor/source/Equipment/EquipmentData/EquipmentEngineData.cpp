//  ________________________________________________
// | EquipmentEngineData.cpp - class implementation |
// | Jack Flower - May 2016                         |
// |________________________________________________|
//

#include "EquipmentEngineData.h"
#include "../Engine/Engine.h"
#include "../../Logic/PhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(EquipmentEngineData, EquipmentData);

	//Konstruktor
	EquipmentEngineData::EquipmentEngineData()
	:
		EquipmentData{},//konstruktor klasy bazowej
		p_engine{ NULL }
	{
	}

	//Konstruktor kopiujπcy
	EquipmentEngineData::EquipmentEngineData(const EquipmentEngineData & EquipmentEngineDataCopy)
	:
		EquipmentData{ EquipmentEngineDataCopy },//konstruktor kopiujπcy klasy bazowej
		p_engine{ EquipmentEngineDataCopy.p_engine }
	{
	}

	//Destruktor wirtualny
	EquipmentEngineData::~EquipmentEngineData()
	{
		//~EquipmentData()
		if (p_engine)
			gPhysicalManager.destroyPhysical(p_engine);
		p_engine = NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EquipmentEngineData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy Engine
	Engine *EquipmentEngineData::getEngine()
	{
		return p_engine;
	}

	//Metoda ustawia wskaünik na obiekt klasy Engine
	void EquipmentEngineData::setEngine(Engine *engine)
	{
		p_engine = engine;
	}
}//namespace equipmentdata
