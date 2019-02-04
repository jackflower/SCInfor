//  _________________________________________________
// | CMapPhysicalTemplate.cpp - class implementation |
// | Jack Flower - March 2015                        |
// |_________________________________________________|


#include "CMapPhysicalTemplate.h"

namespace factory
{
	RTTI_IMPL(CMapPhysicalTemplate, IResource);

	//Konstruktor
	CMapPhysicalTemplate::CMapPhysicalTemplate()
	:
		IResource					(),//konstruktor klasy bazowej
		m_templ_filename			(),
		m_templ_type				(),
		m_templ_code				(),
		m_templ_displayable_type	(),
		m_texture_name				(),
		m_texture_width				(0),
		m_texture_height			(0),
		m_color						(),
		m_animation_name			(),
		m_templ_scale				(0.0f, 0.0f),
		m_templ_rotation			(0.0f),
		m_templ_size				(0.0f, 0.0f),
		m_templ_smooth				(false)
	{
	}

	//Konstruktor kopiuj¹cy
	CMapPhysicalTemplate::CMapPhysicalTemplate(const CMapPhysicalTemplate & CMapPhysicalTemplateCopy)
	:
		IResource					(CMapPhysicalTemplateCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_templ_filename			(CMapPhysicalTemplateCopy.m_templ_filename),
		m_templ_type				(CMapPhysicalTemplateCopy.m_templ_type),
		m_templ_code				(CMapPhysicalTemplateCopy.m_templ_code),
		m_templ_displayable_type	(CMapPhysicalTemplateCopy.m_templ_displayable_type),
		m_texture_name				(CMapPhysicalTemplateCopy.m_texture_name),
		m_texture_width				(CMapPhysicalTemplateCopy.m_texture_width),
		m_texture_height			(CMapPhysicalTemplateCopy.m_texture_height),
		m_color						(CMapPhysicalTemplateCopy.m_color),
		m_animation_name			(CMapPhysicalTemplateCopy.m_animation_name),
		m_templ_scale				(CMapPhysicalTemplateCopy.m_templ_scale),
		m_templ_rotation			(CMapPhysicalTemplateCopy.m_templ_rotation),
		m_templ_size				(CMapPhysicalTemplateCopy.m_templ_size),
		m_templ_smooth				(CMapPhysicalTemplateCopy.m_templ_smooth)
	{
	}

	//Destruktor wirtualny
	CMapPhysicalTemplate::~CMapPhysicalTemplate()
	{
		//IResource					not edit
		m_templ_filename			= "";
		m_templ_type				= "";
		m_templ_code				= "";
		m_templ_displayable_type	= "";
		m_texture_name				= "";
		m_texture_width				= 0;
		m_texture_height			= 0;
		//m_color					not edit
		m_animation_name			= "";
		m_templ_scale.x				= 0.0f;
		m_templ_scale.y				= 0.0f;
		m_templ_rotation			= 0.0f;
		m_templ_size.x				= 0.0f;
		m_templ_size.y				= 0.0f;
		m_templ_smooth				= false;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CMapPhysicalTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CMapPhysicalTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CMapPhysicalTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CMapPhysicalTemplate::Load(CXml &xml)
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
		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Wirtualna metoda tworzenie obiektów pochodnych klasy CMapPhysical
	CMapPhysical* CMapPhysicalTemplate::Create(std::wstring id)
	{
		CMapPhysical* mapphysical = gMapPhysicalManager.CreateMapPhysical(id);
		Fill(mapphysical);
		return mapphysical;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CMapPhysicalTemplate::Fill(CMapPhysical *mapphysical)
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

	//Metoda zwraca nazwê pliku zasobu
	const std::string& CMapPhysicalTemplate::GetFilename() const
	{
		return m_templ_filename;
	}

	//Metoda ustawia nazwê pliku zasobu
	void CMapPhysicalTemplate::setFilename(const std::string& templ_filename)
	{
		m_templ_filename = templ_filename;
	}

	//Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
	const std::string CMapPhysicalTemplate::getType() const
	{
		return m_templ_type;
	}

	//Metoda ustawia typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
	void CMapPhysicalTemplate::setType(const std::string& templ_type)
	{
		m_templ_type = templ_type;
	}

	//Metoda zwraca nazwê kodu dla typu pod³o¿a
	const std::string CMapPhysicalTemplate::getCode() const
	{
		return m_templ_code;
	}

	//Metoda ustawia nazwê kodu dla typu pod³o¿a
	void CMapPhysicalTemplate::setCode(const std::string& templ_code)
	{
		m_templ_code = templ_code;
	}

	//Metoda zwraca typ reprezentacji graficznej obiektu
	///
	const std::string CMapPhysicalTemplate::getDisplayableType() const
	{
		return m_templ_displayable_type;
	}

	//Metoda ustawia typ reprezentacji graficznej obiektu
	void CMapPhysicalTemplate::setDisplayableType(const std::string& templ_displayable_type)
	{
		m_templ_displayable_type = templ_displayable_type;
	}
}//namespace factory
