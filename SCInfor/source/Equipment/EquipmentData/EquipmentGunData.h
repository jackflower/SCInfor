//  _____________________________________________
// | EquipmentGunData.h - class definition       |
// | Jack Flower - May 2016                      |
// |_____________________________________________|
//

#ifndef H_EQUIPMENT_GUN_DATA_JACK
#define H_EQUIPMENT_GUN_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	namespace weapon
	{
		class CGun;
	}
}

using namespace equipment::weapon;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - dzia�o
	///
	class EquipmentGunData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentGunData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param EquipmentGunDataCopy - sta�a referencja na obiekt klasy EquipmentGunData
		///
		EquipmentGunData(const EquipmentGunData & EquipmentGunDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentGunData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy CGun
		///
		CGun *getGun();

		///
		///Metoda ustawia wska�nik na obiekt klasy CGun
		///
		///@param *gun - wska�nik na obiekt klasy CGun
		///
		void setGun(CGun *gun);

	private:

		CGun *p_gun; //wska�nik na klas� CGun - dzia�o
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_GUN_DATA_JACK
