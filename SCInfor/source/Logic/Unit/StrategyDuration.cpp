//  _____________________________________________
// | StrategyDuration.cpp - class implementation |
// | Jack Flower - July 2016                     |
// |_____________________________________________|
//

#include "StrategyDuration.h"

RTTI_IMPL_NOPARENT(StrategyDuration);

//Konstruktor
StrategyDuration::StrategyDuration()
:
	m_time_attack_prepare{ 0.0f },
	m_time_attack_terminate{ 0.0f },
	m_time_defense_prepare{ 0.0f },
	m_time_defense_terminate{ 0.0f }
{
}

//Konstruktor kopiujący
StrategyDuration::StrategyDuration(const StrategyDuration & StrategyDurationCopy)
:
	m_time_attack_prepare{ StrategyDurationCopy.m_time_attack_prepare },
	m_time_attack_terminate{ StrategyDurationCopy.m_time_attack_terminate },
	m_time_defense_prepare{ StrategyDurationCopy.m_time_defense_prepare },
	m_time_defense_terminate{ StrategyDurationCopy.m_time_defense_terminate }
{
}

//Destruktor
StrategyDuration::~StrategyDuration()
{
	m_time_attack_prepare = 0.0f;
	m_time_attack_terminate = 0.0f;
	m_time_defense_prepare = 0.0f;
	m_time_defense_terminate = 0.0f;
}

//Metoda zwraca typ obiektu /RTTI/
const std::string StrategyDuration::getType() const
{
	return rtti.getNameClass();
}

//Metoda zwraca czas przygotowania do stanu ataku
const float StrategyDuration::getTimeAttackPrepare() const
{
	return m_time_attack_prepare;
}

//Metoda ustawia czas przygotowania do stanu ataku
void StrategyDuration::setTimeAttackPrepare(const float time_attack_prepare)
{
	m_time_attack_prepare = time_attack_prepare;
}

//Metoda zwraca czas zakończenia stanu ataku
const float StrategyDuration::getTimeAttackTerminate() const
{
	return m_time_attack_terminate;
}

//Metoda ustawia czas do zakończenia stanu ataku
void StrategyDuration::setTimeAttackTerminate(const float time_attack_terminate)
{
	m_time_attack_terminate = time_attack_terminate;
}

//Metoda zwraca czas przygotowania do stanu obrony
const float StrategyDuration::getTimeDefensePrepare() const
{
	return m_time_defense_prepare;
}

//Metoda ustawia czas przygotowania do stanu obrony
void StrategyDuration::setTimeDefensePrepare(const float time_defense_prepare)
{
	m_time_defense_prepare = time_defense_prepare;
}

//Metoda zwraca czas zakończenia stanu obrony
const float StrategyDuration::getTimeDefenseTerminate() const
{
	return m_time_defense_terminate;
}

//Metoda ustawia czas do zakończenia stanu obrony
void StrategyDuration::setTimeDefenseTerminate(const float time_defense_terminate)
{
	m_time_defense_terminate = time_defense_terminate;
}
