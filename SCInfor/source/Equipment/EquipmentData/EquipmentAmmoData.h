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
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - amunicja
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
		///Konstruktor kopiujπcy
		///
		///@param EquipmentAmmoDataCopy - sta≥a referencja na obiekt klasy EquipmentAmmoData
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
		///Metoda zwraca wskaünik na obiekt klasy CAmmo
		///
		CAmmo* getAmmo();

		///
		///Metoda ustawia wskaünik na obiekt klasy CAmmo
		///
		///@param *ammo - wskaünik na obiekt klasy CAmmo
		///
		void setAmmo(CAmmo * ammo);

	private:

		CAmmo *p_ammo;	//wskaünik na klasÍ CAmmo - amunicja
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AMMO_DATA_JACK
