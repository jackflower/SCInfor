//  ______________________________________________
// | LightingEquipment.cpp - class implementation |
// | Jack Flower - March 2015                     |
// |______________________________________________|
//

#include "LightingEquipment.h"
#include "../../Logic/PhysicalManager.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Animations/AnimSet.h"
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
		setZIndexBody(Z_PHYSICAL_LIGHTING_EQUIPMENT_BODY);
		setZIndexShadowBody(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_BODY);
		setZIndexHead(Z_PHYSICAL_LIGHTING_EQUIPMENT_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_HEAD);
	}

	//Chroniony konstruktor kopiujący
	LightingEquipment::LightingEquipment(const LightingEquipment & LightingEquipmentCopy)
	:
		Actor(LightingEquipmentCopy),//konstruktor kopiujący klasy bazowej
		m_unit_controller(LightingEquipmentCopy.m_unit_controller),//urządzenie włączone
		m_energy_consumption(LightingEquipmentCopy.m_energy_consumption),
		m_lighting_equipment_state(LightingEquipmentCopy.m_lighting_equipment_state)
	{
		setZIndexBody(Z_PHYSICAL_LIGHTING_EQUIPMENT_BODY);
		setZIndexShadowBody(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_BODY);
		setZIndexHead(Z_PHYSICAL_LIGHTING_EQUIPMENT_HEAD);
		setZIndexShadowHead(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_HEAD);
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
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
				setAnimationBody(p_anim_set->getLightingEquipmentBodyLightDafaultAnim());
				setAnimationHead(p_anim_set->getLightingEquipmentHeadLightDafaultAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_LIGHT_ON:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getLightingEquipmentBodyLightOnAnim());
				setAnimationHead(p_anim_set->getLightingEquipmentHeadLightOnAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_LIGHT_OFF:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getLightingEquipmentBodyLightOffAnim());
				setAnimationHead(p_anim_set->getLightingEquipmentHeadLightOffAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_DAMAGE:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getLightingEquipmentBodyLightDamageAnim());
				setAnimationHead(p_anim_set->getLightingEquipmentHeadLightDamageAnim());
			}
			break;
		}
		case LIGHTING_EQUIPMENT_DEATH:
		{
			if (p_anim_set)
			{
				setAnimationBody(p_anim_set->getLightingEquipmentBodyLightDeathAnim());
				setAnimationHead(p_anim_set->getLightingEquipmentHeadLightDeathAnim());
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
		Physical::updateShadow(dt);	//aktualizacja shadow engine

		//jeśli urządzenie jest włączone
		if(m_unit_controller.getState())
		{
			updateAnimations(dt);	//aktualizacja animacji (stany modułu oświetlenia)
		}
	}

	//implementacja metod private:

}//namespace equipment
