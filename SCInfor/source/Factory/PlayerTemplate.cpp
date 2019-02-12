//  ___________________________________________
// | PlayerTemplate.cpp - class implementation |
// | Jack Flower - May 2013                    |
// |___________________________________________|
//

#include "PlayerTemplate.h"
//#include "../XML/CXml.h"
//#include "../Logic/PhysicalManager.h"

namespace factory
{
	RTTI_IMPL(PlayerTemplate, ActorTemplate);

	//Konstruktor
	PlayerTemplate::PlayerTemplate()
	:
		ActorTemplate()
	{
	} 

	//Destruktor wirtualny
	PlayerTemplate::~PlayerTemplate()
	{
		//~ActorTemplate()
		m_player_AI.clear();
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PlayerTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
	void PlayerTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool PlayerTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml
	bool PlayerTemplate::load(CXml & xml)
	{
		//sprawdzamy, czy xml zawiera informację, że jest player
		if (xml.GetString(xml.GetRootNode(), "type") != "player")
			return false;

		//sprawdzamy, czy można załadować dane z klasy bazowej
		if (!ActorTemplate::load(xml))
			return false;

		//reszta, gdyby klasa Player (jej wzorzec PlayerTemplate)
		//miały jakieś pola do wczytania i przekazania...

		return true;
	}

	//Metoda tworzy obiekt klasy Player
	Player *PlayerTemplate::create(std::wstring id)
	{
		Player *player = gPhysicalManager.createPlayer(id);
		fill(player);
		//gdyby były jakieś pola do przekazania, należy to uczynić...
		return player;
	}
}//namespace factory
