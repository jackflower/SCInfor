//  ___________________________________________
// | CCommunication.h - class definition       |
// | Jack Flower - July 2015                   |
// |___________________________________________|
//

#ifndef H_COMMUNICATION_JACK
#define H_COMMUNICATION_JACK

#include "../Actor/CActor.h"
#include "../../Equipment/CSwitch.h"
#include "ECommunicationState.h"
#include "CLogin.h"
#include "ENetworking.h"

namespace logic
{
	namespace communication
	{
		///
		///Klasa bazowa reprezentuje funkcjonalnoœæ ogólnie pojêtej ³¹cznoœci
		///
		class CCommunication : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CCommunication, nale¿y wywo³aæ CPhysicalManager::CreateCommunication();

		protected:

			///
			///Chroniony konstruktor domyœlny
			///
			///@param &uniqueId - sta³a referencja na obiekt klasy std::wstring
			///
			CCommunication(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CCommunicationCopy - obiekt klasy CCommunication
			///
			CCommunication(const CCommunication &CCommunicationCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CCommunication(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazwê modu³u komunikacyjnego
			///
			const std::string GetCommunicationName() const;

			///
			///Metoda ustawia nazwê modu³u komunikacyjnego
			///
			///@param & communication_name - nazwa modu³u komunikacji - sta³a referencja na obiekt klasy std::string
			///
			void SetCommunicationName(const std::string& communication_name);

			///
			///Metoda zwraca flagê, czy obiekt jest zalogowany
			///
			const bool getConnection() const;

			///
			///Metoda ustawia flagê zalogowania obiektu
			///
			///@param connected - flaga, czy po zalogowaniu mo¿na dokonaæ autoryzacji (walidacji)
			///
			void setConnection(const bool connected);

			///
			///Metoda zwraca zasiêg topograficzny pracy przekaŸnika
			///
			const float getRange() const;

			///
			///Metoda ustawia zasiêg topograficzny pracy przekaŸnika
			///
			///@param range - zasiêg przekaŸnika
			///
			void setRange(const float range);

			///
			///Metoda zwraca czas co jaki modu³ siê resetuje/testuje
			///
			const float getResetDuration() const;

			///
			///Metoda ustawia czas co jaki modu³ siê resetuje/testuje
			///
			///@param reset_duration - czas co jaki modu³ siê resetuje/testuje
			///
			void setResetDuration(const float reset_duration);

			///
			///Metoda zwraca referencjê na obiekt klasy CLogin - opakowanie logowania
			///
			CLogin &getLoginModule() { return m_login_module; }

			///
			///Metoda zwraca referencjê dla rodzaju technologii po³¹czenia sieciowego
			///
			const ENetworking &getNetworking() const;

			///
			///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		private:

			std::string				m_communication_name;	//nazwa modu³u ³¹cznoœci
			CSwitch					m_unit_controller;		//w³¹cznik, sterownik, modu³ zarz¹dzania, starter, stacyjka
			ECommunicationState		e_communication_state;	//wyliczenie stanów CCommunication
			bool					m_connected;			//flaga, czy po zalogowaniu nast¹pi³a autoryzacja (walidacja)
			float					m_range;				//zasiêg pracy urz¹dzenie - nadajnik/odbiornik
			float					m_reset_duration;		//czas co jaki modu³ siê resetuje/testuje
			float					m_duration;				//obliczany czas co jaki modu³ siê resetuje/testuje
			CLogin					m_login_module;			//obiekt logowania
			ENetworking				m_networking;			//rodzaj technologii po³¹czenia sieciowego (IP, DHCP, Broadcast)

			//Prywatna metoda zwraca stan, czy dane dane autoryzacji s¹ poprawne i czy obiekt jest zalogowany
			const bool IsConnected() const { return false; }
		};
	}//namespace communication
}//namespace logic
#endif//H_COMMUNICATION_JACK
