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

		//Chroniony konstruktor domyœlny
		CPowerStation::CPowerStation(const std::wstring& uniqueId)
		:
			CActor					(uniqueId),	//konstruktor klasy bazowej
			m_stored_energy			(0.0f),
			m_energy_capacitor		(0.0f),
			m_amount_power_modules	(0),
			m_unit_controller		(true),//urz¹dzenie w³¹czone
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

		//Chroniony konstruktor kopiuj¹cy
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

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CPowerStation::~CPowerStation(void)
		{
			//CActor				not edit
			m_stored_energy			= 0.0f;
			m_energy_capacitor		= 0;
			m_amount_power_modules	= 0;
			//m_unit_controller		not edit
			//m_communication_data	not edit
		}

		//Metoda zwraca nazwê elektrowni wiatrowej
		const std::string CPowerStation::GetPowerStationName() const
		{
			return m_power_station_name;
		}

		///Metoda ustawia nazwê elektrowni wiatrowej
		void CPowerStation::SetPowerStationName(const std::string& power_station_name)
		{
			m_power_station_name = power_station_name;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CPowerStation::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca iloœæ zgromadzonej energii
		const float CPowerStation::getStoredEnergy() const
		{
			return m_stored_energy;
		}

		//Metoda ustawia iloœæ zgromadzonej energii
		void CPowerStation::setStoredEnergy(const float stored_energy)
		{
			m_stored_energy = stored_energy;
		}

		//Metoda zwraca iloœæ energii, któr¹ mo¿e zgromadziæ elektrownia wiatrowa
		const float CPowerStation::getEnergyCapacitor() const
		{
			return m_energy_capacitor;
		}

		//Metoda ustawia iloœæ energii, któr¹ mo¿e zgromadziæ elektrownia wiatrowa
		void CPowerStation::setEnergyCapacitor(const float energy_capacitor)
		{
			m_energy_capacitor = energy_capacitor;
		}

		//Metoda zwraca iloœæ iloœæ modu³ów zasilajacych
		const unsigned CPowerStation::getAmountPowerModules() const
		{
			return m_amount_power_modules;
		}

		//Metoda ustawia iloœæ iloœæ modu³ów zasilajacych
		void CPowerStation::setAmountPowerModules(unsigned amount_power_modules)
		{
			m_amount_power_modules = amount_power_modules;
		}

		//Metoda zwraca flagê, czy obiekt posiada modu³ do komunikacji
		const bool CPowerStation::getUseCommunication() const
		{
			return m_communication_data.getUseEquipment();
		}

		//Metoda ustawia flagê, czy obiekt posiada modu³ do komunikacji
		void CPowerStation::setUseCommunication(const bool use_communication)
		{
			m_communication_data.setUseEquipment(use_communication);
		}

		//Metoda zwraca wskaŸnik na obiekt klasy CCommunication
		CCommunication* CPowerStation::GetCommunication()
		{
			return m_communication_data.getCommunication();
		}

		//Metoda ustawia wskaŸnik na obiekt klasy CCommunication
		void CPowerStation::SetCommunication(CCommunication* communication)
		{
			m_communication_data.setCommunication(communication);
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CPowerStation::Update(float dt)
		{
			if(m_communication_data.getUseEquipment())
			{
				if(m_communication_data.getCommunication())
				{
					//2016 Januray 29 - atrapa
					//to logika ma za zadanie
					//udostêpniæ, porównaæ, dokonaæ walidacji,
					//swoj¹ konfiguracjê z konfiguracj¹ (prawami)
					//modu³u komunikacyjnego CCommunication
					//przekaŸnika, który chce tê elektrowaniê
					//zarejestrowaæ...
					if(m_communication_data.getCommunication()->getRange() > 50)
						Rotate(-2);
				}
			}
		}
	}//namespace powerstation
}//namespace logic
