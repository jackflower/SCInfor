//  ____________________________________________________
// | EquipmentVentilatorData.h - class definition       |
// | Jack Flower - May 2016                             |
// |____________________________________________________|
//

#ifndef H_EQUIPMENT_VENTILATOR_DATA_JACK
#define H_EQUIPMENT_VENTILATOR_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class Ventilator;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - wentylator
	///
	class EquipmentVentilatorData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentVentilatorData();

		///
		///Konstruktor kopiujący
		///
		///@param EquipmentVentilatorDataCopy - stała referencja na obiekt klasy EquipmentVentilatorData
		///
		EquipmentVentilatorData(const EquipmentVentilatorData & EquipmentVentilatorDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentVentilatorData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy Ventilator
		///
		Ventilator* getVentilator();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Ventilator
		///
		///@param *ventilator - wskaźnik na obiekt klasy Ventilator
		///
		void setVentilator(Ventilator * ventilator);

	private:

		Ventilator *p_ventilator;	//wskaźnik na klasę Ventilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_VENTILATOR_DATA_JACK
