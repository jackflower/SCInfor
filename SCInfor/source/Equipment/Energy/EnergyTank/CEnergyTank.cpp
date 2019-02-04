//  ________________________________________
// | CEnergyTank.cpp - class implementation |
// | Jack Flower - December 2012.           |
// |________________________________________|
//

#include "CEnergyTank.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/CAnimSet.h"

using namespace rendering::animation;
using namespace rendering::drawable;

namespace equipment
{
	RTTI_IMPL(CEnergyTank, CActor)

	//Chroniony konstruktor domy�lny
	CEnergyTank::CEnergyTank(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),
		m_energy_tank_name				(),
		m_energy_tank_capacity			(0.0f),	
		m_energy						(0.0f),
		m_energy_tank_rotation_speed	(0.0f),
		m_energy_tank_rotor_speed		(0.0f),
		m_unit_controller				(true)//urz�dzenie w��czone
	{
		SetZIndexBody(Z_PHYSICAL_ENERGY_TANK_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_TANK_BODY);
		SetZIndexHead(Z_PHYSICAL_ENERGY_TANK_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_ENERGY_TANK_HEAD);
	}

	//Chroniony konstruktor kopiuj�cy
	CEnergyTank::CEnergyTank(const CEnergyTank& CEnergyTankCopy)
	:
		CActor							(CEnergyTankCopy),
		m_energy_tank_name				(CEnergyTankCopy.m_energy_tank_name),
		m_energy_tank_capacity			(CEnergyTankCopy.m_energy_tank_capacity),
		m_energy						(CEnergyTankCopy.m_energy),
		m_energy_tank_rotation_speed	(CEnergyTankCopy.m_energy_tank_rotation_speed),
		m_energy_tank_rotor_speed		(CEnergyTankCopy.m_energy_tank_rotor_speed),
		m_unit_controller				(CEnergyTankCopy.m_unit_controller)
	{
	}

	//Destruktor wirtualny
	CEnergyTank::~CEnergyTank(void)
	{
		//CActor						not edit
		m_energy_tank_name				= "";
		m_energy_tank_capacity			= 0.0f;
		m_energy						= 0.0f;
		m_energy_tank_rotation_speed	= 0.0f;
		m_energy_tank_rotor_speed		= 0.0f;
		//m_unit_controller				not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CEnergyTank::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazw� akumulatora energii
	const std::string CEnergyTank::GetEnergyTankName() const
	{
		return m_energy_tank_name;
	}

	//Metoda ustawia nazw� akumulatora energii
	void CEnergyTank::SetEnergyTankName(const std::string& energy_tank_name)
	{
		m_energy_tank_name = energy_tank_name;
	}

	//Metoda zwraca pojemno�� pojemno�� akumulatora energii
	const float CEnergyTank::GetEnergyTankCapacity() const
	{
		return m_energy_tank_capacity;
	}

	//Metoda ustawia pojemno�� akumulatora energii
	void CEnergyTank::SetEnergyTankCapacity(float energy_tank_capacity)
	{
		if (energy_tank_capacity < 0) return;
		m_energy_tank_capacity = energy_tank_capacity;
	}

	//Metoda zwraca ilo�� energii
	const float CEnergyTank::GetEnergy() const
	{
		return m_energy;
	}

	//Metoda ustawia ilo�� paliwa (tlenu) obiektu
	void CEnergyTank::SetEnergy(float energy)
	{
		if (energy < 0)								//je�li uzupe�niamy energi� warto�ci� ujemn� - opuszczamy funkcj�
		{
			m_energy = 0;							//zerujemy
			return;
		}

		if (m_energy_tank_capacity > 0)				//je�li akumulator energii ma pojemno��
		{
			if (energy >= m_energy_tank_capacity)	//je�li ilo�� energii, kt�r� chcemy uzupe�ni� akumulator
													//jest wi�ksza lub r�wna pojemno�ci akumulatoa energii
													//reszta (nadmiar) nie jest wykorzystany
				m_energy = m_energy_tank_capacity;	//ustawiamy ilo�� energii na pojemno�� akumulator energii
			else
				m_energy = energy;					//uzupe�niamy akumulator energii tak� ilo�ci� jak� zamierzamy zamierzamy (Parametr funkcji energy)
		}
		else										//akumulator energii nie ma pojemno��i
			m_energy = 0;							//nie mo�na uzupe�ni� energii.
	}


	//Metoda zwraca pr�dko�� wirowania wska�nika stanu akumulatora
	const float CEnergyTank::GetEnergyTankRotationSpeed() const
	{
		return m_energy_tank_rotation_speed;
	}

	//Metoda ustawia pr�dko�� wirowania wska�nika stanu akumulatora
	void CEnergyTank::SetEnergyTankRotationSpeed(float energy_tank_rotation_speed)
	{
		m_energy_tank_rotation_speed = energy_tank_rotation_speed;
	}

	//CEnergyTank metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
	void CEnergyTank::updateAnimations(float dt)
	{
		switch(m_energytank_state)
		{
		case ENERGYTANK_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyTankBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetEnergyTankHeadDefaultAnim());
			}
			break;
		}
		case ENERGYTANK_RESERVE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyTankBodyReserveAnim());
				SetAnimationHead(p_anim_set->GetEnergyTankHeadReserveAnim());
			}
			break;
		}
		case ENERGYTANK_EMPTY:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyTankBodyEmptyAnim());
				SetAnimationHead(p_anim_set->GetEnergyTankHeadEmptyAnim());
			}
			break;
		}
		case ENERGYTANK_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetEnergyTankBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetEnergyTankHeadDamageAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjc� na modu� sterowania
	CSwitch & CEnergyTank::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void CEnergyTank::Update(float dt)
	{
		UpdateShadow(dt);	//aktualizacja shadow engine

		if(m_unit_controller.getState())
		{
			//obliczamy procentow� pr�dko�� obrotu wirnika w zale�no�ci od ilo�ci energii w akumulatorze
			if(m_energy_tank_capacity)//je�li jest pojemno��
				m_energy_tank_rotor_speed = (m_energy/m_energy_tank_capacity) * m_energy_tank_rotation_speed;

			RotateHead(m_energy_tank_rotor_speed * dt);
			updateAnimations(dt);
		}
	}
}//namespace equipment
