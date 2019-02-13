//  ____________________________________________
// | MapPhysicalType.h - class definition       |
// | Jack Flower - March 2015                   |
// |____________________________________________|
//

#ifndef H_MAP_PHYSICAL_TYPE_JACK
#define H_MAP_PHYSICAL_TYPE_JACK

#include <string>
#include "../../RTTI/RTTI.h"
#include "../../Factory/MapPhysicalFactory/MapPhysicalTemplate.h"

namespace mapengine
{
	///
	///Klasa reprezentuje typ wzorca dla obiektu podłoża umieszczonego na mapie
	///
	class MapPhysicalType
	{
		RTTI_DECL;
		
	public:

		///
		///Konstruktor
		///
		MapPhysicalType();

		///
		///Konstruktor kopiujący
		///
		///@param MapPhysicalTypeCopy - stała referencja na obiekt klasy MapPhysicalType
		///
		MapPhysicalType(const MapPhysicalType & MapPhysicalTypeCopy);

		///
		///Destruktor
		///
		~MapPhysicalType();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		//metody pomocnicze
		
		///
		///Metoda zwraca unikalną nazwę obiektu wzorca nadawaną w pliku xml
		///
		const std::string & getCode() const;

		///
		///Metoda nadaje unikalną nazwę obiektu wzorca nadawaną w pliku xml
		///
		///@param code - nazwa - stała referencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca wskaźnik na wzorzec fabryczny - obiekt klasy MapPhysicalTemplate
		///
		MapPhysicalTemplate * getTemplate();
		
		///
		///Metoda ustawia wskaźnik na wzorzec fabryczny - obiekt klasy MapPhysicalTemplate
		///
		///@param *template_param - wskaźnik na obiekt klasy MapPhysicalTemplate
		///
		void setTemplate(MapPhysicalTemplate *template_param);

	private:

		std::string m_code; //unikalna nazwa obiektu wzorca nadawana w pliku xml
		MapPhysicalTemplate *p_template; //wskaźnik na wzorzec danych

	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_TYPE_JACK
