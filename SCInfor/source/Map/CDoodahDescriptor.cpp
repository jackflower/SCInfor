//  ______________________________________________
// | CDoodahDescriptor.cpp - class implementation |
// | Jack Flower April 2013                       |
// |______________________________________________|
//


#include "CDoodahDescriptor.h"
#include "../Rendering/Drawable/Layers.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include "../Rendering/Animations/CAnimationManager.h"
#include "../Rendering/Drawable/CDrawableManager.h"
//#include "SceneManager/CSceneNode.h"
//#include "SceneManager/CQuadTreeSceneManager.h"
#include "CMapManager.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>

using namespace rendering::displayable;
using namespace rendering::animation;
//using namespace scenequadtree;

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CDoodahDescriptor);
		
	//Konstruktor
	CDoodahDescriptor::CDoodahDescriptor()
	:
		m_file_name		(""),
        m_anim			(""),
		m_x_position	(0.0f),
		m_y_position	(0.0f),
		m_scale			(1.0f),
		m_rotation		(0.0f),
		//m_zindex		(Z_MAPSPRITE_FG),
		m_uniqueId		(0)
	{
		m_uniqueId = nextId++;	//unikalna wartoœæ identyfikatora nadawana w konstruktorze
	}

	//Konstruktor kopiuj¹cy
	CDoodahDescriptor::CDoodahDescriptor(const CDoodahDescriptor& CDoodahDescriptorCopy)
	:
		m_file_name		(CDoodahDescriptorCopy.m_file_name),
        m_anim			(CDoodahDescriptorCopy.m_anim),
		m_x_position	(CDoodahDescriptorCopy.m_x_position),
		m_y_position	(CDoodahDescriptorCopy.m_y_position),
		m_scale			(CDoodahDescriptorCopy.m_scale),
		m_rotation		(CDoodahDescriptorCopy.m_rotation),
		m_zindex		(CDoodahDescriptorCopy.m_zindex),
		m_uniqueId		(CDoodahDescriptorCopy.m_uniqueId)
	{
	}

	//Destruktor
	CDoodahDescriptor::~CDoodahDescriptor()
	{
		m_file_name		= "";
        m_anim			= "";
		m_x_position	= 0.0f;
		m_y_position	= 0.0f;
		m_scale			= 0.0f;
		m_rotation		= 0.0f;
		m_zindex		= 0;
		m_uniqueId		= 0;
	}

	//Metoda tworzy obiekt mapy
	void CDoodahDescriptor::create()
	{
		//tworzymy obiekt klasy CDisplayable
		CDisplayable* p_displayable = gDrawableManager.CreateDisplayable(m_zindex);
		
		if (!m_anim.empty())//jeœli jest nazwa animacji
		{
			p_displayable->SetAnimation(m_anim);	//ustawiamy animacjê
			p_displayable->setScale(m_scale);		//skalujemy obiekt wed³ug wartoœci wczytanych z xml
		}
		else
		{
			//obiekt nie jest obiektem animowanym
			//	p_displayable->SetStaticImage(m_file_name);	//ustawiamy statyczny obraz
			p_displayable->setTexture(m_file_name);	//ustawiamy statyczny obraz
			//tworzymy wskaŸnik na obiekt klasy sf::Sprite i inicjujemy wskaŸnik wskaŸnikiem *p_displayable
			sf::Sprite* p_sf_sprite = p_displayable->GetSprite();
			//jeœli sprite nie ma zainnicjowanego obrazu
			//	if (p_sf_sprite->GetImage() == NULL)
			if (p_sf_sprite->getTexture() == NULL)
				return; //error - return
			//a co z tym kodem?
			//	p_sf_sprite->Resize( p_sf_sprite->GetImage()->GetWidth() * m_scale, p_sf_sprite->GetImage()->GetHeight() * m_scale );
		}

		p_displayable->setPosition(m_x_position, m_y_position);
		p_displayable->setRotation(m_rotation);

		//future...
		//CSceneNode * node = new CSceneNode;
		//node->SetDisplayable(p_displayable);
		//node->SetDoodahDescriptorId(m_uniqueId);
		//gScene.AddSceneNode(node);
	}

	//Nadanie wartoœci sta³ym sk³adowum statycznym
	int CDoodahDescriptor::nextId = 1;
}//namespace mapengine
