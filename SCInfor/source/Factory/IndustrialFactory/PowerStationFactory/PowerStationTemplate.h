//  _________________________________________________
// | PowerStationTemplate.h - class definition       |
// | Jack Flower - May 2015                          |
// |_________________________________________________|
//

#ifndef H_POWER_STATION_TEMPLATE_JACK
#define H_POWER_STATION_TEMPLATE_JACK

#include "../../ActorTemplate.h"
#include "../../../Logic/Industrial/PowerStation/PowerStation.h"
#include "../../../Equipment/EquipmentData/EquipmentCommunicationData.h"

///
///Forward declaration
///
namespace factory
{
	class CommunicationTemplate;
}

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich elektrowni
	///
	class PowerStationTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PowerStationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~PowerStationTemplate();

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
		///@param xml - referencja na obiekt klasy Xml
		///
		bool load(Xml & xml);

		///
		///Metoda tworzy obiekt klasy PowerStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		PowerStation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_power_station - wskaźnik na obiekt klasy PowerStation
		///
		virtual void fill(PowerStation *p_power_station);

	private:

		std::string m_templ_power_station_name; //nazwa elektrowni
		float m_templ_energy_capacitor; //ilość energii do zmagazynowania - pojemność (kondensator)
		unsigned m_templ_amount_power_modules; //ilość modułów zasilajacych (turbin, przetworników, etc...)
		EquipmentCommunicationData mm_templ_communication_data;	//opakowanie funkcjonalności modułu komunikacyjnego
		CommunicationTemplate *p_templ_communication; //wskaźnik na obiekt klasy CommunicationTemplate (wzorzsec modułu komunikacji)
	};
}//namespace factory
#endif//H_POWER_STATION_TEMPLATE_JACK
