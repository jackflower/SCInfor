//  _____________________________________________________________________
// | ENetworking.h - wyliczenie rodzajów technologii połączeń sieciowych |
// | Jack Flower - August 2015                                           |
// |_____________________________________________________________________|
//

#ifndef H_NETWORKING_JACK
#define H_NETWORKING_JACK

namespace logic
{
	namespace communication
	{
		///
		///Wyliczenie rodzajów technologii połączeń sieciowych
		///
		enum ENetworking
		{
			TYPE_DEFAULT	=	0,//any type (każdy - uniwersalny)
			TYPE_IP			=	1,
			TYPE_DHCP		=	2,
			TYPE_BROADCAST	=	3
		};
	}//namespace communication
}//namespace logic
#endif//H_NETWORKING_JACK
