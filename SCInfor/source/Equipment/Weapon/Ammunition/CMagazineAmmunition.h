//  ________________________________________________
// | CMagazineAmmunition.h - class definition       |
// | Jack Flower June 2014.                         |
// |________________________________________________|
//

#ifndef H_MAGAZINE_AMMUNITION_JACK
#define H_MAGAZINE_AMMUNITION_JACK

#include "../../../Logic/Actor/CActor.h"
#include "../../../RTTI/RTTI.h"
#include <vector>

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
		class CMagazineAmmunition : public CActor
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaŸni
			///
			friend class CPhysicalManager;

			//Aby uzyskaæ obiekt CMagazineAmmunition, nale¿y wywo³aæ CPhysicalManager::CreateMagazineAmmunition();

		protected:
			
			///
			///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			CMagazineAmmunition(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj¹cy
			///
			///@param CMagazineAmmunitionCopy - obiekt klasy CMagazineAmmunition
			///
			CMagazineAmmunition(const CMagazineAmmunition& CMagazineAmmunitionCopy);

			///
			//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
			///
			~CMagazineAmmunition();

		public:

		private:
	
			typedef std::vector<CBullet *>	BulletVector;	//definicja typu - (kontener) na pociski

			std::string		m_ammunition_name;					//nazwa logiki amunicji
			int				m_ammunition_capacity;				//pojemnoœæ magazynka na amunicjê
			float			m_bullets_caliber;					//kaliber pocisków dla amunicji w magazynku
			float			m_percentage_reserve_ammunition;	//procentowa wartoœæ amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
			BulletVector	m_bullets;							//wektor (tablica) wskaŸników na pociski

			//pobraæ metody (interface - opakowania) z klasy Ammo)
			//2014-06-20
		};
	}//namespace weapon
}//namespace equipment
#endif//H_MAGAZINE_AMMUNITION_JACK