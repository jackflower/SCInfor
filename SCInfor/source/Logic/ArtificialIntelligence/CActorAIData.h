//  _________________________________________
// | CActorAIData.h - class definition       |
// | Jack Flower April 2015                  |
// |_________________________________________|
//

#ifndef H_ACTOR_AI_DATA_JACK
#define H_ACTOR_AI_DATA_JACK

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "../Actor/CActor.h"
#include "../EEnemyState.h"
#include "../EEnemyAttitude.h"
#include "../../Utilities/Memory/CSafePtr.h"

namespace artificialintelligence
{
	class CActorAI;
}

using namespace logic;
using namespace memory;

namespace artificialintelligence
{
	class CActorAIData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		///@param *AI - wskaŸnik na obiekt klasy CActorAI
		///
		CActorAIData(CActorAI *AI);

		///
		///Destruktor
		///
		~CActorAIData();

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CActor, do którego podpiêta jest AI
		///
		CActor *GetActor();

		void MoveTo(const sf::Vector2f coord, float tolerance = 0.0f);
		void TurnTowards(int newRot);
		void LookTowards(const sf::Vector2f &pos);
		sf::Vector2f GetPosition();


		//metody inline...

		///
		///Metoda zwraca obiekt klasy CActorAI - opakowania informacji AI
		///
		inline CActorAI *GetAI()
		{
			return p_AI;
		}
		
		///
		///Metoda ustawia wskaŸnik na obiekt klasy CActorAI - opakowania informacji AI
		///
		///@param *pointer_AI - wskaŸnik na obiekt klasy CActorAI
		///
		inline void setAI(CActorAI *pointer_AI)
		{
			p_AI = pointer_AI;
		}

		
		inline float GetMovingTime()			{ return m_moving_time; }	
		inline void AddMovingTime(float dt)		{ m_moving_time += dt; }
		inline bool GetWaypointSet()			{ return mWaypointSet; }
		inline void ResetWaypoint()				{ mWaypointSet = false; }
	    inline sf::Vector2f GetWaypoint()		{ return m_waypoint; }
		inline float GetWaypointTolerance()		{ return m_waypoint_tolerance; }
		inline int GetTgtDir()					{ return m_target_direction; }
		
		//inline void SetMovementScheme(CAIScheme *s)
		//{
		//	if (mMovementScheme != s){
		//		SetState(esNormal);
		//		if (p_AI != NULL){
		//			MoveTo(GetActor()->GetPosition(),GetActor()->GetCircleRadius());
		//		} else {
		//			MoveTo(GetPosition());
		//		}
		//	}
		//	mMovementScheme = s;
		//	mMovementSchemeTimer = 0.0f;
		//}

		//inline CAIScheme *GetMovementScheme()
		//{
		//	return mMovementScheme;
		//}

		inline float GetMovementSchemeTimer()
		{
			return mMovementSchemeTimer;
		}

		//inline void SetCombatScheme(CAIScheme *s)
		//{
		//	mCombatScheme = s;
		//	mCombatSchemeTimer = 0.0f;
		//}

		//inline CAIScheme *GetCombatScheme()
		//{
		//	return mCombatScheme;
		//}
		
		inline float GetCombatSchemeTimer(){
			return mCombatSchemeTimer;
		}	
		
		//zamiana na *
		//inline void SetCombatTarget(Memory::CSafePtr<CActor> tgt){
		//	mCombatTarget = tgt;
		//}

		//zamiana na *
		//inline Memory::CSafePtr<CActor> GetCombatTarget(){
		//	return mCombatTarget;
		//}

		//inline CActorFlock *GetFlock()
		//{
		//	return mFlock;
		//}

		//inline void SetFlock(CActorFlock *flock)
		//{
		//	mFlock = flock;
		//}

		inline EEnemyState GetState()			{ return m_state; }
		inline void SetState(EEnemyState State)	{ m_state = State; }

		inline EEnemyAttitude GetAttitude()			{ return m_attitude; }
		inline void SetAttitude(EEnemyAttitude a)	{ m_attitude = a; }

		
		void Update(float dt);


	private:

		CActorAI*		p_AI;					//wskaŸnik na obiekt klasy CActorAI
		EEnemyState		m_state;				//wyliczenie - stany obiektu
		EEnemyAttitude	m_attitude;				//wyliczenie - nastawienia obiektu
		sf::Vector2f	m_waypoint;				//po³o¿enie punktu na drodze do celu
		float			m_waypoint_tolerance;	//wartoœæ tolerancji przy obliczaniu punktu celu
		int				m_target_direction;		//wspó³czynnik kierunku do celu
		float			m_moving_time;			//czas przemieszczania siê
		

		//poni¿se wymaga analizy...
		//CActor* mCombatTarget;
		CSafePtr<CActor> mCombatTarget;

		

		//CAIScheme *mMovementScheme;
		float mMovementSchemeTimer;

		//CAIScheme *mCombatScheme;
		float mCombatSchemeTimer;

		//CActorFlock *mFlock;

		bool mWaypointSet;

	};
}//namespace artificialintelligence
#endif//H_ACTOR_AI_DATA_JACK
