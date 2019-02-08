//  _______________________________________________
// | MagazineAmmunition.h - class definition       |
// | Jack Flower June 2014.                        |
// |_______________________________________________|
//
#ifndef H_MAGAZINE_AMMUNITION_JACK
#define H_MAGAZINE_AMMUNITION_JACK

#include <vector>
#include "../Caliber.h"
#include "../../../Logic/Actor/Actor.h"
#include "../../../RTTI/RTTI.h"

///
///Forwad declaration
///
namespace logic
{
	class CBullet;
}

using namespace logic;

namespace equipment
{
	namespace weapon
	{
		///
		///Klasa reprezentuje magazynek amunicji
		///
		class MagazineAmmunition : public Actor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class CPhysicalManager;

			//Aby uzyskać obiekt MagazineAmmunition, należy wywołać CPhysicalManager::CreateMagazineAmmunition();

		protected:
			
			///
			///Chroniony konstruktor domyślny - używany wyłącznie przez CPhysicalManager
			///
			///@param uniqueId - unikalny identyfikator obiektu - stała referncja na obiekt klasy std::wstring
			///
			MagazineAmmunition(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param MagazineAmmunitionCopy - obiekt klasy MagazineAmmunition
			///
			MagazineAmmunition(const MagazineAmmunition & MagazineAmmunitionCopy);

			///
			//Chroniony destruktor wirtualny - używany wyłącznie przez CPhysicalManager
			///
			~MagazineAmmunition();

			///to do...
			//uzupełnić i zaprojektować interface

		public:

			//to do: future...prototype
			//void setMagazineAmmunitionCaliber(Caliber magazine_ammunition_caliber);

		private:
	
			typedef std::vector<CBullet *> BulletVector; //definicja typu - (kontener) na pociski

			std::string m_ammunition_name; //nazwa logiki amunicji
			int m_ammunition_capacity; //pojemność magazynka na amunicję
			Caliber m_magazine_ammunition_caliber;//kaliber dla aminicji w magazynku (dopasowanie pocisków do magazynka)
			float m_percentage_reserve_ammunition; //procentowa wartość amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
			BulletVector m_bullets; //wektor (tablica) wskaźników na pociski
		};
	}//namespace weapon
}//namespace equipment
#endif//H_MAGAZINE_AMMUNITION_JACK
