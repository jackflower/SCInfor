//  ________________________________________________
// | EquipmentEnergyData.h - class definition       |
// | Jack Flower - May 2016                         |
// |________________________________________________|
//

#ifndef H_EQUIPMENT_ENERGY_DATA_JACK
#define H_EQUIPMENT_ENERGY_DATA_JACK

#include "EquipmentData.h"

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
	///Klasa reprezentuje funkcjonalność obiektu będącego wyposażaniem - energia
	///
	class EquipmentEnergyData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentEnergyData();

		///
		///Konstruktor kopiujący
		///
		///@param EquipmentEnergyDataCopy - stała referencja na obiekt klasy EquipmentEnergyData
		///
		EquipmentEnergyData(const EquipmentEnergyData & EquipmentEnergyDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentEnergyData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy Energy
		///
		Energy *getEnergy();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Energy
		///
		///@param *energy - wskaźnik na obiekt klasy Energy
		///
		void setEnergy(Energy *energy);

	private:

		Energy *p_energy; //wskaźnik na klasę Energy - energia
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGY_DATA_JACK
