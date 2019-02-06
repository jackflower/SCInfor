//  ________________________________________
// | PowerModule.h - class definition       |
// | Jack Flower - July 2014                |
// |________________________________________|
//

#ifndef H_POWER_MODULE_JACK
#define H_POWER_MODULE_JACK

#include "../../../Logic/Actor/CActor.h"
#include "../../Switch.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa bazowa dla modu��w wytwarzania, gromadzenia i przetwarzania energii
	///
	class PowerModule : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
		//Aby uzyska� obiekt PowerModule, nale�y wywo�a� CPhysicalManager::CreatePowerModule();

		///
		///Chroniony konstruktor domy�lny
		///
		///@param uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		PowerModule(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param PowerModuleCopy - obiekt klasy PowerModule
		///
		PowerModule(const PowerModule & PowerModuleCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~PowerModule(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca ilo�� energii, kt�r� mo�na zgromadzi�
		///
		const float getEnergyCapacitor() const;

		///
		///Metoda ustawia ilo�� energii, kt�r� mo�na zgromadzi�
		///
		///@param energy_capacitor - ilo�� energii, kt�r� mo�na zgromadzi�
		///
		void setEnergyCapacitor(float energy_capacitor);

		///
		///Metoda zwraca moc
		///
		const float getPower() const;

		///
		///Metoda ustawia moc
		///
		///@param power - moc
		///
		void setPower(float power);

		///
		///Metoda zwraca ilo�� zgromadzonej energii
		///
		const float getStoredEnergy() const;

		///
		///Metoda ustawia ilo�� zgromadzonej energii
		///
		///@param stored_energy - ilo�� zgromadzonej energii
		///
		void setStoredEnergy(float stored_energy);

	protected:

		float m_energy_capacitor; //energia, kt�ra mo�e zosta� zgromadzona
		float m_power; //moc
		float m_stored_energy; //zgromadzona energia
		Switch m_unit_controller; //w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka

	private:
	};
}//namespace equipment
#endif//H_POWER_MODULE_JACK
