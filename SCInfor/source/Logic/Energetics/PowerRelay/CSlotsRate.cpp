//  _______________________________________
// | CSlotsRate.cpp - class implementation |
// | Jack Flower - January 2016            |
// |_______________________________________|
//

#include "CSlotsRate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

namespace logic
{
	namespace energetics
	{
		RTTI_IMPL(CSlotsRate, CActor);

		//Chroniony konstruktor domyœlny
		CSlotsRate::CSlotsRate(const std::wstring& uniqueId)
		:
			CActor				(uniqueId),//konstruktor klasy bazowej
			m_slot_counter		(0)
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CSlotsRate::CSlotsRate(const CSlotsRate &CSlotsRateCopy)
		:
			CActor				(CSlotsRateCopy),//konstruktor kopiujacy klasy bazowej
			m_slot_counter		(CSlotsRateCopy.m_slot_counter)
		{
		}

		CSlotsRate::~CSlotsRate()
		{
			//CActor			not edit
			m_slot_counter		= 0;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CSlotsRate::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca iloœæ zajêtych slotów
		const int CSlotsRate::getSlotCounter() const
		{
			return m_slot_counter;
		}

		//Metoda ustawia iloœæ zajêtych slotów
		void CSlotsRate::setSlotCounter(const int slot_counter)
		{
			m_slot_counter = slot_counter;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
		void CSlotsRate::UpdateAnimations(float dt)
		{
			switch (m_slot_counter)
			{
			case 0:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetSlotsRateBody_0_Anim());
					SetAnimationHead(p_anim_set->GetSlotsRateHead_0_Anim());
				}
				break;
			}
			case 1:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetSlotsRateBody_1_Anim());
					SetAnimationHead(p_anim_set->GetSlotsRateHead_1_Anim());
				}
				break;
			}
			case 2:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetSlotsRateBody_2_Anim());
					SetAnimationHead(p_anim_set->GetSlotsRateHead_2_Anim());
				}
				break;
			}
			case 3:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetSlotsRateBody_3_Anim());
					SetAnimationHead(p_anim_set->GetSlotsRateHead_3_Anim());
				}
				break;
			}
			case 4:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetSlotsRateBody_4_Anim());
					SetAnimationHead(p_anim_set->GetSlotsRateHead_4_Anim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CSlotsRate::Update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			UpdateAnimations(dt);
		}
	}//namespace energetics
}//namespace logic
