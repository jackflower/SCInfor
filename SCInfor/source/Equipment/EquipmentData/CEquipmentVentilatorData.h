//  _____________________________________________________
// | CEquipmentVentilatorData.h - class definition       |
// | Jack Flower - May 2016                              |
// |_____________________________________________________|
//

#ifndef H_EQUIPMENT_VENTILATOR_DATA_JACK
#define H_EQUIPMENT_VENTILATOR_DATA_JACK

#include "CEquipmentData.h"

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
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - wentylator
	///
	class CEquipmentVentilatorData : public CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentVentilatorData();

		///
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentVentilatorDataCopy - sta≥a referencja na obiekt klasy CEquipmentVentilatorData
		///
		CEquipmentVentilatorData(const CEquipmentVentilatorData & CEquipmentVentilatorDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentVentilatorData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy CVentilator
		///
		CVentilator* getVentilator();

		///
		///Metoda ustawia wskaünik na obiekt klasy CVentilator
		///
		///@param *ventilator - wskaünik na obiekt klasy CVentilator
		///
		void setVentilator(CVentilator* ventilator);

	private:

		CVentilator*	p_ventilator;	//wskaünik na klasÍ CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_VENTILATOR_DATA_JACK
