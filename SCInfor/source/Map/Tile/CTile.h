//  __________________________________
// | CTile.h - class definition       |
// | SCI - by Jack Flower April 2013  |
// |__________________________________|
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
		class CDisplayable;
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
		class CTile
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor
			///
			///@param code - nazwa typy kafla
			///
			CTile(const std::string &code);

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &CTileCopy - obiekt klasy CTile
			///
			CTile(const CTile& CTileCopy);

			///
			///Destruktor
			///
			~CTile();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda inicjuje kafel danymi
			///
			///@param &image_file - nazwa pliku z obrazem kafla
			///
			///@param number - numer obrazu w atlasie
			///
			void initializeTile(const std::string &image_file, int number = -1);
			
			///
			///Metoda zwraca pozycjê kafla
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycjê kafla na mapie
			///
			///@param x - sk³adowa x kafla na mapie
			///
			///@param y - sk³adowa y kafla na mapie
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycjê kafla na mapie
			///
			///@param & tile_position - wektor pozycji - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & tile_position);

			///
			///Metoda ustawia widocznoœæ kafla na mapie
			///
			///@param visible - flaga, czy kafel ma byæ widczny na mapie
			///
			void setVisible(bool visible);

			///
			///Metoda zwraca nazwê znacznika kafla na mapie
			///
			const std::string & getCode() const;

			///
			///Metoda ustawia nazwê znacznika kafla na mapie
			///
			///@param & code - nazwê znacznika kafla na mapie - sta³a referencja na obiekt klasy std::string
			///
			void setCode(const std::string & code);

		protected:

			CDisplayable*	p_displayable;		//wskaŸnik na graficzn¹ reprezentacjê kafla
			std::string		m_code;				//nazwa znacznika kafla na mapie
			sf::Vector2f	m_tile_position;	//pozycja kafla
		};
	}//namespace tile
}//namespace mapengine
#endif //H_TILE_JACK
