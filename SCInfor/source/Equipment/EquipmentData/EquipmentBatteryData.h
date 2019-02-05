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
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - wentylator
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
		///Konstruktor kopiuj�cy
		///
		///@param EquipmentBatteryDataCopy - sta�a referencja na obiekt klasy EquipmentBatteryData
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
		///Metoda zwraca wska�nik na obiekt klasy Battery
		///
		Battery *getBattery();

		///
		///Metoda ustawia wska�nik na obiekt klasy Battery
		///
		///@param *battery - wska�nik na obiekt klasy Battery
		///
		void setBattery(Battery* battery);

	private:

		Battery *p_battery;	//wska�nik na klas� CVentilator - wentylator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_BATTERY_DATA_JACK
