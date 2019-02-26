//  ________________________________________
// | GunTemplate.h - class definition       |
// | Jack Flower June 2014                  |
// |________________________________________|
//

#ifndef H_GUN_TEMPLATE_JACK
#define H_GUN_TEMPLATE_JACK

#include "../../../../Equipment/EquipmentData/EquipmentAmmoData.h"
#include "../../../../Equipment/Weapon/Gun/Gun.h"
#include "../AmmoFactory/AmmoTemplate.h"

using namespace equipment;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec magazynka na amunicję
	///
	class GunTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		GunTemplate();

		///
		///Destruktor wirtualny
		///
		~GunTemplate();

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
		///Metoda tworzy obiekt klasy Gun
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		Gun *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *p_ammo - wskaźnik na obiekt klasy Ammo
		///
		virtual void fill(Gun *p_gun);

	private:

		EquipmentAmmoData m_templ_ammo_data; //opakowanie funkcjonalności amunicji
		AmmoTemplate *p_templ_ammo; //wskaźnik na obiekt klasy AmmoTemplate - fabryka amunicji
		float m_templ_time_ammo_load_delay;	//czas potrzebny do przeładowania amunicji
		float m_templ_time_shot; //czas trwania strzału
		float m_templ_range_shot; //zasięg strzału
		float m_templ_bullet_speed; //prędkość pocisku - działo decyduje
		int m_templ_barrel_count; //ilość luf, które posiada działo
		float m_templ_target_altitude; //apogeum pułapu - apogeum wysokości jaką może osiągnąć pocisk
		sf::Vector2f m_templ_explosion_emiter; //położenia emitera eksplozji wystrzału względem lufy
		float m_templ_ammo_time_delayed; //czas opóźnienia komunikatu uzupełnienia amunicji - jako dana wejściowa dla sf::Randomizer
		unsigned m_templ_limit_amount_damage; //licznik uszkodzeń, po którym następuje stan serwisowy
		LockWeapon m_templ_damage; //generator uszkodzeń - do zainicjowania danymi tworzonego obiektu
	};
}//namespace factory
#endif//H_GUN_TEMPLATE_JACK
