//  ______________________________________________
// | SlotsRateTemplate.h - class definition       |
// | Jack Flower - January 2016                   |
// |______________________________________________|
//

#ifndef H_SLOTS_RATE_TEMPLATE_JACK
#define H_SLOTS_RATE_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/CSlotsRate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wskaźnika przekaźnika (sloty)
	///
	class SlotsRateTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		SlotsRateTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~SlotsRateTemplate();

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
		///Wirtualna metoda ładująca dane z xml ładuje wspólne cechy CActor
		///
		///@param xml - referencja na obiekt klasy CXml
		///
		bool load(CXml & xml);

		///
		///Metoda tworzy obiekt klasy CSlotsRate
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CSlotsRate *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_slots_rate - wskaźnik na obiekt klasy CSlotsRate
		///
		virtual void fill(CSlotsRate *p_slots_rate);

	private:

	};
}//namespace factory
#endif//H_SLOTS_RATE_TEMPLATE_JACK
