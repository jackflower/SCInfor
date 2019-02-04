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
	///Klasa reprezentuje termometr - urz�dzenie pomiarowe
	///
	class CThermometer : public CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
			
		//Aby uzyska� obiekt CThermometer, nale�y wywo�a� CPhysicalManager::CreateThermometer();

	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		///@param &uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
		///
		CThermometer(const std::wstring& uniqueId);
	
		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param &CThermometerCopy - obiekt klasy CThermometer
		///
		CThermometer(const CThermometer& CThermometerCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CThermometer();

	public:

		///
		///Metoda zwraca temperatur�
		///
		const float getTemperature() const;

		///
		///Metoda ustawia temperatur�
		///
		///@param temperature - temperatura
		///
		const void setTemperature(float temperature);

		///
		///Wirtualna metoda aktualizuje logik� obiektu
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
