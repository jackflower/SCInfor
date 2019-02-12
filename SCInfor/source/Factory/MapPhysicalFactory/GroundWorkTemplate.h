//  _______________________________________________
// | GroundWorkTemplate.h - class definition       |
// | Jack Flower - March 2015                      |
// |_______________________________________________|
//

#ifndef H_GROUND_WORK_TEMPLATE_JACK
#define H_GROUND_WORK_TEMPLATE_JACK

#include "MapPhysicalTemplate.h"
#include "../../Map/MapPhysical/GroundWork/GroundWork.h"

using namespace mapengine::groundwork;

namespace factory
{
	///
	//Klasa reprezentuje wzorzec do tworzenia obiektów klasy GroundWorkTemplate
	///
	class GroundWorkTemplate : public MapPhysicalTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		GroundWorkTemplate();

		///
		///Konstruktor kopiujący
		///
		///@param - GroundWorkTemplateCopy - stała referencja na obiekt klasy GroundWorkTemplate
		///
		GroundWorkTemplate(const GroundWorkTemplate & GroundWorkTemplateCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~GroundWorkTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

		///
		///Metoda ładująca dane
		///
		///@param &name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml & xml);

	protected:

		///
		///Metoda tworzy obiekt klasy GroundWork
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		GroundWork *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *groundwork - wskaźnik na obiekt klasy GroundWork
		///
		virtual void fill(GroundWork *groundwork);

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
	
private:
		
		PhysicsGround m_template_physicsground; //obiekt klasy opakowującej fizykę podłoża

	};
}//namespace factory
#endif//H_GROUND_WORK_TEMPLATE_JACK
