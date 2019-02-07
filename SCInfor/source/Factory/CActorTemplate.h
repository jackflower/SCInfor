//  ___________________________________________
// | CActorTemplate.h - class definition       |
// | Jack Flower - February 2013               |
// |___________________________________________|
//

#ifndef H_ACTOR_TEMPLATE_JACK
#define H_ACTOR_TEMPLATE_JACK

#include "CPhysicalTemplate.h"
#include "../Logic/Actor/CActor.h"
#include <string>
#include <vector>
#include <iostream>

///
///Forward declaration
///
namespace xml
{
	class CXml;
}

///
///Forward declaration
///
namespace logic
{
	class CActor;
}

///
///Forward declaration
///
namespace rendering
{
	namespace animation
	{
		class CAnimSet;
	}
}

///
///Forward declaration
///
namespace factory
{
	class CEngineTemplate;
	class EnergyTemplate;
	class CAirconditioningTemplate;
	class CVentilatorTemplate;
	class CGunTemplate;
	class CWindTurbineTemplate;
	class CWindPowerStationTemplate;
	class CPhysicalInfoTemplate;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec aktora
	///
	class CActorTemplate : public CPhysicalTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CActorTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CActorTemplate();

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
		///Wirtualna metoda �aduj�ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);
			
	protected:

		CAnimSet*						p_templ_animations;				//wska�nik na zestaw animacji CActor
		std::vector<CAnimSet*>			m_templ_available_animations;	//wektor wska�nik�w na zestawy dost�pnych animacji dla CActor
		CActorTechnicalData				m_templ_technical_data;			//opakowanie fizyki
		EquipmentEngineData			m_templ_engine_data;			//opakowanie funkcjonalno�ci silnika
		EquipmentEnergyData			m_templ_energy_data;			//opakowanie funkcjonalno�ci energii
		EquipmentAirconditioningData	m_templ_airconditioning_data;	//opakowanie funkcjonalno�ci klimatyzacji
		EquipmentVentilatorData		m_templ_ventilator_data;		//opakowanie funkcjonalno�ci wentylatora
		EquipmentGunData				m_templ_gun_data;				//opakowanie funkcjonalno�ci dzia�o
		CEngineTemplate*				p_templ_engine;					//dane wzorca obiektu Engine
		EnergyTemplate*				p_templ_energy;					//dane wzorca obiektu Energy
		CAirconditioningTemplate*		p_templ_airconditioning;		//wska�nik na obiekt Airconditioning z logik� zarz�dzania modu�em klimatyzatora
		CVentilatorTemplate*			p_templ_ventilator;				//wska�nik na obiekt CVentilatorTemplate z logik� zarz�dzania modu�em wentylatora
		CGunTemplate*					p_templ_gun;					//wska�nik na obiekt CGunTemplate z logik� zarz�dzania dzia�em
		
		bool							m_templ_use_physical_info;		//flaga, czy obiekt posiada wska�nik energii i paliwa
		CPhysicalInfoTemplate*			p_templ_physical_info;			//dane wzorca obiekty CPhysicalInfoTemplate

	protected:

		///
		///Metoda tworzy obiekt klasy CActor
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CActor* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca danymi obiekt klasy CActor
		///
		///@param *actor - wska�nik na obiekt klasy CActor
		///
		virtual void fill(CActor *actor);

	public:

		//metoda zwraca referencj� na kontener z zestawem animacji
		inline const std::vector<CAnimSet*> &GetAvailableAnims() { return m_templ_available_animations; }
	};
} //namespace factory
#endif //H_ACTOR_TEMPLATE_JACK
