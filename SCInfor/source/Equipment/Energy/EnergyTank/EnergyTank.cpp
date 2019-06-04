//  _______________________________________
// | EnergyTank.cpp - class implementation |
// | Jack Flower - December 2012           |
// |_______________________________________|
//

#include "EnergyTank.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/AnimSet.h"

using namespace rendering::animation;
using namespace rendering::drawable;

namespace equipment
{
	RTTI_IMPL(EnergyTank, Actor)

	//Chroniony konstruktor domyślny
	EnergyTank::EnergyTank(const std::wstring & uniqueId)
	:							
		Actor{ uniqueId },
		m_energy_tank_name{},
		m_energy_tank_capacity{ 0.0f },
		m_energy{ 0.0f },
		m_energy_tank_rotation_speed{ 0.0f },
		m_energy_tank_rotor_speed{ 0.0f },
		m_unit_controller{ true }//urządzenie włączone
	{
		setZIndexBody(Z_PHYSICAL_ENERGY_TANK_BODY);
		setZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_TANK_BODY);
		setZIndexHead(Z_PHYSICAL_ENERGY_TANK_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_SHADOW_ENERGY_TANK_HEAD);
	}

	//Chroniony konstruktor kopiujący
	EnergyTank::EnergyTank(const EnergyTank & EnergyTankCopy)
	:
		Actor(EnergyTankCopy),//kostruktor kopiujący klasy bazowej
		m_energy_tank_name{ EnergyTankCopy.m_energy_tank_name },
		m_energy_tank_capacity{ EnergyTankCopy.m_energy_tank_capacity },
		m_energy{ EnergyTankCopy.m_energy },
		m_energy_tank_rotation_speed{ EnergyTankCopy.m_energy_tank_rotation_speed },
		m_energy_tank_rotor_speed{ EnergyTankCopy.m_energy_tank_rotor_speed },
		m_unit_controller{ EnergyTankCopy.m_unit_controller }
	{
		setZIndexBody(Z_PHYSICAL_ENERGY_TANK_BODY);
		setZIndexShadowBody(Z_PHYSICAL_SHADOW_ENERGY_TANK_BODY);
		setZIndexHead(Z_PHYSICAL_ENERGY_TANK_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_SHADOW_ENERGY_TANK_HEAD);
	}

	//Destruktor wirtualny
	EnergyTank::~EnergyTank(void)
	{
		//~Actor()
		m_energy_tank_name = "";
		m_energy_tank_capacity = 0.0f;
		m_energy = 0.0f;
		m_energy_tank_rotation_speed = 0.0f;
		m_energy_tank_rotor_speed = 0.0f;
		m_unit_controller;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EnergyTank::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca nazwę akumulatora energii
	const std::string EnergyTank::getEnergyTankName() const
	{
		return m_energy_tank_name;
	}

	//Metoda ustawia nazwę akumulatora energii
	void EnergyTank::setEnergyTankName(const std::string & energy_tank_name)
	{
		m_energy_tank_name = energy_tank_name;
	}

	//Metoda zwraca pojemność pojemność akumulatora energii
	const float EnergyTank::getEnergyTankCapacity() const
	{
		return m_energy_tank_capacity;
	}

	//Metoda ustawia pojemność akumulatora energii
	void EnergyTank::setEnergyTankCapacity(float energy_tank_capacity)
	{
		if (energy_tank_capacity < 0) return;
		m_energy_tank_capacity = energy_tank_capacity;
	}

	//Metoda zwraca ilość energii
	const float EnergyTank::getEnergy() const
	{
		return m_energy;
	}

	//Metoda ustawia ilość paliwa (tlenu) obiektu
	void EnergyTank::setEnergy(float energy)
	{
		if (energy < 0) //jeśli uzupełniamy energię wartością ujemną - opuszczamy funkcję
		{
			m_energy = 0; //zerujemy
			return;
		}

		if (m_energy_tank_capacity > 0) //jeśli akumulator energii ma pojemność
		{
			//jeśli ilość energii, którą chcemy uzupełnić akumulator
			//jest większa lub równa pojemności akumulatoa energii
			//reszta(nadmiar) nie jest wykorzystany
			if (energy >= m_energy_tank_capacity)	
				//ustawiamy ilość energii na pojemność akumulator energii
				m_energy = m_energy_tank_capacity;	
			else
				//uzupełniamy akumulator energii taką ilością
				//jaką zamierzamy (Parametr funkcji energy)
				m_energy = energy;
		}
		else
			//akumulator energii nie ma pojemnośći
			//nie można uzupełnić energii.
			m_energy = 0;
	}


	//Metoda zwraca prędkość wirowania wskaźnika stanu akumulatora
	const float EnergyTank::getEnergyTankRotationSpeed() const
	{
		return m_energy_tank_rotation_speed;
	}

	//Metoda ustawia prędkość wirowania wskaźnika stanu akumulatora
	void EnergyTank::setEnergyTankRotationSpeed(float energy_tank_rotation_speed)
	{
		m_energy_tank_rotation_speed = energy_tank_rotation_speed;
	}

	//EnergyTank metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void EnergyTank::updateAnimations(float dt)
	{
		switch(m_energytank_state)
		{
		case EEnergyTankState::ENERGYTANK_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getEnergyTankBodyDefaultAnim());
				setAnimationHead(p_anim_set->getEnergyTankHeadDefaultAnim());
			}
			break;
		}
		case EEnergyTankState::ENERGYTANK_RESERVE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getEnergyTankBodyReserveAnim());
				setAnimationHead(p_anim_set->getEnergyTankHeadReserveAnim());
			}
			break;
		}
		case EEnergyTankState::ENERGYTANK_EMPTY:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getEnergyTankBodyEmptyAnim());
				setAnimationHead(p_anim_set->getEnergyTankHeadEmptyAnim());
			}
			break;
		}
		case EEnergyTankState::ENERGYTANK_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getEnergyTankBodyDamageAnim());
				setAnimationHead(p_anim_set->getEnergyTankHeadDamageAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & EnergyTank::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizująca obiekt
	void EnergyTank::update(float dt)
	{
		updateShadow(dt); //aktualizacja shadow engine

		if(m_unit_controller.getState())
		{
			//obliczamy procentową prędkość obrotu wirnika
			//w zależności od ilości energii w akumulatorze
			if(m_energy_tank_capacity)//jeśli jest pojemność
				m_energy_tank_rotor_speed = (m_energy/m_energy_tank_capacity) *
											 m_energy_tank_rotation_speed;

			rotateHead(m_energy_tank_rotor_speed * dt);
			updateAnimations(dt);
		}
	}
}//namespace equipment
