//  _______________________________________
// | CHudSprite.cpp - class implementation |
// | Jack Flower October 2012              |
// |_______________________________________|
//

#include "CHudSprite.h"
//#include "../Camera/CCamera.h"
//#include "../../GameManager/CGame.h"
//#include "../../GameManager/CGameProperties.h"
//
//#include "CClippedSprite.h"
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
	RTTI_IMPL(CHudSprite, IDrawable);

	//Konstruktor
	CHudSprite::CHudSprite()
	:
		IDrawable			(),//konstruktor klasy bazowej
		m_sprite			(NULL), 
		m_clip_rect_enabled	(false)
	{
		memset(m_clip_rect, 0, 4*sizeof(int));
		//m_sprite = new CClippedSprite;
	}

	//Destruktor wirtualny
	CHudSprite::~CHudSprite()
	{
		//delete m_sprite;
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CClippedSprite
	sf::Sprite* CHudSprite::GetSprite() 
	{ 
		//return m_sprite; 
		return NULL;//atrapa
	} 

	//Metoda zwraca wskaŸnik na obiekt klasy CClippedSprite
	CClippedSprite* CHudSprite::GetClippedSprite() 
	{ 
		return m_sprite; 
	}

	//Metoda ustawia obszar przycinania
	void CHudSprite::SetClipRect(int left, int top, int right, int bottom)
	{
		//m_clip_rect_enabled = true;
		//m_clip_rect[0] = left;
		//m_clip_rect[1] = gGameProperties.GetHeight() - bottom;
		//m_clip_rect[2] = right - left;
		//m_clip_rect[3] = bottom - top;
	}

	//Metoda ustawia obszar przycinania
	void CHudSprite::SetClipRect(const sf::FloatRect &rect)
	{
		//SetClipRect((int)rect.Left, (int)rect.Top, (int)rect.Right, (int)rect.Bottom );
	}

	//Wirtualna metoda renderuj¹ca obiekt klasy CHudSprite
	void CHudSprite::Draw( sf::RenderWindow* render_window )
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
		
		//render_window->Draw(*m_sprite);
			
		//glDisable(GL_SCISSOR_TEST);
		//gCamera.SetZoom(zoom);
		//gGame.GetRenderWindow()->GetDefaultView().SetCenter(camera_position);
	}
} //namespace displayable