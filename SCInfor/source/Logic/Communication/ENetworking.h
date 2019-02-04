// ______________________________________________________________________
// | ENetworking.h - wyliczenie rodzaj�w technologii po��cze� sieciowych |
// | Jack Flower - August 2015                                           |
//|______________________________________________________________________|
//

#ifndef H_NETWORKING_JACK
#define H_NETWORKING_JACK

namespace logic
{
	namespace communication
	{
		///
		///Wyliczenie rodzaj�w technologii po��cze� sieciowych
		///
		enum ENetworking
		{
			TYPE_DEFAULT	=	0,//any type (ka�dy - uniwersalny)
			TYPE_IP			=	1,
			TYPE_DHCP		=	2,
			TYPE_BROADCAST	=	3
		};
	}//namespace communication
}//namespace logic
#endif//H_NETWORKING_JACK
