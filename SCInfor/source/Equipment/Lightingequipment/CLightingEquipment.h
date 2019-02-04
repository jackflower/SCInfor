//  _______________________________________________
// | CLightingEquipment.h - class definition       |
// | Jack Flower - March 2015                      |
// |_______________________________________________|
//


#ifndef H_LIGHTING_EQUIPMENT_JACK
#define H_LIGHTING_EQUIPMENT_JACK

#include "../../Logic/Actor/CActor.h"
#include "../../RTTI/RTTI.h"
#include "../CSwitch.h"
#include "ELightingEquipmentState.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje wyposa�enie - o�wietlenie
	///
	class CLightingEquipment : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
			
		//Aby uzyska� obiekt CLightingEquipment, nale�y wywo�a� CPhysicalManager::CreateLightingEquipment();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		CLightingEquipment(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param &CLightingEquipmentCopy - obiekt klasy CLightingEquipment
		///
		CLightingEquipment(const CLightingEquipment& CLightingEquipmentCopy);
				
		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CLightingEquipment(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� uk�adu o�wietlenia
		///
		const std::string GetLightingEquipmentName() const;

		///
		///Metoda ustawia nazw� uk�adu o�wietlenia
		///
		///@param &lighting_equipment_name - nazw� uk�adu o�wietlenia sta�a referencja na std::string
		///
		void SetLightingEquipmentName(const std::string & lighting_equipment_name);

		///
		///Metoda zwraca zu�ycie energii urz�dzenia
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zu�ycie energii urz�dzenia
		///
		///@param energy_consumption - zu�ycie energii
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (light on/off, run, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca referencjc� na modu� sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logik� obiektu
		///
		///@param dt - czas
		///
		void Update(float dt);

	private:

		std::string					m_lighting_equipment_name;	//nazwa wyposa�enia, uk�adu o�wietlajacego obiekt (reflektor, raca, pochodnia, ...etc)
		CSwitch						m_unit_controller;			//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
		float						m_energy_consumption;		//zu�ycie energii
		ELightingEquipmentState		m_lighting_equipment_state;	//wyliczenie stan�w dla obiektu CLightingEquipment
		
		//o�wietlenie...
		//sprawdzi�, czy nie doda� metoda translacji gemometrii...
		//co tutaj jeszcze wt�oczy�?
		//na spokojnie pomy�le�...
		//jak to b�dzie ustalone oraz zaimpementowane
		//musz� napisa� klas� fabryczn� dla tego obiektu...
		//ilo�� �ar�wek? - co� na wz�r si�y �wiat�a - snop �wiat�a?
		//

	};
}//namespace equipment
#endif//H_LIGHTING_EQUIPMENT_JACK