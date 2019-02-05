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
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - dzia≥o
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
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentGunDataCopy - sta≥a referencja na obiekt klasy CEquipmentGunData
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
		///Metoda zwraca wskaünik na obiekt klasy CGun
		///
		CGun* getGun();

		///
		///Metoda ustawia wskaünik na obiekt klasy CGun
		///
		///@param *gun - wskaünik na obiekt klasy CGun
		///
		void setGun(CGun* gun);

	private:

		CGun*	p_gun;	//wskaünik na klasÍ CGun - dzia≥o
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_GUN_DATA_JACK
