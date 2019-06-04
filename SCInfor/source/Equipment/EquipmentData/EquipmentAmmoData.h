//  ______________________________________________
// | EquipmentAmmoData.h - class definition       |
// | Jack Flower - May 2016                       |
// |______________________________________________|
//

#ifndef H_EQUIPMENT_AMMO_DATA_JACK
#define H_EQUIPMENT_AMMO_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	namespace weapon
	{
		class Ammo;
	}
}

using namespace equipment::weapon;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - amunicja
	///
	class EquipmentAmmoData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentAmmoData();

		///
		///Konstruktor kopiujący
		///
		///@param EquipmentAmmoDataCopy - stała referencja na obiekt klasy EquipmentAmmoData
		///
		EquipmentAmmoData(const EquipmentAmmoData & EquipmentAmmoDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentAmmoData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy Ammo
		///
		Ammo *getAmmo();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Ammo
		///
		///@param *ammo - wskaźnik na obiekt klasy Ammo
		///
		void setAmmo(Ammo *ammo);

	private:

		Ammo *p_ammo; //wskaźnik na klasę Ammo - amunicja
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AMMO_DATA_JACK
