//  _______________________________________________
// | StrategyController.cpp - class implementation |
// | Jack Flower - June 2016                       |
// |_______________________________________________|
//

#include "StrategyController.h"

RTTI_IMPL_NOPARENT(StrategyController);

//Konstruktor
StrategyController::StrategyController()
:
	 m_strategy_state(EStrategyState::NEUTRAL)
{
}

//Konstruktor kopiujący
StrategyController::StrategyController(const StrategyController & StrategyControllerCopy)
:
	m_strategy_state(StrategyControllerCopy.m_strategy_state)
{
}

//Destruktor
StrategyController::~StrategyController()
{
	m_strategy_state = EStrategyState::NEUTRAL;
}

//Metoda zwraca typ obiektu /RTTI/
const std::string StrategyController::getType() const
{
	return rtti.getNameClass();
}

//Metoda ustawia strategię ataku
void StrategyController::attack()
{
	m_strategy_state = EStrategyState::ATTACK;
}

//Metoda ustawia strategię obrony
void StrategyController::defense()
{
	m_strategy_state = EStrategyState::DEFENSE;
}

//Metoda ustawia strategię neutralności
void StrategyController::neutral()
{
	m_strategy_state = EStrategyState::NEUTRAL;
}

//Metoda zwraca stan strategii
const EStrategyState & StrategyController::getStrategyState() const
{
	return m_strategy_state;
}

//Metoda ustawia stan strategii
void StrategyController::setStrategyState(const EStrategyState & strategy_state)
{
	m_strategy_state = strategy_state;
}
