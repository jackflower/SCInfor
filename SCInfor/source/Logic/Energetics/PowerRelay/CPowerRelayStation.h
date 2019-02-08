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
		///Klasa reprezentuje przeka�nik energii elektrycznej
		///
		class CPowerRelayStation : public CRelayStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CPowerRelayStation, nale�y wywo�a� CPhysicalManager::CreatePowerRelayStation();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param &uniqueId - sta�a referencja na obiekt klasy std::wstring
			///
			CPowerRelayStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CPowerRelayStationCopy - obiekt klasy CPowerRelayStation
			///
			CPowerRelayStation(const CPowerRelayStation &CPowerRelayStationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			virtual ~CPowerRelayStation();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;
		
			///
			///Metoda zwraca flag�, czy obiekt posiada modu� prezentacji stanu slot�w
			///
			const bool getUseSlotsRate() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada modu� prezentacji stanu slot�w
			///
			///@param use_slots_rate - flaga, czy obiekt posiada modu� prezentacji stanu slot�w
			///
			void setUseSlotsRate(const bool use_slots_rate);

			///
			///Metoda zwraca ilo�� elektrowni, kt�re modu� mo�e obs�ugiwa�
			///
			const int getPowerstationsCapacity() const;

			///
			///Metoda ustawia ilo�� elektrowni, kt�re modu� mo�e obs�ugiwa�
			///
			///@param powerstations_capacity - ilo�� obs�ugiwanych elektrowni
			///
			void setPowerstationsCapacity(const int powerstations_capacity);

			///
			///Metoda zwraca sta�� referencj� na zakres czasu trwania stanu - wizualizacja aktywno�ci
			///
			const std::pair<float, float> & getStateTimeRange() const;

			///
			///Metoda ustawia sta�� referencj� na zakres czasu trwania stanu - wizualizacja aktywno�ci
			///
			///@param & state_time_range - referencja na obiekt klasy std::pair<float, float>
			///
			void setStateTimeRange(const std::pair<float, float> & state_time_range);

			///
			///Metoda zwraca sta�� referencj� na zakres pr�dko�ci i kierunek obracania si� mudu�u
			///
			const std::pair<float, float> & getRotationSpeedRange() const;

			///
			///Metoda ustawia sta�� referencj� na zakres pr�dko�ci i kierunek obracania si� mudu�u
			///
			///@param & rotation_speed_range - referencja na obiekt klasy std::pair<float, float>
			///
			void setRotationSpeedRange(const std::pair<float, float> & rotation_speed_range);

			///
			///Metoda zwraca ilo�� zaj�tych slot�w, do kt�rych zalogowane s� elektrownie
			///
			const int getBusySlots() const;

			///
			///Metoda ustawia ilo�� zaj�tych slot�w, do kt�rych zalogowane s� elektrownie
			///
			///@param busy_slots - ilo�� obs�ugiwanych elektrowni
			///
			void setBusySlots(const int busy_slots);

			///
			///Metoda zwraca czas trwania stanu - wizualizacja aktywno�ci
			///
			const float getStateTime() const;

			///
			///Metoda ustawia czas trwania stanu - wizualizacja aktywno�ci
			///
			///@param state_time -  czas trwania stanu
			///
			void setStateTime(const float state_time);

			///
			///Metoda zwraca pr�dko�� i kierunek obracania si� mudu�u - wizualizacja aktywno�ci
			///
			const float getRotationSpeed() const;

			///
			///Metoda ustawia pr�dko�� i kierunek obracania si� mudu�u - wizualizacja aktywno�ci
			///
			///@param rotation_speed - pr�dko�� i kierunek obracania si� mudu�u
			///
			void setRotationSpeed(const float rotation_speed);

			///
			///Metoda zwraca wska�nik na obiekt klasy CSlotsRate
			///
			CSlotsRate* getSlotsRate();

			///
			///Metoda ustawia wska�nik na obiekt klasy CSlotsRate
			///
			///@param *slots_rate - wska�nik na obiekt CSlotsRate
			///
			void setSlotsRate(CSlotsRate* slots_rate);

			///
			///Metoda zwraca wska�nik na obiekt klasy Battery
			///
			Battery* getBattery();

			///
			///Metoda ustawia wska�nik na obiekt klasy Battery
			///
			///@param *battery - wska�nik na obiekt Battery
			///
			void setBattery(Battery* battery);

			///
			///Metoda zwraca flag�, czy obiekt posiada bateri�
			///
			const bool getUseBattery() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada bateri�
			///
			///@param use_battery - flaga, czy obiekt posiada bateri�
			///
			void setUseBattery(const bool use_battery);

			///
			///Metoda zwraca czas do rozpocz�cia g��wnego zadania obiektu
			///
			const float getTimeToStart() const;

			///
			///Metoda ustawia czas do rozpocz�cia g��wnego zadania obiektu
			///
			///@param time_to_start - czas do rozpocz�cia g��wnego zadania obiektu
			///
			void setTimeToStart(const float time_to_start);

			///
			///Metoda zwraca czas trwania procesu do wyga�ni�cia g��wnego zadania obiektu
			///
			const float getDurationDisconnect() const;

			///
			///Metoda ustawia czas trwania procesu do wyga�ni�cia g��wnego zadania obiektu
			///
			///@param duration_disconnect - czas trwania procesu disconnect
			///
			void setDurationDisconnect(const float duration_disconnect);

			///
			///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			typedef std::vector<CWindPowerStation*>	PowerstationList;	//definicja typu - kontener na elektrownie
			
			PowerstationList			m_powerstations;			//elektrownie
			EPowerRelayStationState		m_powerrelaystation_state;	//wyliczenie stan�w obiektu - przeka�nika energii elektrycznej
			CSlotsRateData				m_slotsrate_date;			//opakowanie funkcjonalno�ci  wska�nika przeka�nika - sloty
			int							m_powerstations_capacity;	//ilo�� obs�ugiwanych elektrowni
			int							m_busy_slots;				//ilo�� zaj�tych slot�w
			std::pair<float, float>		m_state_time_range;			//zakres czasu trwania stanu - wizualizacja aktywno�ci
			std::pair<float, float>		m_rotation_speed_range;		//zakres pr�dko�ci i kierunek obracania si� mudu�u
			float						m_state_time;				//czas trwania stanu - wizualizacja aktywno�ci behawiorystyka
			float						m_rotation_speed;			//pr�dko�� i kierunek obracania si� mudu�u
			EquipmentBatteryData		m_battery_data;				//opakowanie funkcjonalno�ci baterii
			float						m_time_to_start;			//po tym czasie obiekt wchodzi do stanu obs�ugi elektrowni
			float						m_duration_disconnect;		//czas trwania procesu disconnect

		private:

			void updatePowerRelayStationBehavior(float dt);			//prywatna metoda aktualizuje stan obiektu - behawiorystyka
			void updatePowerRelayStationState(float dt);			//prywatna metoda aktualizuje stan obiektu

		protected:
			//metoda aktualizuje wska�nik na obiekt CSlotsRate - geometria
			void updateSlotRateTransformation(float dt);

		};
	}//namespace energetics
}//namespace logic
#endif//H_POWER_RELAY_STATION_JACK
