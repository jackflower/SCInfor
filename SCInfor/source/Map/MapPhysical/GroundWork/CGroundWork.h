//  ________________________________________
// | CGroundWork.h - class definition       |
// | Jack Flower - March 2015               |
// |________________________________________|
//

#ifndef H_GROUND_WORK_JACK
#define H_GROUND_WORK_JACK

#include "../CMapPhysical.h"
#include "../../Ground/PhysicsGround/CPhysicsGround.h"

using namespace mapengine::physicsground;

namespace mapengine
{
	namespace groundwork
	{
		///
		///Klasa reprezentuje rodzaj pod³o¿a (grunt), po którym przemieszczaj¹ siê obiekty
		///
		class CGroundWork : public CMapPhysical
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CMapPhysicalManager;

			//Aby uzyskaæ obiekt CGroundWork, nale¿y wywo³aæ CMapPhysicalManager::CreateGroundWork();

		protected:

			///
			///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CMapPhysicalManager
			///
			///@param & uniqueId - unikalny identyfikator (nadawany w CMapPhysicalManager)
			///
			CGroundWork(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param & CGroundWorkCopy - sta³a referencja na obiekt klasy CGroundWork
			///
			CGroundWork(const CGroundWork & CGroundWorkCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CMapPhysicalManager
			///
			~CGroundWork(void);

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
	}//namespace groundwork
}//namespace mapengine
#endif//H_GROUND_WORK_JACK
