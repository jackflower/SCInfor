//  _______________________________________________
// | CSlotsRateTemplate.h - class definition       |
// | Jack Flower - January 2016                    |
// |_______________________________________________|
//

#ifndef H_SLOTS_RATE_TEMPLATE_JACK
#define H_SLOTS_RATE_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Logic/Energetics/PowerRelay/CSlotsRate.h"

namespace factory
{
	///
	///Klasa reprezentuje prawzorzec wskaŸnika przekaŸnika (sloty)
	///
	class CSlotsRateTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CSlotsRateTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CSlotsRateTemplate();

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
		///Metoda tworzy obiekt klasy CSlotsRate
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CSlotsRate* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_slots_rate - wskaŸnik na obiekt klasy CSlotsRate
		///
		virtual void Fill(CSlotsRate *p_slots_rate);

	private:

	};
}//namespace factory
#endif//H_SLOTS_RATE_TEMPLATE_JACK
