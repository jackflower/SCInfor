//  ______________________________________________
// | LightingEquipment.cpp - class implementation |
// | Jack Flower - March 2015                     |
// |______________________________________________|
//

#include "LightingEquipment.h"
#include "../../Logic/CPhysicalManager.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Displayable/CDisplayable.h"

using namespace rendering::drawable;
using namespace rendering::animation;
using namespace rendering::displayable;

namespace equipment
{
	RTTI_IMPL(LightingEquipment, Actor)

	//Chroniony konstruktor domyślny
	LightingEquipment::LightingEquipment(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_unit_controller(true),//urządzenie włączone
		m_energy_consumption(0.0f),
		m_lighting_equipment_state(LIGHTING_EQUIPMENT_DEFAULT)
	{
		SetZIndexBody(Z_PHYSICAL_LIGHTING_EQUIPMENT_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_BODY);
		SetZIndexHead(Z_PHYSICAL_LIGHTING_EQUIPMENT_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_HEAD);
	}

	//Chroniony konstruktor kopiujący
	LightingEquipment::LightingEquipment(const LightingEquipment & LightingEquipmentCopy)
	:
		Actor(LightingEquipmentCopy),//konstruktor kopiujący klasy bazowej
		m_unit_controller(LightingEquipmentCopy.m_unit_controller),//urządzenie włączone
		m_energy_consumption(LightingEquipmentCopy.m_energy_consumption),
		m_lighting_equipment_state(LightingEquipmentCopy.m_lighting_equipment_state)
	{
		SetZIndexBody(Z_PHYSICAL_LIGHTING_EQUIPMENT_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_BODY);
		SetZIndexHead(Z_PHYSICAL_LIGHTING_EQUIPMENT_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_HEAD);
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
	LightingEquipment::~LightingEquipment(void)
	{
		//Actor
		//m_unit_controller
		m_energy_consumption = 0.0f;
		m_lighting_equipment_state = LIGHTING_EQUIPMENT_DEFAULT;

	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string LightingEquipment::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazwę układu oświetlenia
	const std::string LightingEquipment::getLightingEquipmentName() const
	{
		return m_lighting_equipment_name;
	}

	//Metoda ustawia nazwę układu oświetlenia
	void LightingEquipment::setLightingEquipmentName(const std::string & lighting_equipment_name)
	{
		m_lighting_equipment_name = lighting_equipment_name;
	}

	//Metoda zwraca zużycie energii urządzenia
	const float LightingEquipment::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zużycie energii urządzenia
	void LightingEquipment::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (light on/off, run, etc...)
	void LightingEquipment::updateAnimations(float dt)
	{
		switch(m_lighting_equipment_state)
		{
		case LIGHTING_EQUIPMENT_DEFAULT:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetLightingEquipmentBodyLightDafaultAnim());
				SetAnimationHead(p_anim_set->GetLightingEquipmentHeadLightDafaultAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_LIGHT_ON:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetLightingEquipmentBodyLightOnAnim());
				SetAnimationHead(p_anim_set->GetLightingEquipmentHeadLightOnAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_LIGHT_OFF:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetLightingEquipmentBodyLightOffAnim());
				SetAnimationHead(p_anim_set->GetLightingEquipmentHeadLightOffAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_DAMAGE:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetLightingEquipmentBodyLightDamageAnim());
				SetAnimationHead(p_anim_set->GetLightingEquipmentHeadLightDamageAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_DEATH:
		{
			if (p_anim_set)
			{
				SetAnimationBody(p_anim_set->GetLightingEquipmentBodyLightDeathAnim());
				SetAnimationHead(p_anim_set->GetLightingEquipmentHeadLightDeathAnim());
			}
			break;
		}
		default:
			break;
		}
	}

	//Metoda zwraca referencjcę na moduł sterowania
	Switch & LightingEquipment::getUnitController()
	{
		return m_unit_controller;
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void LightingEquipment::update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		//jeśli urządzenie jest włączone
		if(m_unit_controller.getState())
		{
			updateAnimations(dt);	//aktualizacja animacji (stany modułu oświetlenia)
		}
	}

	//implementacja metod private:

}//namespace equipment
