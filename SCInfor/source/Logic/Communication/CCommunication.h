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
		///Klasa bazowa reprezentuje funkcjonalno�� og�lnie poj�tej ��czno�ci
		///
		class CCommunication : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CCommunication, nale�y wywo�a� CPhysicalManager::CreateCommunication();

		protected:

			///
			///Chroniony konstruktor domy�lny
			///
			///@param &uniqueId - sta�a referencja na obiekt klasy std::wstring
			///
			CCommunication(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CCommunicationCopy - obiekt klasy CCommunication
			///
			CCommunication(const CCommunication &CCommunicationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			~CCommunication(void);

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazw� modu�u komunikacyjnego
			///
			const std::string GetCommunicationName() const;

			///
			///Metoda ustawia nazw� modu�u komunikacyjnego
			///
			///@param & communication_name - nazwa modu�u komunikacji - sta�a referencja na obiekt klasy std::string
			///
			void SetCommunicationName(const std::string& communication_name);

			///
			///Metoda zwraca flag�, czy obiekt jest zalogowany
			///
			const bool getConnection() const;

			///
			///Metoda ustawia flag� zalogowania obiektu
			///
			///@param connected - flaga, czy po zalogowaniu mo�na dokona� autoryzacji (walidacji)
			///
			void setConnection(const bool connected);

			///
			///Metoda zwraca zasi�g topograficzny pracy przeka�nika
			///
			const float getRange() const;

			///
			///Metoda ustawia zasi�g topograficzny pracy przeka�nika
			///
			///@param range - zasi�g przeka�nika
			///
			void setRange(const float range);

			///
			///Metoda zwraca czas co jaki modu� si� resetuje/testuje
			///
			const float getResetDuration() const;

			///
			///Metoda ustawia czas co jaki modu� si� resetuje/testuje
			///
			///@param reset_duration - czas co jaki modu� si� resetuje/testuje
			///
			void setResetDuration(const float reset_duration);

			///
			///Metoda zwraca referencj� na obiekt klasy CLogin - opakowanie logowania
			///
			CLogin &getLoginModule() { return m_login_module; }

			///
			///Metoda zwraca referencj� dla rodzaju technologii po��czenia sieciowego
			///
			const ENetworking &getNetworking() const;

			///
			///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		private:

			std::string				m_communication_name;	//nazwa modu�u ��czno�ci
			CSwitch					m_unit_controller;		//w��cznik, sterownik, modu� zarz�dzania, starter, stacyjka
			ECommunicationState		e_communication_state;	//wyliczenie stan�w CCommunication
			bool					m_connected;			//flaga, czy po zalogowaniu nast�pi�a autoryzacja (walidacja)
			float					m_range;				//zasi�g pracy urz�dzenie - nadajnik/odbiornik
			float					m_reset_duration;		//czas co jaki modu� si� resetuje/testuje
			float					m_duration;				//obliczany czas co jaki modu� si� resetuje/testuje
			CLogin					m_login_module;			//obiekt logowania
			ENetworking				m_networking;			//rodzaj technologii po��czenia sieciowego (IP, DHCP, Broadcast)

			//Prywatna metoda zwraca stan, czy dane dane autoryzacji s� poprawne i czy obiekt jest zalogowany
			const bool IsConnected() const { return false; }
		};
	}//namespace communication
}//namespace logic
#endif//H_COMMUNICATION_JACK
