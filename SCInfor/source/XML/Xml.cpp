//  ________________________________
// | Xml.cpp - class implementation |
// | Jack Flower -  September 2012  |
// |________________________________|
//

#include "Xml.h"
#include "../Utilities/StringUtils/StringUtils.h"

using namespace stringutils;
using namespace rapidxml;

namespace xml
{
	//Konstruktor domyślny
	Xml::Xml(std::string filename, std::string root)
	:
		m_xml_document{},
		m_xml_root{ nullptr },
		m_filename{ filename },
		m_file{ nullptr }
	{
		try//próba utworzenia i otwarcia pliku
		{
			//tworzymy nowy plik i otwieramy jego zawartość
			m_file = new file<>(filename.c_str());
			
			//przepisujemy zawartość pliku do dokumentu xml (parsujemy)
			m_xml_document.parse<parse_declaration_node>(m_file->data());
			
			//ustawiamy się na głównym węźle pliku xml "root"								  
			m_xml_root = m_xml_document.first_node(root.c_str()); 
																
		}
		catch(std::runtime_error & ex)
		{
			fprintf(stderr, "Error while reading file %s: %s\n", filename.c_str(), ex.what());
		}
	}

	//Destruktor
	Xml::~Xml()
	{
		if (m_file != nullptr)
			delete m_file;
	}

	//Metoda zwraca wskaźnik na węzeł root dokumentu
	xml_node<> *Xml::getRootNode()
	{
		return m_xml_root;
	}

	//Metoda zwraca nazwę pliku
	const std::string & Xml::getFilename() const
	{
		return m_filename;
	}

	//Metoda zwraca wskaźnik na węzeł dzieci
	xml_node<> *Xml::getChild(xml_node<> *parent, const std::string & node_name)
	{
		xml_node<>* real_parent = parent ? parent : m_xml_root;
		if (real_parent)
			return real_parent->first_node(node_name.c_str());
		return nullptr;
	}

	//Metoda zwraca wskaźnik na węzeł rodzeństwa
	xml_node<> *Xml::getSibling(xml_node<> *sibling, const std::string & node_name)
	{
		if (sibling)
			return sibling->next_sibling(node_name.c_str());
		return nullptr;
	}

	//Metoda zwraca atrybut wskazanego typu
	bool Xml::getBool(xml_node<> *parent, const std::string & attrib_name, bool default_value)
	{
		bool out = default_value;
		xml_node<>* real_parent = parent ? parent : m_xml_root;
		std::string attr_value;
	    
		if (real_parent)
		{
			if (attrib_name == "")
			{
				if (real_parent->first_node())
				{
					attr_value = real_parent->first_node()->value();
					FromString(attr_value, out);
				}
			}
			else
				if (xml_attribute<>* attr = real_parent->first_attribute(attrib_name.c_str()))
				{
					attr_value = attr->value();
					out = (attr_value == "true");
					FromString(attr_value, out);
				}
		}
		return out;
	}

	//Metoda zwraca atrybut wskazanego typu
	bool Xml::getBool(const std::string & node_name, const std::string & attrib_name, bool default_value)
	{
		if (m_xml_root)
			return getBool(m_xml_root->first_node(node_name.c_str()), attrib_name, default_value);
		return default_value;
	}

	//Metoda zwraca atrybut wskazanego typu
	int Xml::getInt(xml_node<> *parent, const std::string & attrib_name, int default_value)
	{
		int out = default_value;
		xml_node<>* real_parent = parent ? parent : m_xml_root;
		std::string attr_value;
	    
		if (real_parent)
		{
			if (attrib_name == "")
			{
				if (real_parent->first_node())
				{
					attr_value = real_parent->first_node()->value();
					FromString(attr_value, out);
				}
			}
			else
				if (xml_attribute<>* attr = real_parent->first_attribute(attrib_name.c_str()))
				{
					attr_value = attr->value();
					FromString(attr_value, out);
				}
		}
		return out;
	}

	//Metoda zwraca atrybut wskazanego typu
	int Xml::getInt(const std::string & node_name, const std::string & attrib_name, int default_value)
	{
		if (m_xml_root)
			return getInt(m_xml_root->first_node(node_name.c_str()), attrib_name, default_value);
		return default_value;
	}


	//Metoda zwraca atrybut wskazanego typu
	float Xml::getFloat(xml_node<> *parent, const std::string & attrib_name, float default_value)
	{
		float out = default_value;
		xml_node<>* real_parent = parent ? parent : m_xml_root;
		std::string attr_value;
	    
		if (real_parent)
		{
			if (attrib_name == "")
			{
				if (real_parent->first_node())
				{
					attr_value = real_parent->first_node()->value();
					FromString(attr_value, out);
				}
			}
			else
				if (xml_attribute<>* attr = real_parent->first_attribute(attrib_name.c_str()))
				{
					attr_value = attr->value();
					FromString( attr_value, out );
				}
		}
		return out;
	}

	//Metoda zwraca atrybut wskazanego typu
	float Xml::getFloat(const std::string & node_name, const std::string & attrib_name, float default_value)
	{
		if (m_xml_root)
			return getFloat(m_xml_root->first_node(node_name.c_str()), attrib_name, default_value);
		return default_value;
	}

	//Metoda zwraca atrybut wskazanego typu
	std::string Xml::getString(xml_node<> *parent, const std::string & attrib_name)
	{
		xml_node<>* real_parent = parent ? parent : m_xml_root;

		if (real_parent)
		{
			if (attrib_name == "")
			{
				if (real_parent->first_node())
					return real_parent->first_node()->value();
			}
			else if (xml_attribute<>* attr = real_parent->first_attribute(attrib_name.c_str()))
			{
				std::string out = attr->value();
				return out;
			}
		}
		return "";
	}

	//Metoda zwraca atrybut wskazanego typu
	std::string Xml::getString(const std::string & node_name, const std::string & attrib_name)
	{
		if (m_xml_root)
			return getString(m_xml_root->first_node(node_name.c_str()), attrib_name);
		return "";
	}

	//Metoda zwraca atrybut wskazanego typu
	std::wstring Xml::getWString(xml_node<> *parent, const std::string &attrib_name)
	{
		xml_node<>* real_parent = parent ? parent : m_xml_root;

		if (real_parent)
		{
			if (attrib_name == "")
			{
				if (real_parent->first_node())
					return ConvertToWString(real_parent->first_node()->value());
			}
			else if (xml_attribute<>* attr = real_parent->first_attribute(attrib_name.c_str()))
			{
				std::string out = attr->value();
				return ConvertToWString(out);
			}
		}
		return L"";
	}

	//Metoda zwraca atrybut wskazanego typu
	std::wstring Xml::getWString(const std::string & node_name, const std::string & attrib_name)
	{
		if (m_xml_root)
			return getWString(m_xml_root->first_node(node_name.c_str()), attrib_name);
		return L"";
	}
}//namespace xml
