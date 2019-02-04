//  _____________________________________________
// | CBatteryTemplate.h - class definition       |
// | Jack Flower - May 2014                      |
// |_____________________________________________|
//

#ifndef H_BATTERY_TEMPLATE_JACK
#define H_BATTERY_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Equipment/Energy/Battery/CBattery.h"

using namespace equipment::battery;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec baterii
	///
	class CBatteryTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CBatteryTemplate(void);

		///
		///Destruktor
		///
		~CBatteryTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CBattery
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CBattery* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_battery - wskaŸnik na obiekt klasy CBattery
		///
		virtual void Fill(CBattery *p_battery);

	private:

		std::string		m_templ_battery_name;					//nazwa baterii (niklowa, kadmowa, litowa, atomowa...etc)
		float			m_templ_capacity;						//pojemnoœæ baterii - przy ka¿dym pe³nym prze³adowaniu - spada o m_decline
		float			m_templ_factory_capacity;				//fabryczna pojemnoœæ baterii (znamionowa)
		float			m_templ_particle_energy;				//wartoœæ cz¹stki energii przekazywanej z baterii do odbiorcy (zbilansowanie stanu)
		float			m_templ_battery_regeneration_duration;	//czas procesu zu¿ycia jednostki energii
	};
}//namespace factory
#endif//H_BATTERY_TEMPLATE_JACK