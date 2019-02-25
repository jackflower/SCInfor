//  _____________________________________
// | Particle.h - class definition       |
// | Jack Flower - May 2016              |
// |_____________________________________|
//

#ifndef H_PARTICLE_JACK
#define H_PARTICLE_JACK

#include "ParticleState.h"
#include "../../RTTI/RTTI.h"

namespace particle
{
	///
	///Klasa reprezentuje cząsteczkę
	///
	class Particle
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		Particle();

		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referencja na obiekt klasy Particle
		///
		Particle(const Particle & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other - referencja do r-wartości
		///
		Particle(Particle && other);

		///
		///Destruktor
		///
		~Particle();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy Particle
		///
		Particle & operator=(const Particle & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		Particle & operator=(Particle && other);

		
		ParticleState m_current; //aktualne parametry cząsteczki
		ParticleState m_change; //docelowe parametry cząsteczki 
		sf::Vector2f m_position; //pozycja cząsteczki
		sf::Vector2f m_velocity; //prędkość cząsteczki (składowe x i y)
		float m_change_duration; //czas w jakim cząsteczka ma przejść w stan docelowy

		///
		///Metoda aktualizuje parametry cząsteczki zanim cząsteczka przejdzie w stan docelowy
		///
		void CalculateChange();

	private:

		Particle *p_next_particle;	//wskaźnik ma następną cząsteczkę
		Particle *p_prev_particle;	//wskaźnik ma poprzednią cząsteczkę
	};
}//namespace particle
#endif//H_PARTICLE_JACK
