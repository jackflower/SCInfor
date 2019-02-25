//  _____________________________________________________________________
// | ELightingEquipmentState.h - enumeration of states lightingequipment |
// | Jack Flower - February 2014                                         |
// |_____________________________________________________________________|
//

#ifndef H_E_LIGHTING_EQUIPMENT_STATE_JACK
#define H_E_LIGHTING_EQUIPMENT_STATE_JACK

namespace equipment
{
	///
	///Wyliczenie stanów dla obiektu LightingEquipment
	///
	enum ELightingEquipmentState
	{
		LIGHTING_EQUIPMENT_DEFAULT		= 0,
		LIGHTING_EQUIPMENT_LIGHT_ON		= 1,
		LIGHTING_EQUIPMENT_LIGHT_OFF	= 2,
		LIGHTING_EQUIPMENT_DAMAGE		= 3,
		LIGHTING_EQUIPMENT_DEATH		= 4
	};

}//namespace equipment
#endif//H_E_LIGHTING_EQUIPMENT_STATE_JACK
