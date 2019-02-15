//  ______________________________________________
// | AnimatedAnimation.cpp - class implementation |
// | Jack Flower - March 2009                     |
// |______________________________________________|
//

#include "AnimatedAnimation.h"

namespace animated
{

	RTTI_IMPL_NOPARENT(AnimatedAnimation);

	//Konstruktor
	AnimatedAnimation::AnimatedAnimation()
	{
	}

	//Konstruktor kopiujący
	AnimatedAnimation::AnimatedAnimation(const AnimatedAnimation& copy)
		:
		m_frame(copy.m_frame)
	{
	}

	//Konstruktor parametryczny
	AnimatedAnimation::AnimatedAnimation(const rendering::displayable::Texture & texture, int width_frame, int height_frame)
	{
		setAnimationFramesFromAtlasTexture(texture, width_frame, height_frame);
	}

	//Konstruktor przenoszący
	AnimatedAnimation::AnimatedAnimation(AnimatedAnimation && other)
	:
		m_frame(other.m_frame)
	{
	}

	//Destruktor
	AnimatedAnimation::~AnimatedAnimation()
	{
		m_frame.clear();
	}

	//Przeciążony operator przypisania kopiowania
	AnimatedAnimation & AnimatedAnimation::operator=(const AnimatedAnimation & copy)
	{
		if (this != &copy)
			m_frame = copy.m_frame;
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	AnimatedAnimation & AnimatedAnimation::operator=(AnimatedAnimation && other)
	{
		if (this != &other)
		{
			m_frame = other.m_frame;

			//zerowanie obiektu źródłowego
			other.m_frame.clear();
		}
		return *this;
	}

	//Definicja operatora dla obiektu klasy AnimatedFrame
	AnimatedFrame & AnimatedAnimation::operator[] (unsigned N)
	{
		return m_frame[N];
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string AnimatedAnimation::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca ilość obieków klasy AnimatedFrame w wektorze
	unsigned int AnimatedAnimation::size() const
	{
		return m_frame.size();
	}

	//Metoda dodaje do wektora obiekty klasy AnimatedFrame
	bool AnimatedAnimation::setAnimationFramesFromAtlasTexture(const Texture & texture, int width_frame, int height_frame)
	{
		//Zakładamy, że szerokość i wysokość tekstury jest dodatnia
		if (width_frame <= 0 || height_frame <= 0)
			return false;//rozmiar musi być dodatni, a dzielnik nie może być równy zero...
		else
		{
			int width_i = texture.getSize().x / width_frame; //pobieramy szerokość tekstury
			int height_j = texture.getSize().y / height_frame; //pobieramy wysokość tekstury

			for (int j = 0 ; j < height_j; j++)
			{
				for (int i = 0 ; i  <width_i; i++)
				{
					pushFrame(AnimatedFrame(texture, sf::IntRect
								(	width_frame*i,
									height_frame*j,
									width_frame,
									height_frame
								)));
				}
			}
			return true;
		}
	}

	//Metoda dodaje do wektora obiekt klasy CAnimFrame
	void AnimatedAnimation::setSingleAnimationFrameTexture(const Texture & texture, const sf::IntRect & rectangle)
	{
		pushFrame(AnimatedFrame(texture, rectangle));
	}

	//Metoda usuwa z wektora obiekt klasy CAnimFrame o podanym indeksie
	void AnimatedAnimation::deleteAnimFrame(int index)
	{
		m_frame.erase(m_frame.begin() + index);
	}

	//Metoda usuwa z wektora wszystkie elementy
	void AnimatedAnimation::clearAllAnimFrame()
	{
		m_frame.clear();
	}

	//Metoda zwraca z wektora szerokość klatki animacji o podanym indeksie
	int const AnimatedAnimation::getAnimFrameWidth(int animframe_index)
	{
		return m_frame[animframe_index].getFrameRectangle().width;
	}

	//Metoda zwraca z wektora wysokość klatki animacji o podanym indeksie
	int const AnimatedAnimation::getAnimFrameHeight(int animframe_index)
	{
		return m_frame[animframe_index].getFrameRectangle().height;
	}

	//Metoda wstawia do wektora pojedynczy obiekt klasy AnimatedFrame
	void AnimatedAnimation::pushFrame(const AnimatedFrame & new_frame)
	{
		m_frame.push_back(new_frame);
	}
}//namespace animated
