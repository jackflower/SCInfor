/*
 _____________________________________
| CPlayer.h - definicja klasy.        |
| Jack Flower - March 2013.           |
|_____________________________________|

*/

#ifndef H_PLAYER_JACK
#define H_PLAYER_JACK

#include <string>
#include "../Actor/CActor.h"

///
///Forward declaration
///
class CPlayerAI;

namespace logic
{

	///
	///Klasa reprezentuje gracza
	///
	class CPlayer: public CActor 
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CPlayer, nale�y wywo�a� CPhysicalManager::CreatePlayer();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		CPlayer(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CPlayerCopy - parametr - obiekt klasy CPlayer
		///
		CPlayer(const CPlayer &CPlayerCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CPlayer(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		///
		///Wirtualan metoda zabija obiekt klasy CPlayer i wywo�uje odpowiednie czynno�ci z tym zwi�zane
		///
		virtual void Kill();

	private:

		//rozwojowo - zaproponuj pola oraz metody dla gracza (w zale�no�ci od pomys�u)
	};
}//namespace logic
#endif //H_PLAYER_JACK
