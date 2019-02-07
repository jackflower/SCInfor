//  ____________________________________________________
// | AirconditioningTemplate.h - class definition       |
// | Jack Flower June 2014                              |
// |____________________________________________________|
//

#ifndef H_AIRCONDITIONING_TEMPLATE_JACK
#define H_AIRCONDITIONING_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../ThermalInsulationFactory/ThermalInsulationTemplate.h"
#include "../../../../Equipment/Thermodynamics/Airconditioning/Airconditioning.h"
#include "../../../../Equipment/EquipmentData/ThermalInsulationData.h"

using namespace equipmentdata;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec modułu klimatyzatora
	///
	class AirconditioningTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		AirconditioningTemplate();

		///
		///Destruktor wirtualny
		///
		~AirconditioningTemplate();

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
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy Airconditioning
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Airconditioning *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_airconditioning - wskaźnik na obiekt klasy Airconditioning
		///
		virtual void fill(Airconditioning *p_airconditioning);

	private:

		std::string m_templ_airconditioning_name; //nazwa klimatyzatora
		float m_templ_temperature; //temperatura [obliczana]
		float m_templ_temperature_set; //temperatura ustawiona na urządzeniu (klimatyzator)[losowana z zakresu]
		std::pair<float, float> m_templ_temperature_range; //zakres temperatury - skuteczność urządzenia [first - cold, second - warm]
		float m_templ_temperature_increment; //przyrost temperatury - cykl - dynammika
		float m_templ_energy_consumption; //zużycie energii przez klimatyzator
		float m_templ_fuel_consumption; //zużycie paliwa przez klimatyzator
		ThermalInsulationData m_templ_thermalinsulation_data; //opakowanie funkcjonalności termoizolatora
		ThermalInsulationTemplate *p_templ_thermal_insulation; //wskaźnik na obiekt ThermalInsulationTemplate (wzorzec termoizolaora)
	};
}//namespace factory
#endif//H_AIRCONDITIONING_TEMPLATE_JACK
