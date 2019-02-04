//  _________________________________________
// | CPowerModule.cpp - class implementation |
// | Jack Flower - July 2014                 |
// |_________________________________________|
//

#include "CPowerModule.h"

namespace equipment
{
	RTTI_IMPL(CPowerModule, CActor);
		
	//Chroniony konstruktor domyœlny
	CPowerModule::CPowerModule(const std::wstring& uniqueId)
	:
		CActor					(uniqueId),//konstruktor klasy bazowej
		m_energy_capacitor		(0.0f),
		m_power					(0.0f),
		m_stored_energy			(0.0f),
		m_unit_controller		(true)
	{
	}

	//Chroniony konstruktor kopiuj¹cy
	CPowerModule::CPowerModule(const CPowerModule &CPowerModuleCopy)
	:
		CActor					(CPowerModuleCopy),//konstruktor kopiuj¹cy klasy bazowej
		m_energy_capacitor		(CPowerModuleCopy.m_energy_capacitor),
		m_power					(CPowerModuleCopy.m_power),
		m_stored_energy			(CPowerModuleCopy.m_stored_energy),
		m_unit_controller		(CPowerModuleCopy.m_unit_controller)
	{
	}

	//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
	CPowerModule::~CPowerModule(void)
	{
		//CActor				not edit
		m_energy_capacitor		= 0.0f;
		m_power					= 0.0f;
		m_stored_energy			= 0.0f;
		//m_unit_controller		not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPowerModule::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Metoda zwraca iloœæ energii, któr¹ mo¿na zgromadziæ
	const float CPowerModule::getEnergyCapacitor() const
	{
		return m_energy_capacitor;
	}

	//Metoda ustawia iloœæ energii, któr¹ mo¿na zgromadziæ
	void CPowerModule::setEnergyCapacitor(float energy_capacitor)
	{
		m_energy_capacitor = energy_capacitor;
	}

	//Metoda zwraca moc
	const float CPowerModule::getPower() const
	{
		return m_power;
	}

	//Metoda ustawia moc
	void CPowerModule::setPower(float power)
	{
		m_power = power;
	}

	//Metoda zwraca iloœæ zgromadzonej energii
	const float CPowerModule::getStoredEnergy() const
	{
		return m_stored_energy;
	}

	//Metoda ustawia iloœæ zgromadzonej energii
	void CPowerModule::setStoredEnergy(float stored_energy)
	{
			m_stored_energy = stored_energy;
	}
}//namespace equipment
