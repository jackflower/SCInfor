//  _________________________________________________
// | CRelayStationTemplate.h - class definition      |
// | Jack Flower - July 2015                         |
// |_________________________________________________|
//

#ifndef H_RELAY_STATION_TEMPLATE_JACK
#define H_RELAY_STATION_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/CRelayStation.h"
#include "../../../EquipmentFactory/CommunicationFactory/CommunicationTemplate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich przekaünikÛw elektrowni
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
		///Wirtualna metoda zwalniajπca zasÛb - implementacje w klasach pochodnych
		///
		void drop();

		///
		///Metoda ≥adujπca dane
		///
		///@param &name - sta≥a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda ≥adujπca dane z xml ≥aduje wspÛlne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CRelayStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CRelayStation* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype≥niajπca wskazany obiekt danymi tej klasy
		///
		///@param *p_relay_station - wskaünik na obiekt klasy CRelayStation
		///
		virtual void fill(CRelayStation *p_relay_station);

	protected:

		std::string				m_templ_relay_station_name;	//nazwa przekaünika energii elektrycznej
		bool					m_templ_use_communication;	//flaga, czy obiekt posiada modu≥ do komunikacji
		CommunicationTemplate*	p_templ_communication;		//wskaünik na obiekt klasy CommunicationTemplate (wzorzec modu≥u komunikacji)
	};
}//namespace factory
#endif//H_RELAY_STATION_TEMPLATE_JACK
