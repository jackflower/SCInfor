//  ___________________________________________________
// | CEquipmentFuelTankData.h - class definition       |
// | Jack Flower - May 2016                            |
// |___________________________________________________|
//

#ifndef H_EQUIPMENT_FUELTANK_DATA_JACK
#define H_EQUIPMENT_FUELTANK_DATA_JACK

#include "EquipmentData.h"
#include "../Engine/FuelTank/FuelTank.h"

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - zbiornik paliwa
	///
	class CEquipmentFuelTankData : public EquipmentData
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		CEquipmentFuelTankData();

		///
		///Konstruktor kopiujacy
		///
		///@param & CEquipmentFuelTankDataaCopy - sta�a referencja na obiekt klasy CEquipmentFuelTankData
		///
		CEquipmentFuelTankData(const CEquipmentFuelTankData & CEquipmentFuelTankDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEquipmentFuelTankData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy FuelTank
		///
		FuelTank* getFuelTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy FuelTank
		///
		///@param *fueltank - wska�nik na obiekt klasy FuelTank
		///
		void setFuelTank(FuelTank* fueltank);

	private:

		FuelTank*	p_fueltank;	//wska�nik na klas� FuelTank - zbiornik paliwa

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_FUELTANK_DATA_JACK
