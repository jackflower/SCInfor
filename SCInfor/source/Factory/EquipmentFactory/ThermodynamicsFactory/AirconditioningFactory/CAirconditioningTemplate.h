//  _____________________________________________________
// | CAirconditioningTemplate.h - class definition       |
// | Jack Flower June 2014                               |
// |_____________________________________________________|
//

#ifndef H_AIRCONDITIONING_TEMPLATE_JACK
#define H_AIRCONDITIONING_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../ThermalInsulationFactory/CThermalInsulationTemplate.h"
#include "../../../../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../../../../Equipment/EquipmentData/ThermalInsulationData.h"

using namespace equipmentdata;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec modu³u klimatyzatora
	///
	class CAirconditioningTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CAirconditioningTemplate();

		///
		///Destruktor wirtualny
		///
		~CAirconditioningTemplate();

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
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy Airconditioning
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Airconditioning* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_airconditioning - wskaŸnik na obiekt klasy Airconditioning
		///
		virtual void fill(Airconditioning *p_airconditioning);

	private:

		std::string					m_templ_airconditioning_name;		//nazwa klimatyzatora
		float						m_templ_temperature;				//temperatura [obliczana]
		float						m_templ_temperature_set;			//temperatura ustawiona na urz¹dzeniu (klimatyzator)[losowana z zakresu]
		std::pair<float, float>		m_templ_temperature_range;			//zakres temperatury - skutecznoœæ urz¹dzenia [first - cold, second - warm]
		float						m_templ_temperature_increment;		//przyrost temperatury - cykl - dynammika
		float						m_templ_energy_consumption;			//zu¿ycie energii przez klimatyzator
		float						m_templ_fuel_consumption;			//zu¿ycie paliwa przez klimatyzator
		ThermalInsulationData		m_templ_thermalinsulation_data;		//opakowanie funkcjonalnoœci termoizolatora
		CThermalInsulationTemplate* p_templ_thermal_insulation;			//wskaŸnik na obiekt CThermalInsulationTemplate (wzorzec termoizolaora)
	};
}//namespace factory
#endif//H_AIRCONDITIONING_TEMPLATE_JACK