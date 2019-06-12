//  __________________________________________
// | ActorTemplate.h - class definition       |
// | Jack Flower - February 2013              |
// |__________________________________________|
//

#ifndef H_ACTOR_TEMPLATE_JACK
#define H_ACTOR_TEMPLATE_JACK

#include <iostream>
#include "PhysicalTemplate.h"
#include "../Logic/Actor/Actor.h"


///
///Forward declaration
///
namespace xml
{
	class Xml;
}

///
///Forward declaration
///
namespace logic
{
	class Actor;
}

///
///Forward declaration
///
namespace rendering
{
	namespace animation
	{
		class AnimSet;
	}
}

///
///Forward declaration
///
namespace factory
{
	class EngineTemplate;
	class EnergyTemplate;
	class AirconditioningTemplate;
	class VentilatorTemplate;
	class GunTemplate;
	class WindTurbineTemplate;
	class WindPowerStationTemplate;
	class PhysicalInfoTemplate;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec aktora
	///
	class ActorTemplate : public PhysicalTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		ActorTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~ActorTemplate();

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
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);
			
	protected:

		AnimSet *p_templ_animations; //wskaźnik na zestaw animacji Actor
		std::vector<AnimSet*> m_templ_available_animations; //wektor wskaźników na zestawy dostępnych animacji dla Actor
		ActorTechnicalData m_templ_technical_data; //opakowanie fizyki
		EquipmentEngineData m_templ_engine_data; //opakowanie funkcjonalności silnika
		EquipmentEnergyData m_templ_energy_data; //opakowanie funkcjonalności energii
		EquipmentAirconditioningData m_templ_airconditioning_data; //opakowanie funkcjonalności klimatyzacji
		EquipmentVentilatorData m_templ_ventilator_data; //opakowanie funkcjonalności wentylatora
		EquipmentGunData m_templ_gun_data; //opakowanie funkcjonalności działo
		EngineTemplate *p_templ_engine; //dane wzorca obiektu Engine
		EnergyTemplate *p_templ_energy; //dane wzorca obiektu Energy
		AirconditioningTemplate *p_templ_airconditioning; //wskaźnik na obiekt Airconditioning z logiką zarządzania modułem klimatyzatora
		VentilatorTemplate *p_templ_ventilator; //wskaźnik na obiekt VentilatorTemplate z logiką zarządzania modułem wentylatora
		GunTemplate *p_templ_gun; //wskaźnik na obiekt GunTemplate z logiką zarządzania działem
		bool m_templ_use_physical_info;	//flaga, czy obiekt posiada wskaźnik energii i paliwa
		PhysicalInfoTemplate *p_templ_physical_info; //dane wzorca obiekty PhysicalInfoTemplate

	protected:

		///
		///Metoda tworzy obiekt klasy Actor
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Actor *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca danymi obiekt klasy Actor
		///
		///@param *actor - wskaźnik na obiekt klasy Actor
		///
		virtual void fill(Actor *actor);

	public:

		//metoda zwraca referencję na kontener z zestawem animacji
		inline const std::vector<AnimSet*> & getAvailableAnims()
		{
			return m_templ_available_animations;
		}
	};
} //namespace factory
#endif //H_ACTOR_TEMPLATE_JACK
