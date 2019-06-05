//  ____________________________________
// | Gun.cpp - class implementation     |
// | Jack Flower November 2010          |
// |____________________________________|
//

#include "Gun.h"
#include "../../../Logic/PhysicalManager.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/AnimationState.h"
#include "../../../Rendering/Displayable/Displayable.h"
#include "../../../Rendering/Animations/AnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Utilities/Utilities/Utilities.h"
#include "../../../Utilities/Random/CRandom.h"
#include <SFML/Window.hpp>

using namespace rendering::animation;
using namespace rendering::displayable;

namespace equipment
{
	namespace weapon
	{
		RTTI_IMPL(Gun, Actor);

		//Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
		Gun::Gun(const std::wstring & uniqueId)
		:
			Actor{ uniqueId },//konstruktor klasy bazowej
			m_ammo_data{},
			m_ammo_loading{ false },
			m_time_ammo_load_delay{ 0.f },
			m_shot_enabled{ false },
			m_time_shot{ 0.f },
			m_shot_in_progress{ false },
			m_range_shot{ 0.f },
			m_bullet_speed{ 0.f },
			m_barrel_count{ 1 },
			m_target_altitude{ 0.f },
			m_explosion_emiter{ 0.f, 0.f },
			m_ammo_time_delayed{ 0.0f },
			m_gun_state{ EGunState::GUN_DEFAULT },
			m_reliability{ 0.0f },
			m_reliability_range{ 0.0f, 0.0f },
			m_process_time{ 0.0f },
			m_limit_amount_damage{ 0 },
			//waste
			m_time_data{ 0.82f },	//zmienna pomocznicza (waste)
			m_time{ 0.0f },//zmienna pomocznicza (waste)
			direction{ 0.0f }//zmienna pomocznicza (waste)
		{
			//to do: layers
		}

