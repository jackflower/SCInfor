//  ______________________________________________
// | EntityTemperature.cpp - class implementation |
// | Jack Flower - June 2014                      |
// |______________________________________________|
//

#include "EntityTemperature.h"

namespace universe
{
	RTTI_IMPL_NOPARENT(EntityTemperature);

	//Konstruktor
	EntityTemperature::EntityTemperature()
	:
		m_entity_temperature{ 0.0f }
	{
	}

	//Konstruktor kopiujący
	EntityTemperature::EntityTemperature(const EntityTemperature & copy)
	:
		m_entity_temperature{ copy.m_entity_temperature }
	{
	}

	//Destruktor
	EntityTemperature::~EntityTemperature(void)
	{
		m_entity_temperature	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string EntityTemperature::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca temperaturę
	const float EntityTemperature::getEntityTemperature() const
	{
		return m_entity_temperature;
	}

	//Metoda ustawia temperaturę
	void EntityTemperature::setEntityTemperature(float entity_temperature)
	{
		m_entity_temperature = entity_temperature;
	}

}//namespace universe
