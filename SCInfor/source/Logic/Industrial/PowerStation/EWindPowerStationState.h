// ________________________________________________________________
//| EWindPowerStationState.h - wyliczenie stan�w CWindPowerStation |
//| Jack Flower - August 2014                                      |
//|________________________________________________________________|
//

#ifndef H_WIND_POWER_STATION_STATE_JACK
#define H_WIND_POWER_STATION_STATE_JACK

namespace logic
{
	namespace powerstation
	{
		///
		///Wyliczenie stan�w dla obiektu CWindPowerStation
		///
		enum EWindPowerStationState
		{
			WINDPOWER_STATION_DEFAULT		= 0,
			WINDPOWER_STATION_UPDATE_ENERGY = 1,
			WINDPOWER_STATION_DAMAGE		= 2,
			WINDPOWER_STATION_DEATH			= 3
		};
	}//namespace powerstation
}//namespace logic
#endif//H_WIND_POWER_STATION_STATE_JACK
