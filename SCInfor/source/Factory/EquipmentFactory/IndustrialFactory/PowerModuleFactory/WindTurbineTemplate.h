//  ________________________________________________
// | WindTurbineTemplate.h - class definition       |
// | Jack Flower - July 2014                        |
// |________________________________________________|
//

#ifndef H_WIND_TURBINE_TEMPLATE_JACK
#define H_WIND_TURBINE_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Equipment/Industrial/PowerModuleType/WindTurbine.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec turbiny
	///
	class WindTurbineTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		WindTurbineTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~WindTurbineTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml ładuje wspólne cechy CActor
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy WindTurbine
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		WindTurbine *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_turbine - wskaźnik na obiekt klasy WindTurbine
		///
		virtual void fill(WindTurbine *p_turbine);

	private:

		std::string m_templ_turbine_name; //nazwa turbiny
		float m_templ_speed_rotor; //prędkość wirowania turbiny
		float m_templ_speed_transmission; //przekładnia - przełożenie prędkości obrotowej
		float m_templ_energy_capacitor; //energia, która może zostać zgromadzona
		float m_templ_power; //moc (wartość energii dodawana przy każdym pełnym obrocie)
		float m_templ_percentage_activation; //procentowy współczynnik aktywacji turbiny
		float m_templ_energy_full_duration;	//czas trwania stanu, po zgromadzeniu pełnej energii
	};
}//namespace factory
#endif//H_WIND_TURBINE_TEMPLATE_JACK
