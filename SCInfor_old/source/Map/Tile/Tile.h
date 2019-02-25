//  _________________________________
// | Tile.h - class definition       |
// | SCI - by Jack Flower April 2013 |
// |_________________________________|
//


#ifndef H_TILE_JACK
#define H_TILE_JACK

#include <SFML/System/Vector2.hpp>
#include "../../RTTI/RTTI.h"
#include <string>

///
///Forward declaration
///
namespace rendering
{
	namespace displayable
	{
		class Displayable;
	}
}

using namespace rendering::displayable;

namespace mapengine
{
	namespace tile
	{
		///
		///Klasa reprezentuje kafel mapy
		///
		class Tile
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			///@param code - nazwa typy kafla
			///
			Tile(const std::string & code);

			///
			///Konstruktor kopiujący
			///
			///@param TileCopy - obiekt klasy Tile
			///
			Tile(const Tile & TileCopy);

			///
			///Destruktor
			///
			~Tile();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda inicjuje kafel danymi
			///
			///@param image_file - nazwa pliku z obrazem kafla
			///
			///@param number - numer obrazu w atlasie
			///
			void initializeTile(const std::string & image_file, int number = -1);
			
			///
			///Metoda zwraca pozycję kafla
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycję kafla na mapie
			///
			///@param x - składowa x kafla na mapie
			///
			///@param y - składowa y kafla na mapie
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycję kafla na mapie
			///
			///@param tile_position - wektor pozycji - stała referencja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & tile_position);

			///
			///Metoda ustawia widoczność kafla na mapie
			///
			///@param visible - flaga, czy kafel ma być widczny na mapie
			///
			void setVisible(bool visible);

			///
			///Metoda zwraca nazwę znacznika kafla na mapie
			///
			const std::string & getCode() const;

			///
			///Metoda ustawia nazwę znacznika kafla na mapie
			///
			///@param code - nazwę znacznika kafla na mapie - stała referencja na obiekt klasy std::string
			///
			void setCode(const std::string & code);

		protected:

			Displayable *p_displayable;//wskaźnik na graficzną reprezentację kafla
			std::string m_code;//nazwa znacznika kafla na mapie
			sf::Vector2f m_tile_position; //pozycja kafla
		};
	}//namespace tile
}//namespace mapengine
#endif //H_TILE_JACK
