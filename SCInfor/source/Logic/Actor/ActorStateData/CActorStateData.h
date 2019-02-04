//  ____________________________________________
// | CActorStateData.h - class definition       |
// | Jack Flower - May 2016                     |
// |____________________________________________|
//

#ifndef H_ACTOR_STATE_DATA_JACK
#define H_ACTOR_STATE_DATA_JACK

#include "../EActorBasicState.h"
#include "../EActorMoveState.h"
#include "../EActorSpawnState.h"

namespace statesdata
{
	///
	///Klasa opakowuje wyliczenie stan�w
	///
	class CActorStateData
	{
	public:

		///
		///Konstruktor
		///
		CActorStateData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CActorStateDataCopy - sta�a referencja na obiekt klasy CActorStateData
		///
		CActorStateData(const CActorStateData & CActorStateDataCopy);

		///
		///Destruktor
		///
		~CActorStateData();

		///
		///Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
		///
		const EActorBasicState & getBasicState() const;

		///
		///Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
		///
		///@param & basic_state - sta�a referencja na wylicznie stan�w obiektu
		///
		void setBasicState(const EActorBasicState & basic_state);

		///
		///Metoda zwraca stan ruchu obiektu
		///
		const EActorMoveState & getMoveState() const;

		///
		///Metoda ustawia stan ruchu obiektu
		///
		///@param & move_state - sta�a referencja na wylicznie stan�w ruchu obiektu
		///
		void setMoveState(const EActorMoveState & move_state);

		///
		///Metoda zwraca stan behawioralny obiektu
		///
		const EActorSpawnState & getSpawnState() const;

		///
		///Metoda ustawia stan behawioralny obiektu
		///
		///@param & spawn_state - sta�a referencja na wyliczenie stan�w behawioralnych obiektu (procesy �yciowe, trwanie)
		///
		void setSpawnState(const EActorSpawnState & spawn_state);

	private:

		EActorBasicState	e_basic_state;	//stany obiektu (reprezentacja graficzna)
		EActorMoveState		e_move_state;	//stan�w ruchu obiektu
		EActorSpawnState	e_spawn_state;	//stany behawioralne, �yciowe, trwanie

	};
}//namespace statesdata
#endif//H_ACTOR_STATE_DATA_JACK