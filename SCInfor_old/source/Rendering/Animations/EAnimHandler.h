//  ___________________________________________________
// | EAnimHandler.h - enumeration of states animations |
// | Jack Flower - March 2012                          |
// |___________________________________________________|
//

#ifndef H_E_ANIM_HANDLER_JACK
#define H_E_ANIM_HANDLER_JACK

namespace animation
{
	///
	///Wyliczenie uchwytów animacji
	///
	enum EAnimHandler
	{
		//p h y s i c a l
		//body animations handlers
		anim_handle_body_Default									= 0,
		anim_handle_body_Move										= 1,
		anim_handle_body_Death										= 2,
		//head animations handlers
		anim_handle_head_Default									= 3,
		anim_handle_head_Shot										= 4,
		anim_handle_head_Ammo_Loading								= 5,
		anim_handle_head_Death										= 6,

		//a c t o r
		//body animations handlers
		anim_handle_body_ActorDefault								= 7,
		anim_handle_body_ActorMove									= 8,
		anim_handle_body_ActorAttack								= 9,
		anim_handle_body_ActorDefense								= 10,
		anim_handle_body_ActorDamage								= 11,
		anim_handle_body_ActorDeath									= 12,
		//head animations handlers
		anim_handle_head_ActorDefault								= 13,
		anim_handle_head_ActorMove									= 14,
		anim_handle_head_ActorAttack								= 15,
		anim_handle_head_ActorDefense								= 16,
		anim_handle_head_ActorDamage								= 17,
		anim_handle_head_ActorDeath									= 18,

		//r o b o t
		//body animations handlers
		anim_handle_body_RobotDefault								= 19,
		//head animations handlers
		anim_handle_head_RobotDefault								= 20,
		anim_handle_head_RobotAttackOpen							= 21,
		anim_handle_head_RobotAttack								= 22,
		anim_handle_head_RobotAttackClose							= 23,
		anim_handle_head_RobotDefenseOpen							= 24,
		anim_handle_head_RobotDefense								= 25,
		anim_handle_head_RobotDefenseClose							= 26,
		anim_handle_head_RobotDamage								= 27,
		anim_handle_head_RobotDeath									= 28,

		//e n e r g y
		//body animations energy handlers
		anim_equipment_handle_EnergyBodyDefault						= 29,
		anim_equipment_handle_EnergyBodyReserve						= 30,
		anim_equipment_handle_EnergyBodyEmpty						= 31,
		anim_equipment_handle_EnergyBodyDamage						= 32,
		anim_equipment_handle_EnergyBodyDeath						= 33,
		//head animations energy handlers
		anim_equipment_handle_EnergyHeadDefault						= 34,
		anim_equipment_handle_EnergyHeadReserve						= 35,
		anim_equipment_handle_EnergyHeadEmpty						= 36,
		anim_equipment_handle_EnergyHeadDamage						= 37,
		anim_equipment_handle_EnergyHeadDeath						= 38,

		//e n g i n e
		//body animations engine handlers
		anim_equipment_handle_EngineBodyDefault						= 39,
		anim_equipment_handle_EngineBodyStart						= 40,
		anim_equipment_handle_EngineBodyStop						= 41,
		anim_equipment_handle_EngineBodyDamage						= 42,
		anim_equipment_handle_EngineBodyDeath						= 43,
		//head animations engine handlers
		anim_equipment_handle_EngineHeadDefault						= 44,
		anim_equipment_handle_EngineHeadStart						= 45,
		anim_equipment_handle_EngineHeadStop						= 46,
		anim_equipment_handle_EngineHeadDamage						= 47,
		anim_equipment_handle_EngineHeadDeath						= 48,


		//f u e l t a n k
		//body animations fuel handlers
		anim_equipment_handle_FuelTankBodyDefault					= 49,
		anim_equipment_handle_FuelTankBodyReserve					= 50,
		anim_equipment_handle_FuelTankBodyEmpty						= 51,
		anim_equipment_handle_FuelTankBodyDamage					= 52,
		//head animations fuel handlers
		anim_equipment_handle_FuelTankHeadDefault					= 53,
		anim_equipment_handle_FuelTankHeadReserve					= 54,
		anim_equipment_handle_FuelTankHeadEmpty						= 55,
		anim_equipment_handle_FuelTankHeadDamage					= 56,

		//e n e r g y t a n k
		//body animations energytank handlers
		anim_equipment_handle_EnergyTankBodyDefault					= 57,
		anim_equipment_handle_EnergyTankBodyReserve					= 58,
		anim_equipment_handle_EnergyTankBodyEmpty					= 59,
		anim_equipment_handle_EnergyTankBodyDamage					= 60,
		//head animations energytank handlers
		anim_equipment_handle_EnergyTankHeadDefault					= 61,
		anim_equipment_handle_EnergyTankHeadReserve					= 62,
		anim_equipment_handle_EnergyTankHeadEmpty					= 63,
		anim_equipment_handle_EnergyTankHeadDamage					= 64,

