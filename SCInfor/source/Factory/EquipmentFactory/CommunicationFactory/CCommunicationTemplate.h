//  ____________________________________________
// | CEnergyTemplate.h - class definition       |
// | Jack Flower - May 2014                     |
// |____________________________________________|
//

#ifndef H_COMMUNICATION_TEMPLATE_JACK
#define H_COMMUNICATION_TEMPLATE_JACK

#include "../../CActorTemplate.h"
#include "../../../Logic/Communication/CCommunication.h"

using namespace logic::communication;

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich modu³ów odpowiedzialnych za komunikacjê
	///
	class CCommunicationTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CCommunicationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CCommunicationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
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
		///Metoda tworzy obiekt klasy CCommunication
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CCommunication* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_communication - wskaŸnik na obiekt klasy CCommunication
		///
		virtual void Fill(CCommunication *p_communication);

	private:

		std::string		m_templ_communication_name;	//nazwa modu³u ³¹cznoœci
		float			m_templ_range;				//zasiêg pracy urz¹dzenie - nadajnik/odbiornik
		float			m_templ_reset_duration;		//czas co jaki modu³ siê resetuje/testuje
		std::string		m_templ_login;				//login	- opakowanie dla CLogin
		std::string		m_templ_password;			//has³o - opakowanie dla CLogin

		//tworz¹c plik xml nale¿y zdecydowaæ z jakich elementów ten obiekt siê sk³ada
		//mo¿na zablokowaæ reprezetacjê graficzn¹ poporzez flagi use, mo¿na tak¿e
		//zablokowaæ nazwy atrybutów w wêz³ach pliku xml, wtedy animacje nie zostan¹
		//za³adowane, mo¿na tak¿e zupe³nie pomin¹æ to w pliku xml
		//wniosek:
		//utworzyæ taki plik xml, który:
		//zdefuniuje wyposa¿enie modu³u komunikacyjnego (np. bateria?)
		//modu³ komunikacyjny to nic, ale w przypadku przekaŸnika
		//nalezy ustaliæ, co wchodzi w jego wyposa¿enie:
		//
		// - modu³ funkcjonalnoœci energii
		// - modu³ funkcjonalnoœci paliwa
		// - modu³ funkcjonalnoœci wentylacji
		// - modu³ funkcjonalnoœci klimatyzacji
		// - etc...
		// - najprawdopodobniej, póki co, powy¿szych nie bêdzie...

	};
}//namespace factory
#endif//H_COMMUNICATION_TEMPLATE_JACK