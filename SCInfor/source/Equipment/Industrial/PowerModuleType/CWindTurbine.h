//  _________________________________________
// | CWindTurbine.h - class definition       |
// | Jack Flower - July 2014                 |
// |_________________________________________|
//


#ifndef H_WIND_TURBINE_JACK
#define H_WIND_TURBINE_JACK

#include "../PowerModule/CPowerModule.h"
#include "ETurbineState.h"

namespace equipment
{
	///
	///Klasa reprezentuej funkcjonalnoœc turbiny
	///
	class CWindTurbine : public CPowerModule
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt CWindTurbine, nale¿y wywo³aæ CPhysicalManager::CreateWindTurbine();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		CWindTurbine(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CWindTurbineCopy - obiekt klasy CWindTurbine
		///
		CWindTurbine(const CWindTurbine &CWindTurbineCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CWindTurbine(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwê turbiny
		///
		const std::string GetTurbineName() const;

		///
		///Metoda ustawia nazwê turbiny
		///
		///@param &turbine_name - nazwa turbiny sta³a referencja na std::string
		///
		void SetTurbineName(const std::string& turbine_name);

		///
		///Metoda zwraca prêdkoœæ wirowania turbiny
		///
		const float getSpeedRotor() const;

		///
		///Metoda ustawia prêdkoœæ wirowania turbiny
		///
		///@param speed_rotor - prêdkoœæ wirowania turbiny
		///
		void setSpeedRotor(float speed_rotor);

		///
		///Metoda zwraca prze³o¿enie prêdkoœci obrotowej
		///
		const float getSpeedTransmission() const;

		///
		///Metoda ustawia prze³o¿enie prêdkoœci obrotowej
		///
		///@param speed_transmission - prze³o¿enie prêdkoœci obrotowej
		///
		void setSpeedTransmission(float speed_transmission);

		///
		///Metoda zwraca procentowy wspó³czynnik aktywacji turbiny
		///
		const float getPercentageActivation() const;

		///
		///Metoda ustawia procentowy wspó³czynnik aktywacji turbiny
		///
		///@param percentage_activation - procentowy wspó³czynnik aktywacji turbiny
		///
		void setPercentageActivation(float percentage_activation);

		///
		///Metoda zwraca czas trwania stanu, po zgromadzeniu pe³nej energii
		///
		const float getEnergyFuelDuration() const;

		///
		///Metoda ustawia czas trwania stanu, po zgromadzeniu pe³nej energii
		///
		///@param energy_full_duration - czas trwania stanu, po zgromadzeniu pe³nej energii
		///
		void setEnergyFuelDuration(float energy_full_duration);

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

		std::string		m_turbine_name;						//nazwa turbiny
		float			m_speed_rotor;						//prêdkoœæ wirowania turbiny
		float			m_speed_transmission;				//przek³adnia - prze³o¿enie prêdkoœci obrotowej
		float			m_percentage_activation;			//procentowy wspó³czynnik aktywacji turbiny
		float			m_energy_full_duration;				//czas trwania stanu, po zgromadzeniu pe³nej energii
		ETurbineState	m_turbine_state;					//wyliczenie stanów logicznych turbiny (maszyna stanów)

		float			m_cargo_open_duration;				//czas trwania otwierania luku cargo
		float			m_cargo_close_duration;				//czas trwania zamykania luku cargo
		float			m_calculated_speed_rotor;			//obliczana prêdkoœæ wirowania ³opat turbiny
		float			m_calculated_energy_full_duration;	//obliczany czas trwania stanu, po zgromadzeniu pe³nej energii

		//prywatna metoda aktualizuje stan obiektu
		void updateTurbineState(float dt);
	};
}//namespace equipment
#endif//H_WIND_TURBINE_JACK
