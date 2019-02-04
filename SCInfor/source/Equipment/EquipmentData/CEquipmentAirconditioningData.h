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
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - klimatyzator
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
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentAirconditioningDataCopy - sta�a referencja na obiekt klasy CEquipmentAirconditioningData
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
		///Metoda zwraca wska�nik na obiekt klasy CAirconditioning
		///
		CAirconditioning* getAirconditioning();

		///
		///Metoda ustawia wska�nik na obiekt klasy CAirconditioning
		///
		///@param *airconditiong - wska�nik na obiekt klasy CAirconditioning
		///
		void setAirconditioning(CAirconditioning* airconditiong);

	private:

		CAirconditioning*	p_airconditiong;	//wska�nik na klas� CAirconditioning - klimatyzator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_AIRCONDITIONING_DATA_JACK
