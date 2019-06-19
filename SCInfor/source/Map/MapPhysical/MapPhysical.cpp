//  ________________________________________
// | MapPhysical.cpp - class implementation |
// | Jack Flower - March 2015               |
// |________________________________________|
//

#include "MapPhysical.h"
#include "../Ground/PhysicsGround/PhysicsGround.h"
#include "../../Rendering/Displayable/Displayable.h"
#include "../../Rendering/Drawable/DrawableManager.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Rendering/Animations/Animation.h"
#include "../../Rendering/Animations/AnimationState.h"
#include "../../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"


namespace mapengine
{
	RTTI_IMPL_NOPARENT(MapPhysical);

	//Chroniony konstruktor domyślny - używany wyłącznie przez MapPhysicalManager
	MapPhysical::MapPhysical(const std::wstring & uniqueId)
	:
		m_unique_id{ uniqueId },
		m_code{},
		p_displayable{ nullptr },
		m_map_physical_position{ 0.0f, 0.0f },
		m_scale{ 0.0f, 0.0f },
		m_origin{ 0.0f, 0.0f },
		m_rotation{ 0.0f },
		m_size{ 0.0f, 0.0f },
		m_displayable_type{},
		p_template{ nullptr },
		p_synthetic_texture{ nullptr },
		p_synthetic_image{ nullptr },
		m_smooth{ false },
		m_mapphysical_manager_index{ -1 },
		m_ready_for_destruction{ false }
	{
		p_synthetic_texture = new ResourceTexture();
		p_synthetic_image = new sf::Image;
	}

