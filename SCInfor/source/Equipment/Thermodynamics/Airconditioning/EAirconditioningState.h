//  _________________________________________________________________
// | EAirconditioningState.h - enumeration of states airconditioning |
// | Jack Flower - May 2016                                          |
// |_________________________________________________________________|
//

#ifndef H_E_AIRCONDITIONING_STATE_JACK
#define H_E_AIRCONDITIONING_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu CAirconditioning
	///
	enum EAirconditioningState
	{
		AIRCONDITIONING_DEFAULT		= 0,
		AIRCONDITIONING_HEATING		= 1,
		AIRCONDITIONING_COOLING		= 2,
		AIRCONDITIONING_INEFFECTIVE	= 3,
		AIRCONDITIONING_DAMAGE		= 4,
	};
}//namespace equipment
#endif//H_E_AIRCONDITIONING_STATE_JACK
