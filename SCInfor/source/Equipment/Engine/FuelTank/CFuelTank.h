//  ______________________________________
// | CFuelTank.h - class definition       |
// | Jack Flower - December 2012          |
// |______________________________________|
//

#ifndef H_FUEL_TANK_JACK
#define H_FUEL_TANK_JACK

#include "../../../RTTI/RTTI.h"
#include "../../../Logic/Actor/CActor.h"
#include "EFuelTankState.h"
#include "../../CSwitch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje zbiornik paliwa
	///
	class CFuelTank : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskaæ obiekt CFuelTank, nale¿y wywo³aæ CPhysicalManager::CreateFuelTank();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		CFuelTank(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param &CFuelTankCopy - obiekt klasy CFuelTank
		///
		CFuelTank(const CFuelTank& CFuelTankCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CFuelTank(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê zbiornika
		///
		const std::string GetFuelTankName() const;

		///
		///Metoda ustawia nazwê zbiornika
		///
		///@param &fuel_tank_name - sta³a referencja na obiekt klasy std::string
		///
		void SetFuelTankName(const std::string& fuel_tank_name);

		///
		///Metoda zwraca pojemnoœæ zbiornika
		///
		const float GetFuelTankCapacity() const;

		///
		///Metoda ustawia pojemnoœæ zbiornika
		///
		///@param fuel_tank_capacity - pojemnoœæ zbiornika
		///
		void SetFuelTankCapacity(float fuel_tank_capacity);

		///
		///Metoda zwraca iloœæ paliwa
		///
		const float GetFuel() const;

		///
		///Metoda ustawia iloœæ paliwa
		///
		///@param fuel - iloœæ paliwa
		///
		void SetFuel(float fuel);

		///
		///Metoda zwraca stan obiektu CFuelTank
		///
		inline EFuelTankState & getFuelTankState() { return m_fueltank_state; }

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

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

	private:

		std::string		m_fuel_tank_name;		//nazwa zbiornika paliwa
		float			m_fuel_tank_capacity;	//pojemnoœæ zbiornika paliwa (materia³ pêdny)
		float			m_fuel;					//iloœæ paliwa - (materia³u pêdnego)
		EFuelTankState	m_fueltank_state;		//wyliczenie stanów dla obiektu CFuelTank
		CSwitch			m_unit_controller;		//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka

	};
}//namespace equipment
#endif //H_FUEL_TANK_JACK