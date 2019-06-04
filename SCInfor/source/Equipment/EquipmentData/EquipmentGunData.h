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
		class Gun;
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
		///Metoda zwraca wska�nik na obiekt klasy Gun
		///
		Gun *getGun();

		///
		///Metoda ustawia wska�nik na obiekt klasy Gun
		///
		///@param *gun - wska�nik na obiekt klasy Gun
		///
		void setGun(Gun *gun);

	private:

		Gun *p_gun; //wska�nik na klas� Gun - dzia�o obiektu
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_GUN_DATA_JACK
