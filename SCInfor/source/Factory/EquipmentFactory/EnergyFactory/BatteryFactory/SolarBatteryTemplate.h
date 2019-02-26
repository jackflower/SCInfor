//  _________________________________________________
// | SolarBatteryTemplate.h - class definition       |
// | Jack Flower - May 2014                          |
// |_________________________________________________|
//

#ifndef H_SOLAR_BATTERY_TEMPLATE_JACK
#define H_SOLAR_BATTERY_TEMPLATE_JACK

#include "BatteryTemplate.h"
#include "../../../../Equipment/Energy/Battery/SolarBattery.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec baterii słonecznej
	///
	class SolarBatteryTemplate : public BatteryTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		SolarBatteryTemplate();

		///
		///Destruktor
		///
		~SolarBatteryTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

		///
		///Wirtualna metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		virtual bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy SolarBattery
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		SolarBattery *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_solar_battery - wskaźnik na obiekt klasy SolarBattery
		///
		virtual void fill(SolarBattery *p_solar_battery);

	private:

		float m_templ_decline;	//wartość spadku pojemności przy każdym cyklu przeładowaniu (ładowanie/rozładowanie)

	};

}//namespace factory
#endif//H_SOLAR_BATTERY_TEMPLATE_JACK
