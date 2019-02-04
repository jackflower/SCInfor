//  ___________________________________________
// | CParticleState.h - class definition       |
// | Jack Flower - May 2016                    |
// |___________________________________________|
//

#ifndef H_PARTICLE_MODIFIER_JACK
#define H_PARTICLE_MODIFIER_JACK

#include "../../RTTI/RTTI.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

namespace particle
{
	///
	///Klasa reprezentuje stan cz�steczki
	///
	class CParticleState
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CParticleState();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & ParticleStateCopy - sta�a referencja na obiekt klasy CParticleState
		///
		CParticleState(const CParticleState & ParticleStateCopy);

		///
		///Destruktor
		///
		~CParticleState();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

	public:
		sf::Color		m_color;	//kolor cz�steczki
		float			m_angle;	//k�t obr�tu - rotacja cz�steczki
		sf::Vector2f	m_size;		//rozmiar cz�steczki
	};
}//namespace particle
#endif//H_PARTICLE_MODIFIER_JACK
