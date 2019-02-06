//  ______________________________________
// | SolarCell.h - class definition       |
// | Jack Flower - July 2014              |
// |______________________________________|
//

#ifndef H_SOLAR_CELL_JACK
#define H_SOLAR_CELL_JACK

#include "../PowerModule/PowerModule.h"
#include "ESolarCellState.h"

namespace equipment
{
	///
	///Klasa reprezentuje fotoogniwo
	///
	class SolarCell : public PowerModule
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
		//Aby uzyska� obiekt SolarCell, nale�y wywo�a� CPhysicalManager::CreateSolarCell();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		SolarCell(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param SolarCellCopy - obiekt klasy SolarCell
		///
		SolarCell(const SolarCell & SolarCellCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~SolarCell(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazw� fotoogniwa
		///
		const std::string getSolarCellName() const;

		///
		///Metoda ustawia nazw� fotoogniwa
		///
		///@param solarcell_name - nazwa turbiny sta�a referencja na std::string
		///
		void setSolarCellName(const std::string & solarcell_name);

		///
		///Metoda zwraca czas, co jaki nast�puj� proces do��dowywania energii
		///
		const float getEnergyDuration() const;

		///
		///Metoda ustawia czas, co jaki nast�puj� proces do��dowywania energii
		///
		///@param energy_duration - czas, co jaki nast�puj� proces do��dowywania energii
		///
		void setEnergyDuration(float energy_duration);

		///
		///Metoda zwraca pr�dko�� obrotu
		///
		const float getRotationSpeed() const;

		///
		///Metoda ustawia pr�dko�� obrotu
		///
		///@param rotation_speed - pr�dko�� obrotu
		///
		void setRotationSpeed(float rotation_speed);

		///
		///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:
		
		std::string m_solarcell_name; //nazwa fotoogniwa
		float m_energy_duration; //czas, co jaki nast�puje proces �adowania fotoogniwa
		float m_rotation_speed; //pr�dko�� obrotu obiektu
		ESolarCellState m_solarcell_state; //wyliczenie stan�w logicznych fotoogniwa (maszyna stan�w)

		float m_damage_duration; //obliczany czas trwania stanu uszkodzenia
		float m_death_duration; //obliczany czas trwania stanu death (tylko serwis, wymiana)
		float m_calculated_energy_duration;	//obliczany czas, co jaki nast�puje proces �adowania fotoogniwa

		//prywatna metoda aktualizuje stan obiektu
		void updateSolarCellState(float dt);

		//prywatna metoda p�ynnie obracaj�ca fotoogniwo w kierunku �r�d�a energii
		void updateRotation(float dt);

	};
}//namespace equipment
#endif//H_SOLAR_CELL_JACK