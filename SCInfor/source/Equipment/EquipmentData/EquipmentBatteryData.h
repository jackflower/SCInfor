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
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - wentylator
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
		///Konstruktor kopiujący
		///
		///@param EquipmentBatteryDataCopy - stała referencja na obiekt klasy EquipmentBatteryData
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
		///Metoda zwraca wskaźnik na obiekt klasy Battery
		///
		Battery *getBattery();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Battery
		///
		///@param *battery - wskaźnik na obiekt klasy Battery
		///
		void setBattery(Battery* battery);

	private:

		Battery *p_battery;	//wskaźnik na klasę CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_BATTERY_DATA_JACK
