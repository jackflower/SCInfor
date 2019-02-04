//  ___________________________________________
// | CActorController.h - class implementation |
// | Jack Flower April 2015                    |
// |___________________________________________|
//

#include "CActorController.h"
#include "CActor.h"
#include "../../Utilities/Translation/Directions.h"
#include "../../Utilities/MathFunctions/MathFunctions.h"
#include <cmath>

using namespace maths;
using namespace translation;

namespace logic
{

	RTTI_IMPL_NOPARENT(CActorController);
	
	//Konstruktor
	CActorController::CActorController(CActor *actor)
	:
		p_actor		(actor),
		m_strafe	(0),
		m_move		(0),
		m_true_rot	(0.0f)
	{
	}

	//Destruktor wirtualny
	CActorController::~CActorController()
	{
		p_actor		= NULL;
		m_strafe	= 0;
		m_move		= 0;
		m_true_rot	= 0.0f;
	}

	//Metoda ustawia stan i pr�dko�� obiekty
	void CActorController::SetSpeed(float speed)
	{
		if (p_actor->getSpawnState() == SPAWN_STATE_ALIVE)
		{
			//uwzgl�dniam strafe
			sf::Vector2f dir = RotationToVector((float)p_actor->GetRotationBody());//body
			sf::Vector2f move;

			//je�li aktor strzela, ostrzeliwuje si�...
			if (m_strafe != 0)
			{
				move += VectorRightOf(dir) * (float) m_strafe;
				//stan - obiekt ostrzeliwuje si�, trwa wymiana ognia...
				p_actor->setMoveState(MOVE_STATE_STRAFING);
			}

			//je�li aktor si� porusza...
			if(m_move != 0)
			{
				move += dir * (float) m_move;
				//stan - obiekt porusza si�, idzie, spaceruje, jest w ruchu
				p_actor->setMoveState(MOVE_STATE_WALKING);
			}

			//je�li obiekt si� nie porusza i si� nie ostrzeliwuje (iddle....)
			if ((m_move == 0) && (m_strafe == 0))
				return;

			move = Normalize(move);//normalizacja wektora

			p_actor->SetVelocity(move * speed);//ustawienie pr�dko�ci
		}
	}

	//Metoda ustawia stan i wykonuje obr�t
	void CActorController::TurnBy(float rotation)
	{
		//je�li aktor �yje...
	    if (p_actor->getSpawnState() == SPAWN_STATE_ALIVE)
		{
	        m_true_rot += rotation;
	        while (m_true_rot < 0.0f) m_true_rot += 360.0f;
	        while (m_true_rot > 360.0f) m_true_rot -= 360.0f;
			p_actor->SetRotationBody(m_true_rot);//body
	        if ((rotation >= 0.001f) || (rotation <= -0.001))
				p_actor->setMoveState(MOVE_STATE_TURNING);
	    }
	}

	//Wirtualan metoda aktualizuj�ca obiekt
	void CActorController::update(float dt)
	{
		//przed zej�ciem z tego �wiata, obiekt si� zatrzymuje...
	    if (p_actor->getSpawnState() != SPAWN_STATE_ALIVE)
		{
	        p_actor->SetVelocity(sf::Vector2f(0.0f,0.0f));
	    }

		p_actor->setMoveState(MOVE_STATE_STANDING);
		m_move = 0;
		m_strafe = 0;
	}

	//Metoda zwraca warto�� obrotu obiektu
	const float CActorController::GetTrueRot() const
	{
		return m_true_rot;
	}

	//Metoda ustawia warto�� obrotu obiektu
	void CActorController::SetTrueRot(float true_rotation)
	{
		m_true_rot = true_rotation;
	}

	//Metoda ustawia kierunek ruchu
	void CActorController::SetMove(int move)
	{
		m_move = move;
	}

	//Metoda ustawia stan i wykonuje strafe
	void CActorController::SetStrafe(int strafe)
	{
		m_strafe = strafe;
	}

	/*
	void CActorController::GotDamageFrom(float dmg, EffectSourcePtr source)
	{
		if (source != EffectSourcePtr(NULL))
		{
			CPhysical *dealer = source->DeterminePhysicalSource();
			if (dealer)
			{
				//co to takiego? w kodzie zakomentowano...
				//if (gPlayerManager.VerifyKnownPhysical(dealer))
				//    fprintf(stderr,"Physical %ls got damage from %ls\n",p_actor->GetUniqueId().c_str(), dealer->GetUniqueId().c_str());
				//else
				//    fprintf(stderr,"Physical %ls got damage from source that is unverified!\n",p_actor->GetUniqueId().c_str());

			}
			else
			{
				//co to takiego? w kodzie zakomentowano...
				//fprintf(stderr,"Physical %ls got damage from source that couldnt find its dealer!\n",p_actor->GetUniqueId().c_str());
				//source->PrintToStderr();
			}
		}
		else
		{
			//fprintf(stderr,"Physical %ls got damage from unknown source!\n",p_actor->GetUniqueId().c_str());
		}
	}
	*/
}//namespace logic
