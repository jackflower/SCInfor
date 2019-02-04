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
			///Konstruktor kopiuj�cy
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
			///Metoda zwraca pozycj� kafla
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycj� kafla na mapie
			///
			///@param x - sk�adowa x kafla na mapie
			///
			///@param y - sk�adowa y kafla na mapie
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycj� kafla na mapie
			///
			///@param & tile_position - wektor pozycji - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & tile_position);

			///
			///Metoda ustawia widoczno�� kafla na mapie
			///
			///@param visible - flaga, czy kafel ma by� widczny na mapie
			///
			void setVisible(bool visible);

			///
			///Metoda zwraca nazw� znacznika kafla na mapie
			///
			const std::string & getCode() const;

			///
			///Metoda ustawia nazw� znacznika kafla na mapie
			///
			///@param & code - nazw� znacznika kafla na mapie - sta�a referencja na obiekt klasy std::string
			///
			void setCode(const std::string & code);

		protected:

			CDisplayable*	p_displayable;		//wska�nik na graficzn� reprezentacj� kafla
			std::string		m_code;				//nazwa znacznika kafla na mapie
			sf::Vector2f	m_tile_position;	//pozycja kafla
		};
	}//namespace tile
}//namespace mapengine
#endif //H_TILE_JACK
