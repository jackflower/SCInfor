//  ___________________________________
// | Energy.h - class definition       |
// | Jack Flower February 2014         |
// |___________________________________|
//

#ifndef H_ENERGY_JACK
#define H_ENERGY_JACK

#include "EEnergyState.h"
#include "Battery/CBattery.h"
#include "../EquipmentData/CEquipmentEnergyTankData.h"
#include "../EquipmentData/CEquipmentBatteryData.h"
#include "../../Logic/Actor/CActor.h"
#include "../../RTTI/RTTI.h"

using namespace equipment::battery;

namespace equipment
{

	///
	///Klasa reprezentuje mechanizm zarz¹dzania energi¹
	///
	class Energy : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
	
		//Aby uzyskaæ obiekt Energy, nale¿y wywo³aæ CPhysicalManager::CreateEnergy();

	private:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		Energy(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
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
		///Metoda zwraca nazwê akumulatora energii
		///
		const std::string getEnergyName() const;

		///
		///Metoda ustawia nazwê akumulatora energii
		///
		///@param energy_name - typ akumulatora energii sta³a referencja na std::string
		///
		void setEnergyName(const std::string & energy_name);

		///
		///Metoda zwraca wartoœæ, przy której nastêpuje komunikat informacyjny o niskim poziomie energii
		///
		const float getPercentageReserveEnergy() const;

		///
		///Metoda ustawia wartoœæ, przy której nastêpuje komunikat informacyjny o niskim poziomie energii
		///
		///@param percentage_reserve_energy - wartoœæ, przy której nastêpuje komunikat informacyjny o niskim poziomie energii
		///
		void setPercentageReserveEnergy(float percentage_reserve_energy);

		///
		///Metoda zwraca wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku energii
		///
		const bool getEnergyEmptyMessage() const;

		///
		///Metoda ustawia wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku energii
		///
		///@param energy_empty_message - flaga, czy obiekt mo¿e wysy³aæ komunikaty o braku energii
		///
		void setEnergyEmptyMessage(bool energy_empty_message);

		///
		///Metoda zwraca czas opóŸnienia komunikatu o braku energii
		///
		const float getEnergyTimeDelayed() const;

		///
		///Metoda ustawia czas opóŸnienia komunikatu o braku energii
		///
		///@param energy_time_delayed - czas opóŸnienia komunikatu o braku energii
		///
		void setEnergyTimeDelayed(float energy_time_delayed);

		///
		///Metoda zwraca wartoœæ energii dla procesu jej regeneracji
		///
		const float getEnergyRegeneration() const;

		///
		///Metoda ustawia wartoœæ energii dla procesu jej regeneracji
		///
		///@param energy_regeneration - wartoœæ energii dla procesu jej regeneracji
		///
		void setEnergyRegeneration(float energy_regeneration);

		///
		///Metoda zwraca czêstotliwoœæ regeneracji procesu
		///
		const float getEnergyRegenerationTime() const;

		///
		///Metoda ustawia czêstotliwoœæ regeneracji procesu
		///
		///@param energy_regeneration_time - czêstotliwoœæ regeneracji procesu
		///
		void setEnergyRegenerationTime(float energy_regeneration_time);

		///
		///Metoda zwraca prêdkoœæ wirowania wskaŸnika energii w akumulatorze
		///
		const float getEnergyRotationSpeed() const;

		///
		///Metoda ustawia prêdkoœæ wirowania wskaŸnika energii w akumulatorze
		///
		///@param energy_rotation_speed - prêdkoœæ wirowania wskaŸnika energii w akumulatorze
		///
		void setEnergyRotationSpeed(float energy_rotation_speed);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CEnergyTank
		///
		CEnergyTank * getEnergyTank();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CEnergyTank
		///
		///@param *energy_tank - wskaŸnik na obiekt klasy CEnergyTank
		///
		void setEnergyTank(CEnergyTank * energy_tank);

		///
		///Metoda zwraca flagê, czy obiekt posiada akumulator energii
		///
		const bool getUseEnergyTank() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada akumulator energii
		///
		///@param use_energytank - flaga, czy obiekt posiada akumulator energii
		///
		void setUseEnergyTank(bool use_energytank);

		///
		///Metoda zwraca referencjê na opakowanie funkcjonalnoœci akumulatora
		///
		CEquipmentEnergyTankData & getEquipmentEnergyTankData();

		///
		///Metoda ustawia referencjê na opakowanie funkcjonalnoœci akumulatora
		///
		///@param energytank_data - referencja na obiekt klasy CEquipmentEnergyTankData
		///
		void setEquipmentEnergyTankData(CEquipmentEnergyTankData & energytank_data);

		///
		///Metoda zwraca referencjê na opakowanie danych dla transformacji
		///
		CTransformation & getEnergyTankTransformed();

		///
		///Metoda ustawia referencjê na opakowanie danych dla transformacji
		///
		///@param energytank_transformation - referencja na obiekt klasy CTransformation
		///
		void setEnergyTankTransformed(CTransformation & energytank_transformation);

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CBattery - bateria
		///
		CBattery * getBattery();

		///
		///Metoda ustawia wskaŸnik na obiekt klasy CBattery - bateria
		///
		///@param *battery - wskaŸnik na obiekt klasy CBattery - bateria
		///
		void setBattery(CBattery * battery);

		///
		///Metoda zwraca flagê, czy obiekt posiada bateriê
		///
		const bool getUseBattery() const;

		///
		///Metoda ustawia flagê, czy obiekt posiada bateriê
		///
		///@param use_battery - flagê, czy obiekt posiada bateriê
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
		///Metoda zwraca falgê determinuj¹ca do zniszczenia w³aœciciela tego obektu
		///
		inline const bool getOwnerDeathCandidate() const { return m_owner_death_candidate; }

		///
		///Metoda zwraca referencjcê na modu³ sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logikê obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string m_energy_name; //nazwa mechanizmu zarz¹dzania energi¹ <map>//potem usun¹æ, bo nie bêdzie ³adowania danych ze struktur...
		CEquipmentEnergyTankData m_energytank_data; //opakowanie funkcjonalnoœci akumulatora
		float m_percentage_reserve_energy; //procentowa wartoœæ energii, przy której nastêpuje komunikat informacyjny o niskim poziomie energii (default 10% - konstruktor)
		float m_energy_time_delayed; //czas opóŸnienia komunikatu o braku energii - jako dana wejœciowa dla sf::Randomizer
		bool m_energy_empty_message; //flaga, czy obiekt mo¿e wysy³aæ komunikaty o braku energii
		float m_energy_regeneration; //wartoœæ energii dla procesu jej regeneracji (factor/sec)
		float m_energy_regeneration_time; //czêstotliwoœæ regeneracji procesu regeneracji energii akumulatora
		float m_energy_timer; //wyliczany up³ywaj¹cy czas procesów logiki
		float m_energy_percentage_energy; //wyliczana procentowa zawartoœæ energii akumulatora
		float m_energy_rotor_speed; //wyliczana prêdkoœæ wirowania wskaŸnika energii w akumulatorze
		float m_energy_rotation_speed; //prêdkoœæ wirowania wskaŸnika energii w akumulatorze
		EEnergyState m_energy_state; //wyliczenie stanów dla obiektu Energy
		CEquipmentBatteryData m_battery_data; //opakowanie funkcjonalnoœci baterii
		float m_critical_duration; //czas trwania stanu krytycznego
		float m_critical_timer; //lokalny timer stanu krytycznego
		float m_damage_duration; //czas trwania stanu uszkodzenia
		float m_damage_timer; //lokalny timer stanu uszkodzenia
		bool m_owner_death_candidate; //flaga determinuj¹ca do zniszczenia w³aœciciela tego obektu
		CSwitch m_unit_controller; //w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu
		void updateEnergyState(float dt);

		//prywatna metoda aktualizuje obiekt - energytank
		void updateEnergyTank(float dt);

		//prywatna metoda aktualizuje sk³adowe transformacji wzglêdem w³aœciciela
		void updateEnergyTankTransformation(float dt);

	};
}//namespace equipment
#endif//H_ENERGY_JACK
