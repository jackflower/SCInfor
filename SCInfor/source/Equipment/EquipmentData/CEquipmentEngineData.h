//  _________________________________________________
// | CEquipmentEngineData.h - class definition       |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#ifndef H_EQUIPMENT_ENGINE_DATA_JACK
#define H_EQUIPMENT_ENGINE_DATA_JACK

#include "CEquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class CEngine;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - silnik
	///
	class CEquipmentEngineData : public CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentEngineData();

		///
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentEngineDataCopy - sta≥a referencja na obiekt klasy CEquipmentEngineData
		///
		CEquipmentEngineData(const CEquipmentEngineData & CEquipmentEngineDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentEngineData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy CEngine
		///
		CEngine* getEngine();

		///
		///Metoda ustawia wskaünik na obiekt klasy CEngine
		///
		///@param *engine - wskaünik na obiekt klasy CEngine
		///
		void setEngine(CEngine* engine);

	private:

		CEngine*	p_engine;	//wskaünik na klasÍ CEngine - silnik
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENGINE_DATA_JACK
