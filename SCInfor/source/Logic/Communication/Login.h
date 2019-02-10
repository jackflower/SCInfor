//  __________________________________
// | Login.h - class definition       |
// | Jack Flower - July 2015          |
// |__________________________________|
//

#ifndef H_LOGIN_JACK
#define H_LOGIN_JACK

#include <string>
#include "../../RTTI/RTTI.h"

namespace logic
{
	namespace communication
	{
		class Login
		{
		public:

			///
			///Konstruktor
			///
			Login();

			///
			///Konstruktor parametryczny
			///
			///@param login - flaga zalogowania
			///
			Login(bool login);

			///
			///Konstruktor kopiujący
			///
			///@param LoginCopy - stała referencja na obiekt klasy Login
			///
			Login(const Login & LoginCopy);

			///
			///Destruktor
			///
			~Login();

			///
			///Metoda zwraca login systemu
			///
			const std::string getLogin() const;

			///
			///Metoda ustawia login systemu
			///
			///@param login - login systemu
			///
			void setLogin(const std::string & login);

			///
			///Metoda zwraca hasło systemu
			///
			const std::string getPassword() const;

			///
			///Metoda ustawia hasło systemu
			///
			///@param password - hasło systemu
			///
			void setPassword(const std::string & password);

			///
			///Metoda zwraca hasło logowania
			///
			const bool getConnection() const;

			///
			///Metoda ustawia flagę, czy obiekt jest zalogowany do systemu
			///
			///@param connection - flaga, czy obiekt jest zalogowany do systemu
			///
			void setConnection(const bool connection);

			///
			///Metoda logowania do systemu - autoryzacja i walidacja
			///
			///@param login - login systemu
			///
			///@param password - hasło systemu
			///
			bool processLogin(std::string login, std::string password);

			///
			///Metoda wylogowania z systemu
			///
			void processLogout();

		private:

			std::string		m_login;		//login
			std::string		m_password;		//hasło
			bool			m_connection;	//flaga, czy obiekt jest zalogowany do systemu
		};
	}//namespace communication
}//namespace logic
#endif//H_LOGIN_JACK
