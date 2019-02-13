//  _____________________________________________
// | DoodahDescriptor.cpp - class implementation |
// | Jack Flower April 2013                      |
// |_____________________________________________|
//


#include "DoodahDescriptor.h"
#include "../Rendering/Drawable/Layers.h"
#include "../Rendering/Displayable/CDisplayable.h"
#include "../Rendering/Animations/CAnimationManager.h"
#include "../Rendering/Drawable/CDrawableManager.h"
//#include "SceneManager/CSceneNode.h"
//#include "SceneManager/CQuadTreeSceneManager.h"
#include "MapManager.h"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Image.hpp>

using namespace rendering::displayable;
using namespace rendering::animation;
//using namespace scenequadtree;

namespace mapengine
{
	RTTI_IMPL_NOPARENT(DoodahDescriptor);
		
	//Konstruktor
	DoodahDescriptor::DoodahDescriptor()
	:
		m_file_name(""),
        m_anim(""),
		m_x_position(0.0f),
		m_y_position(0.0f),
		m_scale(1.0f),
		m_rotation(0.0f),
		//m_zindex(Z_MAPSPRITE_FG),
		m_uniqueId(0)
	{
		m_uniqueId = nextId++; //unikalna wartość identyfikatora nadawana w konstruktorze
	}

	//Konstruktor kopiujący
	DoodahDescriptor::DoodahDescriptor(const DoodahDescriptor & DoodahDescriptorCopy)
	:
		m_file_name(DoodahDescriptorCopy.m_file_name),
        m_anim(DoodahDescriptorCopy.m_anim),
		m_x_position(DoodahDescriptorCopy.m_x_position),
		m_y_position(DoodahDescriptorCopy.m_y_position),
		m_scale(DoodahDescriptorCopy.m_scale),
		m_rotation(DoodahDescriptorCopy.m_rotation),
		m_zindex(DoodahDescriptorCopy.m_zindex),
		m_uniqueId(DoodahDescriptorCopy.m_uniqueId)
	{
	}

	//Destruktor
	DoodahDescriptor::~DoodahDescriptor()
	{
		m_file_name = "";
        m_anim = "";
		m_x_position = 0.0f;
		m_y_position = 0.0f;
		m_scale = 0.0f;
		m_rotation = 0.0f;
		m_zindex = 0;
		m_uniqueId = 0;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string DoodahDescriptor::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda tworzy obiekt mapy
	void DoodahDescriptor::create()
	{
		//tworzymy obiekt klasy CDisplayable
		CDisplayable* p_displayable = gDrawableManager.CreateDisplayable(m_zindex);
		
		if (!m_anim.empty())//jeśli jest nazwa animacji
		{
			p_displayable->SetAnimation(m_anim);	//ustawiamy animację
			p_displayable->setScale(m_scale);		//skalujemy obiekt według wartości wczytanych z xml
		}
		else
		{
			//obiekt nie jest obiektem animowanym
			//	p_displayable->SetStaticImage(m_file_name);	//ustawiamy statyczny obraz
			p_displayable->setTexture(m_file_name);	//ustawiamy statyczny obraz
			//tworzymy wskaźnik na obiekt klasy sf::Sprite i inicjujemy wskaźnik wskaźnikiem *p_displayable
			sf::Sprite* p_sf_sprite = p_displayable->GetSprite();
			//jeśli sprite nie ma zainnicjowanego obrazu
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

	//Nadanie wartości stałym składowum statycznym
	int DoodahDescriptor::nextId = 1;
}//namespace mapengine
