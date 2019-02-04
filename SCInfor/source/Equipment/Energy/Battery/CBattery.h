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
		///Klasa reprezentruje bateriê (skumulowana energia)
		///
		class CBattery : public CActor
		{
			RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
	
		//Aby uzyskaæ obiekt CBattery, nale¿y wywo³aæ CPhysicalManager::CreateBattery();

		protected:

			///
			///Konstruktor domyœlny chroniony
			///
			CBattery(const std::wstring& uniqueId);

			///
			///Konstruktor kopiuj¹cy chroniony
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
			///Metoda zwraca nazwê baterii
			///
			const std::string GetBatteryName() const;

			///
			///Metoda ustawia nazwê baterii
			///
			///@param &battery_name - nazwa obiektu
			///
			const void SetBatteryName(const std::string& battery_name);

			///
			///Metoda zwraca pojemnoœæ baterii
			///
			const float getCapacity() const;

			///
			///Metoda ustawia pojemnoœæ baterii
			///
			///@param capacity - pojemnoœæ baterii
			///
			void setCapacity(float capacity);

			///
			///Metoda zwraca fabryczn¹ pojemnoœæ baterii
			///
			const float getFactoryCapacity() const;

			///
			///Metoda ustawia fabryczn¹ pojemnoœæ baterii
			///
			///@param factory_capacity - fabryczna pojemnoœæ baterii
			///
			void setFactoryCapacity(float factory_capacity);

			///
			///Metoda zwraca cz¹stkê energii - ³adowanie/roz³adowanie
			///
			const float getParticleEnergy() const;

			///
			///Metoda ustawia cz¹stkê energii - ³adowanie/roz³adowanie
			///
			///@param particle_energy - cz¹stka energii - ³adowanie/roz³adowanie
			///
			void setParticleEnergy(float particle_energy);

			///
			///Metoda zwraca czas procesu zu¿ycia jednostki energii
			///
			const float getBatteryRegenerationDuration() const;

			///
			///Metoda ustawia czas procesu zu¿ycia jednostki energii
			///
			///@param battery_regeneration_duration - czas procesu zu¿ycia jednostki energii
			///
			void setBatteryRegenerationDuration(float battery_regeneration_duration);

			///
			///Metoda zwraca referencjcê na modu³ sterowania
			///
			CSwitch & getUnitController();

			///
			///Metoda zwraca wspó³czynnik stanu (poziomu) na³adowania baterii
			///
			const float getBatteryCharge() const;

			///
			///Metoda ustawia wspó³czynnik stanu (poziomu) na³adowania baterii
			///
			///@param battery_charge - wspó³czynnik stanu (poziomu) na³adowania baterii
			///
			void setBatteryCharge(const float battery_charge);

			///
			///Metoda zwraca wyliczenie stanów baterii
			///
			const EBatteryState & getBatteryState() const;

			///
			///Metoda ustawia wyliczenie stanów baterii
			///
			///@param & battery_state - sta³a referencja na wyliczenie EBatteryState
			///
			void setBatteryState(const EBatteryState & battery_state);

			///
			///Metoda uruchamia procesy i funkcjonalnoœæ baterii
			///
			void runBattery();

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		protected:

			std::string		m_battery_name;						//nazwa baterii (niklowa, kadmowa, litowa, atomowa...etc)
			float			m_capacity;							//pojemnoœæ baterii - przy ka¿dym pe³nym prze³adowaniu - spada o m_decline
			float			m_factory_capacity;					//fabryczna pojemnoœæ baterii (znamionowa)
			float			m_particle_energy;					//wartoœæ cz¹stki energii przekazywanej z baterii do odbiorcy (zbilansowanie stanu)
			float			m_battery_regeneration_duration;	//czas procesu zu¿ycia jednostki energii
			float			m_battery_regeneration_timer;		//lokalny zegar
			CSwitch			m_unit_controller;					//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka
			EBatteryState	m_battery_state;					//wyliczenie stanów dla obiektu CBattery

		private:

			float			m_battery_charge;					//obliczany wspó³czynnik stanu (poziomu) na³adowania baterii
			bool			run_battery;						//flaga uruchamia procesy i funkcjonalnoœæ baterii
			
			//prywatna metoda aktualizuje stan obiektu - bateria
			void updateBatteryState(float dt);
		};
	}//namespace battery
}//namespace equipment
#endif//H_BATTERY_JACK
