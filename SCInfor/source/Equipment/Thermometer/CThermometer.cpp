//  _________________________________________
// | CThermometer.cpp - class implementation |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#include "CThermometer.h"

namespace equipment
{
	RTTI_IMPL(CThermometer, CPhysical)


	//Chroniony konstruktor domy�lny
	CThermometer::CThermometer(const std::wstring& uniqueId)
	:
		CPhysical(uniqueId)//konstruktor klasy bazowej
	{
	}

	//Chroniony konstruktor kopiuj�cy
	CThermometer::CThermometer(const CThermometer& CThermometerCopy)
	:
		CPhysical(CThermometerCopy)//konstruktor kopiuj�cy klasy bazowej
	{
	}

	//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
	CThermometer::~CThermometer()
	{
	}

	//Metoda zwraca temperatur�
	const float CThermometer::getTemperature() const
	{
		return m_temperature;
	}

	//Metoda ustawia temperatur�
	const void CThermometer::setTemperature(float temperature)
	{
		m_temperature = temperature;
	}

	//Wirtualna metoda aktualizuje logik� obiektu
	void CThermometer::Update(float dt)
	{
		//CPhysical::m_m
		//this->m_ma
	}

}//namespace equipment