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
	///Klasa reprezentuje wzorzec magazynka na amunicj�
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
		///Metoda tworzy obiekt klasy CGun
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		CGun* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *p_ammo - wska�nik na obiekt klasy Ammo
		///
		virtual void Fill(CGun *p_gun);

	private:

		EquipmentAmmoData	m_templ_ammo_data;				//opakowanie funkcjonalno�ci amunicji
		CAmmoTemplate*		p_templ_ammo;					//wska�nik na obiekt klasy CAmmoTemplate - fabryka amunicji
		float				m_templ_time_ammo_load_delay;	//czas potrzebny do prze�adowania amunicji
		float				m_templ_time_shot;				//czas trwania strza�u
		float				m_templ_range_shot;				//zasi�g strza�u
		float				m_templ_bullet_speed;			//pr�dko�� pocisku - dzia�o decyduje
		int					m_templ_barrel_count;			//ilo�� luf, kt�re posiada dzia�o
		float				m_templ_target_altitude;		//apogeum pu�apu - apogeum wysoko�ci jak� mo�e osi�gn�� pocisk
		sf::Vector2f	 	m_templ_explosion_emiter;		//po�o�enia emitera eksplozji wystrza�u wzgl�dem lufy
		float				m_templ_ammo_time_delayed;		//czas op�nienia komunikatu uzupe�nienia amunicji - jako dana wej�ciowa dla sf::Randomizer
		unsigned			m_templ_limit_amount_damage;	//licznik uszkodze�, po kt�rym nast�puje stan serwisowy
		CLockWeapon			m_templ_damage;					//generator uszkodze� - do zainicjowania danymi tworzonego obiektu
	};
}//namespace factory
#endif//H_GUN_TEMPLATE_JACK
