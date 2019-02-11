//  _____________________________________
// | FuelTank.cpp - class implementation |
// | Jack Flower - December 2012         |
// |_____________________________________|
//

#include "FuelTank.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/CAnimSet.h"

using namespace rendering::animation;
using namespace rendering::drawable;

namespace equipment
{
	RTTI_IMPL(FuelTank, Actor)

	//Chroniony konstruktor domyślny
	FuelTank::FuelTank(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_fuel_tank_name(),
		m_fuel_tank_capacity(0.0f),
		m_fuel(0.0f),
		m_fueltank_state(EFuelTankState::FUELTANK_DEFAULT),
		m_unit_controller(true)//urządzenie włączone
	{
		setZIndexBody(Z_PHYSICAL_FUEL_TANK_BODY);
		setZIndexShadowBody(Z_PHYSICAL_SHADOW_FUEL_TANK_BODY);
		setZIndexHead(Z_PHYSICAL_FUEL_TANK_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_SHADOW_FUEL_TANK_HEAD);
	}

	//Chroniony konstruktor kopiujący
	FuelTank::FuelTank(const FuelTank & FuelTankCopy)
	:
		Actor(FuelTankCopy),//konstruktor kopiujący klasy bazowej
		m_fuel_tank_name(FuelTankCopy.m_fuel_tank_name),
		m_fuel_tank_capacity(FuelTankCopy.m_fuel_tank_capacity),
		m_fuel(FuelTankCopy.m_fuel),
		m_fueltank_state(FuelTankCopy.m_fueltank_state),
		m_unit_controller(FuelTankCopy.m_unit_controller)
	{
		setZIndexBody(Z_PHYSICAL_FUEL_TANK_BODY);
		setZIndexShadowBody(Z_PHYSICAL_SHADOW_FUEL_TANK_BODY);
		setZIndexHead(Z_PHYSICAL_FUEL_TANK_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_SHADOW_FUEL_TANK_HEAD);
	}

	//Destruktor wirtualny
	FuelTank::~FuelTank(void)
	{
		//Actor
		m_fuel_tank_name = "";
		m_fuel_tank_capacity = 0.0f;
		m_fuel = 0.0f;
		m_fueltank_state = EFuelTankState::FUELTANK_DEFAULT;
		//m_unit_controller
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FuelTank::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę zbiornika
	const std::string FuelTank::getFuelTankName() const
	{
		return m_fuel_tank_name;
	}

	//Metoda ustawia nazwę zbiornika
	void FuelTank::setFuelTankName(const std::string& fuel_tank_name)
	{
		m_fuel_tank_name = fuel_tank_name;
	}

	//Metoda zwraca pojemność zbiornika
	const float FuelTank::getFuelTankCapacity() const
	{
		return m_fuel_tank_capacity;
	}

	//Metoda ustawia pojemność zbiornika paliwa (tlenu)
	void FuelTank::setFuelTankCapacity(float fuel_tank_capacity)
	{
		if (fuel_tank_capacity < 0) return;
		m_fuel_tank_capacity = fuel_tank_capacity;
	}

	//Metoda zwraca ilość paliwa (tlenu) obiektu
	const float FuelTank::getFuel() const
	{
		return m_fuel;
	}

	//Metoda ustawia ilość paliwa (tlenu) obiektu
	void FuelTank::setFuel(float fuel)
	{
		if (fuel < 0) //jeśli tankujemy wartością ujemną - opuszczamy funkcję
		{
			m_fuel = 0; //zerujemy
			return;
		}

		if (m_fuel_tank_capacity > 0)			//jeśli zbiornik ma pojemność
		{
			if (fuel >= m_fuel_tank_capacity)	//jeśli ilość paliwa, którą chcemy zatankować
												//jest większa lub równa pojemności zbiornika
												//reszta (nadmiar) nie jest wykorzystany
				m_fuel = m_fuel_tank_capacity;	//ustawiamy ilość paliwa na pojemność zbiornika
			else
				m_fuel = fuel;					//tankujemy tyle ile zamierzamy (Parametr funkcji fuel)
		}
		else									//zbiornik nie ma pojemnośći
			m_fuel = 0;							//nie można tankować.
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
	void FuelTank::updateAnimations(float dt)
	{
		switch (m_fueltank_state)
		{
		case EFuelTankState::FUELTANK_DEFAULT:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetFuelBodyDefaultAnim());
				setAnimationHead(p_anim_set->GetFuelHeadDefaultAnim());
			}
			break;
		}
		case EFuelTankState::FUELTANK_RESERVE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetFuelBodyReserveAnim());
				setAnimationHead(p_anim_set->GetFuelHeadReserveAnim());
			}
			break;
		}
		case EFuelTankState::FUELTANK_EMPTY:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetFuelBodyEmptyAnim());
				setAnimationHead(p_anim_set->GetFuelHeadEmptyAnim());
			}
			break;
		}
		case EFuelTankState::FUELTANK_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->GetFuelBodyDamageAnim());
				setAnimationHead(p_anim_set->GetFuelHeadDamageAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & FuelTank::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizująca obiekt
	void FuelTank::update(float dt)
	{
		updateShadow(dt);	//aktualizacja shadow engine

		if (m_unit_controller.getState())
			updateAnimations(dt);
	}
}//namespace equipment
