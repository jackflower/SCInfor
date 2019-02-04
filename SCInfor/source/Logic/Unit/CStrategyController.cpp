//  ________________________________________________
// | CStrategyController.cpp - class implementation |
// | Jack Flower - June 2016                        |
// |________________________________________________|
//

#include "CStrategyController.h"

RTTI_IMPL_NOPARENT(CStrategyController);

//Konstruktor
CStrategyController::CStrategyController()
:
	 m_strategy_state(EStrategyState::NEUTRAL)
{
}

//Konstruktor kopiuj�cy
CStrategyController::CStrategyController(const CStrategyController & CStrategyControllerCopy)
:
	m_strategy_state(CStrategyControllerCopy.m_strategy_state)
{
}

//Destruktor
CStrategyController::~CStrategyController()
{
	m_strategy_state = EStrategyState::NEUTRAL;
}

//Metoda zwraca typ obiektu /RTTI/
const std::string CStrategyController::GetType() const
{
	return rtti.GetNameClass();
}

//Metoda ustawia strategi� ataku
void CStrategyController::Attack()
{
	m_strategy_state = EStrategyState::ATTACK;
}

//Metoda ustawia strategi� obrony
void CStrategyController::Defense()
{
	m_strategy_state = EStrategyState::DEFENSE;
}

//Metoda ustawia strategi� neutralno�ci
void CStrategyController::Neutral()
{
	m_strategy_state = EStrategyState::NEUTRAL;
}

//Metoda zwraca stan strategii
const EStrategyState & CStrategyController::getStrategyState() const
{
	return m_strategy_state;
}

//Metoda ustawia stan strategii
void CStrategyController::setStrategyState(const EStrategyState & strategy_state)
{
	m_strategy_state = strategy_state;
}
