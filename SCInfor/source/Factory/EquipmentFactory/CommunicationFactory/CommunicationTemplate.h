//  __________________________________________________
// | CommunicationTemplate.h - class definition       |
// | Jack Flower - May 2014                           |
// |__________________________________________________|
//

#ifndef H_COMMUNICATION_TEMPLATE_JACK
#define H_COMMUNICATION_TEMPLATE_JACK

#include "../../ActorTemplate.h"
#include "../../../Logic/Communication/Communication.h"

using namespace logic::communication;

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich modułów odpowiedzialnych za komunikację
	///
	class CommunicationTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CommunicationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CommunicationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób - implementacje w klasach pochodnych
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
		///Metoda tworzy obiekt klasy Communication
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Communication *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_communication - wskaźnik na obiekt klasy Communication
		///
		virtual void fill(Communication *p_communication);

	private:

		std::string m_templ_communication_name;	//nazwa modułu łączności
		float m_templ_range; //zasięg pracy urządzenie - nadajnik/odbiornik
		float m_templ_reset_duration; //czas co jaki moduł się resetuje/testuje
		std::string m_templ_login; //login	- opakowanie dla Login
		std::string m_templ_password; //hasło - opakowanie dla Login

		//tworząc plik xml należy zdecydować z jakich elementów ten obiekt się składa
		//można zablokować reprezetację graficzną poporzez flagi use, można także
		//zablokować nazwy atrybutów w węzłach pliku xml, wtedy animacje nie zostaną
		//załadowane, można także zupełnie pominąć to w pliku xml
		//wniosek:
		//utworzyć taki plik xml, który:
		//zdefuniuje wyposażenie modułu komunikacyjnego (np. bateria?)
		//moduł komunikacyjny to nic, ale w przypadku przekaźnika
		//nalezy ustalić, co wchodzi w jego wyposażenie:
		//
		// - moduł funkcjonalności energii
		// - moduł funkcjonalności paliwa
		// - moduł funkcjonalności wentylacji
		// - moduł funkcjonalności klimatyzacji
		// - etc...
		// - najprawdopodobniej, póki co, powyższych nie będzie...

	};
}//namespace factory
#endif//H_COMMUNICATION_TEMPLATE_JACK
