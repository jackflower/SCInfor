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
	///Wyliczenie stan�w dla obiektu CAirconditioning
	///
	enum EThermalInsulationState
	{
		THERMALINSULATION_DEFAULT	= 0,	//termoizolator funkcjonuje
		THERMALINSULATION_DAMAGE	= 1,	//z racji faktu, �e jest to urz�dzenie
											//machaniczne, stan damage, nale�y traktowa�
											//jako stan wy��czenia
	};
}//namespace equipment
#endif//H_E_THERMALINSULATION_STATE_JACK
