//  _____________________________________________________
// | PowerRelayStationTemplate.h - class definition      |
// | Jack Flower - July 2015                             |
// |_____________________________________________________|
//

#ifndef H_POWER_RELAY_STATION_TEMPLATE_JACK
#define H_POWER_RELAY_STATION_TEMPLATE_JACK

#include "RelayStationTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/CPowerRelayStation.h"
#include "SlotsRateTemplate.h"
#include "../../../../Factory/EquipmentFactory/EnergyFactory/BatteryFactory/BatteryTemplate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich przekaźników elektrowni
	///
	class PowerRelayStationTemplate : public RelayStationTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PowerRelayStationTemplate();

		///
		///Destruktor wirtualny
		///
		~PowerRelayStationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml ładuje wspólne cechy CActor
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy CPowerRelayStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPowerRelayStation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_power_relay_station - wskaźnik na obiekt klasy CPowerRelayStation
		///
		virtual void fill(CPowerRelayStation *p_power_relay_station);


		//metody  p o m o c n i c z e

		//Metoda zwraca flagę, czy obiekt posiada moduł prezentacji stanu slotów
		inline const bool getTemplateUseSlotsRate() const
		{
			return m_templ_use_slots_rate;
		}

		//Metoda ustawia flagę, czy obiekt posiada moduł prezentacji stanu slotów
		inline void setTemplateUseSlotsRate(const bool templ_use_slots_rate)
		{
			m_templ_use_slots_rate = templ_use_slots_rate;
		}

		//Metoda zwraca ilość elektrowni, które moduł może obsługiwać
		inline const int getTemplatePowerstationsCapacity() const
		{
			return m_templ_powerstations_capacity;
		}

		//Metoda ustawia ilość elektrowni, które moduł może obsługiwać
		inline void setTemplatePowerstationsCapacity(const int templ_powerstations_capacity)
		{
			m_templ_powerstations_capacity = templ_powerstations_capacity;
		}

		//Metoda zwraca stałą referencję na zakres czasu trwania stanu - wizualizacja aktywności
		inline const std::pair<float, float> & getTemplateStateTimeRange() const
		{
			return m_templ_state_time_range;
		}

		//Metoda ustawia stałą referencję na zakres czasu trwania stanu - wizualizacja aktywności
		inline void setTemplateStateTimeRange(const std::pair<float, float> & templ_state_time_range)
		{
			m_templ_state_time_range = templ_state_time_range;
		}

		//Metoda zwraca stałą referencję na zakres prędkości i kierunek obracania się mudułu
		inline const std::pair<float, float> & getTemplateRotationSpeedRange() const
		{
			return m_templ_rotation_speed_range;
		}

		//Metoda ustawia stałą referencję na zakres prędkości i kierunek obracania się mudułu
		inline void setTemplateRotationSpeedRange(const std::pair<float, float> & templ_rotation_speed_range)
		{
			m_templ_rotation_speed_range = templ_rotation_speed_range;
		}

		//Metoda zwraca czas trwania stanu - wizualizacja aktywności
		inline const float getTemplateStateTime() const
		{
			return m_templ_state_time;
		}

		//Metoda ustawia czas trwania stanu - wizualizacja aktywności
		inline void setTemplateStateTime(const float templ_state_time)
		{
			m_templ_state_time = templ_state_time;
		}

		//Metoda zwraca prędkość i kierunek obracania się mudułu - wizualizacja aktywności
		inline const float getTemplateRotationSpeed() const
		{
			return m_templ_rotation_speed;
		}

		//Metoda ustawia prędkość i kierunek obracania się mudułu - wizualizacja aktywności
		inline void setTemplateRotationSpeed(const float templ_rotation_speed)
		{
			m_templ_rotation_speed = templ_rotation_speed;
		}

		//Metoda zwraca wskaźnik na obiekt klasy CSlotsRaTemplate
		inline SlotsRateTemplate* getTemplateSlotsRate()
		{
			return p_templ_slot_rate;
		}

		//Metoda ustawia wskaźnik na obiekt klasy SlotsRateTemplate
		inline void setTemplateSlotsRate(SlotsRateTemplate* templ_slot_rate)
		{
			p_templ_slot_rate = templ_slot_rate;
		}

		//Metoda zwraca wskaźnik na obiekt klasy BatteryTemplate
		inline BatteryTemplate* getTemplateBattery()
		{
			return p_templ_battery;
		}

		//Metoda ustawia wskaźnik na obiekt klasy BatteryTemplate
		inline void setTemplateBattery(BatteryTemplate* templ_battery)
		{
			p_templ_battery = templ_battery;
		}

		//Metoda zwraca flagę, czy obiekt posiada baterię
		inline const bool getTemplateUseBattery() const
		{
			return m_templ_use_battery;
		}

		//Metoda ustawia flagę, czyczy obiekt posiada baterię
		inline void setTemplateUseBattery(const bool templ_use_battery)
		{
			m_templ_use_battery = templ_use_battery;
		}

		//Metoda zwraca czas po jakim obiekt wchodzi do stanu obsługi elektrowni
		inline const float getTemplateTimeToStart() const
		{
			return m_templ_time_to_start;
		}

		//Metoda ustawia czas po jakim obiekt wchodzi do stanu obsługi elektrowni
		inline void setTemplateTimeToStart(const float templ_time_to_start)
		{
			m_templ_time_to_start = templ_time_to_start;
		}

		//Metoda zwraca czas trwania procesu wychodzenia ze stanu obsługi elektrowni
		inline const float getTemplateDurationDisconnect() const
		{
			return m_templ_duration_disconnect;
		}

		//Metoda ustawima czas trwania procesu wychodzenia ze stanu obsługi elektrowni
		inline void setTemplateDurationDisconnect(const float templ_duration_disconnect)
		{
			m_templ_duration_disconnect = templ_duration_disconnect;
		}

	private:

		bool m_templ_use_slots_rate; //flaga, czy obiekt posiada moduł prezentacji stanu slotów
		int m_templ_powerstations_capacity;	//ilość obsługiwanych elektrowni
		std::pair<float, float> m_templ_state_time_range; //zakres czasu trwania stanu - wizualizacja aktywności
		std::pair<float, float> m_templ_rotation_speed_range; //zakres prędkości i kieruneku obracania się mudułu
		float m_templ_state_time; //czas trwania stanu - wizualizacja aktywności
		float m_templ_rotation_speed; //prędkość i kierunek obracania się mudułu
		SlotsRateTemplate *p_templ_slot_rate; //wskaźnik na obiekt klasy SlotsRateTemplate (wzorzec modułu wskaźnika przekaźnika (sloty))
		BatteryTemplate *p_templ_battery; //wskaźnik na obiekt klasy BatteryTemplate (wzorzec baterii)
		bool m_templ_use_battery; //flaga, czy obiekt posiada baterię
		float m_templ_time_to_start; //po tym czasie obiekt wchodzi do stanu obsługi elektrowni
		float m_templ_duration_disconnect; //czas trwania procesu disconnect
		
	};	
}//namespace factory
#endif//H_POWER_RELAY_STATION_TEMPLATE_JACK
