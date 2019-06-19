//  __________________________________________
// | MapObjectType.cpp - class implementation |
// | Jack Flower April 2013                   |
// |__________________________________________|
//

#include "MapObjectType.h"

namespace mapengine
{
	RTTI_IMPL_NOPARENT(MapObjectType);

	//Konstruktor
	MapObjectType::MapObjectType()
	:
		m_code{ "" },
		p_template{ nullptr }
	{
	}

	//Konstruktor kopiujący
	MapObjectType::MapObjectType(const MapObjectType & MapObjectTypeCopy)
	:
		m_code{ MapObjectTypeCopy.m_code },
		p_template{ MapObjectTypeCopy.p_template }
	{
	}

	//Destruktor
	MapObjectType::~MapObjectType()
	{	
		m_code = "";
		p_template = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapObjectType::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca nazwę znacznika obiektu na mapie
	const std::string & MapObjectType::getCode() const
	{
		return m_code;
	}

	//Metoda ustawia nazwę znacznika obiektu na mapie
	void MapObjectType::setCode(const std::string & code)
	{
		m_code = code;
	}

	//Metoda zwraca wskaźnik na wzorzec danych
	PhysicalTemplate *MapObjectType::getTemplate() const
	{
		return p_template;
	}

	//Metoda ustawia wskaźnik na wzorzec danych
	void MapObjectType::setTemplate(PhysicalTemplate *template_param)
	{
		p_template = template_param;
	}
}//namespace mapengine
