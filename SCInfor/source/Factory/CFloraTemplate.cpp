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
	void CFloraTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CFloraTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CFloraTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy xml zawiera informacjê, ¿e jest to jakaœ roœlinnoœæ
		if (xml.GetString(xml.GetRootNode(), "type") != "flora")
			return false;

		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej
		if (!CActorTemplate::Load(xml))
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
	CFlora* CFloraTemplate::Create(std::wstring id)
	{
		CFlora* flora = gPhysicalManager.CreateFlora(id);
		Fill(flora);
		return flora;
	}

	//Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CFlora
	void CFloraTemplate::Fill(CFlora *flora)
	{
		CActorTemplate::Fill(flora);
		//ewentualnie reszta
		if(flora)
		{
			flora->setRotationSpeedBody(m_rotation_speed_body_template);
			flora->setRotationSpeedHead(m_rotation_speed_head_template);
		}
	}
}//namespace factory