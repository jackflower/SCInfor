//  __________________________________________
// | MapObjectType.h - class definition       |
// | Jack Flower April 2013                   |
// |__________________________________________|
//

#ifndef H_MAP_OBJECT_TYPE_JACK
#define H_MAP_OBJECT_TYPE_JACK

#include <string>
#include "../../Factory/PhysicalTemplate.h"
#include "../../RTTI/RTTI.h"

namespace mapengine
{
	///
	///Klasa reprezentuje typ wzorca obiektu umieszczonego na mapie
	///
	class MapObjectType
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		MapObjectType();

		///
		///Konstruktor kopiujący
		///
		///@param MapObjectTypeCopy - obiekt klasy MapObjectType
		///
		MapObjectType(const MapObjectType & MapObjectTypeCopy);

		///
		///Destruktor
		///
		~MapObjectType();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca nazwę znacznika obiektu na mapie
		///
		const std::string & getCode() const;

		///
		///Metoda ustawia nazwę znacznika obiektu na mapie
		///
		///@param code - nazwę znacznika - stała referencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca wskaźnik na wzorzec danych
		///
		PhysicalTemplate *getTemplate() const;

		///
		///Metoda ustawia wskaźnik na wzorzec danych
		///
		///@param *template_param - wskaźnik na wzorzec danych
		///
		void setTemplate(PhysicalTemplate *template_param);

	private:

		std::string m_code; //unikalna nazwa obiektu wzorca nadawana w pliku xml
		PhysicalTemplate *p_template; //wskaźnik na wzorzec danych
	};
} //namespace mapengine
#endif //H_MAP_OBJECT_TYPE_JACK
