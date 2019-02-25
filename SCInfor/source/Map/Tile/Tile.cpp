//  _________________________________
// | Tile.cpp - class implementation |
// | SCI - by Jack Flower April 2013 |
// |_________________________________|
//

#include "Tile.h"
#include "../../Rendering/Displayable/Displayable.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Drawable/DrawableManager.h"

namespace mapengine
{
	namespace tile
	{
	
		RTTI_IMPL_NOPARENT(Tile);
		
		//Konstruktor
		Tile::Tile(const std::string &code)
		:
			p_displayable(NULL),
			m_code(code),
			m_tile_position(0.0f, 0.0f)
		{
		}

		//Konstruktor kopiujący
		Tile::Tile(const Tile & TileCopy)
		:
			p_displayable(TileCopy.p_displayable),
			m_code(TileCopy.m_code),
			m_tile_position(TileCopy.m_tile_position)
		{
		}

		//Destruktor
		Tile::~Tile()
		{
			if (p_displayable != NULL)
				gDrawableManager.destroyDrawable(p_displayable);
			m_code = "";
			m_tile_position.x = 0.0f;
			m_tile_position.y = 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Tile::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda inicjuje kafel danymi
		void Tile::initializeTile(const std::string & image_file, int number)
		{
			if (p_displayable == NULL)
				p_displayable = gDrawableManager.createDisplayable(Z_TILE);
			if(p_displayable)
			{
				p_displayable->setTexture(image_file/*,false*/);
				p_displayable->setVisible(false);
				p_displayable->setScale(1.01f, 1.01f);
			}
		}
		
		//Metoda zwraca pozycję kafla
		const sf::Vector2f & Tile::getPosition() const
		{
			return m_tile_position;
		}

		//Metoda ustawia pozycję kafla na mapie
		void Tile::setPosition(float x, float y)
		{
			m_tile_position.x	= x;
			m_tile_position.y	= y;
			
			if (p_displayable != NULL)
				p_displayable->setPosition(x, y);
		}

		//Metoda ustawia pozycję kafla na mapie
		void Tile::setPosition(const sf::Vector2f & tile_position)
		{
			m_tile_position = tile_position;

			if (p_displayable != NULL)
				p_displayable->setPosition(tile_position);
		}

		//Metoda ustawia widoczność kafla na mapie
		void Tile::setVisible(bool visible)
		{
			if (p_displayable != NULL)
				p_displayable->setVisible(visible);
		}

		//Metoda zwraca nazwę znacznika kafla na mapie
		const std::string & Tile::getCode() const
		{
			return m_code;
		}

		//Metoda ustawia nazwę znacznika kafla na mapie
		void Tile::setCode(const std::string & code)
		{
			m_code = code;
		}
	}//namespace tile
}//namespace mapengine