		//l i g h t i n g  e q u i p m e n t
		//body animations lightingequipment handlers
		anim_equipment_handle_LightingEquipmentBodyLightDefault		= 65,
		anim_equipment_handle_LightingEquipmentBodyLightOn			= 66,
		anim_equipment_handle_LightingEquipmentBodyLightOff			= 67,
		anim_equipment_handle_LightingEquipmentBodyLightDamage		= 68,
		anim_equipment_handle_LightingEquipmentBodyLightDeath		= 69,
		//head animations lightingequipment handlers
		anim_equipment_handle_LightingEquipmentHeadLightDefault		= 70,
		anim_equipment_handle_LightingEquipmentHeadLightOn			= 71,
		anim_equipment_handle_LightingEquipmentHeadLightOff			= 72,
		anim_equipment_handle_LightingEquipmentHeadLightDamage		= 73,
		anim_equipment_handle_LightingEquipmentHeadLightDeath		= 74,

		//g u n
		//body animations gun handlers
		anim_equipment_weapon_handle_BodyGunDefalt					= 75,
		anim_equipment_weapon_handle_BodyGunShoot					= 76,
		anim_equipment_weapon_handle_BodyGunAmmoLoading				= 77,
		anim_equipment_weapon_handle_BodyGunAmmoEmpty				= 78,
		anim_equipment_weapon_handle_BodyGunDamage					= 79,
		anim_equipment_weapon_handle_BodyGunService					= 80,
		anim_equipment_weapon_handle_BodyGunDeath					= 81,
		//head animations gun handlers
		anim_equipment_weapon_handle_HeadGunDefalt					= 82,
		anim_equipment_weapon_handle_HeadGunShoot					= 83,
		anim_equipment_weapon_handle_HeadGunAmmoLoading				= 84,
		anim_equipment_weapon_handle_HeadGunAmmoEmpty				= 85,
		anim_equipment_weapon_handle_HeadGunDamage					= 86,
		anim_equipment_weapon_handle_HeadGunService					= 87,
		anim_equipment_weapon_handle_HeadGunDeath					= 88,

		//a m m o
		//body animations ammo handlers
		anim_equipment_handle_AmmoDefault							= 89,
		anim_equipment_handle_AmmoReserve							= 90,
		anim_equipment_handle_AmmoEmpty								= 91,
		anim_equipment_handle_AmmoDamage							= 92,
		//head animations ammo handlers
		//
		//
		//
		//

		//w i n d t u r b i n e
		//body animations windturbine handlers
		anim_equipment_handle_WindTurbineBodyDefault				= 93,
		anim_equipment_handle_WindTurbineBodyDamage					= 94,
		anim_equipment_handle_WindTurbineBodyDeath					= 95,
		//head animations windturbine handlers
		anim_equipment_handle_WindTurbineHeadDefault				= 96,
		anim_equipment_handle_WindTurbineHeadCargoOpen				= 97,
		anim_equipment_handle_WindTurbineHeadCargoClose				= 98,
		anim_equipment_handle_WindTurbineHeadUpdateEnergy			= 99,
		anim_equipment_handle_WindTurbineHeadDamage					= 100,
		anim_equipment_handle_WindTurbineHeadDeath					= 101,

		//s o l a r c e l l
		//body animations solarcell handlers
		anim_equipment_handle_SolarCellBodyDefault					= 102,
		anim_equipment_handle_SolarCellBodyUpdateEnergy				= 103,
		anim_equipment_handle_SolarCellBodyDamage					= 104,
		anim_equipment_handle_SolarCellBodyDeath					= 105,
		//head animations solarcell handlers
		anim_equipment_handle_SolarCellHeadDefault					= 106,
		anim_equipment_handle_SolarCellHeadUpdateEnergy				= 107,
		anim_equipment_handle_SolarCellHeadDamage					= 108,
		anim_equipment_handle_SolarCellHeadDeath					= 109,

		//w i n d p o w e r s t a t i o n
		//body animations windpowerstation handlers
		anim_equipment_handle_WindPowerStationBodyDefault			= 110,
		anim_equipment_handle_WindPowerStationBodyUpdateEnergy		= 111,
		anim_equipment_handle_WindPowerStationBodyDamage			= 112,
		anim_equipment_handle_WindPowerStationBodyDeath				= 113,
		//head animations windpowerstation handlers
		anim_equipment_handle_WindPowerStationHeadDefault			= 114,
		anim_equipment_handle_WindPowerStationHeadUpdateEnergy		= 115,
		anim_equipment_handle_WindPowerStationHeadDamage			= 116,
		anim_equipment_handle_WindPowerStationHeadDeath				= 117,

