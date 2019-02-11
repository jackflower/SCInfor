//  ______________________________________________
// | PowerRelayStation.h - class definition       |
// | Jack Flower - July 2015                      |
// |______________________________________________|
//

#ifndef H_POWER_RELAY_STATION_JACK
#define H_POWER_RELAY_STATION_JACK

#include "RelayStation.h"
#include "EPowerRelayStationState.h"
#include "SlotsRate.h"
#include "../RelayStationData/SlotsRateData.h"
#include "../../Actor/Actor.h"
#include "../../Industrial/PowerStation/PowerStation.h"
#include "../../Industrial/PowerStation/WindPowerStation/WindPowerStation.h"
#include "../../Communication/Communication.h"
#include "../../../Equipment/Energy/Battery/Battery.h"
#include "../../../Equipment/EquipmentData/EquipmentBatteryData.h"


using namespace equipment::battery;
using namespace relaystationdata;

namespace logic
{
	namespace energetics
	{
		///
		///Klasa reprezentuje przekaźnik energii elektrycznej
		///
		class PowerRelayStation : public RelayStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class CPhysicalManager;

			//Aby uzyskać obiekt PowerRelayStation, należy wywołać CPhysicalManager::CreatePowerRelayStation();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring
			///
			PowerRelayStation(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param PowerRelayStationCopy - obiekt klasy PowerRelayStation
			///
			PowerRelayStation(const PowerRelayStation & PowerRelayStationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
			///
			virtual ~PowerRelayStation();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;
		
			///
			///Metoda zwraca flagę, czy obiekt posiada moduł prezentacji stanu slotów
			///
			const bool getUseSlotsRate() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada moduł prezentacji stanu slotów
			///
			///@param use_slots_rate - flaga, czy obiekt posiada moduł prezentacji stanu slotów
			///
			void setUseSlotsRate(const bool use_slots_rate);

			///
			///Metoda zwraca ilość elektrowni, które moduł może obsługiwać
			///
			const int getPowerstationsCapacity() const;

			///
			///Metoda ustawia ilość elektrowni, które moduł może obsługiwać
			///
			///@param powerstations_capacity - ilość obsługiwanych elektrowni
			///
			void setPowerstationsCapacity(const int powerstations_capacity);

			///
			///Metoda zwraca stałą referencję na zakres czasu trwania stanu - wizualizacja aktywności
			///
			const std::pair<float, float> & getStateTimeRange() const;

			///
			///Metoda ustawia stałą referencję na zakres czasu trwania stanu - wizualizacja aktywności
			///
			///@param state_time_range - referencja na obiekt klasy std::pair<float, float>
			///
			void setStateTimeRange(const std::pair<float, float> & state_time_range);

			///
			///Metoda zwraca stałą referencję na zakres prędkości i kierunek obracania się mudułu
			///
			const std::pair<float, float> & getRotationSpeedRange() const;

			///
			///Metoda ustawia stałą referencję na zakres prędkości i kierunek obracania się mudułu
			///
			///@param rotation_speed_range - referencja na obiekt klasy std::pair<float, float>
			///
			void setRotationSpeedRange(const std::pair<float, float> & rotation_speed_range);

			///
			///Metoda zwraca ilość zajętych slotów, do których zalogowane są elektrownie
			///
			const int getBusySlots() const;

			///
			///Metoda ustawia ilość zajętych slotów, do których zalogowane są elektrownie
			///
			///@param busy_slots - ilość obsługiwanych elektrowni
			///
			void setBusySlots(const int busy_slots);

			///
			///Metoda zwraca czas trwania stanu - wizualizacja aktywności
			///
			const float getStateTime() const;

			///
			///Metoda ustawia czas trwania stanu - wizualizacja aktywności
			///
			///@param state_time -  czas trwania stanu
			///
			void setStateTime(const float state_time);

			///
			///Metoda zwraca prędkość i kierunek obracania się mudułu - wizualizacja aktywności
			///
			const float getRotationSpeed() const;

			///
			///Metoda ustawia prędkość i kierunek obracania się mudułu - wizualizacja aktywności
			///
			///@param rotation_speed - prędkość i kierunek obracania się mudułu
			///
			void setRotationSpeed(const float rotation_speed);

			///
			///Metoda zwraca wskaźnik na obiekt klasy SlotsRate
			///
			SlotsRate *getSlotsRate();

			///
			///Metoda ustawia wskaźnik na obiekt klasy SlotsRate
			///
			///@param *slots_rate - wskaźnik na obiekt SlotsRate
			///
			void setSlotsRate(SlotsRate *slots_rate);

			///
			///Metoda zwraca wskaźnik na obiekt klasy Battery
			///
			Battery *getBattery();

			///
			///Metoda ustawia wskaźnik na obiekt klasy Battery
			///
			///@param *battery - wskaźnik na obiekt Battery
			///
			void setBattery(Battery *battery);

			///
			///Metoda zwraca flagę, czy obiekt posiada baterię
			///
			const bool getUseBattery() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada baterię
			///
			///@param use_battery - flaga, czy obiekt posiada baterię
			///
			void setUseBattery(const bool use_battery);

			///
			///Metoda zwraca czas do rozpoczęcia głównego zadania obiektu
			///
			const float getTimeToStart() const;

			///
			///Metoda ustawia czas do rozpoczęcia głównego zadania obiektu
			///
			///@param time_to_start - czas do rozpoczęcia głównego zadania obiektu
			///
			void setTimeToStart(const float time_to_start);

			///
			///Metoda zwraca czas trwania procesu do wygaśnięcia głównego zadania obiektu
			///
			const float getDurationDisconnect() const;

			///
			///Metoda ustawia czas trwania procesu do wygaśnięcia głównego zadania obiektu
			///
			///@param duration_disconnect - czas trwania procesu disconnect
			///
			void setDurationDisconnect(const float duration_disconnect);

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			typedef std::vector<WindPowerStation*>	PowerstationList; //definicja typu - kontener na elektrownie
			
			PowerstationList m_powerstations; //elektrownie
			EPowerRelayStationState m_powerrelaystation_state;//wyliczenie stanów obiektu - przekaźnika energii elektrycznej
			SlotsRateData m_slotsrate_date; //opakowanie funkcjonalności  wskaźnika przekaźnika - sloty
			int m_powerstations_capacity; //ilość obsługiwanych elektrowni
			int m_busy_slots; //ilość zajętych slotów
			std::pair<float, float> m_state_time_range; //zakres czasu trwania stanu - wizualizacja aktywności
			std::pair<float, float> m_rotation_speed_range; //zakres prędkości i kierunek obracania się mudułu
			float m_state_time; //czas trwania stanu - wizualizacja aktywności behawiorystyka
			float m_rotation_speed; //prędkość i kierunek obracania się mudułu
			EquipmentBatteryData m_battery_data; //opakowanie funkcjonalności baterii
			float m_time_to_start; //po tym czasie obiekt wchodzi do stanu obsługi elektrowni
			float m_duration_disconnect; //czas trwania procesu disconnect

		private:

			void updatePowerRelayStationBehavior(float dt); //prywatna metoda aktualizuje stan obiektu - behawiorystyka
			void updatePowerRelayStationState(float dt); //prywatna metoda aktualizuje stan obiektu

		protected:
			//metoda aktualizuje wskaźnik na obiekt SlotsRate - geometria
			void updateSlotRateTransformation(float dt);

		};
	}//namespace energetics
}//namespace logic
#endif//H_POWER_RELAY_STATION_JACK
