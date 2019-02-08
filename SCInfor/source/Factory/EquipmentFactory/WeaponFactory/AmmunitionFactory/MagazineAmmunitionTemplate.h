//  _____________________________________________________
// | MagazineAmmunitionTemplate.h - class definition     |
// | Jack Flower February 2019                           |
// |_____________________________________________________|
//

#ifndef H_MAGAZINE_AMMUNITION_TEMPLATE_JACK
#define H_MAGAZINE_AMMUNITION_TEMPLATE_JACK

#include "../../../ActorTemplate.h"

namespace factory
{
	///
	///Klasa reprezentuje wzorzec magazynka amunicji
	///
	class MagazineAmmunitionTemplate : public ActorTemplate
	{
		RTTI_DECL;

	public:
		///
		///Konstruktor domyślny
		///
		MagazineAmmunitionTemplate();

		///
		///Destruktor wirtualny
		///
		~MagazineAmmunitionTemplate();

	private:

		//2019-02-07
		//to do:


		//typedef std::vector<CBullet *> BulletVector; //definicja typu - (kontener) na pociski

		//std::string m_ammunition_name; //nazwa logiki amunicji
		//int m_ammunition_capacity; //pojemność magazynka na amunicję
		//Caliber m_magazine_ammunition_caliber;//kaliber dla aminicji w magazynku (dopasowanie pocisków do magazynka)
		//float m_percentage_reserve_ammunition; //procentowa wartość amunicji w magazynku - komunikat o rezerwie (default 10% - konstruktor)
		//BulletVector m_bullets; //wektor (tablica) wskaźników na pociski

	};
}//namespace factory

#endif//H_MAGAZINE_AMMUNITION_TEMPLATE_JACK
