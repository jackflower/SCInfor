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
	///Klasa reprezentuje cz¹steczkê
	///
	class CParticle
	{
	public:

		///
		///Konstruktor
		///
		CParticle();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param & CParticleCopy - sta³a referencja na obiekt klasy CParticle
		///
		CParticle(const CParticle & CParticleCopy);

		///
		///Destruktor
		///
		~CParticle();

		
		CParticleState	m_current;			//aktualne parametry cz¹steczki
		CParticleState	m_change;			//docelowe parametry cz¹steczki 
		sf::Vector2f	m_position;			//pozycja cz¹steczki
		sf::Vector2f	m_velocity;			//prêdkoœæ cz¹steczki (sk³adowe x i y)
		float			m_change_duration;	//czas w jakim cz¹steczka ma przejœæ w stan docelowy

		///
		///Metoda aktualizuje parametry cz¹steczki zanim cz¹steczka przejdzie w stan docelowy
		///
		void CalculateChange();

	private:

		CParticle* p_next_particle;	//wskaŸnik ma nastêpn¹ cz¹steczkê
		CParticle* p_prev_particle;	//wskaŸnik ma poprzedni¹ cz¹steczkê
	};
}//namespace particle
#endif//H_PARTICLE_JACK
