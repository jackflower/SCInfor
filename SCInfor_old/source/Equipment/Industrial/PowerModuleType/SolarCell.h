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
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;
		
		//Aby uzyskać obiekt SolarCell, należy wywołać PhysicalManager::CreateSolarCell();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		SolarCell(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param SolarCellCopy - obiekt klasy SolarCell
		///
		SolarCell(const SolarCell & SolarCellCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		///
		virtual ~SolarCell(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę fotoogniwa
		///
		const std::string getSolarCellName() const;

		///
		///Metoda ustawia nazwę fotoogniwa
		///
		///@param solarcell_name - nazwa turbiny stała referencja na std::string
		///
		void setSolarCellName(const std::string & solarcell_name);

		///
		///Metoda zwraca czas, co jaki następuję proces dołądowywania energii
		///
		const float getEnergyDuration() const;

		///
		///Metoda ustawia czas, co jaki następuję proces dołądowywania energii
		///
		///@param energy_duration - czas, co jaki następuję proces dołądowywania energii
		///
		void setEnergyDuration(float energy_duration);

		///
		///Metoda zwraca prędkość obrotu
		///
		const float getRotationSpeed() const;

		///
		///Metoda ustawia prędkość obrotu
		///
		///@param rotation_speed - prędkość obrotu
		///
		void setRotationSpeed(float rotation_speed);

		///
		///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:
		
		std::string m_solarcell_name; //nazwa fotoogniwa
		float m_energy_duration; //czas, co jaki następuje proces ładowania fotoogniwa
		float m_rotation_speed; //prędkość obrotu obiektu
		ESolarCellState m_solarcell_state; //wyliczenie stanów logicznych fotoogniwa (maszyna stanów)

		float m_damage_duration; //obliczany czas trwania stanu uszkodzenia
		float m_death_duration; //obliczany czas trwania stanu death (tylko serwis, wymiana)
		float m_calculated_energy_duration;	//obliczany czas, co jaki następuje proces ładowania fotoogniwa

		//prywatna metoda aktualizuje stan obiektu
		void updateSolarCellState(float dt);

		//prywatna metoda płynnie obracająca fotoogniwo w kierunku źródła energii
		void updateRotation(float dt);

	};
}//namespace equipment
#endif//H_SOLAR_CELL_JACK
