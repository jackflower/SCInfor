//  ___________________________________________________
// | EFuelTankState.h - enumeration of states fueltank |
// | Jack Flower - April 2014                          |
// |___________________________________________________|

#ifndef H_E_FUELTANK_STATE_JACK
#define H_E_FUELTANK_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu FuelTank
	///
	enum EFuelTankState
	{
		FUELTANK_DEFAULT = 0,
		FUELTANK_RESERVE = 1,
		FUELTANK_EMPTY = 2,
		FUELTANK_DAMAGE = 3,
	};

}//namespace equipment
#endif//H_E_FUELTANK_STATE_JACK
