//  _______________________________________
// | CSolarCell.cpp - class implementation |
// | Jack Flower - July 2014               |
// |_______________________________________|
//

#include "CSolarCell.h"
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
	RTTI_IMPL(CSolarCell, CPowerModule);

	//Chroniony konstruktor domyœlny
	CSolarCell::CSolarCell(const std::wstring& uniqueId)
	:
		CPowerModule					(uniqueId),//konstruktor klasy bazowej
		m_solarcell_name				(),
		m_energy_duration				(0.0f),
		m_rotation_speed				(0.0f),
		m_solarcell_state				(SOLARCELL_DEFAULT),
		m_damage_duration				(0.0f),
		m_death_duration				(0.0f),
		m_calculated_energy_duration	(0.0f)
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CSolarCell::CSolarCell(const CSolarCell &CSolarCellCopy)
	:
		CPowerModule					(CSolarCellCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_solarcell_name				(CSolarCellCopy.m_solarcell_name),
		m_energy_duration				(CSolarCellCopy.m_energy_duration),
		m_rotation_speed				(CSolarCellCopy.m_rotation_speed),
		m_solarcell_state				(CSolarCellCopy.m_solarcell_state),
		m_damage_duration				(CSolarCellCopy.m_damage_duration),
		m_death_duration				(CSolarCellCopy.m_death_duration),
		m_calculated_energy_duration	(CSolarCellCopy.m_calculated_energy_duration)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CSolarCell::~CSolarCell(void)
	{
		//CPowerModule					not edit
		m_solarcell_name				= "";
		m_energy_duration				= 0.0f;
		m_rotation_speed				= 0.0f;
		m_solarcell_state				= SOLARCELL_DEFAULT;
		m_damage_duration				= 0.0f;
		m_death_duration				= 0.0f;
		m_calculated_energy_duration	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CSolarCell::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê fotoogniwa
	const std::string CSolarCell::GetSolarCellName() const
	{
		return m_solarcell_name;
	}

	//Metoda ustawia nazwê fotoogniwa
	void CSolarCell::SetSolarCellName(const std::string& solarcell_name)
	{
		m_solarcell_name = solarcell_name;
	}

	//Metoda zwraca czas, co jaki nastêpujê proces do³¹dowywania energii
	const float CSolarCell::getEnergyDuration() const
	{
		return m_energy_duration;
	}

	//Metoda ustawia czas, co jaki nastêpujê proces do³¹dowywania energii
	void CSolarCell::setEnergyDuration(float energy_duration)
	{
		m_energy_duration = energy_duration;
	}

	//Metoda zwraca prêdkoœæ obrotu
	const float CSolarCell::getRotationSpeed() const
	{
		return m_rotation_speed;
	}

	//Metoda ustawia prêdkoœæ obrotu
	void CSolarCell::setRotationSpeed(float rotation_speed)
	{
		m_rotation_speed = rotation_speed;
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
	void CSolarCell::updateAnimations(float dt)
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

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CSolarCell::Update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		//jeœli urz¹dzenie jest w³¹czone
		if(m_unit_controller.getState())
		{
			updateSolarCellState(dt);
			updateAnimations(dt);
		}
	}

	
	//implementacja metod private:


	//prywatna metoda aktualizuje stan obiektu
	void CSolarCell::updateSolarCellState(float dt)
	{
		//proces przebiega - fotoogniwo gromadzi energiê
		if(m_stored_energy < m_energy_capacitor)
		{
			if(gWeather.getTemperature() > 0)
				m_solarcell_state = SOLARCELL_UPDATE_ENERGY;	//aktywacja ³adowania fotoogniwa
			else
				m_solarcell_state = SOLARCELL_DEFAULT;			//default machine state

			if(m_solarcell_state == SOLARCELL_UPDATE_ENERGY)
			{
				//³adowanie fotoogniwa i aktualizacja obrotu wzglêdem Ÿród³a energii (solar)
				updateRotation(dt);
					
				//zliczam czas
				m_calculated_energy_duration += dt;
				if(m_calculated_energy_duration >= m_energy_duration)
				{
					//aktualizacja energii
					m_stored_energy += m_power * maths::Abs(gWeather.getSolarEnergyFactor());

					if(m_stored_energy > m_energy_capacitor)//kalibracja do wartoœci oczekiwanej
						m_stored_energy = m_energy_capacitor;

					m_calculated_energy_duration = 0.0f;//zerujê czas
					//std::cout << "temperature:    " << gWeather.getTemperature() << " stored_energy: " << m_current_stored_energy << std::endl;
				}
			}
		}
		else
			m_solarcell_state = SOLARCELL_DEFAULT;//default machine state
	}

	//prywatna metoda p³ynnie obracaj¹ca fotoogniwo w kierunku Ÿród³a energii
	void CSolarCell::updateRotation(float dt)
	{
		//2014-08-08
		//bardzo Ÿle napisany kod - zaj¹æ siê tym w innym czasie...
		//k¹t obrotu obiektu jest mniejszy od k¹ta Ÿród³a termicznego
		if(GetRotationHead() < (gWeather.getAngleSun() - CALIBRATION_FACTOR_ANGLE))
		{
			SetRotationHead(GetRotationHead() + m_rotation_speed * dt);
			if(GetRotationHead() <= (gWeather.getAngleSun()- CALIBRATION_FACTOR_ANGLE))
				return;//wyjœcie, jeœli warunek spe³niony
		}
		else
		{
			SetRotationHead(GetRotationHead() - m_rotation_speed * dt);
			if(GetRotationHead() >= (gWeather.getAngleSun() - CALIBRATION_FACTOR_ANGLE))
				return;//wyjœcie, jeœli warunek spe³niony
		}
		//old code:
		//SetRotationHead(gWeather.getAngleSun()- CALIBRATION_FACTOR_ANGLE);
	}
}//namespace equipment
