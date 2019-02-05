//  __________________________________________________
// | ThermalInsulationData.h - class definition       |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#ifndef H_EQUIPMENT_THERMALINSULATION_DATA_JACK
#define H_EQUIPMENT_THERMALINSULATION_DATA_JACK

#include "EquipmentData.h"

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
	class ThermalInsulationData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		ThermalInsulationData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param ThermalInsulationDataCopy - sta�a referencja na obiekt klasy ThermalInsulationData
		///
		ThermalInsulationData(const ThermalInsulationData & ThermalInsulationDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~ThermalInsulationData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

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
