//  _______________________________________________
// | VentilatorTemplate.h - class definition       |
// | Jack Flower June 2014                         |
// |_______________________________________________|
//

#ifndef H_VENTILATOR_TEMPLATE_JACK
#define H_VENTILATOR_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Equipment/Thermodynamics/Ventilator/Ventilator.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec wentylatora
	///
	class VentilatorTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		VentilatorTemplate();

		///
		///Destruktor wirtualny
		///
		~VentilatorTemplate();

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
		///Wirtualna metoda ładująca dane z xml ładuje wspólne cechy Actor
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy Ventilator
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Ventilator *create(std::wstring id = L"");

	protected:

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_ventilator - wskaźnik na obiekt klasy Ventilator
		///
		virtual void fill(Ventilator *p_ventilator);

	private:

		std::string m_templ_ventilator_name; //nazwa wentylatora
		float m_templ_performance; //wydajność
		float m_templ_performance_factor; //współczynnik wydajności (zależy od temperatury)
		float m_templ_energy_consumption; //zużycie energii
		float m_templ_energy_consumption_factor; //współczynnik zużycia energii
	};
}//namespace factory
#endif//H_VENTILATOR_TEMPLATE_JACK
