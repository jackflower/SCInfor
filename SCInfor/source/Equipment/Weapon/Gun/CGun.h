//  _____________________________________
// | CGun.h - class definition           |
// | Jack Flower November 2010           |
// |_____________________________________|
//

#ifndef H_GUN_JACK
#define H_GUN_JACK

#include "../../../Logic/Actor/CActor.h"
#include "LockWeapon/CLockWeapon.h"
#include "../../EquipmentData/CEquipmentAmmoData.h"
#include <SFML/System/Vector2.hpp>
#include "../Ammo/CAmmo.h"
#include "../EGunState.h"

using namespace logic;
using namespace equipment;
using namespace equipment::weapon;
using namespace transformation;
using namespace equipment::weapon::lockweapon;

namespace equipment
{
	namespace weapon
	{
		///
		///Klasa reprezentuje logik� strzelaj�cego dzia�a
		///
		class CGun : public CActor
		{
			RTTI_DECL;
		
			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CGun, nale�y wywo�a� CPhysicalManager::CreateGun();

		protected:

			///
			///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
			///
			///@param &uniqueId - unikalny identyfikator obiektu - sta�a referncja na obiekt klasy std::wstring
			///
			CGun(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param &CGunCopy - sta�a referecnaj na obiekt klasy CGun
			///
			CGun(const CGun& CGunCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			~CGun(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			std::string GetType();
			
			///
			///Metoda zwraca wska�nik obiekt klasy CAmmo
			///
			CAmmo *getAmmo();

			///
			///Metoda ustawia wska�nik obiekt klasy CAmmo
			///
			///@param *ammo - wska�nik obiekt klasy CAmmo
			///
			void setAmmo(CAmmo * ammo);

			///
			///Metoda zwraca flag�, czy obiekt posiada magazynek na amunicj� (amunicj�)
			///
			const bool getUseAmmo() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada magazynek na amunicj� (amunicj�)
			///
			///@param use_ammo - flaga, czy obiekt posiada magazynek na amunicj� (amunicj�)
			///
			void setUseAmmo(bool use_ammo);

			///
			///Metoda zwraca referencj� na opakowanie danych dla transformacji
			///
			CTransformation & getAmmoTransformed();

			///
			///Metoda ustawia referencj� na opakowanie danych dla transformacji
			///
			///@param & ammo_transformation - referencja na obiekt klasy CTransformation
			///
			void setAmmoTransformed(CTransformation & ammo_transformation);

			///
			///Metoda zwraca referencj� na opakowanie funkcjonalno�ci amunicji
			///
			CEquipmentAmmoData & getEquipmentAmmoData();

			///
			///Metoda ustawia referencj� na opakowanie funkcjonalno�ci amunicji
			///
			///@param & ammo_data - referencja na obiekt klasy CEquipmentAmmoData
			///
			void setEquipmentAmmoData(CEquipmentAmmoData & ammo_data);

			///
			///Metoda zwraca flag�, czy mo�na prze�adowa� amunicj�
			///
			const bool GetAmmoLoading() const;

			///
			///Metoda ustawia flag�, czy mo�na prze�adowa� amunicj�
			///
			///@param ammo_loading - flaga, czy mo�na prze�adowa� amunicj�
			///
			void SetAmmoLoading(bool ammo_loading);

			///
			///Metoda zwraca czas prze�adowania amunicji
			///
			const float GetTimeAmmoLoadDelay() const;

			///
			///Metoda ustawia czas prze�adowania amunicji
			///
			///@param time_ammo_load_delay - czas porzebny do prze�adowania amunicji
			///
			void SetTimeAmmoLoadDelay(float time_ammo_load_delay);

			///
			///Metoda zwraca flag�, czy mo�na odda� strza�
			///
			const bool GetShotEnabled() const;

			///
			///Metoda ustawia flag�, czy mo�na odda� strza�
			///
			///@param shot_enabled - flaga, czy mo�na odda� strza�
			///
			void SetShotEnabled(bool shot_enabled);

			///
			///Metoda zwraca czas trwania wystrza�u
			///
			const float GetTimeShot() const;

			///
			///Metoda ustawia czas trwania animacji wystrza�u
			///
			///@param time_shot - czas trwania strza�u
			///
			void SetTimeShot(float time_shot);

			///
			///Metoda zwraca flag� czy trwa wystrza�
			///
			const bool GetShotInProgress() const;

			///
			///Metoda ustawia flag�, czy trwa wystrza�
			///
			///@param shot_in_progress - flaga okre�laj�ca czy trwa wystrza�
			///
			void SetShotInProgress(bool shot_in_progress);

			///
			///Metoda zwraca pr�dko�� pocisku wystrzelonego z dzia�a
			///
			const float GetBulletSpeed() const;

			///
			///Metoda ustawia pr�dko�� pocisku wystrzelonego z dzia�a
			///
			///@param bullet_speed - pr�dko�� pocisku wystrzelonego z dzia�a
			///
			void SetBulletSpeed(const float bullet_speed);
			
			///
			///Metoda zwraca zasi�g strza�u
			///
			const float GetRangeShot() const;

			///
			///Metoda ustawia zasi�g strza�u
			///
			///@param range_shot - zasi�g strza�u
			///
			void SetRangeShot(float range_shot);
			
			///
			///Metoda zwraca ilo�� luf dzia�a
			///
			const int GetBarrelCount() const;

			///
			///Metoda ustawia ilo�� luf dzia�a
			///
			///@param barrel_count - ilo�� luf, kt�re posiada dzia�o
			///
			void SetBarrelCount(int barrel_count);

			///
			///Metoda zwraca apogeum wysoko�ci lotu balistycznego pocisku
			///
			const float GetTargetAltitude() const;

			///
			///Metoda ustawia apogeum wysoko�ci lotu balistycznego pocisku
			///
			///@param target_altitude - apogeum wysoko�ci lotu balistycznego pocisku
			///
			void SetTargetAltitude(float target_altitude);

			///
			///Metoda zwraca sta�� referencj� na wektor po�o�enia emitera eksplozji wzgl�dem lufy
			///
			const sf::Vector2f& GetExplosionEmiter() const;

			///
			///Metoda ustawia po�o�enie emitera eksplozji wzgl�dem lufy - wektor
			///
			///@param &explosion_emiter - wektor - sta�a referencja na warto�� przesuni�cia emitera eksplozji
			///
			void SetExplosionEmiter(sf::Vector2f& explosion_emiter);

			///
			///Metoda ustawia po�o�enie emitera eksplozji wzgl�dem lufy - wsp�rz�dne
			///
			///@param explosion_emiter_x - sk�adowa X przesuni�cia emitera eksplozji
			///
			///@param explosion_emiter_y - sk�adowa Y przesuni�cia emitera eksplozji
			///
			void SetExplosionEmiter(float explosion_emiter_x, float explosion_emiter_y);

			///
			///Metoda sprawdza, czy wystarczy amunicji w magazunku na strza� z wszystkich luf
			///
			const int GetBulletPerSoot();

			///
			///Metoda zwraca czas op�nienia komunikatu uzupe�nienia amunicji
			///
			const float GetAmmoTimeDelayed() const;

			///
			///Metoda ustawia czas op�nienia komunikatu uzupe�nienia amunicji
			///
			///@param ammo_time_delayed - czas op�nienia komunikatu uzupe�nienia amunicji
			///
			void SetAmmoTimeDelayed(float ammo_time_delayed);

			///
			///Metoda zaopatruje obiekt w amunicj� z zewn�trznego �r�d�a
			///
			///@param & ammo_out - referencja na amunicj� - zewn�trzne �r�d�o aminicji
			///
			void supplyAmmunition(int & ammo_out);

			///
			///Metoda zwraca referencj� na przedzia� liczb, w zakresie kt�rego definiujemy zaci�cie dzia�a
			///
			const std::pair<float, float> & getReliabilityRange() const;

			///
			///Metoda ustawia przedzia� liczb, w zakresie kt�rego definiujemy zaci�cie dzia�a
			///
			///@param reliability_range_first - zakres g�rny
			///
			///@param reliability_range_second - zakres dolny
			///
			void setReliabilityRange(float reliability_range_first, float reliability_range_second);

			///
			///Metoda zwraca dopuszczaln� ilo�� wyst�pie� uszkodze�
			///
			const unsigned getLimitAmountDamage() const;//m_limit_amount_damage

			///
			///Metoda ustawia dopuszczaln� ilo�� wyst�pie� uszkodze�
			///
			///@param limit_amount_damage - dopussczalna ilo�� wyst�pie� uszkodze�
			///
			void setLimitAmountDamage(unsigned limit_amount_damage);

			///
			///Metoda zwraca referencj� na obiekt klasy CLockWeapon - generator uszkodze�
			///
			CLockWeapon & getDamage();

			///
			///Metoda ustawia referencj� na obiekt klasy CLockWeapon - generator uszkodze�
			///
			///@param & damage - generator uszkodze�
			///
			void setDamage(CLockWeapon & damage);

			///
			///Metoda zwraca flag�, czy mo�na i trzeba wygenerowa� strza� obiektu
			///
			bool Shoot();

			///
			///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void UpdateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuje logik� obiektu
			///
			///@param dt - czas
			///
			void Update(float dt);

		private:

			CEquipmentAmmoData		m_ammo_data;				//opakowanie funkcjonalno�ci dzia�a
			bool					m_ammo_loading;				//flaga, czy mo�na prze�adowa� amunicj�
			float					m_time_ammo_load_delay;		//czas potrzebny do prze�adowania amunicji
			bool					m_shot_enabled;				//flaga, czy mo�na odda� strza�
			float					m_time_shot;				//czas trwania strza�u
			bool					m_shot_in_progress;			//flaga okre�laj�ca czy trwa wystrza�
			float					m_range_shot;				//zasi�g strza�u
			float					m_bullet_speed;				//pr�dko�� pocisku - dzia�o decyduje
			int						m_barrel_count;				//ilo�� luf, kt�re posiada dzia�o
			float					m_target_altitude;			//apogeum pu�apu - apogeum wysoko�ci jak� mo�e osi�gn�� pocisk
			sf::Vector2f			m_explosion_emiter;			//po�o�enia emitera eksplozji wystrza�u wzgl�dem lufy
			float					m_ammo_time_delayed;		//czas op�nienia komunikatu uzupe�nienia amunicji - jako dana wej�ciowa dla sf::Randomizer
			EGunState				m_gun_state;				//wyliczenie dla automatu stan�w obiektu klasy CGun
			float					m_reliability;				//losowane prawdopodobie�stwo niezawodno�ci dzia�ania
			std::pair<float, float>	m_reliability_range;		//przedzia� w zakresie kt�rego definiujemy zaci�cie dzia�a < 0..1 >
			CLockWeapon				m_damage;					//generator uszkodze�
			float					m_process_time;				//czas procesu potrzebny do wylicze�
			unsigned				m_limit_amount_damage;		//dopuszczalna ilo�� uszkodze�, po kt�rym nast�puje stan serwisowy
			float					m_new_anim_speed;			//wyliczony wsp�czynnik pr�dko�ci odtwarzania animacji
				
		private:

			//prywatna metoda aktualizuj�ce stan obiektu (automat stan�w)	
			void updateGunState(float dt);//uwaga, w tej metodzie obs�uga strza�u...

		   //prywatna metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
			void updateAmmoTransformation(float dt);

			//docelowo: poni�sze opakowa� do jakiego� AI (iddle...)
			float m_time_data;	//zmienna pomocznicza (waste)
			float m_time;		//zmienna pomocznicza (waste)
			float direction;	//zmienna pomocznicza (waste)

		};
	}//	namespace weapon
}//namespace equipment
#endif//H_GUN_JACK
