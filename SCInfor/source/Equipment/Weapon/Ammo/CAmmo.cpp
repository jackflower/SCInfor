//  __________________________________
// | CAmmo.cpp - class implementation |
// | Jack Flower December 2012        |
// |__________________________________|
//

#include "CAmmo.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../Rendering/Drawable/Layers.h"
#include "../../../Rendering/Animations/CAnimation.h"
#include "../../../Rendering/Animations/CAnimationState.h"
#include "../../../Rendering/Displayable/CDisplayable.h"

using namespace rendering::drawable;

namespace equipment
{
	namespace weapon
	{

		RTTI_IMPL(CAmmo, CActor);

		////Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
		CAmmo::CAmmo(const std::wstring& uniqueId)
		:
			CActor						(uniqueId),
			m_caliber					(),
			m_ammo_state				(AMMO_DEFAULT),
			m_ammo						(0),
			m_ammo_capacity				(0),
			m_percentage_reserve_ammo	(0.1f),//factory...
			m_ammo_empty_message		(false),
			m_reserve_ammo				(0)
		{
			SetZIndexBody(Z_PHYSICAL_AMMO_BODY);
			SetZIndexShadowBody(Z_PHYSICAL_SHADOW_AMMO_BODY);
			SetZIndexHead(Z_PHYSICAL_AMMO_HEAD);
			SetZIndexShadowHead(Z_PHYSICAL_SHADOW_AMMO_HEAD);
		}

		//Chroniony konstruktor kopiuj¹cy
		CAmmo::CAmmo(const CAmmo& CAmmoCopy)
		:
			CActor						(CAmmoCopy),
			m_caliber					(CAmmoCopy.m_caliber),
			m_ammo_state				(CAmmoCopy.m_ammo_state),
			m_ammo						(CAmmoCopy.m_ammo),
			m_ammo_capacity				(CAmmoCopy.m_ammo_capacity),
			m_percentage_reserve_ammo	(CAmmoCopy.m_percentage_reserve_ammo),
			m_ammo_empty_message		(CAmmoCopy.m_ammo_empty_message),
			m_reserve_ammo				(CAmmoCopy.m_reserve_ammo)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		CAmmo::~CAmmo()
		{
			//CActor					not edit
			//m_caliber					not edit
			m_ammo_state				= AMMO_DEFAULT;
			m_ammo						= 0;
			m_ammo_capacity				= 0;
			m_percentage_reserve_ammo	= 0.0f;
			m_ammo_empty_message		= false;
			m_reserve_ammo				= 0;
		}

		//Metoda zwraca typ obiektu /RTTI/
		std::string CAmmo::GetType()
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca zwraca kaliber uzbrojenie
		const float CAmmo::getCaliber() const
		{
			return m_caliber.getCaliber();
		}

		//Metoda ustawia kaliber uzbrojenie
		void CAmmo::setCaliber(const float caliber)
		{
			m_caliber.setCaliber(caliber);
		}

		//Metoda zwraca sta³¹ referencjê wyliczenia stanu logiki behawioralnej obiektu
		const EAmmoState CAmmo::getAmmoState() const
		{
			return m_ammo_state;
		}

		//Metoda ustawia wyliczenie stanu logiki behawioralnej obiektu
		void CAmmo::setAmmoState(const EAmmoState & ammo_state)
		{
			m_ammo_state = ammo_state;
		}

		//Metoda zwraca iloœæ amunicji w magazynku
		const int CAmmo::getAmmo() const
		{
			return m_ammo;
		}

		//Metoda ustawia iloœæ amunicji w magazynku
		void CAmmo::setAmmo(const int ammo)
		{
			if (ammo < 0) return;				//iloœæ amunicji nie mo¿e byæ ujemna
			if (m_ammo_capacity > 0)			//jeœli magazynek na amunicjê ma pojemnoœæ
			{
				if (ammo >= m_ammo_capacity)	//jeœli iloœæ amunicji jest wiêksza lub równa 
												//pojemnoœci magazynka na amunicjê
												//reszta (nadmiar) nie jest wykorzystany
					m_ammo = m_ammo_capacity;	//³adujemy tyle amunicji ile mieœci magazynek na amunicjê
				else
					m_ammo = ammo;				//³adujemy tyle amunicji ile zamierzamy (Parametr funkcji)
			}
			else								//magazynek nie ma pojemnoœæi
				m_ammo = 0;						//nie mo¿na za³adowaæ amunicji.
		}

		//Metoda zwraca pojemnoœæ magazynka na amunicjê
		const int CAmmo::getAmmoCapacity() const
		{
			return m_ammo_capacity;
		}

