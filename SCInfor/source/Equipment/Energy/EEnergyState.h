//  _______________________________________________
// | EEnergyState.h - enumeration of states energy |
// | Jack Flower - February 2014                   |
// |_______________________________________________|
//

#ifndef H_E_ENERGY_STATE_JACK
#define H_E_ENERGY_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu Energy
	///
	enum EEnergyState
	{
		ENERGY_DEFAULT	= 0,
		ENERGY_RESERVE	= 1,
		ENERGY_EMPTY	= 2,
		ENERGY_DAMAGE	= 3,
		ENERGY_DEATH	= 4,
	};

}//namespace equipment
#endif//H_E_ENERGY_STATE_JACK
