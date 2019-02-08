//  ______________________________________________
// | LightingEquipment.h - class definition       |
// | Jack Flower - March 2015                     |
// |______________________________________________|
//


#ifndef H_LIGHTING_EQUIPMENT_JACK
#define H_LIGHTING_EQUIPMENT_JACK

#include "../../Logic/Actor/Actor.h"
#include "../../RTTI/RTTI.h"
#include "../Switch.h"
#include "ELightingEquipmentState.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje wyposażenie - oświetlenie
	///
	class LightingEquipment : public Actor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskać obiekt LightingEquipment, należy wywołać CPhysicalManager::CreateLightingEquipment();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		LightingEquipment(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param LightingEquipmentCopy - obiekt klasy LightingEquipment
		///
		LightingEquipment(const LightingEquipment & LightingEquipmentCopy);
				
		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~LightingEquipment(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę układu oświetlenia
		///
		const std::string getLightingEquipmentName() const;

		///
		///Metoda ustawia nazwę układu oświetlenia
		///
		///@param lighting_equipment_name - nazwę układu oświetlenia stała referencja na std::string
		///
		void setLightingEquipmentName(const std::string & lighting_equipment_name);

		///
		///Metoda zwraca zużycie energii urządzenia
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zużycie energii urządzenia
		///
		///@param energy_consumption - zużycie energii
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (light on/off, run, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string m_lighting_equipment_name; //nazwa wyposażenia, układu oświetlajacego obiekt (reflektor, raca, pochodnia, ...etc)
		Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
		float m_energy_consumption; //zużycie energii
		ELightingEquipmentState m_lighting_equipment_state;	//wyliczenie stanów dla obiektu LightingEquipment
		
		//oświetlenie...
		//sprawdzić, czy nie dodać metoda translacji gemometrii...
		//co tutaj jeszcze wtłoczyć?
		//na spokojnie pomyśleć...
		//jak to będzie ustalone oraz zaimpementowane
		//muszę napisać klasę fabryczną dla tego obiektu...
		//ilość żarówek? - coś na wzór siły światła - snop światła?
		//

	};
}//namespace equipment
#endif//H_LIGHTING_EQUIPMENT_JACK
