/*
 ______________________________________________
| CRegionDescriptor.cpp - implementacja klasy. |
| Jack Flower June 2013.                       |
|______________________________________________|

*/

#include "CRegionDescriptor.h"
#include "../Logic/CPhysicalManager.h"
#include "../Logic/MapObjects/CRegion.h"
#include "../Utilities/StringUtils/StringUtils.h"
#include "../Logic/Conditions/CCondition.h"
//#include "../Logic/Effects/CEffectManager.h"
//#include "../Logic/Effects/CEffectHandle.h"

#include <cstdio>

namespace mapengine
{
	RTTI_IMPL_NOPARENT(CRegionDescriptor);

	//Konstruktor
	CRegionDescriptor::CRegionDescriptor(const std::string & region_name, const sf::Vector2f position, float m_scale)
	:
		m_region_name					(region_name),
		m_region_descriptor_position	(position),
		p_condition						(NULL),
		m_next_map						(""),
		m_next_map_region				(""),
		m_rotation						(0.0f),
		m_scale							(m_scale),
		p_effect						(NULL)
	{
		static int nextId = 1;
		m_uniqueId = nextId++;
		if (m_region_name == "")//jeœli nazwa nie jest znana/wczytana  - tworzona jest nazwa zsyntetyzowana
			m_region_name = "region" + stringutils::ToString(m_uniqueId);
	}

	//Destruktor wirtualny
	CRegionDescriptor::~CRegionDescriptor()
	{
		m_region_name					= "";
		//m_region_descriptor_position	not edit
		p_condition						= NULL;
		m_next_map						= "";
		m_next_map_region				= "";
		m_rotation						= 0.0f;
		m_scale							= 0.0f;
		p_effect						= NULL;
		m_uniqueId						= 0;

		printf("destroying region descriptor %s\n", m_region_name.c_str());
	}

	//Metoda tworzy wskaŸnik na obiekt klasy CRegion
	CRegion *CRegionDescriptor::Create()
	{
		CRegion *p_region_decriptor = gPhysicalManager.CreateRegion(stringutils::ConvertToWString(m_region_name));
		p_region_decriptor->SetPosition(m_region_descriptor_position);
		if (m_next_map != "")
		{
			p_region_decriptor->SetNextMap(&m_next_map);
			if (m_next_map_region != "")
				p_region_decriptor->SetNextMapRegion(&m_next_map_region);
		}
		p_region_decriptor->SetCondition(p_condition);
		p_region_decriptor->SetEffectOnEnter(p_effect);
		p_region_decriptor->SetRotation(m_rotation);
		p_region_decriptor->SetScale(m_scale);
		p_region_decriptor->SetDescriptorId(m_uniqueId);
		return p_region_decriptor;
	}

	//Metoda ³aduje dane z pliku xml
	void CRegionDescriptor::Load(CXml &xml, xml_node<> *node)
	{
		/*
		xml_node<> *n = xml.GetChild(node,"next-map");
		if (n) 
			m_next_map = xml.GetString(n);
		n = xml.GetChild(node,"next-map-region");
		if (n)
			m_next_map_region = xml.GetString(n);
		n = xml.GetChild(node,"p_condition");
		if (n!=NULL){
			p_condition = new CCondition();
			p_condition->Load(xml,n);
		}
		n = xml.GetChild(node,"p_effect-on-enter");
		if (n != NULL){
			p_effect = gEffectManager.LoadEffect(xml,n);
		}
		m_rotation = xml.GetFloat(node, "m_rotation");
		*/
	}

	//Metoda serializuje obiekt
	void CRegionDescriptor::Serialize(std::ostream &out, int indent)
	{
		for (int i = 0; i < indent; ++i, out << "\t");
		out << "<region name=\"" << m_region_name << "\" x=\""
			<< m_region_descriptor_position.x << "\" y=\"" << m_region_descriptor_position.y << "\" m_rotation=\"" << m_rotation << "\" m_scale=\"" << m_scale << "\">\n";
		if (m_next_map != ""){
			for (int i = 0; i < indent + 1; ++i, out << "\t");
			out << "<next-map>" << m_next_map << "</next-map>\n";
			for (int i = 0; i < indent + 1; ++i, out << "\t");
			out << "<next-map-region>" << m_next_map_region << "</next-map-region>\n";
		}
		if (p_condition != NULL){
			p_condition->Serialize(out, indent + 1);
		}
		for (int i = 0; i < indent; ++i, out << "\t");
		out << "</region>\n";
	}

	//Metoda zwraca std::string zserializowanego obiektu
	const std::string CRegionDescriptor::Serialize()
	{
		std::stringstream ss;
		Serialize(ss, 0);
		return ss.str();
	}

	//Nadanie wartoœci sta³ym sk³adowum statycznym
	//int CRegionDescriptor::nextId = 1;
}//namespace mapengine