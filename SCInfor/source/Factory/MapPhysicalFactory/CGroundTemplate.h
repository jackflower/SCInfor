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
		///Konstruktor kopiuj�cy
		///
		///@param - CGroundTemplateCopy - sta�a referencja na obiekt klasy CGroundTemplate
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
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
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
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *ground - wska�nik na obiekt klasy CGround
		///
		virtual void Fill(CGround *ground);

		///
		///Metoda zwraca wsp�czynnik tarcia
		///
		const float getTemplateFriction() const;

		///
		///Metoda ustawia wsp�czynnik tarcia
		///
		///@param friction - wsp�czynnik tarcia
		///
		void setTemplateFriction(float friction);

		///
		///Metoda zwraca wsp�czynnik wilgotno�ci
		///
		const float getTemplateHumidity() const;

		///
		///Metoda ustawia wsp�czynnik wilgotno�ci
		///
		///@param humidity - wsp�czynnik wilgotno�ci
		///
		void setTemplateHumidity(float humidity);

		///
		///Metoda zwraca wsp�czynnik przenikalno�ci cieplnej
		///
		const float getTemplateThermalTransmittance() const;

		///
		///Metoda ustawia wsp�czynnik przenikalno�ci cieplnej
		///
		///@param thermal_transmittance - wsp�czynnik przenikalno�ci cieplnej
		///
		void setTemplateThermalTransmittance(float thermal_transmittance);

	private:

		CPhysicsGround	m_template_physicsground;	//obiekt klasy opakowuj�cej fizyk� pod�o�a

	};
}//namespace factory
#endif//H_GROUND_TEMPLATE_JACK
