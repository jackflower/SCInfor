//  ____________________________________
// | Gravity.h - class definition klasy |
// | Jack Flower - May 2014             |
// |____________________________________|
//

#ifndef H_GRAVITY_JACK
#define H_GRAVITY_JACK

#include <string>
#include "../../RTTI/RTTI.h"

namespace interaction
{

	///
	///Klasa reprezentuje grawitację
	///
	class Gravity
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		Gravity();

		///
		///Konstruktor kopiujący
		///
		///@param copy - stała referecja na obiekt klasy Gravity
		///
		Gravity(const Gravity & copy);

		///
		///Destruktor
		///
		~Gravity();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;
	
		///
		///Metoda zwraca siłę grawitacji
		///
		const float getGravityForce() const;

		///
		///Metoda ustawia siłę grawitacji
		///
		///@param gravity_force - siła ciążenia (grawitacja)
		///
		void setGravityForce(float gravity_force);

	private:

		float m_gravity_force; //siła ciążenia (grawitacja)


	};
}//namespace interaction
#endif//H_GRAVITY_JACK
