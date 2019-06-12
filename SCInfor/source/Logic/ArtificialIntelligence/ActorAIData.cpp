//  ________________________________________
// | ActorAIData.cpp - class implementation |
// | Jack Flower April 2015                 |
// |________________________________________|
//


#include "ActorAIData.h"
#include "ActorAI.h"
#include "../../Utilities/MathFunctions/MathFunctions.h"

namespace artificialintelligence
{
	RTTI_IMPL_NOPARENT(ActorAIData);

	//Konstruktor
	ActorAIData::ActorAIData(ActorAI *AI)
	:
		p_AI{ AI },
		m_state{ EEnemyState::ENEMY_STATE_NORMAL },
		m_attitude{ EEnemyAttitude::AI_ENEMY },
		m_waypoint{ sf::Vector2f(0.0f,0.0f) },
		m_waypoint_tolerance{ 0.0f },
		m_target_direction{ 0 },
		mCombatTarget{ CSafePtr<Actor>::NullPtr() },
		//mCombatTarget(nullptr),
		m_moving_time{ 0.0f },
		//mMovementScheme(nullptr),
		m_movement_SchemeTimer(0.0f),
		//mCombatScheme(nullptr),
		m_combat_scheme_timer{ 0.0f },
		//mFlock(nullptr),
		m_waypoint_set{ false }
	{
	}

	//Destruktor
	ActorAIData::~ActorAIData()
	{
		//to do
	}

	Actor *ActorAIData::getActor()
	{
		return p_AI->getActor();
	}

	void ActorAIData::moveTo(const sf::Vector2f coord, float tolerance)
	{
		m_waypoint = coord;
	    m_waypoint_tolerance = tolerance;
		m_moving_time = 0.0f;
	    //m_state = esWaypoint; //2019-02-10 ? 
		m_waypoint_set = true;
		if (maths::Length(coord - sf::Vector2f(0.0f,0.0f)) < 1.0f){
			m_waypoint_set = true;
		}
	}

	//void ActorAIData::LookTowards(const sf::Vector2f &pos)
	//{
	//	TurnTowards(RotationFromVector(pos - GetActor()->GetPosition()));
	//	if (m_state != esWaypoint)
	//		m_state = esTurn;
	//}

	void ActorAIData::turnTowards(int newRot)
	{
		m_target_direction = newRot;
	}

	void ActorAIData::update(float dt)
	{
		m_combat_scheme_timer += dt;
		m_movement_SchemeTimer += dt;
	}

	sf::Vector2f ActorAIData::getPosition()
	{
		if (p_AI != nullptr)
		{
			return getActor()->getPosition();
		}
		else
		{
			//atrapa
			return getActor()->getPosition();
			//tego poniżej nie ma...czekam na impelmentację...
			//return mFlock->GetCenter();
		}
	}
}//namespace artificialintelligence
