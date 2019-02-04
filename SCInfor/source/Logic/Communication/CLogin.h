//  ___________________________________
// | CLogin.h - class definition       |
// | Jack Flower - July 2015           |
// |___________________________________|
//

#ifndef H_LOGIN_JACK
#define H_LOGIN_JACK

#include <string>
#include "../../RTTI/RTTI.h"

namespace logic
{
	namespace communication
	{
		class CLogin
		{
		public:

			///
			///Konstruktor
			///
			CLogin();

			///
			///Konstruktor parametryczny
			///
			///@param login - flaga zalogowania
			///
			CLogin(bool login);

			///
			///Konstruktor kopiuj�cy
			///
			///@param &CLoginCopy - sta�a referencja na obiekt klasy CLogin
			///
			CLogin(const CLogin &CLoginCopy);

			///
			///Destruktor
			///
			~CLogin();

			///
			///Metoda zwraca login systemu
			///
			const std::string getLogin() const;

			///
			///Metoda ustawia login systemu
			///
			///@param login - login systemu
			///
			void setLogin(const std::string login);

			///
			///Metoda zwraca has�o systemu
			///
			const std::string getPassword() const;

			///
			///Metoda ustawia has�o systemu
			///
			///@param password - has�o systemu
			///
			void setPassword(const std::string password);

			///
			///Metoda zwraca has�o logowania
			///
			const bool getConnection() const;

			///
			///Metoda ustawia flag�, czy obiekt jest zalogowany do systemu
			///
			///@param connection - flaga, czy obiekt jest zalogowany do systemu
			///
			void setConnection(const bool connection);

			///
			///Metoda logowania do systemu - autoryzacja i walidacja
			///
			///@param login - login systemu
			///
			///@param password - has�o systemu
			///
			bool Login(std::string login, std::string password);

			///
			///Metoda wylogowania z systemu
			///
			void Logout();

		private:

			std::string		m_login;		//login
			std::string		m_password;		//has�o
			bool			m_connection;	//flaga, czy obiekt jest zalogowany do systemu
		};
	}//namespace communication
}//namespace logic
#endif//H_LOGIN_JACK
