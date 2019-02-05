//  __________________________________________
// | CPowerStation.h - class definition       |
// | Jack Flower - July 2014                  |
// |__________________________________________|
//

#ifndef H_POWER_STATION_JACK
#define H_POWER_STATION_JACK

#include "../../Actor/CActor.h"
#include "../../../Equipment/Switch.h"
#include "../../Communication/CCommunication.h"
#include "../../../Equipment/EquipmentData/EquipmentCommunicationData.h"

using namespace logic::communication;

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa bazowa reprezentuje funkcjonalno�� wszystkich rodzaj�w elektrowni
		///
		class CPowerStation : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
			
			//Aby uzyska� obiekt CPowerStation, nale�y wywo�a� CPhysicalManager::CreatePowerStation();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CPowerStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CPowerStationCopy - obiekt klasy CPowerStation
			///
			CPowerStation(const CPowerStation &CPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CPowerStation(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazw� elektrowni
			///
			const std::string GetPowerStationName() const;

			///
			///Metoda ustawia nazw� elektrowni
			///
			///@param &power_station_name - nazwa elektrowni sta�a referencja na std::string
			///
			void SetPowerStationName(const std::string& power_station_name);

			///
			///Metoda zwraca ilo�� zgromadzonej energii
			///
			const float getStoredEnergy() const;

			///
			///Metoda ustawia ilo�� zgromadzonej energii
			///
			///@param stored_energy - ilo�� zgromadzonej energii
			///
			void setStoredEnergy(const float stored_energy);

			///
			///Metoda zwraca ilo�� energii, kt�r� mo�e zgromadzi� elektrownia wiatrowa
			///
			const float getEnergyCapacitor() const;

			///
			///Metoda ustawia ilo�� energii, kt�r� mo�e zgromadzi� elektrownia wiatrowa
			///
			///@param energy_capacitor - ilo�� energii do zmagazynowania - pojemno�� (kondensator)
			///
			void setEnergyCapacitor(const float energy_capacitor);

			///
			///Metoda zwraca ilo�� ilo�� modu��w zasilajacych
			///
			const unsigned getAmountPowerModules() const;

			///
			///Metoda ustawia ilo�� ilo�� modu��w zasilajacych
			///
			///@param amount_power_modules - ilo�� modu��w zasilajacych (turbin, przetwornik�w)
			///
			void setAmountPowerModules(unsigned amount_power_modules);

			///
			///Metoda zwraca flag�, czy obiekt posiada modu� do komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada modu� do komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada modu� do komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Metoda zwraca wska�nik na obiekt klasy CCommunication
			///
			CCommunication* GetCommunication();

			///
			///Metoda ustawia wska�nik na obiekt klasy CCommunication
			///
			///@param *communication - wska�nik na obiekt klasy CCommunication
			///
			void SetCommunication(CCommunication* communication);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string					m_power_station_name;	//nazwa elektrowni
			float						m_stored_energy;		//aktualnie zgromadzona energia
			float						m_energy_capacitor;		//ilo�� energii do zmagazynowania - pojemno�� (kondensator)
			unsigned					m_amount_power_modules;	//ilo�� modu��w zasilajacych (turbin, przetwornik�w, etc...)
			Switch						m_unit_controller;		//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
			EquipmentCommunicationData m_communication_data;	//opakowanie funkcjonalno�ci modu�u komunikacyjnego

		private:

		};
	}//namespace powerstation
}//namespace logic
#endif//H_POWER_STATION_JACK
