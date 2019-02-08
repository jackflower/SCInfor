//  ___________________________________________
// | CCommunication.cpp - class implementation |
// | Jack Flower - July 2015                   |
// |___________________________________________|
//

#include "CCommunication.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Animations/CAnimation.h"
#include "../../Rendering/Animations/CAnimationState.h"
#include "../../Rendering/Displayable/CDisplayable.h"


namespace logic
{
	namespace communication
	{
		RTTI_IMPL(CCommunication, Actor);

		//Chroniony konstruktor domy�lny
		CCommunication::CCommunication(const std::wstring& uniqueId)
		:
			Actor					(uniqueId),	//konstruktor klasy bazowej
			m_communication_name	(),
			m_unit_controller		(true),//urz�dzenie w��czone
			e_communication_state	(COMMUNICATION_DEFAULT),
			m_connected				(false),
			m_range					(0.0f),
			m_reset_duration		(0.0f),
			m_duration				(0.0f),
			m_login_module			(false),
			m_networking			(TYPE_DEFAULT)
		{
		}

		//Chroniony konstruktor kopiuj�cy
		CCommunication::CCommunication(const CCommunication &CCommunicationCopy)
		:
			Actor					(CCommunicationCopy),//konstruktor kopiujacy klasy bazowej
			m_communication_name	(CCommunicationCopy.m_communication_name),
			m_unit_controller		(CCommunicationCopy.m_unit_controller),
			e_communication_state	(CCommunicationCopy.e_communication_state),
			m_connected				(CCommunicationCopy.m_connected),
			m_range					(CCommunicationCopy.m_range),
			m_reset_duration		(CCommunicationCopy.m_reset_duration),
			m_duration				(CCommunicationCopy.m_duration),
			m_login_module			(CCommunicationCopy.m_login_module),
			m_networking			(CCommunicationCopy.m_networking)
		{
		}

		//Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		CCommunication::~CCommunication(void)
		{
			//Actor				not edit
			m_communication_name	= "";
			//m_unit_controller		not edit
			e_communication_state	= COMMUNICATION_DEFAULT;
			m_connected				= false;
			m_range					= 0.0f;
			m_reset_duration		= 0.0f;
			m_duration				= 0.0f;
			//m_login_module		//not edit
			m_networking			= TYPE_DEFAULT;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CCommunication::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazw� modu�u komunikacyjnego
		const std::string CCommunication::GetCommunicationName() const
		{
			return m_communication_name;
		}

		//Metoda ustawia nazw� modu�u komunikacyjnego
		void CCommunication::SetCommunicationName(const std::string& communication_name)
		{
			m_communication_name = communication_name;
		}

		//Metoda zwraca flag�, czy obiekt jest zalogowany
		const bool CCommunication::getConnection() const
		{
			return m_connected;
		}

		//Metoda ustawia flag� zalogowania obiektu
		void CCommunication::setConnection(const bool connected)
		{
			m_connected = connected;
		}

		//Metoda zwraca zasi�g topograficzny pracy przeka�nika
		const float CCommunication::getRange() const
		{
			return m_range;
		}

		//Metoda ustawia zasi�g topograficzny pracy przeka�nika
		void CCommunication::setRange(const float range)
		{
			m_range = range;
		}

		//Metoda zwraca czas co jaki modu� si� resetuje/testuje
		const float CCommunication::getResetDuration() const
		{
			return m_reset_duration;
		}

		//Metoda ustawia czas co jaki modu� si� resetuje/testuje
		void CCommunication::setResetDuration(const float reset_duration)
		{
			m_reset_duration = reset_duration;
		}

		//Metoda zwraca referencj� dla rodzaju technologii po��czenia sieciowego
		const ENetworking &CCommunication::getNetworking() const
		{
			return m_networking;
		}

		//Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
		void CCommunication::updateAnimations(float dt)
		{
			//to do...
			switch(e_communication_state)
			{
			case COMMUNICATION_DEFAULT:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodyDefaultAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadDefaultAnim());
				}
				break;
			}
			case COMMUNICATION_SEARCH:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodySearchAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadSearchAnim());
				}
				break;
			}
			case COMMUNICATION_LOGIN:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodyLoginAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadLoginAnim());
				}
				break;
			}
			case COMMUNICATION_AUTHORIZATION:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodyAuthorizationAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadAuthorizationAnim());
				}
				break;
			}
			case COMMUNICATION_UPDATE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodyUpdateAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadUpdateAnim());
				}
				break;
			}
			case COMMUNICATION_DAMAGE:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodyDamageAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadDamageAnim());
				}
				break;
			}
			case COMMUNICATION_DEATH:
			{
				if (p_anim_set)
				{
					SetAnimationBody(p_anim_set->GetCommunicationBodyDeathAnim());
					SetAnimationHead(p_anim_set->GetCommunicationHeadDeathAnim());
				}
				break;
			}
			default:
				break;
			}
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void CCommunication::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::update(dt);

			//aktualizacja tylko przy w��czonym urz�dzeniu
			if (m_unit_controller.getState())
			{
				//zarz�dzanie m_reset_duration...
				//
				//AI - poprzez ten modu�, co jaki� czas
				//sprawdzam, czy po��czenie (client/server) jest poprawne
				//dwa modu�y tej klasy (class CCommunication)
				//prowadz� dialog...
				//
				//np. elektrownia "gada" z przeka�nikiem,
				//czyli te dwie klasy musz� mie� wbudowane modu�u
				//do komunikowania si� (clas CCommunication)
			}

			//obs�uga prezentacji graficznej
		}

	}//namespace communication
}//namespace logic
