//  _____________________________________________________
// | ESolarCellState.h - enumeration of states solarcell |
// | Jack Flower - July 2014                             |
// |_____________________________________________________|
//

#ifndef H_E_SOLARCELL_STATE_JACK
#define H_E_SOLARCELL_STATE_JACK

namespace logic
{
	///
	///Wyliczenie stanów dla obiektu SolarCell
	///
	enum ESolarCellState
	{
		SOLARCELL_DEFAULT		= 0,
		SOLARCELL_UPDATE_ENERGY = 1,
		SOLARCELL_DAMAGE		= 2,
		SOLARCELL_DEATH			= 3
	};

	const unsigned int CALIBRATION_FACTOR_ANGLE = 90;
}//namespace logic
#endif//H_E_SOLARCELL_STATE_JACK
