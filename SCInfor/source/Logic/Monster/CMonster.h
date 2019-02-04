/*
 _______________________________________
| CMonster.h - definicja klasy.         |
| Jack Flower - January 2014.           |
|_______________________________________|

*/

#ifndef H_MONSTER_JACK
#define H_MONSTER_JACK

#include "../Actor/CActor.h"

namespace logic
{
	///
	///Klasa reprezentuje potwora
	///
	class CMonster : public CActor
	{

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
		//Aby uzyska� obiekt CMonster, nale�y wywo�a� CPhysicalManager::CreateMonster();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		CMonster(const std::wstring& uniqueId);

		///
		///Destruktor wirtualny
		///
		virtual ~CMonster(void);

	public:

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	private:
		float m_time_do_death;//pol testowe...

	};
}//namespace logic
#endif //H_MONSTER_JACK