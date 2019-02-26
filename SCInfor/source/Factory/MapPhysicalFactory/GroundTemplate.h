//  ___________________________________________
// | GroundTemplate.h - class definition       |
// | Jack Flower - March 2015                  |
// |___________________________________________|
//

#ifndef H_GROUND_TEMPLATE_JACK
#define H_GROUND_TEMPLATE_JACK

#include "../../Map/Ground/Ground.h"
#include "../../Factory/ActorTemplate.h"

namespace factory
{
	///
	//Klasa reprezentuje wzorzec klasy Ground
	///
	class GroundTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		GroundTemplate();

		///
		///Konstruktor kopiujący
		///
		///@param - GroundTemplateCopy - stała referencja na obiekt klasy GroundTemplate
		///
		GroundTemplate(const GroundTemplate & GroundTemplateCopy);
		
		///
		///Destruktor wirtualny
		///
		virtual ~GroundTemplate();

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
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		virtual bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy GroundWork
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Ground *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *ground - wskaźnik na obiekt klasy Ground
		///
		virtual void fill(Ground *ground);

		///
		///Metoda zwraca współczynnik tarcia
		///
		const float getTemplateFriction() const;

		///
		///Metoda ustawia współczynnik tarcia
		///
		///@param friction - współczynnik tarcia
		///
		void setTemplateFriction(float friction);

		///
		///Metoda zwraca współczynnik wilgotności
		///
		const float getTemplateHumidity() const;

		///
		///Metoda ustawia współczynnik wilgotności
		///
		///@param humidity - współczynnik wilgotności
		///
		void setTemplateHumidity(float humidity);

		///
		///Metoda zwraca współczynnik przenikalności cieplnej
		///
		const float getTemplateThermalTransmittance() const;

		///
		///Metoda ustawia współczynnik przenikalności cieplnej
		///
		///@param thermal_transmittance - współczynnik przenikalności cieplnej
		///
		void setTemplateThermalTransmittance(float thermal_transmittance);

	private:

		PhysicsGround m_template_physicsground; //obiekt klasy opakowującej fizykę podłoża

	};
}//namespace factory
#endif//H_GROUND_TEMPLATE_JACK
