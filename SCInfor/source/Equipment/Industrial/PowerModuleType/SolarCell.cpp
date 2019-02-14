//  ______________________________________
// | SolarCell.cpp - class implementation |
// | Jack Flower - July 2014              |
// |______________________________________|
//

#include "SolarCell.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Utilities/MathFunctions/MathFunctions.h"
#include <iostream>

using namespace weather;
using namespace maths;

namespace equipment
{
	RTTI_IMPL(SolarCell, PowerModule);

	//Chroniony konstruktor domyślny
	SolarCell::SolarCell(const std::wstring& uniqueId)
	:
		PowerModule(uniqueId),//konstruktor klasy bazowej
		m_solarcell_name(),
		m_energy_duration(0.0f),
		m_rotation_speed(0.0f),
		m_solarcell_state(SOLARCELL_DEFAULT),
		m_damage_duration(0.0f),
		m_death_duration(0.0f),
		m_calculated_energy_duration(0.0f)
	{
	}

	//Chroniony konstruktor kopiujący
	SolarCell::SolarCell(const SolarCell & SolarCellCopy)
	:
		PowerModule(SolarCellCopy),//konstruktor kopiujący klasy bazowej
		m_solarcell_name(SolarCellCopy.m_solarcell_name),
		m_energy_duration(SolarCellCopy.m_energy_duration),
		m_rotation_speed(SolarCellCopy.m_rotation_speed),
		m_solarcell_state(SolarCellCopy.m_solarcell_state),
		m_damage_duration(SolarCellCopy.m_damage_duration),
		m_death_duration(SolarCellCopy.m_death_duration),
		m_calculated_energy_duration(SolarCellCopy.m_calculated_energy_duration)
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	SolarCell::~SolarCell(void)
	{
		//PowerModule
		m_solarcell_name = "";
		m_energy_duration = 0.0f;
		m_rotation_speed = 0.0f;
		m_solarcell_state = SOLARCELL_DEFAULT;
		m_damage_duration = 0.0f;
		m_death_duration = 0.0f;
		m_calculated_energy_duration = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string SolarCell::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę fotoogniwa
	const std::string SolarCell::getSolarCellName() const
	{
		return m_solarcell_name;
	}

	//Metoda ustawia nazwę fotoogniwa
	void SolarCell::setSolarCellName(const std::string& solarcell_name)
	{
		m_solarcell_name = solarcell_name;
	}

	//Metoda zwraca czas, co jaki następuję proces dołądowywania energii
	const float SolarCell::getEnergyDuration() const
	{
		return m_energy_duration;
	}

	//Metoda ustawia czas, co jaki następuję proces dołądowywania energii
	void SolarCell::setEnergyDuration(float energy_duration)
	{
		m_energy_duration = energy_duration;
	}

	//Metoda zwraca prędkość obrotu
	const float SolarCell::getRotationSpeed() const
	{
		return m_rotation_speed;
	}

	//Metoda ustawia prędkość obrotu
	void SolarCell::setRotationSpeed(float rotation_speed)
	{
		m_rotation_speed = rotation_speed;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
	void SolarCell::updateAnimations(float dt)
	{
		switch(m_solarcell_state)
		{
		case SOLARCELL_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetSolarCellBodyDefaultAnim());
				setAnimationHead(p_anim_set->GetSolarCellHeadDefaultAnim());
			}
			break;
		}
		case SOLARCELL_UPDATE_ENERGY:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetSolarCellBodyUpdateEnergyAnim());
				setAnimationHead(p_anim_set->GetSolarCellHeadUpdateEnergyAnim());
			}
			break;
		}
		case SOLARCELL_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetSolarCellBodyDamageAnim());
				setAnimationHead(p_anim_set->GetSolarCellHeadDamageAnim());
			}
			break;
		}
		case SOLARCELL_DEATH:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetSolarCellBodyDeathAnim());
				setAnimationHead(p_anim_set->GetSolarCellHeadDeathAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizująca obiekt
	void SolarCell::update(float dt)
	{
		Physical::updateShadow(dt);//aktualizacja shadow engine

		//jeśli urządzenie jest włączone
		if(m_unit_controller.getState())
		{
			updateSolarCellState(dt);
			updateAnimations(dt);
		}
	}

	
	//implementacja metod private:

	//prywatna metoda aktualizuje stan obiektu
	void SolarCell::updateSolarCellState(float dt)
	{
		//proces przebiega - fotoogniwo gromadzi energię
		if(m_stored_energy < m_energy_capacitor)
		{
			if(gWeather.getTemperature() > 0)
				m_solarcell_state = SOLARCELL_UPDATE_ENERGY; //aktywacja ładowania fotoogniwa
			else
				m_solarcell_state = SOLARCELL_DEFAULT; //default machine state

			if(m_solarcell_state == SOLARCELL_UPDATE_ENERGY)
			{
				//ładowanie fotoogniwa i aktualizacja obrotu względem źródła energii (solar)
				updateRotation(dt);
					
				//zliczam czas
				m_calculated_energy_duration += dt;
				if(m_calculated_energy_duration >= m_energy_duration)
				{
					//aktualizacja energii
					m_stored_energy += m_power * maths::Abs(gWeather.getSolarEnergyFactor());

					if(m_stored_energy > m_energy_capacitor)//kalibracja do wartości oczekiwanej
						m_stored_energy = m_energy_capacitor;

					m_calculated_energy_duration = 0.0f;//zeruję czas
					//std::cout << "temperature:    " << gWeather.getTemperature() << " stored_energy: " << m_current_stored_energy << std::endl;
				}
			}
		}
		else
			m_solarcell_state = SOLARCELL_DEFAULT;//default machine state
	}

	//prywatna metoda płynnie obracająca fotoogniwo w kierunku źródła energii
	void SolarCell::updateRotation(float dt)
	{
		//2014-08-08
		//bardzo źle napisany kod - zająć się tym w innym czasie...
		//kąt obrotu obiektu jest mniejszy od kąta źródła termicznego
		if(getRotationHead() < (gWeather.getAngleSun() - CALIBRATION_FACTOR_ANGLE))
		{
			setRotationHead(getRotationHead() + m_rotation_speed * dt);
			if(getRotationHead() <= (gWeather.getAngleSun()- CALIBRATION_FACTOR_ANGLE))
				return;//wyjście, jeśli warunek spełniony
		}
		else
		{
			setRotationHead(getRotationHead() - m_rotation_speed * dt);
			if(getRotationHead() >= (gWeather.getAngleSun() - CALIBRATION_FACTOR_ANGLE))
				return;//wyjście, jeśli warunek spełniony
		}
		//old code:
		//SetRotationHead(gWeather.getAngleSun()- CALIBRATION_FACTOR_ANGLE);
	}
}//namespace equipment
