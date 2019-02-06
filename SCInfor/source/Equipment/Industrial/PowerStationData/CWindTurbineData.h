//  _____________________________________________
// | CWindTurbineData.h - class definition       |
// | Jack Flower - May 2016                      |
// |_____________________________________________|
//

#ifndef H_WIND_TURBINE_DATA_JACK
#define H_WIND_TURBINE_DATA_JACK

#include "../../EquipmentData/EquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class WindTurbine;
}

using namespace equipment;
using namespace equipmentdata;

namespace equipmentpowerstationdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - turbina
	///
	class CWindTurbineData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CWindTurbineData();

		///
		///Konstruktor kopiujπcy
		///
		///@param & CWindTurbineDataCopy - sta≥a referencja na obiekt klasy CWindTurbineData
		///
		CWindTurbineData(const CWindTurbineData & CWindTurbineDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CWindTurbineData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy WindTurbine
		///
		WindTurbine* getTurbine();

		///
		///Metoda ustawia wskaünik na obiekt klasy WindTurbine
		///
		///@param *turbine - wskaünik na obiekt klasy WindTurbine
		///
		void setTurbine(WindTurbine* turbine);

	private:

		WindTurbine*	p_turbine;	//wskaünik na klasÍ WindTurbine - turbina
	};
}//namespace equipmentpowerstationdata
#endif//H_WIND_TURBINE_DATA_JACK
