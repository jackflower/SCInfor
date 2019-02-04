//  _______________________________________________________
// | EVentilatorState.h - enumeration of states ventilator |
// | Jack Flower - May 2016                                              |
// |_____________________________________________________________________|
//

#ifndef H_E_VENTILATOR_STATE_JACK
#define H_E_VENTILATOR_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stan�w dla obiektu CVentilator
	///
	enum EVentilatorState
	{
		VENTILATOR_DEFAULT = 0,	//urz�dzenie jest w��czone - wentylator funkcjonuje
		VENTILATOR_DAMAGE = 1,	//urz�dzenie jest w��czone - wentylator stan damage
	};
}//namespace equipment
#endif//H_E_VENTILATOR_STATE_JACK
