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
	///Klasa reprezentuje prawzorzec wszystkich modu��w odpowiedzialnych za komunikacj�
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
		///Wirtualna metoda zwalniaj�ca zas�b - implementacje w klasach pochodnych
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml
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
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_communication - wska�nik na obiekt klasy CCommunication
		///
		virtual void Fill(CCommunication *p_communication);

	private:

		std::string		m_templ_communication_name;	//nazwa modu�u ��czno�ci
		float			m_templ_range;				//zasi�g pracy urz�dzenie - nadajnik/odbiornik
		float			m_templ_reset_duration;		//czas co jaki modu� si� resetuje/testuje
		std::string		m_templ_login;				//login	- opakowanie dla CLogin
		std::string		m_templ_password;			//has�o - opakowanie dla CLogin

		//tworz�c plik xml nale�y zdecydowa� z jakich element�w ten obiekt si� sk�ada
		//mo�na zablokowa� reprezetacj� graficzn� poporzez flagi use, mo�na tak�e
		//zablokowa� nazwy atrybut�w w w�z�ach pliku xml, wtedy animacje nie zostan�
		//za�adowane, mo�na tak�e zupe�nie pomin�� to w pliku xml
		//wniosek:
		//utworzy� taki plik xml, kt�ry:
		//zdefuniuje wyposa�enie modu�u komunikacyjnego (np. bateria?)
		//modu� komunikacyjny to nic, ale w przypadku przeka�nika
		//nalezy ustali�, co wchodzi w jego wyposa�enie:
		//
		// - modu� funkcjonalno�ci energii
		// - modu� funkcjonalno�ci paliwa
		// - modu� funkcjonalno�ci wentylacji
		// - modu� funkcjonalno�ci klimatyzacji
		// - etc...
		// - najprawdopodobniej, p�ki co, powy�szych nie b�dzie...

	};
}//namespace factory
#endif//H_COMMUNICATION_TEMPLATE_JACK