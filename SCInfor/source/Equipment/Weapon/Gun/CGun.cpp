//  _____________________________________
// | CGun.cpp - class implementation     |
// | Jack Flower November 2010           |
// |_____________________________________|
//

#include "CGun.h"
#include "../../../Logic/CPhysicalManager.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"
#include "../../../Rendering/Animations/CAnimSet.h"
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
		RTTI_IMPL(CGun, CActor);

		//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		CGun::CGun(const std::wstring& uniqueId)
		:
			CActor					(uniqueId),//konstruktor klasy bazowej
			m_ammo_data				(),
			m_ammo_loading			(false),
			m_time_ammo_load_delay	(0.f),
			m_shot_enabled			(false),
			m_time_shot				(0.f),
			m_shot_in_progress		(false),
			m_range_shot			(0.f),
			m_bullet_speed			(0.f),
			m_barrel_count			(1),
			m_target_altitude		(0.f),
			m_explosion_emiter		(0.f, 0.f),
			m_ammo_time_delayed		(0.0f),
			m_gun_state				(GUN_DEFAULT),
			m_reliability			(0.0f),
			m_reliability_range		(0.0f, 0.0f),
			m_process_time			(0.0f),
			m_limit_amount_damage	(0),
			//waste
			m_time_data				(0.82f),	//zmienna pomocznicza (waste)
			m_time					(0.0),		//zmienna pomocznicza (waste)
			direction				(0.0f)		//zmienna pomocznicza (waste)
		{
			//dodaæ layer's...
		}

		//Chroniony konstruktor kopiuj¹cy
		CGun::CGun(const CGun& CGunCopy)
		:
			CActor					(CGunCopy),//konstruktor kopiuj¹cy klasy bazowej
			m_ammo_data				(CGunCopy.m_ammo_data),
			m_ammo_loading			(CGunCopy.m_ammo_loading),
			m_time_ammo_load_delay	(CGunCopy.m_time_ammo_load_delay),
			m_shot_enabled			(CGunCopy.m_shot_enabled),
			m_time_shot				(CGunCopy.m_time_shot),
			m_shot_in_progress		(CGunCopy.m_shot_in_progress),
			m_range_shot			(CGunCopy.m_range_shot),
			m_bullet_speed			(CGunCopy.m_bullet_speed),
			m_barrel_count			(CGunCopy.m_barrel_count),
			m_target_altitude		(CGunCopy.m_target_altitude),
			m_explosion_emiter		(CGunCopy.m_explosion_emiter),
			m_ammo_time_delayed		(CGunCopy.m_ammo_time_delayed),
			m_gun_state				(CGunCopy.m_gun_state),
			m_reliability			(CGunCopy.m_reliability),
			m_reliability_range		(CGunCopy.m_reliability_range),
			m_process_time			(CGunCopy.m_process_time),
			m_limit_amount_damage	(CGunCopy.m_limit_amount_damage),
			//waste
			m_time_data				(CGunCopy.m_time_data),	//zmienna pomocznicza (waste)
			m_time					(CGunCopy.m_time),		//zmienna pomocznicza (waste)
			direction				(CGunCopy.direction)	//zmienna pomocznicza (waste)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CGun::~CGun(void)
		{
			//CActor					not edit
			//m_ammo_data				not edit
			m_ammo_loading				= false;
			m_time_ammo_load_delay		= 0.0f;
			m_shot_enabled				= false;
			m_time_shot					= 0.0f;
			m_shot_in_progress			= false;
			m_range_shot				= 0.0f;
			m_bullet_speed				= 0.0f;
			m_barrel_count				= 0;
			m_target_altitude			= 0.0f;
			m_explosion_emiter.x		= 0.0f;
			m_explosion_emiter.y		= 0.0f;
			m_ammo_time_delayed			= 0.0f;
			m_gun_state					= GUN_DEFAULT;
			m_reliability				= 0.0f;
			m_reliability_range.first	= 0.0f;
			m_reliability_range.second	= 0.0f;
			m_process_time				= 0.0f;
			m_limit_amount_damage		= 0;
			//waste
			m_time_data					= 0.0f;	//zmienna pomocznicza (waste)
			m_time						= 0.0f;	//zmienna pomocznicza (waste)
			direction					= 0.0f;	//zmienna pomocznicza (waste)
		}

		//Metoda zwraca typ obiektu /RTTI/
		std::string CGun::GetType()
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca wskaŸnik obiekt klasy Ammo
		Ammo *CGun::getAmmo()
		{
			return m_ammo_data.getAmmo();
		}

		//Metoda ustawia wskaŸnik obiekt klasy Ammo
		void CGun::setAmmo(Ammo * ammo)
		{
			m_ammo_data.setAmmo(ammo);
		}

		//Metoda zwraca flagê, czy obiekt posiada magazynek na amunicjê (amunicjê)
		const bool CGun::getUseAmmo() const
		{
			return m_ammo_data.getUseEquipment();
		}

		//Metoda ustawia flagê, czy obiekt posiada magazynek na amunicjê (amunicjê)
		void CGun::setUseAmmo(bool use_ammo)
		{
			m_ammo_data.setUseEquipment(use_ammo);
		}

		//Metoda zwraca referencjê na opakowanie danych dla transformacji
		CTransformation & CGun::getAmmoTransformed()
		{
			return m_ammo_data.getTransformed();
		}
		
		//Metoda ustawia referencjê na opakowanie danych dla transformacji
		void CGun::setAmmoTransformed(CTransformation & ammo_transformation)
		{
			m_ammo_data.setTransformed(ammo_transformation);
		}

		//Metoda zwraca referencjê na opakowanie funkcjonalnoœci amunicji
		EquipmentAmmoData & CGun::getEquipmentAmmoData()
		{
			return m_ammo_data;
		}

		//Metoda ustawia referencjê na opakowanie funkcjonalnoœci amunicji
		void CGun::setEquipmentAmmoData(EquipmentAmmoData & ammo_data)
		{
			m_ammo_data = ammo_data;
		}

		//Metoda zwraca flagê, czy mo¿na prze³adowaæ amunicjê
		const bool CGun::GetAmmoLoading() const
		{
			return m_ammo_loading;
		}

		//Metoda ustawia flagê, czy mo¿na prze³adowaæ amunicjê
		void CGun::SetAmmoLoading(bool ammo_loading)
		{
			m_ammo_loading = ammo_loading;
		}

		//Metoda zwraca czas prze³adowania amunicji
		const float CGun::GetTimeAmmoLoadDelay() const
		{
			return m_time_ammo_load_delay;
		}

		//Metoda ustawia czas prze³adowania amunicji
		void CGun::SetTimeAmmoLoadDelay(float time_ammo_load_delay)
		{
			m_time_ammo_load_delay = time_ammo_load_delay;
		}

		//Metoda zwraca flagê, czy mo¿na oddaæ strza³
		const bool CGun::GetShotEnabled() const
		{
			return m_shot_enabled;
		}

		//Metoda ustawia flagê, czy mo¿na oddaæ strza³
		void CGun::SetShotEnabled(bool shot_enabled)
		{
			m_shot_enabled = shot_enabled;
		}

		//Metoda zwraca czas trwania wystrza³u
		const float CGun::GetTimeShot() const
		{
			return m_time_shot;
		}

		//Metoda ustawia czas trwania animacji wystrza³u
		void CGun::SetTimeShot(float time_shot)
		{
			m_time_shot = time_shot;
		}

		//Metoda zwraca flagê czy trwa wystrza³
		const bool CGun::GetShotInProgress() const
		{
			return m_shot_in_progress;
		}

		//Metoda ustawia flagê czy trwa wystrza³
		void CGun::SetShotInProgress(bool shot_in_progress)
		{
			m_shot_in_progress = shot_in_progress;
		}

		//Metoda zwraca prêdkoœæ pocisku wystrzelonego z dzia³a
		const float CGun::GetBulletSpeed() const
		{
			return m_bullet_speed;
		}

		//Metoda ustawia prêdkoœæ pocisku wystrzelonego z dzia³a
		void CGun::SetBulletSpeed(const float bullet_speed)
		{
			m_bullet_speed = bullet_speed;
		}
		
		//Metoda zwraca zasiêg strza³u
		const float CGun::GetRangeShot() const
		{
			return m_range_shot;
		}

		//Metoda ustawia zasiêg strza³u
		void CGun::SetRangeShot(float range_shot)
		{
			if (m_range_shot < 0) return;
			m_range_shot = range_shot;
		}

		//Metoda zwraca iloœæ luf dzia³a
		const int CGun::GetBarrelCount() const
		{
			return m_barrel_count;
		}

		//Metoda ustawia iloœæ luf dzia³a
		void CGun::SetBarrelCount(int barrel_count)
		{
			if (m_barrel_count <= 0) m_barrel_count = 1;	//dzia³o musi mieæ przynajmniej jedn¹ lufê
			m_barrel_count = barrel_count;
		}

		//Metoda zwraca apogeum wysokoœci lotu balistycznego pocisku
		const float CGun::GetTargetAltitude() const
		{
			return m_target_altitude;
		}

		//Metoda ustawia apogeum wysokoœci lotu balistycznego pocisku
		void CGun::SetTargetAltitude(float target_altitude)
		{
			m_target_altitude = target_altitude;
		}

		//Metoda zwraca sta³¹ referencjê na wektor po³o¿enia emitera eksplozji wzglêdem lufy
		const sf::Vector2f& CGun::GetExplosionEmiter() const
		{
			return m_explosion_emiter;
		}

		//Metoda ustawia po³o¿enie emitera eksplozji wzglêdem lufy - wektor
		void CGun::SetExplosionEmiter(sf::Vector2f& explosion_emiter)
		{
			m_explosion_emiter = explosion_emiter;
		}

		//Metoda ustawia po³o¿enie emitera eksplozji wzglêdem lufy - wspó³rzêdne
		void CGun::SetExplosionEmiter(float explosion_emiter_x, float explosion_emiter_y)
		{
			m_explosion_emiter.x = explosion_emiter_x;
			m_explosion_emiter.y = explosion_emiter_y;
		}
		
		//Metoda sprawdza, czy wystarczy amunicji w magazunku na strza³ z wszystkich luf
		const int CGun::GetBulletPerSoot()
		{
			int bullet_per_shoot = 0;//pesymistycznie...

			if (m_ammo_data.getAmmo())
			{
				if (m_ammo_data.getAmmo()->getAmmo() >= m_barrel_count)	//jeœli amunicji w magazynku jest wiêcej lub tyle samo co luf
					bullet_per_shoot = m_barrel_count;					//strzelamy z wszystkich luf
				else													//w przeciwnym wypadku
					bullet_per_shoot = m_ammo_data.getAmmo()->getAmmo();//strzelamy tym co pozosta³o
			}
			return bullet_per_shoot;
		}

		//Metoda zwraca czas opóŸnienia komunikatu uzupe³nienia amunicji
		const float CGun::GetAmmoTimeDelayed() const
		{
			return m_ammo_time_delayed;
		}

		//Metoda ustawia czas opóŸnienia komunikatu uzupe³nienia amunicji
		void CGun::SetAmmoTimeDelayed(float ammo_time_delayed)
		{
			m_ammo_time_delayed = ammo_time_delayed;
		}

		//Metoda zaopatruje obiekt w amunicjê z zewnêtrznego Ÿród³a
		void CGun::supplyAmmunition(int & ammo_out)
		{
			//logika zasila magazynek z amunicj¹ w amunicjê pobieran¹
			//z zewn¹trz obliczaj¹c jej iloœæ, bior¹c pod uwagê pojemnoœæ
			//magazynka oraz bilansuje amunicjê z zewn¹trz...
			if (m_ammo_data.getAmmo())
				m_ammo_data.getAmmo()->supplyAmmunition(ammo_out);
		}

		//Metoda zwraca referencjê na przedzia³ liczb, w zakresie którego definiujemy zaciêcie dzia³a
		const std::pair<float, float> & CGun::getReliabilityRange() const
		{
			return m_reliability_range;
		}

		//Metoda ustawia przedzia³ liczb, w zakresie którego definiujemy zaciêcie dzia³a
		void CGun::setReliabilityRange(float reliability_range_first, float reliability_range_second)
		{
			m_reliability_range.first = reliability_range_first;
			m_reliability_range.second = reliability_range_second;
		}

		//Metoda zwraca dopuszczaln¹ iloœæ wyst¹pieñ uszkodzeñ
		const unsigned CGun::getLimitAmountDamage() const
		{
			return m_limit_amount_damage;
		}

		//Metoda ustawia dopuszczaln¹ iloœæ wyst¹pieñ uszkodzeñ
		void CGun::setLimitAmountDamage(unsigned limit_amount_damage)
		{
			m_limit_amount_damage = limit_amount_damage;
		}

		//Metoda zwraca referencjê na obiekt klasy CLockWeapon - generator uszkodzeñ
		CLockWeapon & CGun::getDamage()
		{
			return m_damage;
		}

		//Metoda ustawia referencjê na obiekt klasy CLockWeapon - generator uszkodzeñ
		void CGun::setDamage(CLockWeapon & damage)
		{
			m_damage = damage;
		}

		//Metoda zwraca flagê, czy mo¿na i trzeba wygenerowaæ strza³ obiektu
		bool CGun::Shoot()
		{
			//je¿eli obiekt nie jest w trybie serwisowym
			if (m_gun_state != EGunState::GUN_SERVICE)
			{
				//logika kurka spustowego broni (cyngiel)
				if (m_ammo_data.getAmmo())
				{
					//Jeœli mamy amunicjê i dzia³o nie jest w trybie ³adowania
					if (m_ammo_data.getAmmo()->getAmmo() > 0 && !m_ammo_loading)
						m_shot_enabled = true;
					else
						m_shot_enabled = false;
				}
				//jeœli nast¹pi³o uszkodzenie i jest amunicja
				if (m_damage.getDamage() && m_ammo_data.getAmmo()->getAmmo() > 0)
				{
					m_shot_enabled = false;
					m_gun_state = EGunState::GUN_DAMAGE;
					//sprawdzamy, czy zosta³ wyczerpany limit uszkodzeñ
					if (m_damage.getDamageCount() >= m_limit_amount_damage)
						m_gun_state = EGunState::GUN_SERVICE;//stan serwisowy
				}
			}
			return m_shot_enabled;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
		void CGun::updateAnimations(float dt)
		{
			switch (m_gun_state)
			{
			case GUN_DEFAULT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyDefaultAnim());
					SetAnimationHead(p_anim_set->GetGunHeadDefaultAnim());
					//animacja head odtwarza siê w pêtli
					GetDisplayableHead()->GetAnimationState()->SetLooped(true);
					GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case GUN_SHOOT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyShootAnim());
					SetAnimationHead(p_anim_set->GetGunHeadShootAnim());
					//animacja head odtwarza siê jeden raz
					GetDisplayableHead()->GetAnimationState()->SetLooped(false);
					GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
				}
				break;
			}
			case GUN_AMMO_LOADING:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyAmmoLoadingAnim());
					SetAnimationHead(p_anim_set->GetGunHeadAmmoLoadingAnim());
					//animacja head odtwarza siê jeden raz
					GetDisplayableHead()->GetAnimationState()->SetLooped(false);
					GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(false);
				}
				break;
			}
			case GUN_AMMO_EMPTY:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyAmmoEmptyAnim());
					SetAnimationHead(p_anim_set->GetGunHeadAmmoEmptyAnim());
					//animacja head odtwarza siê w pêtli
					GetDisplayableHead()->GetAnimationState()->SetLooped(true);
					GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case GUN_DAMAGE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyDamageAnim());
					SetAnimationHead(p_anim_set->GetGunHeadDamageAnim());
					//animacja head odtwarza siê w pêtli
					GetDisplayableHead()->GetAnimationState()->SetLooped(true);
					GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case GUN_SERVICE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyServiceAnim());
					SetAnimationHead(p_anim_set->GetGunHeadServiceAnim());
					//animacja head odtwarza siê w pêtli
					GetDisplayableHead()->GetAnimationState()->SetLooped(true);
					GetDisplayableHeadShadow()->GetAnimationState()->SetLooped(true);
				}
				break;
			}
			case GUN_DEATH:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetGunBodyDeathAnim());
					SetAnimationHead(p_anim_set->GetGunHeadDeathAnim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizuje logikê obiektu
		void CGun::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//metoda aktualizuje sk³adowe transformacji wzglêdem w³¹œciciela
			updateAmmoTransformation(dt);
			
			//próba oddania strza³u
			Shoot();
			
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
			SetRotationHead(GetRotationHead() + (radius_offset*direction));
			//
			//c  h  a  o  s  - testy
		}

		//prywatna metoda aktualizuj¹ce stan obiektu (automat stanów)	
		void CGun::updateGunState(float dt)
		{
			//obiekt nie jest w stanie serwisowym
			if (m_gun_state != EGunState::GUN_SERVICE)
			{
				//obiekt nie ma usterek technicznych
				if (m_gun_state != EGunState::GUN_DAMAGE)
				{
					//jeœli mo¿na oddaæ strza³ - jest amunicja i nie trwa ³adowanie
					if (m_shot_enabled)
					{
						//p o c i s k
						//CreateBullet();

						//stan trwania procesu wystrza³u 
						m_gun_state = EGunState::GUN_SHOOT;

						//dostosowanie prêdkoœci odtwarzania animacji dla strza³u
						SetAnimSpeedHead(CPhysical::getCalcualtedAnimSpeed(m_time_shot));

						//bilans amunicji w magazynku
						m_ammo_data.getAmmo()->setAmmo(m_ammo_data.getAmmo()->getAmmo() - GetBulletPerSoot());

						if (m_ammo_data.getAmmo()->getAmmo() <= 0)	//jeœli iloœæ amunicji jest ujemna lub zero
							m_ammo_data.getAmmo()->setAmmo(0);		//zerujemy iloœæ amunicji	

						m_ammo_loading = true;		//trzeba prze³adowaæ dzia³o
						m_shot_in_progress = true;	//trwa wystrza³
						m_shot_enabled = false;		//nie mo¿na teraz strzelaæ
						m_process_time = 0.0f;		//reset zegara
					}

					//jeœli trwa strza³
					if (GetShotInProgress())
					{
						//zliczam czas trwania strza³u
						m_process_time += dt;

						//min¹³ czas trwania strza³u
						if (m_process_time >= m_time_shot)
						{
							//stan trwania ³adowania amunicji
							m_gun_state = EGunState::GUN_AMMO_LOADING;
							//przywróæ czas ekspozycji klatki animacji na wartoœæ zapamiêtan¹
							SetAnimSpeedHead(GetStoredAnimSpeedHead());

							//dostosowanie prêdkoœci odtwarzania animacji ³adowania amunicji
							SetAnimSpeedHead(CPhysical::getCalcualtedAnimSpeed(m_time_ammo_load_delay));

							m_ammo_loading = true;		//ustawiamy flagê, ¿e trzeba prze³adowaæ dzia³o
							m_shot_in_progress = false;	//czas strza³u siê zakoñczy³
							m_shot_enabled = false;		//nie mo¿na teraz strzelaæ
							m_process_time = 0.0f;		//reset zegara
						}
					}

					//jeœli mo¿na prze³adowaæ dzia³o i nie trwa strza³
					if (m_ammo_loading && !m_shot_in_progress)
					{
						//zliczam czas
						m_process_time += dt;

						//min¹³ czas prze³adowania dzia³a
						if (m_process_time >= m_time_ammo_load_delay)
						{
							//stan default
							m_gun_state = EGunState::GUN_DEFAULT;
							//przywróæ czas ekspozycji klatki animacji na wartoœæ zapamiêtan¹
							SetAnimSpeedHead(GetStoredAnimSpeedHead());

							m_ammo_loading = false;		//ju¿ nie mo¿na prze³adowywaæ dzia³a
							m_process_time = 0.0f;		//reset zegara
						}
					}

					//jeœli nie ma amunicji
					if (m_ammo_data.getAmmo()->getAmmo() <= 0)
					{
						//stan braku amunicji
						m_gun_state = EGunState::GUN_AMMO_EMPTY;

						//przywróæ czas ekspozycji klatki animacji na wartoœæ zapamiêtan¹
						SetAnimSpeedHead(GetStoredAnimSpeedHead());

						m_ammo_loading = true;	//ustawiamy flagê, ¿e trzeba prze³adowaæ dzia³o
						m_shot_enabled = false;	//nie mo¿na teraz strzelaæ
						m_process_time = 0.0f;	//reset zegara
					}
				}
			}

			//stan uszkodzenia (zaciêcia) dzia³a...
			if (m_gun_state == EGunState::GUN_DAMAGE)
			{
				//zliczam czas trwania uszkodzenia
				m_process_time += dt;

				//min¹³ czas trwania strza³u
				if (m_process_time >= m_damage.getDurationDamage())//pobraæ z factory
				{
					m_gun_state = EGunState::GUN_DEFAULT;
					RestoreColorHead();
				}
			}

			//stan serwosowy - wymaga interwencji
			if (m_gun_state == EGunState::GUN_SERVICE)
			{
				//czekam na serwis...
				//stan serwisowy wymaga interwencji zewnêtrznej
				//obiekt, posiadaj¹cy logikê interwencji
				//powinien posiadaæ tak¿e magazynek z amunicj¹,
				//a na obiekcie, który serwisuje, wywo³aæ jego
				//metodê: void supplyAmmunition(int & ammo_out);
				//etc...
			}
		}

		//metoda aktualizuje sk³adowe transformacji wzglêdem w³aœciciela
		void CGun::updateAmmoTransformation(float dt)
		{
			m_ammo_data.getTransformed().Transform(this, m_ammo_data.getAmmo());
		}
	}//namespace weapon
}//namespace equipment
