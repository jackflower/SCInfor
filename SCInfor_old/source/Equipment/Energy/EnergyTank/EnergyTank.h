//  _______________________________________
// | EnergyTank.h - class definition       |
// | Jack Flower - December 2012           |
// |_______________________________________|
//

#ifndef H_ENERGY_TANK_JACK
#define H_ENERGY_TANK_JACK

#include "EEnergyTankState.h"
#include "../../Switch.h"
#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Actor/Actor.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje akumulator energii /życia/
	///
	class EnergyTank : public Actor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;
			
		//Aby uzyskać obiekt EnergyTank, należy wywołać PhysicalManager::CreateCEnergyTank();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		EnergyTank(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param EnergyTankCopy - obiekt klasy EnergyTank
		///
		EnergyTank(const EnergyTank & EnergyTankCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~EnergyTank(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę akumulatora energii
		///
		const std::string getEnergyTankName() const;

		///
		///Metoda ustawia nazwę akumulatora energii
		///
		///@param energy_tank_name - stała referencja na obiekt klasy std::string
		///
		void setEnergyTankName(const std::string& energy_tank_name);
		
		///
		///Metoda zwraca pojemność pojemność akumulatora energii
		///
		const float getEnergyTankCapacity() const;

		///
		///Metoda ustawia pojemność akumulatora energii
		///
		///@param energy_tank_capacity - pojemność akumulatora energii
		///
		void setEnergyTankCapacity(float energy_tank_capacity);

		///
		///Metoda zwraca ilość energii
		///
		const float getEnergy() const;

		///
		///Metoda ustawia ilość energii
		///
		///@param energy - ilość energii
		///
		void setEnergy(float energy);

		///
		///Metoda zwraca prędkość wirowania wskaźnika stanu akumulatora
		///
		const float getEnergyTankRotationSpeed() const;

		///
		///Metoda ustawia prędkość wirowania wskaźnika stanu akumulatora
		///
		///@param energy_tank_rotation_speed - prędkość wirowania wskaźnika stanu akumulatora
		///
		void setEnergyTankRotationSpeed(float energy_tank_rotation_speed);

		///
		///Metoda zwraca stan obiektu EnergyTank
		///
		inline EEnergyTankState & getEnergyTankState() { return m_energytank_state; }

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Metoda zwraca referencjcę na moduł sterowania
		///
		Switch & getUnitController();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);


	protected:

		std::string m_energy_tank_name; //nazwa akulatora energii
		float m_energy_tank_capacity; //pojemność akumulatora energii
		float m_energy; //energia /życie/ obiektu
		float m_energy_tank_rotation_speed;	//prędkość wirowania wskaźnika stanu akumulatora
		float m_energy_tank_rotor_speed; //wyliczana prędkość wirowania wskaźnika stanu akumulatora
		EEnergyTankState m_energytank_state; //wyliczenie stanów dla obiektu EnergyTank
		Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
	};
}//namespace equipment
#endif // H_ENERGY_TANK_JACK
