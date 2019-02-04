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
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - termoizolator
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
		///Konstruktor kopiujπcy
		///
		///@param & CThermalInsulationDataCopy - sta≥a referencja na obiekt klasy CThermalInsulationData
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
		///Metoda zwraca wskaünik na obiekt klasy CThermalInsulation
		///
		CThermalInsulation* getThermalInsulation();

		///
		///Metoda ustawia wskaünik na obiekt klasy CThermalInsulation
		///
		///@param *thermalinsulation - wskaünik na obiekt klasy CThermalInsulation
		///
		void setThermalInsulation(CThermalInsulation* thermalinsulation);

	private:

		CThermalInsulation*	p_thermalinsulation;	//wskaünik na klasÍ CThermalInsulation - termoizolator
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_THERMALINSULATION_DATA_JACK
