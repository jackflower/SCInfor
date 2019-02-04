//  __________________________________
// | CTile.cpp - class implementation |
// | SCI - by Jack Flower April 2013  |
// |__________________________________|
//

#include "CTile.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Drawable/CDrawableManager.h"

namespace mapengine
{
	namespace tile
	{
	
		RTTI_IMPL_NOPARENT(CTile);
		
		//Konstruktor
		CTile::CTile(const std::string &code)
		:
			p_displayable		(NULL),
			m_code				(code),
			m_tile_position		(0.0f, 0.0f)
		{
		}

		//Konstruktor kopiuj¹cy
		CTile::CTile(const CTile& CTileCopy)
		:
			p_displayable		(CTileCopy.p_displayable),
			m_code				(CTileCopy.m_code),
			m_tile_position		(CTileCopy.m_tile_position)
		{
		}

		//Destruktor
		CTile::~CTile()
		{
			if (p_displayable != NULL)
				gDrawableManager.DestroyDrawable(p_displayable);
			m_code				= "";
			m_tile_position.x	= 0.0f;
			m_tile_position.y	= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CTile::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda inicjuje kafel danymi
		void CTile::initializeTile(const std::string &image_file, int number)
		{
			if (p_displayable == NULL)
				p_displayable = gDrawableManager.CreateDisplayable(Z_TILE);
			if(p_displayable)
			{
				p_displayable->setTexture(image_file/*,false*/);
				p_displayable->setVisible(false);
				p_displayable->setScale(1.01f, 1.01f);
			}
		}
		
		//Metoda zwraca pozycjê kafla
		const sf::Vector2f & CTile::getPosition() const
		{
			return m_tile_position;
		}

		//Metoda ustawia pozycjê kafla na mapie
		void CTile::setPosition(float x, float y)
		{
			m_tile_position.x	= x;
			m_tile_position.y	= y;
			
			if (p_displayable != NULL)
				p_displayable->setPosition(x, y);
		}

		//Metoda ustawia pozycjê kafla na mapie
		void CTile::setPosition(const sf::Vector2f & tile_position)
		{
			m_tile_position = tile_position;

			if (p_displayable != NULL)
				p_displayable->setPosition(tile_position);
		}

		//Metoda ustawia widocznoœæ kafla na mapie
		void CTile::setVisible(bool visible)
		{
			if (p_displayable != NULL)
				p_displayable->setVisible(visible);
		}

		//Metoda zwraca nazwê znacznika kafla na mapie
		const std::string & CTile::getCode() const
		{
			return m_code;
		}

		//Metoda ustawia nazwê znacznika kafla na mapie
		void CTile::setCode(const std::string & code)
		{
			m_code = code;
		}
	}//namespace tile
}//namespace mapengine
