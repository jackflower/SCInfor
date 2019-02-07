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

		//Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
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
			//doda� layer's...
		}

		//Chroniony konstruktor kopiuj�cy
		CGun::CGun(const CGun& CGunCopy)
		:
			CActor					(CGunCopy),//konstruktor kopiuj�cy klasy bazowej
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

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

		//Metoda zwraca wska�nik obiekt klasy Ammo
		Ammo *CGun::getAmmo()
		{
			return m_ammo_data.getAmmo();
		}

		//Metoda ustawia wska�nik obiekt klasy Ammo
		void CGun::setAmmo(Ammo * ammo)
		{
			m_ammo_data.setAmmo(ammo);
		}

		//Metoda zwraca flag�, czy obiekt posiada magazynek na amunicj� (amunicj�)
		const bool CGun::getUseAmmo() const
		{
			return m_ammo_data.getUseEquipment();
		}

		//Metoda ustawia flag�, czy obiekt posiada magazynek na amunicj� (amunicj�)
		void CGun::setUseAmmo(bool use_ammo)
		{
			m_ammo_data.setUseEquipment(use_ammo);
		}

		//Metoda zwraca referencj� na opakowanie danych dla transformacji
		CTransformation & CGun::getAmmoTransformed()
		{
			return m_ammo_data.getTransformed();
		}
		
		//Metoda ustawia referencj� na opakowanie danych dla transformacji
		void CGun::setAmmoTransformed(CTransformation & ammo_transformation)
		{
			m_ammo_data.setTransformed(ammo_transformation);
		}

		//Metoda zwraca referencj� na opakowanie funkcjonalno�ci amunicji
		EquipmentAmmoData & CGun::getEquipmentAmmoData()
		{
			return m_ammo_data;
		}

		//Metoda ustawia referencj� na opakowanie funkcjonalno�ci amunicji
		void CGun::setEquipmentAmmoData(EquipmentAmmoData & ammo_data)
		{
			m_ammo_data = ammo_data;
		}

		//Metoda zwraca flag�, czy mo�na prze�adowa� amunicj�
		const bool CGun::GetAmmoLoading() const
		{
			return m_ammo_loading;
		}

		//Metoda ustawia flag�, czy mo�na prze�adowa� amunicj�
		void CGun::SetAmmoLoading(bool ammo_loading)
		{
			m_ammo_loading = ammo_loading;
		}

		//Metoda zwraca czas prze�adowania amunicji
		const float CGun::GetTimeAmmoLoadDelay() const
		{
			return m_time_ammo_load_delay;
		}

		//Metoda ustawia czas prze�adowania amunicji
		void CGun::SetTimeAmmoLoadDelay(float time_ammo_load_delay)
		{
			m_time_ammo_load_delay = time_ammo_load_delay;
		}

		//Metoda zwraca flag�, czy mo�na odda� strza�
		const bool CGun::GetShotEnabled() const
		{
			return m_shot_enabled;
		}

		//Metoda ustawia flag�, czy mo�na odda� strza�
		void CGun::SetShotEnabled(bool shot_enabled)
		{
			m_shot_enabled = shot_enabled;
		}

		//Metoda zwraca czas trwania wystrza�u
		const float CGun::GetTimeShot() const
		{
			return m_time_shot;
		}

		//Metoda ustawia czas trwania animacji wystrza�u
		void CGun::SetTimeShot(float time_shot)
		{
			m_time_shot = time_shot;
		}

		//Metoda zwraca flag� czy trwa wystrza�
		const bool CGun::GetShotInProgress() const
		{
			return m_shot_in_progress;
		}

		//Metoda ustawia flag� czy trwa wystrza�
		void CGun::SetShotInProgress(bool shot_in_progress)
		{
			m_shot_in_progress = shot_in_progress;
		}

		//Metoda zwraca pr�dko�� pocisku wystrzelonego z dzia�a
		const float CGun::GetBulletSpeed() const
		{
			return m_bullet_speed;
		}

		//Metoda ustawia pr�dko�� pocisku wystrzelonego z dzia�a
		void CGun::SetBulletSpeed(const float bullet_speed)
		{
			m_bullet_speed = bullet_speed;
		}
		
		//Metoda zwraca zasi�g strza�u
		const float CGun::GetRangeShot() const
		{
			return m_range_shot;
		}

		//Metoda ustawia zasi�g strza�u
		void CGun::SetRangeShot(float range_shot)
		{
			if (m_range_shot < 0) return;
			m_range_shot = range_shot;
		}

		//Metoda zwraca ilo�� luf dzia�a
		const int CGun::GetBarrelCount() const
		{
			return m_barrel_count;
		}

		//Metoda ustawia ilo�� luf dzia�a
		void CGun::SetBarrelCount(int barrel_count)
		{
			if (m_barrel_count <= 0) m_barrel_count = 1;	//dzia�o musi mie� przynajmniej jedn� luf�
			m_barrel_count = barrel_count;
		}

		//Metoda zwraca apogeum wysoko�ci lotu balistycznego pocisku
		const float CGun::GetTargetAltitude() const
		{
			return m_target_altitude;
		}

		//Metoda ustawia apogeum wysoko�ci lotu balistycznego pocisku
		void CGun::SetTargetAltitude(float target_altitude)
		{
			m_target_altitude = target_altitude;
		}

		//Metoda zwraca sta�� referencj� na wektor po�o�enia emitera eksplozji wzgl�dem lufy
		const sf::Vector2f& CGun::GetExplosionEmiter() const
		{
			return m_explosion_emiter;
		}

		//Metoda ustawia po�o�enie emitera eksplozji wzgl�dem lufy - wektor
		void CGun::SetExplosionEmiter(sf::Vector2f& explosion_emiter)
		{
			m_explosion_emiter = explosion_emiter;
		}

		//Metoda ustawia po�o�enie emitera eksplozji wzgl�dem lufy - wsp�rz�dne
		void CGun::SetExplosionEmiter(float explosion_emiter_x, float explosion_emiter_y)
		{
			m_explosion_emiter.x = explosion_emiter_x;
			m_explosion_emiter.y = explosion_emiter_y;
		}
		
		//Metoda sprawdza, czy wystarczy amunicji w magazunku na strza� z wszystkich luf
		const int CGun::GetBulletPerSoot()
		{
			int bullet_per_shoot = 0;//pesymistycznie...

			if (m_ammo_data.getAmmo())
			{
				if (m_ammo_data.getAmmo()->getAmmo() >= m_barrel_count)	//je�li amunicji w magazynku jest wi�cej lub tyle samo co luf
					bullet_per_shoot = m_barrel_count;					//strzelamy z wszystkich luf
				else													//w przeciwnym wypadku
					bullet_per_shoot = m_ammo_data.getAmmo()->getAmmo();//strzelamy tym co pozosta�o
			}
			return bullet_per_shoot;
		}

		//Metoda zwraca czas op�nienia komunikatu uzupe�nienia amunicji
		const float CGun::GetAmmoTimeDelayed() const
		{
			return m_ammo_time_delayed;
		}

		//Metoda ustawia czas op�nienia komunikatu uzupe�nienia amunicji
		void CGun::SetAmmoTimeDelayed(float ammo_time_delayed)
		{
			m_ammo_time_delayed = ammo_time_delayed;
		}

		//Metoda zaopatruje obiekt w amunicj� z zewn�trznego �r�d�a
		void CGun::supplyAmmunition(int & ammo_out)
		{
			//logika zasila magazynek z amunicj� w amunicj� pobieran�
			//z zewn�trz obliczaj�c jej ilo��, bior�c pod uwag� pojemno��
			//magazynka oraz bilansuje amunicj� z zewn�trz...
			if (m_ammo_data.getAmmo())
				m_ammo_data.getAmmo()->supplyAmmunition(ammo_out);
		}

		//Metoda zwraca referencj� na przedzia� liczb, w zakresie kt�rego definiujemy zaci�cie dzia�a
		const std::pair<float, float> & CGun::getReliabilityRange() const
		{
			return m_reliability_range;
		}

		//Metoda ustawia przedzia� liczb, w zakresie kt�rego definiujemy zaci�cie dzia�a
		void CGun::setReliabilityRange(float reliability_range_first, float reliability_range_second)
		{
			m_reliability_range.first = reliability_range_first;
			m_reliability_range.second = reliability_range_second;
		}

		//Metoda zwraca dopuszczaln� ilo�� wyst�pie� uszkodze�
		const unsigned CGun::getLimitAmountDamage() const
		{
			return m_limit_amount_damage;
		}

		//Metoda ustawia dopuszczaln� ilo�� wyst�pie� uszkodze�
		void CGun::setLimitAmountDamage(unsigned limit_amount_damage)
		{
			m_limit_amount_damage = limit_amount_damage;
		}

		//Metoda zwraca referencj� na obiekt klasy CLockWeapon - generator uszkodze�
		CLockWeapon & CGun::getDamage()
		{
			return m_damage;
		}

		//Metoda ustawia referencj� na obiekt klasy CLockWeapon - generator uszkodze�
		void CGun::setDamage(CLockWeapon & damage)
		{
			m_damage = damage;
		}

		//Metoda zwraca flag�, czy mo�na i trzeba wygenerowa� strza� obiektu
		bool CGun::Shoot()
		{
			//je�eli obiekt nie jest w trybie serwisowym
			if (m_gun_state != EGunState::GUN_SERVICE)
			{
				//logika kurka spustowego broni (cyngiel)
				if (m_ammo_data.getAmmo())
				{
					//Je�li mamy amunicj� i dzia�o nie jest w trybie �adowania
					if (m_ammo_data.getAmmo()->getAmmo() > 0 && !m_ammo_loading)
						m_shot_enabled = true;
					else
						m_shot_enabled = false;
				}
				//je�li nast�pi�o uszkodzenie i jest amunicja
				if (m_damage.getDamage() && m_ammo_data.getAmmo()->getAmmo() > 0)
				{
					m_shot_enabled = false;
					m_gun_state = EGunState::GUN_DAMAGE;
					//sprawdzamy, czy zosta� wyczerpany limit uszkodze�
					if (m_damage.getDamageCount() >= m_limit_amount_damage)
						m_gun_state = EGunState::GUN_SERVICE;//stan serwisowy
				}
			}
			return m_shot_enabled;
		}

		//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
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
					//animacja head odtwarza si� w p�tli
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
					//animacja head odtwarza si� jeden raz
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
					//animacja head odtwarza si� jeden raz
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
					//animacja head odtwarza si� w p�tli
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
					//animacja head odtwarza si� w p�tli
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
					//animacja head odtwarza si� w p�tli
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

		//Wirtualna metoda aktualizuje logik� obiektu
		void CGun::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);

			//metoda aktualizuje sk�adowe transformacji wzgl�dem w���ciciela
			updateAmmoTransformation(dt);
			
			//pr�ba oddania strza�u
			Shoot();
			
			//aktualizacja stan�w
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

		//prywatna metoda aktualizuj�ce stan obiektu (automat stan�w)	
		void CGun::updateGunState(float dt)
		{
			//obiekt nie jest w stanie serwisowym
			if (m_gun_state != EGunState::GUN_SERVICE)
			{
				//obiekt nie ma usterek technicznych
				if (m_gun_state != EGunState::GUN_DAMAGE)
				{
					//je�li mo�na odda� strza� - jest amunicja i nie trwa �adowanie
					if (m_shot_enabled)
					{
						//p o c i s k
						//CreateBullet();

						//stan trwania procesu wystrza�u 
						m_gun_state = EGunState::GUN_SHOOT;

						//dostosowanie pr�dko�ci odtwarzania animacji dla strza�u
						SetAnimSpeedHead(CPhysical::getCalcualtedAnimSpeed(m_time_shot));

						//bilans amunicji w magazynku
						m_ammo_data.getAmmo()->setAmmo(m_ammo_data.getAmmo()->getAmmo() - GetBulletPerSoot());

						if (m_ammo_data.getAmmo()->getAmmo() <= 0)	//je�li ilo�� amunicji jest ujemna lub zero
							m_ammo_data.getAmmo()->setAmmo(0);		//zerujemy ilo�� amunicji	

						m_ammo_loading = true;		//trzeba prze�adowa� dzia�o
						m_shot_in_progress = true;	//trwa wystrza�
						m_shot_enabled = false;		//nie mo�na teraz strzela�
						m_process_time = 0.0f;		//reset zegara
					}

					//je�li trwa strza�
					if (GetShotInProgress())
					{
						//zliczam czas trwania strza�u
						m_process_time += dt;

						//min�� czas trwania strza�u
						if (m_process_time >= m_time_shot)
						{
							//stan trwania �adowania amunicji
							m_gun_state = EGunState::GUN_AMMO_LOADING;
							//przywr�� czas ekspozycji klatki animacji na warto�� zapami�tan�
							SetAnimSpeedHead(GetStoredAnimSpeedHead());

							//dostosowanie pr�dko�ci odtwarzania animacji �adowania amunicji
							SetAnimSpeedHead(CPhysical::getCalcualtedAnimSpeed(m_time_ammo_load_delay));

							m_ammo_loading = true;		//ustawiamy flag�, �e trzeba prze�adowa� dzia�o
							m_shot_in_progress = false;	//czas strza�u si� zako�czy�
							m_shot_enabled = false;		//nie mo�na teraz strzela�
							m_process_time = 0.0f;		//reset zegara
						}
					}

					//je�li mo�na prze�adowa� dzia�o i nie trwa strza�
					if (m_ammo_loading && !m_shot_in_progress)
					{
						//zliczam czas
						m_process_time += dt;

						//min�� czas prze�adowania dzia�a
						if (m_process_time >= m_time_ammo_load_delay)
						{
							//stan default
							m_gun_state = EGunState::GUN_DEFAULT;
							//przywr�� czas ekspozycji klatki animacji na warto�� zapami�tan�
							SetAnimSpeedHead(GetStoredAnimSpeedHead());

							m_ammo_loading = false;		//ju� nie mo�na prze�adowywa� dzia�a
							m_process_time = 0.0f;		//reset zegara
						}
					}

					//je�li nie ma amunicji
					if (m_ammo_data.getAmmo()->getAmmo() <= 0)
					{
						//stan braku amunicji
						m_gun_state = EGunState::GUN_AMMO_EMPTY;

						//przywr�� czas ekspozycji klatki animacji na warto�� zapami�tan�
						SetAnimSpeedHead(GetStoredAnimSpeedHead());

						m_ammo_loading = true;	//ustawiamy flag�, �e trzeba prze�adowa� dzia�o
						m_shot_enabled = false;	//nie mo�na teraz strzela�
						m_process_time = 0.0f;	//reset zegara
					}
				}
			}

			//stan uszkodzenia (zaci�cia) dzia�a...
			if (m_gun_state == EGunState::GUN_DAMAGE)
			{
				//zliczam czas trwania uszkodzenia
				m_process_time += dt;

				//min�� czas trwania strza�u
				if (m_process_time >= m_damage.getDurationDamage())//pobra� z factory
				{
					m_gun_state = EGunState::GUN_DEFAULT;
					RestoreColorHead();
				}
			}

			//stan serwosowy - wymaga interwencji
			if (m_gun_state == EGunState::GUN_SERVICE)
			{
				//czekam na serwis...
				//stan serwisowy wymaga interwencji zewn�trznej
				//obiekt, posiadaj�cy logik� interwencji
				//powinien posiada� tak�e magazynek z amunicj�,
				//a na obiekcie, kt�ry serwisuje, wywo�a� jego
				//metod�: void supplyAmmunition(int & ammo_out);
				//etc...
			}
		}

		//metoda aktualizuje sk�adowe transformacji wzgl�dem w�a�ciciela
		void CGun::updateAmmoTransformation(float dt)
		{
			m_ammo_data.getTransformed().Transform(this, m_ammo_data.getAmmo());
		}
	}//namespace weapon
}//namespace equipment
