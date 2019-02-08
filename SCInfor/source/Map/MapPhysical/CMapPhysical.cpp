//  _________________________________________
// | CMapPhysical.cpp - class implementation |
// | Jack Flower - March 2015                |
// |_________________________________________|
//

#include "CMapPhysical.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../../Rendering/Drawable/CDrawableManager.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Animations/CAnimation.h"
#include "../../Rendering/Animations/CAnimationState.h"
#include "../../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"
#include "../Ground/PhysicsGround/CPhysicsGround.h"


namespace mapengine
{
	RTTI_IMPL_NOPARENT(CMapPhysical);

	//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CMapPhysicalManager
	CMapPhysical::CMapPhysical(const std::wstring& uniqueId)
	:
		m_unique_id					(uniqueId),
		m_code						(),
		p_displayable				(NULL),
		m_map_physical_position		(0.0f, 0.0f),
		m_scale						(0.0f, 0.0f),
		m_origin					(0.0f, 0.0f),
		m_rotation					(0.0f),
		m_size						(0.0f, 0.0f),
		m_displayable_type			(),
		p_template					(NULL),
		p_synthetic_texture			(NULL),
		p_synthetic_image			(NULL),
		m_smooth					(false),
		m_mapphysical_manager_index	(-1),
		m_ready_for_destruction		(false)
	{
		p_synthetic_texture = new CTexture();
		p_synthetic_image = new sf::Image;
	}

