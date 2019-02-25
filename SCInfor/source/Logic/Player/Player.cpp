//  ___________________________________
// | Player.cpp - class implementation |
// | Jack Flower - March 2013          |
// |___________________________________|
//

#include "Player.h"

namespace logic
{
	RTTI_IMPL(Player, Actor);

	//Chroniony konstruktor domyślny
	Player::Player(const std::wstring &uniqueId) 
	:	
		Actor(uniqueId)	
	{
	}

	//Chroniony konstruktor kopiujący
	Player::Player(const Player & PlayerCopy)
	:
		Actor(PlayerCopy)//konstruktor kopiujący klasy bazowej
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	Player::~Player() 
	{
		//~Actor()
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Player::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda aktualizująca obiekt
	void Player::update(float dt)
	{
		Actor::update(dt);
	}

	//Wirtualan metoda zabija obiekt klasy Player i wywołuje odpowiednie czynności z tym związane
	void Player::kill() 
	{
		//póki co będzie się wywoływała metoda klasy bazowej
		Actor::kill();
		//to do...
	}
}//namespace logic
