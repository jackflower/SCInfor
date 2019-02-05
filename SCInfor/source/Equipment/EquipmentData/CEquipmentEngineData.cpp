//  _________________________________________________
// | CEquipmentEngineData.cpp - class implementation |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#include "CEquipmentEngineData.h"
#include "../Engine/Engine.h"
#include "../../Logic/CPhysicalManager.h"

namespace equipmentdata
{
	RTTI_IMPL(CEquipmentEngineData, EquipmentData);

	//Konstruktor
	CEquipmentEngineData::CEquipmentEngineData()
	:
		EquipmentData		(),//konstruktor klasy bazowej
		p_engine			(NULL)
	{
	}

	//Konstruktor kopiujπcy
	CEquipmentEngineData::CEquipmentEngineData(const CEquipmentEngineData & CEquipmentEngineDataCopy)
	:
		EquipmentData		(CEquipmentEngineDataCopy),//konstruktor kopiujπcy klasy bazowej
		p_engine			(CEquipmentEngineDataCopy.p_engine)
	{
	}

	//Destruktor wirtualny
	CEquipmentEngineData::~CEquipmentEngineData()
	{
		//EquipmentData	not edit
		if (p_engine)
			gPhysicalManager.DestroyPhysical(p_engine);
		p_engine			= NULL;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEquipmentEngineData::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wskaünik na obiekt klasy Engine
	Engine* CEquipmentEngineData::getEngine()
	{
		return p_engine;
	}

	//Metoda ustawia wskaünik na obiekt klasy Engine
	void CEquipmentEngineData::setEngine(Engine* engine)
	{
		p_engine = engine;
	}
}//namespace equipmentdata
