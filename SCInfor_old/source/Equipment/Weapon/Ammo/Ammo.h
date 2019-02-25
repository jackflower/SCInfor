//  _________________________________
// | Ammo.h - class definition       |
// | Jack Flower December 2012       |
// |_________________________________|
//

#ifndef H_AMMO_JACK
#define H_AMMO_JACK

#include "../../../Logic/Actor/Actor.h"
#include "../Caliber.h"
#include "EAmmoState.h"

using namespace logic;

namespace equipment
{
	namespace weapon
	{
		///
		///Klasa reprezentuje magazynek na amunicję
		///
		class Ammo : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class PhysicalManager;

			//Aby uzyskać obiekt Ammo, należy wywołać PhysicalManager::CreateAmmo();

		protected:

			///
			///Chroniony konstruktor domyślny - używany wyłącznie przez PhysicalManager
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			Ammo(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param AmmoCopy - obiekt klasy Ammo
			///
			Ammo(const Ammo & AmmoCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
			///
			~Ammo();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			std::string getType();

			///
			///Metoda zwraca kaliber uzbrojenie
			///
			const float getCaliber() const;

			///
			///Metoda ustawia kaliber uzbrojenie
			///
			///@param caliber - rkaliber uzbrojenie
			///
			void setCaliber(const float caliber);

			///
			///Metoda zwraca stałą referencję wyliczenia stanu logiki behawioralnej obiektu
			///
			const EAmmoState getAmmoState() const;

			///
			///Metoda ustawia wyliczenie stanu logiki behawioralnej obiektu
			///
			///@param  &ammo_state - stała referencja na wyliczenie EAmmoState (wyliczenie stanów magazynka z amunicją)
			///
			void setAmmoState(const EAmmoState & ammo_state);

			///
			///Metoda zwraca ilość amunicji w magazynku
			///
			const int getAmmo() const;

			///
			///Metoda ustawia ilość amunicji w magazynku
			///
			///@param ammo - ilość aminicji
			///
			void setAmmo(const int ammo);

			///
			///Metoda zwraca pojemność magazynka na amunicję
			///
			const int getAmmoCapacity() const;

			///
			///Metoda ustawia pojemność magazynka na amunicję
			///
			///@param ammo_capacity - pojemność magazynka na amunicję
			///
			void setAmmoCapacity(const int ammo_capacity);
			
			///
			///Metoda zwraca wartość, przy której następuje komunikat o rezerwie amunicji
			///
			const float getPercentageReserveAmmo() const;

			///
			///Metoda ustawia wartość, przy której następuje komunikat o rezerwie amunicji
			///
			///@param percentage_reserve_ammo - wartość, przy której następuje komunikat o rezerwie amunicji
			///
			void setPercentageReserveAmmo(const float percentage_reserve_ammo);

			///
			///Metoda zwraca wartość flagi, czy obiekt może wysyłać komunikaty o braku amunicji
			///
			const bool getAmmoEmptyMessage() const;

			///
			///Metoda ustawia wartość flagi, czy obiekt może wysyłać komunikaty o braku paliwa
			///
			///@param ammo_empty_message - flaga, czy obiekt może wysyłać komunikaty o braku amunicji
			///
			void setAmmoEmptyMessage(const bool ammo_empty_message);

			///
			///Metoda zwraca nazwę kalibru
			///
			const std::string & getCaliberName() const;

			///
			///Metoda ustawia nazwę kalibru
			///
			///@param name - stała referencja na obiekt klasy std::string
			///
			void setCaliberName(const std::string & name);

			///
			///Metoda zwraca stałą referencję na wyliczenie ECaliber
			///
			const ECaliber & getCaliberType() const;

			///
			///Metoda ustawia referencję na wyliczenie ECaliber
			///
			///@param caliber - stała referencja na wyliczenie ECaliber
			///
			void setCaliberType(const ECaliber & caliber);

			///
			///Metoda zwraca rezerwę amunicji w magazynku
			///
			const int getReserveAmmo() const;

			///
			///Metoda ustawia zwraca rezerwę amunicji w magazynku
			///
			///@param reserve_ammo - rezerwa aminicji
			///
			void setReserveAmmo(const int reserve_ammo);
			
			///
			///Metoda zaopatruje obiekt w amunicję z zewnętrznego źródła
			///
			///@param ammo_out - referencja na amunicję - zewnętrzne źródło aminicji
			///
			void supplyAmmunition(int & ammo_out);

			///
			///Wirtualna metoda aktualizuje animacje w zależności od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void updateAnimations(float dt);

			///
			///Metoda aktulizuje obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///to do...
			//uzupełnić i zaprojektować interface

		private:

			Caliber m_caliber; //kaliber aminicji
			EAmmoState m_ammo_state; //wyliczenie stanów magazynka z amunicją	
			int m_ammo; //ilość amunicji w magazynku
			int m_ammo_capacity; //pojemność magazynka na amunicję
			float m_percentage_reserve_ammo; //procentowa wartość amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
			bool m_ammo_empty_message; //flaga - obiekt może wysyłać komunikaty o braku amunicji
			int m_reserve_ammo; //wyliczona ilość amunicji w magazynku dla rezerwy

		};
	}//namespace weapon
}//namespace equipment
#endif //H_AMMO_JACK
