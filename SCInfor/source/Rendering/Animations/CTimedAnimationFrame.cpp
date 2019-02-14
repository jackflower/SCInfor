//  _________________________________________________
// | CTimedAnimationFrame.cpp - class implementation |
// | Jack Flower - March 2012                        |
// |_________________________________________________|
//

#include "CTimedAnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(CTimedAnimationFrame);

		//Konstruktor domyœlny
		CTimedAnimationFrame::CTimedAnimationFrame(void)
		:
			m_time	(0.0f),
			m_frame	()
		{
		}

		//Konstruktor kopiuj¹cy
		CTimedAnimationFrame::CTimedAnimationFrame(const CTimedAnimationFrame& CTimedAnimationFrameCopy)
		:
			m_time	(CTimedAnimationFrameCopy.m_time),
			m_frame	(CTimedAnimationFrameCopy.m_frame)
		{
		}

		//Konstruktor paramatryczny
		CTimedAnimationFrame::CTimedAnimationFrame(float time, const AnimationFrame& frame)
		:
			m_time	(time),
			m_frame	(frame)
		{
		}

		//Destruktor
		CTimedAnimationFrame::~CTimedAnimationFrame(void)
		{
			m_time	= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CTimedAnimationFrame::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca czas odtwarzania klatki animacji
		float CTimedAnimationFrame::GetFrameTime()
		{
			return m_time;
		}

		//Metoda zwraca referencjê klatki animacji - referencja do obiektu klasy AnimationFrame
		AnimationFrame &CTimedAnimationFrame::GetAnimationFrame()
		{
			return m_frame;
		}
	}//namespace animation
}//namespace rendering
