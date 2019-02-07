//  ______________________________________________________________
// | WindPowerStationMultipledTemplate.h - class definition       |
// | Jack Flower - April 2016                                     |
// |______________________________________________________________|
//

#ifndef H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK
#define H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK

#include "WindPowerStationTemplate.h"
#include "../../../Logic/Industrial/PowerStation/WindPowerStation/CWindPowerStationMultipled.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec elektrowni wiatrowej z wieloma turbinami
	///
	class WindPowerStationMultipledTemplate : public WindPowerStationTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		WindPowerStationMultipledTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~WindPowerStationMultipledTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param name - sta³a referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy CWindPowerStationMultipled
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CWindPowerStationMultipled *create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_windpower_station_multipled - wskaŸnik na obiekt klasy CWindPowerStationMultipled
		///
		virtual void fill(CWindPowerStationMultipled *p_windpower_station_multipled);

	private:

	};
}//namespace factory
#endif//H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK
