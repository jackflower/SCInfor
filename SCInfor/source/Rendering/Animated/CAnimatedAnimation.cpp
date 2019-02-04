//  _______________________________________________
// | CAnimatedAnimation.cpp - class implementation |
// | Jack Flower - March 2009                      |
// | update May 2017                               |
// |_______________________________________________|
//

#include "CAnimatedAnimation.h"

namespace animated
{
	//Konstruktor
	CAnimatedAnimation::CAnimatedAnimation(void)
	{
	}

	//Konstruktor parametryczny
	CAnimatedAnimation::CAnimatedAnimation(const sf::Texture& texture, int width_frame, int height_frame)
	{
		SetAnimationFramesFromAtlasTexture(texture, width_frame, height_frame);
	}

	//Konstruktor kopiuj¹cy
	CAnimatedAnimation::CAnimatedAnimation(const CAnimatedAnimation& copy)
	:
		m_frame(copy.m_frame)
	{
	}

	//Destruktor
	CAnimatedAnimation::~CAnimatedAnimation(void)
	{
		m_frame.clear();
	}

	//Metoda zwraca iloœæ obieków klasy CAnimFrame w wektorze
	unsigned int CAnimatedAnimation::Size() const
	{
	    return m_frame.size();
	}

	//Definicja operatora dla obiektu klasy CAnimFrame
	CAnimatedFrame & CAnimatedAnimation::operator [] (unsigned N)
	{
		return m_frame[N];
	}

	//Metoda dodaje do wektora obiekty klasy CAnimFrame
	bool CAnimatedAnimation::SetAnimationFramesFromAtlasTexture(const sf::Texture & texture, int width_frame, int height_frame)
	{
		//Zak³adamy, ¿e szerokoœæ i wysokoœæ tekstury jest dodatnia
		if (width_frame <= 0 || height_frame <= 0)
			return false;//rozmiar musi byæ dodatni, a dzielnik nie mo¿e byæ równy zero...
		else
		{
			int width_i = texture.getSize().x / width_frame;	//pobieramy szerokoœæ tekstury
			int height_j = texture.getSize().y / height_frame;	//pobieramy wysokoœæ tekstury

			for (int j = 0 ; j < height_j; j++)
			{
				for (int i = 0 ; i  <width_i; i++)
				{
					pushFrame(CAnimatedFrame(texture, sf::IntRect
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
	void CAnimatedAnimation::SetSingleAnimationFrameTexture(const sf::Texture & texture, const sf::IntRect & rectangle)
	{
		pushFrame(CAnimatedFrame(texture, rectangle));
	}

	//Metoda usuwa z wektora obiekt klasy CAnimFrame o podanym indeksie
	void CAnimatedAnimation::DeleteAnimFrame(int index)
	{
		m_frame.erase(m_frame.begin() + index);
	}

	//Metoda usuwa z wektora wszystkie elementy
	void CAnimatedAnimation::ClearAllAnimFrame()
	{
		m_frame.clear();
	}

	//Metoda zwraca z wektora szerokoœæ klatki animacji o podanym indeksie
	int const CAnimatedAnimation::GetAnimFrameWidth(int animframe_index)
	{
		return m_frame[animframe_index].GetFrameRectangle().width;
	}

	//Metoda zwraca z wektora wysokoœæ klatki animacji o podanym indeksie
	int const CAnimatedAnimation::GetAnimFrameHeight(int animframe_index)
	{
		return m_frame[animframe_index].GetFrameRectangle().height;
	}

	//Metoda wstawia do wektora pojedynczy obiekt klasy CAnimatedFrame
	void CAnimatedAnimation::pushFrame(const CAnimatedFrame & new_frame)
	{
		m_frame.push_back(new_frame);
	}
}//namespace animated
