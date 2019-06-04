//  _____________________________________________________________________
// | EThermalInsulationState.h - enumeration of states thermalinsulation |
// | Jack Flower - May 2016                                              |
// |_____________________________________________________________________|
//

#ifndef H_E_THERMALINSULATION_STATE_JACK
#define H_E_THERMALINSULATION_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu Airconditioning
	///
	enum class EThermalInsulationState
	{
		THERMALINSULATION_DEFAULT = 0,	//termoizolator funkcjonuje
		THERMALINSULATION_DAMAGE = 1,	//z racji faktu, że jest to urządzenie
											//machaniczne, stan damage, należy traktować
											//jako stan wyłączenia
	};
}//namespace equipment
#endif//H_E_THERMALINSULATION_STATE_JACK
