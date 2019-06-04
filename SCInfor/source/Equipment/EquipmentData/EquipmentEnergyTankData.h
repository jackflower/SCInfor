//  ____________________________________________________
// | EquipmentEnergyTankData.h - class definition       |
// | Jack Flower - May 2016                             |
// |____________________________________________________|
//

#ifndef H_EQUIPMENT_ENERGYTANK_DATA_JACK
#define H_EQUIPMENT_ENERGYTANK_DATA_JACK

#include "EquipmentData.h"
#include "../Energy/EnergyTank/EnergyTank.h"

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - akumulator
	///
	class EquipmentEnergyTankData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EquipmentEnergyTankData();

		///
		///Konstruktor kopiujπcy
		///
		///@param EquipmentEnergyTankDataCopy - sta≥a referencja na obiekt klasy EquipmentEnergyTankData
		///
		EquipmentEnergyTankData(const EquipmentEnergyTankData & EquipmentEnergyTankDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentEnergyTankData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy EnergyTank
		///
		EnergyTank *getEnergyTank();

		///
		///Metoda ustawia wskaünik na obiekt klasy EnergyTank
		///
		///@param *energytank - wskaünik na obiekt klasy EnergyTank
		///
		void setEnergyTank(EnergyTank *energytank);

	private:

		EnergyTank *p_energytank; //wskaünik na klasÍ EnergyTank - akumulator

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGYTANK_DATA_JACK
