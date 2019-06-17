//  __________________________________________________________
// | EPowerRelayStationState.h - enumeration of states energy |
// | Jack Flower - July 2015                                  |
// |__________________________________________________________|
//

#ifndef H_POWER_RELAY_STATION_STATE_JACK
#define H_POWER_RELAY_STATION_STATE_JACK

namespace logic
{
	namespace energetics
	{
		///
		///Wyliczenie stanów dla obiektu PowerRelayStation
		///
		enum class EPowerRelayStationState
		{
			POWER_RELAY_STATION_DEFAULT = 0,
			POWER_RELAY_STATION_UPDATE_CONNECTION = 1,
			POWER_RELAY_STATION_DISCONNECT = 2,
			POWER_RELAY_STATION_DAMAGE = 3,
			POWER_RELAY_STATION_DEATHT = 4,
		};
	}//namespace energetics
}//namespace logic
#endif//H_POWER_RELAY_STATION_STATE_JACK
