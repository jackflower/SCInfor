//  __________________________________________
// | AnimatedFrame.cpp - class implementation |
// | Jack Flower - March 2009                 |
// |__________________________________________|
//

#include "AnimatedFrame.h"

namespace animated
{
	RTTI_IMPL_NOPARENT(AnimatedFrame);

	//Konstruktor
	AnimatedFrame::AnimatedFrame()
	: 
		p_texture(0),
		m_rectangle()
	{
	}

	//Konstruktor kopiujący
	AnimatedFrame::AnimatedFrame(const AnimatedFrame & copy)
	: 
		p_texture(copy.p_texture),
		m_rectangle(copy.m_rectangle)
	{
	}

	//Konstruktor przenoszący
	AnimatedFrame::AnimatedFrame(AnimatedFrame && other)
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
	AnimatedFrame::AnimatedFrame(const Texture & texture, const sf::IntRect & rectangle)
	//AnimatedFrame::AnimatedFrame(const sf::Texture & texture, const sf::IntRect & rectangle)
	: 
		p_texture	(&texture),
		m_rectangle	(rectangle)
	{
	}

	//Konstruktor parametryczny
	//AnimatedFrame::AnimatedFrame(const sf::Texture & texture)
	AnimatedFrame::AnimatedFrame(const Texture & texture)
	:
		p_texture	(&texture)
	{
		if (p_texture != 0)
			m_rectangle = sf::IntRect(0, 0, p_texture->getSize().x, p_texture->getSize().y);
	}

	//Destruktor
	AnimatedFrame::~AnimatedFrame()
	{
		p_texture = NULL;
	}

	//Przeciążony operator przypisania kopiowania
	AnimatedFrame & AnimatedFrame::operator=(const AnimatedFrame & copy)
	{
		if (this != &copy)
		{
			//zwalaniamy dane pod wskaźnikiem
			delete p_texture;
			//tworzymy nowy obiekt na podstawie obiektu źródłowego
			p_texture = new Texture(*copy.p_texture);
			m_rectangle = copy.m_rectangle;
		}
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	AnimatedFrame & AnimatedFrame::operator=(AnimatedFrame && other)
	{
		if (this != &other)
		{
			//zwalaniamy dane pod wskaźnikiem
			delete p_texture; //rzuca wyjatkiem...
			//przenosimy pod wskaźnik dane z obiektu źródłowego
			p_texture = other.p_texture;
			m_rectangle = other.m_rectangle;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie

			//zerowanie obiektu źródłowego
			other.p_texture = nullptr;
			other.m_rectangle.left = 0;
			other.m_rectangle.top = 0;
			other.m_rectangle.width = 0;
			other.m_rectangle.height = 0;

		}
		return *this;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string AnimatedFrame::getType() const
	{
		return rtti.getNameClass();
	}


	//Metoda zwraca stały wskaźnik na teksturę klatki animacji z wektora
	const sf::Texture *AnimatedFrame::getFrameImage() const
	{
		return p_texture;
	}

	//Metoda zwraca koordynaty klatki animacji z wektora
	const sf::IntRect AnimatedFrame::getFrameRectangle() const
	{
		return m_rectangle;
	}
}//namespace animated
