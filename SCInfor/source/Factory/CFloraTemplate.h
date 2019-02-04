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
	///Klasa reprezentuje generyczny wzorzec roœlinnoœci
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
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CFlora
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CFlora* Create(std::wstring id = L"");

	private:

		///
		///Wirtualna metoda wype³niaj¹ca danymi obiekt klasy CFlora
		///
		///@param *flora - wskaŸnik na obiekt klasy CFlora
		///
		virtual void Fill(CFlora *flora);

		//gdy w klasie CFlora byd¹ dodawane pola
		//to tutaj, w klasie jej fabryki,
		//nale¿ay utworzyæ takie same pola oraz je uwzglêdniæ

		float m_rotation_speed_body_template; //prêdkoœæ rotacji body
		float m_rotation_speed_head_template; //prêdkoœæ rotacji head


	};
}//namespace factory
#endif //H_FLORA_TEMPLATE_JACK
