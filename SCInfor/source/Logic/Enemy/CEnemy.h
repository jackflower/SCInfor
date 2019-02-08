//  ___________________________________
// | CEnemy.h - class definition       |
// | Jack Flower - March 2014          |
// |___________________________________|
//

#ifndef H_ENEMY_JACK
#define H_ENEMY_JACK

#include <string>
#include "../Actor/Actor.h"

///
///Forward declaration
///
class CActorAI;

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
	class CEnemy: public Actor 
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CEnemy, nale�y wywo�a� CPhysicalManager::CreateEnemy();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		CEnemy(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CEnemyCopy - parametr - obiekt klasy CEnemy
		///
		CEnemy(const CEnemy &CEnemyCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CEnemy(void);

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
		///Wirtualan metoda zabija obiekt klasy CEnemy i wywo�uje odpowiednie czynno�ci z tym zwi�zane
		///
		virtual void kill();

	protected:
	private:

	};
}//namespace logic
#endif //H_ENEMY_JACK
