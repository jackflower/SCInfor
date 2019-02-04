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

	//Konstruktor kopiuj¹cy
	CGround::CGround(const CGround & CGroundCopy)
	:
		CActor				(CGroundCopy),	//konstruktor kopiuj¹cy klasy bazowej
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

	//Metoda zwraca wspó³czynnik tarcia
	const float CGround::getFriction() const
	{
		return m_physicsground.getFriction();
	}

	//Metoda ustawia wspó³czynnik tarcia
	void CGround::setFriction(float friction)
	{
		m_physicsground.setFriction(friction);
	}

	//Metoda zwraca wspó³czynnik wilgotnoœci
	const float CGround::getHumidity() const
	{
		return m_physicsground.getHumidity();
	}

	//Metoda ustawia wspó³czynnik wilgotnoœci
	void CGround::setHumidity(float humidity)
	{
		m_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
	const float CGround::getThermalTransmittance() const
	{
		return m_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
	void CGround::setThermalTransmittance(float thermal_transmittance)
	{
		m_physicsground.setThermalTransmittance(thermal_transmittance);
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CGround::update(float dt)
	{
		CPhysical::UpdateShadow(dt);
		//to do
		//2016-02-20
		//Pod³o¿e w swojej logice - behawioralnym zachowaniu
		//reagowaæ na przyk³ad na opad deszczu, œniegu, na przep³yw wody,
		//na nacisk i pozosta³e wrunki pogodowe, jak i te¿
		//wszelkie zjawiska fizyczne...
		//
		//Na podstawie chech opisuj¹cych obiekt pod³o¿e, obiekty
		//na nim siê znajduj¹ce lub w inny sposób z nim reaguj¹ce,
		//bêd¹ce w reakcji - altualizuj¹ swoj¹ logikê - bahawioryzm
		//test...
		//SetColorBody(sf::Color::Green);
		//test...
	}
}//namespace mapengine
