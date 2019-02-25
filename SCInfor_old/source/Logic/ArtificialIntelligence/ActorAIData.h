//  ________________________________________
// | ActorAIData.h - class definition       |
// | Jack Flower April 2015                 |
// |________________________________________|
//

#ifndef H_ACTOR_AI_DATA_JACK
#define H_ACTOR_AI_DATA_JACK

#include "../Actor/Actor.h"
#include "../EEnemyState.h"
#include "../EEnemyAttitude.h"
#include "../../Utilities/Memory/CSafePtr.h"

namespace artificialintelligence
{
	class ActorAI;
}

using namespace logic;
using namespace memory;

namespace artificialintelligence
{
	class ActorAIData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		///@param *AI - wskaźnik na obiekt klasy ActorAI
		///
		ActorAIData(ActorAI *AI);

		///
		///Destruktor
		///
		~ActorAIData();

		///
		///Metoda zwraca wskaźnik na obiekt klasy Actor, do którego podpięta jest AI
		///
		Actor *getActor();

		void moveTo(const sf::Vector2f coord, float tolerance = 0.0f);
		void turnTowards(int newRot);
		//void LookTowards(const sf::Vector2f &pos);
		sf::Vector2f getPosition();


		///
		///Metoda zwraca obiekt klasy ActorAI - opakowanie informacji AI
		///
		inline ActorAI *getAI()
		{
			return p_AI;
		}
		
		///
		///Metoda ustawia wskaźnik na obiekt klasy ActorAI - opakowania informacji AI
		///
		///@param *pointer_AI - wskaźnik na obiekt klasy ActorAI
		///
		inline void setAI(ActorAI *pointer_AI)
		{
			p_AI = pointer_AI;
		}
		
		inline float GetMovingTime() { return m_moving_time; }	
		inline void AddMovingTime(float dt) { m_moving_time += dt; }
		inline bool GetWaypointSet() { return m_waypoint_set; }
		inline void ResetWaypoint() { m_waypoint_set = false; }
	    inline sf::Vector2f GetWaypoint() { return m_waypoint; }
		inline float GetWaypointTolerance()	{ return m_waypoint_tolerance; }
		inline int GetTgtDir() { return m_target_direction; }
		
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
			return m_movement_SchemeTimer;
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
		
		inline float GetCombatSchemeTimer()
		{
			return m_combat_scheme_timer;
		}	
		
		//zamiana na *
		//inline void SetCombatTarget(Memory::CSafePtr<Actor> tgt){
		//	mCombatTarget = tgt;
		//}

		//zamiana na *
		//inline Memory::CSafePtr<Actor> GetCombatTarget(){
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

		inline EEnemyState getState() { return m_state; }
		inline void setState(EEnemyState State)	{ m_state = State; }
		inline EEnemyAttitude getAttitude() { return m_attitude; }
		inline void setAttitude(EEnemyAttitude a) { m_attitude = a; }
		
		void update(float dt);

	private:

		ActorAI *p_AI; //wskaźnik na obiekt klasy ActorAI
		EEnemyState m_state; //wyliczenie - stany obiektu
		EEnemyAttitude m_attitude; //wyliczenie - nastawienia obiektu
		sf::Vector2f m_waypoint; //położenie punktu na drodze do celu
		float m_waypoint_tolerance;	//wartość tolerancji przy obliczaniu punktu celu
		int m_target_direction;	//współczynnik kierunku do celu
		float m_moving_time; //czas przemieszczania się

		//poniżse wymaga analizy...
		//Actor* mCombatTarget;
		CSafePtr<Actor> mCombatTarget;

		//CAIScheme *mMovementScheme;
		float m_movement_SchemeTimer;

		//CAIScheme *mCombatScheme;
		float m_combat_scheme_timer;

		//CActorFlock *mFlock;

		bool m_waypoint_set;

	};
}//namespace artificialintelligence
#endif//H_ACTOR_AI_DATA_JACK
