//  ___________________________________________________
// | CThermalInsulationData.h - class definition       |
// | Jack Flower - May 2016                            |
// |___________________________________________________|
//

#ifndef H_EQUIPMENT_THERMALINSULATION_DATA_JACK
#define H_EQUIPMENT_THERMALINSULATION_DATA_JACK

#include "CEquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class CThermalInsulation;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - termoizolator
	///
	class CThermalInsulationData : public CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CThermalInsulationData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CThermalInsulationDataCopy - sta�a referencja na obiekt klasy CThermalInsulationData
		///
		CThermalInsulationData(const CThermalInsulationData & CThermalInsulationDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CThermalInsulationData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy CThermalInsulation
		///
		CThermalInsulation* getThermalInsulation();

		///
		///Metoda ustawia wska�nik na obiekt klasy CThermalInsulation
		///
		///@param *thermalinsulation - wska�nik na obiekt klasy CThermalInsulation
		///
		void setThermalInsulation(CThermalInsulation* thermalinsulation);

	private:

		CThermalInsulation*	p_thermalinsulation;	//wska�nik na klas� CThermalInsulation - termoizolator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_THERMALINSULATION_DATA_JACK
