// ________________________________________
// | CRectangle.h - class definition       |
// | Jack Flower - April 2014.             |
// |_______________________________________|
//

#ifndef H_RECTANGLE_JACK
#define H_RECTANGLE_JACK

#include <SFML/Graphics.hpp>
#include "../Drawable/IDrawable.h"
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
		class CRectangle : public IDrawable
		{
			RTTI_DECL;
		
		public:

			///
			///Konstruktor
			///
			CRectangle();
			
			///
			///Destruktor
			///
			~CRectangle();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca wska�nik na obiekt sf::RectangleShape
			///
			sf::RectangleShape *getRectangleShape();

			///
			///Metoda zwraca pozycj� obiektu
			///
			const sf::Vector2f& getPosition() const;

			///
			///Metoda ustawia pozycj� obiektu
			///
			///@param x - wsp�rz�dna x obiektu
			///
			///@param y - wsp�rz�dna y obiektu
			///
			void setPosition(float x, float y);

			///
			//Metoda ustawia pozycj� obiektu
			///
			///@param &vector - referenacja - obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f& vector);

			///
			///Wirtualna metoda renderuj�ca obiekt
			///
			///@render render - parametr drawable
			///
			virtual void Draw(sf::RenderWindow* render);

		protected:
		
			sf::RectangleShape* p_rectangle;		//wska�nik na obiekt klasy sf::RectangleShape (kontekst graficzny)
		};
	}//namespace primitives
}//namespace rendering
#endif//H_RECTANGLE_JACK
