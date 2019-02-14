//  _________________________________
// | Ammo.cpp - class implementation |
// | Jack Flower December 2012       |
// |_________________________________|
//

#include "Ammo.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/Animation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

using namespace rendering::drawable;

namespace equipment
{
	namespace weapon
	{

		RTTI_IMPL(Ammo, Actor);

		////Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
		Ammo::Ammo(const std::wstring & uniqueId)
		:
			Actor(uniqueId),
			m_caliber(),
			m_ammo_state(AMMO_DEFAULT),
			m_ammo(0),
			m_ammo_capacity(0),
			m_percentage_reserve_ammo(0.1f),//factory...
			m_ammo_empty_message(false),
			m_reserve_ammo(0)
		{
			setZIndexBody(Z_PHYSICAL_AMMO_BODY);
			setZIndexShadowBody(Z_PHYSICAL_SHADOW_AMMO_BODY);
			setZIndexHead(Z_PHYSICAL_AMMO_HEAD);
			setZIndexShadowHead(Z_PHYSICAL_SHADOW_AMMO_HEAD);
		}

		//Chroniony konstruktor kopiujący
		Ammo::Ammo(const Ammo & AmmoCopy)
		:
			Actor(AmmoCopy),
			m_caliber(AmmoCopy.m_caliber),
			m_ammo_state(AmmoCopy.m_ammo_state),
			m_ammo(AmmoCopy.m_ammo),
			m_ammo_capacity(AmmoCopy.m_ammo_capacity),
			m_percentage_reserve_ammo(AmmoCopy.m_percentage_reserve_ammo),
			m_ammo_empty_message(AmmoCopy.m_ammo_empty_message),
			m_reserve_ammo(AmmoCopy.m_reserve_ammo)
		{
			setZIndexBody(Z_PHYSICAL_AMMO_BODY);
			setZIndexShadowBody(Z_PHYSICAL_SHADOW_AMMO_BODY);
			setZIndexHead(Z_PHYSICAL_AMMO_HEAD);
			setZIndexShadowHead(Z_PHYSICAL_SHADOW_AMMO_HEAD);
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		Ammo::~Ammo()
		{
			//Actor
			//m_caliber
			m_ammo_state = EAmmoState::AMMO_DEFAULT;
			m_ammo = 0;
			m_ammo_capacity = 0;
			m_percentage_reserve_ammo = 0.0f;
			m_ammo_empty_message = false;
			m_reserve_ammo = 0;
		}

		//Metoda zwraca typ obiektu /RTTI/
		std::string Ammo::getType()
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca zwraca kaliber uzbrojenie
		const float Ammo::getCaliber() const
		{
			return m_caliber.getCaliber();
		}

		//Metoda ustawia kaliber uzbrojenie
		void Ammo::setCaliber(const float caliber)
		{
			m_caliber.setCaliber(caliber);
		}

		//Metoda zwraca stałą referencję wyliczenia stanu logiki behawioralnej obiektu
		const EAmmoState Ammo::getAmmoState() const
		{
			return m_ammo_state;
		}

		//Metoda ustawia wyliczenie stanu logiki behawioralnej obiektu
		void Ammo::setAmmoState(const EAmmoState & ammo_state)
		{
			m_ammo_state = ammo_state;
		}

		//Metoda zwraca ilość amunicji w magazynku
		const int Ammo::getAmmo() const
		{
			return m_ammo;
		}

		//Metoda ustawia ilość amunicji w magazynku
		void Ammo::setAmmo(const int ammo)
		{
			if (ammo < 0) return;				//ilość amunicji nie może być ujemna
			if (m_ammo_capacity > 0)			//jeśli magazynek na amunicję ma pojemność
			{
				if (ammo >= m_ammo_capacity)	//jeśli ilość amunicji jest większa lub równa 
												//pojemności magazynka na amunicję
												//reszta (nadmiar) nie jest wykorzystany
					m_ammo = m_ammo_capacity;	//ładujemy tyle amunicji ile mieści magazynek na amunicję
				else
					m_ammo = ammo;				//ładujemy tyle amunicji ile zamierzamy (Parametr funkcji)
			}
			else								//magazynek nie ma pojemnośći
				m_ammo = 0;						//nie można załadować amunicji.
		}

		//Metoda zwraca pojemność magazynka na amunicję
		const int Ammo::getAmmoCapacity() const
		{
			return m_ammo_capacity;
		}

		//Metoda ustawia pojemność magazunku na amunicję
		void Ammo::setAmmoCapacity(const int ammo_capacity)
		{
			m_ammo_capacity = ammo_capacity;
		}

		//Metoda zwraca wartość, przy której następuje komunikat o rezerwie amunicji
		const float Ammo::getPercentageReserveAmmo() const
		{
			return m_percentage_reserve_ammo;
		}

		//Metoda ustawia wartość, przy której następuje komunikat o rezerwie amunicji
		void Ammo::setPercentageReserveAmmo(const float percentage_reserve_ammo)
		{
			m_percentage_reserve_ammo = percentage_reserve_ammo;
		}

		//Metoda zwraca wartość flagi, czy obiekt może wysyłać komunikaty o braku amunicji
		const bool Ammo::getAmmoEmptyMessage() const
		{
			return m_ammo_empty_message;
		}

		//Metoda ustawia wartość flagi, czy obiekt może wysyłać komunikaty o braku paliwa
		void Ammo::setAmmoEmptyMessage(const bool ammo_empty_message)
		{
			m_ammo_empty_message = ammo_empty_message;
		}

		//Metoda zwraca nazwę kalibru
		const std::string & Ammo::getCaliberName() const
		{
			return m_caliber.getName();
		}

		//Metoda ustawia nazwę kalibru
		void Ammo::setCaliberName(const std::string & name)
		{
			m_caliber.setName(name);
		}

		//Metoda zwraca stałą referencję na wyliczenie ECaliber
		const ECaliber & Ammo::getCaliberType() const
		{
			return m_caliber.getCaliberType();
		}

		//Metoda ustawia referencję na wyliczenie ECaliber
		void Ammo::setCaliberType(const ECaliber & caliber)
		{
			m_caliber.setCaliberType(caliber);
		}

		//Metoda zwraca rezerwę amunicji w magazynku
		const int Ammo::getReserveAmmo() const
		{
			return m_reserve_ammo;
		}

		//Metoda ustawia zwraca rezerwę amunicji w magazynku
		void Ammo::setReserveAmmo(const int reserve_ammo)
		{
			m_reserve_ammo = reserve_ammo;
		}
		
		//Metoda zaopatruje obiekt w amunicję z zewnętrznego źródła
		void Ammo::supplyAmmunition(int & ammo_out)
		{
			if (m_ammo >= m_ammo_capacity) return;	//nie ma potrzeby ładowania amunicji
			if (ammo_out <= 0) return;				//nie ma co ładować
			
			//obliczamy ile amunicji możemy doładować do magazynka
			int m_ammo_need = m_ammo_capacity - m_ammo;

			//amunicji jest więcej lub tyle samo ile chcemy doładować
			if (ammo_out >= m_ammo_need)
				m_ammo = m_ammo + m_ammo_need;
			//w przeciwnym wypadku pomnieszamy doładowanie - bierzemy tyle ile można
			else
			{
				m_ammo_need = ammo_out;
				m_ammo = m_ammo + m_ammo_need;
			}

			//bilans
			ammo_out = ammo_out - m_ammo_need;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		void Ammo::updateAnimations(float dt)
		{
			switch (m_ammo_state)
			{
			case AMMO_DEFAULT:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetAmmoDefaultAnim());
					//head - not used
				}
				break;
			}
			case AMMO_RESERVE:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetAmmoReserveAnim());
					//head - not used
				}
				break;
			}
			case AMMO_EMPTY:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetAmmoEmptyAnim());
					//head - not used
				}
				break;
			}
			case AMMO_DAMAGE:
			{
				if (p_anim_set)
				{
					setAnimationBody(p_anim_set->GetAmmoDamageAnim());
					//head - not used
				}
				break;
			}
			default:
				break;
			}
		}

		//Metoda aktulizuje obiekt
		void Ammo::update(float dt)
		{
			//aktualizacja shadow engine
			Physical::updateShadow(dt);
			
			//jeśli ilość amunicji w magazynku jest większa od ilości dla rezerwy
			if(m_ammo > m_reserve_ammo)
				m_ammo_state = AMMO_DEFAULT;

			//jeśli ilość amunicji w magazynku jest mniejsza lub równa od ilości dla rezerwy
			else if (m_ammo <= m_reserve_ammo)
				m_ammo_state = AMMO_RESERVE;
			
			//jeśli nie ma amunicji w magazynku
			if (m_ammo <= 0)
				m_ammo_state = AMMO_EMPTY;
	
			//future - warunek dla stanu AMMO_DAMAGE (już się pisze - chaos/zacięcie języka spustowego)
		
			//aktualizacja animacji
			updateAnimations(dt);
		}
	}//namespace weapon
}//namespace equipment
