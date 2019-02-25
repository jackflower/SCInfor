//  __________________________________________
// | ParticleState.h - class definition       |
// | Jack Flower - May 2016                   |
// |__________________________________________|
//

#ifndef H_PARTICLE_MODIFIER_JACK
#define H_PARTICLE_MODIFIER_JACK

#include "../../RTTI/RTTI.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace particle
{
	///
	///Klasa reprezentuje stan cząsteczki
	///
	class ParticleState
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		ParticleState();

		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referencja na obiekt klasy ParticleState
		///
		ParticleState(const ParticleState & copy);

		///
		///Konstruktor przenoszący
		///
		///@param other - referencja do r-wartości
		///
		ParticleState(ParticleState && other);

		///
		///Destruktor
		///
		~ParticleState();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Przeciążony operator przypisania kopiowania
		///
		///@param copy - stała referencja na obiekt klasy Particle
		///
		ParticleState & operator=(const ParticleState & copy);

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		ParticleState & operator=(ParticleState && other);


	public:
		sf::Color m_color; //kolor cząsteczki
		float m_angle; //kąt obrótu - rotacja cząsteczki
		sf::Vector2f m_size; //rozmiar cząsteczki
	};
}//namespace particle
#endif//H_PARTICLE_MODIFIER_JACK
