// ____________________________________
// | Player.h - definicja klasy        |
// | Jack Flower - March 2013          |
// |___________________________________|
//

#ifndef H_PLAYER_JACK
#define H_PLAYER_JACK

#include <string>
#include "../Actor/Actor.h"

///
///Forward declaration
///
class CPlayerAI;

namespace logic
{

	///
	///Klasa reprezentuje gracza
	///
	class Player: public Actor 
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;

		//Aby uzyskać obiekt Player, należy wywołać PhysicalManager::CreatePlayer();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - stała referencja na obiekt klasy std::wstring
		///
		Player(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param PlayerCopy - parametr - obiekt klasy Player
		///
		Player(const Player & PlayerCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		///
		virtual ~Player();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		///
		///Wirtualan metoda zabija obiekt klasy Player i wywołuje odpowiednie czynności z tym związane
		///
		virtual void kill();

	private:

		//rozwojowo - pola oraz metody dla gracza (w zależności od pomysłu)
	};
}//namespace logic
#endif //H_PLAYER_JACK
