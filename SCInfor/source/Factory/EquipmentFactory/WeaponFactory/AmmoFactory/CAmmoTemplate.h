//  __________________________________________________
// | CAmmoTemplateTemplate.h - class definition       |
// | Jack Flower June 2014                            |
// |__________________________________________________|
//

#ifndef H_AMMO_TEMPLATE_JACK
#define H_AMMO_TEMPLATE_JACK

#include "../../../CActorTemplate.h"
#include "../../../../Equipment/Weapon/Ammo/CAmmo.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec magazynka na amunicjê
	///
	class CAmmoTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CAmmoTemplate();

		///
		///Destruktor wirtualny
		///
		~CAmmoTemplate();

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
		///Metoda tworzy obiekt klasy CAmmo
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CAmmo* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_ammo - wskaŸnik na obiekt klasy CAmmo
		///
		virtual void Fill(CAmmo *p_ammo);

	private:

		CCaliber		m_templ_caliber;					//kaliber aminicji
		EAmmoState		m_templ_ammo_state;					//wyliczenie stanów magazynka z amunicj¹	
		int				m_templ_ammo;						//iloœæ amunicji w magazynku
		int				m_templ_ammo_capacity;				//pojemnoœæ magazynka na amunicjê
		float			m_templ_percentage_reserve_ammo;	//procentowa wartoœæ amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
		int				m_templ_reserve_ammo;				//wyliczana iloœæ amunicji w magazynku dla rezerwy (w tym wzorcu)
	};
}//namespace factory
#endif//H_AMMO_TEMPLATE_JACK
