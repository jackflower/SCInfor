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
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml �aduje wsp�lne cechy CActor
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
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_turbine - wska�nik na obiekt klasy WindTurbine
		///
		virtual void Fill(WindTurbine *p_turbine);

	private:

		std::string		m_templ_turbine_name;			//nazwa turbiny
		float			m_templ_speed_rotor;			//pr�dko�� wirowania turbiny
		float			m_templ_speed_transmission;		//przek�adnia - prze�o�enie pr�dko�ci obrotowej
		float			m_templ_energy_capacitor;		//energia, kt�ra mo�e zosta� zgromadzona
		float			m_templ_power;					//moc (warto�� energii dodawana przy ka�dym pe�nym obrocie)
		float			m_templ_percentage_activation;	//procentowy wsp�czynnik aktywacji turbiny
		float			m_templ_energy_full_duration;	//czas trwania stanu, po zgromadzeniu pe�nej energii
	};
}//namespace factory
#endif//H_WIND_TURBINE_TEMPLATE_JACK