		//p o w e r r e l a y s t a t i o n
		//body animations powerrelaystation handlers
		anim_handle_body_PowerRelayStationDefault					= 118,
		anim_handle_body_PowerRelayStationUpdateConnection			= 119,
		anim_handle_body_PowerRelayStationDisconnect				= 120,
		anim_handle_body_PowerRelayStationDamage					= 121,
		anim_handle_body_PowerRelayStationDeath						= 122,
		//head animations powerrelaystation handlers
		anim_handle_head_PowerRelayStationDefault					= 123,
		anim_handle_head_PowerRelayStationUpdateConnection			= 124,
		anim_handle_head_PowerRelayStationDisconnect				= 125,
		anim_handle_head_PowerRelayStationDamage					= 126,
		anim_handle_head_PowerRelayStationDeath						= 127,

		//c o m m u n i c a t i o n
		//body animations communication handlers
		anim_handle_body_CommunicationDefault						= 128,
		anim_handle_body_CommunicationSearch						= 129,
		anim_handle_body_CommunicationLogin							= 130,
		anim_handle_body_CommunicationAuthorization					= 131,
		anim_handle_body_CommunicationUpdate						= 132,
		anim_handle_body_CommunicationDamage						= 133,
		anim_handle_body_CommunicationDeath							= 134,
		//head animations communication handlers
		anim_handle_head_CommunicationDefault						= 135,
		anim_handle_head_CommunicationSearch						= 136,
		anim_handle_head_CommunicationLogin							= 137,
		anim_handle_head_CommunicationAuthorization					= 138,
		anim_handle_head_CommunicationUpdate						= 139,
		anim_handle_head_CommunicationDamage						= 140,
		anim_handle_head_CommunicationDeath							= 141,

		//s l o t s r a t e
		//body animations slotsrate handlers
		anim_handle_body_SlotsRate_0								= 142,
		anim_handle_body_SlotsRate_1								= 143,
		anim_handle_body_SlotsRate_2								= 144,
		anim_handle_body_SlotsRate_3								= 145,
		anim_handle_body_SlotsRate_4								= 146,
		//head animations slotsrate handlers
		anim_handle_head_SlotsRate_0								= 147,
		anim_handle_head_SlotsRate_1								= 148,
		anim_handle_head_SlotsRate_2								= 149,
		anim_handle_head_SlotsRate_3								= 150,
		anim_handle_head_SlotsRate_4								= 151,

		//a i r c o n d i t i o n i n g
		//body animations airconditioning handlers
		anim_handle_body_airconditioning_default					= 152,
		anim_handle_body_airconditioning_heating					= 153,
		anim_handle_body_airconditioning_cooling					= 154,
		anim_handle_body_airconditioning_ineffective				= 155,
		anim_handle_body_airconditioning_damage						= 156,
		//head animations airconditioning handlers
		anim_handle_head_airconditioning_default					= 157,
		anim_handle_head_airconditioning_heating					= 158,
		anim_handle_head_airconditioning_cooling					= 159,
		anim_handle_head_airconditioning_ineffective				= 160,
		anim_handle_head_airconditioning_damage						= 161,

		//t h e r m a l i n s u l a t i o n
		//body animations thermalinsulation handlers
		anim_handle_body_thermalinsulation_default					= 162,
		anim_handle_body_thermalinsulation_damage					= 163,
		//head animations thermalinsulation handlers
		anim_handle_head_thermalinsulation_default					= 164,
		anim_handle_head_thermalinsulation_damage					= 165,

		//v e n t i l a t o r
		//body animations ventilator handlers
		anim_handle_body_ventilator_default							= 166,
		anim_handle_body_ventilator_damage							= 167,
		//head animations ventilator handlers
		anim_handle_head_ventilator_default							= 168,
		anim_handle_head_ventilator_damage							= 169,

		//b a t t e r y
		//body animations battery handlers
		anim_handle_body_battery_default							= 170,
		anim_handle_body_battery_operate							= 171,
		anim_handle_body_battery_exhausted							= 172,
		anim_handle_body_battery_damage								= 173,
		//head animations battery handlers
		anim_handle_head_battery_default							= 174,
		anim_handle_head_battery_operate							= 175,
		anim_handle_head_battery_exhausted							= 176,
		anim_handle_head_battery_damage								= 177
	};
}//namespace animation
#endif //H_E_ANIM_HANDLER_JACK
