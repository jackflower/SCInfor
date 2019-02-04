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
	///Klasa reprezentuje grawitacj�
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
		///Konstruktor kopiuj�cy
		///
		///@param CGravityCopy - sta�a referecja na obiekt klasy CGravity
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
		///Metoda zwraca si�� grawitacji
		///
		const float getGravityForce() const;

		///
		///Metoda ustawia si�� grawitacji
		///
		///@param gravity_force - si�a ci��enia (grawitacja)
		///
		void setGravityForce(float gravity_force);

	private:

		float m_gravity_force;		//si�a ci��enia (grawitacja)


	};
}//namespace interaction
#endif//H_GRAVITY_JACK