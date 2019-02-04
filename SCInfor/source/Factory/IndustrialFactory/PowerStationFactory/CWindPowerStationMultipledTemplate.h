//  _______________________________________________________________
// | CWindPowerStationMultipledTemplate.h - class definition       |
// | Jack Flower - April 2016                                      |
// |_______________________________________________________________|
//

#ifndef H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK
#define H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK

#include "CWindPowerStationTemplate.h"
#include "../../../Logic/Industrial/PowerStation/WindPowerStation/CWindPowerStationMultipled.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec elektrowni wiatrowej z wieloma turbinami
	///
	class CWindPowerStationMultipledTemplate : public CWindPowerStationTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CWindPowerStationMultipledTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CWindPowerStationMultipledTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CWindPowerStationMultipled
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CWindPowerStationMultipled* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_windpower_station_multipled - wskaŸnik na obiekt klasy CWindPowerStationMultipled
		///
		virtual void Fill(CWindPowerStationMultipled *p_windpower_station_multipled);

	private:

	};
}//namespace factory
#endif//H_WIND_POWER_STATION_MULTIPLED_TEMPLATE_JACK
