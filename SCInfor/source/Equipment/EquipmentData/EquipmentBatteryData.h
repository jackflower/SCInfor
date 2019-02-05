//  _________________________________________________
// | EquipmentBatteryData.h - class definition       |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#ifndef H_EQUIPMENT_BATTERY_DATA_JACK
#define H_EQUIPMENT_BATTERY_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	namespace battery
	{
		class Battery;
	}
}

using namespace equipment;
using namespace equipment::battery;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - wentylator
	///
	class EquipmentBatteryData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentBatteryData();

		///
		///Konstruktor kopiujπcy
		///
		///@param EquipmentBatteryDataCopy - sta≥a referencja na obiekt klasy EquipmentBatteryData
		///
		EquipmentBatteryData(const EquipmentBatteryData & EquipmentBatteryDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentBatteryData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy Battery
		///
		Battery *getBattery();

		///
		///Metoda ustawia wskaünik na obiekt klasy Battery
		///
		///@param *battery - wskaünik na obiekt klasy Battery
		///
		void setBattery(Battery* battery);

	private:

		Battery *p_battery;	//wskaünik na klasÍ CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_BATTERY_DATA_JACK
