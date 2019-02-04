//  ___________________________________________
// | CAnimatedFrame.cpp - class implementation |
// | Jack Flower - March 2009                  |
// | update May 2017                           |
// |___________________________________________|
//

#include "CAnimatedFrame.h"

namespace animated
{
	//Konstruktor
	CAnimatedFrame::CAnimatedFrame()
	: 
		p_texture	(0),
		m_rectangle	()
	{
	}

	//Konstruktor kopiuj¹cy
	CAnimatedFrame::CAnimatedFrame(const CAnimatedFrame & copy)
	: 
		p_texture	(copy.p_texture),
		m_rectangle	(copy.m_rectangle)
	{
	}

	//Konstruktor parametryczny
	CAnimatedFrame::CAnimatedFrame(const sf::Texture & texture, const sf::IntRect & rectangle)
	: 
		p_texture	(&texture),
		m_rectangle	(rectangle)
	{
	}

	//Konstruktor parametryczny
	CAnimatedFrame::CAnimatedFrame(const sf::Texture & texture)
	:
		p_texture	(&texture)
	{
		if (p_texture != 0)
			m_rectangle = sf::IntRect(0, 0, p_texture->getSize().x, p_texture->getSize().y);
	}

	//Destruktor
	CAnimatedFrame::~CAnimatedFrame()
	{
		p_texture = NULL;
	}

	//Metoda zwraca sta³y wskaŸnik na teksturê klatki animacji z wektora
	const sf::Texture *CAnimatedFrame::GetFrameImage() const
	{
		return p_texture;
	}

	//Metoda zwraca koordynaty klatki animacji z wektora
	const sf::IntRect CAnimatedFrame::GetFrameRectangle() const
	{
		return m_rectangle;
	}
}//namespace animated
