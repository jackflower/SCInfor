//  ______________________________________________________
// | CWindPowerStationTemplate.h - class definition       |
// | Jack Flower - August 2014                            |
// |______________________________________________________|
//

#ifndef H_WIND_POWER_STATION_TEMPLATE_JACK
#define H_WIND_POWER_STATION_TEMPLATE_JACK

#include "../../../Logic/Industrial/PowerStation/WindPowerStation/CWindPowerStation.h"
#include "../../EquipmentFactory/IndustrialFactory/PowerModuleFactory/CWindTurbineTemplate.h"
#include "CPowerStationTemplate.h"


namespace factory
{
	///
	///Klasa reprezentuje wzorzec elektrowni wiatrowej
	///
	class CWindPowerStationTemplate : public CPowerStationTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CWindPowerStationTemplate(void);

		///
		///Destruktor wirtualny
		///
		virtual ~CWindPowerStationTemplate(void);

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CWindPowerStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CWindPowerStation* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_windpower_station - wskaŸnik na obiekt klasy CWindPowerStation
		///
		virtual void Fill(CWindPowerStation *p_windpower_station);


		//metody  p o m o c n i c z e

		inline const float getEnergyCondensationTime() const
		{
			return m_templ_energy_condensation_time;
		}

		inline const bool getUseWindTurbine() const
		{
			return m_templ_use_windturbine;
		}

		inline	const bool getUseRotationHead() const
		{
			return m_templ_use_rotation_head;
		}

		inline	void setUseRotationHead(const bool templ_use_rotation_head)
		{
			m_templ_use_rotation_head = templ_use_rotation_head;
		}

		inline	const float getSpeedRotationHead() const
		{
			return m_templ_speed_rotation_head;
		}

		inline	void setSpeedRotationHead(const bool templ_speed_rotation_head)
		{
			m_templ_speed_rotation_head = templ_speed_rotation_head;
		}

	private:

		float					m_templ_energy_condensation_time;	//czas co jaki nastêpuje kondensacja energii
		bool					m_templ_use_windturbine;			//flaga, czy elektrownia wiatrowa posiada turbiê wiatrow¹
		float					m_templ_portion_energy;				//porcja energii, któr¹ bêdê móg³ zabieraæ z turbiny
		bool					m_templ_use_rotation_head;			//flaga okreœla, czy korpus siê obraca (HEAD)
		float					m_templ_speed_rotation_head;		//prêdkoœæ obrotu korpusu (HEAD)
		CWindTurbineTemplate*	p_templ_windturbine;				//wskaŸnik na obiekt klasy CWindTurbineTemplate - wzorzec CWindTurbine
	};
}//namespace factory
#endif//H_WIND_POWER_STATION_TEMPLATE_JACK
