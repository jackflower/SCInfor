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
	///Klasa reprezentuje prawzorzec wska�nika przeka�nika (sloty)
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
		///Metoda tworzy obiekt klasy CSlotsRate
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CSlotsRate* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_slots_rate - wska�nik na obiekt klasy CSlotsRate
		///
		virtual void Fill(CSlotsRate *p_slots_rate);

	private:

	};
}//namespace factory
#endif//H_SLOTS_RATE_TEMPLATE_JACK
