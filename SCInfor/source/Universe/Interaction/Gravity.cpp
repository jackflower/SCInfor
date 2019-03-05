//  ____________________________________
// | Gravity.cpp - class implementation |
// | Jack Flower - May 2014             |
// |____________________________________|
//

#include "Gravity.h"

namespace interaction
{
	RTTI_IMPL_NOPARENT(Gravity);

	//Konstruktor
	Gravity::Gravity()
	:
		m_gravity_force{ 0.0f }
	{
	}

	//Konstruktor kopiujący
	Gravity::Gravity(const Gravity & copy)
	:
		m_gravity_force{ copy.m_gravity_force }
	{
	}

	//Destruktor
	Gravity::~Gravity()
	{
		m_gravity_force	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Gravity::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca siłę grawitacji
	const float Gravity::getGravityForce() const
	{
		return m_gravity_force;
	}

	//Metoda ustawia siłę grawitacji
	void Gravity::setGravityForce(float gravity_force)
	{
		m_gravity_force = gravity_force;
	}

}//namespace interaction
