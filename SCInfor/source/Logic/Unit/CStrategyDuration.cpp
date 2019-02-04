//  ______________________________________________
// | CStrategyDuration.cpp - class implementation |
// | Jack Flower - July 2016                      |
// |______________________________________________|
//

#include "CStrategyDuration.h"

RTTI_IMPL_NOPARENT(CStrategyDuration);

//Konstruktor
CStrategyDuration::CStrategyDuration()
:
	m_time_attack_prepare		(0.0f),
	m_time_attack_terminate		(0.0f),
	m_time_defense_prepare		(0.0f),
	m_time_defense_terminate	(0.0f)
{
}

//Konstruktor kopiuj¹cy
CStrategyDuration::CStrategyDuration(const CStrategyDuration & CStrategyDurationCopy)
:
	m_time_attack_prepare		(CStrategyDurationCopy.m_time_attack_prepare),
	m_time_attack_terminate		(CStrategyDurationCopy.m_time_attack_terminate),
	m_time_defense_prepare		(CStrategyDurationCopy.m_time_defense_prepare),
	m_time_defense_terminate	(CStrategyDurationCopy.m_time_defense_terminate)
{
}

//Destruktor
CStrategyDuration::~CStrategyDuration()
{
	m_time_attack_prepare		= 0.0f;
	m_time_attack_terminate		= 0.0f;
	m_time_defense_prepare		= 0.0f;
	m_time_defense_terminate	= 0.0f;
}

//Metoda zwraca typ obiektu /RTTI/
const std::string CStrategyDuration::GetType() const
{
	return rtti.GetNameClass();
}

//Metoda zwraca czas przygotowania do stanu ataku
const float CStrategyDuration::getTimeAttackPrepare() const
{
	return m_time_attack_prepare;
}

//Metoda ustawia czas przygotowania do stanu ataku
void CStrategyDuration::setTimeAttackPrepare(const float time_attack_prepare)
{
	m_time_attack_prepare = time_attack_prepare;
}

//Metoda zwraca czas zakoñczenia stanu ataku
const float CStrategyDuration::getTimeAttackTerminate() const
{
	return m_time_attack_terminate;
}

//Metoda ustawia czas do zakoñczenia stanu ataku
void CStrategyDuration::setTimeAttackTerminate(const float time_attack_terminate)
{
	m_time_attack_terminate = time_attack_terminate;
}

//Metoda zwraca czas przygotowania do stanu obrony
const float CStrategyDuration::getTimeDefensePrepare() const
{
	return m_time_defense_prepare;
}

//Metoda ustawia czas przygotowania do stanu obrony
void CStrategyDuration::setTimeDefensePrepare(const float time_defense_prepare)
{
	m_time_defense_prepare = time_defense_prepare;
}

//Metoda zwraca czas zakoñczenia stanu obrony
const float CStrategyDuration::getTimeDefenseTerminate() const
{
	return m_time_defense_terminate;
}

//Metoda ustawia czas do zakoñczenia stanu obrony
void CStrategyDuration::setTimeDefenseTerminate(const float time_defense_terminate)
{
	m_time_defense_terminate = time_defense_terminate;
}
