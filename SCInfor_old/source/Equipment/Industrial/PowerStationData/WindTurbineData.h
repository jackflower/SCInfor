//  ____________________________________________
// | WindTurbineData.h - class definition       |
// | Jack Flower - May 2016                     |
// |____________________________________________|
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
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - turbina
	///
	class WindTurbineData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		WindTurbineData();

		///
		///Konstruktor kopiujący
		///
		///@param WindTurbineDataCopy - stała referencja na obiekt klasy WindTurbineData
		///
		WindTurbineData(const WindTurbineData & WindTurbineDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~WindTurbineData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy WindTurbine
		///
		WindTurbine *getTurbine();

		///
		///Metoda ustawia wskaźnik na obiekt klasy WindTurbine
		///
		///@param *turbine - wskaźnik na obiekt klasy WindTurbine
		///
		void setTurbine(WindTurbine *turbine);

	private:

		WindTurbine *p_turbine;	//wskaźnik na klasę WindTurbine - turbina
	};
}//namespace equipmentpowerstationdata
#endif//H_WIND_TURBINE_DATA_JACK
