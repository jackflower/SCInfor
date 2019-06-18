//  _____________________________________
// | Monster.h - class definition        |
// | Jack Flower - January 2014          |
// |_____________________________________|
//

#ifndef H_MONSTER_JACK
#define H_MONSTER_JACK

#include "../Actor/Actor.h"

namespace logic
{
	///
	///Klasa reprezentuje potwora
	///
	class Monster : public Actor
	{

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;
		
		//Aby uzyskać obiekt Monster, należy wywołać PhysicalManager::CreateMonster();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Monster(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param MonsterCopy - stała referencja na obiekt klasy Monster
		///
		Monster(const Monster & MonsterCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~Monster();

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

	private:

		float m_time_do_death;//pole testowe...

	};
}//namespace logic
#endif //H_MONSTER_JACK
