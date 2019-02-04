//  _________________________________________________
// | CRelayStationTemplate.h - class definition      |
// | Jack Flower - July 2015                         |
// |_________________________________________________|
//

#ifndef H_RELAY_STATION_TEMPLATE_JACK
#define H_RELAY_STATION_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/CRelayStation.h"
#include "../../../EquipmentFactory/CommunicationFactory/CCommunicationTemplate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich przeka�nik�w elektrowni
	///
	class CRelayStationTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CRelayStationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CRelayStationTemplate();

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
		///Wirtualna metoda �aduj�ca dane z xml �aduje wsp�lne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CRelayStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CRelayStation* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_relay_station - wska�nik na obiekt klasy CRelayStation
		///
		virtual void Fill(CRelayStation *p_relay_station);

	protected:

		std::string				m_templ_relay_station_name;	//nazwa przeka�nika energii elektrycznej
		bool					m_templ_use_communication;	//flaga, czy obiekt posiada modu� do komunikacji
		CCommunicationTemplate*	p_templ_communication;		//wska�nik na obiekt klasy CCommunicationTemplate (wzorzec modu�u komunikacji)
	};
}//namespace factory
#endif//H_RELAY_STATION_TEMPLATE_JACK
