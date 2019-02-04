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
		///Klasa reprezentuje magazynek na amunicjê
		///
		class CAmmo : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CAmmo, nale¿y wywo³aæ CPhysicalManager::CreateAmmo();

		protected:

			///
			///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			CAmmo(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CAmmoCopy - obiekt klasy CAmmo
			///
			CAmmo(const CAmmo& CAmmoCopy);

			///
			///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
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
			///Metoda zwraca sta³¹ referencjê wyliczenia stanu logiki behawioralnej obiektu
			///
			const EAmmoState getAmmoState() const;

			///
			///Metoda ustawia wyliczenie stanu logiki behawioralnej obiektu
			///
			///@param  &ammo_state - sta³a referencja na wyliczenie EAmmoState (wyliczenie stanów magazynka z amunicj¹)
			///
			void setAmmoState(const EAmmoState & ammo_state);

			///
			///Metoda zwraca iloœæ amunicji w magazynku
			///
			const int getAmmo() const;

			///
			///Metoda ustawia iloœæ amunicji w magazynku
			///
			///@param ammo - iloœæ aminicji
			///
			void setAmmo(const int ammo);

			///
			///Metoda zwraca pojemnoœæ magazynka na amunicjê
			///
			const int getAmmoCapacity() const;

			///
			///Metoda ustawia pojemnoœæ magazynka na amunicjê
			///
			///@param ammo_capacity - pojemnoœæ magazynka na amunicjê
			///
			void setAmmoCapacity(const int ammo_capacity);
			
			///
			///Metoda zwraca wartoœæ, przy której nastêpuje komunikat o rezerwie amunicji
			///
			const float getPercentageReserveAmmo() const;

			///
			///Metoda ustawia wartoœæ, przy której nastêpuje komunikat o rezerwie amunicji
			///
			///@param percentage_reserve_ammo - wartoœæ, przy której nastêpuje komunikat o rezerwie amunicji
			///
			void setPercentageReserveAmmo(const float percentage_reserve_ammo);

			///
			///Metoda zwraca wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku amunicji
			///
			const bool GetAmmoEmptyMessage() const;

			///
			///Metoda ustawia wartoœæ flagi, czy obiekt mo¿e wysy³aæ komunikaty o braku paliwa
			///
			///@param ammo_empty_message - flaga, czy obiekt mo¿e wysy³aæ komunikaty o braku amunicji
			///
			void SetAmmoEmptyMessage(const bool ammo_empty_message);

			///
			///Metoda zwraca nazwê kalibru
			///
			const std::string & getCaliberName() const;

			///
			///Metoda ustawia nazwê kalibru
			///
			///@param & name - sta³a referencja na obiekt klasy std::string
			///
			void setCaliberName(const std::string & name);

			///
			///Metoda zwraca sta³¹ referencjê na wyliczenie ECaliber
			///
			const ECaliber & getCaliberType() const;

			///
			///Metoda ustawia referencjê na wyliczenie ECaliber
			///
			///@param & caliber - sta³a referencja na wyliczenie ECaliber
			///
			void setCaliberType(const ECaliber & caliber);

			///
			///Metoda zwraca rezerwê amunicji w magazynku
			///
			const int getReserveAmmo() const;

			///
			///Metoda ustawia zwraca rezerwê amunicji w magazynku
			///
			///@param reserve_ammo - rezerwa aminicji
			///
			void setReserveAmmo(const int reserve_ammo);
			
			///
			///Metoda zaopatruje obiekt w amunicjê z zewnêtrznego Ÿród³a
			///
			///@param & ammo_out - referencja na amunicjê - zewnêtrzne Ÿród³o aminicji
			///
			void supplyAmmunition(int & ammo_out);

			///
			///Wirtualna metoda aktualizuje animacje w zale¿noœci od stanu logiki obiektu
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
			EAmmoState		m_ammo_state;				//wyliczenie stanów magazynka z amunicj¹	
			int				m_ammo;						//iloœæ amunicji w magazynku
			int				m_ammo_capacity;			//pojemnoœæ magazynka na amunicjê
			float			m_percentage_reserve_ammo;	//procentowa wartoœæ amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
			bool			m_ammo_empty_message;		//flaga - obiekt mo¿e wysy³aæ komunikaty o braku amunicji
			int				m_reserve_ammo;				//wyliczona iloœæ amunicji w magazynku dla rezerwy

		};
	}//namespace weapon
}//namespace equipment
#endif //H_AMMO_JACK
