//  _____________________________________________
// | ECaliber.h - wyliczenie kalibrów uzbrojenia |
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
		///Wyliczenie stanów dla obiektów Caliber
		///wykorzystywane w przypadku doboru kalibru
		///
		enum ECaliber
		{
			CALIBER_FIREARM				= 0,	//każda broń palna
			CALIBER_SMALL_ARMS			= 1,	//broń ręczna
			CALIBER_AUTOMATIC_WEAPONS	= 2,	//broń automatyczna
			CALIBER_RIFLE				= 3,	//strzelba/karabin
			CALIBER_ROCKET				= 4,	//rakieta
			CALIBER_GUN					= 5,	//pistolet
			CALIBER_REVOLVER			= 6,	//rewolwer
			CALIBER_MINE				= 7,	//mina
			CALIBER_CANNON				= 8,	//armata
			CALIBER_MORTAR				= 9		//moździerz
		};
	}//namespace weapon
}//namespace equipment 
#endif//H_E_CALIBER_JACK
