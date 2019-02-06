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
	class ThermalInsulation;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - termoizolator
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
		///Konstruktor kopiujący
		///
		///@param ThermalInsulationDataCopy - stała referencja na obiekt klasy ThermalInsulationData
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
		///Metoda zwraca wskaźnik na obiekt klasy ThermalInsulation
		///
		ThermalInsulation* getThermalInsulation();

		///
		///Metoda ustawia wskaźnik na obiekt klasy ThermalInsulation
		///
		///@param *thermalinsulation - wskaźnik na obiekt klasy ThermalInsulation
		///
		void setThermalInsulation(ThermalInsulation* thermalinsulation);

	private:

		ThermalInsulation*	p_thermalinsulation;	//wskaźnik na klasę ThermalInsulation - termoizolator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_THERMALINSULATION_DATA_JACK
