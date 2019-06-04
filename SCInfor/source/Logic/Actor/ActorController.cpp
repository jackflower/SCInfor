//  __________________________________________
// | ActorController.h - class implementation |
// | Jack Flower April 2015                   |
// |__________________________________________|
//

#include "ActorController.h"
#include "Actor.h"
#include "../../Utilities/Translation/Directions.h"
#include "../../Utilities/MathFunctions/MathFunctions.h"
#include <cmath>

using namespace maths;
using namespace translation;

namespace logic
{

	RTTI_IMPL_NOPARENT(ActorController);
	
	//Konstruktor
	ActorController::ActorController(Actor *actor)
	:
		p_actor{ actor },
		m_strafe{ 0 },
		m_move{ 0 },
		m_true_rot{ 0.0f }
	{
	}

	//Destruktor wirtualny
	ActorController::~ActorController()
	{
		p_actor = NULL;
		m_strafe = 0;
		m_move = 0;
		m_true_rot = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ActorController::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda ustawia stan i prędkość obiekty
	void ActorController::setSpeed(float speed)
	{
		if (p_actor->getSpawnState() == SPAWN_STATE_ALIVE)
		{
			//uwzględniam strafe
			sf::Vector2f dir = RotationToVector((float)p_actor->getRotationBody());//body
			sf::Vector2f move;

			//jeśli aktor strzela, ostrzeliwuje się...
			if (m_strafe != 0)
			{
				move += VectorRightOf(dir) * (float) m_strafe;
				//stan - obiekt ostrzeliwuje się, trwa wymiana ognia...
				p_actor->setMoveState(MOVE_STATE_STRAFING);
			}

			//jeśli aktor się porusza...
			if(m_move != 0)
			{
				move += dir * (float) m_move;
				//stan - obiekt porusza się, idzie, spaceruje, jest w ruchu
				p_actor->setMoveState(MOVE_STATE_WALKING);
			}

			//jeśli obiekt się nie porusza i się nie ostrzeliwuje (iddle....)
			if ((m_move == 0) && (m_strafe == 0))
				return;

			move = Normalize(move);//normalizacja wektora

			p_actor->setVelocity(move * speed);//ustawienie prędkości
		}
	}

	//Metoda ustawia stan i wykonuje obrót
	void ActorController::turnBy(float rotation)
	{
		//jeśli aktor żyje...
	    if (p_actor->getSpawnState() == SPAWN_STATE_ALIVE)
		{
	        m_true_rot += rotation;
	        while (m_true_rot < 0.0f) m_true_rot += 360.0f;
	        while (m_true_rot > 360.0f) m_true_rot -= 360.0f;
			p_actor->setRotationBody(m_true_rot);//body
	        if ((rotation >= 0.001f) || (rotation <= -0.001))
				p_actor->setMoveState(MOVE_STATE_TURNING);
	    }
	}



	//Metoda zwraca wartość obrotu obiektu
	const float ActorController::getTrueRot() const
	{
		return m_true_rot;
	}

	//Metoda ustawia wartość obrotu obiektu
	void ActorController::setTrueRot(float true_rotation)
	{
		m_true_rot = true_rotation;
	}

	//Metoda ustawia kierunek ruchu
	void ActorController::setMove(int move)
	{
		m_move = move;
	}

	//Wirtualan metoda aktualizująca obiekt
	void ActorController::update(float dt)
	{
		//przed zejściem z tego świata, obiekt się zatrzymuje...
		if (p_actor->getSpawnState() != SPAWN_STATE_ALIVE)
		{
			p_actor->setVelocity(sf::Vector2f(0.0f, 0.0f));
		}

		p_actor->setMoveState(MOVE_STATE_STANDING);
		m_move = 0;
		m_strafe = 0;
	}

	//Metoda ustawia stan i wykonuje strafe
	void ActorController::setStrafe(int strafe)
	{
		m_strafe = strafe;
	}

	/*
	void ActorController::GotDamageFrom(float dmg, EffectSourcePtr source)
	{
		if (source != EffectSourcePtr(NULL))
		{
			Physical *dealer = source->DeterminePhysicalSource();
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
