//  __________________________________________
// | ParticleState.cpp - class implementation |
// | Jack Flower - May 2016                   |
// |__________________________________________|
//

#include "ParticleState.h"

namespace particle
{
	RTTI_IMPL_NOPARENT(ParticleState);

	//Konstruktor
	ParticleState::ParticleState()
	:
		m_color{},
		m_angle{ 0.0f },
		m_size{ 0.0f, 0.0f }
	{
	}

	//Konstruktor kopiujący
	ParticleState::ParticleState(const ParticleState & copy)
	:
		m_color{ copy.m_color },
		m_angle{ copy.m_angle },
		m_size{ copy.m_size }
	{
	}

	//Konstruktor przenoszący
	ParticleState::ParticleState(ParticleState && other)
	:
		m_color{ other.m_color }, //konstruktor przenoszący klasy bazowej
		m_angle{ other.m_angle },
		m_size{ other.m_size }
	{
		//zerujemy składowe obiektu źródłowego...
		other.m_color;
		other.m_angle = 0.f;
		other.m_size.x = 0.f;
		other.m_size.y = 0.f;
	}

	//Destruktor
	ParticleState::~ParticleState()
	{
		m_color;
		m_angle = 0.0f;
		m_size.x = 0.0f;
		m_size.y = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string ParticleState::getType() const
	{
		return rtti.GetNameClass();
	}

	//Przeciążony operator przypisania kopiowania
	ParticleState & ParticleState::operator=(const ParticleState & copy)
	{
		if (this != &copy)
		{
			m_color = copy.m_color;
			m_angle = copy.m_angle;
			m_size = copy.m_size;
		}
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	ParticleState & ParticleState::operator=(ParticleState && other)
	{
		if (this != &other)
		{
			m_color = other.m_color;
			m_angle = other.m_angle;
			m_size = other.m_size;

			//zerowanie obiektu źródłowego
			other.m_color;
			other.m_angle = 0.0f;
			other.m_size.x = 0.0f;
			other.m_size.y = 0.0f;
		}
		return *this;
	}
}//namespace particle
