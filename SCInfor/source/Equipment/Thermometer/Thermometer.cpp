//  ________________________________________
// | Thermometer.cpp - class implementation |
// | Jack Flower - April 2015               |
// |________________________________________|
//

#include "Thermometer.h"

namespace equipment
{
	RTTI_IMPL(Thermometer, Physical)


	//Chroniony konstruktor domyślny
	Thermometer::Thermometer(const std::wstring & uniqueId)
	:
		Physical(uniqueId),//konstruktor klasy bazowej
		m_range(),
		m_temperature(0.0f),
		e_display_type(EDisplayType::PROGRESS_BAR)
	{
		//to do: layers
	}

	//Chroniony konstruktor kopiujący
	Thermometer::Thermometer(const Thermometer & ThermometerCopy)
	:
		Physical(ThermometerCopy),//konstruktor kopiujący klasy bazowej
		m_range(ThermometerCopy.m_range),
		m_temperature(ThermometerCopy.m_temperature),
		e_display_type(ThermometerCopy.e_display_type)
	{
		//to do: layers
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	Thermometer::~Thermometer()
	{
		//Physical
		m_range.max = 0.0f;
		m_range.min = 0.0f;
		m_temperature = 0.0f;
		//e_display_type
	}

	//Metoda zwraca temperaturę
	const float Thermometer::getTemperature() const
	{
		return m_temperature;
	}

	//Metoda ustawia temperaturę
	const void Thermometer::setTemperature(float temperature)
	{
		m_temperature = temperature;
	}

	//Wirtualna metoda aktualizuje logikę obiektu
	void Thermometer::update(float dt)
	{
		//Physical...
	}

}//namespace equipment
