//  ___________________________________
// | Ground.h - class definition       |
// | Jack Flower - February 2016       |
// |___________________________________|
//

#ifndef H_GROUND_JACK
#define H_GROUND_JACK

#include "PhysicsGround/PhysicsGround.h"
#include "../../Logic/PhysicalManager.h"
#include "../../Logic/Actor/Actor.h"

using namespace logic;
using namespace mapengine::physicsground;

namespace mapengine
{
	///Klasa reprezentuje rodzaj podłoża (grunt), po którym przemieszczają się obiekty
	///
	class Ground : public Actor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;

		//Aby uzyskać obiekt Ground, należy wywołać PhysicalManager::CreateGround();

	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
		///
		///@param uniqueId - unikalny identyfikator (nadawany w PhysicalManager)
		///
		Ground(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param GroundCopy - stała referencja na obiekt klasy Ground
		///
		Ground(const Ground & GroundCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez MapPhysicalManager
		///
		virtual ~Ground(void);

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca współczynnik tarcia
		///
		const float getFriction() const;

		///
		///Metoda ustawia współczynnik tarcia
		///
		///@param friction - współczynnik tarcia
		///
		void setFriction(float friction);

		///
		///Metoda zwraca współczynnik wilgotności
		///
		const float getHumidity() const;

		///
		///Metoda ustawia współczynnik wilgotności
		///
		///@param humidity - współczynnik wilgotności
		///
		void setHumidity(float humidity);

		///
		///Metoda zwraca współczynnik przenikalności cieplnej
		///
		const float getThermalTransmittance() const;

		///
		///Metoda ustawia współczynnik przenikalności cieplnej
		///
		///@param thermal_transmittance - współczynnik przenikalności cieplnej
		///
		void setThermalTransmittance(float thermal_transmittance);

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	private:

		PhysicsGround m_physicsground; //wskaźnik na klasę opakowującą fizykę podłoża
		
	};
}//namespace mapengine
#endif//H_GROUND_JACK
