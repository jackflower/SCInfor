////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "AnimationFrame.h"

namespace acodemia
{
	namespace animation
	{
		//Konstruktor
		AnimationFrame::AnimationFrame()
		:
			p_texture(nullptr),
			m_rectangle()
		{
		}

		//Konstruktor kopiujący
		AnimationFrame::AnimationFrame(const AnimationFrame & copy)
		:
			p_texture(copy.p_texture),
			m_rectangle(copy.m_rectangle)
		{
		}

		//Konstruktor przenoszący
		AnimationFrame::AnimationFrame(AnimationFrame && other)
		:
			p_texture(nullptr)
		{
			//kopiujemy pod wskaźnik dane obiektu źródłowego
			p_texture = other.p_texture;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_texture = nullptr;
		}

		//Konstruktor parametryczny
		AnimationFrame::AnimationFrame(const acodemia::rendering::Texture & texture, const sf::IntRect & rectangle)
		:
			p_texture(& texture),
			m_rectangle(rectangle)
		{
		}

		//Konstruktor parametryczny
		AnimationFrame::AnimationFrame(const acodemia::rendering::Texture & texture)
		:
			p_texture(& texture)
		{
			if (p_texture != nullptr)
				m_rectangle = sf::IntRect(0, 0, p_texture->getSize().x, p_texture->getSize().y);
		}

		//Destruktor
		AnimationFrame::~AnimationFrame()
		{
			p_texture = nullptr;
		}

		//Przeciążony operator przypisania kopiowania
		AnimationFrame & AnimationFrame::operator=(const AnimationFrame & copy)
		{
			if (this != &copy)
			{
				//zwalaniamy dane pod wskaźnikiem
				delete p_texture;
				//tworzymy nowy obiekt na podstawie obiektu źródłowego
				p_texture = new acodemia::rendering::Texture(*copy.p_texture);
				m_rectangle = copy.m_rectangle;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		AnimationFrame & AnimationFrame::operator=(AnimationFrame && other)
		{
			if (this != & other)
			{
				//zwalaniamy dane pod wskaźnikiem
				//...delete p_texture; //rzuca wyjatkiem...
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				p_texture = other.p_texture;
				m_rectangle = other.m_rectangle;
				//zwalniamy wskaźnik na dane obiektu źródłowego tak,
				//aby destruktor nie zwalniał pamięci wielokrotnie

				//zerowanie obiektu źródłowego
				other.p_texture = nullptr;
				other.m_rectangle.left		= 0;
				other.m_rectangle.top		= 0;
				other.m_rectangle.width		= 0;
				other.m_rectangle.height	= 0;

			}
			return *this;
		}

		//Metoda zwraca stały wskaźnik na teksturę klatki animacji z wektora
		const sf::Texture *AnimationFrame::getFrameImage() const
		{
			return p_texture;
		}

		//Metoda zwraca koordynaty klatki animacji z wektora
		const sf::IntRect AnimationFrame::getFrameRectangle() const
		{
			return m_rectangle;
		}
	}//namespace animation
}//namespace acodemia
