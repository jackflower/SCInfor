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

	//Metoda ustawia stan i prêdkoœæ obiekty
	void CActorController::SetSpeed(float speed)
	{
		if (p_actor->getSpawnState() == SPAWN_STATE_ALIVE)
		{
			//uwzglêdniam strafe
			sf::Vector2f dir = RotationToVector((float)p_actor->GetRotationBody());//body
			sf::Vector2f move;

			//jeœli aktor strzela, ostrzeliwuje siê...
			if (m_strafe != 0)
			{
				move += VectorRightOf(dir) * (float) m_strafe;
				//stan - obiekt ostrzeliwuje siê, trwa wymiana ognia...
				p_actor->setMoveState(MOVE_STATE_STRAFING);
			}

			//jeœli aktor siê porusza...
			if(m_move != 0)
			{
				move += dir * (float) m_move;
				//stan - obiekt porusza siê, idzie, spaceruje, jest w ruchu
				p_actor->setMoveState(MOVE_STATE_WALKING);
			}

			//jeœli obiekt siê nie porusza i siê nie ostrzeliwuje (iddle....)
			if ((m_move == 0) && (m_strafe == 0))
				return;

			move = Normalize(move);//normalizacja wektora

			p_actor->SetVelocity(move * speed);//ustawienie prêdkoœci
		}
	}

	//Metoda ustawia stan i wykonuje obrót
	void CActorController::TurnBy(float rotation)
	{
		//jeœli aktor ¿yje...
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

	//Wirtualan metoda aktualizuj¹ca obiekt
	void CActorController::update(float dt)
	{
		//przed zejœciem z tego œwiata, obiekt siê zatrzymuje...
	    if (p_actor->getSpawnState() != SPAWN_STATE_ALIVE)
		{
	        p_actor->SetVelocity(sf::Vector2f(0.0f,0.0f));
	    }

		p_actor->setMoveState(MOVE_STATE_STANDING);
		m_move = 0;
		m_strafe = 0;
	}

	//Metoda zwraca wartoœæ obrotu obiektu
	const float CActorController::GetTrueRot() const
	{
		return m_true_rot;
	}

	//Metoda ustawia wartoœæ obrotu obiektu
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
