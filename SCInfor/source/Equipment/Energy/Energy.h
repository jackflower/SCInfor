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
	///Klasa reprezentuje mechanizm zarz�dzania energi�
	///
	class Energy : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
	
		//Aby uzyska� obiekt Energy, nale�y wywo�a� CPhysicalManager::CreateEnergy();

	private:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		Energy(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
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
		///Metoda zwraca nazw� akumulatora energii
		///
		const std::string getEnergyName() const;

		///
		///Metoda ustawia nazw� akumulatora energii
		///
		///@param energy_name - typ akumulatora energii sta�a referencja na std::string
		///
		void setEnergyName(const std::string & energy_name);

		///
		///Metoda zwraca warto��, przy kt�rej nast�puje komunikat informacyjny o niskim poziomie energii
		///
		const float getPercentageReserveEnergy() const;

		///
		///Metoda ustawia warto��, przy kt�rej nast�puje komunikat informacyjny o niskim poziomie energii
		///
		///@param percentage_reserve_energy - warto��, przy kt�rej nast�puje komunikat informacyjny o niskim poziomie energii
		///
		void setPercentageReserveEnergy(float percentage_reserve_energy);

		///
		///Metoda zwraca warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku energii
		///
		const bool getEnergyEmptyMessage() const;

		///
		///Metoda ustawia warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku energii
		///
		///@param energy_empty_message - flaga, czy obiekt mo�e wysy�a� komunikaty o braku energii
		///
		void setEnergyEmptyMessage(bool energy_empty_message);

		///
		///Metoda zwraca czas op�nienia komunikatu o braku energii
		///
		const float getEnergyTimeDelayed() const;

		///
		///Metoda ustawia czas op�nienia komunikatu o braku energii
		///
		///@param energy_time_delayed - czas op�nienia komunikatu o braku energii
		///
		void setEnergyTimeDelayed(float energy_time_delayed);

		///
		///Metoda zwraca warto�� energii dla procesu jej regeneracji
		///
		const float getEnergyRegeneration() const;

		///
		///Metoda ustawia warto�� energii dla procesu jej regeneracji
		///
		///@param energy_regeneration - warto�� energii dla procesu jej regeneracji
		///
		void setEnergyRegeneration(float energy_regeneration);

		///
		///Metoda zwraca cz�stotliwo�� regeneracji procesu
		///
		const float getEnergyRegenerationTime() const;

		///
		///Metoda ustawia cz�stotliwo�� regeneracji procesu
		///
		///@param energy_regeneration_time - cz�stotliwo�� regeneracji procesu
		///
		void setEnergyRegenerationTime(float energy_regeneration_time);

		///
		///Metoda zwraca pr�dko�� wirowania wska�nika energii w akumulatorze
		///
		const float getEnergyRotationSpeed() const;

		///
		///Metoda ustawia pr�dko�� wirowania wska�nika energii w akumulatorze
		///
		///@param energy_rotation_speed - pr�dko�� wirowania wska�nika energii w akumulatorze
		///
		void setEnergyRotationSpeed(float energy_rotation_speed);

		///
		///Metoda zwraca wska�nik na obiekt klasy CEnergyTank
		///
		CEnergyTank * getEnergyTank();

		///
		///Metoda ustawia wska�nik na obiekt klasy CEnergyTank
		///
		///@param *energy_tank - wska�nik na obiekt klasy CEnergyTank
		///
		void setEnergyTank(CEnergyTank * energy_tank);

		///
		///Metoda zwraca flag�, czy obiekt posiada akumulator energii
		///
		const bool getUseEnergyTank() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada akumulator energii
		///
		///@param use_energytank - flaga, czy obiekt posiada akumulator energii
		///
		void setUseEnergyTank(bool use_energytank);

		///
		///Metoda zwraca referencj� na opakowanie funkcjonalno�ci akumulatora
		///
		CEquipmentEnergyTankData & getEquipmentEnergyTankData();

		///
		///Metoda ustawia referencj� na opakowanie funkcjonalno�ci akumulatora
		///
		///@param energytank_data - referencja na obiekt klasy CEquipmentEnergyTankData
		///
		void setEquipmentEnergyTankData(CEquipmentEnergyTankData & energytank_data);

		///
		///Metoda zwraca referencj� na opakowanie danych dla transformacji
		///
		CTransformation & getEnergyTankTransformed();

		///
		///Metoda ustawia referencj� na opakowanie danych dla transformacji
		///
		///@param energytank_transformation - referencja na obiekt klasy CTransformation
		///
		void setEnergyTankTransformed(CTransformation & energytank_transformation);

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca wska�nik na obiekt klasy CBattery - bateria
		///
		CBattery * getBattery();

		///
		///Metoda ustawia wska�nik na obiekt klasy CBattery - bateria
		///
		///@param *battery - wska�nik na obiekt klasy CBattery - bateria
		///
		void setBattery(CBattery * battery);

		///
		///Metoda zwraca flag�, czy obiekt posiada bateri�
		///
		const bool getUseBattery() const;

		///
		///Metoda ustawia flag�, czy obiekt posiada bateri�
		///
		///@param use_battery - flag�, czy obiekt posiada bateri�
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
		///Metoda zwraca falg� determinuj�ca do zniszczenia w�a�ciciela tego obektu
		///
		inline const bool getOwnerDeathCandidate() const { return m_owner_death_candidate; }

		///
		///Metoda zwraca referencjc� na modu� sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuje logik� obiektu
		///
		///@param dt - czas
		///
		void update(float dt);

	private:

		std::string m_energy_name; //nazwa mechanizmu zarz�dzania energi� <map>//potem usun��, bo nie b�dzie �adowania danych ze struktur...
		CEquipmentEnergyTankData m_energytank_data; //opakowanie funkcjonalno�ci akumulatora
		float m_percentage_reserve_energy; //procentowa warto�� energii, przy kt�rej nast�puje komunikat informacyjny o niskim poziomie energii (default 10% - konstruktor)
		float m_energy_time_delayed; //czas op�nienia komunikatu o braku energii - jako dana wej�ciowa dla sf::Randomizer
		bool m_energy_empty_message; //flaga, czy obiekt mo�e wysy�a� komunikaty o braku energii
		float m_energy_regeneration; //warto�� energii dla procesu jej regeneracji (factor/sec)
		float m_energy_regeneration_time; //cz�stotliwo�� regeneracji procesu regeneracji energii akumulatora
		float m_energy_timer; //wyliczany up�ywaj�cy czas proces�w logiki
		float m_energy_percentage_energy; //wyliczana procentowa zawarto�� energii akumulatora
		float m_energy_rotor_speed; //wyliczana pr�dko�� wirowania wska�nika energii w akumulatorze
		float m_energy_rotation_speed; //pr�dko�� wirowania wska�nika energii w akumulatorze
		EEnergyState m_energy_state; //wyliczenie stan�w dla obiektu Energy
		CEquipmentBatteryData m_battery_data; //opakowanie funkcjonalno�ci baterii
		float m_critical_duration; //czas trwania stanu krytycznego
		float m_critical_timer; //lokalny timer stanu krytycznego
		float m_damage_duration; //czas trwania stanu uszkodzenia
		float m_damage_timer; //lokalny timer stanu uszkodzenia
		bool m_owner_death_candidate; //flaga determinuj�ca do zniszczenia w�a�ciciela tego obektu
		CSwitch m_unit_controller; //w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka

		//prywatna metoda aktualizuje stan obiektu
		void updateEnergyState(float dt);

		//prywatna metoda aktualizuje obiekt - energytank
		void updateEnergyTank(float dt);

		//prywatna metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
		void updateEnergyTankTransformation(float dt);

	};
}//namespace equipment
#endif//H_ENERGY_JACK
