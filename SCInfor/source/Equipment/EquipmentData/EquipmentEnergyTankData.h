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
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - akumulator
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
		///Konstruktor kopiuj�cy
		///
		///@param EquipmentEnergyTankDataCopy - sta�a referencja na obiekt klasy EquipmentEnergyTankData
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
		///Metoda zwraca wska�nik na obiekt klasy EnergyTank
		///
		EnergyTank *getEnergyTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy EnergyTank
		///
		///@param *energytank - wska�nik na obiekt klasy EnergyTank
		///
		void setEnergyTank(EnergyTank *energytank);

	private:

		EnergyTank *p_energytank; //wska�nik na klas� EnergyTank - akumulator

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGYTANK_DATA_JACK
