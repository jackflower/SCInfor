//  ___________________________________
// | Energy.h - class definition       |
// | Jack Flower February 2014         |
// |___________________________________|
//

#ifndef H_ENERGY_JACK
#define H_ENERGY_JACK

#include "EEnergyState.h"
#include "Battery/Battery.h"
#include "../EquipmentData/CEquipmentEnergyTankData.h"
#include "../EquipmentData/CEquipmentBatteryData.h"
#include "../../Logic/Actor/CActor.h"
#include "../../RTTI/RTTI.h"

using namespace equipment::battery;

namespace equipment
{

	///
	///Klasa reprezentuje mechanizm zarządzania energią
	///
	class Energy : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
	
		//Aby uzyskać obiekt Energy, należy wywołać CPhysicalManager::CreateEnergy();

	private:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		Energy(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param EnergyCopy - obiekt klasy Energy
		///
		Energy(const Energy & EnergyCopy);

		///
		///Destruktor
		///
		~Energy(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę akumulatora energii
		///
		const std::string getEnergyName() const;

		///
		///Metoda ustawia nazwę akumulatora energii
		///
		///@param energy_name - typ akumulatora energii stała referencja na std::string
		///
		void setEnergyName(const std::string & energy_name);

		///
		///Metoda zwraca wartość, przy której następuje komunikat informacyjny o niskim poziomie energii
		///
		const float getPercentageReserveEnergy() const;

		///
		///Metoda ustawia wartość, przy której następuje komunikat informacyjny o niskim poziomie energii
		///
		///@param percentage_reserve_energy - wartość, przy której następuje komunikat informacyjny o niskim poziomie energii
		///
		void setPercentageReserveEnergy(float percentage_reserve_energy);

		///
		///Metoda zwraca wartość flagi, czy obiekt może wysyłać komunikaty o braku energii
		///
		const bool getEnergyEmptyMessage() const;

		///
		///Metoda ustawia wartość flagi, czy obiekt może wysyłać komunikaty o braku energii
		///
		///@param energy_empty_message - flaga, czy obiekt może wysyłać komunikaty o braku energii
		///
		void setEnergyEmptyMessage(bool energy_empty_message);

		///
		///Metoda zwraca czas opóźnienia komunikatu o braku energii
		///
		const float getEnergyTimeDelayed() const;

		///
		///Metoda ustawia czas opóźnienia komunikatu o braku energii
		///
		///@param energy_time_delayed - czas opóźnienia komunikatu o braku energii
		///
		void setEnergyTimeDelayed(float energy_time_delayed);

		///
		///Metoda zwraca wartość energii dla procesu jej regeneracji
		///
		const float getEnergyRegeneration() const;

		///
		///Metoda ustawia wartość energii dla procesu jej regeneracji
		///
		///@param energy_regeneration - wartość energii dla procesu jej regeneracji
		///
		void setEnergyRegeneration(float energy_regeneration);

		///
		///Metoda zwraca częstotliwość regeneracji procesu
		///
		const float getEnergyRegenerationTime() const;

		///
		///Metoda ustawia częstotliwość regeneracji procesu
		///
		///@param energy_regeneration_time - częstotliwość regeneracji procesu
		///
		void setEnergyRegenerationTime(float energy_regeneration_time);

		///
		///Metoda zwraca prędkość wirowania wskaźnika energii w akumulatorze
		///
		const float getEnergyRotationSpeed() const;

		///
		///Metoda ustawia prędkość wirowania wskaźnika energii w akumulatorze
		///
		///@param energy_rotation_speed - prędkość wirowania wskaźnika energii w akumulatorze
		///
		void setEnergyRotationSpeed(float energy_rotation_speed);

		///
		///Metoda zwraca wskaźnik na obiekt klasy EnergyTank
		///
		EnergyTank * getEnergyTank();

		///
		///Metoda ustawia wskaźnik na obiekt klasy EnergyTank
		///
		///@param *energy_tank - wskaźnik na obiekt klasy EnergyTank
		///
		void setEnergyTank(EnergyTank * energy_tank);

		///
		///Metoda zwraca flagę, czy obiekt posiada akumulator energii
		///
		const bool getUseEnergyTank() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada akumulator energii
		///
		///@param use_energytank - flaga, czy obiekt posiada akumulator energii
		///
		void setUseEnergyTank(bool use_energytank);

		///
		///Metoda zwraca referencję na opakowanie funkcjonalności akumulatora
		///
		CEquipmentEnergyTankData & getEquipmentEnergyTankData();

		///
		///Metoda ustawia referencję na opakowanie funkcjonalności akumulatora
		///
		///@param energytank_data - referencja na obiekt klasy CEquipmentEnergyTankData
		///
		void setEquipmentEnergyTankData(CEquipmentEnergyTankData & energytank_data);

		///
		///Metoda zwraca referencję na opakowanie danych dla transformacji
		///
		CTransformation & getEnergyTankTransformed();

		///
		///Metoda ustawia referencję na opakowanie danych dla transformacji
		///
		///@param energytank_transformation - referencja na obiekt klasy CTransformation
		///
		void setEnergyTankTransformed(CTransformation & energytank_transformation);

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Battery - bateria
		///
		Battery * getBattery();

		///
		///Metoda ustawia wskaźnik na obiekt klasy Battery - bateria
		///
		///@param *battery - wskaźnik na obiekt klasy Battery - bateria
		///
		void setBattery(Battery * battery);

		///
		///Metoda zwraca flagę, czy obiekt posiada baterię
		///
		const bool getUseBattery() const;

		///
		///Metoda ustawia flagę, czy obiekt posiada baterię
		///
		///@param use_battery - flagę, czy obiekt posiada baterię
		///
		void setUseBattery(bool use_battery);

		///
		///Metoda zwraca czas trwania stanu krytycznego
		///
		const float getCriticalDuration() const;

		///
		///Metoda ustawia czas trwania stanu krytycznego
		///
		///@param critical_duration - czas trwania stanu krytycznego
		///
		void setCriticalDuration(float critical_duration);

		///
		///Metoda zwraca czas trwania stanu uszkodzenia
		///
		const float getDamageDuration() const;

		///
		///Metoda ustawia czas trwania stanu uszkodzenia
		///
		///@param damage_duration - czas trwania stanu uszkodzenia
		///
		void setDamageDuration(float damage_duration);

		///
		///Metoda zwraca falgę determinująca do zniszczenia właściciela tego obektu
		///
		inline const bool getOwnerDeathCandidate() const { return m_owner_death_candidate; }

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logikę obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string m_energy_name; //nazwa mechanizmu zarządzania energią <map>//potem usunąć, bo nie będzie ładowania danych ze struktur...
		CEquipmentEnergyTankData m_energytank_data; //opakowanie funkcjonalności akumulatora
		float m_percentage_reserve_energy; //procentowa wartość energii, przy której następuje komunikat informacyjny o niskim poziomie energii (default 10% - konstruktor)
		float m_energy_time_delayed; //czas opóźnienia komunikatu o braku energii - jako dana wejściowa dla sf::Randomizer
		bool m_energy_empty_message; //flaga, czy obiekt może wysyłać komunikaty o braku energii
		float m_energy_regeneration; //wartość energii dla procesu jej regeneracji (factor/sec)
		float m_energy_regeneration_time; //częstotliwość regeneracji procesu regeneracji energii akumulatora
		float m_energy_timer; //wyliczany upływający czas procesów logiki
		float m_energy_percentage_energy; //wyliczana procentowa zawartość energii akumulatora
		float m_energy_rotor_speed; //wyliczana prędkość wirowania wskaźnika energii w akumulatorze
		float m_energy_rotation_speed; //prędkość wirowania wskaźnika energii w akumulatorze
		EEnergyState m_energy_state; //wyliczenie stanów dla obiektu Energy
		CEquipmentBatteryData m_battery_data; //opakowanie funkcjonalności baterii
		float m_critical_duration; //czas trwania stanu krytycznego
		float m_critical_timer; //lokalny timer stanu krytycznego
		float m_damage_duration; //czas trwania stanu uszkodzenia
		float m_damage_timer; //lokalny timer stanu uszkodzenia
		bool m_owner_death_candidate; //flaga determinująca do zniszczenia właściciela tego obektu
		Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu
		void updateEnergyState(float dt);

		//prywatna metoda aktualizuje obiekt - energytank
		void updateEnergyTank(float dt);

		//prywatna metoda aktualizuje składowe transformacji względem właściciela
		void updateEnergyTankTransformation(float dt);

	};
}//namespace equipment
#endif//H_ENERGY_JACK
