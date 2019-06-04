//  ________________________________________________
// | EquipmentEngineData.h - class definition       |
// | Jack Flower - May 2016                         |
// |________________________________________________|
//

#ifndef H_EQUIPMENT_ENGINE_DATA_JACK
#define H_EQUIPMENT_ENGINE_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class Engine;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - silnik
	///
	class EquipmentEngineData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentEngineData();

		///
		///Konstruktor kopiujπcy
		///
		///@param EquipmentEngineDataCopy - sta≥a referencja na obiekt klasy EquipmentEngineData
		///
		EquipmentEngineData(const EquipmentEngineData & EquipmentEngineDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentEngineData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy Engine
		///
		Engine *getEngine();

		///
		///Metoda ustawia wskaünik na obiekt klasy Engine
		///
		///@param *engine - wskaünik na obiekt klasy Engine
		///
		void setEngine(Engine *engine);

	private:

		Engine *p_engine; //wskaünik na klasÍ Engine - silnik obiektu
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENGINE_DATA_JACK
