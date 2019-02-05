//  _____________________________________________________
// | CEquipmentEnergyTankData.h - class definition       |
// | Jack Flower - May 2016                              |
// |_____________________________________________________|
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
	class CEquipmentEnergyTankData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEquipmentEnergyTankData();

		///
		///Konstruktor kopiujacy
		///
		///@param & CEquipmentEnergyTankDataCopy - sta�a referencja na obiekt klasy CEquipmentEnergyTankData
		///
		CEquipmentEnergyTankData(const CEquipmentEnergyTankData & CEquipmentEnergyTankDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentEnergyTankData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy EnergyTank
		///
		EnergyTank* getEnergyTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy EnergyTank
		///
		///@param *fueltank - wska�nik na obiekt klasy EnergyTank
		///
		void setEnergyTank(EnergyTank* energytank);

	private:

		EnergyTank*	p_energytank;	//wska�nik na klas� EnergyTank - akumulator

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGYTANK_DATA_JACK
