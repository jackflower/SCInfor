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

	//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
	CThermalInsulation::CThermalInsulation(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),//konstruktor klasy bazowej
		m_temperature_ambient			(0.0f),
		m_thermal_protection			(0.0f),
		m_thermal_protection_factor		(0.0f),
		m_thermal_protection_consume	(0.0f),
		m_thermal_protection_duration	(0.0f),
		m_thermalinsulation_state		(EThermalInsulationState::THERMALINSULATION_DEFAULT),
		m_unit_controller				(false),//urz¹dzenie wy³¹czone - uruchamia siê z opóŸnieniem
		m_elapsed_time					(0.0f)
	{
	}

	//Chroniony konstruktor kopiuj¹cy
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

	//Metoda zwraca nazwê termoizolatra
	const std::string CThermalInsulation::GetThermalInsulationName() const
	{
		return m_thermalinsulation_name;
	}

	//Metoda ustawia nazwê termoizolatra
	void CThermalInsulation::SetThermalInsulationName(const std::string& thermalinsulation_name)
	{
		m_thermalinsulation_name = thermalinsulation_name;
	}

	//Metoda zwraca temperaturê otoczenia - skorygowan¹ wielkoœci¹ termiozolacji
	const float CThermalInsulation::getTemperatureAmbient() const
	{
		return m_temperature_ambient;
	}

	//Metoda ustawia temperaturê otoczenia - skorygowan¹ wielkoœci¹ termiozolacji
	void CThermalInsulation::setTemperatureAmbient(float temperature_ambient)
	{
		m_temperature_ambient = temperature_ambient;
	}

	//Metoda zwraca wartoœæ ochrony termicznej
	const float CThermalInsulation::getThermalProtection() const
	{
		return m_thermal_protection;
	}

	//Metoda ustawia wartoœæ ochrony termicznej
	void CThermalInsulation::setThermalProtection(float thermal_protection)
	{
		m_thermal_protection = thermal_protection;
	}

	//Metoda zwraca wspó³czynnik termoizolacji
	const float CThermalInsulation::getThermalProtectionFactor() const
	{
		return m_thermal_protection_factor;
	}

	//Metoda ustawia wspó³czynnik termoizolacji
	void CThermalInsulation::setThermalProtectionFactor(float thermal_protection_factor)
	{
		m_thermal_protection_factor = thermal_protection_factor;
	}

	//Metoda zwraca wartoœæ zu¿ycia/starzenia obiektu
	const float CThermalInsulation::getThermalProtectionConsume() const
	{
		return m_thermal_protection_consume;
	}

	//Metoda ustawia wartoœæ zu¿ycia/starzenia obiektu
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

	//Metoda zwraca referencjcê na modu³ sterowania
	CSwitch & CThermalInsulation::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
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

	//Metoda aktualizuje logikê obiektu
	void CThermalInsulation::Update(float dt)
	{
		//aktywacja
		m_unit_controller.updateToRun(dt);

		//aktualizacja tylko przy w³¹czonym urz¹dzeniu
		if (m_unit_controller.getState())
		{
			//przekazanie temperatury otoczenia
			m_temperature_ambient = gWeather.getTemperature();
			//wyliczenie wsó³czynnika termicznego w zale¿nœci od k¹ta padania promieni s³onecznych
			m_thermal_protection_factor = (gWeather.getSolarEnergyFactor() * m_thermal_protection);
			//korekty temperatury, wzglêdem której modu³ klimatyzacji bêdzie regulowa³ temperaturê wewn¹trz uk³ady
			m_temperature_ambient = m_temperature_ambient - m_thermal_protection_factor;

			//aktualizacja gdy zu¿ycie wartoœæ zu¿ycia termoizolatora jest wartoœci¹ dodatni¹
			if(m_thermal_protection > 0)
			{
				//odmierzam u³yw czasu dla aktualizacji zu¿ycia/starzenia
				m_elapsed_time += dt;

				//jeœli up³yn¹³ czas - aktualizacja
				if(m_elapsed_time > m_thermal_protection_duration)
				{
					m_thermal_protection -= m_thermal_protection_consume;
					//jeœli wartoœæ jest ujemna - zerujemy
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
		//aktualizacja tylko przy w³¹czonym urz¹dzeniu
		if (m_unit_controller.getState())
			m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DEFAULT;
		else
			m_thermalinsulation_state = EThermalInsulationState::THERMALINSULATION_DAMAGE;
	}
}//namespace equipment
