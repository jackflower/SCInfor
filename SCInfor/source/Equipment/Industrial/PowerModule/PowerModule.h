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
	///Klasa bazowa dla modu³ów wytwarzania, gromadzenia i przetwarzania energii
	///
	class PowerModule : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt PowerModule, nale¿y wywo³aæ CPhysicalManager::CreatePowerModule();

		///
		///Chroniony konstruktor domyœlny
		///
		///@param uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		PowerModule(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param PowerModuleCopy - obiekt klasy PowerModule
		///
		PowerModule(const PowerModule & PowerModuleCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~PowerModule(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca iloœæ energii, któr¹ mo¿na zgromadziæ
		///
		const float getEnergyCapacitor() const;

		///
		///Metoda ustawia iloœæ energii, któr¹ mo¿na zgromadziæ
		///
		///@param energy_capacitor - iloœæ energii, któr¹ mo¿na zgromadziæ
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
		///Metoda zwraca iloœæ zgromadzonej energii
		///
		const float getStoredEnergy() const;

		///
		///Metoda ustawia iloœæ zgromadzonej energii
		///
		///@param stored_energy - iloœæ zgromadzonej energii
		///
		void setStoredEnergy(float stored_energy);

	protected:

		float m_energy_capacitor; //energia, która mo¿e zostaæ zgromadzona
		float m_power; //moc
		float m_stored_energy; //zgromadzona energia
		Switch m_unit_controller; //w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka

	private:
	};
}//namespace equipment
#endif//H_POWER_MODULE_JACK
