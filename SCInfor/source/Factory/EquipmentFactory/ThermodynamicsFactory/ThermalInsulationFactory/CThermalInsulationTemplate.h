//  _______________________________________________________
// | CThermalInsulationTemplate.h - class definition       |
// | Jack Flower June 2014                                 |
// |_______________________________________________________|
//

#ifndef H_THERMAL_INSULATION_TEMPLATE_JACK
#define H_THERMAL_INSULATION_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../../../../Equipment/Thermodynamics/ThermalInsulation/ThermalInsulation.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec termoizolatora
	///
	class CThermalInsulationTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CThermalInsulationTemplate();

		///
		///Destruktor wirtualny
		///
		~CThermalInsulationTemplate();

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
		///Metoda tworzy obiekt klasy ThermalInsulation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		ThermalInsulation* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_thermalinsulation - wskaŸnik na obiekt klasy ThermalInsulation
		///
		virtual void fill(ThermalInsulation *p_thermalinsulation);


	private:

		std::string		m_templ_thermalinsulation_name;			//nazwa termoizolatora
		float			m_templ_temperature_ambient;			//temperatura otoczenia - skorygowana wielkoœci¹ termiozolacji
		float			m_templ_thermal_protection;				//ochrona termiczna - termoizolator
		float			m_templ_thermal_protection_factor;		//obliczany wspó³czynnik termoizolacji
		float			m_templ_thermal_protection_consume;		//wartoœæ zu¿ycia ochrony termicznej w jednostce czasu
		float			m_templ_thermal_protection_duration;	//czas cyklu procesu zu¿ycia/starzenia ochrony termicznej
	};
}//namespace factory
#endif//H_THERMAL_INSULATION_TEMPLATE_JACK
