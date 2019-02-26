//  ________________________________________________
// | MapPhysicalTemplate.cpp - class implementation |
// | Jack Flower - March 2015                       |
// |________________________________________________|


#include "MapPhysicalTemplate.h"

namespace factory
{
	RTTI_IMPL(MapPhysicalTemplate, Resource);

	//Konstruktor
	MapPhysicalTemplate::MapPhysicalTemplate()
	:
		Resource(),//konstruktor klasy bazowej
		m_templ_filename(),
		m_templ_type(),
		m_templ_code(),
		m_templ_displayable_type(),
		m_texture_name(),
		m_texture_width(0),
		m_texture_height(0),
		m_color(),
		m_animation_name(),
		m_templ_scale(0.0f, 0.0f),
		m_templ_rotation(0.0f),
		m_templ_size(0.0f, 0.0f),
		m_templ_smooth(false)
	{
	}

	//Konstruktor kopiujący
	MapPhysicalTemplate::MapPhysicalTemplate(const MapPhysicalTemplate & MapPhysicalTemplateCopy)
	:
		Resource(MapPhysicalTemplateCopy),//konstruktor kopiujący klasy bazowej
		m_templ_filename(MapPhysicalTemplateCopy.m_templ_filename),
		m_templ_type(MapPhysicalTemplateCopy.m_templ_type),
		m_templ_code(MapPhysicalTemplateCopy.m_templ_code),
		m_templ_displayable_type(MapPhysicalTemplateCopy.m_templ_displayable_type),
		m_texture_name(MapPhysicalTemplateCopy.m_texture_name),
		m_texture_width(MapPhysicalTemplateCopy.m_texture_width),
		m_texture_height(MapPhysicalTemplateCopy.m_texture_height),
		m_color(MapPhysicalTemplateCopy.m_color),
		m_animation_name(MapPhysicalTemplateCopy.m_animation_name),
		m_templ_scale(MapPhysicalTemplateCopy.m_templ_scale),
		m_templ_rotation(MapPhysicalTemplateCopy.m_templ_rotation),
		m_templ_size(MapPhysicalTemplateCopy.m_templ_size),
		m_templ_smooth(MapPhysicalTemplateCopy.m_templ_smooth)
	{
	}

	//Destruktor wirtualny
	MapPhysicalTemplate::~MapPhysicalTemplate()
	{
		//Resource
		m_templ_filename = "";
		m_templ_type = "";
		m_templ_code = "";
		m_templ_displayable_type = "";
		m_texture_name = "";
		m_texture_width = 0;
		m_texture_height = 0;
		//m_color
		m_animation_name = "";
		m_templ_scale.x = 0.0f;
		m_templ_scale.y = 0.0f;
		m_templ_rotation = 0.0f;
		m_templ_size.x = 0.0f;
		m_templ_size.y = 0.0f;
		m_templ_smooth = false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string MapPhysicalTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void MapPhysicalTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool MapPhysicalTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool MapPhysicalTemplate::load(Xml & xml)
	{
		//nazwa pliku xml
		m_templ_filename = xml.getFilename();

		//typ obiektu - ResourceManager - na tej podstawie tworzy MapPhysical
		if (xml_node<> *node = xml.getRootNode())
			m_templ_type = xml.getString(node, "type");

		//odczyt konfiguracji i danych dla obiektu
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "mapphysical_config"))
		{
			m_templ_code = xml.getString(node, "code");
			m_templ_displayable_type = xml.getString(node, "displayable_type");
			m_texture_name = xml.getString(node, "texture_name");
			m_texture_width = xml.getInt(node, "texture_width");
			m_texture_height = xml.getInt(node, "texture_height");
			m_color.r = xml.getInt(node, "color_r");
			m_color.g = xml.getInt(node, "color_g");
			m_color.b = xml.getInt(node, "color_b");
			m_color.a = xml.getInt(node, "color_a");
			m_animation_name = xml.getString(node, "animation_name");
			m_templ_scale.x = xml.getFloat(node, "scale_x");
			m_templ_scale.y = xml.getFloat(node, "scale_y");
			m_templ_rotation = xml.getFloat(node, "rotation");
			m_templ_size.x = xml.getFloat(node, "size_x");
			m_templ_size.y = xml.getFloat(node, "size_y");
			m_templ_smooth = xml.getBool(node, "smooth");
		}
		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Wirtualna metoda tworzenie obiektów pochodnych klasy MapPhysical
	MapPhysical* MapPhysicalTemplate::create(std::wstring id)
	{
		MapPhysical *mapphysical = gMapPhysicalManager.createMapPhysical(id);
		fill(mapphysical);
		return mapphysical;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void MapPhysicalTemplate::fill(MapPhysical *mapphysical)
	{
		if(mapphysical)
		{
			if (m_templ_displayable_type == "image")
				mapphysical->setImage(m_texture_name);
			else if(m_templ_displayable_type == "synthetic")
				mapphysical->setImage(m_texture_width, m_texture_height, m_color);
			else if(m_templ_displayable_type == "animation")
				mapphysical->setAnimation(m_animation_name);
			else
				//synthetic...
				mapphysical->setImage(m_texture_width, m_texture_height, m_color);
			
			mapphysical->setScale(m_templ_scale);
			mapphysical->setRotation(m_templ_rotation);
			mapphysical->setSize(m_templ_size);
			mapphysical->setTemplate(this);
			mapphysical->setSmooth(m_templ_smooth);
		}
	}

	//Metoda zwraca nazwę pliku zasobu
	const std::string& MapPhysicalTemplate::getFilename() const
	{
		return m_templ_filename;
	}

	//Metoda ustawia nazwę pliku zasobu
	void MapPhysicalTemplate::setFilename(const std::string & templ_filename)
	{
		m_templ_filename = templ_filename;
	}

	//Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
	const std::string MapPhysicalTemplate::getTypeName() const
	{
		return m_templ_type;
	}

	//Metoda ustawia typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
	void MapPhysicalTemplate::setTypeName(const std::string & templ_type)
	{
		m_templ_type = templ_type;
	}

	//Metoda zwraca nazwę kodu dla typu podłoża
	const std::string MapPhysicalTemplate::getCode() const
	{
		return m_templ_code;
	}

	//Metoda ustawia nazwę kodu dla typu podłoża
	void MapPhysicalTemplate::setCode(const std::string & templ_code)
	{
		m_templ_code = templ_code;
	}

	//Metoda zwraca typ reprezentacji graficznej obiektu
	///
	const std::string MapPhysicalTemplate::getDisplayableType() const
	{
		return m_templ_displayable_type;
	}

	//Metoda ustawia typ reprezentacji graficznej obiektu
	void MapPhysicalTemplate::setDisplayableType(const std::string & templ_displayable_type)
	{
		m_templ_displayable_type = templ_displayable_type;
	}
}//namespace factory
