//  _________________________________________
// | CThermometer.h - class definition       |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#ifndef H_THERMOMETER_JACK
#define H_THERMOMETER_JACK

#include "../../RTTI/RTTI.h"
#include "../../Logic/Physical/CPhysical.h"
#include "EDisplayType.h"

using namespace logic;

namespace equipment
{
	///
	///Klasa reprezentuje termometr - urz¹dzenie pomiarowe
	///
	class CThermometer : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
			
		//Aby uzyskaæ obiekt CThermometer, nale¿y wywo³aæ CPhysicalManager::CreateThermometer();

	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
		///
		CThermometer(const std::wstring& uniqueId);
	
		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param &CThermometerCopy - obiekt klasy CThermometer
		///
		CThermometer(const CThermometer& CThermometerCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CThermometer();

	public:

		///
		///Metoda zwraca temperaturê
		///
		const float getTemperature() const;

		///
		///Metoda ustawia temperaturê
		///
		///@param temperature - temperatura
		///
		const void setTemperature(float temperature);

		///
		///Wirtualna metoda aktualizuje logikê obiektu
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:
		
		typedef struct {float min; float max;} Range;//definicja typu
		
		Range			m_range;		//zakres pomiaru temperatury
		float			m_temperature;	//temperatura pomiaru
		EDisplayType	e_display_type;	//typ prezentacji temperatury
	};
}
#endif//H_THERMOMETER_JACK
