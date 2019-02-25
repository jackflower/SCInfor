/*
 _______________________________________
| CGravity.cpp - implementacja klasy.   |
| Jack Flower - May 2014.               |
|_______________________________________|

*/

#include "CGravity.h"

namespace interaction
{
	RTTI_IMPL_NOPARENT(CGravity);

	//Konstruktor
	CGravity::CGravity(void)
	:
		m_gravity_force	(0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CGravity::CGravity(const CGravity & CGravityCopy)
	:
		m_gravity_force	(CGravityCopy.m_gravity_force)
	{
	}

	//Destruktor
	CGravity::~CGravity(void)
	{
		m_gravity_force	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CGravity::GetType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca si³ê grawitacji
	const float CGravity::getGravityForce() const
	{
		return m_gravity_force;
	}

	//Metoda ustawia si³ê grawitacji
	void CGravity::setGravityForce(float gravity_force)
	{
		m_gravity_force = gravity_force;
	}

}//namespace interaction