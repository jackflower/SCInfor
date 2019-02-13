//  __________________________________________________
// | MapPhysicalDescriptor.cpp - class implementation |
// | Jack Flower - March 2015                         |
// |__________________________________________________|
//

#include "MapPhysicalDescriptor.h"
#include "../../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"
#include "../../Utilities/StringUtils/StringUtils.h"
#include <iostream>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(MapPhysicalDescriptor);

	//Konstruktor
	MapPhysicalDescriptor::MapPhysicalDescriptor()
	:
		p_template(NULL),
		m_unique_id(0),
		m_code(),
		m_name(),
		m_position(0.0f, 0.0f),
		m_scale(1.0f, 1.0f),
		m_rotation(0.0f),
		m_size(0.0f, 0.0f),
		m_smooth(false)
	{
		m_unique_id = nextId++;	//unikalna wartość identyfikatora zwiększana w konstruktorze
		//nazwa z pliku xml, lub liczba wygenerowana...
	}

	//Konstruktor kopiujący
	MapPhysicalDescriptor::MapPhysicalDescriptor(const MapPhysicalDescriptor & MapPhysicalDescriptorCopy)
	:
		p_template(MapPhysicalDescriptorCopy.p_template),
		m_unique_id(MapPhysicalDescriptorCopy.m_unique_id),//zerujemy licznik, czy kopia to kopia?
		m_code(MapPhysicalDescriptorCopy.m_code),
		m_name(MapPhysicalDescriptorCopy.m_name),
		m_position(MapPhysicalDescriptorCopy.m_position),
		m_scale(MapPhysicalDescriptorCopy.m_scale),
		m_rotation(MapPhysicalDescriptorCopy.m_rotation),
		m_size(MapPhysicalDescriptorCopy.m_size),
		m_smooth(MapPhysicalDescriptorCopy.m_smooth)
	{
	}

	//Destruktor
	MapPhysicalDescriptor::~MapPhysicalDescriptor()
	{
		p_template = NULL;
		m_unique_id = 0;
		m_code = "";
		m_name = "";
		m_position.x = 0.0f;
		m_position.y = 0.0f;
		m_scale.x = 0.0f;
		m_scale.x = 0.0f;
		m_rotation = 0.0f;
		m_size.x = 0.0f;
		m_size.y = 0.0f;
		m_smooth = false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapPhysicalDescriptor::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda tworzy obiekt mapy
	void MapPhysicalDescriptor::create()
	{
		MapPhysical *mapphys = p_template->create(stringutils::ConvertToWString(m_name));
		if (mapphys != 0)
		{
			mapphys->setTemplate(p_template);
			mapphys->setCode(m_code);
			mapphys->setPosition(m_position);
			mapphys->setScale(m_scale);
			mapphys->setRotation(m_rotation);
			mapphys->setSize(m_size);
			mapphys->setSmooth(m_smooth);
			mapphys->setVisible(m_visible);
		}
	}

	//Metoda zwraca wskaźnik na wzorzec fabryczny obiektu
	MapPhysicalTemplate *MapPhysicalDescriptor::getTemplate() const
	{ 
		return p_template;
	}

	//Metoda ustawia wskaźnik na wzorzec fabryczny obiektu
	void MapPhysicalDescriptor::setTemplate(MapPhysicalTemplate *template_param)
	{
		p_template = template_param;
	}

	//Metoda zwraca unikalny identyfikator (nadawany w MapPhysicalManager)
	const int MapPhysicalDescriptor::getUniqueId() const
	{
		return m_unique_id;
	}

	//Metoda zwraca referencję na nazwę kodu dla typu podłoża zapisanego w pliku xml
	const std::string & MapPhysicalDescriptor::getCode() const
	{
		return m_code;
	}
		
	//Metoda zwraca nazwę kodu dla typu podłoża zapisanego w pliku xml
	void MapPhysicalDescriptor::setCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca referencję na nazwę własną obiektu nadawaną na poziomie wpisu w pliku xml
	const std::string & MapPhysicalDescriptor::getName() const
	{
		return m_name;
	}

	//Metoda ustawia nazwę własną obiektu nadawaną na poziomie wpisu w pliku xml
	void MapPhysicalDescriptor::setName(const std::string & name)
	{
		m_name = name;
	}

	//Metoda zwraca pozycję obiektu
	///
	const sf::Vector2f & MapPhysicalDescriptor::getPosition() const
	{
		return m_position;
	}

	//Metoda ustawia pozycję obiektu
	void MapPhysicalDescriptor::setPosition(const sf::Vector2f & position)
	{
		m_position = position;
	}

	//Metoda ustawia na pozycję obiektu
	void MapPhysicalDescriptor::setPosition(float position_x, float position_y)
	{
		m_position.x = position_x;
		m_position.y = position_y;
	}

	//Metoda zwraca skalę
	const sf::Vector2f & MapPhysicalDescriptor::getScale() const
	{
		return m_scale;
	}
		
	//Metoda ustawia skalę
	void MapPhysicalDescriptor::setScale(float x, float y)
	{
		m_scale.x = x;
		m_scale.y = y;
	}

	//Metoda ustawia skalę
	void MapPhysicalDescriptor::setScale(const sf::Vector2f & scale)
	{
		m_scale = scale;
	}

	//Metoda ustawia skalę
	void MapPhysicalDescriptor::setScale(float factors)
	{
		m_scale.x = factors;
		m_scale.y = factors;
	}

	//Metoda zwraca wartość obrotu
	float MapPhysicalDescriptor::getRotation() const
	{ 
		return m_rotation;
	}

	//Metoda ustawia wartość obrotu
	void MapPhysicalDescriptor::setRotation(float rotation_value)
	{
		m_rotation = rotation_value;
	}

	//Metoda zwraca rozmiar obiektu
	const sf::Vector2f & MapPhysicalDescriptor::getSize() const
	{
		return m_size;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysicalDescriptor::setSize(const sf::Vector2f & size)
	{
		m_size = size;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysicalDescriptor::setSize(float x, float y)
	{
		m_size.x = x;
		m_size.y = y;
	}

	//Metoda ustawia rozmiar obiektu
	void MapPhysicalDescriptor::setSize(float uniform)
	{
		m_size.x = uniform;
		m_size.y = uniform;
	}

	//Metoda zwraca flagę określającą filtr wygładzający teksturę
	const bool MapPhysicalDescriptor::getSmooth() const
	{
		return m_smooth;
	}

	//Metoda ustawia flagę określającą filtr wygładzający teksturę
	void MapPhysicalDescriptor::setSmooth(bool smooth)
	{
		m_smooth = smooth;
	}

	//Metoda zwraca flagę określającą czy obiekt jest widoczny
	const bool MapPhysicalDescriptor::getVisible() const
	{
		return m_visible;
	}

	//Metoda ustawia flagę określającą czy obiekt będzie widoczny
	void MapPhysicalDescriptor::setVisible(bool visible)
	{
		m_visible = visible;
	}
}//namespace mapengine

//Nadanie wartości stałym składowym statycznym
int mapengine::MapPhysicalDescriptor::nextId = 1;
