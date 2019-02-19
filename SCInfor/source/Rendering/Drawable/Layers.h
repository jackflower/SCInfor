//  _______________________________
// | Layers.h - warstwy renderingu |
// | Jack Flower - March 2012      |
// |_______________________________|
//

#ifndef H_LAYER_JACK
#define H_LAYER_JACK

namespace rendering
{
	namespace drawable
	{
		///
		///Lista wartości dla zdefiniowanych warstw, na których będzie renderowana grafika
		///algorymt "m a l a r z a" - top down
		///
		const int Z_MAX											= 800;	//fundament (warstwa oddalona najdalej od oka kamery)
		const int Z_TILE										= 700;	//klafle
		const int Z_GROUND_WORK									= 600;	//podłoże

		//f l o r a
		const int Z_FLORA_SHADOW_BODY							= 530;	//flora body shadow
		const int Z_FLORA_BODY									= 520;	//flora body
		const int Z_FLORA_SHADOW_HEAD							= 510;	//flora head shadow
		const int Z_FLORA_HEAD									= 500;	//flora head

		//w r e c k
		//1. magazynki z amunicją
		//2. to edit
		//3. to edit
		const int Z_WRECK_SHADOW_BODY							= 488;	//wreck body shadow
		const int Z_WRECK_BODY									= 486;	//wreck body
		const int Z_WRECK_SHADOW_HEAD							= 484;	//wreck head shadow
		const int Z_WRECK_HEAD									= 482;	//wreck head
		
		//r e l a y s t a t i o n
		const int Z_PHYSICAL_SHADOW_RELAY_STATION_BODY			= 480;	//relaystation body shadow
		const int Z_PHYSICAL_RELAY_STATION_BODY					= 470;	//relaystation body
		const int Z_PHYSICAL_SHADOW_RELAY_STATION_HEAD			= 460;	//relaystation head shadow
		const int Z_PHYSICAL_RELAY_STATION_HEAD					= 450;	//relaystation head

		//p o w e r s t a t i o n
		const int Z_PHYSICAL_SHADOW_POWER_STATION_BODY			= 440;	//powermodule body shadow
		const int Z_PHYSICAL_POWER_STATION_BODY					= 430;	//powermodule body
		const int Z_PHYSICAL_SHADOW_POWER_STATION_HEAD			= 420;	//powermodule head shadow
		const int Z_PHYSICAL_POWERM_STATION_HEAD				= 410;	//powermodule head

		//w i n d t u r b i n e
		const int Z_PHYSICAL_SHADOW_WIND_TURBINE_BODY			= 400;	//windturbine body shadow
		const int Z_PHYSICAL_WIND_TURBINE_BODY					= 390;	//windturbine body
		const int Z_PHYSICAL_SHADOW_WIND_TURBINE_HEAD			= 380;	//windturbine head shadow
		const int Z_PHYSICAL_WIND_TURBINE_HEAD					= 370;	//windturbine head

		//l i g h t i n g  e q u i p m e n t
		const int Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_BODY		= 360;	//lightingequipment body shadow
		const int Z_PHYSICAL_LIGHTING_EQUIPMENT_BODY			= 350;	//lightingequipment body
		const int Z_PHYSICAL_SHADOW_LIGHTING_EQUIPMENT_HEAD		= 340;	//lightingequipment head shadow
		const int Z_PHYSICAL_LIGHTING_EQUIPMENT_HEAD			= 330;	//lightingequipment head

		//s l o t s r a t e
		const int Z_SLOTS_RATE_SHADOW_BODY						= 320;	//slotsrate body shadow
		const int Z_SLOTS_RATE_BODY								= 310;	//slotsrate body
		const int Z_SLOTS_RATE_SHADOW_HEAD						= 300;	//slotsrate head shadow
		const int Z_SLOTS_RATE_HEAD								= 290;	//slotsrate head

		//p h y s i c a l  body
		const int Z_PHYSICAL_SHADOWS_BODY						= 280;	//physical unit (owner) body shadow
		const int Z_PHYSICAL_BODY								= 270;	//physical unit (owner) body

		//e n g i ne
		const int Z_PHYSICAL_SHADOW_ENGINE_BODY					= 260;	//engine body shadow
		const int Z_PHYSICAL_ENGINE_BODY						= 250;	//engine body
		const int Z_PHYSICAL_SHADOW_ENGINE_HEAD					= 240;	//engine head shadow
		const int Z_PHYSICAL_ENGINE_HEAD						= 230;	//engine head

		//e n e r g y
		const int Z_PHYSICAL_SHADOW_ENERGY_BODY					= 220;	//energy body shadow
		const int Z_PHYSICAL_ENERGY_BODY						= 210;	//energy body
		const int Z_PHYSICAL_SHADOW_ENERGY_HEAD					= 200;	//energy head shadow
		const int Z_PHYSICAL_ENERGY_HEAD						= 190;	//energy head

		//f u e l t a n k
		const int Z_PHYSICAL_SHADOW_FUEL_TANK_BODY				= 180;	//fuel tank body shadow
		const int Z_PHYSICAL_FUEL_TANK_BODY						= 170;	//fuel tank body
		const int Z_PHYSICAL_SHADOW_FUEL_TANK_HEAD				= 160;	//fuel tank head shadow
		const int Z_PHYSICAL_FUEL_TANK_HEAD						= 150;	//fuel tank head

		//e n e r g y t a n k
		const int Z_PHYSICAL_SHADOW_ENERGY_TANK_BODY			= 140;	//energy tank body shadow
		const int Z_PHYSICAL_ENERGY_TANK_BODY					= 130;	//energy tank body
		const int Z_PHYSICAL_SHADOW_ENERGY_TANK_HEAD			= 120;	//energy tank head shadow
		const int Z_PHYSICAL_ENERGY_TANK_HEAD					= 110;	//energy tank head

		//a m m o
		const int Z_PHYSICAL_SHADOW_AMMO_BODY					= 108;	//ammo body shadow
		const int Z_PHYSICAL_AMMO_BODY							= 106;	//ammo body
		const int Z_PHYSICAL_SHADOW_AMMO_HEAD					= 104;	//ammo head shadow
		const int Z_PHYSICAL_AMMO_HEAD							= 102;	//ammo head

		//p h y s i c a l  head
		const int Z_PHYSICAL_SHADOWS_HEAD						= 100;	//physical unit (owner) head shadow
		const int Z_PHYSICAL_HEAD								= 90;	//physical unit (owner) head

		//p r o g r e s s  b a r s
		const int Z_PHYSICAL_INFO_STATUS_BAR					= 80;	//statusbar - progress bar (rectangle)

		//p h y s i c a l  i n f o  l a b e l
		const int Z_PHYSICAL_INFO_BODY_SHADOW					= 70;	//physical info body shadow
		const int Z_PHYSICAL_INFO_BODY							= 60;	//physical info body
		const int Z_PHYSICAL_INFO_HEAD_SHADOW					= 50;	//physical info head shadow
		const int Z_PHYSICAL_INFO_HEAD							= 40;	//physical info head

		//i n f o r m a t i o n
		const int Z_INFORMATION_BACK							= 30;	//warstwa informacji - podcień czcionki tekstu
		const int Z_INFORMATION_FRONT							= 20;	//warstwa informacji
		const int Z_CURSOR										= 10;	//kursor
		const int Z_ZERO										= 0;	//warstwa zerowa (pierwsza od oka kamery)
	}//namespace drawable
}//namespace rendering
#endif //H_LAYER_JACK
