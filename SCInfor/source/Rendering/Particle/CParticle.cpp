//  ______________________________________
// | CParticle.cpp - class implementation |
// | Jack Flower - May 2016               |
// |______________________________________|
//

#include "CParticle.h"

namespace particle
{
	//Konstruktor
	CParticle::CParticle()
	{
	}

	//Konstruktor kopiuj¹cy
	CParticle::CParticle(const CParticle & CParticleCopy)
	{
	}

	//Destruktor
	CParticle::~CParticle()
	{
	}

	void CParticle::CalculateChange()
	{
		m_change.m_color.a = (sf::Uint8)(((float)m_change.m_color.a - (float)m_current.m_color.a) / m_change_duration);
		m_change.m_angle = (m_change.m_angle - m_current.m_angle) / m_change_duration;
		m_change.m_size = (m_change.m_size - m_current.m_size) / m_change_duration;

		//note:
		//w czasie testów pobawiæ siê kolorami...
	}
}//namespace particle

