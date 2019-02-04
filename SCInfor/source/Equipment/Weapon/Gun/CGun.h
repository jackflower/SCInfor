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
		///Klasa reprezentuje logikê strzelaj¹cego dzia³a
		///
		class CGun : public CActor
		{
			RTTI_DECL;
		
			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CGun, nale¿y wywo³aæ CPhysicalManager::CreateGun();

		protected:

			///
			///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			///@param &uniqueId - unikalny identyfikator obiektu - sta³a referncja na obiekt klasy std::wstring
			///
			CGun(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param &CGunCopy - sta³a referecnaj na obiekt klasy CGun
			///
			CGun(const CGun& CGunCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CGun(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			std::string GetType();
			
			///
			///Metoda zwraca wskaŸnik obiekt klasy CAmmo
			///
			CAmmo *getAmmo();

			///
			///Metoda ustawia wskaŸnik obiekt klasy CAmmo
			///
			///@param *ammo - wskaŸnik obiekt klasy CAmmo
			///
			void setAmmo(CAmmo * ammo);

			///
			///Metoda zwraca flagê, czy obiekt posiada magazynek na amunicjê (amunicjê)
			///
			const bool getUseAmmo() const;

			///
			///Metoda ustawia flagê, czy obiekt posiada magazynek na amunicjê (amunicjê)
			///
			///@param use_ammo - flaga, czy obiekt posiada magazynek na amunicjê (amunicjê)
			///
			void setUseAmmo(bool use_ammo);

			///
			///Metoda zwraca referencjê na opakowanie danych dla transformacji
			///
			CTransformation & getAmmoTransformed();

			///
			///Metoda ustawia referencjê na opakowanie danych dla transformacji
			///
			///@param & ammo_transformation - referencja na obiekt klasy CTransformation
			///
			void setAmmoTransformed(CTransformation & ammo_transformation);

			///
			///Metoda zwraca referencjê na opakowanie funkcjonalnoœci amunicji
			///
			CEquipmentAmmoData & getEquipmentAmmoData();

			///
			///Metoda ustawia referencjê na opakowanie funkcjonalnoœci amunicji
			///
			///@param & ammo_data - referencja na obiekt klasy CEquipmentAmmoData
			///
			void setEquipmentAmmoData(CEquipmentAmmoData & ammo_data);

			///
			///Metoda zwraca flagê, czy mo¿na prze³adowaæ amunicjê
			///
			const bool GetAmmoLoading() const;

			///
			///Metoda ustawia flagê, czy mo¿na prze³adowaæ amunicjê
			///
			///@param ammo_loading - flaga, czy mo¿na prze³adowaæ amunicjê
			///
			void SetAmmoLoading(bool ammo_loading);

			///
			///Metoda zwraca czas prze³adowania amunicji
			///
			const float GetTimeAmmoLoadDelay() const;

			///
			///Metoda ustawia czas prze³adowania amunicji
			///
			///@param time_ammo_load_delay - czas porzebny do prze³adowania amunicji
			///
			void SetTimeAmmoLoadDelay(float time_ammo_load_delay);

			///
			///Metoda zwraca flagê, czy mo¿na oddaæ strza³
			///
			const bool GetShotEnabled() const;

			///
			///Metoda ustawia flagê, czy mo¿na oddaæ strza³
			///
			///@param shot_enabled - flaga, czy mo¿na oddaæ strza³
			///
			void SetShotEnabled(bool shot_enabled);

			///
			///Metoda zwraca czas trwania wystrza³u
			///
			const float GetTimeShot() const;

			///
			///Metoda ustawia czas trwania animacji wystrza³u
			///
			///@param time_shot - czas trwania strza³u
			///
			void SetTimeShot(float time_shot);

			///
			///Metoda zwraca flagê czy trwa wystrza³
			///
			const bool GetShotInProgress() const;

			///
			///Metoda ustawia flagê, czy trwa wystrza³
			///
			///@param shot_in_progress - flaga okreœlaj¹ca czy trwa wystrza³
			///
			void SetShotInProgress(bool shot_in_progress);

			///
			///Metoda zwraca prêdkoœæ pocisku wystrzelonego z dzia³a
			///
			const float GetBulletSpeed() const;

			///
			///Metoda ustawia prêdkoœæ pocisku wystrzelonego z dzia³a
			///
			///@param bullet_speed - prêdkoœæ pocisku wystrzelonego z dzia³a
			///
			void SetBulletSpeed(const float bullet_speed);
			
			///
			///Metoda zwraca zasiêg strza³u
			///
			const float GetRangeShot() const;

			///
			///Metoda ustawia zasiêg strza³u
			///
			///@param range_shot - zasiêg strza³u
			///
			void SetRangeShot(float range_shot);
			
			///
			///Metoda zwraca iloœæ luf dzia³a
			///
			const int GetBarrelCount() const;

			///
			///Metoda ustawia iloœæ luf dzia³a
			///
			///@param barrel_count - iloœæ luf, które posiada dzia³o
			///
			void SetBarrelCount(int barrel_count);

			///
			///Metoda zwraca apogeum wysokoœci lotu balistycznego pocisku
			///
			const float GetTargetAltitude() const;

			///
			///Metoda ustawia apogeum wysokoœci lotu balistycznego pocisku
			///
			///@param target_altitude - apogeum wysokoœci lotu balistycznego pocisku
			///
			void SetTargetAltitude(float target_altitude);

			///
			///Metoda zwraca sta³¹ referencjê na wektor po³o¿enia emitera eksplozji wzglêdem lufy
			///
			const sf::Vector2f& GetExplosionEmiter() const;

			///
			///Metoda ustawia po³o¿enie emitera eksplozji wzglêdem lufy - wektor
			///
			///@param &explosion_emiter - wektor - sta³a referencja na wartoœæ przesuniêcia emitera eksplozji
			///
			void SetExplosionEmiter(sf::Vector2f& explosion_emiter);

			///
			///Metoda ustawia po³o¿enie emitera eksplozji wzglêdem lufy - wspó³rzêdne
			///
			///@param explosion_emiter_x - sk³adowa X przesuniêcia emitera eksplozji
			///
			///@param explosion_emiter_y - sk³adowa Y przesuniêcia emitera eksplozji
			///
			void SetExplosionEmiter(float explosion_emiter_x, float explosion_emiter_y);

			///
			///Metoda sprawdza, czy wystarczy amunicji w magazunku na strza³ z wszystkich luf
			///
			const int GetBulletPerSoot();

			///
			///Metoda zwraca czas opóŸnienia komunikatu uzupe³nienia amunicji
			///
			const float GetAmmoTimeDelayed() const;

			///
			///Metoda ustawia czas opóŸnienia komunikatu uzupe³nienia amunicji
			///
			///@param ammo_time_delayed - czas opóŸnienia komunikatu uzupe³nienia amunicji
			///
			void SetAmmoTimeDelayed(float ammo_time_delayed);

			///
			///Metoda zaopatruje obiekt w amunicjê z zewnêtrznego Ÿród³a
			///
			///@param & ammo_out - referencja na amunicjê - zewnêtrzne Ÿród³o aminicji
			///
			void supplyAmmunition(int & ammo_out);

			///
			///Metoda zwraca referencjê na przedzia³ liczb, w zakresie którego definiujemy zaciêcie dzia³a
			///
			const std::pair<float, float> & getReliabilityRange() const;

			///
			///Metoda ustawia przedzia³ liczb, w zakresie którego definiujemy zaciêcie dzia³a
			///
			///@param reliability_range_first - zakres górny
			///
			///@param reliability_range_second - zakres dolny
			///
			void setReliabilityRange(float reliability_range_first, float reliability_range_second);

			///
			///Metoda zwraca dopuszczaln¹ iloœæ wyst¹pieñ uszkodzeñ
			///
			const unsigned getLimitAmountDamage() const;//m_limit_amount_damage

			///
			///Metoda ustawia dopuszczaln¹ iloœæ wyst¹pieñ uszkodzeñ
			///
			///@param limit_amount_damage - dopussczalna iloœæ wyst¹pieñ uszkodzeñ
			///
			void setLimitAmountDamage(unsigned limit_amount_damage);

			///
			///Metoda zwraca referencjê na obiekt klasy CLockWeapon - generator uszkodzeñ
			///
			CLockWeapon & getDamage();

			///
			///Metoda ustawia referencjê na obiekt klasy CLockWeapon - generator uszkodzeñ
			///
			///@param & damage - generator uszkodzeñ
			///
			void setDamage(CLockWeapon & damage);

			///
			///Metoda zwraca flagê, czy mo¿na i trzeba wygenerowaæ strza³ obiektu
			///
			bool Shoot();

			///
			///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void UpdateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuje logikê obiektu
			///
			///@param dt - czas
			///
			void Update(float dt);

		private:

			CEquipmentAmmoData		m_ammo_data;				//opakowanie funkcjonalnoœci dzia³a
			bool					m_ammo_loading;				//flaga, czy mo¿na prze³adowaæ amunicjê
			float					m_time_ammo_load_delay;		//czas potrzebny do prze³adowania amunicji
			bool					m_shot_enabled;				//flaga, czy mo¿na oddaæ strza³
			float					m_time_shot;				//czas trwania strza³u
			bool					m_shot_in_progress;			//flaga okreœlaj¹ca czy trwa wystrza³
			float					m_range_shot;				//zasiêg strza³u
			float					m_bullet_speed;				//prêdkoœæ pocisku - dzia³o decyduje
			int						m_barrel_count;				//iloœæ luf, które posiada dzia³o
			float					m_target_altitude;			//apogeum pu³apu - apogeum wysokoœci jak¹ mo¿e osi¹gn¹æ pocisk
			sf::Vector2f			m_explosion_emiter;			//po³o¿enia emitera eksplozji wystrza³u wzglêdem lufy
			float					m_ammo_time_delayed;		//czas opóŸnienia komunikatu uzupe³nienia amunicji - jako dana wejœciowa dla sf::Randomizer
			EGunState				m_gun_state;				//wyliczenie dla automatu stanów obiektu klasy CGun
			float					m_reliability;				//losowane prawdopodobieñstwo niezawodnoœci dzia³ania
			std::pair<float, float>	m_reliability_range;		//przedzia³ w zakresie którego definiujemy zaciêcie dzia³a < 0..1 >
			CLockWeapon				m_damage;					//generator uszkodzeñ
			float					m_process_time;				//czas procesu potrzebny do wyliczeñ
			unsigned				m_limit_amount_damage;		//dopuszczalna iloœæ uszkodzeñ, po którym nastêpuje stan serwisowy
			float					m_new_anim_speed;			//wyliczony wspó³czynnik prêdkoœci odtwarzania animacji
				
		private:

			//prywatna metoda aktualizuj¹ce stan obiektu (automat stanów)	
			void updateGunState(float dt);//uwaga, w tej metodzie obs³uga strza³u...

		   //prywatna metoda aktualizuje sk³adowe transformacji wzglêdem w³aœciciela
			void updateAmmoTransformation(float dt);

			//docelowo: poni¿sze opakowaæ do jakiegoœ AI (iddle...)
			float m_time_data;	//zmienna pomocznicza (waste)
			float m_time;		//zmienna pomocznicza (waste)
			float direction;	//zmienna pomocznicza (waste)

		};
	}//	namespace weapon
}//namespace equipment
#endif//H_GUN_JACK
