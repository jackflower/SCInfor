//  _________________________________________________________
// | ECommunicationState.h - wyliczenie stanów Communication |
// | Jack Flower - July 2015                                 |
// |_________________________________________________________|
//

#ifndef H_COMMUNICATION_STATE_JACK
#define H_COMMUNICATION_STATE_JACK

namespace logic
{
	namespace communication
	{
		///
		///Wyliczenie stanów dla obiektu Communication
		///
		enum class ECommunicationState
		{
			COMMUNICATION_DEFAULT = 0,
			COMMUNICATION_SEARCH = 1,
			COMMUNICATION_LOGIN = 2,
			COMMUNICATION_AUTHORIZATION = 3,
			COMMUNICATION_UPDATE = 4,
			COMMUNICATION_DAMAGE = 5,
			COMMUNICATION_DEATH = 6,
		};
	}//namespace communication
}//namespace logic
#endif//H_COMMUNICATION_STATE_JACK
