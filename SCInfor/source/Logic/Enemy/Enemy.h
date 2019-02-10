//  __________________________________
// | Enemy.h - class definition       |
// | Jack Flower - March 2014         |
// |__________________________________|
//

#ifndef H_ENEMY_JACK
#define H_ENEMY_JACK

#include "../Actor/Actor.h"

///
///Forward declaration
///
class ActorAI;

///
///Forward declaration
///
namespace equipment
{
	class Engine;
}

using namespace equipment;


namespace logic
{
	///
	///Klasa reprezentuje wroga
	///
	class Enemy: public Actor 
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;

		//Aby uzyskać obiekt Enemy, należy wywołać CPhysicalManager::CreateEnemy();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Enemy(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param EnemyCopy - parametr - obiekt klasy Enemy
		///
		Enemy(const Enemy & EnemyCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~Enemy(void);

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
		///Wirtualan metoda zabija obiekt klasy Enemy i wywołuje odpowiednie czynności z tym związane
		///
		virtual void kill();

	protected:
	private:

	};
}//namespace logic
#endif //H_ENEMY_JACK
