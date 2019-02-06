//  ______________________________________
// | SolarCell.cpp - class implementation |
// | Jack Flower - July 2014              |
// |______________________________________|
//

#include "SolarCell.h"
#include "../../../Weather/CWeather.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Utilities/MathFunctions/MathFunctions.h"
#include <iostream>

using namespace weather;
using namespace maths;

namespace equipment
{
	RTTI_IMPL(SolarCell, PowerModule);

	//Chroniony konstruktor domy�lny
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

	//Chroniony konstruktor kopiuj�cy
	SolarCell::SolarCell(const SolarCell & SolarCellCopy)
	:
		PowerModule(SolarCellCopy),//konstruktor kopiuj�cy klasy bazowej
		m_solarcell_name(SolarCellCopy.m_solarcell_name),
		m_energy_duration(SolarCellCopy.m_energy_duration),
		m_rotation_speed(SolarCellCopy.m_rotation_speed),
		m_solarcell_state(SolarCellCopy.m_solarcell_state),
		m_damage_duration(SolarCellCopy.m_damage_duration),
		m_death_duration(SolarCellCopy.m_death_duration),
		m_calculated_energy_duration(SolarCellCopy.m_calculated_energy_duration)
	{
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

	//Metoda zwraca nazw� fotoogniwa
	const std::string SolarCell::getSolarCellName() const
	{
		return m_solarcell_name;
	}

	//Metoda ustawia nazw� fotoogniwa
	void SolarCell::setSolarCellName(const std::string& solarcell_name)
	{
		m_solarcell_name = solarcell_name;
	}

	//Metoda zwraca czas, co jaki nast�puj� proces do��dowywania energii
	const float SolarCell::getEnergyDuration() const
	{
		return m_energy_duration;
	}

	//Metoda ustawia czas, co jaki nast�puj� proces do��dowywania energii
	void SolarCell::setEnergyDuration(float energy_duration)
	{
		m_energy_duration = energy_duration;
	}

	//Metoda zwraca pr�dko�� obrotu
	const float SolarCell::getRotationSpeed() const
	{
		return m_rotation_speed;
	}

	//Metoda ustawia pr�dko�� obrotu
	void SolarCell::setRotationSpeed(float rotation_speed)
	{
		m_rotation_speed = rotation_speed;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
	void SolarCell::updateAnimations(float dt)
	{
		switch(m_solarcell_state)
		{
		case SOLARCELL_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetSolarCellBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetSolarCellHeadDefaultAnim());
			}
			break;
		}
		case SOLARCELL_UPDATE_ENERGY:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetSolarCellBodyUpdateEnergyAnim());
				SetAnimationHead(p_anim_set->GetSolarCellHeadUpdateEnergyAnim());
			}
			break;
		}
		case SOLARCELL_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetSolarCellBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetSolarCellHeadDamageAnim());
			}
			break;
		}
		case SOLARCELL_DEATH:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetSolarCellBodyDeathAnim());
				SetAnimationHead(p_anim_set->GetSolarCellHeadDeathAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void SolarCell::update(float dt)
	{
		CPhysical::UpdateShadow(dt);//aktualizacja shadow engine

		//je�li urz�dzenie jest w��czone
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
		//proces przebiega - fotoogniwo gromadzi energi�
		if(m_stored_energy < m_energy_capacitor)
		{
			if(gWeather.getTemperature() > 0)
				m_solarcell_state = SOLARCELL_UPDATE_ENERGY; //aktywacja �adowania fotoogniwa
			else
				m_solarcell_state = SOLARCELL_DEFAULT; //default machine state

			if(m_solarcell_state == SOLARCELL_UPDATE_ENERGY)
			{
				//�adowanie fotoogniwa i aktualizacja obrotu wzgl�dem �r�d�a energii (solar)
				updateRotation(dt);
					
				//zliczam czas
				m_calculated_energy_duration += dt;
				if(m_calculated_energy_duration >= m_energy_duration)
				{
					//aktualizacja energii
					m_stored_energy += m_power * maths::Abs(gWeather.getSolarEnergyFactor());

					if(m_stored_energy > m_energy_capacitor)//kalibracja do warto�ci oczekiwanej
						m_stored_energy = m_energy_capacitor;

					m_calculated_energy_duration = 0.0f;//zeruj� czas
					//std::cout << "temperature:    " << gWeather.getTemperature() << " stored_energy: " << m_current_stored_energy << std::endl;
				}
			}
		}
		else
			m_solarcell_state = SOLARCELL_DEFAULT;//default machine state
	}

	//prywatna metoda p�ynnie obracaj�ca fotoogniwo w kierunku �r�d�a energii
	void SolarCell::updateRotation(float dt)
	{
		//2014-08-08
		//bardzo �le napisany kod - zaj�� si� tym w innym czasie...
		//k�t obrotu obiektu jest mniejszy od k�ta �r�d�a termicznego
		if(GetRotationHead() < (gWeather.getAngleSun() - CALIBRATION_FACTOR_ANGLE))
		{
			SetRotationHead(GetRotationHead() + m_rotation_speed * dt);
			if(GetRotationHead() <= (gWeather.getAngleSun()- CALIBRATION_FACTOR_ANGLE))
				return;//wyj�cie, je�li warunek spe�niony
		}
		else
		{
			SetRotationHead(GetRotationHead() - m_rotation_speed * dt);
			if(GetRotationHead() >= (gWeather.getAngleSun() - CALIBRATION_FACTOR_ANGLE))
				return;//wyj�cie, je�li warunek spe�niony
		}
		//old code:
		//SetRotationHead(gWeather.getAngleSun()- CALIBRATION_FACTOR_ANGLE);
	}
}//namespace equipment