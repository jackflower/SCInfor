//  __________________________________________________
// | EquipmentFuelTankData.h - class definition       |
// | Jack Flower - May 2016                           |
// |__________________________________________________|
//

#ifndef H_EQUIPMENT_FUELTANK_DATA_JACK
#define H_EQUIPMENT_FUELTANK_DATA_JACK

#include "EquipmentData.h"
#include "../Engine/FuelTank/FuelTank.h"

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - zbiornik paliwa
	///
	class EquipmentFuelTankData : public EquipmentData
	{
		RTTI_DECL;
	
	public:

		///
		///Konstruktor
		///
		EquipmentFuelTankData();

		///
		///Konstruktor kopiujacy
		///
		///@param EquipmentFuelTankDataaCopy - sta≥a referencja na obiekt klasy EquipmentFuelTankData
		///
		EquipmentFuelTankData(const EquipmentFuelTankData & CEquipmentFuelTankDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EquipmentFuelTankData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaünik na obiekt klasy FuelTank
		///
		FuelTank *getFuelTank();

		///
		///Metoda ustawia wskaünik na obiekt klasy FuelTank
		///
		///@param *fueltank - wskaünik na obiekt klasy FuelTank
		///
		void setFuelTank(FuelTank *fueltank);

	private:

		FuelTank *p_fueltank; //wskaünik na klasÍ FuelTank - zbiornik paliwa obiektu

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_FUELTANK_DATA_JACK
