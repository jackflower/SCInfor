//  _______________________________________________
// | CEquipmentAmmoData.h - class definition       |
// | Jack Flower - May 2016                        |
// |_______________________________________________|
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
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - amunicja
	///
	class CEquipmentAmmoData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentAmmoData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentAmmoDataCopy - sta�a referencja na obiekt klasy CEquipmentAmmoData
		///
		CEquipmentAmmoData(const CEquipmentAmmoData & CEquipmentAmmoDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentAmmoData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy CAmmo
		///
		CAmmo* getAmmo();

		///
		///Metoda ustawia wska�nik na obiekt klasy CAmmo
		///
		///@param *ammo - wska�nik na obiekt klasy CAmmo
		///
		void setAmmo(CAmmo* ammo);

	private:

		CAmmo*	p_ammo;	//wska�nik na klas� CAmmo - amunicja
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AMMO_DATA_JACK
