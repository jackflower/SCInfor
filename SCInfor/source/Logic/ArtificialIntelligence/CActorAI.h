//  _____________________________________
// | CActorAI.h - class definition       |
// | Jack Flower April 2015              |
// |_____________________________________|
//

#ifndef H_ACTOR_AI_JACK
#define H_ACTOR_AI_JACK

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "../EEnemyState.h"
#include "../EEnemyAttitude.h"
#include "../Actor/CActorController.h"
#include "CActorAIData.h"

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
	class CActorAI : public CActorController
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		///@param *actor - wska�nik na obiekt klasy CActor
		///
		CActorAI(CActor *actor);

		///
		///Destruktor wirtualny
		///
		virtual ~CActorAI();

		///
		///Metoda zwraca wska�nik na schematu AI
		///
		inline CAIScheme *GetScheme()
		{
			return p_scheme;
		}

		///
		///Metoda ustawia wska�nik na schemat AI
		///
		///@param *scheme - wska�nik na schemat AI
		///
		///@duration - czas trwania
		///
		void SetScheme(CAIScheme *scheme, float duration = 1.0f);

		///
		///Metoda zwraca wska�nik na obiekt klasy CActor,
		///do kt�rego nale�y ten kod AI
		///pole jest w klasie bazowej - CActorController
		///
		inline CActor *GetActor()
		{
			return p_actor;
		}
	    
		///
		///Metoda zwrca flag�, czy osi�gni�to zamierzon� pozycj�
		///
		bool ReachedWaypoint();
	    
		///
		///Metoda zwraca wska�nik na opakowanie danych AI
		///
		inline CActorAIData *GetData()
		{
			return &m_data;
		}

		///
		///Metoda aktualizuje obiekt
		///
		///@param dt - czas
		///
		void update( float dt );

	protected:

		CAIScheme*			p_scheme;					//wska�nik na obiekt klasy CAIScheme (schemat AI)
		CActorAIData		m_data;						//opakowane dane AI
		float				m_turning_sharpness;		//w��czanie ostro�ci...zwi�zane z rotacj�...
		float				m_time_to_change_scheme;	//czas potrzebny na zmian� schematu AI
		std::vector<int>	mAvailableAbilities;
		
		float CalculateSpeedModifier(float turning_sharpness);
		void UpdateRotation(float dt);

		
		int ChooseAbility();
	};
}//namespace artificialintelligence
#endif//H_ACTOR_AI_JACK
