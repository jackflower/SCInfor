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
	///Klasa reprezentuje akumulator energii /¿ycia/
	///
	class CEnergyTank : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskaæ obiekt CEnergyTank, nale¿y wywo³aæ CPhysicalManager::CreateCEnergyTank();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		CEnergyTank(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
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
		///Metoda zwraca nazwê akumulatora energii
		///
		const std::string GetEnergyTankName() const;

		///
		///Metoda ustawia nazwê akumulatora energii
		///
		///@param & energy_tank_name - sta³a referencja na obiekt klasy std::string
		///
		void SetEnergyTankName(const std::string& energy_tank_name);
		
		///
		///Metoda zwraca pojemnoœæ pojemnoœæ akumulatora energii
		///
		const float GetEnergyTankCapacity() const;

		///
		///Metoda ustawia pojemnoœæ akumulatora energii
		///
		///@param energy_tank_capacity - pojemnoœæ akumulatora energii
		///
		void SetEnergyTankCapacity(float energy_tank_capacity);

		///
		///Metoda zwraca iloœæ energii
		///
		const float GetEnergy() const;

		///
		///Metoda ustawia iloœæ energii
		///
		///@param energy - iloœæ energii
		///
		void SetEnergy(float energy);

		///
		///Metoda zwraca prêdkoœæ wirowania wskaŸnika stanu akumulatora
		///
		const float GetEnergyTankRotationSpeed() const;

		///
		///Metoda ustawia prêdkoœæ wirowania wskaŸnika stanu akumulatora
		///
		///@param energy_tank_rotation_speed - prêdkoœæ wirowania wskaŸnika stanu akumulatora
		///
		void SetEnergyTankRotationSpeed(float energy_tank_rotation_speed);

		///
		///Metoda zwraca stan obiektu CEnergyTank
		///
		inline EEnergyTankState & getEnergyTankState() { return m_energytank_state; }

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void UpdateAnimations(float dt);

		///
		///Metoda zwraca referencjcê na modu³ sterowania
		///
		CSwitch & getUnitController();

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);


	protected:

		std::string			m_energy_tank_name;				//nazwa akulatora energii
		float				m_energy_tank_capacity;			//pojemnoœæ akumulatora energii
		float				m_energy;						//energia /¿ycie/ obiektu
		float				m_energy_tank_rotation_speed;	//prêdkoœæ wirowania wskaŸnika stanu akumulatora
		float				m_energy_tank_rotor_speed;		//wyliczana prêdkoœæ wirowania wskaŸnika stanu akumulatora
		EEnergyTankState	m_energytank_state;				//wyliczenie stanów dla obiektu CEnergyTank
		CSwitch				m_unit_controller;				//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka
	};
}//namespace equipment
#endif // H_ENERGY_TANK_JACK
