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
		///Klasa reprezentuje funkcjonalno�� elektrowni wiatrowej
		///
		class CWindPowerStation : public CPowerStation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;
			
			//Aby uzyska� obiekt CWindPowerStation, nale�y wywo�a� CPhysicalManager::CreateWindPowerStation();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			CWindPowerStation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CWindPowerStationCopy - obiekt klasy CWindPowerStation
			///
			CWindPowerStation(const CWindPowerStation &CWindPowerStationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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
			///Metoda zwraca czas co jaki nast�puje kondensacja energii
			///
			const float getEnergyCondensationTime() const;

			///
			///Metoda ustawia czas co jaki nast�puje kondensacja energii
			///
			///@param energy_condensation_time - czas co jaki nast�puje kondensacja energii
			///
			void setEnergyCondensationTime(const float energy_condensation_time);

			///
			///Metoda zwraca wsp�czynnik bezw�adno�ci
			///
			const float getPortionEenergyFactor() const;

			///
			///Metoda ustawia wsp�czynnik bezw�adno�ci
			///
			///@param portion_energy_factor - wsp�czynnik bezw�adno�ci
			///
			void setPortionEenergyFactor(const float portion_energy_factor);

			///
			///Metoda zwraca porcj� energii - warto�� prze�adunku z turbiny
			///
			const float getPortionEnergy() const;

			///
			///Metoda ustawia porcj� energii - warto�� prze�adunku z turbiny
			///
			///@param portion_energy - porcja energii
			///
			void setPortionEnergy(const float portion_energy);

			///
			///Metoda zwraca flag�, czy elektrownia wiatrowa posiada turbi� wiatrow�
			///
			const bool getUseWindTurbine() const;

			///
			///Metoda ustawia flag�, czy elektrownia wiatrowa posiada turbi� wiatrow�
			///
			///@param use_windturbine - flaga, czy elektrownia wiatrowa posiada turbi� wiatrow�
			///
			void setUseWindTurbine(const bool use_windturbine);

			///
			///Metoda zwraca wska�nik na obiekt klasy WindTurbine
			///
			WindTurbine* getWindTurbine();
		
			///
			///Metoda ustawia wska�nik na obiekt klasy WindTurbine
			///
			///@param *windturbine - wska�nik na obiekt klasy WindTurbine
			///
			void setWindTurbine(WindTurbine* windturbine);
			
			///
			///Metoda zwraca flag�, czy korpus si� obraca (HEAD)
			///
			const bool getUseRotationHead() const;

			///
			///Metoda ustawia flag�, czy korpus si� obraca (HEAD)
			///
			///@param use_rotation_head - flaga, czy korpus si� obraca (HEAD)
			///
			void setUseRotationHead(const bool use_rotation_head);

			///
			///Metoda zwraca pr�dko�� obrotu korpusu (HEAD)
			///
			const float getSpeedRotationHead() const;

			///
			///Metoda ustawia pr�dko�� obrotu korpusu (HEAD)
			///
			///@param speed_rotation_head - r�dko�� obrotu korpusu (HEAD)
			///
			void setSpeedRotationHead(const float speed_rotation_head);

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

		protected:

			EWindPowerStationState		m_windpower_station_state;		//wyliczenie stan�w obiektu
			CWindTurbineData			m_windturbine_data;				//opakowanie funkcjonalno�ci turbiny wiatrowej
			float						m_energy_condensation_time;		//czas co jaki nast�puje kondensacja energii
			float						m_portion_energy_factor;		//wsp�czynnik bezw�adno�ci (z turbiny pobieramy mniej energii ni� mo�emy)
			float						m_portion_energy;				//porcja energii, kt�r� b�d� m�g� zabiera� z turbiny
			bool						m_use_rotation_head;			//flaga okre�la, czy korpus si� obraca (HEAD)
			float						m_speed_rotation_head;			//pr�dko�� obrotu korpusu (HEAD)
			float						m_damage;						//uszkodzenia/i/lub/proces starzenia - docelowo klasa
			float						m_elapsed_time;					//czas procesu
			static float				s_portion_energy_default;		//porcja energii, kt�r� b�d� m�g� zabiera� z turbiny (dla bezpiecze�stwa)
			static float				s_portion_energy_factor;		//wsp�czynnik bezw�adno�ci

			//prywatna metoda aktualizuje stan obiektu
			void updateWindPowerState(float dt);

			//prywatna metoda aktualizuje po�o�enie turbiny wzgl�dem w�a�ciciela
			void updateCWindTurbineTransformation(float dt);

		};
	}//namespace powerstation
}//namespace logic
#endif//H_WIND_POWER_STATION_JACK
