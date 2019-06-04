//  _______________________________________________________
// | EEnergyTankState.h - enumeration of states energytank |
// | Jack Flower - May 2014                                |
// |_______________________________________________________|
//

#ifndef H_E_ENERGYTANK_STATE_JACK
#define H_E_ENERGYTANK_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu EnergyTank
	///
	enum class EEnergyTankState
	{
		ENERGYTANK_DEFAULT = 0,
		ENERGYTANK_RESERVE = 1,
		ENERGYTANK_EMPTY = 2,
		ENERGYTANK_DAMAGE = 3,
	};
}//namespace equipment
#endif//H_E_ENERGYTANK_STATE_JACK
