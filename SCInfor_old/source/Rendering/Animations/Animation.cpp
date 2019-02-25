//  ______________________________________
// | Animation.cpp - class implementation |
// | Jack Flower - March 2012             |
// |______________________________________|
//

#include "Animation.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(Animation);

		//Konstruktor domyślny
		Animation::Animation()
		:
			m_animation_name("")
		{
		}

		//Konstruktor kopiujący
		Animation::Animation(const Animation & AnimationCopy)
		:
			m_animation_name(AnimationCopy.m_animation_name)
		{
		}

		//Konstruktor przenoszący
		Animation::Animation(Animation && other)
		:
			m_animation_name(""),
			m_frames()
		{
			// kopiujemy dane z obiektu źródłowego
			m_animation_name = other.m_animation_name;
			m_frames = other.m_frames;
			//zwalniamy obiekt źródłowy
			other.m_animation_name = "";
			other.m_frames.clear();
		}

		//Przeciążony operator przypisania kopiowania
		Animation & Animation::operator=(const Animation & copy)
		{
			if (this != & copy)
			{
				//zwalniamy dane pod wskaźnikiem
				//	delete p_pointer;
				//tworzymy nowy obiekt
				//	p_texture = new Object();

				//kopiujemy dane z obiektu źródłowego
				m_animation_name = copy.m_animation_name;
				m_frames = copy.m_frames;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Animation & Animation::operator=(Animation && other)
		{
			if (this != & other)
			{
				//zwalniamy dane pod wskaźnikiem
				//delete p_pointer;
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				//p_pointer = other.p_pointer;

				//kopiujemy dane z obiektu źródłowego
				m_animation_name = other.m_animation_name;
				m_frames = other.m_frames;
				
				//zwalniamy wskaźnik na dane obiektu źródłowego tak,
				//aby destruktor nie zwalniał pamięci wielokrotnie
				//zerowanie obiektu źródłowego
				//other.p_pointer = nullptr;

				other.m_animation_name = "";
				other.m_frames.clear();
			}
			return *this;
		}

		//Destruktor
		Animation::~Animation()
		{
			//m_frames
			m_animation_name = "";
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Animation::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca referencję na nazwę animacji
		const std::string & Animation::getAnimationName() const
		{ 
			return m_animation_name;
		}

		//Metoda ustawia na nazwę animacji
		const void Animation::setAnimationName(const std::string & anim_name)
		{
			m_animation_name = anim_name;
		}

		//Metoda zwraca czas równy całkowitej długości trwania wszystkich klatek animacji (kumulacja)
		float Animation::totalLength()
		{
			if (m_frames.empty()) //jeśli nie ma klatek, to czas odtwarzania klatki animacji
				return 0.0f; //jest równy zero
			else
				return m_frames.back().getFrameTime();
				//w przeciwnym wypadku jest to czas odtwarzania
				//(ostatniej) klatki animacji wektora - czyli czas
				//kumulacji poprzednich (suma trwania wszystkich klatek)
		}
	}//namespace animation
}//namespace rendering
