//  ______________________________________
// | SlotsRate.cpp - class implementation |
// | Jack Flower - January 2016           |
// |______________________________________|
//

#include "SlotsRate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/AnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

namespace logic
{
	namespace energetics
	{
		RTTI_IMPL(SlotsRate, Actor);

		//Chroniony konstruktor domyślny
		SlotsRate::SlotsRate(const std::wstring & uniqueId)
		:
			Actor(uniqueId),//konstruktor klasy bazowej
			m_slot_counter(0)
		{
			//to do: layers
		}

		//Chroniony konstruktor kopiujący
		SlotsRate::SlotsRate(const SlotsRate & SlotsRateCopy)
		:
			Actor(SlotsRateCopy),//konstruktor kopiujacy klasy bazowej
			m_slot_counter(SlotsRateCopy.m_slot_counter)
		{
			//to do: layers
		}

		SlotsRate::~SlotsRate()
		{
			//~Actor()
			m_slot_counter = 0;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string SlotsRate::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca ilość zajętych slotów
		const int SlotsRate::getSlotCounter() const
		{
			return m_slot_counter;
		}

		//Metoda ustawia ilość zajętych slotów
		void SlotsRate::setSlotCounter(const int slot_counter)
		{
			m_slot_counter = slot_counter;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		void SlotsRate::updateAnimations(float dt)
		{
			switch (m_slot_counter)
			{
			case 0:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetSlotsRateBody_0_Anim());
					setAnimationHead(p_anim_set->GetSlotsRateHead_0_Anim());
				}
				break;
			}
			case 1:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetSlotsRateBody_1_Anim());
					setAnimationHead(p_anim_set->GetSlotsRateHead_1_Anim());
				}
				break;
			}
			case 2:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetSlotsRateBody_2_Anim());
					setAnimationHead(p_anim_set->GetSlotsRateHead_2_Anim());
				}
				break;
			}
			case 3:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetSlotsRateBody_3_Anim());
					setAnimationHead(p_anim_set->GetSlotsRateHead_3_Anim());
				}
				break;
			}
			case 4:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetSlotsRateBody_4_Anim());
					setAnimationHead(p_anim_set->GetSlotsRateHead_4_Anim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizująca obiekt
		void SlotsRate::update(float dt)
		{
			//aktualizacja shadow engine
			Physical::updateShadow(dt);

			updateAnimations(dt);
		}
	}//namespace energetics
}//namespace logic
