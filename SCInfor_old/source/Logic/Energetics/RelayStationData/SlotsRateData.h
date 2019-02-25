//  __________________________________________
// | SlotsRateData.h - class definition       |
// | Jack Flower - May 2016                   |
// |__________________________________________|
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
		class SlotsRate;
	}
}

using namespace equipmentdata;
using namespace logic::energetics;

namespace relaystationdata
{
	///
	///Klasa reprezentuje funkcjonalność wskaźnika przekaźnika - sloty
	///
	class SlotsRateData : public EquipmentData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		SlotsRateData();

		///
		///Konstruktor kopiujący
		///
		///@param & SlotsRateDataCopy - stała referencja na obiekt klasy SlotsRateData
		///
		SlotsRateData(const SlotsRateData & SlotsRateDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~SlotsRateData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wskaźnik na obiekt klasy SlotsRate
		///
		SlotsRate *getSlotsRate();

		///
		///Metoda ustawia wskaźnik na obiekt klasy SlotsRate
		///
		///@param *slotsrate - wskaźnik na obiekt klasy SlotsRate
		///
		void setSlotsRate(SlotsRate *slotsrate);

	private:

		SlotsRate *p_slotsrate;	//wskaźnik na klasę SlotsRate - sloty przekaźnika
	};
}//namespace relaystationdata
#endif//H_SLOTS_RATE_DATA_JACK
