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
	class CEnergy;
}

using namespace equipment;

namespace equipmentdata
{
	///
	///Klasa reprezentuje funkcjonalno�� obiektu b�d�cego wyposa�aniem - energia
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
		///Konstruktor kopiuj�cy
		///
		///@param & CEquipmentEnergyDataCopy - sta�a referencja na obiekt klasy CEquipmentEnergyData
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
		///Metoda zwraca wska�nik na obiekt klasy CEnergy
		///
		CEnergy* getEnergy();

		///
		///Metoda ustawia wska�nik na obiekt klasy CEnergy
		///
		///@param *energy - wska�nik na obiekt klasy CEnergy
		///
		void setEnergy(CEnergy* energy);

	private:

		CEnergy*	p_energy;	//wska�nik na klas� CEnergy - energia
	};
}//namespace equipmentdata
#endif//H_EQUIPMENT_ENERGY_DATA_JACK
