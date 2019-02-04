//  __________________________________________
// | CPowerStation.cpp - class implementation |
// | Jack Flower - July 2014                  |
// |__________________________________________|
//

#include "CPowerStation.h"
#include "../../CPhysicalManager.h"
#include "../../../Rendering/Drawable/Layers.h"

using namespace rendering::drawable;

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(CPowerStation, CActor);

		//Chroniony konstruktor domy�lny
		CPowerStation::CPowerStation(const std::wstring& uniqueId)
		:
			CActor					(uniqueId),	//konstruktor klasy bazowej
			m_stored_energy			(0.0f),
			m_energy_capacitor		(0.0f),
			m_amount_power_modules	(0),
			m_unit_controller		(true),//urz�dzenie w��czone
			m_communication_data	()
		{
			SetZIndexBody(Z_PHYSICAL_SHADOW_POWER_STATION_BODY);
			SetZIndexShadowBody(Z_PHYSICAL_POWER_STATION_BODY);
			SetZIndexHead(Z_PHYSICAL_SHADOW_POWER_STATION_HEAD);
			SetZIndexShadowHead(Z_PHYSICAL_POWERM_STATION_HEAD);

			//testy...zaliczone...
			//this->SetCategory(PHYSICAL_MONSTER);
			//testy...zaliczone...
			//gWirelessPowerTransmissionManager.m_energysender_List.push_back(this);
			//gWirelessPowerStationRouter.m_powerstations.push_back(this);
			//int x = 0;
		}

		//Chroniony konstruktor kopiuj�cy
		CPowerStation::CPowerStation(const CPowerStation &CPowerStationCopy)
		:
			CActor					(CPowerStationCopy),//konstruktor kopiujacy klasy bazowej
			m_stored_energy			(CPowerStationCopy.m_stored_energy),
			m_energy_capacitor		(CPowerStationCopy.m_energy_capacitor),
			m_amount_power_modules	(CPowerStationCopy.m_amount_power_modules),
			m_unit_controller		(CPowerStationCopy.m_unit_controller),
			m_communication_data	(CPowerStationCopy.m_communication_data)
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CPowerStation::~CPowerStation(void)
		{
			//CActor				not edit
			m_stored_energy			= 0.0f;
			m_energy_capacitor		= 0;
			m_amount_power_modules	= 0;
			//m_unit_controller		not edit
			//m_communication_data	not edit
		}

		//Metoda zwraca nazw� elektrowni wiatrowej
		const std::string CPowerStation::GetPowerStationName() const
		{
			return m_power_station_name;
		}

		///Metoda ustawia nazw� elektrowni wiatrowej
		void CPowerStation::SetPowerStationName(const std::string& power_station_name)
		{
			m_power_station_name = power_station_name;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CPowerStation::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca ilo�� zgromadzonej energii
		const float CPowerStation::getStoredEnergy() const
		{
			return m_stored_energy;
		}

		//Metoda ustawia ilo�� zgromadzonej energii
		void CPowerStation::setStoredEnergy(const float stored_energy)
		{
			m_stored_energy = stored_energy;
		}

		//Metoda zwraca ilo�� energii, kt�r� mo�e zgromadzi� elektrownia wiatrowa
		const float CPowerStation::getEnergyCapacitor() const
		{
			return m_energy_capacitor;
		}

		//Metoda ustawia ilo�� energii, kt�r� mo�e zgromadzi� elektrownia wiatrowa
		void CPowerStation::setEnergyCapacitor(const float energy_capacitor)
		{
			m_energy_capacitor = energy_capacitor;
		}

		//Metoda zwraca ilo�� ilo�� modu��w zasilajacych
		const unsigned CPowerStation::getAmountPowerModules() const
		{
			return m_amount_power_modules;
		}

		//Metoda ustawia ilo�� ilo�� modu��w zasilajacych
		void CPowerStation::setAmountPowerModules(unsigned amount_power_modules)
		{
			m_amount_power_modules = amount_power_modules;
		}

		//Metoda zwraca flag�, czy obiekt posiada modu� do komunikacji
		const bool CPowerStation::getUseCommunication() const
		{
			return m_communication_data.getUseEquipment();
		}

		//Metoda ustawia flag�, czy obiekt posiada modu� do komunikacji
		void CPowerStation::setUseCommunication(const bool use_communication)
		{
			m_communication_data.setUseEquipment(use_communication);
		}

		//Metoda zwraca wska�nik na obiekt klasy CCommunication
		CCommunication* CPowerStation::GetCommunication()
		{
			return m_communication_data.getCommunication();
		}

		//Metoda ustawia wska�nik na obiekt klasy CCommunication
		void CPowerStation::SetCommunication(CCommunication* communication)
		{
			m_communication_data.setCommunication(communication);
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CPowerStation::Update(float dt)
		{
			if(m_communication_data.getUseEquipment())
			{
				if(m_communication_data.getCommunication())
				{
					//2016 Januray 29 - atrapa
					//to logika ma za zadanie
					//udost�pni�, por�wna�, dokona� walidacji,
					//swoj� konfiguracj� z konfiguracj� (prawami)
					//modu�u komunikacyjnego CCommunication
					//przeka�nika, kt�ry chce t� elektrowani�
					//zarejestrowa�...
					if(m_communication_data.getCommunication()->getRange() > 50)
						Rotate(-2);
				}
			}
		}
	}//namespace powerstation
}//namespace logic
