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
	///Klasa reprezentuje prawzorzec wszystkich przekaŸników elektrowni
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
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
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
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_power_relay_station - wskaŸnik na obiekt klasy CPowerRelayStation
		///
		virtual void Fill(CPowerRelayStation *p_power_relay_station);


		//metody  p o m o c n i c z e

		//Metoda zwraca flagê, czy obiekt posiada modu³ prezentacji stanu slotów
		inline const bool getTemplateUseSlotsRate() const
		{
			return m_templ_use_slots_rate;
		}

		//Metoda ustawia flagê, czy obiekt posiada modu³ prezentacji stanu slotów
		inline void setTemplateUseSlotsRate(const bool templ_use_slots_rate)
		{
			m_templ_use_slots_rate = templ_use_slots_rate;
		}

		//Metoda zwraca iloœæ elektrowni, które modu³ mo¿e obs³ugiwaæ
		inline const int getTemplatePowerstationsCapacity() const
		{
			return m_templ_powerstations_capacity;
		}

		//Metoda ustawia iloœæ elektrowni, które modu³ mo¿e obs³ugiwaæ
		inline void setTemplatePowerstationsCapacity(const int templ_powerstations_capacity)
		{
			m_templ_powerstations_capacity = templ_powerstations_capacity;
		}

		//Metoda zwraca sta³¹ referencjê na zakres czasu trwania stanu - wizualizacja aktywnoœci
		inline const std::pair<float, float> & getTemplateStateTimeRange() const
		{
			return m_templ_state_time_range;
		}

		//Metoda ustawia sta³¹ referencjê na zakres czasu trwania stanu - wizualizacja aktywnoœci
		inline void setTemplateStateTimeRange(const std::pair<float, float> & templ_state_time_range)
		{
			m_templ_state_time_range = templ_state_time_range;
		}

		//Metoda zwraca sta³¹ referencjê na zakres prêdkoœci i kierunek obracania siê mudu³u
		inline const std::pair<float, float> & getTemplateRotationSpeedRange() const
		{
			return m_templ_rotation_speed_range;
		}

		//Metoda ustawia sta³¹ referencjê na zakres prêdkoœci i kierunek obracania siê mudu³u
		inline void setTemplateRotationSpeedRange(const std::pair<float, float> & templ_rotation_speed_range)
		{
			m_templ_rotation_speed_range = templ_rotation_speed_range;
		}

		//Metoda zwraca czas trwania stanu - wizualizacja aktywnoœci
		inline const float getTemplateStateTime() const
		{
			return m_templ_state_time;
		}

		//Metoda ustawia czas trwania stanu - wizualizacja aktywnoœci
		inline void setTemplateStateTime(const float templ_state_time)
		{
			m_templ_state_time = templ_state_time;
		}

		//Metoda zwraca prêdkoœæ i kierunek obracania siê mudu³u - wizualizacja aktywnoœci
		inline const float getTemplateRotationSpeed() const
		{
			return m_templ_rotation_speed;
		}

		//Metoda ustawia prêdkoœæ i kierunek obracania siê mudu³u - wizualizacja aktywnoœci
		inline void setTemplateRotationSpeed(const float templ_rotation_speed)
		{
			m_templ_rotation_speed = templ_rotation_speed;
		}

		//Metoda zwraca wskaŸnik na obiekt klasy CSlotsRaTemplate
		inline CSlotsRateTemplate* getTemplateSlotsRate()
		{
			return p_templ_slot_rate;
		}

		//Metoda ustawia wskaŸnik na obiekt klasy CSlotsRateTemplate
		inline void setTemplateSlotsRate(CSlotsRateTemplate* templ_slot_rate)
		{
			p_templ_slot_rate = templ_slot_rate;
		}

		//Metoda zwraca wskaŸnik na obiekt klasy CBatteryTemplate
		inline CBatteryTemplate* getTemplateBattery()
		{
			return p_templ_battery;
		}

		//Metoda ustawia wskaŸnik na obiekt klasy CBatteryTemplate
		inline void setTemplateBattery(CBatteryTemplate* templ_battery)
		{
			p_templ_battery = templ_battery;
		}

		//Metoda zwraca flagê, czy obiekt posiada bateriê
		inline const bool getTemplateUseBattery() const
		{
			return m_templ_use_battery;
		}

		//Metoda ustawia flagê, czyczy obiekt posiada bateriê
		inline void setTemplateUseBattery(const bool templ_use_battery)
		{
			m_templ_use_battery = templ_use_battery;
		}

		//Metoda zwraca czas po jakim obiekt wchodzi do stanu obs³ugi elektrowni
		inline const float getTemplateTimeToStart() const
		{
			return m_templ_time_to_start;
		}

		//Metoda ustawia czas po jakim obiekt wchodzi do stanu obs³ugi elektrowni
		inline void setTemplateTimeToStart(const float templ_time_to_start)
		{
			m_templ_time_to_start = templ_time_to_start;
		}

		//Metoda zwraca czas trwania procesu wychodzenia ze stanu obs³ugi elektrowni
		inline const float getTemplateDurationDisconnect() const
		{
			return m_templ_duration_disconnect;
		}

		//Metoda ustawima czas trwania procesu wychodzenia ze stanu obs³ugi elektrowni
		inline void setTemplateDurationDisconnect(const float templ_duration_disconnect)
		{
			m_templ_duration_disconnect = templ_duration_disconnect;
		}

	private:

		bool						m_templ_use_slots_rate;			//flaga, czy obiekt posiada modu³ prezentacji stanu slotów
		int							m_templ_powerstations_capacity;	//iloœæ obs³ugiwanych elektrowni
		std::pair<float, float>		m_templ_state_time_range;		//zakres czasu trwania stanu - wizualizacja aktywnoœci
		std::pair<float, float>		m_templ_rotation_speed_range;	//zakres prêdkoœci i kieruneku obracania siê mudu³u
		float						m_templ_state_time;				//czas trwania stanu - wizualizacja aktywnoœci
		float						m_templ_rotation_speed;			//prêdkoœæ i kierunek obracania siê mudu³u
		CSlotsRateTemplate*			p_templ_slot_rate;				//wskaŸnik na obiekt klasy CSlotsRateTemplate (wzorzec modu³u wskaŸnika przekaŸnika (sloty))
		CBatteryTemplate*			p_templ_battery;				//wskaŸnik na obiekt klasy CBatteryTemplate (wzorzec baterii)
		bool						m_templ_use_battery;			//flaga, czy obiekt posiada bateriê
		float						m_templ_time_to_start;			//po tym czasie obiekt wchodzi do stanu obs³ugi elektrowni
		float						m_templ_duration_disconnect;	//czas trwania procesu disconnect
		
	};	
}//namespace factory
#endif//H_POWER_RELAY_STATION_TEMPLATE_JACK
