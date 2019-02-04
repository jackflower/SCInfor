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
		///Konstruktor kopiuj¹cy
		///
		///@param & CTransformationCopy - sta³a referenfcja na obiekt klasy CTransformation
		///
		CTransformation(const CTransformation & CTransformationCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CTransformation();

		///
		///Metoda zwraca po³o¿enie przed transformacj¹
		///
		const sf::Vector2f & getInitial() const;

		///
		///Metoda ustawia po³o¿enie przed transformacj¹
		///
		///@param &initial - referencja na wektor pozycji pocz¹tkowej
		///
		void setInitial(sf::Vector2f & initial);

		///
		///Metoda ustawia po³o¿enie przed transformacj¹
		///
		///@param initial_x - wspó³rzêdna pocz¹tkowa X ammo
		///
		///@param initial_y - wspó³rzêdna pocz¹tkowa Y ammo
		///
		void setInitial(float initial_x, float initial_y);

		///
		///Metoda zwraca referencjê wektora przesuniêcia
		///
		const sf::Vector2f & getOffset() const;

		///
		///Metoda ustawia wektor przesuniêcia
		///
		///@param & offset - referencja na wektor przesuniêcia
		///
		void setOffset(sf::Vector2f & offset);

		///
		///Metoda ustawia wektor przesuniêcia
		///
		///@param offset_x - wspó³rzedna X
		///
		///@param offset_y - wspó³rzedna Y
		///
		void setOffset(float offset_x, float offset_y);

		///
		///Metoda zwraca referencjê na wektora po³o¿enia emitera
		///
		const sf::Vector2f & getEmiter() const;

		///
		///Metoda ustawia wektor po³o¿enia emitera
		///
		///@param emiter - referencja na wektor emitera
		///
		void setEmiter(sf::Vector2f & emiter);

		///
		///Metoda ustawia wektor po³o¿enia emitera
		///
		///@param emiter_x - wspó³rzedna X
		///
		///@param emiter_y - wspó³rzedna Y
		///
		void setEmiter(float emiter_x, float emiter_y);

		///
		///Metoda dokonuje transformacji skali, pozycji, obrotu
		///
		///@param * p_parent - wskaŸnik na obiekt klasy CActor
		///
		////@param * p_child - wskaŸnik na obiekt klasy CActor
		///
		void Transform(CActor * p_parent, CActor * p_child);

	private:

		sf::Vector2f	m_initial;	//pozycja pocz¹tkowa wzglêdem w³aœciciela
		sf::Vector2f	m_offset;	//przesuniêcie pozycji wzglêdem w³aœciciela
		sf::Vector2f	m_emiter;	//poprawka pozycji wzglêdem w³aœciciela

	};
}//namespace transformation
#endif//H_TRANSFORMATION_JACK
