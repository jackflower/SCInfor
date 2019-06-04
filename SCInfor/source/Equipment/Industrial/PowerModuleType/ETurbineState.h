//  _________________________________________________
// | ETurbineState.h - enumeration of states turbine |
// | Jack Flower - July 2014                         |
// |_________________________________________________|
//

#ifndef H_E_TURBINE_STATE_JACK
#define H_E_TURBINE_STATE_JACK

namespace logic
{
	///
	///Wyliczenie stanów dla obiektu WindTurbine
	///
	enum class ETurbineState
	{
		TURBINE_DEFAULT = 0,
		TURBINE_CARGO_DOOR_OPEN = 1,
		TURBINE_CARGO_DOOR_CLOSE = 2,
		TURBINE_UPDATE_ENERGY = 3,
		TURBINE_DAMAGE = 4,
		TURBINE_DEATH = 5,
	};

	const unsigned int FULL_ROTATION = 359;
}//namespace logic
#endif//H_E_TURBINE_STATE_JACK
