//  ____________________________________________
// | CGroundTemplate.h - class definition       |
// | Jack Flower - March 2015                   |
// |____________________________________________|
//

#ifndef H_GROUND_TEMPLATE_JACK
#define H_GROUND_TEMPLATE_JACK

#include "../../Map/Ground/CGround.h"
#include "../../Factory/CActorTemplate.h"

namespace factory
{
	///
	//Klasa reprezentuje wzorzec klasy CGround
	///
	class CGroundTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CGroundTemplate();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param - CGroundTemplateCopy - sta³a referencja na obiekt klasy CGroundTemplate
		///
		CGroundTemplate(const CGroundTemplate & CGroundTemplateCopy);
		
		///
		///Destruktor wirtualny
		///
		virtual ~CGroundTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CGroundWork
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CGround* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *ground - wskaŸnik na obiekt klasy CGround
		///
		virtual void Fill(CGround *ground);

		///
		///Metoda zwraca wspó³czynnik tarcia
		///
		const float getTemplateFriction() const;

		///
		///Metoda ustawia wspó³czynnik tarcia
		///
		///@param friction - wspó³czynnik tarcia
		///
		void setTemplateFriction(float friction);

		///
		///Metoda zwraca wspó³czynnik wilgotnoœci
		///
		const float getTemplateHumidity() const;

		///
		///Metoda ustawia wspó³czynnik wilgotnoœci
		///
		///@param humidity - wspó³czynnik wilgotnoœci
		///
		void setTemplateHumidity(float humidity);

		///
		///Metoda zwraca wspó³czynnik przenikalnoœci cieplnej
		///
		const float getTemplateThermalTransmittance() const;

		///
		///Metoda ustawia wspó³czynnik przenikalnoœci cieplnej
		///
		///@param thermal_transmittance - wspó³czynnik przenikalnoœci cieplnej
		///
		void setTemplateThermalTransmittance(float thermal_transmittance);

	private:

		CPhysicsGround	m_template_physicsground;	//obiekt klasy opakowuj¹cej fizykê pod³o¿a

	};
}//namespace factory
#endif//H_GROUND_TEMPLATE_JACK
