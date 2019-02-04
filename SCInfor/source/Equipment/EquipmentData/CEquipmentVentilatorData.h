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
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - wentylator
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
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentVentilatorDataCopy - sta�a referencja na obiekt klasy CEquipmentVentilatorData
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
		///Metoda zwraca wska�nik na obiekt klasy CVentilator
		///
		CVentilator* getVentilator();

		///
		///Metoda ustawia wska�nik na obiekt klasy CVentilator
		///
		///@param *ventilator - wska�nik na obiekt klasy CVentilator
		///
		void setVentilator(CVentilator* ventilator);

	private:

		CVentilator*	p_ventilator;	//wska�nik na klas� CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_VENTILATOR_DATA_JACK
