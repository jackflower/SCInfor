// _______________________________________
// | Rectangle.h - class definition       |
// | Jack Flower - April 2014             |
// |______________________________________|
//

#ifndef H_RECTANGLE_JACK
#define H_RECTANGLE_JACK

#include <SFML/Graphics.hpp>
#include "../Drawable/Drawable.h"
#include "../../RTTI/RTTI.h"

using namespace rendering::drawable;

///
///Forward declaration
///
namespace sf
{
	class RenderWindow;
	class RectangleShape;
}

namespace rendering
{
	namespace primitives
	{
		///
		///Klasa reprezentuje wrapper klasy bibliotecznej sf::RectangleShape
		///
		class Rectangle : public rendering::drawable::Drawable
		{
			RTTI_DECL;
		
		public:

			///
			///Konstruktor
			///
			Rectangle();
			
			///
			///Destruktor
			///
			~Rectangle();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca wskaźnik na obiekt sf::RectangleShape
			///
			sf::RectangleShape *getRectangleShape();

			///
			///Metoda zwraca pozycję obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param x - współrzędna x obiektu
			///
			///@param y - współrzędna y obiektu
			///
			void setPosition(float x, float y);

			///
			//Metoda ustawia pozycję obiektu
			///
			///@param vector - referenacja - obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);

			///
			///Wirtualna metoda renderująca obiekt
			///
			///@render *render - wskaźnin na kontekst graficzny drawable
			///
			virtual void draw(sf::RenderWindow *render);

		protected:
		
			sf::RectangleShape *p_rectangle; //wskaźnik na obiekt klasy sf::RectangleShape (kontekst graficzny)
		};
	}//namespace primitives
}//namespace rendering
#endif//H_RECTANGLE_JACK
