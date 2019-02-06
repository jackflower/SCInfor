//  ________________________________________
// | WindTurbine.h - class definition       |
// | Jack Flower - July 2014                |
// |________________________________________|
//


#ifndef H_WIND_TURBINE_JACK
#define H_WIND_TURBINE_JACK

#include "../PowerModule/PowerModule.h"
#include "ETurbineState.h"

namespace equipment
{
	///
	///Klasa reprezentuej funkcjonalnośc turbiny
	///
	class WindTurbine : public PowerModule
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskać obiekt WindTurbine, należy wywołać CPhysicalManager::CreateWindTurbine();

	protected:

		///
		///Chroniony konstruktor domyślny
		///
		///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
		///
		WindTurbine(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param WindTurbineCopy - obiekt klasy WindTurbine
		///
		WindTurbine(const WindTurbine & WindTurbineCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		///
		virtual ~WindTurbine(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę turbiny
		///
		const std::string getTurbineName() const;

		///
		///Metoda ustawia nazwę turbiny
		///
		///@param turbine_name - nazwa turbiny stała referencja na std::string
		///
		void setTurbineName(const std::string & turbine_name);

		///
		///Metoda zwraca prędkość wirowania turbiny
		///
		const float getSpeedRotor() const;

		///
		///Metoda ustawia prędkość wirowania turbiny
		///
		///@param speed_rotor - prędkość wirowania turbiny
		///
		void setSpeedRotor(float speed_rotor);

		///
		///Metoda zwraca przełożenie prędkości obrotowej
		///
		const float getSpeedTransmission() const;

		///
		///Metoda ustawia przełożenie prędkości obrotowej
		///
		///@param speed_transmission - przełożenie prędkości obrotowej
		///
		void setSpeedTransmission(float speed_transmission);

		///
		///Metoda zwraca procentowy współczynnik aktywacji turbiny
		///
		const float getPercentageActivation() const;

		///
		///Metoda ustawia procentowy współczynnik aktywacji turbiny
		///
		///@param percentage_activation - procentowy współczynnik aktywacji turbiny
		///
		void setPercentageActivation(float percentage_activation);

		///
		///Metoda zwraca czas trwania stanu, po zgromadzeniu pełnej energii
		///
		const float getEnergyFuelDuration() const;

		///
		///Metoda ustawia czas trwania stanu, po zgromadzeniu pełnej energii
		///
		///@param energy_full_duration - czas trwania stanu, po zgromadzeniu pełnej energii
		///
		void setEnergyFuelDuration(float energy_full_duration);

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

		std::string m_turbine_name; //nazwa turbiny
		float m_speed_rotor; //prędkość wirowania turbiny
		float m_speed_transmission; //przekładnia - przełożenie prędkości obrotowej
		float m_percentage_activation; //procentowy współczynnik aktywacji turbiny
		float m_energy_full_duration; //czas trwania stanu, po zgromadzeniu pełnej energii
		ETurbineState m_turbine_state; //wyliczenie stanów logicznych turbiny (maszyna stanów)

		float m_cargo_open_duration; //czas trwania otwierania luku cargo
		float m_cargo_close_duration; //czas trwania zamykania luku cargo
		float m_calculated_speed_rotor; //obliczana prędkość wirowania łopat turbiny
		float m_calculated_energy_full_duration; //obliczany czas trwania stanu, po zgromadzeniu pełnej energii

		//prywatna metoda aktualizuje stan obiektu
		void updateTurbineState(float dt);
	};
}//namespace equipment
#endif//H_WIND_TURBINE_JACK
