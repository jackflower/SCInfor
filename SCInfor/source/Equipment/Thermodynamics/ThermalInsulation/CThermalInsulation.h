//  _______________________________________________
// | CThermalInsulation.h - class definition       |
// | Jack Flower June 2014                         |
// |_______________________________________________|
//

#ifndef H_THERMAL_INSULATION_JACK
#define H_THERMAL_INSULATION_JACK

#include "EThermalInsulationState.h"
#include "../../../Logic/Actor/CActor.h"
#include "../../CSwitch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje funkcjonalnoœæ termoizolatora
	///
	class CThermalInsulation : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;

		//Aby uzyskaæ obiekt CThermalInsulation, nale¿y wywo³aæ CPhysicalManager::CreateThermalInsulation();

	protected:

		///
		///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		CThermalInsulation(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CThermalInsulationCopy - sta³a referecja na obiekt klasy CThermalInsulation
		///
		CThermalInsulation(const CThermalInsulation & CThermalInsulationCopy);

		///
		///Destruktor
		///
		~CThermalInsulation();
	
	public:
		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê termoizolatra
		///
		const std::string GetThermalInsulationName() const;

		///
		///Metoda ustawia nazwê termoizolatra
		///
		///@param &thermalinsulation_name - typ termoizolatora sta³a referencja na std::string
		///
		void SetThermalInsulationName(const std::string& thermalinsulation_name);

		///
		///Metoda zwraca temperaturê otoczenia - skorygowan¹ wielkoœci¹ termiozolacji
		///
		const float getTemperatureAmbient() const;

		///
		///Metoda ustawia temperaturê otoczenia - skorygowan¹ wielkoœci¹ termiozolacji
		///
		///@param temperature_ambient - temperatura otoczenia - skorygowana wielkoœci¹ termiozolacji
		///
		void setTemperatureAmbient(float temperature_ambient);

		///
		///Metoda zwraca wartoœæ ochrony termicznej
		///
		const float getThermalProtection() const;

		///
		///Metoda ustawia wartoœæ ochrony termicznej
		///
		///@param thermal_protection - ochrona termiczna - termoizolator
		///
		void setThermalProtection(float thermal_protection);

		///
		///Metoda zwraca wspó³czynnik termoizolacji
		///
		const float getThermalProtectionFactor() const;

		///
		///Metoda ustawia wspó³czynnik termoizolacji
		///
		///@param thermal_protection_factor - wspó³czynnik termoizolacji
		///
		void setThermalProtectionFactor(float thermal_protection_factor);

		///
		///Metoda zwraca wartoœæ zu¿ycia/starzenia obiektu
		///
		const float getThermalProtectionConsume() const;

		///
		///Metoda ustawia wartoœæ zu¿ycia/starzenia obiektu
		///
		///@param thermal_protection_consume - zu¿ycie/starzenie
		///
		void setThermalProtectionConsume(float thermal_protection_consume);

		///
		///Metoda zwraca czas trwania cyklu procesu starzenia
		///
		const float getThermalProtectionDuration() const;

		///
		///Metoda ustawia czas trwania cyklu procesu starzenia
		///
		///@param thermal_protection_duration - czas trwania cyklu procesu starzenia
		///
		void setThermalProtectionDuration(float thermal_protection_duration);

		///
		///Metoda zwraca referencjcê na modu³ sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void UpdateAnimations(float dt);

		///
		///Metoda aktualizuje logikê obiektu
		///
		///@param dt - czas
		///
		void Update(float dt);

	private:

		std::string				m_thermalinsulation_name;		//nazwa termoizolatora
		float					m_temperature_ambient;			//temperatura otoczenia - skorygowana wielkoœci¹ termiozolacji
		float					m_thermal_protection;			//ochrona termiczna - termoizolator
		float					m_thermal_protection_factor;	//obliczany wspó³czynnik termoizolacji
		float					m_thermal_protection_consume;	//wartoœæ zu¿ycia ochrony termicznej w jednostce czasu
		float					m_thermal_protection_duration;	//czas cyklu procesu zu¿ycia/starzenia ochrony termicznej
		EThermalInsulationState m_thermalinsulation_state;		//wyliczenie stanów
		CSwitch					m_unit_controller;				//w³¹cznik urz¹dzenie
		float					m_elapsed_time;					//czas procesu - sk³adawa pomocnicza

		//prywatna metoda aktualizuje stan obiektu - termoizolator
		void updateThermalInsulationState(float dt);
	};
}//namespace equipment
#endif//H_THERMAL_INSULATION_JACK
