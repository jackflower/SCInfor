//  _________________________________________________________
// | EquipmentAirconditioningData.h - class definition       |
// | Jack Flower - May 2016                                  |
// |_________________________________________________________|
//

#ifndef H_EQUIPMENT_AIRCONDITIONING_DATA_JACK
#define H_EQUIPMENT_AIRCONDITIONING_DATA_JACK

#include "EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class Airconditioning;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - klimatyzator
	///
	class EquipmentAirconditioningData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentAirconditioningData();

		///
		///Konstruktor kopiujący
		///
		///@param EquipmentAirconditioningDataCopy - stała referencja na obiekt klasy EquipmentAirconditioningData
		///
		EquipmentAirconditioningData(const EquipmentAirconditioningData & EquipmentAirconditioningDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentAirconditioningData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;
		
		///
		///Metoda zwraca wskaźnik na obiekt klasy Airconditioning
		///
		Airconditioning *getAirconditioning();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Airconditioning
		///
		///@param *airconditiong - wskaźnik na obiekt klasy Airconditioning
		///
		void setAirconditioning(Airconditioning *airconditiong);

	private:

		Airconditioning *p_airconditiong; //wskaźnik na klasę Airconditioning - klimatyzator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AIRCONDITIONING_DATA_JACK
