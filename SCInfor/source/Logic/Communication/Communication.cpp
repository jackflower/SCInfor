﻿//  __________________________________________
// | Communication.cpp - class implementation |
// | Jack Flower - July 2015                  |
// |__________________________________________|
//

#include "Communication.h"
#include "../../Rendering/Animations/CAnimSet.h"
#include "../../Rendering/Animations/CAnimation.h"
#include "../../Rendering/Animations/CAnimationState.h"
#include "../../Rendering/Displayable/CDisplayable.h"


namespace logic
{
	namespace communication
	{
		RTTI_IMPL(Communication, Actor);

		//Chroniony konstruktor domyślny
		Communication::Communication(const std::wstring & uniqueId)
		:
			Actor(uniqueId), //konstruktor klasy bazowej
			m_communication_name(),
			m_unit_controller(true),//urządzenie włączone
			e_communication_state(COMMUNICATION_DEFAULT),
			m_connected(false),
			m_range(0.0f),
			m_reset_duration(0.0f),
			m_duration(0.0f),
			m_login_module(false),
			m_networking(TYPE_DEFAULT)
		{
		}

		//Chroniony konstruktor kopiujący
		Communication::Communication(const Communication & CommunicationCopy)
		:
			Actor(CommunicationCopy),//konstruktor kopiujacy klasy bazowej
			m_communication_name(CommunicationCopy.m_communication_name),
			m_unit_controller(CommunicationCopy.m_unit_controller),
			e_communication_state(CommunicationCopy.e_communication_state),
			m_connected(CommunicationCopy.m_connected),
			m_range(CommunicationCopy.m_range),
			m_reset_duration(CommunicationCopy.m_reset_duration),
			m_duration(CommunicationCopy.m_duration),
			m_login_module(CommunicationCopy.m_login_module),
			m_networking(CommunicationCopy.m_networking)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
		Communication::~Communication()
		{
			//~Actor()
			m_communication_name = "";
			//m_unit_controller
			e_communication_state = COMMUNICATION_DEFAULT;
			m_connected = false;
			m_range = 0.0f;
			m_reset_duration = 0.0f;
			m_duration = 0.0f;
			//m_login_module
			m_networking = TYPE_DEFAULT;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Communication::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazwę modułu komunikacyjnego
		const std::string Communication::getCommunicationName() const
		{
			return m_communication_name;
		}

		//Metoda ustawia nazwę modułu komunikacyjnego
		void Communication::setCommunicationName(const std::string & communication_name)
		{
			m_communication_name = communication_name;
		}

		//Metoda zwraca flagę, czy obiekt jest zalogowany
		const bool Communication::getConnection() const
		{
			return m_connected;
		}

		//Metoda ustawia flagę zalogowania obiektu
		void Communication::setConnection(const bool connected)
		{
			m_connected = connected;
		}

		//Metoda zwraca zasięg topograficzny pracy przekaźnika
		const float Communication::getRange() const
		{
			return m_range;
		}

		//Metoda ustawia zasięg topograficzny pracy przekaźnika
		void Communication::setRange(const float range)
		{
			m_range = range;
		}

		//Metoda zwraca czas co jaki moduł się resetuje/testuje
		const float Communication::getResetDuration() const
		{
			return m_reset_duration;
		}

		//Metoda ustawia czas co jaki moduł się resetuje/testuje
		void Communication::setResetDuration(const float reset_duration)
		{
			m_reset_duration = reset_duration;
		}

		//Metoda zwraca referencję na obiekt klasy Login - opakowanie logowania
		Login & Communication::getLoginModule()
		{ 
			return m_login_module;
		}

		//Metoda ustawia stałą referencję na obiekt klasy Login - opakowanie logowania
		void Communication::setLoginModule(const Login & login_module)
		{
			m_login_module = login_module;
		}

		//Metoda zwraca login systemu
		const std::string Communication::getLogin() const
		{
			return m_login_module.getLogin();
		}

		//Metoda ustawia login systemu
		void Communication::setLogin(const std::string & login)
		{
			m_login_module.setLogin(login);
		}

		//Metoda zwraca hasło systemu
		const std::string Communication::getPassword() const
		{
			return m_login_module.getPassword();
		}

		//Metoda ustawia hasło systemu
		void Communication::setPassword(const std::string password)
		{
			m_login_module.setPassword(password);
		}


		////////

		//Metoda zwraca referencję dla rodzaju technologii połączenia sieciowego
		const ENetworking & Communication::getNetworking() const
		{
			return m_networking;
		}

		//Metoda ustawia referencję dla rodzaju technologii połączenia sieciowego
		void Communication::setNetworking(const ENetworking & networking)
		{
			m_networking = networking;
		}

		//Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
		void Communication::updateAnimations(float dt)
		{
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

		//Wirtualna metoda aktualizująca obiekt
		void Communication::update(float dt)
		{
			//aktualizacja shadow engine
			CPhysical::update(dt);

			//aktualizacja tylko przy włączonym urządzeniu
			if (m_unit_controller.getState())
			{
				//zarządzanie m_reset_duration...
				//
				//AI - poprzez ten moduł, co jakiś czas
				//sprawdzam, czy połączenie (client/server) jest poprawne
				//dwa moduły tej klasy (class Communication)
				//prowadzą dialog...
				//
				//np. elektrownia "gada" z przekaźnikiem,
				//czyli te dwie klasy muszą mieć wbudowane modułu
				//do komunikowania się (clas Communication)
			}

			//obsługa prezentacji graficznej
		}

	}//namespace communication
}//namespace logic