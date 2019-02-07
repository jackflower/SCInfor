//  ___________________________________________
// | CFloraTemplate.cpp - class implementation |
// | SCI - March 2014                          |
// |___________________________________________|
//

#include "CFloraTemplate.h"
#include "../XML/CXml.h"
#include "../Logic/CPhysicalManager.h"

namespace factory
{
	//Konstruktor
	CFloraTemplate::CFloraTemplate()
	:
		CActorTemplate					(),//konstruktor klasy bazowej
		m_rotation_speed_body_template	(0.0f),
		m_rotation_speed_head_template	(0.0f)
	{
	} 

	//Destruktor wirtualny
	CFloraTemplate::~CFloraTemplate()
	{
		m_rotation_speed_body_template = 0.0f;
		m_rotation_speed_head_template = 0.0f;
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CFloraTemplate::drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CFloraTemplate::load(const std::string &name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CFloraTemplate::load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest to jakaœ roœlinnoœæ
		if (xml.GetString(xml.GetRootNode(), "type") != "flora")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::load(xml))
			return false;

		//gdy w klasie CFlora byd¹ dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale¿ay utworzyæ takie same pola oraz je uwzglêdniæ

		//³adujemy dane o prêdkoœci obrotu
		if (xml_node<>*	node = xml.GetChild(xml.GetRootNode(), "rotation_speed"))
		{
			m_rotation_speed_body_template = xml.GetFloat(node, "rotation_speed_body");
			m_rotation_speed_head_template = xml.GetFloat(node, "rotation_speed_head");
		}

		return true;
	}

	//Metoda tworzy obiekt klasy CFlora
	CFlora* CFloraTemplate::create(std::wstring id)
	{
		CFlora* flora = gPhysicalManager.CreateFlora(id);
		fill(flora);
		return flora;
	}

	//Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CFlora
	void CFloraTemplate::fill(CFlora *flora)
	{
		CActorTemplate::fill(flora);
		//ewentualnie reszta
		if(flora)
		{
			flora->setRotationSpeedBody(m_rotation_speed_body_template);
			flora->setRotationSpeedHead(m_rotation_speed_head_template);
		}
	}
}//namespace factory