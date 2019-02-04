//  __________________________________________________
// | CEquipmentBatteryData.h - class definition       |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#ifndef H_EQUIPMENT_BATTERY_DATA_JACK
#define H_EQUIPMENT_BATTERY_DATA_JACK

#include "CEquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	namespace battery
	{
		class CBattery;
	}
}

using namespace equipment;
using namespace equipment::battery;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - wentylator
	///
	class CEquipmentBatteryData : public CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentBatteryData();

		///
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentBatteryDataCopy - sta≥a referencja na obiekt klasy CEquipmentBatteryData
		///
		CEquipmentBatteryData(const CEquipmentBatteryData & CEquipmentBatteryDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentBatteryData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy CBattery
		///
		CBattery* getBattery();

		///
		///Metoda ustawia wskaünik na obiekt klasy CBattery
		///
		///@param *battery - wskaünik na obiekt klasy CBattery
		///
		void setBattery(CBattery* battery);

	private:

		CBattery*	p_battery;	//wskaünik na klasÍ CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_BATTERY_DATA_JACK
