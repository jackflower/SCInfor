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
		class CAmmo;
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
		///Metoda zwraca wskaźnik na obiekt klasy CAmmo
		///
		CAmmo* getAmmo();

		///
		///Metoda ustawia wskaźnik na obiekt klasy CAmmo
		///
		///@param *ammo - wskaźnik na obiekt klasy CAmmo
		///
		void setAmmo(CAmmo * ammo);

	private:

		CAmmo *p_ammo;	//wskaźnik na klasę CAmmo - amunicja
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AMMO_DATA_JACK
