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
	///Klasa reprezentuje funkcjonalnoúÊ obiektu bÍdπcego wyposaøaniem - zbiornik paliwa
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
		///@param & CEquipmentFuelTankDataaCopy - sta≥a referencja na obiekt klasy CEquipmentFuelTankData
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
		///Metoda zwraca wskaünik na obiekt klasy CFuelTank
		///
		CFuelTank* getFuelTank();

		///
		///Metoda ustawia wskaünik na obiekt klasy CFuelTank
		///
		///@param *fueltank - wskaünik na obiekt klasy CFuelTank
		///
		void setFuelTank(CFuelTank* fueltank);

	private:

		CFuelTank*	p_fueltank;	//wskaünik na klasÍ CFuelTank - zbiornik paliwa

	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_FUELTANK_DATA_JACK
