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
		///Klasa bazowa reprezentuje funkcjonalnoœæ wszystkich rodzajów elektrowni
		///
		class CPowerStation : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CPowerStation, nale¿y wywo³aæ CPhysicalManager::CreatePowerStation();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CPowerStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CPowerStationCopy - obiekt klasy CPowerStation
			///
			CPowerStation(const CPowerStation &CPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CPowerStation(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazwê elektrowni
			///
			const std::string GetPowerStationName() const;

			///
			///Metoda ustawia nazwê elektrowni
			///
			///@param &power_station_name - nazwa elektrowni sta³a referencja na std::string
			///
			void SetPowerStationName(const std::string& power_station_name);

			///
			///Metoda zwraca iloœæ zgromadzonej energii
			///
			const float getStoredEnergy() const;

			///
			///Metoda ustawia iloœæ zgromadzonej energii
			///
			///@param stored_energy - iloœæ zgromadzonej energii
			///
			void setStoredEnergy(const float stored_energy);

			///
			///Metoda zwraca iloœæ energii, któr¹ mo¿e zgromadziæ elektrownia wiatrowa
			///
			const float getEnergyCapacitor() const;

			///
			///Metoda ustawia iloœæ energii, któr¹ mo¿e zgromadziæ elektrownia wiatrowa
			///
			///@param energy_capacitor - iloœæ energii do zmagazynowania - pojemnoœæ (kondensator)
			///
			void setEnergyCapacitor(const float energy_capacitor);

			///
			///Metoda zwraca iloœæ iloœæ modu³ów zasilajacych
			///
			const unsigned getAmountPowerModules() const;

			///
			///Metoda ustawia iloœæ iloœæ modu³ów zasilajacych
			///
			///@param amount_power_modules - iloœæ modu³ów zasilajacych (turbin, przetworników)
			///
			void setAmountPowerModules(unsigned amount_power_modules);

			///
			///Metoda zwraca flagê, czy obiekt posiada modu³ do komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flagê, czy obiekt posiada modu³ do komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada modu³ do komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Metoda zwraca wskaŸnik na obiekt klasy CCommunication
			///
			CCommunication* GetCommunication();

			///
			///Metoda ustawia wskaŸnik na obiekt klasy CCommunication
			///
			///@param *communication - wskaŸnik na obiekt klasy CCommunication
			///
			void SetCommunication(CCommunication* communication);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string					m_power_station_name;	//nazwa elektrowni
			float						m_stored_energy;		//aktualnie zgromadzona energia
			float						m_energy_capacitor;		//iloœæ energii do zmagazynowania - pojemnoœæ (kondensator)
			unsigned					m_amount_power_modules;	//iloœæ modu³ów zasilajacych (turbin, przetworników, etc...)
			Switch						m_unit_controller;		//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka
			EquipmentCommunicationData m_communication_data;	//opakowanie funkcjonalnoœci modu³u komunikacyjnego

		private:

		};
	}//namespace powerstation
}//namespace logic
#endif//H_POWER_STATION_JACK
