//  _________________________________________________
// | CEquipmentEnergyData.h - class definition       |
// | Jack Flower - May 2016                          |
// |_________________________________________________|
//

#ifndef H_EQUIPMENT_ENERGY_DATA_JACK
#define H_EQUIPMENT_ENERGY_DATA_JACK

#include "CEquipmentData.h"

///
///Forward declaration
///
namespace equipment
{
	class Energy;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - energia
	///
	class CEquipmentEnergyData : public CEquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentEnergyData();

		///
		///Konstruktor kopiujπcy
		///
		///@param & CEquipmentEnergyDataCopy - sta≥a referencja na obiekt klasy CEquipmentEnergyData
		///
		CEquipmentEnergyData(const CEquipmentEnergyData & CEquipmentEnergyDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentEnergyData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy Energy
		///
		Energy* getEnergy();

		///
		///Metoda ustawia wskaünik na obiekt klasy Energy
		///
		///@param *energy - wskaünik na obiekt klasy Energy
		///
		void setEnergy(Energy* energy);

	private:

		Energy*	p_energy;	//wskaünik na klasÍ Energy - energia
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGY_DATA_JACK
