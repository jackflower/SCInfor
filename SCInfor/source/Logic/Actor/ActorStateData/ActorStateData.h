//  ___________________________________________
// | ActorStateData.h - class definition       |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#ifndef H_ACTOR_STATE_DATA_JACK
#define H_ACTOR_STATE_DATA_JACK

#include "../EActorBasicState.h"
#include "../EActorMoveState.h"
#include "../EActorSpawnState.h"

namespace statesdata
{
	///
	///Klasa opakowuje wyliczenie stanów
	///
	class ActorStateData
	{
	public:

		///
		///Konstruktor
		///
		ActorStateData();

		///
		///Konstruktor kopiujący
		///
		///@param ActorStateDataCopy - stała referencja na obiekt klasy ActorStateData
		///
		ActorStateData(const ActorStateData & ActorStateDataCopy);

		///
		///Destruktor
		///
		~ActorStateData();

		///
		///Metoda zwraca stan obiektu - aktualizacja reprezentacji obiektu
		///
		const EActorBasicState & getBasicState() const;

		///
		///Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
		///
		///@param basic_state - stała referencja na wylicznie stanów obiektu
		///
		void setBasicState(const EActorBasicState & basic_state);

		///
		///Metoda zwraca stan ruchu obiektu
		///
		const EActorMoveState & getMoveState() const;

		///
		///Metoda ustawia stan ruchu obiektu
		///
		///@param move_state - stała referencja na wylicznie stanów ruchu obiektu
		///
		void setMoveState(const EActorMoveState & move_state);

		///
		///Metoda zwraca stan behawioralny obiektu
		///
		const EActorSpawnState & getSpawnState() const;

		///
		///Metoda ustawia stan behawioralny obiektu
		///
		///@param spawn_state - stała referencja na wyliczenie stanów behawioralnych obiektu (procesy życiowe, trwanie)
		///
		void setSpawnState(const EActorSpawnState & spawn_state);

	private:

		EActorBasicState e_basic_state; //stany obiektu (reprezentacja graficzna)
		EActorMoveState e_move_state; //stanów ruchu obiektu
		EActorSpawnState e_spawn_state;	//stany behawioralne, życiowe, trwanie

	};
}//namespace statesdata
#endif//H_ACTOR_STATE_DATA_JACK
