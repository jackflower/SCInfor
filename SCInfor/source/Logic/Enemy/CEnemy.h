//  ___________________________________
// | CEnemy.h - class definition       |
// | Jack Flower - March 2014          |
// |___________________________________|
//

#ifndef H_ENEMY_JACK
#define H_ENEMY_JACK

#include <string>
#include "../Actor/CActor.h"

///
///Forward declaration
///
class CActorAI;

///
///Forward declaration
///
namespace equipment
{
	class CEngine;
}

using namespace equipment;


namespace logic
{
	///
	///Klasa reprezentuje wroga
	///
	class CEnemy: public CActor 
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;

		//Aby uzyskaæ obiekt CEnemy, nale¿y wywo³aæ CPhysicalManager::CreateEnemy();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		CEnemy(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CEnemyCopy - parametr - obiekt klasy CEnemy
		///
		CEnemy(const CEnemy &CEnemyCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CEnemy(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		///
		///Wirtualan metoda zabija obiekt klasy CEnemy i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
		///
		virtual void Kill();

	protected:
	private:

	};
}//namespace logic
#endif //H_ENEMY_JACK
