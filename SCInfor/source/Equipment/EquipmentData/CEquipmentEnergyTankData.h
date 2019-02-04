//  _____________________________________________________
// | CEquipmentEnergyTankData.h - class definition       |
// | Jack Flower - May 2016                              |
// |_____________________________________________________|
//

#ifndef H_EQUIPMENT_ENERGYTANK_DATA_JACK
#define H_EQUIPMENT_ENERGYTANK_DATA_JACK

#include "CEquipmentData.h"
#include "../Energy/EnergyTank/CEnergyTank.h"

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - akumulator
	///
	class CEquipmentEnergyTankData : public CEquipmentData
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
		///Metoda zwraca wska�nik na obiekt klasy CEnergyTank
		///
		CEnergyTank* getEnergyTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy CEnergyTank
		///
		///@param *fueltank - wska�nik na obiekt klasy CEnergyTank
		///
		void setEnergyTank(CEnergyTank* energytank);

	private:

		CEnergyTank*	p_energytank;	//wska�nik na klas� CEnergyTank - akumulator

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGYTANK_DATA_JACK
