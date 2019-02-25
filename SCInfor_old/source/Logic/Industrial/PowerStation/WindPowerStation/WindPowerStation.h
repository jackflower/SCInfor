//  _____________________________________________
// | WindPowerStation.h - class definition       |
// | Jack Flower - July 2014                     |
// |_____________________________________________|
//

#ifndef H_WIND_POWER_STATION_JACK
#define H_WIND_POWER_STATION_JACK

#include "../PowerStation.h"
#include "../EWindPowerStationState.h"
#include "../../../../Equipment/Industrial/PowerModuleType/WindTurbine.h"
#include "../../../../Equipment/Industrial/PowerStationData/WindTurbineData.h"
#include "../../../../RTTI/RTTI.h"

using namespace equipment;
using namespace equipmentpowerstationdata;

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalność elektrowni wiatrowej
		///
		class WindPowerStation : public PowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;
			
			//Aby uzyskać obiekt WindPowerStation, należy wywołać PhysicalManager::CreateWindPowerStation();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			WindPowerStation(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param WindPowerStationCopy - stała referencja na obiekt klasy WindPowerStation
			///
			WindPowerStation(const WindPowerStation & WindPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~WindPowerStation();

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca stan obiektu
			///
			const EWindPowerStationState getPowerStationState() const;

			///
			///Metoda ustawia stan obiektu
			///
			///@param windpower_station_state - stała referencja na wyliczenie stan obiektu CWindPowerStationState
			///
			void setPowerStationState(const EWindPowerStationState & windpower_station_state);

			///
			///Metoda zwraca czas co jaki następuje kondensacja energii
			///
			const float getEnergyCondensationTime() const;

			///
			///Metoda ustawia czas co jaki następuje kondensacja energii
			///
			///@param energy_condensation_time - czas co jaki następuje kondensacja energii
			///
			void setEnergyCondensationTime(const float energy_condensation_time);

			///
			///Metoda zwraca współczynnik bezwładności
			///
			const float getPortionEenergyFactor() const;

			///
			///Metoda ustawia współczynnik bezwładności
			///
			///@param portion_energy_factor - współczynnik bezwładności
			///
			void setPortionEenergyFactor(const float portion_energy_factor);

			///
			///Metoda zwraca porcję energii - wartość przeładunku z turbiny
			///
			const float getPortionEnergy() const;

			///
			///Metoda ustawia porcję energii - wartość przeładunku z turbiny
			///
			///@param portion_energy - porcja energii
			///
			void setPortionEnergy(const float portion_energy);

			///
			///Metoda zwraca flagę, czy elektrownia wiatrowa posiada turbię wiatrową
			///
			const bool getUseWindTurbine() const;

			///
			///Metoda ustawia flagę, czy elektrownia wiatrowa posiada turbię wiatrową
			///
			///@param use_windturbine - flaga, czy elektrownia wiatrowa posiada turbię wiatrową
			///
			void setUseWindTurbine(const bool use_windturbine);

			///
			///Metoda zwraca wskaźnik na obiekt klasy WindTurbine
			///
			WindTurbine *getWindTurbine();
		
			///
			///Metoda ustawia wskaźnik na obiekt klasy WindTurbine
			///
			///@param *windturbine - wskaźnik na obiekt klasy WindTurbine
			///
			void setWindTurbine(WindTurbine *windturbine);
			
			///
			///Metoda zwraca flagę, czy korpus się obraca (HEAD)
			///
			const bool getUseRotationHead() const;

			///
			///Metoda ustawia flagę, czy korpus się obraca (HEAD)
			///
			///@param use_rotation_head - flaga, czy korpus się obraca (HEAD)
			///
			void setUseRotationHead(const bool use_rotation_head);

			///
			///Metoda zwraca prędkość obrotu korpusu (HEAD)
			///
			const float getSpeedRotationHead() const;

			///
			///Metoda ustawia prędkość obrotu korpusu (HEAD)
			///
			///@param speed_rotation_head - rędkość obrotu korpusu (HEAD)
			///
			void setSpeedRotationHead(const float speed_rotation_head);

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

		protected:

			EWindPowerStationState m_windpower_station_state; //wyliczenie stanów obiektu
			WindTurbineData m_windturbine_data; //opakowanie funkcjonalności turbiny wiatrowej
			float m_energy_condensation_time; //czas co jaki następuje kondensacja energii
			float m_portion_energy_factor; //współczynnik bezwładności (z turbiny pobieramy mniej energii niż możemy)
			float m_portion_energy; //porcja energii, którą będę mógł zabierać z turbiny
			bool m_use_rotation_head; //flaga określa, czy korpus się obraca (HEAD)
			float m_speed_rotation_head; //prędkość obrotu korpusu (HEAD)
			float m_damage; //uszkodzenia/i/lub/proces starzenia - docelowo klasa
			float m_elapsed_time; //czas procesu
			static float s_portion_energy_default; //porcja energii, którą będę mógł zabierać z turbiny (dla bezpieczeństwa)
			static float s_portion_energy_factor; //współczynnik bezwładności

			//prywatna metoda aktualizuje stan obiektu
			void updateWindPowerState(float dt);

			//prywatna metoda aktualizuje położenie turbiny względem właściciela
			void updateCWindTurbineTransformation(float dt);

		};
	}//namespace powerstation
}//namespace logic
#endif//H_WIND_POWER_STATION_JACK
