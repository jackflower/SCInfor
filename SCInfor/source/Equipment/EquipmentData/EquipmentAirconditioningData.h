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
	class CAirconditioning;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - klimatyzator
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
		///Konstruktor kopiujπcy
		///
		///@param EquipmentAirconditioningDataCopy - sta≥a referencja na obiekt klasy EquipmentAirconditioningData
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
		///Metoda zwraca wskaünik na obiekt klasy CAirconditioning
		///
		CAirconditioning* getAirconditioning();

		///
		///Metoda ustawia wskaünik na obiekt klasy CAirconditioning
		///
		///@param *airconditiong - wskaünik na obiekt klasy CAirconditioning
		///
		void setAirconditioning(CAirconditioning* airconditiong);

	private:

		CAirconditioning*	p_airconditiong;	//wskaünik na klasÍ Airconditioning - klimatyzator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AIRCONDITIONING_DATA_JACK
