//  _________________________________________
// | AmmoTemplate.h - class definition       |
// | Jack Flower June 2014                   |
// |_________________________________________|
//

#ifndef H_AMMO_TEMPLATE_JACK
#define H_AMMO_TEMPLATE_JACK

#include "../../../ActorTemplate.h"
#include "../../../../Equipment/Weapon/Ammo/Ammo.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec magazynka na amunicję
	///
	class AmmoTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		AmmoTemplate();

		///
		///Destruktor wirtualny
		///
		~AmmoTemplate();

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
		///Metoda tworzy obiekt klasy Ammo
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Ammo *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_ammo - wskaźnik na obiekt klasy Ammo
		///
		virtual void fill(Ammo *p_ammo);

	private:

		Caliber m_templ_caliber; //kaliber aminicji
		EAmmoState m_templ_ammo_state; //wyliczenie stanów magazynka z amunicją	
		int m_templ_ammo; //ilość amunicji w magazynku
		int m_templ_ammo_capacity; //pojemność magazynka na amunicję
		float m_templ_percentage_reserve_ammo; //procentowa wartość amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
		int m_templ_reserve_ammo; //wyliczana ilość amunicji w magazynku dla rezerwy (w tym wzorcu)
	};
}//namespace factory
#endif//H_AMMO_TEMPLATE_JACK
