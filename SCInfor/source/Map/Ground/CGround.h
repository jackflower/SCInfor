//  ____________________________________
// | CGround.h - class definition       |
// | Jack Flower - February 2016        |
// |____________________________________|
//

#ifndef H_GROUND_JACK
#define H_GROUND_JACK

#include "../../Logic/CPhysicalManager.h"
#include "../../Logic/Actor/CActor.h"
#include "PhysicsGround/CPhysicsGround.h"

using namespace logic;
using namespace mapengine::physicsground;

namespace mapengine
{
	///Klasa reprezentuje rodzaj pod�o�a (grunt), po kt�rym przemieszczaj� si� obiekty
	///
	class CGround : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;

		//Aby uzyska� obiekt CGround, nale�y wywo�a� CPhysicalManager::CreateGround();

	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CPhysicalManager)
		///
		CGround(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param & CGroundCopy - sta�a referencja na obiekt klasy CGround
		///
		CGround(const CGround & CGroundCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CMapPhysicalManager
		///
		virtual ~CGround(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wsp�czynnik tarcia
		///
		const float getFriction() const;

		///
		///Metoda ustawia wsp�czynnik tarcia
		///
		///@param friction - wsp�czynnik tarcia
		///
		void setFriction(float friction);

		///
		///Metoda zwraca wsp�czynnik wilgotno�ci
		///
		const float getHumidity() const;

		///
		///Metoda ustawia wsp�czynnik wilgotno�ci
		///
		///@param humidity - wsp�czynnik wilgotno�ci
		///
		void setHumidity(float humidity);

		///
		///Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
		///
		const float getThermalTransmittance() const;

		///
		///Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
		///
		///@param thermal_transmittance - wsp�czynnik przenikalno�ci cieplnej
		///
		void setThermalTransmittance(float thermal_transmittance);

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	private:

		CPhysicsGround	m_physicsground;	//wska�nik na klas� opakowuj�c� fizyk� pod�o�a
		
	};
}//namespace mapengine
#endif//H_GROUND_JACK
