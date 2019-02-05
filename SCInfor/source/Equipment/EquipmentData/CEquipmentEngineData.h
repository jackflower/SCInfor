//  _________________________________________________
// | CEquipmentEngineData.h - class definition       |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
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
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - silnik
	///
	class CEquipmentEngineData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentEngineData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentEngineDataCopy - sta�a referencja na obiekt klasy CEquipmentEngineData
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
		///Metoda zwraca wska�nik na obiekt klasy Engine
		///
		Engine* getEngine();

		///
		///Metoda ustawia wska�nik na obiekt klasy Engine
		///
		///@param *engine - wska�nik na obiekt klasy Engine
		///
		void setEngine(Engine* engine);

	private:

		Engine*	p_engine;	//wska�nik na klas� Engine - silnik
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENGINE_DATA_JACK
