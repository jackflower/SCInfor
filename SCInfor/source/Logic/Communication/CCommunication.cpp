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

		//Chroniony konstruktor domyœlny
		CCommunication::CCommunication(const std::wstring& uniqueId)
		:
			Actor					(uniqueId),	//konstruktor klasy bazowej
			m_communication_name	(),
			m_unit_controller		(true),//urz¹dzenie w³¹czone
			e_communication_state	(COMMUNICATION_DEFAULT),
			m_connected				(false),
			m_range					(0.0f),
			m_reset_duration		(0.0f),
			m_duration				(0.0f),
			m_login_module			(false),
			m_networking			(TYPE_DEFAULT)
		{
		}

		//Chroniony konstruktor kopiuj¹cy
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

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
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

		//Metoda zwraca nazwê modu³u komunikacyjnego
		const std::string CCommunication::GetCommunicationName() const
		{
			return m_communication_name;
		}

		//Metoda ustawia nazwê modu³u komunikacyjnego
		void CCommunication::SetCommunicationName(const std::string& communication_name)
		{
			m_communication_name = communication_name;
		}

		//Metoda zwraca flagê, czy obiekt jest zalogowany
		const bool CCommunication::getConnection() const
		{
			return m_connected;
		}

		//Metoda ustawia flagê zalogowania obiektu
		void CCommunication::setConnection(const bool connected)
		{
			m_connected = connected;
		}

		//Metoda zwraca zasiêg topograficzny pracy przekaŸnika
		const float CCommunication::getRange() const
		{
			return m_range;
		}

		//Metoda ustawia zasiêg topograficzny pracy przekaŸnika
		void CCommunication::setRange(const float range)
		{
			m_range = range;
		}

		//Metoda zwraca czas co jaki modu³ siê resetuje/testuje
		const float CCommunication::getResetDuration() const
		{
			return m_reset_duration;
		}

		//Metoda ustawia czas co jaki modu³ siê resetuje/testuje
		void CCommunication::setResetDuration(const float reset_duration)
		{
			m_reset_duration = reset_duration;
		}

		//Metoda zwraca referencjê dla rodzaju technologii po³¹czenia sieciowego
		const ENetworking &CCommunication::getNetworking() const
		{
			return m_networking;
		}

		//Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
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

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CCommunication::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::update(dt);

			//aktualizacja tylko przy w³¹czonym urz¹dzeniu
			if (m_unit_controller.getState())
			{
				//zarz¹dzanie m_reset_duration...
				//
				//AI - poprzez ten modu³, co jakiœ czas
				//sprawdzam, czy po³¹czenie (client/server) jest poprawne
				//dwa modu³y tej klasy (class CCommunication)
				//prowadz¹ dialog...
				//
				//np. elektrownia "gada" z przekaŸnikiem,
				//czyli te dwie klasy musz¹ mieæ wbudowane modu³u
				//do komunikowania siê (clas CCommunication)
			}

			//obs³uga prezentacji graficznej
		}

	}//namespace communication
}//namespace logic
