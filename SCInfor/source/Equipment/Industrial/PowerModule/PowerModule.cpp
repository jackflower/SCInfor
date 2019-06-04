//  ________________________________________
// | PowerModule.cpp - class implementation |
// | Jack Flower - July 2014                |
// |________________________________________|
//

#include "PowerModule.h"

namespace equipment
{
	RTTI_IMPL(PowerModule, Actor);
		
	//Chroniony konstruktor domyślny
	PowerModule::PowerModule(const std::wstring & uniqueId)
	:
		Actor{ uniqueId },//konstruktor klasy bazowej
		m_energy_capacitor{ 0.0f },
		m_power{ 0.0f },
		m_stored_energy{ 0.0f },
		m_unit_controller{ true }
	{
	}

	//Chroniony konstruktor kopiujący
	PowerModule::PowerModule(const PowerModule & PowerModuleCopy)
	:
		Actor(PowerModuleCopy),//konstruktor kopiujący klasy bazowej
		m_energy_capacitor{ PowerModuleCopy.m_energy_capacitor },
		m_power{ PowerModuleCopy.m_power },
		m_stored_energy{ PowerModuleCopy.m_stored_energy },
		m_unit_controller{ PowerModuleCopy.m_unit_controller }
	{
	}

	//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
	PowerModule::~PowerModule(void)
	{
		//~Actor()
		m_energy_capacitor = 0.0f;
		m_power = 0.0f;
		m_stored_energy = 0.0f;
		//m_unit_controller
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PowerModule::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca ilość energii, którą można zgromadzić
	const float PowerModule::getEnergyCapacitor() const
	{
		return m_energy_capacitor;
	}

	//Metoda ustawia ilość energii, którą można zgromadzić
	void PowerModule::setEnergyCapacitor(float energy_capacitor)
	{
		m_energy_capacitor = energy_capacitor;
	}

	//Metoda zwraca moc
	const float PowerModule::getPower() const
	{
		return m_power;
	}

	//Metoda ustawia moc
	void PowerModule::setPower(float power)
	{
		m_power = power;
	}

	//Metoda zwraca ilość zgromadzonej energii
	const float PowerModule::getStoredEnergy() const
	{
		return m_stored_energy;
	}

	//Metoda ustawia ilość zgromadzonej energii
	void PowerModule::setStoredEnergy(float stored_energy)
	{
			m_stored_energy = stored_energy;
	}
}//namespace equipment
