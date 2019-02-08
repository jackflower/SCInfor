//  ___________________________________________
// | ActorStateData.cpp - class implementation |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#include "ActorStateData.h"

namespace statesdata
{
	//Konstruktor
	ActorStateData::ActorStateData()
	:
		e_basic_state(EActorBasicState::UNIT_DEFAULT),
		e_move_state(EActorMoveState::MOVE_STATE_STANDING),
		e_spawn_state(EActorSpawnState::SPAWN_STATE_ALIVE)
	{
	}

	//Konstruktor kopiujący
	ActorStateData::ActorStateData(const ActorStateData & ActorStateDataCopy)
	:
		e_basic_state(ActorStateDataCopy.e_basic_state),
		e_move_state(ActorStateDataCopy.e_move_state),
		e_spawn_state(ActorStateDataCopy.e_spawn_state)
	{
	}

	//Destruktor
	ActorStateData::~ActorStateData()
	{
		e_basic_state = EActorBasicState::UNIT_DEFAULT;
		e_move_state = EActorMoveState::MOVE_STATE_STANDING;
		e_spawn_state = EActorSpawnState::SPAWN_STATE_SPAWNING;
	}

	//Metoda zwraca stan obiektu - aktualizacja reprezentacji obiektu
	const EActorBasicState & ActorStateData::getBasicState() const
	{
		return e_basic_state;
	}

	//Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
	void ActorStateData::setBasicState(const EActorBasicState & basic_state)
	{
		e_basic_state = basic_state;
	}

	//Metoda zwraca stan ruchu obiektu
	const EActorMoveState & ActorStateData::getMoveState() const
	{
		return e_move_state;
	}

	//Metoda ustawia stan ruchu obiektu
	void ActorStateData::setMoveState(const EActorMoveState & move_state)
	{
		e_move_state = move_state;
	}

	//Metoda zwraca stan behawioralny obiektu
	const EActorSpawnState & ActorStateData::getSpawnState() const
	{
		return e_spawn_state;
	}

	//Metoda ustawia stan behawioralny obiektu
	void ActorStateData::setSpawnState(const EActorSpawnState & spawn_state)
	{
		e_spawn_state = spawn_state;
	}

}//namespace statesdata
