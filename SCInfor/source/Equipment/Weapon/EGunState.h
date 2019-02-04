//  ______________________________________________
// | EGunState.h - wyliczenie kalibr�w uzbrojenia |
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
		///Wyliczenie stan�w dla obiekt�w CGun
		///
		enum EGunState
		{
			GUN_DEFAULT			= 0,	//stan default
			GUN_SHOOT			= 1,	//stan trwania procesu wystrza�u
			GUN_AMMO_LOADING	= 2,	//stan �adowania aminucji (prze�adowanie)
			GUN_AMMO_EMPTY		= 3,	//pusty magazynek - nie ma czym strzela�
			GUN_DAMAGE			= 4,	//uszkodzenie (np. zaci�cie dzia�a)
			GUN_SERVICE			= 5,	//stan serwisowy - wymaga interwencji
			GUN_DEATH			= 6		//death - proces destrukcji obiektu (wreck)
		};
	}//namespace weapon
}//namespace equipment 
#endif//H_E_GUN_STATE_JACK
