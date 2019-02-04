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
	///Klasa reprezentuje rodzaj pod³o¿a (grunt), po którym przemieszczaj¹ siê obiekty
	///
	class CGround : public CActor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;

		//Aby uzyskaæ obiekt CGround, nale¿y wywo³aæ CPhysicalManager::CreateGround();

	protected:

		///
		///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CPhysicalManager)
		///
		CGround(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param & CGroundCopy - sta³a referencja na obiekt klasy CGround
		///
		CGround(const CGround & CGroundCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CMapPhysicalManager
		///
		virtual ~CGround(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca wspó³czynnik tarcia
		///
		const float getFriction() const;

		///
		///Metoda ustawia wspó³czynnik tarcia
		///
		///@param friction - wspó³czynnik tarcia
		///
		void setFriction(float friction);

		///
		///Metoda zwraca wspó³czynnik wilgotnoœci
		///
		const float getHumidity() const;

		///
		///Metoda ustawia wspó³czynnik wilgotnoœci
		///
		///@param humidity - wspó³czynnik wilgotnoœci
		///
		void setHumidity(float humidity);

		///
		///Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
		///
		const float getThermalTransmittance() const;

		///
		///Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
		///
		///@param thermal_transmittance - wspó³czynnik przenikalnoœci cieplnej
		///
		void setThermalTransmittance(float thermal_transmittance);

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

	private:

		CPhysicsGround	m_physicsground;	//wskaŸnik na klasê opakowuj¹c¹ fizykê pod³o¿a
		
	};
}//namespace mapengine
#endif//H_GROUND_JACK
