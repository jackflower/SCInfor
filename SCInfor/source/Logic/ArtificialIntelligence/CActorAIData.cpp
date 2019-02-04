//  _________________________________________
// | CActorAIData.cpp - class implementation |
// | Jack Flower April 2015                  |
// |_________________________________________|
//


#include "CActorAIData.h"
#include "CActorAI.h"

namespace artificialintelligence
{
	RTTI_IMPL_NOPARENT(CActorAIData);

	//Konstruktor
	CActorAIData::CActorAIData(CActorAI *AI)
	:
		p_AI(AI),
		//m_state(esNormal),
		//m_attitude(AI_ENEMY),
		//mWaypoint(sf::Vector2f(0.0f,0.0f)),
		m_waypoint_tolerance(0.0f),
		m_target_direction(0),
		mCombatTarget(CSafePtr<CActor>::NullPtr()),
		//mCombatTarget(NULL),
		m_moving_time(0.0f),
		//mMovementScheme(NULL),
		mMovementSchemeTimer(0.0f),
		//mCombatScheme(NULL),
		mCombatSchemeTimer(0.0f),
		//mFlock(NULL),
		mWaypointSet(false)
	{
	}

	//Destruktor
	CActorAIData::~CActorAIData()
	{
	}

	CActor *CActorAIData::GetActor()
	{
		return p_AI->GetActor();
	}

	//void CActorAIData::MoveTo(const sf::Vector2f coord, float tolerance)
	//{
	//    mWaypoint = coord;
	//    m_waypoint_tolerance = tolerance;
	//	m_moving_time = 0.0f;
	//    m_state = esWaypoint;
	//	mWaypointSet = true;
	//	if (Maths::Length(coord - sf::Vector2f(0.0f,0.0f)) < 1.0f){
	//		mWaypointSet = true;
	//	}
	//}

	//void CActorAIData::LookTowards(const sf::Vector2f &pos)
	//{
	//	TurnTowards(RotationFromVector(pos - GetActor()->GetPosition()));
	//	if (m_state != esWaypoint)
	//		m_state = esTurn;
	//}

	void CActorAIData::TurnTowards(int newRot)
	{
		//m_target_direction = newRot;
	}

	void CActorAIData::Update(float dt)
	{
		//mCombatSchemeTimer+=dt;
		//mMovementSchemeTimer+=dt;
	}

	//sf::Vector2f CActorAIData::GetPosition()
	//{
	//	if (p_AI != NULL){
	//		return GetActor()->GetPosition();
	//	} else {
	//		return mFlock->GetCenter();
	//	}
	//}
	//jeden

	//przeniesiole jako inline...
	//void CActorAIData::setActorAI(CActorAI *pointer_AI)
	//{
	//	p_AI = pointer_AI;
	//}
}//namespace artificialintelligence