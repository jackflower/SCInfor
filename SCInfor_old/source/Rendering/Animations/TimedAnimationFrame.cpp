//  ________________________________________________
// | TimedAnimationFrame.cpp - class implementation |
// | Jack Flower - March 2012                       |
// |________________________________________________|
//

#include "TimedAnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(TimedAnimationFrame);

		//Konstruktor domyślny
		TimedAnimationFrame::TimedAnimationFrame()
		:
			m_time(0.0f),
			m_frame()
		{
		}

		//Konstruktor kopiujący
		TimedAnimationFrame::TimedAnimationFrame(const TimedAnimationFrame & TimedAnimationFrameCopy)
		:
			m_time(TimedAnimationFrameCopy.m_time),
			m_frame(TimedAnimationFrameCopy.m_frame)
		{
		}

		//Konstruktor paramatryczny
		TimedAnimationFrame::TimedAnimationFrame(float time, const AnimationFrame & frame)
		:
			m_time(time),
			m_frame(frame)
		{
		}

		//Destruktor
		TimedAnimationFrame::~TimedAnimationFrame(void)
		{
			m_time = 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string TimedAnimationFrame::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca czas odtwarzania klatki animacji
		float TimedAnimationFrame::getFrameTime()
		{
			return m_time;
		}

		//Metoda zwraca referencję klatki animacji - referencja do obiektu klasy AnimationFrame
		AnimationFrame &TimedAnimationFrame::getAnimationFrame()
		{
			return m_frame;
		}
	}//namespace animation
}//namespace rendering
