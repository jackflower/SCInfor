//  ___________________________________________
// | CFloraTemplate.h - class definition       |
// | SCI - March 2014                          |
// |___________________________________________|
//

#ifndef H_FLORA_TEMPLATE_JACK
#define H_FLORA_TEMPLATE_JACK

#include "CActorTemplate.h"
#include "../Logic/Flora/CFlora.h"

///
///Forward declaration
///
namespace xml
{
	class CXml;
}

namespace factory
{
	///
	///Klasa reprezentuje generyczny wzorzec ro�linno�ci
	///
	class CFloraTemplate : public CActorTemplate
	{

	public:

		///
		///Konstruktor
		///
		CFloraTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CFloraTemplate();

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
		///Wirtualna metoda �aduj�ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CFlora
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CFlora* create(std::wstring id = L"");

	private:

		///
		///Wirtualna metoda wype�niaj�ca danymi obiekt klasy CFlora
		///
		///@param *flora - wska�nik na obiekt klasy CFlora
		///
		virtual void fill(CFlora *flora);

		//gdy w klasie CFlora byd� dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale�ay utworzy� takie same pola oraz je uwzgl�dni�

		float m_rotation_speed_body_template; //pr�dko�� rotacji body
		float m_rotation_speed_head_template; //pr�dko�� rotacji head


	};
}//namespace factory
#endif //H_FLORA_TEMPLATE_JACK
