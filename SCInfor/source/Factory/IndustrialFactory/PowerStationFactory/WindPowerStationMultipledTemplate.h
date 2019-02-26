//  ______________________________________________________________
// | WindPowerStationMultipledTemplate.h - class definition       |
// | Jack Flower - April 2016                                     |
// |______________________________________________________________|
//

#ifndef H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK
#define H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK

#include "WindPowerStationTemplate.h"
#include "../../../Logic/Industrial/PowerStation/WindPowerStation/WindPowerStationMultipled.h"

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
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Wirtualna metoda �aduj�ca dane
		///
		///@param name - sta�a referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda �aduj�ca dane
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy WindPowerStationMultipled
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		WindPowerStationMultipled *create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_windpower_station_multipled - wska�nik na obiekt klasy WindPowerStationMultipled
		///
		virtual void fill(WindPowerStationMultipled *p_windpower_station_multipled);

	private:

	};
}//namespace factory
#endif//H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK
