//  __________________________________________________________
// | CEquipmentAirconditioningData.h - class definition       |
// | Jack Flower - May 2016                                   |
// |__________________________________________________________|
//

#ifndef H_EQUIPMENT_AIRCONDITIONING_DATA_JACK
#define H_EQUIPMENT_AIRCONDITIONING_DATA_JACK

#include "CEquipmentData.h"

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
	class CEquipmentAirconditioningData : public CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentAirconditioningData();

		///
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentAirconditioningDataCopy - sta≥a referencja na obiekt klasy CEquipmentAirconditioningData
		///
		CEquipmentAirconditioningData(const CEquipmentAirconditioningData & CEquipmentAirconditioningDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentAirconditioningData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;
		
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

		CAirconditioning*	p_airconditiong;	//wskaünik na klasÍ CAirconditioning - klimatyzator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AIRCONDITIONING_DATA_JACK