	//Chroniony konstruktor kopiuj¹cy
	CMapPhysical::CMapPhysical(const CMapPhysical &CMapPhysicalCopy)
	:
		m_unique_id					(CMapPhysicalCopy.m_unique_id),
		m_code						(CMapPhysicalCopy.m_code),
		p_displayable				(CMapPhysicalCopy.p_displayable),
		m_map_physical_position		(CMapPhysicalCopy.m_map_physical_position),
		m_scale						(CMapPhysicalCopy.m_scale),
		m_origin					(CMapPhysicalCopy.m_origin),
		m_rotation					(CMapPhysicalCopy.m_rotation),
		m_size						(CMapPhysicalCopy.m_size),
		m_displayable_type			(CMapPhysicalCopy.m_displayable_type),
		p_template					(CMapPhysicalCopy.p_template),
		p_synthetic_texture			(CMapPhysicalCopy.p_synthetic_texture),
		p_synthetic_image			(CMapPhysicalCopy.p_synthetic_image),
		m_smooth					(CMapPhysicalCopy.m_smooth),
		m_mapphysical_manager_index	(CMapPhysicalCopy.m_mapphysical_manager_index),
		m_ready_for_destruction		(CMapPhysicalCopy.m_ready_for_destruction)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CMapPhysicalManager
	CMapPhysical::~CMapPhysical()
	{
		m_unique_id						= L"";
		m_code							= "";
		
		if (p_displayable != NULL)
			gDrawableManager.DestroyDrawable(p_displayable);
		
		p_displayable					= NULL;
		m_map_physical_position.x		= 0.0f;
		m_map_physical_position.y		= 0.0f;
		m_scale.x						= 0.0f;
		m_scale.y						= 0.0f;
		m_origin.x						= 0.0f;
		m_origin.y						= 0.0f;
		m_rotation						= 0.0f;
		m_size.x						= 0.0f;
		m_size.y						= 0.0f;
		m_displayable_type				= "";
		p_template						= NULL;
		
		if(p_synthetic_texture)
			delete p_synthetic_texture;
		p_synthetic_texture				= NULL;
		
		if(p_synthetic_image)
			delete p_synthetic_image;
		p_synthetic_image				= NULL;

		m_smooth						= false;
		m_mapphysical_manager_index		= 0;
		m_ready_for_destruction			= false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMapPhysical::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca unikaln¹ nazwê obiektu klasy CMapWork
	const std::wstring & CMapPhysical::GetUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda ustawia flagê dla obiektów gotowych do destrukcji
	void CMapPhysical::MarkForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Metoda zwraca nazwê znacznika pod³o¿a na mapie (odczytany z xml)
	const std::string & CMapPhysical::getCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazwê znacznika pod³o¿a na mapie (dotyczy xml)
	void CMapPhysical::setCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca pozycjê pod³o¿a
	const sf::Vector2f & CMapPhysical::getPosition() const
	{
		return m_map_physical_position;
	}

	//Metoda ustawia pozycjê pod³o¿a na mapie
	void CMapPhysical::setPosition(float x, float y)
	{
		m_map_physical_position.x = x;
		m_map_physical_position.y = y;
		if (p_displayable != NULL)
			p_displayable->setPosition(x, y);
	}

	//Metoda ustawia pozycjê pod³o¿a na mapie
	void CMapPhysical::setPosition(const sf::Vector2f & map_physical_position)
	{
		m_map_physical_position = map_physical_position;
		if (p_displayable != NULL)
			p_displayable->setPosition(map_physical_position);
	}

	//Metoda zwraca skalê
	const sf::Vector2f& CMapPhysical::getScale() const
	{
		return m_scale;
	}

	//Metoda ustawia skalê
	void CMapPhysical::setScale(float x, float y)
	{
		m_scale.x = x;
		m_scale.y = y;
		if(p_displayable)
			p_displayable->setScale(x, y);
	}

	//Metoda ustawia skalê
	void CMapPhysical::setScale(const sf::Vector2f& scale)
	{
		m_scale = scale;
		if(p_displayable)
			p_displayable->setScale(scale);
	}

	//Metoda ustawia skalê
	void CMapPhysical::setScale(float factors)
	{
		m_scale.x = factors;
		m_scale.y = factors;
		if(p_displayable)
			p_displayable->setScale(factors, factors);
	}

	//Metoda ustawia skalê w stosunku do obecnej skali
	void CMapPhysical::scale(float factorX, float factorY)
	{
		m_scale.x = factorX;
		m_scale.y = factorY;
		if(p_displayable)
			p_displayable->scale(factorX, factorY);
	}

	//Metoda ustawia skalê w stosunku do obecnej skali
	void CMapPhysical::scale(const sf::Vector2f & factor)
	{
		m_scale = factor;
		if(p_displayable)
			p_displayable->scale(factor);
	}

	//Metoda zwraca wspó³rzêdne punktu uchwytu obiektu
	const sf::Vector2f& CMapPhysical::getOrigin() const
	{
		return m_origin;
	}

	//Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
	void CMapPhysical::setOrigin(float x, float y)
	{
		m_origin.x = x;
		m_origin.y = y;
		if(p_displayable)
			p_displayable->setOrigin(x, y);
	}

	//Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
	void CMapPhysical::setOrigin(const sf::Vector2f & origin)
	{
		m_origin = origin;
		if(p_displayable)
			p_displayable->setOrigin(origin);
	}

	//Metoda zwraca wartoœæ obrotu
	float CMapPhysical::getRotation() const
	{ 
		return m_rotation;
	}

	//Metoda ustawia wartoœæ obrotu
	void CMapPhysical::setRotation(float rotation_value)
	{
		m_rotation = rotation_value;
		if(p_displayable)
			p_displayable->setRotation(rotation_value);
	}

	//Metoda obraca wartoœæ obrotu
	void CMapPhysical::rotate(float angle)
	{
		m_rotation = angle;
		if(p_displayable)
			p_displayable->rotate(angle);
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2f & CMapPhysical::getSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysical::setSize(const sf::Vector2f & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysical::setSize(float x, float y)
	{
		m_size.x = x;
		m_size.y = y;
	}

	//Metoda ustawia rozmiar obiektu
	void CMapPhysical::setSize(float uniform)
	{
		m_size.x = uniform;
		m_size.y = uniform;
	}

	//Metoda ustawia widocznoœæ pod³o¿a na mapie
	void CMapPhysical::setVisible(bool visible)
	{
		if (p_displayable != NULL)
			p_displayable->setVisible(visible);
	}

	//Metoda ustawia grafikê na teksturê
	void CMapPhysical::setImage(const std::string & image_name)
	{
		checkDisplayable();
		if (p_displayable)
			p_displayable->setTexture(image_name);
	}

	//Metoda generuje obraz tekstury
	void CMapPhysical::setImage(unsigned width, unsigned height, const sf::Color & color)
	{
		checkDisplayable();

		p_synthetic_texture->create(width, height);
		p_synthetic_image->create(width, height, color);
		p_synthetic_texture->update(*p_synthetic_image);

		if(p_displayable)
			p_displayable->setTexture(p_synthetic_texture);
	}

		
	//Metoda generuje obraz tekstury
	void CMapPhysical::setImage(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		checkDisplayable();

		p_synthetic_texture->create(width, height);
		p_synthetic_image->create(width, height, sf::Color(r, g, b, a));
		p_synthetic_texture->update(*p_synthetic_image);

		if(p_displayable)
			p_displayable->setTexture(p_synthetic_texture);
	}

	//Metoda ustawia animacjê
	void CMapPhysical::setAnimation(const std::string & animation_name)
	{
		checkDisplayable();
		if(p_displayable)
			p_displayable->SetAnimation(animation_name);
	}

	//Metoda zwraca typ reprezentacji graficznej obiektu
	const std::string CMapPhysical::getMapPhysicalDisplayableType() const
	{
		return m_displayable_type;
	}
	
	//Metoda ustawia typ reprezentacji graficznej obiektu
	void CMapPhysical::setMapPhysicalDisplayableType(const std::string displayable_type)
	{
		m_displayable_type = displayable_type;
	}

	//Metoda zwraca flagê okreœlaj¹c¹ filtr wyg³adzaj¹cy teksturê
	const bool CMapPhysical::getSmooth() const
	{
		return m_smooth;
	}

	//Metoda ustawia flagê okreœlaj¹c¹ filtr wyg³adzaj¹cy teksturê
	void CMapPhysical::setSmooth(bool smooth)
	{
		m_smooth = smooth;
		if(p_displayable)
			p_displayable->setSmoothing(m_smooth);
	}

	//Metoda zwraca wskaŸnik na obiekt klasy CDisplayable
	CDisplayable* CMapPhysical::GetDisplayable()
	{
		return p_displayable;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CMapPhysical::update(float dt)
	{
		//nothing to do...
	}

	//implementajca metod private:

	//prywatna metoda sprawdza, czy trzeba utworzyæ
	//obiekt klasy CDisplayable (body), np. gdy chcemy
	//dodaæ obrazek, animacjê, syntetyk, etc...
	void CMapPhysical::checkDisplayable()
	{
		if (!p_displayable)
			p_displayable = gDrawableManager.CreateDisplayable(Z_GROUND_WORK);
	}
}//namespace mapengine
