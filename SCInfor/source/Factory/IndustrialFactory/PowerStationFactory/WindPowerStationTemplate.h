//  _____________________________________________________
// | WindPowerStationTemplate.h - class definition       |
// | Jack Flower - August 2014                           |
// |_____________________________________________________|
//

#ifndef H_WIND_POWER_STATION_TEMPLATE_JACK
#define H_WIND_POWER_STATION_TEMPLATE_JACK

#include "../../../Logic/Industrial/PowerStation/WindPowerStation/CWindPowerStation.h"
#include "../../EquipmentFactory/IndustrialFactory/PowerModuleFactory/WindTurbineTemplate.h"
#include "PowerStationTemplate.h"


namespace factory
{
	///
	///Klasa reprezentuje wzorzec elektrowni wiatrowej
	///
	class WindPowerStationTemplate : public PowerStationTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		WindPowerStationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~WindPowerStationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Wirtualna metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy CWindPowerStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CWindPowerStation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_windpower_station - wskaźnik na obiekt klasy CWindPowerStation
		///
		virtual void fill(CWindPowerStation *p_windpower_station);


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

		float m_templ_energy_condensation_time;	//czas co jaki następuje kondensacja energii
		bool m_templ_use_windturbine; //flaga, czy elektrownia wiatrowa posiada turbię wiatrową
		float m_templ_portion_energy; //porcja energii, którą będę mógł zabierać z turbiny
		bool m_templ_use_rotation_head; //flaga określa, czy korpus się obraca (HEAD)
		float m_templ_speed_rotation_head; //prędkość obrotu korpusu (HEAD)
		WindTurbineTemplate *p_templ_windturbine; //wskaźnik na obiekt klasy WindTurbineTemplate - wzorzec WindTurbine
	};
}//namespace factory
#endif//H_WIND_POWER_STATION_TEMPLATE_JACK
