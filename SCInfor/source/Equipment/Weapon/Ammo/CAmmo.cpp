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

		////Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
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

		//Chroniony konstruktor kopiuj�cy
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

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
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

		//Metoda zwraca sta�� referencj� wyliczenia stanu logiki behawioralnej obiektu
		const EAmmoState CAmmo::getAmmoState() const
		{
			return m_ammo_state;
		}

		//Metoda ustawia wyliczenie stanu logiki behawioralnej obiektu
		void CAmmo::setAmmoState(const EAmmoState & ammo_state)
		{
			m_ammo_state = ammo_state;
		}

		//Metoda zwraca ilo�� amunicji w magazynku
		const int CAmmo::getAmmo() const
		{
			return m_ammo;
		}

		//Metoda ustawia ilo�� amunicji w magazynku
		void CAmmo::setAmmo(const int ammo)
		{
			if (ammo < 0) return;				//ilo�� amunicji nie mo�e by� ujemna
			if (m_ammo_capacity > 0)			//je�li magazynek na amunicj� ma pojemno��
			{
				if (ammo >= m_ammo_capacity)	//je�li ilo�� amunicji jest wi�ksza lub r�wna 
												//pojemno�ci magazynka na amunicj�
												//reszta (nadmiar) nie jest wykorzystany
					m_ammo = m_ammo_capacity;	//�adujemy tyle amunicji ile mie�ci magazynek na amunicj�
				else
					m_ammo = ammo;				//�adujemy tyle amunicji ile zamierzamy (Parametr funkcji)
			}
			else								//magazynek nie ma pojemno��i
				m_ammo = 0;						//nie mo�na za�adowa� amunicji.
		}

		//Metoda zwraca pojemno�� magazynka na amunicj�
		const int CAmmo::getAmmoCapacity() const
		{
			return m_ammo_capacity;
		}

		//Metoda ustawia pojemno�� magazunku na amunicj�
		void CAmmo::setAmmoCapacity(const int ammo_capacity)
		{
			m_ammo_capacity = ammo_capacity;
		}

		//Metoda zwraca warto��, przy kt�rej nast�puje komunikat o rezerwie amunicji
		const float CAmmo::getPercentageReserveAmmo() const
		{
			return m_percentage_reserve_ammo;
		}

		//Metoda ustawia warto��, przy kt�rej nast�puje komunikat o rezerwie amunicji
		void CAmmo::setPercentageReserveAmmo(const float percentage_reserve_ammo)
		{
			m_percentage_reserve_ammo = percentage_reserve_ammo;
		}

		//Metoda zwraca warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku amunicji
		const bool CAmmo::GetAmmoEmptyMessage() const
		{
			return m_ammo_empty_message;
		}

		//Metoda ustawia warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
		void CAmmo::SetAmmoEmptyMessage(const bool ammo_empty_message)
		{
			m_ammo_empty_message = ammo_empty_message;
		}

		//Metoda zwraca nazw� kalibru
		const std::string & CAmmo::getCaliberName() const
		{
			return m_caliber.getName();
		}

		//Metoda ustawia nazw� kalibru
		void CAmmo::setCaliberName(const std::string & name)
		{
			m_caliber.setName(name);
		}

		//Metoda zwraca sta�� referencj� na wyliczenie ECaliber
		const ECaliber & CAmmo::getCaliberType() const
		{
			return m_caliber.getCaliberType();
		}

		//Metoda ustawia referencj� na wyliczenie ECaliber
		void CAmmo::setCaliberType(const ECaliber & caliber)
		{
			m_caliber.setCaliberType(caliber);
		}

		//Metoda zwraca rezerw� amunicji w magazynku
		const int CAmmo::getReserveAmmo() const
		{
			return m_reserve_ammo;
		}

		//Metoda ustawia zwraca rezerw� amunicji w magazynku
		void CAmmo::setReserveAmmo(const int reserve_ammo)
		{
			m_reserve_ammo = reserve_ammo;
		}
		
		//Metoda zaopatruje obiekt w amunicj� z zewn�trznego �r�d�a
		void CAmmo::supplyAmmunition(int & ammo_out)
		{
			if (m_ammo >= m_ammo_capacity) return;	//nie ma potrzeby �adowania amunicji
			if (ammo_out <= 0) return;				//nie ma co �adowa�
			
			//obliczamy ile amunicji mo�emy do�adowa� do magazynka
			int m_ammo_need = m_ammo_capacity - m_ammo;

			//amunicji jest wi�cej lub tyle samo ile chcemy do�adowa�
			if (ammo_out >= m_ammo_need)
				m_ammo = m_ammo + m_ammo_need;
			//w przeciwnym wypadku pomnieszamy do�adowanie - bierzemy tyle ile mo�na
			else
			{
				m_ammo_need = ammo_out;
				m_ammo = m_ammo + m_ammo_need;
			}

			//bilans
			ammo_out = ammo_out - m_ammo_need;
		}

		//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
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
			
			//je�li ilo�� amunicji w magazynku jest wi�ksza od ilo�ci dla rezerwy
			if(m_ammo > m_reserve_ammo)
				m_ammo_state = AMMO_DEFAULT;

			//je�li ilo�� amunicji w magazynku jest mniejsza lub r�wna od ilo�ci dla rezerwy
			else if (m_ammo <= m_reserve_ammo)
				m_ammo_state = AMMO_RESERVE;
			
			//je�li nie ma amunicji w magazynku
			if (m_ammo <= 0)
				m_ammo_state = AMMO_EMPTY;
	
			//future - warunek dla stanu AMMO_DAMAGE (ju� si� pisze - chaos/zaci�cie j�zyka spustowego)
		
			//aktualizacja animacji
			updateAnimations(dt);
		}
	}//namespace weapon
}//namespace equipment
