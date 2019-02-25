//  ________________________________________________
// | MapObjectDescriptor.cpp - class implementation |
// | Jack Flower April 2013                         |
// |________________________________________________|
//

#include "MapObjectDescriptor.h"
#include "../../Factory/PhysicalTemplate.h"
#include "../../Utilities/StringUtils/StringUtils.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(MapObjectDescriptor);

	//Konstruktor
	MapObjectDescriptor::MapObjectDescriptor()
	:
		m_code(""),
		m_name(""),
		p_templ(NULL),
		m_x_position(0.0f),
		m_y_position(0.0f),
		m_rotation_body(0),
		m_rotation_head(0),
		m_uniqueId(0),
		m_smooth(false)
	{
		m_uniqueId = nextId++; //unikalna wartość identyfikatora zwiększana w konstruktorze
	}
	
	//Konstruktor kopiujący
	MapObjectDescriptor::MapObjectDescriptor(const MapObjectDescriptor & MapObjectDescriptorCopy)
	:
		m_code(MapObjectDescriptorCopy.m_code),
		m_name(MapObjectDescriptorCopy.m_name),
		p_templ(MapObjectDescriptorCopy.p_templ),
		m_x_position(MapObjectDescriptorCopy.m_x_position),
		m_y_position(MapObjectDescriptorCopy.m_y_position),
		m_rotation_body(MapObjectDescriptorCopy.m_rotation_body),
		m_rotation_head(MapObjectDescriptorCopy.m_rotation_head),
		m_uniqueId(MapObjectDescriptorCopy.m_uniqueId),
		m_smooth(MapObjectDescriptorCopy.m_smooth)
	{
	}

	//Destruktor
	MapObjectDescriptor::~MapObjectDescriptor()
	{
		m_code = "";
		m_name = "";
		p_templ = NULL;
		m_x_position = 0.0f;
		m_y_position = 0.0f;
		m_rotation_body = 0;
		m_rotation_head = 0;
		m_uniqueId = 0;
		m_smooth = false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapObjectDescriptor::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda tworzy obiekt mapy
	void MapObjectDescriptor::create()
	{
		Physical *phys = p_templ->create(stringutils::ConvertToWString(m_name));
		if (phys != 0)
		{
			phys->setPosition(sf::Vector2f(m_x_position, m_y_position));
			phys->setRotationBody(m_rotation_body);
			phys->setRotationHead(m_rotation_head);
			phys->setSmoothing(m_smooth);
		}
	}

	//Metoda zwraca nazwę znacznika obiektu na mapie
	const std::string & MapObjectDescriptor::getCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazwę znacznika obiektu na mapie
	void MapObjectDescriptor::setCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca nazwę, którą nadajemy obiektowi
	const std::string & MapObjectDescriptor::getName() const
	{
		return m_name;
	}

	//Metoda ustawia nazwę, którą nadajemy obiektowi
	void MapObjectDescriptor::setName(const std::string & name)
	{
		m_name = name;
	}


	//Metoda zwraca wskaźnik na wzorzec produkcyjny
	PhysicalTemplate* MapObjectDescriptor::getTemplate() const
	{
		return p_templ;
	}

	//Metoda ustawia wskaźnik na wzorzec produkcyjny
	void MapObjectDescriptor::setTemplate(PhysicalTemplate *template_param)
	{
		p_templ = template_param;
	}

	//Metoda zwraca pozycję obietu - składowa X (plik xml operuje body)
	const float MapObjectDescriptor::getXPosition() const
	{
		return m_x_position;
	}

	//Metoda ustawia pozycję obietu - składowa X (plik xml operuje body)
	void MapObjectDescriptor::setXPosition(float x_position)
	{
		m_x_position = x_position;
	}

	//Metoda zwraca pozycję obietu - składowa Y (plik xml operuje body)
	const float MapObjectDescriptor::getYPosition() const
	{
		return m_y_position;
	}

	//Metoda ustawia pozycję obietu - składowa Y (plik xml operuje body)
	void MapObjectDescriptor::setYPosition(float y_position)
	{
		m_y_position = y_position;
	}

	//Metoda zwraca obrót obiektu - body
	const float MapObjectDescriptor::getRotationBody() const
	{
		return m_rotation_body;
	}

	//Metoda ustawia obrót obiektu - body
	void MapObjectDescriptor::setRotationBody(float rotation_body)
	{
		m_rotation_body = rotation_body;
	}

	//Metoda zwraca obrót obiektu - head
	const float MapObjectDescriptor::getRotationHead() const
	{
		return m_rotation_head;
	}

	//Metoda ustawia obrót obiektu - head
	void MapObjectDescriptor::setRotationHead(float rotation_head)
	{
		m_rotation_head = rotation_head;
	}

	//Metoda zwraca flaga filtru grafiki - smooth
	const bool MapObjectDescriptor::getSmooth() const
	{
		return m_smooth;
	}
		
	//Metoda ustawia flaga filtru grafiki - smooth
	void MapObjectDescriptor::setSmooth(bool smooth)
	{
		m_smooth = smooth;
	}

	const int MapObjectDescriptor::getUniqueId() const
	{
		return m_uniqueId;
	}

}//namespace mapengine

//Nadanie wartości stałym składowum statycznym
int mapengine::MapObjectDescriptor::nextId = 1;
