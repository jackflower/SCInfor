//  ______________________________________
// | HudSprite.cpp - class implementation |
// | Jack Flower October 2012             |
// |______________________________________|
//

#include "HudSprite.h"
//#include "../Camera/CCamera.h"
//#include "../../GameManager/CGame.h"
//#include "../../GameManager/CGameProperties.h"
//
//#include "ClippedSprite.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

//#ifdef PLATFORM_MACOSX
//#include <gl.h>
//#else
//#include <GL/gl.h>
//#endif

namespace displayable
{
	RTTI_IMPL(HudSprite, Drawable);

	//Konstruktor
	HudSprite::HudSprite()
	:
		Drawable(),//konstruktor klasy bazowej
		m_sprite(nullptr), 
		m_clip_rect_enabled(false)
	{
		memset(m_clip_rect, 0, 4*sizeof(int));
		//m_sprite = new ClippedSprite;
	}

	//Destruktor wirtualny
	HudSprite::~HudSprite()
	{
		//delete m_sprite;
	}

	//Metoda zwraca wskaźnik na obiekt klasy ClippedSprite
	sf::Sprite *HudSprite::getSprite() 
	{ 
		//return m_sprite; 
		return nullptr;//atrapa
	} 

	//Metoda zwraca wskaźnik na obiekt klasy ClippedSprite
	ClippedSprite *HudSprite::getClippedSprite() 
	{ 
		return m_sprite; 
	}

	//Metoda ustawia obszar przycinania
	void HudSprite::setClipRect(int left, int top, int right, int bottom)
	{
		//m_clip_rect_enabled = true;
		//m_clip_rect[0] = left;
		//m_clip_rect[1] = gGameProperties.GetHeight() - bottom;
		//m_clip_rect[2] = right - left;
		//m_clip_rect[3] = bottom - top;
	}

	//Metoda ustawia obszar przycinania
	void HudSprite::setClipRect(const sf::FloatRect & rect)
	{
		setClipRect((int)rect.left, (int)rect.top, (int)rect.width, (int)rect.height );
	}

	//Wirtualna metoda renderująca obiekt klasy HudSprite
	void HudSprite::draw( sf::RenderWindow *render_window )
	{
		//float zoom = gCamera.GetZoom();
		//gCamera.SetZoom(1.0f); 

		//sf::Vector2f camera_position = gGame.GetRenderWindow()->GetDefaultView().GetCenter();
		//gGame.GetRenderWindow()->GetDefaultView().SetCenter(gGame.GetRenderWindow()->GetDefaultView().GetHalfSize());

		//if (m_clip_rect_enabled)
		//{
		//	glEnable(GL_SCISSOR_TEST);
		//	glScissor(m_clip_rect[0], m_clip_rect[1], m_clip_rect[2], m_clip_rect[3]);
		//}
		
		//render_window->draw(*m_sprite);
			
		//glDisable(GL_SCISSOR_TEST);
		//gCamera.SetZoom(zoom);
		//gGame.GetRenderWindow()->GetDefaultView().SetCenter(camera_position);
	}
} //namespace displayable
