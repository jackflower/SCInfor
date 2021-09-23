////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2021
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraŸnych ani domniemanych gwarancji.
//
// W ¿adnym wypadku Autor nie ponosi odpowiedzialnoœci
// za jakiekolwiek szkody powsta³e w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala siê na korzystanie z tego oprogramowania
// w dowolnym celu, tak¿e komercyjnym. Mo¿na je zmieniæ
// i swobodnie rozpowszechniaæ.
//
// Zastrzega siê nastêpuj¹ce ograniczenia:
//
// 1. Jeœli u¿ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by³oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "Displayable.hpp"

namespace rendering
{

	// Default constructor
	Displayable::Displayable() :
		sf::Drawable{}, // base class constructor
		sf::Transformable{}, // base class constructor
		m_sprite{}
	{
	}

	// Copy constructor
	Displayable::Displayable(const Displayable& copy) :
		//sf::Drawable{ copy }, // noncopyable...
		sf::Transformable{ copy }, // base class copy constructor
		m_sprite{copy.m_sprite }
	{
	}

	// Move constructor
	Displayable::Displayable(Displayable&& other) :
		//sf::Drawable{ other }, // noncopyable...
		sf::Transformable{ other }, // base class move constructor
		m_sprite{other.m_sprite}
	{
	}

	// Virtual destructor
	Displayable::~Displayable()
	{
	}

	// Overloaded copy assignment operator
	Displayable& Displayable::operator=(const Displayable& copy)
	{
		if (this != &copy)
		{
			m_sprite = copy.m_sprite;
		}
		return *this;
	}

	// Overloaded move assignment operator
	Displayable& Displayable::operator=(Displayable&& other)
	{
		if (this != &other)
		{
			m_sprite = other.m_sprite;
		}
		return *this;
	}

	// Get the sub-rectangle of the texture that the object will display
	const sf::IntRect& Displayable::getTextureRect() const
	{
		return m_sprite.getTextureRect();
	}

	// Set the sub-rectangle of the texture that the object will display
	void Displayable::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight)
	{
		setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
	}

	// Set the sub-rectangle of the texture that the object will display
	void Displayable::setTextureRect(const sf::IntRect& rectangle)
	{
		m_sprite.setTextureRect(rectangle);
	}

	// Get the local bounding rectangle of the entity
	sf::FloatRect Displayable::getLocalBounds() const
	{
		return m_sprite.getLocalBounds();
	}

	// Get the global bounding rectangle of the entity
	sf::FloatRect Displayable::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	// Get the global color of the object
	const sf::Color&  Displayable::getColor() const
	{
		return m_sprite.getColor();
	}

	// Set the global color of the object
	void Displayable::setColor(const sf::Color& color)
	{
		m_sprite.setColor(color);
	}

	// Get the source texture of the sprite
	const sf::Texture* Displayable::getTexture() const
	{
		return m_sprite.getTexture();
	}

	// Change the source texture of the object
	void Displayable::setTexture(const sf::Texture & texture)
	{
		m_sprite.setTexture(texture);
	}

	// Virtual object rendering method
	void Displayable::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// a position / rotation / scale transformation must
		// take place before the unit is displayed
		states.transform *= getTransform();
		target.draw(m_sprite, states);		
	}

}//namespace rendering
