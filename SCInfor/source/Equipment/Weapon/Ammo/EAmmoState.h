//  _______________________________________________________
// | EAmmoState.h - wyliczenie stanów magazynka z amunicj¹ |
// | Jack Flower - April 2016                              |
// |_______________________________________________________|
//

#ifndef H_E_AMMO_STATE_JACK
#define H_E_AMMO_STATE_JACK

namespace equipment
{
	namespace weapon
	{
		///
		///Wyliczenie stanów dla obiektów CAmmo
		///
		enum EAmmoState
		{
			AMMO_DEFAULT	= 0,	//stan - default
			AMMO_RESERVE	= 1,	//stan - rezerwa amunicji
			AMMO_EMPTY		= 2,	//stan - magzynek jest pusty
			AMMO_DAMAGE		= 3,	//stan - magzynek uszkodzony
		};
	}//namespace weapon
}//namespace equipment 
#endif//H_E_AMMO_STATE_JACK