	//Chroniony konstruktor kopiujący
	MapPhysical::MapPhysical(const MapPhysical & MapPhysicalCopy)
	:
		m_unique_id{ MapPhysicalCopy.m_unique_id },
		m_code{ MapPhysicalCopy.m_code },
		p_displayable{ MapPhysicalCopy.p_displayable },
		m_map_physical_position{ MapPhysicalCopy.m_map_physical_position },
		m_scale{ MapPhysicalCopy.m_scale },
		m_origin{ MapPhysicalCopy.m_origin },
		m_rotation{ MapPhysicalCopy.m_rotation },
		m_size{ MapPhysicalCopy.m_size },
		m_displayable_type{ MapPhysicalCopy.m_displayable_type },
		p_template{ MapPhysicalCopy.p_template },
		p_synthetic_texture{ MapPhysicalCopy.p_synthetic_texture },
		p_synthetic_image{ MapPhysicalCopy.p_synthetic_image },
		m_smooth{ MapPhysicalCopy.m_smooth },
		m_mapphysical_manager_index{ MapPhysicalCopy.m_mapphysical_manager_index },
		m_ready_for_destruction{ MapPhysicalCopy.m_ready_for_destruction }
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez MapPhysicalManager
	MapPhysical::~MapPhysical()
	{
		m_unique_id = L"";
		m_code = "";
		
		if (p_displayable != nullptr)
			gDrawableManager.destroyDrawable(p_displayable);
		
		p_displayable = nullptr;
		m_map_physical_position.x = 0.0f;
		m_map_physical_position.y = 0.0f;
		m_scale.x = 0.0f;
		m_scale.y = 0.0f;
		m_origin.x = 0.0f;
		m_origin.y = 0.0f;
		m_rotation = 0.0f;
		m_size.x = 0.0f;
		m_size.y = 0.0f;
		m_displayable_type = "";
		p_template = nullptr;
		
		if(p_synthetic_texture)
			delete p_synthetic_texture;
		p_synthetic_texture = nullptr;
		
		if(p_synthetic_image)
			delete p_synthetic_image;
		p_synthetic_image = nullptr;

		m_smooth = false;
		m_mapphysical_manager_index = 0;
		m_ready_for_destruction = false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapPhysical::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca unikalną nazwę obiektu klasy CMapWork
	const std::wstring & MapPhysical::getUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda ustawia flagę dla obiektów gotowych do destrukcji
	void MapPhysical::markForDelete()
	{
		m_ready_for_destruction = true;
	}

	//Metoda zwraca nazwę znacznika podłoża na mapie (odczytany z xml)
	const std::string & MapPhysical::getCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazwę znacznika podłoża na mapie (dotyczy xml)
	void MapPhysical::setCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca pozycję podłoża
	const sf::Vector2f & MapPhysical::getPosition() const
	{
		return m_map_physical_position;
	}

	//Metoda ustawia pozycję podłoża na mapie
	void MapPhysical::setPosition(float x, float y)
	{
		m_map_physical_position.x = x;
		m_map_physical_position.y = y;
		if (p_displayable != nullptr)
			p_displayable->setPosition(x, y);
	}

	//Metoda ustawia pozycję podłoża na mapie
	void MapPhysical::setPosition(const sf::Vector2f & map_physical_position)
	{
		m_map_physical_position = map_physical_position;
		if (p_displayable != nullptr)
			p_displayable->setPosition(map_physical_position);
	}

	//Metoda zwraca skalę
	const sf::Vector2f & MapPhysical::getScale() const
	{
		return m_scale;
	}

	//Metoda ustawia skalę
	void MapPhysical::setScale(float x, float y)
	{
		m_scale.x = x;
		m_scale.y = y;
		if(p_displayable)
			p_displayable->setScale(x, y);
	}

	//Metoda ustawia skalę
	void MapPhysical::setScale(const sf::Vector2f & scale)
	{
		m_scale = scale;
		if(p_displayable)
			p_displayable->setScale(scale);
	}

	//Metoda ustawia skalę
	void MapPhysical::setScale(float factors)
	{
		m_scale.x = factors;
		m_scale.y = factors;
		if(p_displayable)
			p_displayable->setScale(factors, factors);
	}

	//Metoda ustawia skalę w stosunku do obecnej skali
	void MapPhysical::scale(float factorX, float factorY)
	{
		m_scale.x = factorX;
		m_scale.y = factorY;
		if(p_displayable)
			p_displayable->scale(factorX, factorY);
	}

	//Metoda ustawia skalę w stosunku do obecnej skali
	void MapPhysical::scale(const sf::Vector2f & factor)
	{
		m_scale = factor;
		if(p_displayable)
			p_displayable->scale(factor);
	}

	//Metoda zwraca współrzędne punktu uchwytu obiektu
	const sf::Vector2f & MapPhysical::getOrigin() const
	{
		return m_origin;
	}

	//Metoda ustawia współrzędne punktu uchwytu obiektu
	void MapPhysical::setOrigin(float x, float y)
	{
		m_origin.x = x;
		m_origin.y = y;
		if(p_displayable)
			p_displayable->setOrigin(x, y);
	}

	//Metoda ustawia współrzędne punktu uchwytu obiektu
	void MapPhysical::setOrigin(const sf::Vector2f & origin)
	{
		m_origin = origin;
		if(p_displayable)
			p_displayable->setOrigin(origin);
	}

	//Metoda zwraca wartość obrotu
	float MapPhysical::getRotation() const
	{ 
		return m_rotation;
	}

	//Metoda ustawia wartość obrotu
	void MapPhysical::setRotation(float rotation_value)
	{
		m_rotation = rotation_value;
		if(p_displayable)
			p_displayable->setRotation(rotation_value);
	}

	//Metoda obraca wartość obrotu
	void MapPhysical::rotate(float angle)
	{
		m_rotation = angle;
		if(p_displayable)
			p_displayable->rotate(angle);
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2f & MapPhysical::getSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysical::setSize(const sf::Vector2f & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysical::setSize(float x, float y)
	{
		m_size.x = x;
		m_size.y = y;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysical::setSize(float uniform)
	{
		m_size.x = uniform;
		m_size.y = uniform;
	}

	//Metoda ustawia widoczność podłoża na mapie
	void MapPhysical::setVisible(bool visible)
	{
		if (p_displayable != nullptr)
			p_displayable->setVisible(visible);
	}

	//Metoda ustawia grafikę na teksturę
	void MapPhysical::setImage(const std::string & image_name)
	{
		checkDisplayable();
		if (p_displayable)
			p_displayable->setTexture(image_name);
	}

	//Metoda generuje obraz tekstury
	void MapPhysical::setImage(unsigned width, unsigned height, const sf::Color & color)
	{
		checkDisplayable();

		p_synthetic_texture->create(width, height);
		p_synthetic_image->create(width, height, color);
		p_synthetic_texture->update(*p_synthetic_image);

		if(p_displayable)
			p_displayable->setTexture(p_synthetic_texture);
	}
		
	//Metoda generuje obraz tekstury
	void MapPhysical::setImage(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
	{
		checkDisplayable();

		p_synthetic_texture->create(width, height);
		p_synthetic_image->create(width, height, sf::Color(r, g, b, a));
		p_synthetic_texture->update(*p_synthetic_image);

		if(p_displayable)
			p_displayable->setTexture(p_synthetic_texture);
	}

	//Metoda ustawia animację
	void MapPhysical::setAnimation(const std::string & animation_name)
	{
		checkDisplayable();
		if(p_displayable)
			p_displayable->setAnimation(animation_name);
	}

	//Metoda zwraca stałą referencję na typ reprezentacji graficznej obiektu
	const std::string & MapPhysical::getMapPhysicalDisplayableType() const
	{
		return m_displayable_type;
	}
	
	//Metoda ustawia typ reprezentacji graficznej obiektu
	void MapPhysical::setMapPhysicalDisplayableType(const std::string & displayable_type)
	{
		m_displayable_type = displayable_type;
	}

	//Metoda zwraca flagę określającą filtr wygładzający teksturę
	const bool MapPhysical::getSmooth() const
	{
		return m_smooth;
	}

	//Metoda ustawia flagę określającą filtr wygładzający teksturę
	void MapPhysical::setSmooth(bool smooth)
	{
		m_smooth = smooth;
		if(p_displayable)
			p_displayable->setSmoothing(m_smooth);
	}

	//Metoda zwraca wskaźnik na obiekt klasy MapPhysicalTemplate
	MapPhysicalTemplate *MapPhysical::getTemplate() const
	{
		return p_template;
	}

	//Metoda ustawia wskaźnik na obiekt klasy MapPhysicalTemplate
	void MapPhysical::setTemplate(MapPhysicalTemplate *p_template_param)
	{
		p_template = p_template_param;
	}


	//Metoda zwraca wskaźnik na obiekt klasy Displayable
	Displayable *MapPhysical::getDisplayable()
	{
		return p_displayable;
	}

	//Wirtualna metoda aktualizująca obiekt
	void MapPhysical::update(float dt)
	{
		//nothing to do...
	}

	//implementajca metod private:

	//prywatna metoda sprawdza, czy trzeba utworzyć
	//obiekt klasy Displayable (body), np. gdy chcemy
	//dodać obrazek, animację, syntetyk, etc...
	void MapPhysical::checkDisplayable()
	{
		if (!p_displayable)
			p_displayable = gDrawableManager.createDisplayable(Z_GROUND_WORK);
	}
}//namespace mapengine
