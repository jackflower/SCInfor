//  ___________________________________
// | CLogin.cpp - class implementation |
// | Jack Flower - July 2015           |
// |___________________________________|
//

#include "CLogin.h"

namespace logic
{
	namespace communication
	{
		//Konstruktor
		CLogin::CLogin(void)
		:
			m_login				(),
			m_password			(),
			m_connection		(false)
		{
		}
			
		//Konstruktor kopiuj¹cy
		CLogin::CLogin(const CLogin &CLoginCopy)
		:
			m_login				(CLoginCopy.m_login),
			m_password			(CLoginCopy.m_password),
			m_connection		(CLoginCopy.m_connection)
		{
		}

		//Konstruktor parametryczny
		CLogin::CLogin(bool login)
		:
			m_login				(),
			m_password			(),
			m_connection		(login)
		{
		}

		//Destruktor
		CLogin::~CLogin()
		{
			m_login				= "";
			m_password			= "";
			//m_connection()	not edit
		}

		//Metoda zwraca login systemu
		const std::string CLogin::getLogin() const
		{
			return m_login;
		}

		//Metoda ustawia login systemu
		void CLogin::setLogin(const std::string login)
		{
			m_login = login;
		}

		//Metoda zwraca has³o systemu
		const std::string CLogin::getPassword() const
		{
			return m_password;
		}

		//Metoda ustawia has³o systemu
		void CLogin::setPassword(const std::string password)
		{
			m_password = password;
		}

		//Metoda zwraca has³o logowania
		const bool CLogin::getConnection() const
		{
			return m_connection;
		}

		//Metoda ustawia flagê, czy obiekt jest zalogowany do systemu
		void CLogin::setConnection(const bool connection)
		{
			m_connection = connection;
		}

		//Metoda logowania do systemu - autoryzacja i walidacja
		bool CLogin::Login(std::string login, std::string password)
		{
			//walidacja
			if(m_login == login && m_password == password)
			{	
				m_connection = true;
				return true;
			}
			return false;
		}

		//Metoda wylogowania z systemu
		void CLogin::Logout()
		{
			m_connection = false;
		}
	}//namespace communication
}//namespace communication
