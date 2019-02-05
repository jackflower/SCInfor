//  _______________________________________________
// | EEngineState.h - enumeration of states engine |
// | Jack Flower - December 2013                   |
// |_______________________________________________|
//

#ifndef H_E_ENGINE_STATE_JACK
#define H_E_ENGINE_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu CEngine
	///
	enum EEngineState
	{
		ENGINE_DEFAULT	= 0,
		ENGINE_START	= 1,
		ENGINE_STOP		= 2,
		ENGINE_DAMAGE	= 3,
		ENGINE_DEATH	= 4,
	};

}//namespace equipment
#endif//H_E_ENGINE_STATE_JACK
