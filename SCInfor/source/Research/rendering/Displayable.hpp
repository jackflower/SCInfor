////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek 2021
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

#ifndef HPP_DISPLAYABLE_ACODEMIA
#define HPP_DISPLAYABLE_ACODEMIA

#include <SFML/Graphics.hpp>

namespace rendering
{
	///
	/// Class represents an object that can be rendered
	///
	class Displayable: public sf::Drawable, public sf::Transformable
	{

	public:

		///
		/// Default constructor
		///
		Displayable();

		///
		/// Copy constructor
		///
		/// @param copy - copy source
		///
		Displayable(const Displayable& copy);

		///
		/// Move constructor
		///
		/// @param other - reference to r-value 
		///
		Displayable(Displayable&& other);

		///
		/// Virtual destructor
		///
		~Displayable();

		///
		/// Overloaded copy assignment operator
		///
		/// @param copy - copy source
		///
		Displayable& operator=(const Displayable& copy);

		///
		/// Overloaded move assignment operator
		///
		/// @param other -  reference to r-value 
		///
		Displayable& operator=(Displayable&& other);

		///
		/// Get the sub-rectangle of the texture that the object will display
		///
		const sf::IntRect& getTextureRect() const;

		///
		/// Set the sub-rectangle of the texture that the object will display
		///
		/// @param rectLeft - left corner of the rectangular area
		///
		/// @param rectTop - top corner of the rectangular area
		///
		/// @param rectWidth - width of the rectangular area
		///
		/// @param rectHeight - height of the rectangular area
		///
		void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);

		///
		/// Set the sub-rectangle of the texture that the object will display
		///
		/// @param rectangle - constant reference to an object of class sf::IntRect
		///
		void setTextureRect(const sf::IntRect& rectangle);

		///
		/// Get the local bounding rectangle of the entity
		///
		sf::FloatRect getLocalBounds() const;

		///
		/// Get the global bounding rectangle of the entity
		///
		sf::FloatRect getGlobalBounds() const;

		///
		/// Get the global color of the object
		///
		const sf::Color& getColor() const;

		///
		/// Set the global color of the object
		///
		///@param color - constant reference to an object of class sf::Color
		///
		void setColor(const sf::Color& color);

		///
		/// Get the source texture of the sprite
		///
		const sf::Texture* getTexture() const;

		///
		/// Change the source texture of the object
		///
		/// @param texture - constant reference to an object of class sf::Texture
		///
		void setTexture(const sf::Texture& texture);

	private:

		///
		/// Virtual object rendering method
		///
		/// @param target - reference to the graphic context
		///
		/// @param states - render states
		///
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Sprite m_sprite; // rendered object

	};
} //namespace rendering
#endif//HPP_DISPLAYABLE_ACODEMIA
