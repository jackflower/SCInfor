//  ____________________________________
// | ActorAI.h - class definition       |
// | Jack Flower April 2015             |
// |____________________________________|
//

#ifndef H_ACTOR_AI_JACK
#define H_ACTOR_AI_JACK

#include "../EEnemyState.h"
#include "../EEnemyAttitude.h"
#include "../Actor/ActorController.h"
#include "ActorAIData.h"

///
///Forward declaration
///
namespace artificialintelligence
{
	class CAIScheme;
}
class CActorFlock;
class IDecorator;

namespace artificialintelligence
{
	///
	///Klasa reprezentuje rozszerzenie opakowania informacji AI
	///
	class ActorAI : public ActorController
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		///@param *actor - wskaźnik na obiekt klasy Actor
		///
		ActorAI(Actor *actor);

		///
		///Destruktor wirtualny
		///
		virtual ~ActorAI();

		///
		///Metoda zwraca wskaźnik na schematu AI
		///
		inline CAIScheme *getScheme()
		{
			return p_scheme;
		}

		///
		///Metoda ustawia wskaźnik na schemat AI
		///
		///@param *scheme - wskaźnik na schemat AI
		///
		///@duration - czas trwania
		///
		void setScheme(CAIScheme *scheme, float duration = 1.0f);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Actor,
		///do którego należy ten kod AI
		///pole jest w klasie bazowej - ActorController
		///
		inline Actor *getActor()
		{
			return p_actor;
		}
	    
		///
		///Metoda zwraca flagę, czy osiągnięto zamierzoną pozycję
		///
		bool reachedWaypoint();
	    
		///
		///Metoda zwraca wskaźnik na opakowanie danych AI
		///
		inline ActorAIData *getData()
		{
			return & m_data;
		}

		///
		///Metoda aktualizuje obiekt
		///
		///@param dt - czas
		///
		void update( float dt );

	protected:

		CAIScheme *p_scheme; //wskaźnik na obiekt klasy CAIScheme (schemat AI)
		ActorAIData m_data; //opakowane dane AI
		float m_turning_sharpness; //włączanie ostrości...związane z rotacją...
		float m_time_to_change_scheme; //czas potrzebny na zmianę schematu AI
		std::vector<int> mAvailableAbilities;
		
		float calculateSpeedModifier(float turning_sharpness);
		void updateRotation(float dt);
		
		int chooseAbility();
	};
}//namespace artificialintelligence
#endif//H_ACTOR_AI_JACK
