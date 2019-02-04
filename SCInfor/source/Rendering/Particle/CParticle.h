//  ______________________________________
// | CParticle.h - class definition       |
// | Jack Flower - May 2016               |
// |______________________________________|
//

#ifndef H_PARTICLE_JACK
#define H_PARTICLE_JACK

#include "CParticleState.h"

namespace particle
{
	///
	///Klasa reprezentuje cz�steczk�
	///
	class CParticle
	{
	public:

		///
		///Konstruktor
		///
		CParticle();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CParticleCopy - sta�a referencja na obiekt klasy CParticle
		///
		CParticle(const CParticle & CParticleCopy);

		///
		///Destruktor
		///
		~CParticle();

		
		CParticleState	m_current;			//aktualne parametry cz�steczki
		CParticleState	m_change;			//docelowe parametry cz�steczki 
		sf::Vector2f	m_position;			//pozycja cz�steczki
		sf::Vector2f	m_velocity;			//pr�dko�� cz�steczki (sk�adowe x i y)
		float			m_change_duration;	//czas w jakim cz�steczka ma przej�� w stan docelowy

		///
		///Metoda aktualizuje parametry cz�steczki zanim cz�steczka przejdzie w stan docelowy
		///
		void CalculateChange();

	private:

		CParticle* p_next_particle;	//wska�nik ma nast�pn� cz�steczk�
		CParticle* p_prev_particle;	//wska�nik ma poprzedni� cz�steczk�
	};
}//namespace particle
#endif//H_PARTICLE_JACK
