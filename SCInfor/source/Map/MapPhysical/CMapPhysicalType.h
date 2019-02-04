//  _____________________________________________
// | CMapPhysicalType.h - class definition       |
// | Jack Flower - March 2015                    |
// |_____________________________________________|
//

#ifndef H_MAP_PHYSICAL_TYPE_JACK
#define H_MAP_PHYSICAL_TYPE_JACK

#include <string>
#include "../../RTTI/RTTI.h"
#include "../../Factory/MapPhysicalFactory/CMapPhysicalTemplate.h"

namespace mapengine
{
	///
	///Klasa reprezentuje typ wzorca dla obiektu pod�o�a umieszczonego na mapie
	///
	class CMapPhysicalType
	{
		RTTI_DECL;
		
	public:

		///
		///Konstruktor
		///
		CMapPhysicalType();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CMapPhysicalTypeCopy - sta�a referencja na obiekt klasy CMapPhysicalType
		///
		CMapPhysicalType(const CMapPhysicalType & CMapPhysicalTypeCopy);

		///
		///Destruktor
		///
		~CMapPhysicalType();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		//metody pomocnicze
		
		///
		///Metoda zwraca unikaln� nazw� obiektu wzorca nadawan� w pliku xml
		///
		const std::string & GetCode() const;

		///
		///Metoda nadaje unikaln� nazw� obiektu wzorca nadawan� w pliku xml
		///
		///@param & code - nazwa - sta�a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca wska�nik na wzorzec fabryczny - obiekt klasy CMapPhysicalTemplate
		///
		CMapPhysicalTemplate* GetTemplate();
		
		///
		///Metoda ustawia wska�nik na wzorzec fabryczny - obiekt klasy CMapPhysicalTemplate
		///
		///@param *template_param - wska�nik na obiekt klasy CMapPhysicalTemplate
		///
		void SetTemplate(CMapPhysicalTemplate* template_param);

	private:

		std::string				m_code;		//unikalna nazwa obiektu wzorca nadawana w pliku xml
		CMapPhysicalTemplate*	p_template;	//wska�nik na wzorzec danych

	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_TYPE_JACK
