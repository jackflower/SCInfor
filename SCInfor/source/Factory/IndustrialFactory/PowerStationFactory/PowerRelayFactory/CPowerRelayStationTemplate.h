//  ______________________________________________________
// | CPowerRelayStationTemplate.h - class definition      |
// | Jack Flower - July 2015                              |
// |______________________________________________________|
//

#ifndef H_POWER_RELAY_STATION_TEMPLATE_JACK
#define H_POWER_RELAY_STATION_TEMPLATE_JACK

#include "CRelayStationTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/CPowerRelayStation.h"
#include "CSlotsRateTemplate.h"
#include "../../../../Factory/EquipmentFactory/EnergyFactory/BatteryFactory/CBatteryTemplate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich przeka�nik�w elektrowni
	///
	class CPowerRelayStationTemplate : public CRelayStationTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPowerRelayStationTemplate();

		///
		///Destruktor wirtualny
		///
		~CPowerRelayStationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml �aduje wsp�lne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CPowerRelayStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPowerRelayStation* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_power_relay_station - wska�nik na obiekt klasy CPowerRelayStation
		///
		virtual void Fill(CPowerRelayStation *p_power_relay_station);


		//metody  p o m o c n i c z e

		//Metoda zwraca flag�, czy obiekt posiada modu� prezentacji stanu slot�w
		inline const bool getTemplateUseSlotsRate() const
		{
			return m_templ_use_slots_rate;
		}

		//Metoda ustawia flag�, czy obiekt posiada modu� prezentacji stanu slot�w
		inline void setTemplateUseSlotsRate(const bool templ_use_slots_rate)
		{
			m_templ_use_slots_rate = templ_use_slots_rate;
		}

		//Metoda zwraca ilo�� elektrowni, kt�re modu� mo�e obs�ugiwa�
		inline const int getTemplatePowerstationsCapacity() const
		{
			return m_templ_powerstations_capacity;
		}

		//Metoda ustawia ilo�� elektrowni, kt�re modu� mo�e obs�ugiwa�
		inline void setTemplatePowerstationsCapacity(const int templ_powerstations_capacity)
		{
			m_templ_powerstations_capacity = templ_powerstations_capacity;
		}

		//Metoda zwraca sta�� referencj� na zakres czasu trwania stanu - wizualizacja aktywno�ci
		inline const std::pair<float, float> & getTemplateStateTimeRange() const
		{
			return m_templ_state_time_range;
		}

		//Metoda ustawia sta�� referencj� na zakres czasu trwania stanu - wizualizacja aktywno�ci
		inline void setTemplateStateTimeRange(const std::pair<float, float> & templ_state_time_range)
		{
			m_templ_state_time_range = templ_state_time_range;
		}

		//Metoda zwraca sta�� referencj� na zakres pr�dko�ci i kierunek obracania si� mudu�u
		inline const std::pair<float, float> & getTemplateRotationSpeedRange() const
		{
			return m_templ_rotation_speed_range;
		}

		//Metoda ustawia sta�� referencj� na zakres pr�dko�ci i kierunek obracania si� mudu�u
		inline void setTemplateRotationSpeedRange(const std::pair<float, float> & templ_rotation_speed_range)
		{
			m_templ_rotation_speed_range = templ_rotation_speed_range;
		}

		//Metoda zwraca czas trwania stanu - wizualizacja aktywno�ci
		inline const float getTemplateStateTime() const
		{
			return m_templ_state_time;
		}

		//Metoda ustawia czas trwania stanu - wizualizacja aktywno�ci
		inline void setTemplateStateTime(const float templ_state_time)
		{
			m_templ_state_time = templ_state_time;
		}

		//Metoda zwraca pr�dko�� i kierunek obracania si� mudu�u - wizualizacja aktywno�ci
		inline const float getTemplateRotationSpeed() const
		{
			return m_templ_rotation_speed;
		}

		//Metoda ustawia pr�dko�� i kierunek obracania si� mudu�u - wizualizacja aktywno�ci
		inline void setTemplateRotationSpeed(const float templ_rotation_speed)
		{
			m_templ_rotation_speed = templ_rotation_speed;
		}

		//Metoda zwraca wska�nik na obiekt klasy CSlotsRaTemplate
		inline CSlotsRateTemplate* getTemplateSlotsRate()
		{
			return p_templ_slot_rate;
		}

		//Metoda ustawia wska�nik na obiekt klasy CSlotsRateTemplate
		inline void setTemplateSlotsRate(CSlotsRateTemplate* templ_slot_rate)
		{
			p_templ_slot_rate = templ_slot_rate;
		}

		//Metoda zwraca wska�nik na obiekt klasy CBatteryTemplate
		inline CBatteryTemplate* getTemplateBattery()
		{
			return p_templ_battery;
		}

		//Metoda ustawia wska�nik na obiekt klasy CBatteryTemplate
		inline void setTemplateBattery(CBatteryTemplate* templ_battery)
		{
			p_templ_battery = templ_battery;
		}

		//Metoda zwraca flag�, czy obiekt posiada bateri�
		inline const bool getTemplateUseBattery() const
		{
			return m_templ_use_battery;
		}

		//Metoda ustawia flag�, czyczy obiekt posiada bateri�
		inline void setTemplateUseBattery(const bool templ_use_battery)
		{
			m_templ_use_battery = templ_use_battery;
		}

		//Metoda zwraca czas po jakim obiekt wchodzi do stanu obs�ugi elektrowni
		inline const float getTemplateTimeToStart() const
		{
			return m_templ_time_to_start;
		}

		//Metoda ustawia czas po jakim obiekt wchodzi do stanu obs�ugi elektrowni
		inline void setTemplateTimeToStart(const float templ_time_to_start)
		{
			m_templ_time_to_start = templ_time_to_start;
		}

		//Metoda zwraca czas trwania procesu wychodzenia ze stanu obs�ugi elektrowni
		inline const float getTemplateDurationDisconnect() const
		{
			return m_templ_duration_disconnect;
		}

		//Metoda ustawima czas trwania procesu wychodzenia ze stanu obs�ugi elektrowni
		inline void setTemplateDurationDisconnect(const float templ_duration_disconnect)
		{
			m_templ_duration_disconnect = templ_duration_disconnect;
		}

	private:

		bool						m_templ_use_slots_rate;			//flaga, czy obiekt posiada modu� prezentacji stanu slot�w
		int							m_templ_powerstations_capacity;	//ilo�� obs�ugiwanych elektrowni
		std::pair<float, float>		m_templ_state_time_range;		//zakres czasu trwania stanu - wizualizacja aktywno�ci
		std::pair<float, float>		m_templ_rotation_speed_range;	//zakres pr�dko�ci i kieruneku obracania si� mudu�u
		float						m_templ_state_time;				//czas trwania stanu - wizualizacja aktywno�ci
		float						m_templ_rotation_speed;			//pr�dko�� i kierunek obracania si� mudu�u
		CSlotsRateTemplate*			p_templ_slot_rate;				//wska�nik na obiekt klasy CSlotsRateTemplate (wzorzec modu�u wska�nika przeka�nika (sloty))
		CBatteryTemplate*			p_templ_battery;				//wska�nik na obiekt klasy CBatteryTemplate (wzorzec baterii)
		bool						m_templ_use_battery;			//flaga, czy obiekt posiada bateri�
		float						m_templ_time_to_start;			//po tym czasie obiekt wchodzi do stanu obs�ugi elektrowni
		float						m_templ_duration_disconnect;	//czas trwania procesu disconnect
		
	};	
}//namespace factory
#endif//H_POWER_RELAY_STATION_TEMPLATE_JACK
