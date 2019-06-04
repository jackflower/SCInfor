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
	///Wyliczenie stanów dla obiektu Ventilator
	///
	enum class EVentilatorState
	{
		VENTILATOR_DEFAULT = 0,	//urządzenie jest włączone - wentylator funkcjonuje
		VENTILATOR_DAMAGE = 1,	//urządzenie jest włączone - wentylator stan damage
	};
}//namespace equipment
#endif//H_E_VENTILATOR_STATE_JACK
