//  ______________________________________________
// | CWindPowerStation.h - class definition       |
// | Jack Flower - July 2014                      |
// |______________________________________________|
//

#ifndef H_WIND_POWER_STATION_JACK
#define H_WIND_POWER_STATION_JACK

#include "../CPowerStation.h"
#include "../EWindPowerStationState.h"
#include "../../../../Equipment/Industrial/PowerModuleType/WindTurbine.h"
#include "../../../../Equipment/Industrial/PowerStationData/CWindTurbineData.h"
#include "../../../../RTTI/RTTI.h"

using namespace equipment;
using namespace equipmentpowerstationdata;

namespace logic
{
	namespace powerstation
	{
		///
		///Klasa reprezentuje funkcjonalnoœæ elektrowni wiatrowej
		///
		class CWindPowerStation : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;
			
			//Aby uzyskaæ obiekt CWindPowerStation, nale¿y wywo³aæ CPhysicalManager::CreateWindPowerStation();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			CWindPowerStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CWindPowerStationCopy - obiekt klasy CWindPowerStation
			///
			CWindPowerStation(const CWindPowerStation &CWindPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CWindPowerStation();

		public:
			
			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca stan obiektu
			///
			const EWindPowerStationState getPowerStationState() const;

			///
			///Metoda ustawia stan obiektu
			///
			///@param windpower_station_state - wyliczenie stan obiektu CWindPowerStationState
			///
			void setPowerStationState(const EWindPowerStationState windpower_station_state);

			///
			///Metoda zwraca czas co jaki nastêpuje kondensacja energii
			///
			const float getEnergyCondensationTime() const;

			///
			///Metoda ustawia czas co jaki nastêpuje kondensacja energii
			///
			///@param energy_condensation_time - czas co jaki nastêpuje kondensacja energii
			///
			void setEnergyCondensationTime(const float energy_condensation_time);

			///
			///Metoda zwraca wspó³czynnik bezw³adnoœci
			///
			const float getPortionEenergyFactor() const;

			///
			///Metoda ustawia wspó³czynnik bezw³adnoœci
			///
			///@param portion_energy_factor - wspó³czynnik bezw³adnoœci
			///
			void setPortionEenergyFactor(const float portion_energy_factor);

			///
			///Metoda zwraca porcjê energii - wartoœæ prze³adunku z turbiny
			///
			const float getPortionEnergy() const;

			///
			///Metoda ustawia porcjê energii - wartoœæ prze³adunku z turbiny
			///
			///@param portion_energy - porcja energii
			///
			void setPortionEnergy(const float portion_energy);

			///
			///Metoda zwraca flagê, czy elektrownia wiatrowa posiada turbiê wiatrow¹
			///
			const bool getUseWindTurbine() const;

			///
			///Metoda ustawia flagê, czy elektrownia wiatrowa posiada turbiê wiatrow¹
			///
			///@param use_windturbine - flaga, czy elektrownia wiatrowa posiada turbiê wiatrow¹
			///
			void setUseWindTurbine(const bool use_windturbine);

			///
			///Metoda zwraca wskaŸnik na obiekt klasy WindTurbine
			///
			WindTurbine* getWindTurbine();
		
			///
			///Metoda ustawia wskaŸnik na obiekt klasy WindTurbine
			///
			///@param *windturbine - wskaŸnik na obiekt klasy WindTurbine
			///
			void setWindTurbine(WindTurbine* windturbine);
			
			///
			///Metoda zwraca flagê, czy korpus siê obraca (HEAD)
			///
			const bool getUseRotationHead() const;

			///
			///Metoda ustawia flagê, czy korpus siê obraca (HEAD)
			///
			///@param use_rotation_head - flaga, czy korpus siê obraca (HEAD)
			///
			void setUseRotationHead(const bool use_rotation_head);

			///
			///Metoda zwraca prêdkoœæ obrotu korpusu (HEAD)
			///
			const float getSpeedRotationHead() const;

			///
			///Metoda ustawia prêdkoœæ obrotu korpusu (HEAD)
			///
			///@param speed_rotation_head - rêdkoœæ obrotu korpusu (HEAD)
			///
			void setSpeedRotationHead(const float speed_rotation_head);

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

		protected:

			EWindPowerStationState		m_windpower_station_state;		//wyliczenie stanów obiektu
			CWindTurbineData			m_windturbine_data;				//opakowanie funkcjonalnoœci turbiny wiatrowej
			float						m_energy_condensation_time;		//czas co jaki nastêpuje kondensacja energii
			float						m_portion_energy_factor;		//wspó³czynnik bezw³adnoœci (z turbiny pobieramy mniej energii ni¿ mo¿emy)
			float						m_portion_energy;				//porcja energii, któr¹ bêdê móg³ zabieraæ z turbiny
			bool						m_use_rotation_head;			//flaga okreœla, czy korpus siê obraca (HEAD)
			float						m_speed_rotation_head;			//prêdkoœæ obrotu korpusu (HEAD)
			float						m_damage;						//uszkodzenia/i/lub/proces starzenia - docelowo klasa
			float						m_elapsed_time;					//czas procesu
			static float				s_portion_energy_default;		//porcja energii, któr¹ bêdê móg³ zabieraæ z turbiny (dla bezpieczeñstwa)
			static float				s_portion_energy_factor;		//wspó³czynnik bezw³adnoœci

			//prywatna metoda aktualizuje stan obiektu
			void updateWindPowerState(float dt);

			//prywatna metoda aktualizuje po³o¿enie turbiny wzglêdem w³aœciciela
			void updateCWindTurbineTransformation(float dt);

		};
	}//namespace powerstation
}//namespace logic
#endif//H_WIND_POWER_STATION_JACK
