//  ______________________________________
// | CFuelTank.cpp - class implementation |
// | Jack Flower - December 2012          |
// |______________________________________|
//

#include "CFuelTank.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/CAnimSet.h"

using namespace rendering::animation;
using namespace rendering::drawable;

namespace equipment
{
	RTTI_IMPL(CFuelTank, CActor)

	//Chroniony konstruktor domyœlny
	CFuelTank::CFuelTank(const std::wstring& uniqueId)
	:
		CActor					(uniqueId),//konstruktor klasy bazowej
		m_fuel_tank_name		(),
		m_fuel_tank_capacity	(0.0f),
		m_fuel					(0.0f),
		m_fueltank_state		(EFuelTankState::FUELTANK_DEFAULT),
		m_unit_controller		(true)//urz¹dzenie w³¹czone
	{
		SetZIndexBody(Z_PHYSICAL_FUEL_TANK_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_FUEL_TANK_BODY);
		SetZIndexHead(Z_PHYSICAL_FUEL_TANK_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_FUEL_TANK_HEAD);
	}

	//Chroniony konstruktor kopiuj¹cy
	CFuelTank::CFuelTank(const CFuelTank& CFuelTankCopy)
	:
		CActor					(CFuelTankCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_fuel_tank_name		(CFuelTankCopy.m_fuel_tank_name),
		m_fuel_tank_capacity	(CFuelTankCopy.m_fuel_tank_capacity),
		m_fuel					(CFuelTankCopy.m_fuel),
		m_fueltank_state		(CFuelTankCopy.m_fueltank_state),
		m_unit_controller		(CFuelTankCopy.m_unit_controller)
	{
	}

	//Destruktor wirtualny
	CFuelTank::~CFuelTank(void)
	{
		//CActor				not edit
		m_fuel_tank_name		= "";
		m_fuel_tank_capacity	= 0.0f;
		m_fuel					= 0.0f;
		m_fueltank_state		= EFuelTankState::FUELTANK_DEFAULT;
		//m_unit_controller		not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CFuelTank::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwê zbiornika
	const std::string CFuelTank::GetFuelTankName() const
	{
		return m_fuel_tank_name;
	}

	//Metoda ustawia nazwê zbiornika
	void CFuelTank::SetFuelTankName(const std::string& fuel_tank_name)
	{
		m_fuel_tank_name = fuel_tank_name;
	}

	//Metoda zwraca pojemnoœæ zbiornika
	const float CFuelTank::GetFuelTankCapacity() const
	{
		return m_fuel_tank_capacity;
	}

	//Metoda ustawia pojemnoœæ zbiornika paliwa (tlenu)
	void CFuelTank::SetFuelTankCapacity(float fuel_tank_capacity)
	{
		if (fuel_tank_capacity < 0) return;
		m_fuel_tank_capacity = fuel_tank_capacity;
	}

	//Metoda zwraca iloœæ paliwa (tlenu) obiektu
	const float CFuelTank::GetFuel() const
	{
		return m_fuel;
	}

	//Metoda ustawia iloœæ paliwa (tlenu) obiektu
	void CFuelTank::SetFuel(float fuel)
	{
		if (fuel < 0)						//jeœli tankujemy wartoœci¹ ujemn¹ - opuszczamy funkcjê
		{
			m_fuel = 0;						//zerujemy
			return;
		}

		if (m_fuel_tank_capacity > 0)			//jeœli zbiornik ma pojemnoœæ
		{
			if (fuel >= m_fuel_tank_capacity)	//jeœli iloœæ paliwa, któr¹ chcemy zatankowaæ
												//jest wiêksza lub równa pojemnoœci zbiornika
												//reszta (nadmiar) nie jest wykorzystany
				m_fuel = m_fuel_tank_capacity;	//ustawiamy iloœæ paliwa na pojemnoœæ zbiornika
			else
				m_fuel = fuel;					//tankujemy tyle ile zamierzamy (Parametr funkcji fuel)
		}
		else									//zbiornik nie ma pojemnoœæi
			m_fuel = 0;							//nie mo¿na tankowaæ.
	}

	//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
	void CFuelTank::updateAnimations(float dt)
	{
		switch (m_fueltank_state)
		{
		case EFuelTankState::FUELTANK_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetFuelBodyDefaultAnim());
				SetAnimationHead(p_anim_set->GetFuelHeadDefaultAnim());
			}
			break;
		}
		case EFuelTankState::FUELTANK_RESERVE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetFuelBodyReserveAnim());
				SetAnimationHead(p_anim_set->GetFuelHeadReserveAnim());
			}
			break;
		}
		case EFuelTankState::FUELTANK_EMPTY:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetFuelBodyEmptyAnim());
				SetAnimationHead(p_anim_set->GetFuelHeadEmptyAnim());
			}
			break;
		}
		case EFuelTankState::FUELTANK_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetFuelBodyDamageAnim());
				SetAnimationHead(p_anim_set->GetFuelHeadDamageAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjcê na modu³ sterowania
	Switch & CFuelTank::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CFuelTank::update(float dt)
	{
		UpdateShadow(dt);	//aktualizacja shadow engine

		if (m_unit_controller.getState())
			updateAnimations(dt);
	}
}//namespace equipment
