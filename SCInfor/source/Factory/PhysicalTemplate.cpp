//  _____________________________________________
// | PhysicalTemplate.cpp - class implementation |
// | Jack Flower - November 2012                 |
// |_____________________________________________|
//

#include "PhysicalTemplate.h"

namespace factory
{
	RTTI_IMPL(PhysicalTemplate, Resource);

	//Konstruktor
	PhysicalTemplate::PhysicalTemplate()
	:
		Resource(),//konstruktor klasy bazowej
		m_templ_filename(),
		m_templ_type(),
		m_templ_genre(),
		m_templ_circle_radius(0.0f),
		m_templ_rect_size(1.0f, 1.0f),
		m_templ_rect_size_body(1.0f, 1.0f),
		m_templ_rect_size_head(1.0f, 1.0f),
		m_templ_texture_body(),
		m_templ_texture_head(),
		m_templ_altitude(1.0f),
		m_templ_use_displayable_body(false),
		m_templ_use_shadow_body(false),
		m_templ_use_displayable_head(false),
		m_templ_use_shadow_head(false),
		m_templ_color_body(sf::Color()),
		m_templ_color_head(sf::Color()),
		m_templ_scale_body(1.0f),
		m_templ_scale_head(1.0f),
		m_templ_part_collision_data()
	{
	}

