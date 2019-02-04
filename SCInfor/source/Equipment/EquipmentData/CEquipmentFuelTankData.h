//  ___________________________________________________
// | CEquipmentFuelTankData.h - class definition       |
// | Jack Flower - May 2016                            |
// |___________________________________________________|
//

#ifndef H_EQUIPMENT_FUELTANK_DATA_JACK
#define H_EQUIPMENT_FUELTANK_DATA_JACK

#include "CEquipmentData.h"
#include "../Engine/FuelTank/CFuelTank.h"

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - zbiornik paliwa
	///
	class CEquipmentFuelTankData : public CEquipmentData
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
		///Metoda zwraca wska�nik na obiekt klasy CFuelTank
		///
		CFuelTank* getFuelTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy CFuelTank
		///
		///@param *fueltank - wska�nik na obiekt klasy CFuelTank
		///
		void setFuelTank(CFuelTank* fueltank);

	private:

		CFuelTank*	p_fueltank;	//wska�nik na klas� CFuelTank - zbiornik paliwa

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_FUELTANK_DATA_JACK
