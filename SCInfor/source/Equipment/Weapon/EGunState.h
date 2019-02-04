//  ______________________________________________
// | EGunState.h - wyliczenie kalibrów uzbrojenia |
// | Jack Flower - March 2016                     |
// |______________________________________________|
//

#ifndef H_E_GUN_STATE_JACK
#define H_E_GUN_STATE_JACK

namespace equipment
{
	namespace weapon
	{
		///
		///Wyliczenie stanów dla obiektów CGun
		///
		enum EGunState
		{
			GUN_DEFAULT			= 0,	//stan default
			GUN_SHOOT			= 1,	//stan trwania procesu wystrza³u
			GUN_AMMO_LOADING	= 2,	//stan ³adowania aminucji (prze³adowanie)
			GUN_AMMO_EMPTY		= 3,	//pusty magazynek - nie ma czym strzelaæ
			GUN_DAMAGE			= 4,	//uszkodzenie (np. zaciêcie dzia³a)
			GUN_SERVICE			= 5,	//stan serwisowy - wymaga interwencji
			GUN_DEATH			= 6		//death - proces destrukcji obiektu (wreck)
		};
	}//namespace weapon
}//namespace equipment 
#endif//H_E_GUN_STATE_JACK
