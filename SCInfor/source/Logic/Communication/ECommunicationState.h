// ___________________________________________________________
// | ECommunicationState.h - wyliczenie stanów CCommunication |
// | Jack Flower - July 2015                                  |
//|___________________________________________________________|
//

#ifndef H_COMMUNICATION_STATE_JACK
#define H_COMMUNICATION_STATE_JACK

namespace logic
{
	namespace communication
	{
		///
		///Wyliczenie stanów dla obiektu CCommunication
		///
		enum ECommunicationState
		{
			COMMUNICATION_DEFAULT			= 0,
			COMMUNICATION_SEARCH			= 1,
			COMMUNICATION_LOGIN				= 2,
			COMMUNICATION_AUTHORIZATION		= 3,
			COMMUNICATION_UPDATE			= 4,
			COMMUNICATION_DAMAGE			= 5,
			COMMUNICATION_DEATH				= 6,
		};
	}//namespace communication
}//namespace logic
#endif//H_COMMUNICATION_STATE_JACK
