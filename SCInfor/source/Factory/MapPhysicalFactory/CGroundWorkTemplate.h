//  ________________________________________________
// | CGroundWorkTemplate.h - class definition       |
// | Jack Flower - March 2015                       |
// |________________________________________________|
//

#ifndef H_GROUND_WORK_TEMPLATE_JACK
#define H_GROUND_WORK_TEMPLATE_JACK

#include "CMapPhysicalTemplate.h"
#include "../../Map/MapPhysical/GroundWork/CGroundWork.h"

using namespace mapengine::groundwork;

namespace factory
{
	///
	//Klasa reprezentuje wzorzec do tworzenia obiekt�w klasy CGroundWorkTemplate
	///
	class CGroundWorkTemplate : public CMapPhysicalTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CGroundWorkTemplate();

		///
		///Konstruktor kopiuj�cy
		///
		///@param - CGroundWorkTemplateCopy - sta�a referencja na obiekt klasy CGroundWorkTemplate
		///
		CGroundWorkTemplate(const CGroundWorkTemplate & CGroundWorkTemplateCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CGroundWorkTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml &xml);

	protected:

		///
		///Metoda tworzy obiekt klasy CGroundWork
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CGroundWork* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *groundwork - wska�nik na obiekt klasy CGroundWork
		///
		virtual void fill(CGroundWork *groundwork);

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
	
private:
		
		CPhysicsGround	m_template_physicsground;	//obiekt klasy opakowuj�cej fizyk� pod�o�a

	};
}//namespace factory
#endif//H_GROUND_WORK_TEMPLATE_JACK
