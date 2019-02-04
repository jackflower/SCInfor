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
		///Konstruktor kopiuj�cy
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
		///Metoda zwraca nazw� znacznika obiektu na mapie
		///
		const std::string & GetCode() const;

		///
		///Metoda ustawia nazw� znacznika obiektu na mapie
		///
		///@param & code - nazw� znacznika - sta�a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca wska�nik na wzorzec danych
		///
		CPhysicalTemplate* GetTemplate() const;

		///
		///Metoda ustawia wska�nik na wzorzec danych
		///
		///@param *template_param - wska�nik na wzorzec danych
		///
		void SetTemplate(CPhysicalTemplate* template_param);

	private:

		std::string			m_code;		//unikalna nazwa obiektu wzorca nadawana w pliku xml
		CPhysicalTemplate*	p_template;	//wska�nik na wzorzec danych
	};
} //namespace mapengine
#endif //H_MAP_OBJECT_TYPE_JACK
