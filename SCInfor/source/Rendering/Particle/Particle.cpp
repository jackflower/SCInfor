//  _____________________________________
// | Particle.cpp - class implementation |
// | Jack Flower - May 2016              |
// |_____________________________________|
//

#include "Particle.h"

namespace particle
{
	RTTI_IMPL_NOPARENT(Particle);

	//Konstruktor
	Particle::Particle()
	{
	}

	//Konstruktor kopiujący
	Particle::Particle(const Particle & copy)
	:
		m_current{ copy.m_current }, //konstruktor przenoszący klasy bazowej
		m_change{ copy.m_change },
		m_position{ copy.m_position },
		m_velocity{ copy.m_velocity },
		m_change_duration{ copy.m_change_duration },
		p_next_particle{ copy.p_next_particle },
		p_prev_particle{ copy.p_prev_particle }
	{
	}

	//Konstruktor przenoszący
	Particle::Particle(Particle && other)
	:
		m_current{ other.m_current }, //konstruktor przenoszący klasy bazowej
		m_change{ other.m_change },
		m_position{ other.m_position },
		m_velocity{ other.m_velocity },
		m_change_duration{ other.m_change_duration },
		p_next_particle{ other.p_next_particle },
		p_prev_particle{ other.p_prev_particle }
	{
		//zerujemy składowe obiektu źródłowego...
		other.m_current;
		other.m_change;
		other.m_position.x = 0.f;
		other.m_position.y = 0.f;
		other.m_velocity.x = 0.f;
		other.m_velocity.y = 0.f;
		other.m_change_duration = 0.0f;
		//zwalniamy wskaźnik na dane obiektu źródłowego tak,
		//aby destruktor nie zwalniał pamięci wielokrotnie
		other.p_next_particle = nullptr;
		other.p_prev_particle = nullptr;
	}

	//Destruktor
	Particle::~Particle()
	{
		//m_current
		//m_change
		m_position.x = 0.0f;
		m_position.y = 0.0f;
		m_velocity.x = 0.0f;
		m_velocity.y = 0.0f;
		m_change_duration = 0.0f;
		p_next_particle = nullptr;
		p_prev_particle = nullptr;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Particle::getType() const
	{
		return rtti.GetNameClass();
	}

	//Przeciążony operator przypisania kopiowania
	Particle & Particle::operator=(const Particle & copy)
	{
		if (this != &copy)
		{
			m_current = copy.m_current;
			m_change = copy.m_change;
			m_position = copy.m_position;
			m_velocity = copy.m_velocity;
			m_change_duration = copy.m_change_duration;

			//zwalaniamy dane pod wskaźnikiem
			delete p_next_particle;
			delete p_prev_particle;
			//tworzymy nowy obiekt na podstawie obiektu źródłowego
			p_next_particle = new Particle(*copy.p_next_particle);
			p_prev_particle = new Particle(*copy.p_prev_particle);
		}
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	Particle & Particle::operator=(Particle && other)
	{
		if (this != &other)
		{
			m_current = other.m_current;
			m_change = other.m_change;
			m_position = other.m_position;
			m_velocity = other.m_velocity;
			m_change_duration = other.m_change_duration;

			//zwalaniamy dane pod wskaźnikiem
			delete p_next_particle;
			delete p_prev_particle;
			//przenosimy pod wskaźnik dane z obiektu źródłowego
			p_next_particle = other.p_next_particle;
			p_prev_particle = other.p_prev_particle;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_next_particle = nullptr;
			other.p_prev_particle = nullptr;

			//zerowanie obiektu źródłowego
			other.m_current;
			other.m_change;
			other.m_position.x = 0.0f;
			other.m_position.y = 0.0f;
			other.m_velocity.x = 0.0f;
			other.m_velocity.y = 0.0f;
			other.m_change_duration = 0.0f;
		}
		return *this;
	}

	void Particle::CalculateChange()
	{
		m_change.m_color.a = (sf::Uint8)(((float)m_change.m_color.a - (float)m_current.m_color.a) / m_change_duration);
		m_change.m_angle = (m_change.m_angle - m_current.m_angle) / m_change_duration;
		m_change.m_size = (m_change.m_size - m_current.m_size) / m_change_duration;
	}
}//namespace particle
