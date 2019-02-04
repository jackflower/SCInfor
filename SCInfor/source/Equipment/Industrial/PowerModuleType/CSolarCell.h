//  _______________________________________
// | CSolarCell.h - class definition       |
// | Jack Flower - July 2014               |
// |_______________________________________|
//

#ifndef H_SOLAR_CELL_JACK
#define H_SOLAR_CELL_JACK

#include "../PowerModule/CPowerModule.h"
#include "ESolarCellState.h"

namespace equipment
{
	///
	///Klasa reprezentuje fotoogniwo
	///
	class CSolarCell : public CPowerModule
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt CSolarCell, nale¿y wywo³aæ CPhysicalManager::CreateSolarCell();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		CSolarCell(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CSolarCellCopy - obiekt klasy CSolarCell
		///
		CSolarCell(const CSolarCell &CSolarCellCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CSolarCell(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê fotoogniwa
		///
		const std::string GetSolarCellName() const;

		///
		///Metoda ustawia nazwê fotoogniwa
		///
		///@param &solarcell_name - nazwa turbiny sta³a referencja na std::string
		///
		void SetSolarCellName(const std::string& solarcell_name);

		///
		///Metoda zwraca czas, co jaki nastêpujê proces do³¹dowywania energii
		///
		const float getEnergyDuration() const;

		///
		///Metoda ustawia czas, co jaki nastêpujê proces do³¹dowywania energii
		///
		///@param energy_duration - czas, co jaki nastêpujê proces do³¹dowywania energii
		///
		void setEnergyDuration(float energy_duration);

		///
		///Metoda zwraca prêdkoœæ obrotu
		///
		const float getRotationSpeed() const;

		///
		///Metoda ustawia prêdkoœæ obrotu
		///
		///@param rotation_speed - prêdkoœæ obrotu
		///
		void setRotationSpeed(float rotation_speed);

		///
		///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
		///
		///@param dt - czas
		///
		virtual void updateAnimations(float dt);

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:
		
		std::string			m_solarcell_name;				//nazwa fotoogniwa
		float				m_energy_duration;				//czas, co jaki nastêpuje proces ³adowania fotoogniwa
		float				m_rotation_speed;				//prêdkoœæ obrotu obiektu
		ESolarCellState		m_solarcell_state;				//wyliczenie stanów logicznych fotoogniwa (maszyna stanów)

		float				m_damage_duration;				//obliczany czas trwania stanu uszkodzenia
		float				m_death_duration;				//obliczany czas trwania stanu death (tylko serwis, wymiana)
		float				m_calculated_energy_duration;	//obliczany czas, co jaki nastêpuje proces ³adowania fotoogniwa

		//prywatna metoda aktualizuje stan obiektu
		void updateSolarCellState(float dt);

		//prywatna metoda p³ynnie obracaj¹ca fotoogniwo w kierunku Ÿród³a energii
		void updateRotation(float dt);

	};
}//namespace equipment
#endif//H_SOLAR_CELL_JACK
