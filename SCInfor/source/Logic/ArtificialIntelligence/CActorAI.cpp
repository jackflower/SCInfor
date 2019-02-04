//  _____________________________________
// | CActorAI.cpp - class implementation |
// | Jack Flower April 2015              |
// |_____________________________________|
//


#include <cmath>
#include <cstdio>
#include "CActorAI.h"
#include "CAIScheme.h"
//#include "CAISchemeManager.h"
//#include "CAIAbilityHint.h"
//#include "../CPlayer.h"
//#include "../CPlayerManager.h"
//#include "../Abilities/CAbility.h"
//#include "../../Audio/CAudioManager.h"
//to b�dzie wymaga�o sporej refaktoryzacji...
//#include "../../Utils/MathsFunc.h"
//#include "../../Utils/CRand.h"
//#include "../../Utils/Directions.h"
//#include "../../Utils/HRTimer.h"
//#include "CActorFlock.h"


namespace artificialintelligence
{
	RTTI_IMPL(CActorAI, CActorController);

	//Konstruktor
	CActorAI::CActorAI(CActor *actor)
	:
		CActorController		(actor),	//konstruktor klasy bazowej
		//m_data				(this),		//ostrze�enie zbyt wczesnego wi�zania *)
		m_data					(NULL),
		m_turning_sharpness		(0.0f),
		p_scheme				(NULL),
		m_time_to_change_scheme	(0.0f)
	{
		m_data.setAI(this);//*) inicjacja wska�nika - obiekt jest utworzony
	}

	//Destruktor wirtualny
	CActorAI::~CActorAI()
	{
		//CActorController		not edit
		//m_data				not edit
		m_turning_sharpness		= 0.0f;
		p_scheme				= NULL;
		m_time_to_change_scheme	= 0.0f;

	}

	//Metoda ustawia wska�nik na schemat AI
	void CActorAI::SetScheme(CAIScheme *scheme, float duration)
	{
		//if (p_scheme)
		//	p_scheme->UnregisterAI(this->GetSafePointer());
		//
		//p_scheme = scheme;
		//p_scheme->RegisterAI(this->GetSafePointer());
		//m_time_to_change_scheme = duration;
	}

	void CActorAI::UpdateRotation(float dt)
	{
		/*
		float rot = float( GetActor()->GetRotation() );
		m_turning_sharpness = Maths::Abs( rot - m_data.GetTgtDir() );

		if ( m_turning_sharpness < 1.0f )
		{
			m_turning_sharpness = 0.0f;
			return;
		}

		float maxTurn = GetActor()->GetMaxTurnSpeed() * dt;
		int tgtDir = m_data.GetTgtDir();
		float angleByLeft = tgtDir - rot; 
		if ( angleByLeft < 0.0f ) angleByLeft = std::fmod(angleByLeft, 360.0f) + 360.0f;
		float angleByRight = rot - tgtDir; 
		if ( angleByRight < 0.0f ) angleByRight = std::fmod(angleByRight, 360.0f) + 360.0f;

		if ( angleByLeft < angleByRight)	rot = std::min( angleByLeft, maxTurn );			// w lewo
		else								rot = std::min( angleByRight, maxTurn ) * -1.0f;// w prawo

		TurnBy(rot);
		*/
	}

	//float CActorAI::CalculateSpeedModifier(float turning_sharpness)
	//{
	//    return 0.6f + 0.2f * (1.0f + cosf(turning_sharpness*3.14159265f/180.0f));
	//}


	//int CActorAI::ChooseAbility()
	//{
	//    int r = gRand.Rnd(0,mAvailableAbilities.size());
	//    if ((r >= 0) && ((unsigned int)r < mAvailableAbilities.size()))
	//        return mAvailableAbilities[r];
	//    else
	//        return -1;
	//}

	//Metoda zwrca flag�, czy osi�gni�to zamierzon� pozycj�
	bool CActorAI::ReachedWaypoint()
	{
		//sf::Vector2f v = m_data.GetWaypoint() - GetActor()->GetPosition();
		//float len = maths::Length( v );
		//float tolerance = GetActor()->GetCircleRadius() + m_data.GetWaypointTolerance();
		//return (len < tolerance);

		return false;//atrapa
	}

	//Metoda aktualizuje obiekt
	void CActorAI::update(float dt)
	{
		/*
		CActorController::update(dt);

		m_data.update(dt);

		if ( GetActor()->GetSpawnState() != CActor::ssAlive )	return;
		if ( p_scheme )											p_scheme->UpdateAI(&m_data, dt);

		// TODO: Dodac rozne zachowania w zaleznosci od nastawienia do gracza
		// TEMP:
		if ( m_data.GetAttitude() != AI_ENEMY )
			return;

		// wykonaj ruch / obrot
		if ( m_data.GetState() == esWaypoint )
		{
			m_data.AddMovingTime(dt);

			sf::Vector2f v = m_data.GetWaypoint() - GetActor()->GetPosition();
			float len = Maths::Length( v );
			float tolerance = GetActor()->GetCircleRadius() + m_data.GetWaypointTolerance();

			m_data.TurnTowards( RotationFromVector( Maths::Normalize(v) ) );
			UpdateRotation( dt );
			if ( len < GetActor()->GetStats()->GetCurrAspect(aSpeed) * dt + tolerance )
			{
				m_data.SetState(esNormal);
				GetActor()->SetVelocity( Maths::VectorZero() );
				if ( len > tolerance )
					GetActor()->SetPosition( GetActor()->GetPosition() + Maths::Normalize( v ) * ( len - tolerance ) );
			}
			else
			{
				float speedModifier = CalculateSpeedModifier(m_turning_sharpness);

				SetMove(Maths::Sgn(speedModifier));
				SetSpeed(GetActor()->GetStats()->GetCurrAspect(aSpeed)*(speedModifier>0.0f?speedModifier:-speedModifier));
			}
		}
		else if ( m_data.GetState() == esTurn ){
			UpdateRotation( dt );
			
			float rot = float( GetActor()->GetRotation() );
			if (Maths::Abs( rot - m_data.GetTgtDir() ) < 0.0001f)
				m_data.SetState(esNormal);
		} else
			SetSpeed( GetActor()->GetStats()->GetCurrAspect(aSpeed) );

		// atak
		for ( unsigned i = 0; i < gPlayerManager.GetPlayerCount(); i++ )
		{
			CPlayer *player = gPlayerManager.GetPlayerByOrder( i );
			if (player == NULL) continue;
			mAvailableAbilities.clear();
			GetActor()->GetAbilityPerformer().GetAvailableAbilities(mAvailableAbilities);
			if (mAvailableAbilities.size() > 0){
				int idx = ChooseAbility(); //GetActor()->GetAbilityPerformer().GetDefaultAttack()
				CAbility *abi = GetActor()->GetAbilityPerformer().GetAbility( idx )->ability;
				ExecutionContextPtr context = GetActor()->GetAbilityPerformer().GetContext(idx);
				if (abi == NULL) continue;
				bool useAbility = false;
				if (abi->mAIHint == NULL)
					useAbility = abi->InMeleeRange( GetActor(), player, context );
				else
					useAbility = abi->mAIHint->UseAbility( GetActor(), player);
				if (useAbility)
				{
					GetActor()->GetAbilityPerformer().PerformAbility( idx );

					//odegraj dzwiek
					if ( unsigned sndCount = GetActor()->GetAttackSounds().size() )
						gAudioManager.GetSoundPlayer().Play( GetActor()->GetAttackSounds()[ rand() % sndCount ], GetActor()->GetPosition() );
  				} 
			}
		}
		*/
	}

}//namespace artificialintelligence