	//Destruktor
	PhysicalTemplate::~PhysicalTemplate()
	{
		//~Resource()
		m_templ_filename = "";
		m_templ_type = "";
		m_templ_genre = L"";
		m_templ_circle_radius = 0.0f;
		//m_templ_rect_size
		m_templ_rect_size_body.x = 0.0;
		m_templ_rect_size_body.y = 0.0;
		m_templ_rect_size_head.x = 0.0;
		m_templ_rect_size_head.y = 0.0;
		m_templ_texture_body = "";
		m_templ_texture_head = "";
		m_templ_altitude = 0.0f;
		m_templ_use_displayable_body = false;
		m_templ_use_shadow_body = false;
		m_templ_use_displayable_head = false;
		m_templ_use_shadow_head = false;
		//m_templ_color_body
		//m_templ_color_head
		m_templ_scale_body = 0.0f;
		m_templ_scale_head = 0.0f;
		//m_templ_part_collision_data
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PhysicalTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda ładująca dane
	bool PhysicalTemplate::load(const std::string & name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool PhysicalTemplate::load(CXml & xml)
	{
		//nazwa pliku xml
		m_templ_filename = xml.GetFilename();

		//typ obiektu
		if (xml_node<> *node = xml.GetRootNode())
			m_templ_type = xml.GetString(node, "type");

		//nazwa "gatunku" obiektu (np. robot, human, gun, etc...)
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "genre"))
			m_templ_genre = xml.GetWString(node, "genre");

		//zakres promienia detekcji kolizji
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "radius"))
		{
			m_templ_circle_radius = xml.GetFloat(node, "circle_radius");
		}

		//wektor przechowujący rozmiar obszaru prostokątnego
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "rect_size"))
		{
			m_templ_rect_size.x = xml.GetFloat(node, "rect_size_x");
			m_templ_rect_size.y = xml.GetFloat(node, "rect_size_y");
		}

		//wektor przechowujący rozmiar obszaru prostokątnego
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "rect_size"))
		{
			//body
			m_templ_rect_size_body.x = xml.GetFloat(node, "rect_size_body_x");
			m_templ_rect_size_body.y = xml.GetFloat(node, "rect_size_body_y");
			//head
			m_templ_rect_size_head.x = xml.GetFloat(node, "rect_size_head_x");
			m_templ_rect_size_head.y = xml.GetFloat(node, "rect_size_head_y");
		}

		//skala obiektu (body and head)
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "scale"))
		{
			m_templ_scale_body = xml.GetFloat(node, "scale_body");
			m_templ_scale_head = xml.GetFloat(node, "scale_head");
		}

		//wartość pułapu obiektu względem podłoża
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "altitude"))
		{
			m_templ_altitude = xml.GetFloat(node, "altitude");
		}

		//pola konfiguracyjne - potrzebne przy podejmowaniu decyzji - wygląd obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "physical_config"))
		{
			m_templ_use_displayable_body = xml.GetBool(node, "use_displayable_body");
			m_templ_use_shadow_body = xml.GetBool(node, "use_shadow_body");
			m_templ_use_displayable_head = xml.GetBool(node, "use_displayable_head");
			m_templ_use_shadow_head = xml.GetBool(node, "use_shadow_head");
		}
		
		//konfiguraja koloru
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "physical_color"))
		{
			m_templ_color_body.r = xml.GetInt(node, "color_body_r");
			m_templ_color_body.g = xml.GetInt(node, "color_body_g");
			m_templ_color_body.b = xml.GetInt(node, "color_body_b");
			m_templ_color_body.a = xml.GetInt(node, "color_body_a");

			m_templ_color_head.r = xml.GetInt(node, "color_head_r");
			m_templ_color_head.g = xml.GetInt(node, "color_head_g");
			m_templ_color_head.b = xml.GetInt(node, "color_head_b");
			m_templ_color_head.a = xml.GetInt(node, "color_head_a");
		}

		//ładowanie danych reprezentacji graficznej - obrazy statyczne
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "static_image"))
		{
			m_templ_texture_body = xml.GetString(node, "image_name_body");
			m_templ_texture_head = xml.GetString(node, "image_name_head");
		}

		//konfiguraja danych o kolidowaniu poszczególnych części, z których składa się obiekt
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "colliding_config"))
		{
			m_templ_part_collision_data.setCollidingBody(xml.GetBool(node, "colliding_body"));
			m_templ_part_collision_data.setCollidingBodyShadow(xml.GetBool(node, "colliding_body_shadow"));
			m_templ_part_collision_data.setCollidingHead(xml.GetBool(node, "colliding_head"));
			m_templ_part_collision_data.setCollidingHeadShadow(xml.GetBool(node, "colliding_head_shadow"));
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void PhysicalTemplate::fill(Physical *physical)
	{
		//ustawienie kompletnego wzorca
		physical->setTemplate(this);

		//nazwa gatunku
		physical->setGenre(m_templ_genre);

		//radius
		physical->setBoundingCircle(m_templ_circle_radius);

		//rectangle size
		physical->setBoundingRect(m_templ_rect_size);

		//rectangle size - synthetic
		//body
		physical->setRectangleSizeBody(m_templ_rect_size_body);
		//head
		physical->setRectangleSizeHead(m_templ_rect_size_head);

		//body scale
		physical->setScaleBody(m_templ_scale_body, m_templ_scale_body);

		//head scale
		physical->setScaleHead(m_templ_scale_head, m_templ_scale_head);

		//altitude - pułap obiektu względem podłoża
		physical->setAltitude(m_templ_altitude);

		//konfiguracja obiektu - body, head, wygląd, cień, etc...
		physical->setUseDisplayableBody(m_templ_use_displayable_body);
		physical->setUseShadowBody(m_templ_use_shadow_body);
		physical->setUseDisplayableHead(m_templ_use_displayable_head);
		physical->setUseShadowHead(m_templ_use_shadow_head);

		//konfiguracja koloru (szczególnie tektury syntetyczne)
		physical->setColorBody(m_templ_color_body);
		physical->setColorHead(m_templ_color_head);

		//konfiguraja danych o kolidowaniu poszczególnych części, z których składa się obiekt
		physical->getPartCollisionData().setCollidingBody(m_templ_part_collision_data.getCollidingBody());
		physical->getPartCollisionData().setCollidingBodyShadow(m_templ_part_collision_data.getCollidingBodyShadow());
		physical->getPartCollisionData().setCollidingHead(m_templ_part_collision_data.getCollidingHead());
		physical->getPartCollisionData().setCollidingHeadShadow(m_templ_part_collision_data.getCollidingHeadShadow());

		//konfiguracja danych reprezentacji graficznej - body
		if (m_templ_use_displayable_body)
		{
			//static image body
			if (m_templ_texture_body != "")
				physical->setTextureBody(m_templ_texture_body);
			else
				//synthetic body
				physical->setTextureBody((unsigned)m_templ_rect_size_body.x, (unsigned)m_templ_rect_size_body.y, m_templ_color_body);
		}

		//konfiguracja danych reprezentacji graficznej - head
		if (m_templ_use_displayable_head)
		{
			//static image head
			if (m_templ_texture_head != "")
				physical->setTextureHead(m_templ_texture_head);
			else
				//synthetic head
				physical->setTextureHead((unsigned)m_templ_rect_size_head.x, (unsigned)m_templ_rect_size_head.y, m_templ_color_head);
		}
	}

}//namespace factory