		//Metoda ustawia pojemnoœæ magazunku na amunicjê
		void CAmmo::setAmmoCapacity(const int ammo_capacity)
		{
			m_ammo_capacity = ammo_capacity;
		}

		//Metoda zwraca wartoœæ, przy której nastêpuje komunikat o rezerwie amunicji
		const float CAmmo::getPercentageReserveAmmo() const
		{
			return m_percentage_reserve_ammo;
		}

		//Metoda ustawia wartoœæ, przy której nastêpuje komunikat o rezerwie amunicji
		void CAmmo::setPercentageReserveAmmo(const float percentage_reserve_ammo)
		{
			m_percentage_reserve_ammo = percentage_reserve_ammo;
		}

		//Metoda zwraca wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku amunicji
		const bool CAmmo::GetAmmoEmptyMessage() const
		{
			return m_ammo_empty_message;
		}

		//Metoda ustawia wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku paliwa
		void CAmmo::SetAmmoEmptyMessage(const bool ammo_empty_message)
		{
			m_ammo_empty_message = ammo_empty_message;
		}

		//Metoda zwraca nazwê kalibru
		const std::string & CAmmo::getCaliberName() const
		{
			return m_caliber.getName();
		}

		//Metoda ustawia nazwê kalibru
		void CAmmo::setCaliberName(const std::string & name)
		{
			m_caliber.setName(name);
		}

		//Metoda zwraca sta³¹ referencjê na wyliczenie ECaliber
		const ECaliber & CAmmo::getCaliberType() const
		{
			return m_caliber.getCaliberType();
		}

		//Metoda ustawia referencjê na wyliczenie ECaliber
		void CAmmo::setCaliberType(const ECaliber & caliber)
		{
			m_caliber.setCaliberType(caliber);
		}

		//Metoda zwraca rezerwê amunicji w magazynku
		const int CAmmo::getReserveAmmo() const
		{
			return m_reserve_ammo;
		}

		//Metoda ustawia zwraca rezerwê amunicji w magazynku
		void CAmmo::setReserveAmmo(const int reserve_ammo)
		{
			m_reserve_ammo = reserve_ammo;
		}
		
		//Metoda zaopatruje obiekt w amunicjê z zewnêtrznego Ÿród³a
		void CAmmo::supplyAmmunition(int & ammo_out)
		{
			if (m_ammo >= m_ammo_capacity) return;	//nie ma potrzeby ³adowania amunicji
			if (ammo_out <= 0) return;				//nie ma co ³adowaæ
			
			//obliczamy ile amunicji mo¿emy do³adowaæ do magazynka
			int m_ammo_need = m_ammo_capacity - m_ammo;

			//amunicji jest wiêcej lub tyle samo ile chcemy do³adowaæ
			if (ammo_out >= m_ammo_need)
				m_ammo = m_ammo + m_ammo_need;
			//w przeciwnym wypadku pomnieszamy do³adowanie - bierzemy tyle ile mo¿na
			else
			{
				m_ammo_need = ammo_out;
				m_ammo = m_ammo + m_ammo_need;
			}

			//bilans
			ammo_out = ammo_out - m_ammo_need;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
		void CAmmo::updateAnimations(float dt)
		{
			switch (m_ammo_state)
			{
			case AMMO_DEFAULT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetAmmoDefaultAnim());
					//head - not used
				}
				break;
			}
			case AMMO_RESERVE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetAmmoReserveAnim());
					//head - not used
				}
				break;
			}
			case AMMO_EMPTY:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetAmmoEmptyAnim());
					//head - not used
				}
				break;
			}
			case AMMO_DAMAGE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetAmmoDamageAnim());
					//head - not used
				}
				break;
			}
			default:
				break;
			}
		}

		//Metoda aktulizuje obiekt
		void CAmmo::Update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::UpdateShadow(dt);
			
			//jeœli iloœæ amunicji w magazynku jest wiêksza od iloœci dla rezerwy
			if(m_ammo > m_reserve_ammo)
				m_ammo_state = AMMO_DEFAULT;

			//jeœli iloœæ amunicji w magazynku jest mniejsza lub równa od iloœci dla rezerwy
			else if (m_ammo <= m_reserve_ammo)
				m_ammo_state = AMMO_RESERVE;
			
			//jeœli nie ma amunicji w magazynku
			if (m_ammo <= 0)
				m_ammo_state = AMMO_EMPTY;
	
			//future - warunek dla stanu AMMO_DAMAGE (ju¿ siê pisze - chaos/zaciêcie jêzyka spustowego)
		
			//aktualizacja animacji
			updateAnimations(dt);
		}
	}//namespace weapon
}//namespace equipment
