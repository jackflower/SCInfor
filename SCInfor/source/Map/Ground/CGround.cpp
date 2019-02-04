//  ____________________________________
// | CGround.cpp - class implementation |
// | Jack Flower - February 2016        |
// |____________________________________|
//

#include "CGround.h"
#include "../../Utilities/StringUtils/StringUtils.h"

using namespace stringutils;

namespace mapengine
{
	RTTI_IMPL(CGround, CActor);

	//Konstruktor
	CGround::CGround(const std::wstring& uniqueId)
	:
		CActor				(uniqueId),	//konstruktor klasy bazowej
		m_physicsground		()
	{
	}

	//Konstruktor kopiuj�cy
	CGround::CGround(const CGround & CGroundCopy)
	:
		CActor				(CGroundCopy),	//konstruktor kopiuj�cy klasy bazowej
		m_physicsground		(CGroundCopy.m_physicsground)
	{
	}

	//Destruktor
	CGround::~CGround()
	{
		//CActor			not edit
		//m_physicsground	not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CGround::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca wsp�czynnik tarcia
	const float CGround::getFriction() const
	{
		return m_physicsground.getFriction();
	}

	//Metoda ustawia wsp�czynnik tarcia
	void CGround::setFriction(float friction)
	{
		m_physicsground.setFriction(friction);
	}

	//Metoda zwraca wsp�czynnik wilgotno�ci
	const float CGround::getHumidity() const
	{
		return m_physicsground.getHumidity();
	}

	//Metoda ustawia wsp�czynnik wilgotno�ci
	void CGround::setHumidity(float humidity)
	{
		m_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
	const float CGround::getThermalTransmittance() const
	{
		return m_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
	void CGround::setThermalTransmittance(float thermal_transmittance)
	{
		m_physicsground.setThermalTransmittance(thermal_transmittance);
	}

	//Wirtualna metoda aktualizuj�ca obiekt
	void CGround::update(float dt)
	{
		CPhysical::UpdateShadow(dt);
		//to do
		//2016-02-20
		//Pod�o�e w swojej logice - behawioralnym zachowaniu
		//reagowa� na przyk�ad na opad deszczu, �niegu, na przep�yw wody,
		//na nacisk i pozosta�e wrunki pogodowe, jak i te�
		//wszelkie zjawiska fizyczne...
		//
		//Na podstawie chech opisuj�cych obiekt pod�o�e, obiekty
		//na nim si� znajduj�ce lub w inny spos�b z nim reaguj�ce,
		//b�d�ce w reakcji - altualizuj� swoj� logik� - bahawioryzm
		//test...
		//SetColorBody(sf::Color::Green);
		//test...
	}
}//namespace mapengine
