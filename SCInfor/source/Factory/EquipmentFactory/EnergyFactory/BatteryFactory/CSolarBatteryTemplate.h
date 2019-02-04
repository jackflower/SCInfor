//  __________________________________________________
// | CSolarBatteryTemplate.h - class definition       |
// | Jack Flower - May 2014                           |
// |__________________________________________________|
//

#ifndef H_SOLAR_BATTERY_TEMPLATE_JACK
#define H_SOLAR_BATTERY_TEMPLATE_JACK

#include "CBatteryTemplate.h"
#include "../../../../Equipment/Energy/Battery/SolarBattery.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec baterii s�onecznej
	///
	class CSolarBatteryTemplate : public CBatteryTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CSolarBatteryTemplate(void);

		///
		///Destruktor
		///
		~CSolarBatteryTemplate(void);

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
		///Metoda tworzy obiekt klasy SolarBattery
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		SolarBattery* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_solar_battery - wska�nik na obiekt klasy SolarBattery
		///
		virtual void Fill(SolarBattery *p_solar_battery);

	private:

		float m_templ_decline;	//warto�� spadku pojemno�ci przy ka�dym cyklu prze�adowaniu (�adowanie/roz�adowanie)

	};

}//namespace factory
#endif//H_SOLAR_BATTERY_TEMPLATE_JACK