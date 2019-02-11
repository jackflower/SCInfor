//  ________________________________________
// | PowerStation.cpp - class implementation |
// | Jack Flower - July 2014                 |
// |_________________________________________|
//

#include "PowerStation.h"
#include "../../CPhysicalManager.h"
#include "../../../Rendering/Drawable/Layers.h"

using namespace rendering::drawable;

namespace logic
{
	namespace powerstation
	{
		RTTI_IMPL(PowerStation, Actor);

		//Chroniony konstruktor domyślny
		PowerStation::PowerStation(const std::wstring & uniqueId)
		:
			Actor(uniqueId),	//konstruktor klasy bazowej
			m_stored_energy(0.0f),
			m_energy_capacitor(0.0f),
			m_amount_power_modules(0),
			m_unit_controller(true),//urządzenie włączone
			m_communication_data()
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

		//Chroniony konstruktor kopiujący
		PowerStation::PowerStation(const PowerStation & PowerStationCopy)
		:
			Actor(PowerStationCopy),//konstruktor kopiujacy klasy bazowej
			m_stored_energy(PowerStationCopy.m_stored_energy),
			m_energy_capacitor(PowerStationCopy.m_energy_capacitor),
			m_amount_power_modules(PowerStationCopy.m_amount_power_modules),
			m_unit_controller(PowerStationCopy.m_unit_controller),
			m_communication_data(PowerStationCopy.m_communication_data)
		{
			SetZIndexBody(Z_PHYSICAL_SHADOW_POWER_STATION_BODY);
			SetZIndexShadowBody(Z_PHYSICAL_POWER_STATION_BODY);
			SetZIndexHead(Z_PHYSICAL_SHADOW_POWER_STATION_HEAD);
			SetZIndexShadowHead(Z_PHYSICAL_POWERM_STATION_HEAD);
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		PowerStation::~PowerStation(void)
		{
			//~Actor()
			m_stored_energy = 0.0f;
			m_energy_capacitor = 0;
			m_amount_power_modules = 0;
			//m_unit_controller
			//m_communication_data
		}

		//Metoda zwraca nazwę elektrowni wiatrowej
		const std::string PowerStation::getPowerStationName() const
		{
			return m_power_station_name;
		}

		///Metoda ustawia nazwę elektrowni wiatrowej
		void PowerStation::setPowerStationName(const std::string & power_station_name)
		{
			m_power_station_name = power_station_name;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string PowerStation::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca ilość zgromadzonej energii
		const float PowerStation::getStoredEnergy() const
		{
			return m_stored_energy;
		}

		//Metoda ustawia ilość zgromadzonej energii
		void PowerStation::setStoredEnergy(const float stored_energy)
		{
			m_stored_energy = stored_energy;
		}

		//Metoda zwraca ilość energii, którą może zgromadzić elektrownia wiatrowa
		const float PowerStation::getEnergyCapacitor() const
		{
			return m_energy_capacitor;
		}

		//Metoda ustawia ilość energii, którą może zgromadzić elektrownia wiatrowa
		void PowerStation::setEnergyCapacitor(const float energy_capacitor)
		{
			m_energy_capacitor = energy_capacitor;
		}

		//Metoda zwraca ilość ilość modułów zasilajacych
		const unsigned PowerStation::getAmountPowerModules() const
		{
			return m_amount_power_modules;
		}

		//Metoda ustawia ilość ilość modułów zasilajacych
		void PowerStation::setAmountPowerModules(unsigned amount_power_modules)
		{
			m_amount_power_modules = amount_power_modules;
		}

		//Metoda zwraca flagę, czy obiekt posiada moduł do komunikacji
		const bool PowerStation::getUseCommunication() const
		{
			return m_communication_data.getUseEquipment();
		}

		//Metoda ustawia flagę, czy obiekt posiada moduł do komunikacji
		void PowerStation::setUseCommunication(const bool use_communication)
		{
			m_communication_data.setUseEquipment(use_communication);
		}

		//Metoda zwraca wskaźnik na obiekt klasy Communication
		Communication *PowerStation::GetCommunication()
		{
			return m_communication_data.getCommunication();
		}

		//Metoda ustawia wskaźnik na obiekt klasy Communication
		void PowerStation::SetCommunication(Communication *communication)
		{
			m_communication_data.setCommunication(communication);
		}

		//Wirtualna metoda aktualizująca obiekt
		void PowerStation::update(float dt)
		{
			if(m_communication_data.getUseEquipment())
			{
				if(m_communication_data.getCommunication())
				{
					//2016 Januray 29 - atrapa
					//to logika ma za zadanie
					//udostępnić, porównać, dokonać walidacji,
					//swoją konfigurację z konfiguracją (prawami)
					//modułu komunikacyjnego Communication
					//przekaźnika, który chce tę elektrowanię
					//zarejestrować...
					if(m_communication_data.getCommunication()->getRange() > 50)
						Rotate(-2);
				}
			}
		}
	}//namespace powerstation
}//namespace logic
