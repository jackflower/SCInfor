//  __________________________________
// | Login.cpp - class implementation |
// | Jack Flower - July 2015          |
// |__________________________________|
//

#include "Login.h"

namespace logic
{
	namespace communication
	{
		//Konstruktor
		Login::Login(void)
		:
			m_login(),
			m_password(),
			m_connection(false)
		{
		}
			
		//Konstruktor parametryczny
		Login::Login(bool login)
			:
			m_login(),
			m_password(),
			m_connection(login)
		{
		}

		//Konstruktor kopiujący
		Login::Login(const Login & LoginCopy)
		:
			m_login(LoginCopy.m_login),
			m_password(LoginCopy.m_password),
			m_connection(LoginCopy.m_connection)
		{
		}

		//Destruktor
		Login::~Login()
		{
			m_login = "";
			m_password = "";
			m_connection = false;
		}

		//Metoda zwraca login systemu
		const std::string Login::getLogin() const
		{
			return m_login;
		}

		//Metoda ustawia login systemu
		void Login::setLogin(const std::string & login)
		{
			m_login = login;
		}

		//Metoda zwraca hasło systemu
		const std::string Login::getPassword() const
		{
			return m_password;
		}

		//Metoda ustawia hasło systemu
		void Login::setPassword(const std::string & password)
		{
			m_password = password;
		}

		//Metoda zwraca hasło logowania
		const bool Login::getConnection() const
		{
			return m_connection;
		}

		//Metoda ustawia flagę, czy obiekt jest zalogowany do systemu
		void Login::setConnection(const bool connection)
		{
			m_connection = connection;
		}

		//Metoda logowania do systemu - autoryzacja i walidacja
		bool Login::processLogin(std::string login, std::string password)
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
		void Login::processLogout()
		{
			m_connection = false;
			m_login = "";
			m_password = "";
		}
	}//namespace communication
}//namespace communication
