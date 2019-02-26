//  __________________________________________
// | FloraTemplate.h - class definition       |
// | SCI - March 2014                         |
// |__________________________________________|
//

#ifndef H_FLORA_TEMPLATE_JACK
#define H_FLORA_TEMPLATE_JACK

#include "ActorTemplate.h"
#include "../Logic/Flora/Flora.h"

///
///Forward declaration
///
namespace xml
{
	class Xml;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec roślinności
	///
	class FloraTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		FloraTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~FloraTemplate();

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
		///Wirtualna metoda ładująca dane z xml
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy Flora
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Flora *create(std::wstring id = L"");

	private:

		///
		///Wirtualna metoda wypełniająca danymi obiekt klasy Flora
		///
		///@param *flora - wskaźnik na obiekt klasy Flora
		///
		virtual void fill(Flora *flora);

		//gdy w klasie Flora bydą dodawane pola
		//to tutaj, w klasie jej fabryki,
		//należay utworzyć takie same pola oraz je uwzględnić

		float m_rotation_speed_body_template; //prędkość rotacji body
		float m_rotation_speed_head_template; //prędkość rotacji head

	};
}//namespace factory
#endif //H_FLORA_TEMPLATE_JACK
