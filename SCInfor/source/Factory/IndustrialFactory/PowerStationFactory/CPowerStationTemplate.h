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
		///Metoda tworzy obiekt klasy CPowerStation
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CPowerStation* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_power_station - wska�nik na obiekt klasy CPowerStation
		///
		virtual void Fill(CPowerStation *p_power_station);

	private:

		std::string					m_templ_power_station_name;		//nazwa elektrowni
		float						m_templ_energy_capacitor;		//ilo�� energii do zmagazynowania - pojemno�� (kondensator)
		unsigned					m_templ_amount_power_modules;	//ilo�� modu��w zasilajacych (turbin, przetwornik�w, etc...)
		EquipmentCommunicationData mm_templ_communication_data;	//opakowanie funkcjonalno�ci modu�u komunikacyjnego
		CCommunicationTemplate*		p_templ_communication;			//wska�nik na obiekt klasy CCommunicationTemplate (wzorzsec modu�u komunikacji)
	};
}//namespace factory
#endif//H_POWER_STATION_TEMPLATE_JACK
