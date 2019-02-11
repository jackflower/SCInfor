//  ___________________________________
// | CRobot.cpp - class implementation |
// | Jack Flower - June 2016           |
// |___________________________________|
//

#include "CRobot.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../Rendering/Animations/CAnimation.h"
#include "../../../../Rendering/Animations/CAnimationState.h"
#include "../../../../Rendering/Drawable/Layers.h"
#include "../../../../Rendering/Displayable/CDisplayable.h"
#include "../../../../Game/Game.h"

using namespace rendering::animation;
using namespace rendering::displayable;

namespace logic
{
	namespace unit
	{
		RTTI_IMPL(CRobot, CUnit);

		CRobot::CRobot(const std::wstring& uniqueId)
		:
			CUnit					(uniqueId),	//chroniony konstruktor klasy bazowej
			m_robot_state			(ERobotState::ROBOT_DEFAULT),
			m_strategy_duration		(),
			m_elapsed_time			(0.0f)
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CRobot::CRobot(const CRobot & CRobottCopy)
		:
			CUnit					(CRobottCopy),	//chroniony konstruktor kopiuj¹cy klasy bazowej
			m_robot_state			(CRobottCopy.m_robot_state),
			m_strategy_duration		(CRobottCopy.m_strategy_duration),
			m_elapsed_time			(CRobottCopy.m_elapsed_time)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CRobot::~CRobot()
		{
			//CUnit					not edit
			m_robot_state			= ERobotState::ROBOT_DEFAULT;
			//m_strategy_duration	not edit
			m_elapsed_time			= 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CRobot::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca sta³¹ referencjê na obiekt klasy CStrategyDuration
		const CStrategyDuration & CRobot::getStrategyDuration() const
		{
			return m_strategy_duration;
		}

		//Metoda ustawia referencjê na obiekt klasy CStrategyDuration
		void CRobot::setStrategyDuration(const CStrategyDuration & strategy_duration)
		{
			m_strategy_duration = strategy_duration;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		void CRobot::updateAnimations(float dt)
		{
			switch (m_robot_state)
			{
			case ERobotState::ROBOT_DEFAULT:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadDefaultAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(true);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_ATTACK_PREPARE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadAttackOpenAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(false);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_ATTACK_DURING:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadAttackAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(true);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_ATTACK_TERMINATE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadAttackCloseAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(false);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_DEFENSE_PREPARE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadDefenseOpenAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(false);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_DEFENSE_DURING:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadDefenseAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(true);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_DEFENSE_TERMINATE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadDefenseCloseAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(false);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_DAMAGE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadDamageAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(true);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_DEATH:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->GetRobotHeadDeathAnim());
					getDisplayableHead()->GetAnimationState()->SetLooped(true);
					getDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualan metoda zabija obiekt klasy Actor i wywo³uje odpowiednie czynnoœci z tym zwi¹zane
		void CRobot::kill()
		{
			//to do...
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CRobot::update(float dt)
		{
			//Physical::update(dt);
			//Actor::update(dt);

			updateState(dt);
			updateAnimations(dt);
			Physical::updateShadow(dt);
			Actor::updateComponents(dt);
		}

		void CRobot::updateState(float dt)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (m_robot_state != ERobotState::ROBOT_ATTACK_DURING && CUnit::m_strategy_controller.getStrategyState() == EStrategyState::NEUTRAL)
				{
					fprintf(stderr, "Attack...\n");
					CUnit::m_strategy_controller.Attack();
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (m_robot_state != ERobotState::ROBOT_DEFENSE_DURING && CUnit::m_strategy_controller.getStrategyState() == EStrategyState::NEUTRAL)
				{
					fprintf(stderr, "Defense...\n");
					CUnit::m_strategy_controller.Defense();
				}
			}

			//a t t a c k
			if (CUnit::m_strategy_controller.getStrategyState() == EStrategyState::ATTACK)
			{
				m_elapsed_time += dt;

				if (m_robot_state == ERobotState::ROBOT_DEFENSE_DURING)
					m_robot_state = ERobotState::ROBOT_DEFENSE_TERMINATE;

				if (m_robot_state == ERobotState::ROBOT_DEFENSE_TERMINATE)
				{
					if (m_elapsed_time >= m_strategy_duration.getTimeDefensePrepare())
					{
						m_robot_state = ERobotState::ROBOT_ATTACK_PREPARE;
						m_elapsed_time = 0.0f;
					}
				}
				else
				{
					m_robot_state = ERobotState::ROBOT_ATTACK_PREPARE;
					if (m_elapsed_time >= m_strategy_duration.getTimeAttackPrepare())
					{
						m_robot_state = ERobotState::ROBOT_ATTACK_DURING;
						CUnit::m_strategy_controller.setStrategyState(EStrategyState::NEUTRAL);
						m_elapsed_time = 0;
					}
				}
			}

			//d e f e n s e
			if (CUnit::m_strategy_controller.getStrategyState() == EStrategyState::DEFENSE)
			{
				m_elapsed_time += dt;

				if (m_robot_state == ERobotState::ROBOT_ATTACK_DURING)
					m_robot_state = ERobotState::ROBOT_ATTACK_TERMINATE;

				if (m_robot_state == ERobotState::ROBOT_ATTACK_TERMINATE)
				{
					if (m_elapsed_time >= m_strategy_duration.getTimeAttackTerminate())
					{
						m_robot_state = ERobotState::ROBOT_DEFENSE_PREPARE;
						m_elapsed_time = 0.0f;
					}
				}
				else
				{
					m_robot_state = ERobotState::ROBOT_DEFENSE_PREPARE;
					if (m_elapsed_time >= m_strategy_duration.getTimeDefensePrepare())
					{
						m_robot_state = ERobotState::ROBOT_DEFENSE_DURING;
						CUnit::m_strategy_controller.setStrategyState(EStrategyState::NEUTRAL);
						m_elapsed_time = 0;
					}
				}
			}
		}

	}//namespace unit
}//namespace logic
