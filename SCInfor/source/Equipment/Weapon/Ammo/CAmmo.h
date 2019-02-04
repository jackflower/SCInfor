//  __________________________________
// | CAmmo.h - class definition       |
// | Jack Flower December 2012        |
// |__________________________________|
//

#ifndef H_AMMO_JACK
#define H_AMMO_JACK

#include "../../../Logic/Actor/CActor.h"
#include "../CCaliber.h"
#include "EAmmoState.h"

using namespace logic;

namespace equipment
{
	namespace weapon
	{
		///
		///Klasa reprezentuje magazynek na amunicj�
		///
		class CAmmo : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CPhysicalManager;

			//Aby uzyska� obiekt CAmmo, nale�y wywo�a� CPhysicalManager::CreateAmmo();

		protected:

			///
			///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CPhysicalManager
			///
			CAmmo(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CAmmoCopy - obiekt klasy CAmmo
			///
			CAmmo(const CAmmo& CAmmoCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
			///
			~CAmmo();

		public:

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			std::string GetType();

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
			///Metoda zwraca sta�� referencj� wyliczenia stanu logiki behawioralnej obiektu
			///
			const EAmmoState getAmmoState() const;

			///
			///Metoda ustawia wyliczenie stanu logiki behawioralnej obiektu
			///
			///@param  &ammo_state - sta�a referencja na wyliczenie EAmmoState (wyliczenie stan�w magazynka z amunicj�)
			///
			void setAmmoState(const EAmmoState & ammo_state);

			///
			///Metoda zwraca ilo�� amunicji w magazynku
			///
			const int getAmmo() const;

			///
			///Metoda ustawia ilo�� amunicji w magazynku
			///
			///@param ammo - ilo�� aminicji
			///
			void setAmmo(const int ammo);

			///
			///Metoda zwraca pojemno�� magazynka na amunicj�
			///
			const int getAmmoCapacity() const;

			///
			///Metoda ustawia pojemno�� magazynka na amunicj�
			///
			///@param ammo_capacity - pojemno�� magazynka na amunicj�
			///
			void setAmmoCapacity(const int ammo_capacity);
			
			///
			///Metoda zwraca warto��, przy kt�rej nast�puje komunikat o rezerwie amunicji
			///
			const float getPercentageReserveAmmo() const;

			///
			///Metoda ustawia warto��, przy kt�rej nast�puje komunikat o rezerwie amunicji
			///
			///@param percentage_reserve_ammo - warto��, przy kt�rej nast�puje komunikat o rezerwie amunicji
			///
			void setPercentageReserveAmmo(const float percentage_reserve_ammo);

			///
			///Metoda zwraca warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku amunicji
			///
			const bool GetAmmoEmptyMessage() const;

			///
			///Metoda ustawia warto�� flagi, czy obiekt mo�e wysy�a� komunikaty o braku paliwa
			///
			///@param ammo_empty_message - flaga, czy obiekt mo�e wysy�a� komunikaty o braku amunicji
			///
			void SetAmmoEmptyMessage(const bool ammo_empty_message);

			///
			///Metoda zwraca nazw� kalibru
			///
			const std::string & getCaliberName() const;

			///
			///Metoda ustawia nazw� kalibru
			///
			///@param & name - sta�a referencja na obiekt klasy std::string
			///
			void setCaliberName(const std::string & name);

			///
			///Metoda zwraca sta�� referencj� na wyliczenie ECaliber
			///
			const ECaliber & getCaliberType() const;

			///
			///Metoda ustawia referencj� na wyliczenie ECaliber
			///
			///@param & caliber - sta�a referencja na wyliczenie ECaliber
			///
			void setCaliberType(const ECaliber & caliber);

			///
			///Metoda zwraca rezerw� amunicji w magazynku
			///
			const int getReserveAmmo() const;

			///
			///Metoda ustawia zwraca rezerw� amunicji w magazynku
			///
			///@param reserve_ammo - rezerwa aminicji
			///
			void setReserveAmmo(const int reserve_ammo);
			
			///
			///Metoda zaopatruje obiekt w amunicj� z zewn�trznego �r�d�a
			///
			///@param & ammo_out - referencja na amunicj� - zewn�trzne �r�d�o aminicji
			///
			void supplyAmmunition(int & ammo_out);

			///
			///Wirtualna metoda aktualizuje animacje w zale�no�ci od stanu logiki obiektu
			///
			///@param dt - czas
			///
			virtual void UpdateAnimations(float dt);

			///
			///Metoda aktulizuje obiekt
			///
			///@param dt - czas
			///
			virtual void Update(float dt);

		private:

			CCaliber		m_caliber;					//kaliber aminicji
			EAmmoState		m_ammo_state;				//wyliczenie stan�w magazynka z amunicj�	
			int				m_ammo;						//ilo�� amunicji w magazynku
			int				m_ammo_capacity;			//pojemno�� magazynka na amunicj�
			float			m_percentage_reserve_ammo;	//procentowa warto�� amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
			bool			m_ammo_empty_message;		//flaga - obiekt mo�e wysy�a� komunikaty o braku amunicji
			int				m_reserve_ammo;				//wyliczona ilo�� amunicji w magazynku dla rezerwy

		};
	}//namespace weapon
}//namespace equipment
#endif //H_AMMO_JACK
