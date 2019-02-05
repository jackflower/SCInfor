//  __________________________________________________
// | CPowerStationTemplate.h - class definition       |
// | Jack Flower - May 2015                           |
// |__________________________________________________|
//

#ifndef H_POWER_STATION_TEMPLATE_JACK
#define H_POWER_STATION_TEMPLATE_JACK

#include "../../CActorTemplate.h"
#include "../../../Logic/Industrial/PowerStation/CPowerStation.h"
#include "../../../Equipment/EquipmentData/EquipmentCommunicationData.h"

///
///Forward declaration
///
namespace factory
{
	class CCommunicationTemplate;
}

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wszystkich elektrowni
	///
	class CPowerStationTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPowerStationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CPowerStationTemplate();

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
		///Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		bool Load(CXml &xml);

		///
		///Metoda tworzy obiekt klasy CPowerStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPowerStation* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_power_station - wskaŸnik na obiekt klasy CPowerStation
		///
		virtual void Fill(CPowerStation *p_power_station);

	private:

		std::string					m_templ_power_station_name;		//nazwa elektrowni
		float						m_templ_energy_capacitor;		//iloœæ energii do zmagazynowania - pojemnoœæ (kondensator)
		unsigned					m_templ_amount_power_modules;	//iloœæ modu³ów zasilajacych (turbin, przetworników, etc...)
		EquipmentCommunicationData mm_templ_communication_data;	//opakowanie funkcjonalnoœci modu³u komunikacyjnego
		CCommunicationTemplate*		p_templ_communication;			//wskaŸnik na obiekt klasy CCommunicationTemplate (wzorzsec modu³u komunikacji)
	};
}//namespace factory
#endif//H_POWER_STATION_TEMPLATE_JACK
