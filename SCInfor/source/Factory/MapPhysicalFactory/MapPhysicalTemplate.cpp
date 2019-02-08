//  ________________________________________________
// | MapPhysicalTemplate.cpp - class implementation |
// | Jack Flower - March 2015                       |
// |________________________________________________|


#include "MapPhysicalTemplate.h"

namespace factory
{
	RTTI_IMPL(MapPhysicalTemplate, IResource);

	//Konstruktor
	MapPhysicalTemplate::MapPhysicalTemplate()
	:
		IResource(),//konstruktor klasy bazowej
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
		IResource(MapPhysicalTemplateCopy),//konstruktor kopiujący klasy bazowej
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
		//IResource
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
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void MapPhysicalTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool MapPhysicalTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool MapPhysicalTemplate::load(CXml & xml)
	{
		//nazwa pliku xml
		m_templ_filename = xml.GetFilename();

		//typ obiektu - CResourceManager - na tej podstawie tworzy CMapPhysical
		if (xml_node<> *node = xml.GetRootNode())
			m_templ_type = xml.GetString(node, "type");

		//odczyt konfiguracji i danych dla obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "mapphysical_config"))
		{
			m_templ_code = xml.GetString(node, "code");
			m_templ_displayable_type = xml.GetString(node, "displayable_type");
			m_texture_name = xml.GetString(node, "texture_name");
			m_texture_width = xml.GetInt(node, "texture_width");
			m_texture_height = xml.GetInt(node, "texture_height");
			m_color.r = xml.GetInt(node, "color_r");
			m_color.g = xml.GetInt(node, "color_g");
			m_color.b = xml.GetInt(node, "color_b");
			m_color.a = xml.GetInt(node, "color_a");
			m_animation_name = xml.GetString(node, "animation_name");
			m_templ_scale.x = xml.GetFloat(node, "scale_x");
			m_templ_scale.y = xml.GetFloat(node, "scale_y");
			m_templ_rotation = xml.GetFloat(node, "rotation");
			m_templ_size.x = xml.GetFloat(node, "size_x");
			m_templ_size.y = xml.GetFloat(node, "size_y");
			m_templ_smooth = xml.GetBool(node, "smooth");
		}
		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Wirtualna metoda tworzenie obiektów pochodnych klasy CMapPhysical
	CMapPhysical* MapPhysicalTemplate::create(std::wstring id)
	{
		CMapPhysical *mapphysical = gMapPhysicalManager.CreateMapPhysical(id);
		fill(mapphysical);
		return mapphysical;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void MapPhysicalTemplate::fill(CMapPhysical *mapphysical)
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
			mapphysical->SetTemplate(this);
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

	//Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
	const std::string MapPhysicalTemplate::getTypeName() const
	{
		return m_templ_type;
	}

	//Metoda ustawia typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
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
