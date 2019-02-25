//  _______________________________________
// | GroundWork.cpp - class implementation |
// | Jack Flower - March 2015              |
// |_______________________________________|
//

#include "GroundWork.h"
#include "../../../Utilities/StringUtils/StringUtils.h"

using namespace stringutils;

namespace mapengine
{
	namespace groundwork
	{
		RTTI_IMPL(GroundWork, MapPhysical);

		//Konstruktor
		GroundWork::GroundWork(const std::wstring & uniqueId)
		:
			MapPhysical(uniqueId),	//konstruktor klasy bazowej
			m_physicsground()
		{
		}

		//Konstruktor kopiujący
		GroundWork::GroundWork(const GroundWork & GroundWorkCopy)
		:
			MapPhysical(GroundWorkCopy), //konstruktor kopiujący klasy bazowej
			m_physicsground(GroundWorkCopy.m_physicsground)
		{
		}

		//Destruktor
		GroundWork::~GroundWork()
		{
			//~MapPhysical()
			//m_physicsground
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string GroundWork::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca współczynnik tarcia
		const float GroundWork::getFriction() const
		{
			return m_physicsground.getFriction();
		}

		//Metoda ustawia współczynnik tarcia
		void GroundWork::setFriction(float friction)
		{
			m_physicsground.setFriction(friction);
		}

		//Metoda zwraca współczynnik wilgotności
		const float GroundWork::getHumidity() const
		{
			return m_physicsground.getHumidity();
		}

		//Metoda ustawia współczynnik wilgotności
		void GroundWork::setHumidity(float humidity)
		{
			m_physicsground.setHumidity(humidity);
		}

		//Metoda zwraca współczynnik przenikalności cieplnej
		const float GroundWork::getThermalTransmittance() const
		{
			return m_physicsground.getThermalTransmittance();
		}

		//Metoda ustawia współczynnik przenikalności cieplnej
		void GroundWork::setThermalTransmittance(float thermal_transmittance)
		{
			m_physicsground.setThermalTransmittance(thermal_transmittance);
		}

		//Wirtualna metoda aktualizująca obiekt
		void GroundWork::update(float dt)
		{
			//nothdig to do...
		}
	}//namespace groundwork
}//namespace mapengine
