//  _________________________________________
// | PowerStation.h - class definition       |
// | Jack Flower - July 2014                 |
// |_________________________________________|
//

#ifndef H_POWER_STATION_JACK
#define H_POWER_STATION_JACK

#include "../../Actor/Actor.h"
#include "../../../Equipment/Switch.h"
#include "../../Communication/Communication.h"
#include "../../../Equipment/EquipmentData/EquipmentCommunicationData.h"

using namespace logic::communication;

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa bazowa reprezentuje funkcjonalność wszystkich rodzajów elektrowni
		///
		class PowerStation : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;
			
			//Aby uzyskać obiekt PowerStation, należy wywołać PhysicalManager::CreatePowerStation();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			PowerStation(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param PowerStationCopy - obiekt klasy PowerStation
			///
			PowerStation(const PowerStation & PowerStationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			virtual ~PowerStation(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca nazwę elektrowni
			///
			const std::string getPowerStationName() const;

			///
			///Metoda ustawia nazwę elektrowni
			///
			///@param power_station_name - nazwa elektrowni stała referencja na std::string
			///
			void setPowerStationName(const std::string & power_station_name);

			///
			///Metoda zwraca ilość zgromadzonej energii
			///
			const float getStoredEnergy() const;

			///
			///Metoda ustawia ilość zgromadzonej energii
			///
			///@param stored_energy - ilość zgromadzonej energii
			///
			void setStoredEnergy(const float stored_energy);

			///
			///Metoda zwraca ilość energii, którą może zgromadzić elektrownia wiatrowa
			///
			const float getEnergyCapacitor() const;

			///
			///Metoda ustawia ilość energii, którą może zgromadzić elektrownia wiatrowa
			///
			///@param energy_capacitor - ilość energii do zmagazynowania - pojemność (kondensator)
			///
			void setEnergyCapacitor(const float energy_capacitor);

			///
			///Metoda zwraca ilość ilość modułów zasilajacych
			///
			const unsigned getAmountPowerModules() const;

			///
			///Metoda ustawia ilość ilość modułów zasilajacych
			///
			///@param amount_power_modules - ilość modułów zasilajacych (turbin, przetworników)
			///
			void setAmountPowerModules(unsigned amount_power_modules);

			///
			///Metoda zwraca flagę, czy obiekt posiada moduł do komunikacji
			///
			const bool getUseCommunication() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada moduł do komunikacji
			///
			///@param use_communication - flaga, czy obiekt posiada moduł do komunikacji
			///
			void setUseCommunication(const bool use_communication);

			///
			///Metoda zwraca wskaźnik na obiekt klasy Communication
			///
			Communication *GetCommunication();

			///
			///Metoda ustawia wskaźnik na obiekt klasy Communication
			///
			///@param *communication - wskaźnik na obiekt klasy Communication
			///
			void SetCommunication(Communication *communication);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string m_power_station_name; //nazwa elektrowni
			float m_stored_energy; //aktualnie zgromadzona energia
			float m_energy_capacitor; //ilość energii do zmagazynowania - pojemność (kondensator)
			unsigned m_amount_power_modules; //ilość modułów zasilajacych (turbin, przetworników, etc...)
			Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
			EquipmentCommunicationData m_communication_data; //opakowanie funkcjonalności modułu komunikacyjnego

		private:

		};
	}//namespace powerstation
}//namespace logic
#endif//H_POWER_STATION_JACK
