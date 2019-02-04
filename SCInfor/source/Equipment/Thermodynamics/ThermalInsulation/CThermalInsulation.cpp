//  _______________________________________________
// | CThermalInsulation.cpp - class implementation |
// | Jack Flower June 2014                         |
// |_______________________________________________|
//

#include "CThermalInsulation.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

using namespace weather;

namespace equipment
{
	RTTI_IMPL(CThermalInsulation, CActor);

	//Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
	CThermalInsulation::CThermalInsulation(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),//konstruktor klasy bazowej
		m_temperature_ambient			(0.0f),
		m_thermal_protection			(0.0f),
		m_thermal_protection_factor		(0.0f),
		m_thermal_protection_consume	(0.0f),
		m_thermal_protection_duration	(0.0f),
		m_thermalinsulation_state		(EThermalInsulationState::THERMALINSULATION_DEFAULT),
		m_unit_controller				(false),//urz�dzenie wy��czone - uruchamia si� z op�nieniem
		m_elapsed_time					(0.0f)
	{
	}

	//Chroniony konstruktor kopiuj�cy
	CThermalInsulation::CThermalInsulation(const CThermalInsulation & CThermalInsulationCopy)
	:
		CActor							(CThermalInsulationCopy),
		m_temperature_ambient			(CThermalInsulationCopy.m_temperature_ambient),
		m_thermal_protection			(CThermalInsulationCopy.m_thermal_protection),
		m_thermal_protection_factor		(CThermalInsulationCopy.m_thermal_protection_factor),
		m_thermal_protection_consume	(CThermalInsulationCopy.m_thermal_protection_consume),
		m_thermal_protection_duration	(CThermalInsulationCopy.m_thermal_protection_duration),
		m_thermalinsulation_state		(CThermalInsulationCopy.m_thermalinsulation_state),
		m_unit_controller				(CThermalInsulationCopy.m_unit_controller),
		m_elapsed_time					(CThermalInsulationCopy.m_elapsed_time)
	{
	}

	//Destruktor
	CThermalInsulation::~CThermalInsulation()
	{
		//CActor						not edit
		m_temperature_ambient			= 0.0f;
		m_thermal_protection			= 0.0f;
		m_thermal_protection_factor		= 0.0f;
		m_thermal_protection_consume	= 0.0f;
		m_thermal_protection_duration	= 0.0f;
		m_thermalinsulation_state		= EThermalInsulationState::THERMALINSULATION_DEFAULT;
		//m_unit_controller				not edit
		m_elapsed_time				= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CThermalInsulation::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazw� termoizolatra
	const std::string CThermalInsulation::GetThermalInsulationName() const
	{
		return m_thermalinsulation_name;
	}

	//Metoda ustawia nazw� termoizolatra
	void CThermalInsulation::SetThermalInsulationName(const std::string& thermalinsulation_name)
	{
		m_thermalinsulation_name = thermalinsulation_name;
	}

	//Metoda zwraca temperatur� otoczenia - skorygowan� wielko�ci� termiozolacji
	const float CThermalInsulation::getTemperatureAmbient() const
	{
		return m_temperature_ambient;
	}

	//Metoda ustawia temperatur� otoczenia - skorygowan� wielko�ci� termiozolacji
	void CThermalInsulation::setTemperatureAmbient(float temperature_ambient)
	{
		m_temperature_ambient = temperature_ambient;
	}

	//Metoda zwraca warto�� ochrony termicznej
	const float CThermalInsulation::getThermalProtection() const
	{
		return m_thermal_protection;
	}

	//Metoda ustawia warto�� ochrony termicznej
	void CThermalInsulation::setThermalProtection(float thermal_protection)
	{
		m_thermal_protection = thermal_protection;
	}

	//Metoda zwraca wsp�czynnik termoizolacji
	const float CThermalInsulation::getThermalProtectionFactor() const
	{
		return m_thermal_protection_factor;
	}

	//Metoda ustawia wsp�czynnik termoizolacji
	void CThermalInsulation::setThermalProtectionFactor(float thermal_protection_factor)
	{
		m_thermal_protection_factor = thermal_protection_factor;
	}

	//Metoda zwraca warto�� zu�ycia/starzenia obiektu
	const float CThermalInsulation::getThermalProtectionConsume() const
	{
		return m_thermal_protection_consume;
	}

	//Metoda ustawia warto�� zu�ycia/starzenia obiektu
	void CThermalInsulation::setThermalProtectionConsume(float thermal_protection_consume)
	{
		m_thermal_protection_consume = thermal_protection_consume;
	}

	//Metoda zwraca czas trwania cyklu procesu starzenia
	const float CThermalInsulation::getThermalProtectionDuration() const
	{
		return m_thermal_protection_duration;
	}

	//Metoda ustawia czas trwania cyklu procesu starzenia
	void CThermalInsulation::setThermalProtectionDuration(float thermal_protection_duration)
	{
		m_thermal_protection_duration = thermal_protection_duration;
	}

	//Metoda zwraca referencjc� na modu� sterowania
	CSwitch & CThermalInsulation::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
	void CThermalInsulation::updateAnimations(float dt)
	{
		switch (m_thermalinsulation_state)
		{
		case EThermalInsulationState::THERMALINSULATION_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetThermalInsulationBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetThermalInsulationHeadDefaultAnim());
			}
			break;
		}
		case EThermalInsulationState::THERMALINSULATION_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetThermalInsulationBodyDamagetAnim());
				SetAnimationHead(p_anim_set->GetThermalInsulationHeadDamagetAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda aktualizuje logik� obiektu
	void CThermalInsulation::Update(float dt)
	{
		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy w��czonym urz�dzeniu
		if (m_unit_controller.getState())
		{
			//przekazanie temperatury otoczenia
			m_temperature_ambient = gWeather.getTemperature();
			//wyliczenie ws�czynnika termicznego w zale�n�ci od k�ta padania promieni s�onecznych
			m_thermal_protection_factor = (gWeather.getSolarEnergyFactor() * m_thermal_protection);
			//korekty temperatury, wzgl�dem kt�rej modu� klimatyzacji b�dzie regulowa� temperatur� wewn�trz uk�ady
			m_temperature_ambient = m_temperature_ambient - m_thermal_protection_factor;

			//aktualizacja gdy zu�ycie warto�� zu�ycia termoizolatora jest warto�ci� dodatni�
			if(m_thermal_protection > 0)
			{
				//odmierzam u�yw czasu dla aktualizacji zu�ycia/starzenia
				m_elapsed_time += dt;

				//je�li up�yn�� czas - aktualizacja
				if(m_elapsed_time > m_thermal_protection_duration)
				{
					m_thermal_protection -= m_thermal_protection_consume;
					//je�li warto�� jest ujemna - zerujemy
					if(m_thermal_protection <= 0) m_thermal_protection = 0.0f;
					m_elapsed_time = 0.0f;
				}
			}
		}

		//aktualizuja stanu obiektu - termoizolator
		updateThermalInsulationState(dt);
	}

	//prywatna metoda aktualizuje stan obiektu - termoizolator
	void CThermalInsulation::updateThermalInsulationState(float dt)
	{
		//aktualizacja tylko przy w��czonym urz�dzeniu
		if (m_unit_controller.getState())
			m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DEFAULT;
		else
			m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DAMAGE;
	}
}//namespace equipment
