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

	//Chroniony konstruktor domyœlny
	CEnergyTank::CEnergyTank(const std::wstring& uniqueId)
	:
		CActor							(uniqueId),
		m_energy_tank_name				(),
		m_energy_tank_capacity			(0.0f),	
		m_energy						(0.0f),
		m_energy_tank_rotation_speed	(0.0f),
		m_energy_tank_rotor_speed		(0.0f),
		m_unit_controller				(true)//urz¹dzenie w³¹czone
	{
		SetZIndexBody(Z_PHYSICAL_ENERGY_TANK_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_TANK_BODY);
		SetZIndexHead(Z_PHYSICAL_ENERGY_TANK_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_ENERGY_TANK_HEAD);
	}

	//Chroniony konstruktor kopiuj¹cy
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

	//Metoda zwraca nazwê akumulatora energii
	const std::string CEnergyTank::GetEnergyTankName() const
	{
		return m_energy_tank_name;
	}

	//Metoda ustawia nazwê akumulatora energii
	void CEnergyTank::SetEnergyTankName(const std::string& energy_tank_name)
	{
		m_energy_tank_name = energy_tank_name;
	}

	//Metoda zwraca pojemnoœæ pojemnoœæ akumulatora energii
	const float CEnergyTank::GetEnergyTankCapacity() const
	{
		return m_energy_tank_capacity;
	}

	//Metoda ustawia pojemnoœæ akumulatora energii
	void CEnergyTank::SetEnergyTankCapacity(float energy_tank_capacity)
	{
		if (energy_tank_capacity < 0) return;
		m_energy_tank_capacity = energy_tank_capacity;
	}

	//Metoda zwraca iloœæ energii
	const float CEnergyTank::GetEnergy() const
	{
		return m_energy;
	}

	//Metoda ustawia iloœæ paliwa (tlenu) obiektu
	void CEnergyTank::SetEnergy(float energy)
	{
		if (energy < 0)								//jeœli uzupe³niamy energiê wartoœci¹ ujemn¹ - opuszczamy funkcjê
		{
			m_energy = 0;							//zerujemy
			return;
		}

		if (m_energy_tank_capacity > 0)				//jeœli akumulator energii ma pojemnoœæ
		{
			if (energy >= m_energy_tank_capacity)	//jeœli iloœæ energii, któr¹ chcemy uzupe³niæ akumulator
													//jest wiêksza lub równa pojemnoœci akumulatoa energii
													//reszta (nadmiar) nie jest wykorzystany
				m_energy = m_energy_tank_capacity;	//ustawiamy iloœæ energii na pojemnoœæ akumulator energii
			else
				m_energy = energy;					//uzupe³niamy akumulator energii tak¹ iloœci¹ jak¹ zamierzamy zamierzamy (Parametr funkcji energy)
		}
		else										//akumulator energii nie ma pojemnoœæi
			m_energy = 0;							//nie mo¿na uzupe³niæ energii.
	}


	//Metoda zwraca prêdkoœæ wirowania wskaŸnika stanu akumulatora
	const float CEnergyTank::GetEnergyTankRotationSpeed() const
	{
		return m_energy_tank_rotation_speed;
	}

	//Metoda ustawia prêdkoœæ wirowania wskaŸnika stanu akumulatora
	void CEnergyTank::SetEnergyTankRotationSpeed(float energy_tank_rotation_speed)
	{
		m_energy_tank_rotation_speed = energy_tank_rotation_speed;
	}

	//CEnergyTank metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
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

	//Metoda zwraca referencjcê na modu³ sterowania
	CSwitch & CEnergyTank::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CEnergyTank::Update(float dt)
	{
		UpdateShadow(dt);	//aktualizacja shadow engine

		if(m_unit_controller.getState())
		{
			//obliczamy procentow¹ prêdkoœæ obrotu wirnika w zale¿noœci od iloœci energii w akumulatorze
			if(m_energy_tank_capacity)//jeœli jest pojemnoœæ
				m_energy_tank_rotor_speed = (m_energy/m_energy_tank_capacity) * m_energy_tank_rotation_speed;

			RotateHead(m_energy_tank_rotor_speed * dt);
			updateAnimations(dt);
		}
	}
}//namespace equipment
