//  __________________________________________
// | FloraTemplate.cpp - class implementation |
// | SCI - March 2014                         |
// |__________________________________________|
//

#include "FloraTemplate.h"
#include "../XML/CXml.h"
#include "../Logic/PhysicalManager.h"

namespace factory
{
	RTTI_IMPL(FloraTemplate, ActorTemplate);

	//Konstruktor
	FloraTemplate::FloraTemplate()
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_rotation_speed_body_template(0.0f),
		m_rotation_speed_head_template(0.0f)
	{
	} 

	//Destruktor wirtualny
	FloraTemplate::~FloraTemplate()
	{
		//~ActorTemplate()
		m_rotation_speed_body_template = 0.0f;
		m_rotation_speed_head_template = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FloraTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void FloraTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool FloraTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool FloraTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy xml zawiera informację, że jest to jakaś roślinność
		if (xml.GetString(xml.GetRootNode(), "type") != "flora")
			return false;

		//sprawdzamy, czy można załadować dane z klasy bazowej
		if (!ActorTemplate::load(xml))
			return false;

		//gdy w klasie Flora bydą dodawane pola
		//to tutaj, w klasie jej fabryki,
		//należay utworzyć takie same pola oraz je uwzględnić

		//ładujemy dane o prędkości obrotu
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "rotation_speed"))
		{
			m_rotation_speed_body_template = xml.GetFloat(node, "rotation_speed_body");
			m_rotation_speed_head_template = xml.GetFloat(node, "rotation_speed_head");
		}

		return true;
	}

	//Metoda tworzy obiekt klasy Flora
	Flora *FloraTemplate::create(std::wstring id)
	{
		Flora *flora = gPhysicalManager.createFlora(id);
		fill(flora);
		return flora;
	}

	//Wirtualna metoda wypełniająca danymi obiekt klasy Flora
	void FloraTemplate::fill(Flora *flora)
	{
		ActorTemplate::fill(flora);
		//ewentualnie reszta
		if(flora)
		{
			flora->setRotationSpeedBody(m_rotation_speed_body_template);
			flora->setRotationSpeedHead(m_rotation_speed_head_template);
		}
	}
}//namespace factory
