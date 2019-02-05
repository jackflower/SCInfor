//  ______________________________________________
// | CEquipmentGunData.h - class definition       |
// | Jack Flower - May 2016                       |
// |______________________________________________|
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
	class CEquipmentGunData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentGunData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentGunDataCopy - sta�a referencja na obiekt klasy CEquipmentGunData
		///
		CEquipmentGunData(const CEquipmentGunData & CEquipmentGunDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentGunData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy CGun
		///
		CGun* getGun();

		///
		///Metoda ustawia wska�nik na obiekt klasy CGun
		///
		///@param *gun - wska�nik na obiekt klasy CGun
		///
		void setGun(CGun* gun);

	private:

		CGun*	p_gun;	//wska�nik na klas� CGun - dzia�o
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_GUN_DATA_JACK
