//  ___________________________________________
// | CMapObjectType.h - class definition       |
// | Jack Flower April 2013                    |
// |___________________________________________|
//

#ifndef H_MAP_OBJECT_TYPE_JACK
#define H_MAP_OBJECT_TYPE_JACK

#include <string>
#include "../../Factory/CPhysicalTemplate.h"
#include "../../RTTI/RTTI.h"

namespace mapengine
{
	///
	///Klasa reprezentuje typ wzorca obiektu umieszczonego na mapie
	///
	class CMapObjectType
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CMapObjectType();

		///
		///Konstruktor kopiujπcy
		///
		///@param &CMapObjectTypeCopy - obiekt klasy CMapObjectType
		///
		CMapObjectType(const CMapObjectType& CMapObjectTypeCopy);

		///
		///Destruktor
		///
		~CMapObjectType();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca nazwÍ znacznika obiektu na mapie
		///
		const std::string & GetCode() const;

		///
		///Metoda ustawia nazwÍ znacznika obiektu na mapie
		///
		///@param & code - nazwÍ znacznika - sta≥a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca wskaünik na wzorzec danych
		///
		CPhysicalTemplate* GetTemplate() const;

		///
		///Metoda ustawia wskaünik na wzorzec danych
		///
		///@param *template_param - wskaünik na wzorzec danych
		///
		void SetTemplate(CPhysicalTemplate* template_param);

	private:

		std::string			m_code;		//unikalna nazwa obiektu wzorca nadawana w pliku xml
		CPhysicalTemplate*	p_template;	//wskaünik na wzorzec danych
	};
} //namespace mapengine
#endif //H_MAP_OBJECT_TYPE_JACK
