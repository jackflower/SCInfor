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
	///Klasa reprezentuje wyposa¿enie - oœwietlenie
	///
	class CLightingEquipment : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskaæ obiekt CLightingEquipment, nale¿y wywo³aæ CPhysicalManager::CreateLightingEquipment();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		CLightingEquipment(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param &CLightingEquipmentCopy - obiekt klasy CLightingEquipment
		///
		CLightingEquipment(const CLightingEquipment& CLightingEquipmentCopy);
				
		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CLightingEquipment(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê uk³adu oœwietlenia
		///
		const std::string GetLightingEquipmentName() const;

		///
		///Metoda ustawia nazwê uk³adu oœwietlenia
		///
		///@param &lighting_equipment_name - nazwê uk³adu oœwietlenia sta³a referencja na std::string
		///
		void SetLightingEquipmentName(const std::string & lighting_equipment_name);

		///
		///Metoda zwraca zu¿ycie energii urz¹dzenia
		///
		const float getEnergyConsumption() const;

		///
		///Metoda ustawia zu¿ycie energii urz¹dzenia
		///
		///@param energy_consumption - zu¿ycie energii
		///
		void setEnergyConsumption(float energy_consumption);

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (light on/off, run, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca referencjcê na modu³ sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logikê obiektu
		///
		///@param dt - czas
		///
		void Update(float dt);

	private:

		std::string					m_lighting_equipment_name;	//nazwa wyposa¿enia, uk³adu oœwietlajacego obiekt (reflektor, raca, pochodnia, ...etc)
		CSwitch						m_unit_controller;			//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka
		float						m_energy_consumption;		//zu¿ycie energii
		ELightingEquipmentState		m_lighting_equipment_state;	//wyliczenie stanów dla obiektu CLightingEquipment
		
		//oœwietlenie...
		//sprawdziæ, czy nie dodaæ metoda translacji gemometrii...
		//co tutaj jeszcze wt³oczyæ?
		//na spokojnie pomyœleæ...
		//jak to bêdzie ustalone oraz zaimpementowane
		//muszê napisaæ klasê fabryczn¹ dla tego obiektu...
		//iloœæ ¿arówek? - coœ na wzór si³y œwiat³a - snop œwiat³a?
		//

	};
}//namespace equipment
#endif//H_LIGHTING_EQUIPMENT_JACK