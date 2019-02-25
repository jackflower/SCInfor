//  ___________________________________
// | Ground.cpp - class implementation |
// | Jack Flower - February 2016       |
// |___________________________________|
//

#include "Ground.h"
#include "../../Utilities/StringUtils/StringUtils.h"

using namespace stringutils;

namespace mapengine
{
	RTTI_IMPL(Ground, Actor);

	//Konstruktor
	Ground::Ground(const std::wstring & uniqueId)
	:
		Actor(uniqueId), //konstruktor klasy bazowej
		m_physicsground()
	{
	}

	//Konstruktor kopiujący
	Ground::Ground(const Ground & CGroundCopy)
	:
		Actor(CGroundCopy),	//konstruktor kopiujący klasy bazowej
		m_physicsground(CGroundCopy.m_physicsground)
	{
	}

	//Destruktor
	Ground::~Ground()
	{
		//~Actor()
		//m_physicsground
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Ground::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca współczynnik tarcia
	const float Ground::getFriction() const
	{
		return m_physicsground.getFriction();
	}

	//Metoda ustawia współczynnik tarcia
	void Ground::setFriction(float friction)
	{
		m_physicsground.setFriction(friction);
	}

	//Metoda zwraca współczynnik wilgotności
	const float Ground::getHumidity() const
	{
		return m_physicsground.getHumidity();
	}

	//Metoda ustawia współczynnik wilgotności
	void Ground::setHumidity(float humidity)
	{
		m_physicsground.setHumidity(humidity);
	}

	//Metoda zwraca współczynnik przenikalności cieplnej
	const float Ground::getThermalTransmittance() const
	{
		return m_physicsground.getThermalTransmittance();
	}

	//Metoda ustawia współczynnik przenikalności cieplnej
	void Ground::setThermalTransmittance(float thermal_transmittance)
	{
		m_physicsground.setThermalTransmittance(thermal_transmittance);
	}

	//Wirtualna metoda aktualizująca obiekt
	void Ground::update(float dt)
	{
		Physical::updateShadow(dt);
		//to do
		//2016-02-20
		//Podłoże w swojej logice - behawioralnym zachowaniu
		//reaguje na przykład na opad deszczu, śniegu, na przepływ wody,
		//na nacisk i pozostałe wrunki pogodowe, jak i też
		//wszelkie zjawiska fizyczne...
		//
		//Na podstawie chech opisujących obiekt podłoże, obiekty
		//na nim się znajdujące w taki, lub w inny sposób z nim reagujące,
		//będące w reakcji - altualizują swoją logikę - bahawioryzm
		//test...
		//SetColorBody(sf::Color::Green);
		//test...
	}
}//namespace mapengine
