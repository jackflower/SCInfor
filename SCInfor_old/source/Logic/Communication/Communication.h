//  __________________________________________
// | Communication.h - class definition       |
// | Jack Flower - July 2015                  |
// |__________________________________________|
//

#ifndef H_COMMUNICATION_JACK
#define H_COMMUNICATION_JACK


#include "ECommunicationState.h"
#include "Login.h"
#include "ENetworking.h"
#include "../Actor/Actor.h"
#include "../../Equipment/Switch.h"

namespace logic
{
	namespace communication
	{
		///
		///Klasa bazowa reprezentuje funkcjonalność ogólnie pojętej łączności
		///
		class Communication : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt Communication, należy wywołać PhysicalManager::CreateCommunication();

		protected:

			///
			///Chroniony konstruktor domyślny
			///
			///@param uniqueId - stała referencja na obiekt klasy std::wstring
			///
			Communication(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param CommunicationCopy - obiekt klasy Communication
			///
			Communication(const Communication & CommunicationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~Communication( );

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca nazwę modułu komunikacyjnego
			///
			const std::string getCommunicationName() const;

			///
			///Metoda ustawia nazwę modułu komunikacyjnego
			///
			///@param communication_name - nazwa modułu komunikacji - stała referencja na obiekt klasy std::string
			///
			void setCommunicationName(const std::string & communication_name);

			///
			///Metoda zwraca flagę, czy obiekt jest zalogowany
			///
			const bool getConnection() const;

			///
			///Metoda ustawia flagę zalogowania obiektu
			///
			///@param connected - flaga, czy po zalogowaniu można dokonać autoryzacji (walidacji)
			///
			void setConnection(const bool connected);

			///
			///Metoda zwraca zasięg topograficzny pracy przekaźnika
			///
			const float getRange() const;

			///
			///Metoda ustawia zasięg topograficzny pracy przekaźnika
			///
			///@param range - zasięg przekaźnika
			///
			void setRange(const float range);

			///
			///Metoda zwraca czas co jaki moduł się resetuje/testuje
			///
			const float getResetDuration() const;

			///
			///Metoda ustawia czas co jaki moduł się resetuje/testuje
			///
			///@param reset_duration - czas co jaki moduł się resetuje/testuje
			///
			void setResetDuration(const float reset_duration);

			///
			///Metoda zwraca stałą referencję na obiekt klasy Login - opakowanie logowania
			///
			Login & getLoginModule();

			///
			///Metoda ustawia stałą referencję na obiekt klasy Login - opakowanie logowania
			///
			///@param login_module - stała referencja na obiekt klasy Login
			///
			void setLoginModule(const Login & login_module);

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
			void setPassword(const std::string password);

			///
			///Metoda zwraca referencję dla rodzaju technologii połączenia sieciowego
			///
			const ENetworking & getNetworking() const;

			///
			///Metoda ustawia referencję dla rodzaju technologii połączenia sieciowego
			///
			///@param networking - stała referencja na wyliczenie ENetworking
			///
			void setNetworking(const ENetworking & networking);

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			std::string m_communication_name; //nazwa modułu łączności
			Switch m_unit_controller; //włącznik, sterownik, moduł zarządzania, starter, stacyjka
			ECommunicationState e_communication_state; //wyliczenie stanów Communication
			bool m_connected; //flaga, czy po zalogowaniu nastąpiła autoryzacja (walidacja)
			float m_range; //zasięg pracy urządzenie - nadajnik/odbiornik
			float m_reset_duration; //czas co jaki moduł się resetuje/testuje
			float m_duration; //obliczany czas co jaki moduł się resetuje/testuje
			Login m_login_module; //moduł obiektu logowania
			ENetworking m_networking; //rodzaj technologii połączenia sieciowego (IP, DHCP, Broadcast)

			//Prywatna metoda zwraca stan, czy dane dane autoryzacji są poprawne i czy obiekt jest zalogowany
			const bool IsConnected() const { return false; }
		};
	}//namespace communication
}//namespace logic
#endif//H_COMMUNICATION_JACK
