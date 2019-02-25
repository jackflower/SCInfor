//  ____________________________________________
// | BatteryTemplate.h - class definition       |
// | Jack Flower - May 2014                     |
// |____________________________________________|
//

#ifndef H_BATTERY_TEMPLATE_JACK
#define H_BATTERY_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Equipment/Energy/Battery/Battery.h"

using namespace equipment::battery;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec baterii
	///
	class BatteryTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		BatteryTemplate();

		///
		///Destruktor
		///
		~BatteryTemplate();

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
		///@param xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy Battery
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Battery *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_battery - wskaźnik na obiekt klasy Battery
		///
		virtual void fill(Battery *p_battery);

	private:

		std::string m_templ_battery_name; //nazwa baterii (niklowa, kadmowa, litowa, atomowa...etc)
		float m_templ_capacity; //pojemność baterii - przy każdym pełnym przeładowaniu - spada o m_decline
		float m_templ_factory_capacity; //fabryczna pojemność baterii (znamionowa)
		float m_templ_particle_energy; //wartość cząstki energii przekazywanej z baterii do odbiorcy (zbilansowanie stanu)
		float m_templ_battery_regeneration_duration; //czas procesu zużycia jednostki energii
	};
}//namespace factory
#endif//H_BATTERY_TEMPLATE_JACK
