//  ___________________________________________
// | CSlotsRateData.h - class definition       |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#ifndef H_SLOTS_RATE_DATA_JACK
#define H_SLOTS_RATE_DATA_JACK

#include "../../../Equipment/EquipmentData/EquipmentData.h"

///
///Forward declaration
///
namespace logic
{
	namespace energetics
	{
		class CSlotsRate;
	}
}

using namespace equipmentdata;
using namespace logic::energetics;

namespace relaystationdata
{
	///
	///Klasa reprezentuje funkcjonalno�� wska�nika przeka�nika - sloty
	///
	class CSlotsRateData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CSlotsRateData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CSlotsRateDataCopy - sta�a referencja na obiekt klasy CSlotsRateData
		///
		CSlotsRateData(const CSlotsRateData & CSlotsRateDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CSlotsRateData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wska�nik na obiekt klasy CSlotsRate
		///
		CSlotsRate* getSlotsRate();

		///
		///Metoda ustawia wska�nik na obiekt klasy CSlotsRate
		///
		///@param *slotsrate - wska�nik na obiekt klasy CSlotsRate
		///
		void setSlotsRate(CSlotsRate* slotsrate);

	private:

		CSlotsRate*	p_slotsrate;	//wska�nik na klas� CSlotsRate - sloty przeka�nika
	};
}//namespace relaystationdata
#endif//H_SLOTS_RATE_DATA_JACK
