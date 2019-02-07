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
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml �aduje wsp�lne cechy CActor
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
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_ventilator - wska�nik na obiekt klasy Ventilator
		///
		virtual void fill(Ventilator *p_ventilator);

	private:

		std::string		m_templ_ventilator_name;			//nazwa wentylatora
		float			m_templ_performance;				//wydajno��
		float			m_templ_performance_factor;			//wsp�czynnik wydajno�ci (zale�y od temperatury)
		float			m_templ_energy_consumption;			//zu�ycie energii
		float			m_templ_energy_consumption_factor;	//wsp�czynnik zu�ycia energii
	};
}//namespace factory
#endif//H_VENTILATOR_TEMPLATE_JACK