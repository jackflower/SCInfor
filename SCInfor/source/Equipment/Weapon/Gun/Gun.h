//  ____________________________________
// | Gun.h - class definition           |
// | Jack Flower November 2010          |
// |____________________________________|
//

#ifndef H_GUN_JACK
#define H_GUN_JACK

#include "../../../Logic/Actor/Actor.h"
#include "LockWeapon/LockWeapon.h"
#include "../../EquipmentData/EquipmentAmmoData.h"
#include <SFML/System/Vector2.hpp>
#include "../Ammo/Ammo.h"
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
		///Klasa reprezentuje logikę strzelającego działa
		///
		class Gun : public Actor
		{
			RTTI_DECL;
		
			///
			///Deklaracja przyjaźni
			///
			friend class CPhysicalManager;

			//Aby uzyskać obiekt Gun, należy wywołać CPhysicalManager::CreateGun();

		protected:

			///
			///Chroniony konstruktor domyślny - używany wyłącznie przez CPhysicalManager
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			Gun(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param GunCopy - stała referecnaj na obiekt klasy Gun
			///
			Gun(const Gun & GunCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
			///
			~Gun(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			std::string getType();
			
			///
			///Metoda zwraca wskaźnik obiekt klasy Ammo
			///
			Ammo *getAmmo();

			///
			///Metoda ustawia wskaźnik obiekt klasy Ammo
			///
			///@param *ammo - wskaźnik obiekt klasy Ammo
			///
			void setAmmo(Ammo *ammo);

			///
			///Metoda zwraca flagę, czy obiekt posiada magazynek na amunicję (amunicję)
			///
			const bool getUseAmmo() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada magazynek na amunicję (amunicję)
			///
			///@param use_ammo - flaga, czy obiekt posiada magazynek na amunicję (amunicję)
			///
			void setUseAmmo(bool use_ammo);

			///
			///Metoda zwraca referencję na opakowanie danych dla transformacji
			///
			CTransformation & getAmmoTransformed();

			///
			///Metoda ustawia referencję na opakowanie danych dla transformacji
			///
			///@param & ammo_transformation - referencja na obiekt klasy CTransformation
			///
			void setAmmoTransformed(CTransformation & ammo_transformation);

			///
			///Metoda zwraca referencję na opakowanie funkcjonalności amunicji
			///
			EquipmentAmmoData & getEquipmentAmmoData();

			///
			///Metoda ustawia referencję na opakowanie funkcjonalności amunicji
			///
			///@param & ammo_data - referencja na obiekt klasy EquipmentAmmoData
			///
			void setEquipmentAmmoData(EquipmentAmmoData & ammo_data);

			///
			///Metoda zwraca flagę, czy można przeładować amunicję
			///
			const bool getAmmoLoading() const;

			///
			///Metoda ustawia flagę, czy można przeładować amunicję
			///
			///@param ammo_loading - flaga, czy można przeładować amunicję
			///
			void setAmmoLoading(bool ammo_loading);

			///
			///Metoda zwraca czas przeładowania amunicji
			///
			const float getTimeAmmoLoadDelay() const;

			///
			///Metoda ustawia czas przeładowania amunicji
			///
			///@param time_ammo_load_delay - czas porzebny do przeładowania amunicji
			///
			void setTimeAmmoLoadDelay(float time_ammo_load_delay);

			///
			///Metoda zwraca flagę, czy można oddać strzał
			///
			const bool getShotEnabled() const;

			///
			///Metoda ustawia flagę, czy można oddać strzał
			///
			///@param shot_enabled - flaga, czy można oddać strzał
			///
			void setShotEnabled(bool shot_enabled);

			///
			///Metoda zwraca czas trwania wystrzału
			///
			const float getTimeShot() const;

			///
			///Metoda ustawia czas trwania animacji wystrzału
			///
			///@param time_shot - czas trwania strzału
			///
			void setTimeShot(float time_shot);

			///
			///Metoda zwraca flagę czy trwa wystrzał
			///
			const bool getShotInProgress() const;

			///
			///Metoda ustawia flagę, czy trwa wystrzał
			///
			///@param shot_in_progress - flaga określająca czy trwa wystrzał
			///
			void setShotInProgress(bool shot_in_progress);

			///
			///Metoda zwraca prędkość pocisku wystrzelonego z działa
			///
			const float getBulletSpeed() const;

			///
			///Metoda ustawia prędkość pocisku wystrzelonego z działa
			///
			///@param bullet_speed - prędkość pocisku wystrzelonego z działa
			///
			void setBulletSpeed(const float bullet_speed);
			
			///
			///Metoda zwraca zasięg strzału
			///
			const float getRangeShot() const;

			///
			///Metoda ustawia zasięg strzału
			///
			///@param range_shot - zasięg strzału
			///
			void setRangeShot(float range_shot);
			
			///
			///Metoda zwraca ilość luf działa
			///
			const int getBarrelCount() const;

			///
			///Metoda ustawia ilość luf działa
			///
			///@param barrel_count - ilość luf, które posiada działo
			///
			void setBarrelCount(int barrel_count);

			///
			///Metoda zwraca apogeum wysokości lotu balistycznego pocisku
			///
			const float getTargetAltitude() const;

			///
			///Metoda ustawia apogeum wysokości lotu balistycznego pocisku
			///
			///@param target_altitude - apogeum wysokości lotu balistycznego pocisku
			///
			void setTargetAltitude(float target_altitude);

			///
			///Metoda zwraca stałą referencję na wektor położenia emitera eksplozji względem lufy
			///
			const sf::Vector2f & getExplosionEmiter() const;

			///
			///Metoda ustawia położenie emitera eksplozji względem lufy - wektor
			///
			///@param &explosion_emiter - wektor - stała referencja na wartość przesunięcia emitera eksplozji
			///
			void setExplosionEmiter(sf::Vector2f & explosion_emiter);

			///
			///Metoda ustawia położenie emitera eksplozji względem lufy - współrzędne
			///
			///@param explosion_emiter_x - składowa X przesunięcia emitera eksplozji
			///
			///@param explosion_emiter_y - składowa Y przesunięcia emitera eksplozji
			///
			void setExplosionEmiter(float explosion_emiter_x, float explosion_emiter_y);

			///
			///Metoda sprawdza, czy wystarczy amunicji w magazunku na strzał z wszystkich luf
			///
			const int getBulletPerSoot();

			///
			///Metoda zwraca czas opóźnienia komunikatu uzupełnienia amunicji
			///
			const float getAmmoTimeDelayed() const;

			///
			///Metoda ustawia czas opóźnienia komunikatu uzupełnienia amunicji
			///
			///@param ammo_time_delayed - czas opóźnienia komunikatu uzupełnienia amunicji
			///
			void setAmmoTimeDelayed(float ammo_time_delayed);

			///
			///Metoda zaopatruje obiekt w amunicję z zewnętrznego źródła
			///
			///@param & ammo_out - referencja na amunicję - zewnętrzne źródło aminicji
			///
			void supplyAmmunition(int & ammo_out);

			///
			///Metoda zwraca referencję na przedział liczb, w zakresie którego definiujemy zacięcie działa
			///
			const std::pair<float, float> & getReliabilityRange() const;

			///
			///Metoda ustawia przedział liczb, w zakresie którego definiujemy zacięcie działa
			///
			///@param reliability_range_first - zakres górny
			///
			///@param reliability_range_second - zakres dolny
			///
			void setReliabilityRange(float reliability_range_first, float reliability_range_second);

			///
			///Metoda zwraca dopuszczalną ilość wystąpień uszkodzeń
			///
			const unsigned getLimitAmountDamage() const;//m_limit_amount_damage

			///
			///Metoda ustawia dopuszczalną ilość wystąpień uszkodzeń
			///
			///@param limit_amount_damage - dopussczalna ilość wystąpień uszkodzeń
			///
			void setLimitAmountDamage(unsigned limit_amount_damage);

			///
			///Metoda zwraca referencję na obiekt klasy LockWeapon - generator uszkodzeń
			///
			LockWeapon & getDamage();

			///
			///Metoda ustawia referencję na obiekt klasy LockWeapon - generator uszkodzeń
			///
			///@param & damage - generator uszkodzeń
			///
			void setDamage(LockWeapon & damage);

			///
			///Metoda zwraca flagę, czy można i trzeba wygenerować strzał obiektu
			///
			bool shoot();

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuje logikę obiektu
			///
			///@param dt - czas
			///
			void update(float dt);

		private:

			EquipmentAmmoData m_ammo_data; //opakowanie funkcjonalności działa
			bool m_ammo_loading; //flaga, czy można przeładować amunicję
			float m_time_ammo_load_delay; //czas potrzebny do przeładowania amunicji
			bool m_shot_enabled; //flaga, czy można oddać strzał
			float m_time_shot; //czas trwania strzału
			bool m_shot_in_progress; //flaga określająca czy trwa wystrzał
			float m_range_shot; //zasięg strzału
			float m_bullet_speed; //prędkość pocisku - działo decyduje
			int m_barrel_count; //ilość luf, które posiada działo
			float m_target_altitude; //apogeum pułapu - apogeum wysokości jaką może osiągnąć pocisk
			sf::Vector2f m_explosion_emiter; //położenia emitera eksplozji wystrzału względem lufy
			float m_ammo_time_delayed; //czas opóźnienia komunikatu uzupełnienia amunicji - jako dana wejściowa dla sf::Randomizer
			EGunState m_gun_state; //wyliczenie dla automatu stanów obiektu klasy Gun
			float m_reliability; //losowane prawdopodobieństwo niezawodności działania
			std::pair<float, float>	m_reliability_range; //przedział w zakresie którego definiujemy zacięcie działa < 0..1 >
			LockWeapon m_damage; //generator uszkodzeń
			float m_process_time; //czas procesu potrzebny do wyliczeń
			unsigned m_limit_amount_damage; //dopuszczalna ilość uszkodzeń, po którym następuje stan serwisowy
			float m_new_anim_speed; //wyliczony współczynnik prędkości odtwarzania animacji
				
		private:

			//prywatna metoda aktualizujące stan obiektu (automat stanów)	
			void updateGunState(float dt);//uwaga, w tej metodzie obsługa strzału...

		   //prywatna metoda aktualizuje składowe transformacji względem właściciela
			void updateAmmoTransformation(float dt);

			//docelowo: poniższe opakować do jakiegoś AI (iddle...)
			float m_time_data; //zmienna pomocznicza (waste)
			float m_time; //zmienna pomocznicza (waste)
			float direction; //zmienna pomocznicza (waste)

		};
	}//	namespace weapon
}//namespace equipment
#endif//H_GUN_JACK
