//  ____________________________________________
// | CEnergyTemplate.h - class definition       |
// | Jack Flower - May 2014                     |
// |____________________________________________|
//

#ifndef H_ENERGY_TEMPLATE_JACK
#define H_ENERGY_TEMPLATE_JACK

#include "EnergyTankFactory/CEnergyTankTemplate.h"
#include "BatteryFactory/CBatteryTemplate.h"
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
	class CEnergyTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CEnergyTemplate(void);

		///
		///Destruktor
		///
		~CEnergyTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Wirtualna metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy Energy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Energy* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_energy - wska�nik na obiekt klasy Energy
		///
		virtual void Fill(Energy *p_energy);


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

		inline CBatteryTemplate *getTemplateBattery()
		{
			return p_templ_battery;
		}

		inline void setTemplateBattery(CBatteryTemplate * battery)
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

		std::string					m_templ_energy_name;				//nazwa akumulatora energii (niklowy, kadmowy, lityczny, atomowy...etc)
		EquipmentEnergyTankData	m_templ_energytank_data;			//opakowanie funkcjonalno�ci zbiornika paliwa
		CEnergyTankTemplate*		p_templ_energy_tank;				//wska�nik na dane wzorca akumulatora energii
		EquipmentBatteryData		m_templ_battery_data;				//opakowanie funkcjonalno�ci baterii
		CBatteryTemplate*			p_templ_battery;					//wska�nik na dane wzorca baterii
		float						m_templ_percentage_reserve_energy;	//procentowa warto�� energii, przy kt�rej nast�puje komunikat informacyjny o rezerwie, wyczerpaniu energii
		float						m_templ_energy_time_delayed;		//czas op�nienia komunikatu o wyczerpaniu energii
		bool						m_templ_energy_empty_message;		//flaga, czy obiekt mo�e wysy�a� komunikaty o wyczerpaniu energii
		float						m_templ_energy_regeneration;		//warto�� samoregeneracji energii (obiekt regeneruje energi� - odpoczywa)
		float						m_templ_regeneration_time;			//cz�stotliwo�� regeneracji procesu
		float						m_templ_energy_rotation_speed;		//pr�dko�� wirowania wska�nika energii w akumulatorze
		float						m_templ_critical_duration;			//czas trwania stanu krytycznego
		float						m_templ_damage_duration;			//czas trwania stanu uszkodzenia
	};
}
#endif//H_ENERGY_TEMPLATE_JACK
