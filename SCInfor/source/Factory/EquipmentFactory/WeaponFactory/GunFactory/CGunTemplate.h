//  _________________________________________
// | CGunTemplate.h - class definition       |
// | Jack Flower June 2014                   |
// |_________________________________________|
//

#ifndef H_GUN_TEMPLATE_JACK
#define H_GUN_TEMPLATE_JACK

#include "../../../../Equipment/EquipmentData/EquipmentAmmoData.h"
#include "../../../../Equipment/Weapon/Gun/CGun.h"
#include "../AmmoFactory/CAmmoTemplate.h"

using namespace equipment;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec magazynka na amunicjê
	///
	class CGunTemplate : public CActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CGunTemplate();

		///
		///Destruktor wirtualny
		///
		~CGunTemplate();

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
		///Metoda tworzy obiekt klasy CGun
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CGun* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *p_ammo - wskaŸnik na obiekt klasy Ammo
		///
		virtual void Fill(CGun *p_gun);

	private:

		EquipmentAmmoData	m_templ_ammo_data;				//opakowanie funkcjonalnoœci amunicji
		CAmmoTemplate*		p_templ_ammo;					//wskaŸnik na obiekt klasy CAmmoTemplate - fabryka amunicji
		float				m_templ_time_ammo_load_delay;	//czas potrzebny do prze³adowania amunicji
		float				m_templ_time_shot;				//czas trwania strza³u
		float				m_templ_range_shot;				//zasiêg strza³u
		float				m_templ_bullet_speed;			//prêdkoœæ pocisku - dzia³o decyduje
		int					m_templ_barrel_count;			//iloœæ luf, które posiada dzia³o
		float				m_templ_target_altitude;		//apogeum pu³apu - apogeum wysokoœci jak¹ mo¿e osi¹gn¹æ pocisk
		sf::Vector2f	 	m_templ_explosion_emiter;		//po³o¿enia emitera eksplozji wystrza³u wzglêdem lufy
		float				m_templ_ammo_time_delayed;		//czas opóŸnienia komunikatu uzupe³nienia amunicji - jako dana wejœciowa dla sf::Randomizer
		unsigned			m_templ_limit_amount_damage;	//licznik uszkodzeñ, po którym nastêpuje stan serwisowy
		CLockWeapon			m_templ_damage;					//generator uszkodzeñ - do zainicjowania danymi tworzonego obiektu
	};
}//namespace factory
#endif//H_GUN_TEMPLATE_JACK
