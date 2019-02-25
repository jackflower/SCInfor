//  ______________________________________________
// | ThermalInsulation.h - class definition       |
// | Jack Flower June 2014                        |
// |______________________________________________|
//

#ifndef H_THERMAL_INSULATION_JACK
#define H_THERMAL_INSULATION_JACK

#include "EThermalInsulationState.h"
#include "../../../Logic/Actor/Actor.h"
#include "../../Switch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje funkcjonalność termoizolatora
	///
	class ThermalInsulation : public Actor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;

		//Aby uzyskać obiekt ThermalInsulation, należy wywołać PhysicalManager::CreateThermalInsulation();

	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		ThermalInsulation(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param ThermalInsulationCopy - stała referecja na obiekt klasy ThermalInsulation
		///
		ThermalInsulation(const ThermalInsulation & ThermalInsulationCopy);

		///
		///Destruktor
		///
		~ThermalInsulation();
	
	public:
		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę termoizolatra
		///
		const std::string getThermalInsulationName() const;

		///
		///Metoda ustawia nazwę termoizolatra
		///
		///@param thermalinsulation_name - typ termoizolatora stała referencja na std::string
		///
		void setThermalInsulationName(const std::string & thermalinsulation_name);

		///
		///Metoda zwraca temperaturę otoczenia - skorygowaną wielkością termiozolacji
		///
		const float getTemperatureAmbient() const;

		///
		///Metoda ustawia temperaturę otoczenia - skorygowaną wielkością termiozolacji
		///
		///@param temperature_ambient - temperatura otoczenia - skorygowana wielkością termiozolacji
		///
		void setTemperatureAmbient(float temperature_ambient);

		///
		///Metoda zwraca wartość ochrony termicznej
		///
		const float getThermalProtection() const;

		///
		///Metoda ustawia wartość ochrony termicznej
		///
		///@param thermal_protection - ochrona termiczna - termoizolator
		///
		void setThermalProtection(float thermal_protection);

		///
		///Metoda zwraca współczynnik termoizolacji
		///
		const float getThermalProtectionFactor() const;

		///
		///Metoda ustawia współczynnik termoizolacji
		///
		///@param thermal_protection_factor - współczynnik termoizolacji
		///
		void setThermalProtectionFactor(float thermal_protection_factor);

		///
		///Metoda zwraca wartość zużycia/starzenia obiektu
		///
		const float getThermalProtectionConsume() const;

		///
		///Metoda ustawia wartość zużycia/starzenia obiektu
		///
		///@param thermal_protection_consume - zużycie/starzenie
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
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string m_thermalinsulation_name; //nazwa termoizolatora
		float m_temperature_ambient; //temperatura otoczenia - skorygowana wielkością termiozolacji
		float m_thermal_protection; //ochrona termiczna - termoizolator
		float m_thermal_protection_factor; //obliczany współczynnik termoizolacji
		float m_thermal_protection_consume;	//wartość zużycia ochrony termicznej w jednostce czasu
		float m_thermal_protection_duration; //czas cyklu procesu zużycia/starzenia ochrony termicznej
		EThermalInsulationState m_thermalinsulation_state; //wyliczenie stanów
		Switch m_unit_controller; //włącznik urządzenie
		float m_elapsed_time; //czas procesu - składawa pomocnicza

		//prywatna metoda aktualizuje stan obiektu - termoizolator
		void updateThermalInsulationState(float dt);
	};
}//namespace equipment
#endif//H_THERMAL_INSULATION_JACK
