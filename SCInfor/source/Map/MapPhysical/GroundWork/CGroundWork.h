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
		///Klasa reprezentuje rodzaj pod�o�a (grunt), po kt�rym przemieszczaj� si� obiekty
		///
		class CGroundWork : public CMapPhysical
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CMapPhysicalManager;

			//Aby uzyska� obiekt CGroundWork, nale�y wywo�a� CMapPhysicalManager::CreateGroundWork();

		protected:

			///
			///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CMapPhysicalManager
			///
			///@param & uniqueId - unikalny identyfikator (nadawany w CMapPhysicalManager)
			///
			CGroundWork(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param & CGroundWorkCopy - sta�a referencja na obiekt klasy CGroundWork
			///
			CGroundWork(const CGroundWork & CGroundWorkCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CMapPhysicalManager
			///
			~CGroundWork(void);

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
	}//namespace groundwork
}//namespace mapengine
#endif//H_GROUND_WORK_JACK
