//  ______________________________________________________
// | ThermalInsulationTemplate.h - class definition       |
// | Jack Flower June 2014                                |
// |______________________________________________________|
//

#ifndef H_THERMAL_INSULATION_TEMPLATE_JACK
#define H_THERMAL_INSULATION_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../../../../Equipment/Thermodynamics/ThermalInsulation/ThermalInsulation.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec termoizolatora
	///
	class ThermalInsulationTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		ThermalInsulationTemplate();

		///
		///Destruktor wirtualny
		///
		~ThermalInsulationTemplate();

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
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy ThermalInsulation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		ThermalInsulation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_thermalinsulation - wskaźnik na obiekt klasy ThermalInsulation
		///
		virtual void fill(ThermalInsulation *p_thermalinsulation);


	private:

		std::string m_templ_thermalinsulation_name; //nazwa termoizolatora
		float m_templ_temperature_ambient; //temperatura otoczenia - skorygowana wielkością termiozolacji
		float m_templ_thermal_protection; //ochrona termiczna - termoizolator
		float m_templ_thermal_protection_factor; //obliczany współczynnik termoizolacji
		float m_templ_thermal_protection_consume; //wartość zużycia ochrony termicznej w jednostce czasu
		float m_templ_thermal_protection_duration; //czas cyklu procesu zużycia/starzenia ochrony termicznej
	};
}//namespace factory
#endif//H_THERMAL_INSULATION_TEMPLATE_JACK