		//Chroniony konstruktor kopiujący
		Gun::Gun(const Gun& GunCopy)
		:
			Actor(GunCopy),//konstruktor kopiujący klasy bazowej
			m_ammo_data{ GunCopy.m_ammo_data },
			m_ammo_loading{ GunCopy.m_ammo_loading },
			m_time_ammo_load_delay{ GunCopy.m_time_ammo_load_delay },
			m_shot_enabled{ GunCopy.m_shot_enabled },
			m_time_shot{ GunCopy.m_time_shot },
			m_shot_in_progress{ GunCopy.m_shot_in_progress },
			m_range_shot{ GunCopy.m_range_shot },
			m_bullet_speed{ GunCopy.m_bullet_speed },
			m_barrel_count{ GunCopy.m_barrel_count },
			m_target_altitude{ GunCopy.m_target_altitude },
			m_explosion_emiter{ GunCopy.m_explosion_emiter },
			m_ammo_time_delayed{ GunCopy.m_ammo_time_delayed },
			m_gun_state{ GunCopy.m_gun_state },
			m_reliability{ GunCopy.m_reliability },
			m_reliability_range{ GunCopy.m_reliability_range },
			m_process_time{ GunCopy.m_process_time },
			m_limit_amount_damage{ GunCopy.m_limit_amount_damage },
			//waste
			m_time_data{ GunCopy.m_time_data }, //zmienna pomocznicza (waste)
			m_time{ GunCopy.m_time }, //zmienna pomocznicza (waste)
			direction{ GunCopy.direction } //zmienna pomocznicza (waste)
		{
			//to do: layers
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		Gun::~Gun(void)
		{
			//~Actor()
			m_ammo_data;
			m_ammo_loading = false;
			m_time_ammo_load_delay = 0.0f;
			m_shot_enabled = false;
			m_time_shot = 0.0f;
			m_shot_in_progress = false;
			m_range_shot = 0.0f;
			m_bullet_speed = 0.0f;
			m_barrel_count = 0;
			m_target_altitude = 0.0f;
			m_explosion_emiter.x = 0.0f;
			m_explosion_emiter.y = 0.0f;
			m_ammo_time_delayed = 0.0f;
			m_gun_state = EGunState::GUN_DEFAULT;
			m_reliability = 0.0f;
			m_reliability_range.first = 0.0f;
			m_reliability_range.second = 0.0f;
			m_process_time = 0.0f;
			m_limit_amount_damage = 0;
			//waste
			m_time_data = 0.0f; //zmienna pomocznicza (waste)
			m_time = 0.0f; //zmienna pomocznicza (waste)
			direction = 0.0f; //zmienna pomocznicza (waste)
		}

		//Metoda zwraca typ obiektu /RTTI/
		std::string Gun::getType()
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca wskaźnik obiekt klasy Ammo
		Ammo *Gun::getAmmo()
		{
			return m_ammo_data.getAmmo();
		}

		//Metoda ustawia wskaźnik obiekt klasy Ammo
		void Gun::setAmmo(Ammo *ammo)
		{
			m_ammo_data.setAmmo(ammo);
		}

		//Metoda zwraca flagę, czy obiekt posiada magazynek na amunicję (amunicję)
		const bool Gun::getUseAmmo() const
		{
			return m_ammo_data.getUseEquipment();
		}

		//Metoda ustawia flagę, czy obiekt posiada magazynek na amunicję (amunicję)
		void Gun::setUseAmmo(bool use_ammo)
		{
			m_ammo_data.setUseEquipment(use_ammo);
		}

		//Metoda zwraca referencję na opakowanie danych dla transformacji
		CTransformation & Gun::getAmmoTransformed()
		{
			return m_ammo_data.getTransformed();
		}
		
		//Metoda ustawia referencję na opakowanie danych dla transformacji
		void Gun::setAmmoTransformed(CTransformation & ammo_transformation)
		{
			m_ammo_data.setTransformed(ammo_transformation);
		}

		//Metoda zwraca referencję na opakowanie funkcjonalności amunicji
		EquipmentAmmoData & Gun::getEquipmentAmmoData()
		{
			return m_ammo_data;
		}

		//Metoda ustawia referencję na opakowanie funkcjonalności amunicji
		void Gun::setEquipmentAmmoData(EquipmentAmmoData & ammo_data)
		{
			m_ammo_data = ammo_data;
		}

		//Metoda zwraca flagę, czy można przeładować amunicję
		const bool Gun::getAmmoLoading() const
		{
			return m_ammo_loading;
		}

		//Metoda ustawia flagę, czy można przeładować amunicję
		void Gun::setAmmoLoading(bool ammo_loading)
		{
			m_ammo_loading = ammo_loading;
		}

		//Metoda zwraca czas przeładowania amunicji
		const float Gun::getTimeAmmoLoadDelay() const
		{
			return m_time_ammo_load_delay;
		}

		//Metoda ustawia czas przeładowania amunicji
		void Gun::setTimeAmmoLoadDelay(float time_ammo_load_delay)
		{
			m_time_ammo_load_delay = time_ammo_load_delay;
		}

		//Metoda zwraca flagę, czy można oddać strzał
		const bool Gun::getShotEnabled() const
		{
			return m_shot_enabled;
		}

		//Metoda ustawia flagę, czy można oddać strzał
		void Gun::setShotEnabled(bool shot_enabled)
		{
			m_shot_enabled = shot_enabled;
		}

		//Metoda zwraca czas trwania wystrzału
		const float Gun::getTimeShot() const
		{
			return m_time_shot;
		}

		//Metoda ustawia czas trwania animacji wystrzału
		void Gun::setTimeShot(float time_shot)
		{
			m_time_shot = time_shot;
		}

		//Metoda zwraca flagę czy trwa wystrzał
		const bool Gun::getShotInProgress() const
		{
			return m_shot_in_progress;
		}

		//Metoda ustawia flagę czy trwa wystrzał
		void Gun::setShotInProgress(bool shot_in_progress)
		{
			m_shot_in_progress = shot_in_progress;
		}

		//Metoda zwraca prędkość pocisku wystrzelonego z działa
		const float Gun::getBulletSpeed() const
		{
			return m_bullet_speed;
		}

		//Metoda ustawia prędkość pocisku wystrzelonego z działa
		void Gun::setBulletSpeed(const float bullet_speed)
		{
			m_bullet_speed = bullet_speed;
		}
		
		//Metoda zwraca zasięg strzału
		const float Gun::getRangeShot() const
		{
			return m_range_shot;
		}

		//Metoda ustawia zasięg strzału
		void Gun::setRangeShot(float range_shot)
		{
			if (m_range_shot < 0) return;
			m_range_shot = range_shot;
		}

		//Metoda zwraca ilość luf działa
		const int Gun::getBarrelCount() const
		{
			return m_barrel_count;
		}

		//Metoda ustawia ilość luf działa
		void Gun::setBarrelCount(int barrel_count)
		{
			if (m_barrel_count <= 0) m_barrel_count = 1;	//działo musi mieć przynajmniej jedną lufę
			m_barrel_count = barrel_count;
		}

		//Metoda zwraca apogeum wysokości lotu balistycznego pocisku
		const float Gun::getTargetAltitude() const
		{
			return m_target_altitude;
		}

		//Metoda ustawia apogeum wysokości lotu balistycznego pocisku
		void Gun::setTargetAltitude(float target_altitude)
		{
			m_target_altitude = target_altitude;
		}

		//Metoda zwraca stałą referencję na wektor położenia emitera eksplozji względem lufy
		const sf::Vector2f & Gun::getExplosionEmiter() const
		{
			return m_explosion_emiter;
		}

		//Metoda ustawia położenie emitera eksplozji względem lufy - wektor
		void Gun::setExplosionEmiter(sf::Vector2f & explosion_emiter)
		{
			m_explosion_emiter = explosion_emiter;
		}

		//Metoda ustawia położenie emitera eksplozji względem lufy - współrzędne
		void Gun::setExplosionEmiter(float explosion_emiter_x, float explosion_emiter_y)
		{
			m_explosion_emiter.x = explosion_emiter_x;
			m_explosion_emiter.y = explosion_emiter_y;
		}
		
		//Metoda sprawdza, czy wystarczy amunicji w magazunku na strzał z wszystkich luf
		const int Gun::getBulletPerSoot()
		{
			int bullet_per_shoot = 0;//pesymistycznie...

			if (m_ammo_data.getAmmo())
			{
				if (m_ammo_data.getAmmo()->getAmmo() >= m_barrel_count)	//jeśli amunicji w magazynku jest więcej lub tyle samo co luf
					bullet_per_shoot = m_barrel_count;					//strzelamy z wszystkich luf
				else													//w przeciwnym wypadku
					bullet_per_shoot = m_ammo_data.getAmmo()->getAmmo();//strzelamy tym co pozostało
			}
			return bullet_per_shoot;
		}

		//Metoda zwraca czas opóźnienia komunikatu uzupełnienia amunicji
		const float Gun::getAmmoTimeDelayed() const
		{
			return m_ammo_time_delayed;
		}

		//Metoda ustawia czas opóźnienia komunikatu uzupełnienia amunicji
		void Gun::setAmmoTimeDelayed(float ammo_time_delayed)
		{
			m_ammo_time_delayed = ammo_time_delayed;
		}

		//Metoda zaopatruje obiekt w amunicję z zewnętrznego źródła
		void Gun::supplyAmmunition(int & ammo_out)
		{
			//logika zasila magazynek z amunicją w amunicję pobieraną
			//z zewnątrz obliczając jej ilość, biorąc pod uwagę pojemność
			//magazynka oraz bilansuje amunicję z zewnątrz...
			if (m_ammo_data.getAmmo())
				m_ammo_data.getAmmo()->supplyAmmunition(ammo_out);
		}

		//Metoda zwraca referencję na przedział liczb, w zakresie którego definiujemy zacięcie działa
		const std::pair<float, float> & Gun::getReliabilityRange() const
		{
			return m_reliability_range;
		}

		//Metoda ustawia przedział liczb, w zakresie którego definiujemy zacięcie działa
		void Gun::setReliabilityRange(float reliability_range_first, float reliability_range_second)
		{
			m_reliability_range.first = reliability_range_first;
			m_reliability_range.second = reliability_range_second;
		}

		//Metoda zwraca dopuszczalną ilość wystąpień uszkodzeń
		const unsigned Gun::getLimitAmountDamage() const
		{
			return m_limit_amount_damage;
		}

		//Metoda ustawia dopuszczalną ilość wystąpień uszkodzeń
		void Gun::setLimitAmountDamage(unsigned limit_amount_damage)
		{
			m_limit_amount_damage = limit_amount_damage;
		}

		//Metoda zwraca referencję na obiekt klasy LockWeapon - generator uszkodzeń
		LockWeapon & Gun::getDamage()
		{
			return m_damage;
		}

		//Metoda ustawia referencję na obiekt klasy LockWeapon - generator uszkodzeń
		void Gun::setDamage(LockWeapon & damage)
		{
			m_damage = damage;
		}

		//Metoda zwraca flagę, czy można i trzeba wygenerować strzał obiektu
		bool Gun::shoot()
		{
			//jeżeli obiekt nie jest w trybie serwisowym
			if (m_gun_state != EGunState::GUN_SERVICE)
			{
				//logika kurka spustowego broni (cyngiel)
				if (m_ammo_data.getAmmo())
				{
					//Jeśli mamy amunicję i działo nie jest w trybie ładowania
					if (m_ammo_data.getAmmo()->getAmmo() > 0 && !m_ammo_loading)
						m_shot_enabled = true;
					else
						m_shot_enabled = false;
				}
				//jeśli nastąpiło uszkodzenie i jest amunicja
				if (m_damage.getDamage() && m_ammo_data.getAmmo()->getAmmo() > 0)
				{
					m_shot_enabled = false;
					m_gun_state = EGunState::GUN_DAMAGE;
					//sprawdzamy, czy został wyczerpany limit uszkodzeń
					if (m_damage.getDamageCount() >= m_limit_amount_damage)
						m_gun_state = EGunState::GUN_SERVICE;//stan serwisowy
				}
			}
			return m_shot_enabled;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		void Gun::updateAnimations(float dt)
		{
			switch (m_gun_state)
			{
			case EGunState::GUN_DEFAULT:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyDefaultAnim());
					setAnimationHead(p_anim_set->getGunHeadDefaultAnim());
					//animacja head odtwarza się w pętli
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case EGunState::GUN_SHOOT:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyShootAnim());
					setAnimationHead(p_anim_set->getGunHeadShootAnim());
					//animacja head odtwarza się jeden raz
					getDisplayableHead()->getAnimationState()->setLooped(false);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(false);
				}
				break;
			}
			case EGunState::GUN_AMMO_LOADING:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyAmmoLoadingAnim());
					setAnimationHead(p_anim_set->getGunHeadAmmoLoadingAnim());
					//animacja head odtwarza się jeden raz
					getDisplayableHead()->getAnimationState()->setLooped(false);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(false);
				}
				break;
			}
			case EGunState::GUN_AMMO_EMPTY:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyAmmoEmptyAnim());
					setAnimationHead(p_anim_set->getGunHeadAmmoEmptyAnim());
					//animacja head odtwarza się w pętli
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case EGunState::GUN_DAMAGE:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyDamageAnim());
					setAnimationHead(p_anim_set->getGunHeadDamageAnim());
					//animacja head odtwarza się w pętli
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case EGunState::GUN_SERVICE:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyServiceAnim());
					setAnimationHead(p_anim_set->getGunHeadServiceAnim());
					//animacja head odtwarza się w pętli
					getDisplayableHead()->getAnimationState()->setLooped(true);
					getDisplayableHeadShadow()->getAnimationState()->setLooped(true);
				}
				break;
			}
			case EGunState::GUN_DEATH:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->getGunBodyDeathAnim());
					setAnimationHead(p_anim_set->getGunHeadDeathAnim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizuje logikę obiektu
		void Gun::update(float dt)
		{
			//aktualizacja shadow engine
			Physical::updateShadow(dt);

			//metoda aktualizuje składowe transformacji względem włąściciela
			updateAmmoTransformation(dt);
			
			//próba oddania strzału
			shoot();
			
			//aktualizacja stanów
			updateGunState(dt);

			//aktualizacja animacji
			updateAnimations(dt);

			//c  h  a  o  s  - testy
			//
			m_time += dt;
			if(m_time > m_time_data)
			{ 
				direction = gRandom.Rndnf();
				m_time = 0.0f;
			}
			float radius_offset = gRandom.Rndf(0.62f);
			setRotationHead(getRotationHead() + (radius_offset*direction));
			//
			//c  h  a  o  s  - testy
		}

		//prywatna metoda aktualizujące stan obiektu (automat stanów)	
		void Gun::updateGunState(float dt)
		{
			//obiekt nie jest w stanie serwisowym
			if (m_gun_state != EGunState::GUN_SERVICE)
			{
				//obiekt nie ma usterek technicznych
				if (m_gun_state != EGunState::GUN_DAMAGE)
				{
					//jeśli można oddać strzał - jest amunicja i nie trwa ładowanie
					if (m_shot_enabled)
					{
						//p o c i s k
						//CreateBullet();

						//stan trwania procesu wystrzału 
						m_gun_state = EGunState::GUN_SHOOT;

						//dostosowanie prędkości odtwarzania animacji dla strzału
						setAnimSpeedHead(Physical::getCalcualtedAnimSpeed(m_time_shot));

						//bilans amunicji w magazynku
						m_ammo_data.getAmmo()->setAmmo(m_ammo_data.getAmmo()->getAmmo() - getBulletPerSoot());

						if (m_ammo_data.getAmmo()->getAmmo() <= 0)	//jeśli ilość amunicji jest ujemna lub zero
							m_ammo_data.getAmmo()->setAmmo(0);		//zerujemy ilość amunicji	

						m_ammo_loading = true;		//trzeba przeładować działo
						m_shot_in_progress = true;	//trwa wystrzał
						m_shot_enabled = false;		//nie można teraz strzelać
						m_process_time = 0.0f;		//reset zegara
					}

					//jeśli trwa strzał
					if (getShotInProgress())
					{
						//zliczam czas trwania strzału
						m_process_time += dt;

						//minął czas trwania strzału
						if (m_process_time >= m_time_shot)
						{
							//stan trwania ładowania amunicji
							m_gun_state = EGunState::GUN_AMMO_LOADING;
							//przywróć czas ekspozycji klatki animacji na wartość zapamiętaną
							setAnimSpeedHead(getStoredAnimSpeedHead());

							//dostosowanie prędkości odtwarzania animacji ładowania amunicji
							setAnimSpeedHead(Physical::getCalcualtedAnimSpeed(m_time_ammo_load_delay));

							m_ammo_loading = true;		//ustawiamy flagę, że trzeba przeładować działo
							m_shot_in_progress = false;	//czas strzału się zakończył
							m_shot_enabled = false;		//nie można teraz strzelać
							m_process_time = 0.0f;		//reset zegara
						}
					}

					//jeśli można przeładować działo i nie trwa strzał
					if (m_ammo_loading && !m_shot_in_progress)
					{
						//zliczam czas
						m_process_time += dt;

						//minął czas przeładowania działa
						if (m_process_time >= m_time_ammo_load_delay)
						{
							//stan default
							m_gun_state = EGunState::GUN_DEFAULT;
							//przywróć czas ekspozycji klatki animacji na wartość zapamiętaną
							setAnimSpeedHead(getStoredAnimSpeedHead());

							m_ammo_loading = false;		//już nie można przeładowywać działa
							m_process_time = 0.0f;		//reset zegara
						}
					}

					//jeśli nie ma amunicji
					if (m_ammo_data.getAmmo()->getAmmo() <= 0)
					{
						//stan braku amunicji
						m_gun_state = EGunState::GUN_AMMO_EMPTY;

						//przywróć czas ekspozycji klatki animacji na wartość zapamiętaną
						setAnimSpeedHead(getStoredAnimSpeedHead());

						m_ammo_loading = true;	//ustawiamy flagę, że trzeba przeładować działo
						m_shot_enabled = false;	//nie można teraz strzelać
						m_process_time = 0.0f;	//reset zegara
					}
				}
			}

			//stan uszkodzenia (zacięcia) działa...
			if (m_gun_state == EGunState::GUN_DAMAGE)
			{
				//zliczam czas trwania uszkodzenia
				m_process_time += dt;

				//minął czas trwania strzału
				if (m_process_time >= m_damage.getDurationDamage())//pobrać z factory
				{
					m_gun_state = EGunState::GUN_DEFAULT;
					restoreColorHead();
				}
			}

			//stan serwosowy - wymaga interwencji
			if (m_gun_state == EGunState::GUN_SERVICE)
			{
				//czekam na serwis...
				//stan serwisowy wymaga interwencji zewnętrznej
				//obiekt, posiadający logikę interwencji
				//powinien posiadać także magazynek z amunicją,
				//a na obiekcie, który serwisuje, wywołać jego
				//metodę: void supplyAmmunition(int & ammo_out);
				//etc...
			}
		}

		//metoda aktualizuje składowe transformacji względem właściciela
		void Gun::updateAmmoTransformation(float dt)
		{
			m_ammo_data.getTransformed().Transform(this, m_ammo_data.getAmmo());
		}
	}//namespace weapon
}//namespace equipment
