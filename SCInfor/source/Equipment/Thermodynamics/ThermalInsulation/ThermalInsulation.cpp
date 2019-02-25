//  ______________________________________________
// | ThermalInsulation.cpp - class implementation |
// | Jack Flower June 2014                        |
// |______________________________________________|
//

#include "ThermalInsulation.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Displayable/Displayable.h"

using namespace weather;

namespace equipment
{
	RTTI_IMPL(ThermalInsulation, Actor);

	//Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
	ThermalInsulation::ThermalInsulation(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_temperature_ambient(0.0f),
		m_thermal_protection(0.0f),
		m_thermal_protection_factor(0.0f),
		m_thermal_protection_consume(0.0f),
		m_thermal_protection_duration(0.0f),
		m_thermalinsulation_state(EThermalInsulationState::THERMALINSULATION_DEFAULT),
		m_unit_controller(false),//urządzenie wyłączone - uruchamia się z opóźnieniem
		m_elapsed_time(0.0f)
	{
		//to do: layers
	}

	//Chroniony konstruktor kopiujący
	ThermalInsulation::ThermalInsulation(const ThermalInsulation & CThermalInsulationCopy)
	:
		Actor(CThermalInsulationCopy),
		m_temperature_ambient(CThermalInsulationCopy.m_temperature_ambient),
		m_thermal_protection(CThermalInsulationCopy.m_thermal_protection),
		m_thermal_protection_factor(CThermalInsulationCopy.m_thermal_protection_factor),
		m_thermal_protection_consume(CThermalInsulationCopy.m_thermal_protection_consume),
		m_thermal_protection_duration(CThermalInsulationCopy.m_thermal_protection_duration),
		m_thermalinsulation_state(CThermalInsulationCopy.m_thermalinsulation_state),
		m_unit_controller(CThermalInsulationCopy.m_unit_controller),
		m_elapsed_time(CThermalInsulationCopy.m_elapsed_time)
	{
		//to do: layers
	}

	//Destruktor
	ThermalInsulation::~ThermalInsulation()
	{
		//Actor
		m_temperature_ambient = 0.0f;
		m_thermal_protection = 0.0f;
		m_thermal_protection_factor = 0.0f;
		m_thermal_protection_consume = 0.0f;
		m_thermal_protection_duration = 0.0f;
		m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DEFAULT;
		//m_unit_controller
		m_elapsed_time = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ThermalInsulation::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca nazwę termoizolatra
	const std::string ThermalInsulation::getThermalInsulationName() const
	{
		return m_thermalinsulation_name;
	}

	//Metoda ustawia nazwę termoizolatra
	void ThermalInsulation::setThermalInsulationName(const std::string& thermalinsulation_name)
	{
		m_thermalinsulation_name = thermalinsulation_name;
	}

	//Metoda zwraca temperaturę otoczenia - skorygowaną wielkością termiozolacji
	const float ThermalInsulation::getTemperatureAmbient() const
	{
		return m_temperature_ambient;
	}

	//Metoda ustawia temperaturę otoczenia - skorygowaną wielkością termiozolacji
	void ThermalInsulation::setTemperatureAmbient(float temperature_ambient)
	{
		m_temperature_ambient = temperature_ambient;
	}

	//Metoda zwraca wartość ochrony termicznej
	const float ThermalInsulation::getThermalProtection() const
	{
		return m_thermal_protection;
	}

	//Metoda ustawia wartość ochrony termicznej
	void ThermalInsulation::setThermalProtection(float thermal_protection)
	{
		m_thermal_protection = thermal_protection;
	}

	//Metoda zwraca współczynnik termoizolacji
	const float ThermalInsulation::getThermalProtectionFactor() const
	{
		return m_thermal_protection_factor;
	}

	//Metoda ustawia współczynnik termoizolacji
	void ThermalInsulation::setThermalProtectionFactor(float thermal_protection_factor)
	{
		m_thermal_protection_factor = thermal_protection_factor;
	}

	//Metoda zwraca wartość zużycia/starzenia obiektu
	const float ThermalInsulation::getThermalProtectionConsume() const
	{
		return m_thermal_protection_consume;
	}

	//Metoda ustawia wartość zużycia/starzenia obiektu
	void ThermalInsulation::setThermalProtectionConsume(float thermal_protection_consume)
	{
		m_thermal_protection_consume = thermal_protection_consume;
	}

	//Metoda zwraca czas trwania cyklu procesu starzenia
	const float ThermalInsulation::getThermalProtectionDuration() const
	{
		return m_thermal_protection_duration;
	}

	//Metoda ustawia czas trwania cyklu procesu starzenia
	void ThermalInsulation::setThermalProtectionDuration(float thermal_protection_duration)
	{
		m_thermal_protection_duration = thermal_protection_duration;
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & ThermalInsulation::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void ThermalInsulation::updateAnimations(float dt)
	{
		switch (m_thermalinsulation_state)
		{
		case EThermalInsulationState::THERMALINSULATION_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getThermalInsulationBodyDefaultAnim());
				setAnimationHead(p_anim_set->getThermalInsulationHeadDefaultAnim());
			}
			break;
		}
		case EThermalInsulationState::THERMALINSULATION_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getThermalInsulationBodyDamagetAnim());
				setAnimationHead(p_anim_set->getThermalInsulationHeadDamagetAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda aktualizuje logikę obiektu
	void ThermalInsulation::update(float dt)
	{
		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy włączonym urządzeniu
		if (m_unit_controller.getState())
		{
			//przekazanie temperatury otoczenia
			m_temperature_ambient = gWeather.getTemperature();
			//wyliczenie współczynnika termicznego w zależnści od kąta padania promieni słonecznych
			m_thermal_protection_factor = (gWeather.getSolarEnergyFactor() * m_thermal_protection);
			//korekty temperatury, względem której moduł klimatyzacji będzie regulował temperaturę wewnątrz układy
			m_temperature_ambient = m_temperature_ambient - m_thermal_protection_factor;

			//aktualizacja gdy zużycie wartość zużycia termoizolatora jest wartością dodatnią
			if(m_thermal_protection > 0)
			{
				//odmierzam uływ czasu dla aktualizacji zużycia/starzenia
				m_elapsed_time += dt;

				//jeśli upłynął czas - aktualizacja
				if(m_elapsed_time > m_thermal_protection_duration)
				{
					m_thermal_protection -= m_thermal_protection_consume;
					//jeśli wartość jest ujemna - zerujemy
					if(m_thermal_protection <= 0) m_thermal_protection = 0.0f;
					m_elapsed_time = 0.0f;
				}
			}
		}

		//aktualizuja stanu obiektu - termoizolator
		updateThermalInsulationState(dt);
	}

	//prywatna metoda aktualizuje stan obiektu - termoizolator
	void ThermalInsulation::updateThermalInsulationState(float dt)
	{
		//aktualizacja tylko przy włączonym urządzeniu
		if (m_unit_controller.getState())
			m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DEFAULT;
		else
			m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DAMAGE;
	}
}//namespace equipment
