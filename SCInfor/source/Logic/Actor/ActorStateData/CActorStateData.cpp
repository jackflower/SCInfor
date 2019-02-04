//  ____________________________________________
// | CActorStateData.cpp - class implementation |
// | Jack Flower - May 2016                     |
// |____________________________________________|
//

#include "CActorStateData.h"

namespace statesdata
{
	//Konstruktor
	CActorStateData::CActorStateData()
	:
		e_basic_state	(EActorBasicState::UNIT_DEFAULT),
		e_move_state	(EActorMoveState::MOVE_STATE_STANDING),
		e_spawn_state	(EActorSpawnState::SPAWN_STATE_ALIVE)
	{
	}

	//Konstruktor kopiuj¹cy
	CActorStateData::CActorStateData(const CActorStateData & CActorStateDataCopy)
	:
		e_basic_state	(CActorStateDataCopy.e_basic_state),
		e_move_state	(CActorStateDataCopy.e_move_state),
		e_spawn_state	(CActorStateDataCopy.e_spawn_state)
	{
	}

	//Destruktor
	CActorStateData::~CActorStateData()
	{
		e_basic_state	= EActorBasicState::UNIT_DEFAULT;
		e_move_state	= EActorMoveState::MOVE_STATE_STANDING;
		e_spawn_state	= EActorSpawnState::SPAWN_STATE_SPAWNING;
	}

	//Metoda zwraca stan obiektu - aktualizcja reprezentacji obiektu
	const EActorBasicState & CActorStateData::getBasicState() const
	{
		return e_basic_state;
	}

	//Metoda ustawia stan obiektu - aktualizcja reprezentacji obiektu
	void CActorStateData::setBasicState(const EActorBasicState & basic_state)
	{
		e_basic_state = basic_state;
	}

	//Metoda zwraca stan ruchu obiektu
	const EActorMoveState & CActorStateData::getMoveState() const
	{
		return e_move_state;
	}

	//Metoda ustawia stan ruchu obiektu
	void CActorStateData::setMoveState(const EActorMoveState & move_state)
	{
		e_move_state = move_state;
	}

	//Metoda zwraca stan behawioralny obiektu
	const EActorSpawnState & CActorStateData::getSpawnState() const
	{
		return e_spawn_state;
	}

	//Metoda ustawia stan behawioralny obiektu
	void CActorStateData::setSpawnState(const EActorSpawnState & spawn_state)
	{
		e_spawn_state = spawn_state;
	}

}//namespace statesdata
