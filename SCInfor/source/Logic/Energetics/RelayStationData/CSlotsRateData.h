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
	///Klasa reprezentuje funkcjonalnoúÊ wskaünika przekaünika - sloty
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
		///Konstruktor kopiujπcy
		///
		///@param & CSlotsRateDataCopy - sta≥a referencja na obiekt klasy CSlotsRateData
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
		///Metoda zwraca wskaünik na obiekt klasy CSlotsRate
		///
		CSlotsRate* getSlotsRate();

		///
		///Metoda ustawia wskaünik na obiekt klasy CSlotsRate
		///
		///@param *slotsrate - wskaünik na obiekt klasy CSlotsRate
		///
		void setSlotsRate(CSlotsRate* slotsrate);

	private:

		CSlotsRate*	p_slotsrate;	//wskaünik na klasÍ CSlotsRate - sloty przekaünika
	};
}//namespace relaystationdata
#endif//H_SLOTS_RATE_DATA_JACK
