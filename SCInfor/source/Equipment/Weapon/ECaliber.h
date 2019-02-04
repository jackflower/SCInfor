//  _____________________________________________
// | ECaliber.h - wyliczenie kalibr�w uzbrojenia |
// | Jack Flower - March 2016                    |
// |_____________________________________________|
//

#ifndef H_E_CALIBER_JACK
#define H_E_CALIBER_JACK

namespace equipment
{
	namespace weapon
	{
		///
		///Wyliczenie stan�w dla obiekt�w CCaliber
		///wykorzystywane w przypadku doboru kalibru
		///
		enum ECaliber
		{
			CALIBER_FIREARM				= 0,	//ka�da bro� palna
			CALIBER_SMALL_ARMS			= 1,	//bro� r�czna
			CALIBER_AUTOMATIC_WEAPONS	= 2,	//bro� automatyczna
			CALIBER_RIFLE				= 3,	//strzelba/karabin
			CALIBER_ROCKET				= 4,	//rakieta
			CALIBER_GUN					= 5,	//pistolet
			CALIBER_REVOLVER			= 6,	//rewolwer
			CALIBER_MINE				= 7,	//mina
			CALIBER_CANNON				= 8,	//armata
			CALIBER_MORTAR				= 9		//mo�dzierz
		};
	}//namespace weapon
}//namespace equipment 
#endif//H_E_CALIBER_JACK
