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
	///Klasa reprezentuje funkcjonalno�� termoizolatora
	///
	class CThermalInsulation : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CThermalInsulation, nale�y wywo�a� CPhysicalManager::CreateThermalInsulation();

	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
		///
		CThermalInsulation(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CThermalInsulationCopy - sta�a referecja na obiekt klasy CThermalInsulation
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
		///Metoda zwraca nazw� termoizolatra
		///
		const std::string GetThermalInsulationName() const;

		///
		///Metoda ustawia nazw� termoizolatra
		///
		///@param &thermalinsulation_name - typ termoizolatora sta�a referencja na std::string
		///
		void SetThermalInsulationName(const std::string& thermalinsulation_name);

		///
		///Metoda zwraca temperatur� otoczenia - skorygowan� wielko�ci� termiozolacji
		///
		const float getTemperatureAmbient() const;

		///
		///Metoda ustawia temperatur� otoczenia - skorygowan� wielko�ci� termiozolacji
		///
		///@param temperature_ambient - temperatura otoczenia - skorygowana wielko�ci� termiozolacji
		///
		void setTemperatureAmbient(float temperature_ambient);

		///
		///Metoda zwraca warto�� ochrony termicznej
		///
		const float getThermalProtection() const;

		///
		///Metoda ustawia warto�� ochrony termicznej
		///
		///@param thermal_protection - ochrona termiczna - termoizolator
		///
		void setThermalProtection(float thermal_protection);

		///
		///Metoda zwraca wsp�czynnik termoizolacji
		///
		const float getThermalProtectionFactor() const;

		///
		///Metoda ustawia wsp�czynnik termoizolacji
		///
		///@param thermal_protection_factor - wsp�czynnik termoizolacji
		///
		void setThermalProtectionFactor(float thermal_protection_factor);

		///
		///Metoda zwraca warto�� zu�ycia/starzenia obiektu
		///
		const float getThermalProtectionConsume() const;

		///
		///Metoda ustawia warto�� zu�ycia/starzenia obiektu
		///
		///@param thermal_protection_consume - zu�ycie/starzenie
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
		///Metoda zwraca referencjc� na modu� sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void UpdateAnimations(float dt);

		///
		///Metoda aktualizuje logik� obiektu
		///
		///@param dt - czas
		///
		void Update(float dt);

	private:

		std::string				m_thermalinsulation_name;		//nazwa termoizolatora
		float					m_temperature_ambient;			//temperatura otoczenia - skorygowana wielko�ci� termiozolacji
		float					m_thermal_protection;			//ochrona termiczna - termoizolator
		float					m_thermal_protection_factor;	//obliczany wsp�czynnik termoizolacji
		float					m_thermal_protection_consume;	//warto�� zu�ycia ochrony termicznej w jednostce czasu
		float					m_thermal_protection_duration;	//czas cyklu procesu zu�ycia/starzenia ochrony termicznej
		EThermalInsulationState m_thermalinsulation_state;		//wyliczenie stan�w
		CSwitch					m_unit_controller;				//w��cznik urz�dzenie
		float					m_elapsed_time;					//czas procesu - sk�adawa pomocnicza

		//prywatna metoda aktualizuje stan obiektu - termoizolator
		void updateThermalInsulationState(float dt);
	};
}//namespace equipment
#endif//H_THERMAL_INSULATION_JACK
