//  _____________________________________
// | CBattery.h - class definition       |
// | Jack Flower May 2014                |
// |_____________________________________|
//


#ifndef H_BATTERY_JACK
#define H_BATTERY_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Actor/CActor.h"
#include "../../CSwitch.h"
#include "EBatteryState.h"

using namespace logic;

namespace equipment
{
	namespace battery
	{
		///
		///Klasa reprezentruje bateri� (skumulowana energia)
		///
		class CBattery : public CActor
		{
			RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
	
		//Aby uzyska� obiekt CBattery, nale�y wywo�a� CPhysicalManager::CreateBattery();

		protected:

			///
			///Konstruktor domy�lny chroniony
			///
			CBattery(const std::wstring& uniqueId);

			///
			///Konstruktor kopiuj�cy chroniony
			///
			///@param &CBatteryCopy - obiekt klasy CBattery
			///
			CBattery(const CBattery& CBatteryCopy);

			///
			///Destruktor chroniony
			///
			~CBattery();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const ;

			///
			///Metoda zwraca nazw� baterii
			///
			const std::string GetBatteryName() const;

			///
			///Metoda ustawia nazw� baterii
			///
			///@param &battery_name - nazwa obiektu
			///
			const void SetBatteryName(const std::string& battery_name);

			///
			///Metoda zwraca pojemno�� baterii
			///
			const float getCapacity() const;

			///
			///Metoda ustawia pojemno�� baterii
			///
			///@param capacity - pojemno�� baterii
			///
			void setCapacity(float capacity);

			///
			///Metoda zwraca fabryczn� pojemno�� baterii
			///
			const float getFactoryCapacity() const;

			///
			///Metoda ustawia fabryczn� pojemno�� baterii
			///
			///@param factory_capacity - fabryczna pojemno�� baterii
			///
			void setFactoryCapacity(float factory_capacity);

			///
			///Metoda zwraca cz�stk� energii - �adowanie/roz�adowanie
			///
			const float getParticleEnergy() const;

			///
			///Metoda ustawia cz�stk� energii - �adowanie/roz�adowanie
			///
			///@param particle_energy - cz�stka energii - �adowanie/roz�adowanie
			///
			void setParticleEnergy(float particle_energy);

			///
			///Metoda zwraca czas procesu zu�ycia jednostki energii
			///
			const float getBatteryRegenerationDuration() const;

			///
			///Metoda ustawia czas procesu zu�ycia jednostki energii
			///
			///@param battery_regeneration_duration - czas procesu zu�ycia jednostki energii
			///
			void setBatteryRegenerationDuration(float battery_regeneration_duration);

			///
			///Metoda zwraca referencjc� na modu� sterowania
			///
			CSwitch & getUnitController();

			///
			///Metoda zwraca wsp�czynnik stanu (poziomu) na�adowania baterii
			///
			const float getBatteryCharge() const;

			///
			///Metoda ustawia wsp�czynnik stanu (poziomu) na�adowania baterii
			///
			///@param battery_charge - wsp�czynnik stanu (poziomu) na�adowania baterii
			///
			void setBatteryCharge(const float battery_charge);

			///
			///Metoda zwraca wyliczenie stan�w baterii
			///
			const EBatteryState & getBatteryState() const;

			///
			///Metoda ustawia wyliczenie stan�w baterii
			///
			///@param & battery_state - sta�a referencja na wyliczenie EBatteryState
			///
			void setBatteryState(const EBatteryState & battery_state);

			///
			///Metoda uruchamia procesy i funkcjonalno�� baterii
			///
			void runBattery();

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		protected:

			std::string		m_battery_name;						//nazwa baterii (niklowa, kadmowa, litowa, atomowa...etc)
			float			m_capacity;							//pojemno�� baterii - przy ka�dym pe�nym prze�adowaniu - spada o m_decline
			float			m_factory_capacity;					//fabryczna pojemno�� baterii (znamionowa)
			float			m_particle_energy;					//warto�� cz�stki energii przekazywanej z baterii do odbiorcy (zbilansowanie stanu)
			float			m_battery_regeneration_duration;	//czas procesu zu�ycia jednostki energii
			float			m_battery_regeneration_timer;		//lokalny zegar
			CSwitch			m_unit_controller;					//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
			EBatteryState	m_battery_state;					//wyliczenie stan�w dla obiektu CBattery

		private:

			float			m_battery_charge;					//obliczany wsp�czynnik stanu (poziomu) na�adowania baterii
			bool			run_battery;						//flaga uruchamia procesy i funkcjonalno�� baterii
			
			//prywatna metoda aktualizuje stan obiektu - bateria
			void updateBatteryState(float dt);
		};
	}//namespace battery
}//namespace equipment
#endif//H_BATTERY_JACK
