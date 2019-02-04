//  ___________________________________________
// | CParticleState.cpp - class implementation |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#include "CParticleState.h"

namespace particle
{
	RTTI_IMPL_NOPARENT(CParticleState);

	//Konstruktor
	CParticleState::CParticleState()
	:
		m_color	(),
		m_angle	(0.0f),
		m_size	(0.0f, 0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CParticleState::CParticleState(const CParticleState & ParticleStateCopy)
	:
		m_color	(ParticleStateCopy.m_color),
		m_angle	(ParticleStateCopy.m_angle),
		m_size	(ParticleStateCopy.m_size)
	{
	}

	//Destruktor
	CParticleState::~CParticleState()
	{
		//m_color	not edit
		m_angle		= 0.0f;
		m_size.x	= 0.0f;
		m_size.y	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CParticleState::GetType() const
	{
		return rtti.GetNameClass();
	}

}//namespace particle
