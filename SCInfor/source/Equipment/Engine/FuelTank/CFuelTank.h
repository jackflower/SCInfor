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
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
			
		//Aby uzyska� obiekt CFuelTank, nale�y wywo�a� CPhysicalManager::CreateFuelTank();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		CFuelTank(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
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
		///Metoda zwraca nazw� zbiornika
		///
		const std::string GetFuelTankName() const;

		///
		///Metoda ustawia nazw� zbiornika
		///
		///@param &fuel_tank_name - sta�a referencja na obiekt klasy std::string
		///
		void SetFuelTankName(const std::string& fuel_tank_name);

		///
		///Metoda zwraca pojemno�� zbiornika
		///
		const float GetFuelTankCapacity() const;

		///
		///Metoda ustawia pojemno�� zbiornika
		///
		///@param fuel_tank_capacity - pojemno�� zbiornika
		///
		void SetFuelTankCapacity(float fuel_tank_capacity);

		///
		///Metoda zwraca ilo�� paliwa
		///
		const float GetFuel() const;

		///
		///Metoda ustawia ilo�� paliwa
		///
		///@param fuel - ilo�� paliwa
		///
		void SetFuel(float fuel);

		///
		///Metoda zwraca stan obiektu CFuelTank
		///
		inline EFuelTankState & getFuelTankState() { return m_fueltank_state; }

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu (move, attack, death, etc...)
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

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

	private:

		std::string		m_fuel_tank_name;		//nazwa zbiornika paliwa
		float			m_fuel_tank_capacity;	//pojemno�� zbiornika paliwa (materia� p�dny)
		float			m_fuel;					//ilo�� paliwa - (materia�u p�dnego)
		EFuelTankState	m_fueltank_state;		//wyliczenie stan�w dla obiektu CFuelTank
		CSwitch			m_unit_controller;		//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka

	};
}//namespace equipment
#endif //H_FUEL_TANK_JACK