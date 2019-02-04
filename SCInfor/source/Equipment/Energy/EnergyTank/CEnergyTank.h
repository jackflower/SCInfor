//  ________________________________________
// | CEnergyTank.h - class definition       |
// | Jack Flower - December 2012            |
// |________________________________________|
//

#ifndef H_ENERGY_TANK_JACK
#define H_ENERGY_TANK_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Actor/CActor.h"
#include "EEnergyTankState.h"
#include "../../CSwitch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje akumulator energii /�ycia/
	///
	class CEnergyTank : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
			
		//Aby uzyska� obiekt CEnergyTank, nale�y wywo�a� CPhysicalManager::CreateCEnergyTank();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		CEnergyTank(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param &CEnergyTankCopy - obiekt klasy CEnergyTank
		///
		CEnergyTank(const CEnergyTank& CEnergyTankCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CEnergyTank(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazw� akumulatora energii
		///
		const std::string GetEnergyTankName() const;

		///
		///Metoda ustawia nazw� akumulatora energii
		///
		///@param & energy_tank_name - sta�a referencja na obiekt klasy std::string
		///
		void SetEnergyTankName(const std::string& energy_tank_name);
		
		///
		///Metoda zwraca pojemno�� pojemno�� akumulatora energii
		///
		const float GetEnergyTankCapacity() const;

		///
		///Metoda ustawia pojemno�� akumulatora energii
		///
		///@param energy_tank_capacity - pojemno�� akumulatora energii
		///
		void SetEnergyTankCapacity(float energy_tank_capacity);

		///
		///Metoda zwraca ilo�� energii
		///
		const float GetEnergy() const;

		///
		///Metoda ustawia ilo�� energii
		///
		///@param energy - ilo�� energii
		///
		void SetEnergy(float energy);

		///
		///Metoda zwraca pr�dko�� wirowania wska�nika stanu akumulatora
		///
		const float GetEnergyTankRotationSpeed() const;

		///
		///Metoda ustawia pr�dko�� wirowania wska�nika stanu akumulatora
		///
		///@param energy_tank_rotation_speed - pr�dko�� wirowania wska�nika stanu akumulatora
		///
		void SetEnergyTankRotationSpeed(float energy_tank_rotation_speed);

		///
		///Metoda zwraca stan obiektu CEnergyTank
		///
		inline EEnergyTankState & getEnergyTankState() { return m_energytank_state; }

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void UpdateAnimations(float dt);

		///
		///Metoda zwraca referencjc� na modu� sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);


	protected:

		std::string			m_energy_tank_name;				//nazwa akulatora energii
		float				m_energy_tank_capacity;			//pojemno�� akumulatora energii
		float				m_energy;						//energia /�ycie/ obiektu
		float				m_energy_tank_rotation_speed;	//pr�dko�� wirowania wska�nika stanu akumulatora
		float				m_energy_tank_rotor_speed;		//wyliczana pr�dko�� wirowania wska�nika stanu akumulatora
		EEnergyTankState	m_energytank_state;				//wyliczenie stan�w dla obiektu CEnergyTank
		CSwitch				m_unit_controller;				//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
	};
}//namespace equipment
#endif // H_ENERGY_TANK_JACK
