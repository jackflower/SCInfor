//  ____________________________________
// | Battery.h - class definition       |
// | Jack Flower May 2014               |
// |____________________________________|
//


#ifndef H_BATTERY_JACK
#define H_BATTERY_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Actor/Actor.h"
#include "../../Switch.h"
#include "EBatteryState.h"

using namespace logic;

namespace equipment
{
	namespace battery
	{
		///
		///Klasa reprezentruje baterię (skumulowana energia)
		///
		class Battery : public Actor
		{
			RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
	
		//Aby uzyskać obiekt Battery, należy wywołać CPhysicalManager::CreateBattery();

		protected:

			///
			///Konstruktor domyślny chroniony
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			Battery(const std::wstring & uniqueId);

			///
			///Konstruktor kopiujący chroniony
			///
			///@param BatteryCopy - stała referencja na obiekt klasy Battery
			///
			Battery(const Battery & BatteryCopy);

			///
			///Destruktor wirtualny chroniony
			///
			virtual ~Battery();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const ;

			///
			///Metoda zwraca nazwę baterii
			///
			const std::string getBatteryName() const;

			///
			///Metoda ustawia nazwę baterii
			///
			///@param battery_name - nazwa obiektu
			///
			void setBatteryName(const std::string & battery_name);

			///
			///Metoda zwraca pojemność baterii
			///
			const float getCapacity() const;

			///
			///Metoda ustawia pojemność baterii
			///
			///@param capacity - pojemność baterii
			///
			void setCapacity(float capacity);

			///
			///Metoda zwraca fabryczną pojemność baterii
			///
			const float getFactoryCapacity() const;

			///
			///Metoda ustawia fabryczną pojemność baterii
			///
			///@param factory_capacity - fabryczna pojemność baterii
			///
			void setFactoryCapacity(float factory_capacity);

			///
			///Metoda zwraca cząstkę energii - ładowanie/rozładowanie
			///
			const float getParticleEnergy() const;

			///
			///Metoda ustawia cząstkę energii - ładowanie/rozładowanie
			///
			///@param particle_energy - cząstka energii - ładowanie/rozładowanie
			///
			void setParticleEnergy(float particle_energy);

			///
			///Metoda zwraca czas procesu zużycia jednostki energii
			///
			const float getBatteryRegenerationDuration() const;

			///
			///Metoda ustawia czas procesu zużycia jednostki energii
			///
			///@param battery_regeneration_duration - czas procesu zużycia jednostki energii
			///
			void setBatteryRegenerationDuration(float battery_regeneration_duration);

			///
			///Metoda zwraca referencjcę na moduł sterowania
			///
			Switch & getUnitController();

			///
			///Metoda zwraca współczynnik stanu (poziomu) naładowania baterii
			///
			const float getBatteryCharge() const;

			///
			///Metoda ustawia współczynnik stanu (poziomu) naładowania baterii
			///
			///@param battery_charge - współczynnik stanu (poziomu) naładowania baterii
			///
			void setBatteryCharge(const float battery_charge);

			///
			///Metoda zwraca wyliczenie stanów baterii
			///
			const EBatteryState & getBatteryState() const;

			///
			///Metoda ustawia wyliczenie stanów baterii
			///
			///@param battery_state - stała referencja na wyliczenie EBatteryState
			///
			void setBatteryState(const EBatteryState & battery_state);

			///
			///Metoda uruchamia procesy i funkcjonalność baterii
			///
			void runBattery();

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			std::string		m_battery_name;						//nazwa baterii (niklowa, kadmowa, litowa, atomowa...etc)
			float			m_capacity;							//pojemność baterii - przy każdym pełnym przeładowaniu - spada o m_decline
			float			m_factory_capacity;					//fabryczna pojemność baterii (znamionowa)
			float			m_particle_energy;					//wartość cząstki energii przekazywanej z baterii do odbiorcy (zbilansowanie stanu)
			float			m_battery_regeneration_duration;	//czas procesu zużycia jednostki energii
			float			m_battery_regeneration_timer;		//lokalny zegar
			Switch			m_unit_controller;					//włącznik, sterownik, moduł zarządzania, starter, stacyjka
			EBatteryState	m_battery_state;					//wyliczenie stanów dla obiektu Battery

		private:

			float			m_battery_charge;					//obliczany współczynnik stanu (poziomu) naładowania baterii
			bool			run_battery;						//flaga uruchamia procesy i funkcjonalność baterii
			
			//prywatna metoda aktualizuje stan obiektu - bateria
			void updateBatteryState(float dt);
		};
	}//namespace battery
}//namespace equipment
#endif//H_BATTERY_JACK
