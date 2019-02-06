//  _________________________________________________
// | CWindTurbineTemplate.h - class definition       |
// | Jack Flower - July 2014                         |
// |_________________________________________________|
//

#ifndef H_WIND_TURBINE_TEMPLATE_JACK
#define H_WIND_TURBINE_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Equipment/Industrial/PowerModuleType/WindTurbine.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec turbiny
	///
	class CWindTurbineTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CWindTurbineTemplate(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CWindTurbineTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy WindTurbine
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		WindTurbine* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_turbine - wskaŸnik na obiekt klasy WindTurbine
		///
		virtual void Fill(WindTurbine *p_turbine);

	private:

		std::string		m_templ_turbine_name;			//nazwa turbiny
		float			m_templ_speed_rotor;			//prêdkoœæ wirowania turbiny
		float			m_templ_speed_transmission;		//przek³adnia - prze³o¿enie prêdkoœci obrotowej
		float			m_templ_energy_capacitor;		//energia, która mo¿e zostaæ zgromadzona
		float			m_templ_power;					//moc (wartoœæ energii dodawana przy ka¿dym pe³nym obrocie)
		float			m_templ_percentage_activation;	//procentowy wspó³czynnik aktywacji turbiny
		float			m_templ_energy_full_duration;	//czas trwania stanu, po zgromadzeniu pe³nej energii
	};
}//namespace factory
#endif//H_WIND_TURBINE_TEMPLATE_JACK
