//  ___________________________________________
// | EnergyTemplate.h - class definition       |
// | Jack Flower - May 2014                    |
// |___________________________________________|
//

#ifndef H_ENERGY_TEMPLATE_JACK
#define H_ENERGY_TEMPLATE_JACK

#include "EnergyTankFactory/EnergyTankTemplate.h"
#include "BatteryFactory/BatteryTemplate.h"
#include "../../../Equipment/Energy/Energy.h"
#include "../../../Equipment/EquipmentData/EquipmentEnergyTankData.h"
#include "../../../Equipment/Energy/Battery/Battery.h"
#include "../../../Equipment/EquipmentData/EquipmentBatteryData.h"

using namespace equipment::battery;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec energii - akumulator
	///
	class EnergyTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		EnergyTemplate();

		///
		///Destruktor
		///
		~EnergyTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

		///
		///Wirtualna metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy Energy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Energy *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_energy - wskaźnik na obiekt klasy Energy
		///
		virtual void fill(Energy *p_energy);


		//metody  p o m o c n i c z e
		inline const std::string getEnergyName() const
		{
			return m_templ_energy_name;
		}

		inline void setEnergyName(const std::string templ_energy_name)
		{
			m_templ_energy_name = templ_energy_name;
		}

		inline const float getPercetageReserveEnergy() const
		{
			return m_templ_percentage_reserve_energy;
		}

		inline void setPercetageReserveEnergy(float templ_percentage_reserve_energy)
		{
			m_templ_percentage_reserve_energy = templ_percentage_reserve_energy;
		}

		inline const float getEnergyTimeDelayed() const
		{
			return m_templ_energy_time_delayed;
		}

		inline void setEnergyTimeDelayed(float templ_energy_time_delayed)
		{
			m_templ_energy_time_delayed = templ_energy_time_delayed;
		}

		inline const bool getEnergyEmptyMessage() const
		{
			return m_templ_energy_empty_message;
		}

		inline void setEnergyEmptyMessage(bool templ_energy_empty_message)
		{
			m_templ_energy_empty_message = templ_energy_empty_message;
		}

		inline const float getEnergyRegenaration() const
		{
			return m_templ_energy_regeneration;
		}
	
		inline void setEnergyRegenaration(float templ_energy_regeneration)
		{
			m_templ_energy_regeneration = templ_energy_regeneration;
		}

		inline const float getRegenarationTime() const
		{
			return m_templ_regeneration_time;
		}

		inline void setRegenarationTime(float templ_regeneration_time)
		{
			m_templ_regeneration_time = templ_regeneration_time;
		}

		inline const float getEnergyRotationSpeed() const
		{
			return m_templ_energy_rotation_speed;
		}

		inline void setEnergyRotationSpeed(float templ_energy_rotation_speed)
		{
			m_templ_energy_rotation_speed = templ_energy_rotation_speed;
		}

		inline BatteryTemplate *getTemplateBattery()
		{
			return p_templ_battery;
		}

		inline void setTemplateBattery(BatteryTemplate * battery)
		{
			p_templ_battery = battery;
		}

		inline const bool getUseBattery() const
		{
			return m_templ_battery_data.getUseEquipment();
		}

		inline void setUseBattery(bool use_battery)
		{
			m_templ_battery_data.setUseEquipment(use_battery);
		}

		inline const float getCriticalDuration() const
		{
			return m_templ_critical_duration;
		}

		inline void setCriticalDuration(float templ_critical_duration)
		{
			m_templ_critical_duration = templ_critical_duration;
		}

		inline const float getDamageDuration() const
		{
			return m_templ_damage_duration;
		}

		inline void setDamageDuration(float templ_damage_duration)
		{
			m_templ_damage_duration = templ_damage_duration;
		}

	protected:

	private:

		std::string m_templ_energy_name; //nazwa akumulatora energii (niklowy, kadmowy, lityczny, atomowy...etc)
		EquipmentEnergyTankData	m_templ_energytank_data; //opakowanie funkcjonalności zbiornika paliwa
		EnergyTankTemplate *p_templ_energy_tank; //wskaźnik na dane wzorca akumulatora energii
		EquipmentBatteryData m_templ_battery_data; //opakowanie funkcjonalności baterii
		BatteryTemplate *p_templ_battery; //wskaźnik na dane wzorca baterii
		float m_templ_percentage_reserve_energy; //procentowa wartość energii, przy której następuje komunikat informacyjny o rezerwie, wyczerpaniu energii
		float m_templ_energy_time_delayed; //czas opóźnienia komunikatu o wyczerpaniu energii
		bool m_templ_energy_empty_message; //flaga, czy obiekt może wysyłać komunikaty o wyczerpaniu energii
		float m_templ_energy_regeneration; //wartość samoregeneracji energii (obiekt regeneruje energię - odpoczywa)
		float m_templ_regeneration_time; //częstotliwość regeneracji procesu
		float m_templ_energy_rotation_speed; //prędkość wirowania wskaźnika energii w akumulatorze
		float m_templ_critical_duration; //czas trwania stanu krytycznego
		float m_templ_damage_duration; //czas trwania stanu uszkodzenia
	};
}
#endif//H_ENERGY_TEMPLATE_JACK
