//  _______________________________________________
// | CLightingEquipment.cpp - class implementation |
// | Jack Flower - March 2015                      |
// |_______________________________________________|
//

#include "CLightingEquipment.h"
#include "../../Logic/CPhysicalManager.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Displayable/CDisplayable.h"

using namespace rendering::drawable;
using namespace rendering::animation;
using namespace rendering::displayable;

namespace equipment
{
	RTTI_IMPL(CLightingEquipment, CActor)

	//Chroniony konstruktor domy�lny
	CLightingEquipment::CLightingEquipment(const std::wstring& uniqueId)
	:
		CActor						(uniqueId),//konstruktor klasy bazowej
		m_unit_controller			(true),//urz�dzenie w��czone
		m_energy_consumption		(0.0f),
		m_lighting_equipment_state	(LIGHTING_EQUIPMENT_DEFAULT)
	{
		SetZIndexBody(Z_PHYSICAL_LIGHTING_EQUIPMENT_BODY);
		SetZIndexShadowBody(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_BODY);
		SetZIndexHead(Z_PHYSICAL_LIGHTING_EQUIPMENT_HEAD);
		SetZIndexShadowHead(Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_HEAD);
	}

	//Chroniony konstruktor kopiuj�cy
	CLightingEquipment::CLightingEquipment(const CLightingEquipment& CLightingEquipmentCopy)
	:
		CActor						(CLightingEquipmentCopy),//konstruktor kopiuj�cy klasy bazowej
		m_unit_controller			(CLightingEquipmentCopy.m_unit_controller),//urz�dzenie w��czone
		m_energy_consumption		(CLightingEquipmentCopy.m_energy_consumption),
		m_lighting_equipment_state	(CLightingEquipmentCopy.m_lighting_equipment_state)
	{
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
	CLightingEquipment::~CLightingEquipment(void)
	{
		//CActor					not edit
		//m_unit_controller			not edit
		m_energy_consumption		= 0.0f;
		m_lighting_equipment_state	= LIGHTING_EQUIPMENT_DEFAULT;

	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CLightingEquipment::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca nazw� uk�adu o�wietlenia
	const std::string CLightingEquipment::GetLightingEquipmentName() const
	{
		return m_lighting_equipment_name;
	}

	//Metoda ustawia nazw� uk�adu o�wietlenia
	void CLightingEquipment::SetLightingEquipmentName(const std::string & lighting_equipment_name)
	{
		m_lighting_equipment_name = lighting_equipment_name;
	}

	//Metoda zwraca zu�ycie energii urz�dzenia
	const float CLightingEquipment::getEnergyConsumption() const
	{
		return m_energy_consumption;
	}

	//Metoda ustawia zu�ycie energii urz�dzenia
	void CLightingEquipment::setEnergyConsumption(float energy_consumption)
	{
		m_energy_consumption = energy_consumption;
	}

	//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (light on/off, run, etc...)
	void CLightingEquipment::updateAnimations(float dt)
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


	//Wirtualna metoda aktualizuje logik� obiektu
	void CLightingEquipment::update(float dt)
	{
		CPhysical::UpdateShadow(dt);	//aktualizacja shadow engine

		//je�li urz�dzenie jest w��czone
		if(m_unit_controller.getState())
		{
			updateAnimations(dt);	//aktualizacja animacji (stany energy)
		}
	}

	//implementacja metod private:


}//namespace equipment