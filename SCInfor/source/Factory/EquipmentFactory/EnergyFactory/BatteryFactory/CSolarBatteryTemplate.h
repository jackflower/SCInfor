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
	///Klasa reprezentuje wzorzec baterii s³onecznej
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
		///Metoda tworzy obiekt klasy SolarBattery
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		SolarBattery* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_solar_battery - wskaŸnik na obiekt klasy SolarBattery
		///
		virtual void Fill(SolarBattery *p_solar_battery);

	private:

		float m_templ_decline;	//wartoœæ spadku pojemnoœci przy ka¿dym cyklu prze³adowaniu (³adowanie/roz³adowanie)

	};

}//namespace factory
#endif//H_SOLAR_BATTERY_TEMPLATE_JACK