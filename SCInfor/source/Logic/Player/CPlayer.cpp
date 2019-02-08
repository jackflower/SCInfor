/*
 _____________________________________
| CPlayer.cpp - implementacja klasy.  |
| Jack Flower - March 2013.           |
|_____________________________________|

*/

#include "CPlayer.h"

namespace logic
{
	RTTI_IMPL(CPlayer, Actor);

	//Chroniony konstruktor domyœlny
	CPlayer::CPlayer(const std::wstring &uniqueId) 
	:	
		Actor	(uniqueId)	
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CPlayer::CPlayer(const CPlayer &CPlayerCopy)
	:
		Actor	(CPlayerCopy)//konstruktor kopiuj¹cy klasy bazowej
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CPlayer::~CPlayer(void) 
	{
		//to do...
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPlayer::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CPlayer::update(float dt)
	{
		Actor::update(dt);
	}

	//Wirtualan metoda zabija obiekt klasy CPlayer i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
	void CPlayer::kill() 
	{
		//póki co bêdzie siê wywo³ywa³a metoda klasy bazowej
		Actor::kill();
		//to do...
	}
}//namespace logic