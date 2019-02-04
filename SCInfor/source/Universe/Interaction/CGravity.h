/*
 _______________________________________
| CGravity.h - definicja klasy.         |
| Jack Flower - May 2014.               |
|_______________________________________|

*/

#ifndef H_GRAVITY_JACK
#define H_GRAVITY_JACK

#include <string>
#include "../../RTTI/RTTI.h"

namespace interaction
{

	///
	///Klasa reprezentuje grawitacjê
	///
	class CGravity
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CGravity(void);

		///
		///Konstruktor kopiuj¹cy
		///
		///@param CGravityCopy - sta³a referecja na obiekt klasy CGravity
		///
		CGravity(const CGravity & CGravityCopy);

		///
		///Destruktor
		///
		~CGravity(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;
	
		///
		///Metoda zwraca si³ê grawitacji
		///
		const float getGravityForce() const;

		///
		///Metoda ustawia si³ê grawitacji
		///
		///@param gravity_force - si³a ci¹¿enia (grawitacja)
		///
		void setGravityForce(float gravity_force);

	private:

		float m_gravity_force;		//si³a ci¹¿enia (grawitacja)


	};
}//namespace interaction
#endif//H_GRAVITY_JACK