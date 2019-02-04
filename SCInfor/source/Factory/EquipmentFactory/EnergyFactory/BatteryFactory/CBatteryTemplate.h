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
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Wirtualna metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml
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
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_battery - wska�nik na obiekt klasy CBattery
		///
		virtual void Fill(CBattery *p_battery);

	private:

		std::string		m_templ_battery_name;					//nazwa baterii (niklowa, kadmowa, litowa, atomowa...etc)
		float			m_templ_capacity;						//pojemno�� baterii - przy ka�dym pe�nym prze�adowaniu - spada o m_decline
		float			m_templ_factory_capacity;				//fabryczna pojemno�� baterii (znamionowa)
		float			m_templ_particle_energy;				//warto�� cz�stki energii przekazywanej z baterii do odbiorcy (zbilansowanie stanu)
		float			m_templ_battery_regeneration_duration;	//czas procesu zu�ycia jednostki energii
	};
}//namespace factory
#endif//H_BATTERY_TEMPLATE_JACK