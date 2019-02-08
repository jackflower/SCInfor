//  _______________________________________________
// | CPowerRelayStation.h - class definition       |
// | Jack Flower - July 2015                       |
// |_______________________________________________|
//

#ifndef H_POWER_RELAY_STATION_JACK
#define H_POWER_RELAY_STATION_JACK

#include "CRelayStation.h"
#include "EPowerRelayStationState.h"
#include "CSlotsRate.h"
#include "../RelayStationData/CSlotsRateData.h"
#include "../../Actor/Actor.h"
#include "../../Industrial/PowerStation/CPowerStation.h"
#include "../../Industrial/PowerStation/WindPowerStation/CWindPowerStation.h"
#include "../../Communication/CCommunication.h"
#include "../../../Equipment/Energy/Battery/Battery.h"
#include "../../../Equipment/EquipmentData/EquipmentBatteryData.h"


using namespace equipment::battery;
using namespace relaystationdata;

namespace logic
{
	namespace energetics
	{
		///
		///Klasa reprezentuje przekaŸnik energii elektrycznej
		///
		class CPowerRelayStation : public CRelayStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CPowerRelayStation, nale¿y wywo³aæ CPhysicalManager::CreatePowerRelayStation();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			///@param &uniqueId - sta³a referencja na obiekt klasy std::wstring
			///
			CPowerRelayStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CPowerRelayStationCopy - obiekt klasy CPowerRelayStation
			///
			CPowerRelayStation(const CPowerRelayStation &CPowerRelayStationCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			virtual ~CPowerRelayStation();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;
		
			///
			///Metoda zwraca flagê, czy obiekt posiada modu³ prezentacji stanu slotów
			///
			const bool getUseSlotsRate() const;

			///
			///Metoda ustawia flagê, czy obiekt posiada modu³ prezentacji stanu slotów
			///
			///@param use_slots_rate - flaga, czy obiekt posiada modu³ prezentacji stanu slotów
			///
			void setUseSlotsRate(const bool use_slots_rate);

			///
			///Metoda zwraca iloœæ elektrowni, które modu³ mo¿e obs³ugiwaæ
			///
			const int getPowerstationsCapacity() const;

			///
			///Metoda ustawia iloœæ elektrowni, które modu³ mo¿e obs³ugiwaæ
			///
			///@param powerstations_capacity - iloœæ obs³ugiwanych elektrowni
			///
			void setPowerstationsCapacity(const int powerstations_capacity);

			///
			///Metoda zwraca sta³¹ referencjê na zakres czasu trwania stanu - wizualizacja aktywnoœci
			///
			const std::pair<float, float> & getStateTimeRange() const;

			///
			///Metoda ustawia sta³¹ referencjê na zakres czasu trwania stanu - wizualizacja aktywnoœci
			///
			///@param & state_time_range - referencja na obiekt klasy std::pair<float, float>
			///
			void setStateTimeRange(const std::pair<float, float> & state_time_range);

			///
			///Metoda zwraca sta³¹ referencjê na zakres prêdkoœci i kierunek obracania siê mudu³u
			///
			const std::pair<float, float> & getRotationSpeedRange() const;

			///
			///Metoda ustawia sta³¹ referencjê na zakres prêdkoœci i kierunek obracania siê mudu³u
			///
			///@param & rotation_speed_range - referencja na obiekt klasy std::pair<float, float>
			///
			void setRotationSpeedRange(const std::pair<float, float> & rotation_speed_range);

			///
			///Metoda zwraca iloœæ zajêtych slotów, do których zalogowane s¹ elektrownie
			///
			const int getBusySlots() const;

			///
			///Metoda ustawia iloœæ zajêtych slotów, do których zalogowane s¹ elektrownie
			///
			///@param busy_slots - iloœæ obs³ugiwanych elektrowni
			///
			void setBusySlots(const int busy_slots);

			///
			///Metoda zwraca czas trwania stanu - wizualizacja aktywnoœci
			///
			const float getStateTime() const;

			///
			///Metoda ustawia czas trwania stanu - wizualizacja aktywnoœci
			///
			///@param state_time -  czas trwania stanu
			///
			void setStateTime(const float state_time);

			///
			///Metoda zwraca prêdkoœæ i kierunek obracania siê mudu³u - wizualizacja aktywnoœci
			///
			const float getRotationSpeed() const;

			///
			///Metoda ustawia prêdkoœæ i kierunek obracania siê mudu³u - wizualizacja aktywnoœci
			///
			///@param rotation_speed - prêdkoœæ i kierunek obracania siê mudu³u
			///
			void setRotationSpeed(const float rotation_speed);

			///
			///Metoda zwraca wskaŸnik na obiekt klasy CSlotsRate
			///
			CSlotsRate* getSlotsRate();

			///
			///Metoda ustawia wskaŸnik na obiekt klasy CSlotsRate
			///
			///@param *slots_rate - wskaŸnik na obiekt CSlotsRate
			///
			void setSlotsRate(CSlotsRate* slots_rate);

			///
			///Metoda zwraca wskaŸnik na obiekt klasy Battery
			///
			Battery* getBattery();

			///
			///Metoda ustawia wskaŸnik na obiekt klasy Battery
			///
			///@param *battery - wskaŸnik na obiekt Battery
			///
			void setBattery(Battery* battery);

			///
			///Metoda zwraca flagê, czy obiekt posiada bateriê
			///
			const bool getUseBattery() const;

			///
			///Metoda ustawia flagê, czy obiekt posiada bateriê
			///
			///@param use_battery - flaga, czy obiekt posiada bateriê
			///
			void setUseBattery(const bool use_battery);

			///
			///Metoda zwraca czas do rozpoczêcia g³ównego zadania obiektu
			///
			const float getTimeToStart() const;

			///
			///Metoda ustawia czas do rozpoczêcia g³ównego zadania obiektu
			///
			///@param time_to_start - czas do rozpoczêcia g³ównego zadania obiektu
			///
			void setTimeToStart(const float time_to_start);

			///
			///Metoda zwraca czas trwania procesu do wygaœniêcia g³ównego zadania obiektu
			///
			const float getDurationDisconnect() const;

			///
			///Metoda ustawia czas trwania procesu do wygaœniêcia g³ównego zadania obiektu
			///
			///@param duration_disconnect - czas trwania procesu disconnect
			///
			void setDurationDisconnect(const float duration_disconnect);

			///
			///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			typedef std::vector<CWindPowerStation*>	PowerstationList;	//definicja typu - kontener na elektrownie
			
			PowerstationList			m_powerstations;			//elektrownie
			EPowerRelayStationState		m_powerrelaystation_state;	//wyliczenie stanów obiektu - przekaŸnika energii elektrycznej
			CSlotsRateData				m_slotsrate_date;			//opakowanie funkcjonalnoœci  wskaŸnika przekaŸnika - sloty
			int							m_powerstations_capacity;	//iloœæ obs³ugiwanych elektrowni
			int							m_busy_slots;				//iloœæ zajêtych slotów
			std::pair<float, float>		m_state_time_range;			//zakres czasu trwania stanu - wizualizacja aktywnoœci
			std::pair<float, float>		m_rotation_speed_range;		//zakres prêdkoœci i kierunek obracania siê mudu³u
			float						m_state_time;				//czas trwania stanu - wizualizacja aktywnoœci behawiorystyka
			float						m_rotation_speed;			//prêdkoœæ i kierunek obracania siê mudu³u
			EquipmentBatteryData		m_battery_data;				//opakowanie funkcjonalnoœci baterii
			float						m_time_to_start;			//po tym czasie obiekt wchodzi do stanu obs³ugi elektrowni
			float						m_duration_disconnect;		//czas trwania procesu disconnect

		private:

			void updatePowerRelayStationBehavior(float dt);			//prywatna metoda aktualizuje stan obiektu - behawiorystyka
			void updatePowerRelayStationState(float dt);			//prywatna metoda aktualizuje stan obiektu

		protected:
			//metoda aktualizuje wskaŸnik na obiekt CSlotsRate - geometria
			void updateSlotRateTransformation(float dt);

		};
	}//namespace energetics
}//namespace logic
#endif//H_POWER_RELAY_STATION_JACK
