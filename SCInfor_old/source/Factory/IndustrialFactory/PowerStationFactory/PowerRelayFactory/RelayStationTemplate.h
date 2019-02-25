//  ________________________________________________
// | RelayStationTemplate.h - class definition      |
// | Jack Flower - July 2015                        |
// |________________________________________________|
//

#ifndef H_RELAY_STATION_TEMPLATE_JACK
#define H_RELAY_STATION_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/RelayStation.h"
#include "../../../EquipmentFactory/CommunicationFactory/CommunicationTemplate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich przekaźników elektrowni
	///
	class RelayStationTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		RelayStationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~RelayStationTemplate();

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
		///Wirtualna metoda ładująca dane z xml ładuje wspólne cechy Actor
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy RelayStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		RelayStation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_relay_station - wskaźnik na obiekt klasy RelayStation
		///
		virtual void fill(RelayStation *p_relay_station);

	protected:

		std::string m_templ_relay_station_name;	//nazwa przekaźnika energii elektrycznej
		bool m_templ_use_communication;	//flaga, czy obiekt posiada moduł do komunikacji
		CommunicationTemplate *p_templ_communication; //wskaźnik na obiekt klasy CommunicationTemplate (wzorzec modułu komunikacji)
	};
}//namespace factory
#endif//H_RELAY_STATION_TEMPLATE_JACK
