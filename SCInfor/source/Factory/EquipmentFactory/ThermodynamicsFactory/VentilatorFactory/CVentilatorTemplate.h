//  ________________________________________________
// | CVentilatorTemplate.h - class definition       |
// | Jack Flower June 2014                          |
// |________________________________________________|
//

#ifndef H_VENTILATOR_TEMPLATE_JACK
#define H_VENTILATOR_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Equipment/Thermodynamics/Ventilator/Ventilator.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec wentylatora
	///
	class CVentilatorTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CVentilatorTemplate();

		///
		///Destruktor wirtualny
		///
		~CVentilatorTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy Ventilator
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Ventilator* create(std::wstring id = L"");

	protected:

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_ventilator - wskaŸnik na obiekt klasy Ventilator
		///
		virtual void fill(Ventilator *p_ventilator);

	private:

		std::string		m_templ_ventilator_name;			//nazwa wentylatora
		float			m_templ_performance;				//wydajnoœæ
		float			m_templ_performance_factor;			//wspó³czynnik wydajnoœci (zale¿y od temperatury)
		float			m_templ_energy_consumption;			//zu¿ycie energii
		float			m_templ_energy_consumption_factor;	//wspó³czynnik zu¿ycia energii
	};
}//namespace factory
#endif//H_VENTILATOR_TEMPLATE_JACK