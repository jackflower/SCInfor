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
	class CWindTurbine;
}

using namespace equipment;
using namespace equipmentdata;

namespace equipmentpowerstationdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - turbina
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
		///Konstruktor kopiuj�cy
		///
		///@param & CWindTurbineDataCopy - sta�a referencja na obiekt klasy CWindTurbineData
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
		///Metoda zwraca wska�nik na obiekt klasy CWindTurbine
		///
		CWindTurbine* getTurbine();

		///
		///Metoda ustawia wska�nik na obiekt klasy CWindTurbine
		///
		///@param *turbine - wska�nik na obiekt klasy CWindTurbine
		///
		void setTurbine(CWindTurbine* turbine);

	private:

		CWindTurbine*	p_turbine;	//wska�nik na klas� CWindTurbine - turbina
	};
}//namespace equipmentpowerstationdata
#endif//H_WIND_TURBINE_DATA_JACK
