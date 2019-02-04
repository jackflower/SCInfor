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
	///Klasa reprezentuje wzorzec magazynka na amunicj�
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
		///Metoda tworzy obiekt klasy CAmmo
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CAmmo* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_ammo - wska�nik na obiekt klasy CAmmo
		///
		virtual void Fill(CAmmo *p_ammo);

	private:

		CCaliber		m_templ_caliber;					//kaliber aminicji
		EAmmoState		m_templ_ammo_state;					//wyliczenie stan�w magazynka z amunicj�	
		int				m_templ_ammo;						//ilo�� amunicji w magazynku
		int				m_templ_ammo_capacity;				//pojemno�� magazynka na amunicj�
		float			m_templ_percentage_reserve_ammo;	//procentowa warto�� amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
		int				m_templ_reserve_ammo;				//wyliczana ilo�� amunicji w magazynku dla rezerwy (w tym wzorcu)
	};
}//namespace factory
#endif//H_AMMO_TEMPLATE_JACK
