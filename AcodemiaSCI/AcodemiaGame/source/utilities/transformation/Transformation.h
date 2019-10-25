//  ____________________________________________
// | CTransformation.h - class definition       |
// | Jack Flower - May 2016                     |
// |____________________________________________|
//

#ifndef H_TRANSFORMATION_JACK
#define H_TRANSFORMATION_JACK

#include <SFML/Graphics/Transformable.hpp>
#include "../../RTTI/RTTI.h"

///
///Forward declaration
///
namespace logic
{
	class CActor;
}

using namespace logic;

namespace transformation
{
	class CTransformation
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CTransformation();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CTransformationCopy - sta�a referenfcja na obiekt klasy CTransformation
		///
		CTransformation(const CTransformation & CTransformationCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CTransformation();

		///
		///Metoda zwraca po�o�enie przed transformacj�
		///
		const sf::Vector2f & getInitial() const;

		///
		///Metoda ustawia po�o�enie przed transformacj�
		///
		///@param &initial - referencja na wektor pozycji pocz�tkowej
		///
		void setInitial(sf::Vector2f & initial);

		///
		///Metoda ustawia po�o�enie przed transformacj�
		///
		///@param initial_x - wsp�rz�dna pocz�tkowa X ammo
		///
		///@param initial_y - wsp�rz�dna pocz�tkowa Y ammo
		///
		void setInitial(float initial_x, float initial_y);

		///
		///Metoda zwraca referencj� wektora przesuni�cia
		///
		const sf::Vector2f & getOffset() const;

		///
		///Metoda ustawia wektor przesuni�cia
		///
		///@param & offset - referencja na wektor przesuni�cia
		///
		void setOffset(sf::Vector2f & offset);

		///
		///Metoda ustawia wektor przesuni�cia
		///
		///@param offset_x - wsp�rzedna X
		///
		///@param offset_y - wsp�rzedna Y
		///
		void setOffset(float offset_x, float offset_y);

		///
		///Metoda zwraca referencj� na wektora po�o�enia emitera
		///
		const sf::Vector2f & getEmiter() const;

		///
		///Metoda ustawia wektor po�o�enia emitera
		///
		///@param emiter - referencja na wektor emitera
		///
		void setEmiter(sf::Vector2f & emiter);

		///
		///Metoda ustawia wektor po�o�enia emitera
		///
		///@param emiter_x - wsp�rzedna X
		///
		///@param emiter_y - wsp�rzedna Y
		///
		void setEmiter(float emiter_x, float emiter_y);

		///
		///Metoda dokonuje transformacji skali, pozycji, obrotu
		///
		///@param * p_parent - wska�nik na obiekt klasy CActor
		///
		////@param * p_child - wska�nik na obiekt klasy CActor
		///
		void Transform(CActor * p_parent, CActor * p_child);

	private:

		sf::Vector2f	m_initial;	//pozycja pocz�tkowa wzgl�dem w�a�ciciela
		sf::Vector2f	m_offset;	//przesuni�cie pozycji wzgl�dem w�a�ciciela
		sf::Vector2f	m_emiter;	//poprawka pozycji wzgl�dem w�a�ciciela

	};
}//namespace transformation
#endif//H_TRANSFORMATION_JACK
