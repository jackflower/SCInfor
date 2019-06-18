//  __________________________________
// | Robot.cpp - class implementation |
// | Jack Flower - June 2016          |
// |__________________________________|
//

#include "Robot.h"
#include "../../../../Rendering/Animations/AnimSet.h"
#include "../../../../Rendering/Animations/Animation.h"
#include "../../../../Rendering/Animations/AnimationState.h"
#include "../../../../Rendering/Drawable/Layers.h"
#include "../../../../Rendering/Displayable/Displayable.h"
#include "../../../../Game/Game.h"

using namespace rendering::animation;
using namespace rendering::displayable;

namespace logic
{
	namespace unit
	{
		RTTI_IMPL(Robot, Unit);

		Robot::Robot(const std::wstring & uniqueId)
		:
			Unit{ uniqueId }, //chroniony konstruktor klasy bazowej
			m_robot_state{ ERobotState::ROBOT_DEFAULT },
			m_strategy_duration{},
			m_elapsed_time{ 0.0f }
		{
		}

		//Chroniony konstruktor kopiujący
		Robot::Robot(const Robot & RobottCopy)
		:
			Unit (RobottCopy), //chroniony konstruktor kopiujący klasy bazowej
			m_robot_state{ RobottCopy.m_robot_state },
			m_strategy_duration{ RobottCopy.m_strategy_duration },
			m_elapsed_time{ RobottCopy.m_elapsed_time }
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		Robot::~Robot()
		{
			//~Unit()
			m_robot_state = ERobotState::ROBOT_DEFAULT;
			m_strategy_duration;
			m_elapsed_time = 0.0f;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Robot::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca stałą referencję na obiekt klasy StrategyDuration
		const StrategyDuration & Robot::getStrategyDuration() const
		{
			return m_strategy_duration;
		}

		//Metoda ustawia referencję na obiekt klasy StrategyDuration
		void Robot::setStrategyDuration(const StrategyDuration & strategy_duration)
		{
			m_strategy_duration = strategy_duration;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		void Robot::updateAnimations(float dt)
		{
			switch (m_robot_state)
			{
			case ERobotState::ROBOT_DEFAULT:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadDefaultAnim());
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_ATTACK_PREPARE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadAttackOpenAnim());
					getDisplayableHead()->getAnimationState()->setLooped(false);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_ATTACK_DURING:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadAttackAnim());
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_ATTACK_TERMINATE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadAttackCloseAnim());
					getDisplayableHead()->getAnimationState()->setLooped(false);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_DEFENSE_PREPARE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadDefenseOpenAnim());
					getDisplayableHead()->getAnimationState()->setLooped(false);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_DEFENSE_DURING:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadDefenseAnim());
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_DEFENSE_TERMINATE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadDefenseCloseAnim());
					getDisplayableHead()->getAnimationState()->setLooped(false);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(false);
				}
				break;
			}
			case ERobotState::ROBOT_DAMAGE:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadDamageAnim());
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case ERobotState::ROBOT_DEATH:
			{
				if (p_anim_set)
				{
					//setAnimationBody(p_anim_set->GetRobotBodyDefaultAnim());
					setAnimationHead(p_anim_set->getRobotHeadDeathAnim());
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualan metoda zabija obiekt klasy Actor i wywołuje odpowiednie czynności z tym związane
		void Robot::kill()
		{
			//
		}

		//Wirtualna metoda aktualizująca obiekt
		void Robot::update(float dt)
		{
			updateState(dt);
			updateAnimations(dt);
			Physical::updateShadow(dt);
			Actor::updateComponents(dt);
		}

		void Robot::updateState(float dt)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (m_robot_state != ERobotState::ROBOT_ATTACK_DURING && Unit::m_strategy_controller.getStrategyState() == EStrategyState::NEUTRAL)
				{
					fprintf(stderr, "Attack...\n");
					Unit::m_strategy_controller.attack();
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (m_robot_state != ERobotState::ROBOT_DEFENSE_DURING && Unit::m_strategy_controller.getStrategyState() == EStrategyState::NEUTRAL)
				{
					fprintf(stderr, "Defense...\n");
					Unit::m_strategy_controller.defense();
				}
			}

			//a t t a c k
			if (Unit::m_strategy_controller.getStrategyState() == EStrategyState::ATTACK)
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
						Unit::m_strategy_controller.setStrategyState(EStrategyState::NEUTRAL);
						m_elapsed_time = 0;
					}
				}
			}

			//d e f e n s e
			if (Unit::m_strategy_controller.getStrategyState() == EStrategyState::DEFENSE)
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
						Unit::m_strategy_controller.setStrategyState(EStrategyState::NEUTRAL);
						m_elapsed_time = 0;
					}
				}
			}
		}

	}//namespace unit
}//namespace logic
