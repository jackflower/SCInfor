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
	//Klasa reprezentuje wzorzec do tworzenia obiektów klasy CGroundWorkTemplate
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
		///Konstruktor kopiuj¹cy
		///
		///@param - CGroundWorkTemplateCopy - sta³a referencja na obiekt klasy CGroundWorkTemplate
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
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
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
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *groundwork - wskaŸnik na obiekt klasy CGroundWork
		///
		virtual void fill(CGroundWork *groundwork);

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
	
private:
		
		CPhysicsGround	m_template_physicsground;	//obiekt klasy opakowuj¹cej fizykê pod³o¿a

	};
}//namespace factory
#endif//H_GROUND_WORK_TEMPLATE_JACK
