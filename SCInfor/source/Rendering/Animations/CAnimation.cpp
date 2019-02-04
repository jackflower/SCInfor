//  _______________________________________
// | CAnimation.cpp - class implementation |
// | Jack Flower - March 2012              |
// |_______________________________________|
//

#include "CAnimation.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(CAnimation);

		//Konstruktor domy�lny
		CAnimation::CAnimation(void)
		:
			m_animation_name("")
		{
		}

		//Konstruktor kopiuj�cy
		CAnimation::CAnimation(const CAnimation& CAnimationCopy)
		:
			m_animation_name(CAnimationCopy.m_animation_name)
		{
		}

		//Destruktor
		CAnimation::~CAnimation(void)
		{
			m_animation_name = "";
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CAnimation::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca referencj� na nazw� animacji
		const std::string& CAnimation::GetAnimationName() const
		{ 
			return m_animation_name;
		}

		//Metoda ustawia na nazw� animacji
		const void CAnimation::SetAnimationName(std::string anim_name)
		{
			m_animation_name = anim_name;
		}

		//Metoda zwraca czas r�wny ca�kowitej d�ugo�ci trwania wszystkich klatek animacji (kumulacja)
		float CAnimation::TotalLength()
		{
			if (m_frames.empty())						//je�li nie ma klatek, to czas odtwarzania klatki animacji
				return 0.0f;							//jest r�wny zero
			else
				return m_frames.back().GetFrameTime();	//w przeciwnym wypadku jest to czas odtwarzania
														//(ostatniej) klatki animacji wektora - czyli czas
														//kumulacji poprzednich (suma trwania wszystckich klatek)
		}
	}//namespace animation
}//namespace rendering