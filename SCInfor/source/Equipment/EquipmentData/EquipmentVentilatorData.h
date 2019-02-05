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
	class CVentilator;
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
		///Metoda zwraca wskaźnik na obiekt klasy CVentilator
		///
		CVentilator* getVentilator();

		///
		///Metoda ustawia wskaźnik na obiekt klasy CVentilator
		///
		///@param *ventilator - wskaźnik na obiekt klasy CVentilator
		///
		void setVentilator(CVentilator * ventilator);

	private:

		CVentilator *p_ventilator;	//wskaźnik na klasę CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_VENTILATOR_DATA_JACK
