//  ____________________________________
// | AnimSet.h - class definition       |
// | Jack Flower - March 2012           |
// |____________________________________|
//

#ifndef H_ANIM_SET_JACK
#define H_ANIM_SET_JACK

#include <vector>
#include "EAnimHandler.h"
#include "../../XML/Xml.h"
#include "../../RTTI/RTTI.h"

using namespace animation;
using namespace xml;

namespace rendering
{
	namespace animation
	{
		///
		///Forward declaration
		///
		class Animation;

		///
		///Forward declaration
		///
		class NameAnimPairTranslator;

		///
		///Klasa reprezentuje zestaw animacji obiektu
		///
		class AnimSet
		{
			RTTI_DECL;

		public:
	    
			///
			///Konstruktor domyślny
			///
			AnimSet();

			///
			///Konstruktor kopiujący
			///
			///@param AnimSet - parametr - obiekt klasy AnimSet
			///
			AnimSet(const AnimSet & AnimSetCopy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			AnimSet(AnimSet && other);

			///
			///Destruktor
			///
			~AnimSet();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy AnimSet
			///
			AnimSet & operator=(const AnimSet & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			AnimSet & operator=(AnimSet && other);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca nazwę zestawu animacji
			///
			const std::string getAnimSetName() const;

			///
			///Metoda ustawia nazwę zestawu animacji
			///
			///@param animset_name - stała referencja na std::string
			///
			void setAnimSetName(const std::string & animset_name);

			///
			///Metoda parsuje uchwyt animacji na podstawie nazwy lub int
			///
			///@param handle_input - nazwa - referencja na obiekt klasy std::string
			///
			static int parseAnimHandle(std::string & handle_input);

			///
			///Metoda ustawia animację
			///
			///@param anim_handle - uchwyt animacji
			///
			///@param *p_anim - wskaźnik na animację
			///
			void setAnimation(int anim_handle, Animation *p_anim);

			///
			///Metoda ustawia animację
			///
			///@param anim_handle - uchwyt animacji
			///
			///@param anim_name - nazwa animacji referencja na obiekt std::string
			///
			void setAnimation(int anim_handle, std::string & anim_name);
	    
			///
			///Metoda zwraca nazwę animacji na podstawie uchwytu
			///
			///@param anim_handle - uchwyt animacji
			///
			std::string *getAnimName(int anim_handle);

			///
			///Metoda zwraca wskaźnik na animację na podstawie parametru - uchwytu
			///
			///@param anim_handle - uchwyt animacji
			///
			Animation *getAnim(int anim_handle);
	    
			//metody pomocnicze
			

			//p h y s i c a l  body animations

			inline Animation *getDefaultAnimBody()
			{ return getAnim(EAnimHandler::anim_handle_body_Default); }

			inline Animation *getMoveAnimBody()
			{ return getAnim(EAnimHandler::anim_handle_body_Move); }
			
			inline Animation *getDeathAnimBody()
			{ return getAnim(EAnimHandler::anim_handle_body_Death); }

			//p h y s i c a l  head animations

			inline Animation *getDefaultAnimHead()
			{ return getAnim(EAnimHandler::anim_handle_head_Default);	}

			inline Animation *getShotAnimHead()
			{ return getAnim(EAnimHandler::anim_handle_head_Shot); }
			
			inline Animation *getAmmoLoadingAnimHead()
			{ return getAnim(EAnimHandler::anim_handle_head_Ammo_Loading); }
			
			inline Animation *getDeathAnimHead()
			{ return getAnim(EAnimHandler::anim_handle_head_Death); }
			
			//a c t o r  body animations

			inline Animation *getUnitBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ActorDefault); }
			
			inline Animation *getUnitBodyMovetAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ActorMove); }
			
			inline Animation *getUnitBodyAttackAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ActorAttack);	}
			
			inline Animation *getUnitBodyDefenseAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ActorDefense); }
			
			inline Animation *getUnitBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ActorDamage); }
			
			inline Animation *getUnitBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ActorDeath); }
			
			//a c t o r  head animations

			inline Animation *getUnitHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ActorDefault); }

			inline Animation *getUnitHeadMovetAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ActorMove); }

			inline Animation *getUnitHeadAttackAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ActorAttack); }

			inline Animation *getUnitHeadDefenseAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ActorDefense); }

			inline Animation *getUnitHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ActorDamage); }

			inline Animation *getUnitHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ActorDeath); }

			//r o b o t  body animations

			inline Animation *getRobotBodyDefaultAnim() 
			{ return getAnim(EAnimHandler::anim_handle_body_RobotDefault); }

			//r o b o t  head animations

			inline Animation *getRobotHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotDefault); }

			inline Animation *getRobotHeadAttackOpenAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotAttackOpen); }

			inline Animation *getRobotHeadAttackAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotAttack); }

			inline Animation *getRobotHeadAttackCloseAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotAttackClose); }

			inline Animation *getRobotHeadDefenseOpenAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotDefenseOpen); }

			inline Animation *getRobotHeadDefenseAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotDefense); }

			inline Animation *getRobotHeadDefenseCloseAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotDefenseClose); }

			inline Animation *getRobotHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotDamage); }

			inline Animation *getRobotHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_RobotDeath); }

			//e n e r g y  body animations

			inline Animation *getEnergyBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyBodyDefault); }

			inline Animation *getEnergyBodyReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyBodyReserve); }

			inline Animation *getEnergyBodyEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyBodyEmpty); }

			inline Animation *getEnergyBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyBodyDamage); }

			inline Animation *getEnergyBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyBodyDeath); }
			
			//e n e r g y  head animations

			inline Animation *getEnergyHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyHeadDefault); }

			inline Animation *getEnergyHeadReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyHeadReserve); }

			inline Animation *getEnergyHeadEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyHeadEmpty); }

			inline Animation *getEnergyHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyHeadDamage); }

			inline Animation *getEnergyHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyHeadDeath); }

			//e n g i n e  body animations

			inline Animation *getEngineBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineBodyDefault); }
			
			inline Animation *getEngineBodyStartAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineBodyStart); }
			
			inline Animation *getEngineBodyStopAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineBodyStop); }
			
			inline Animation *getEngineBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineBodyDamage); }
			
			inline Animation *getEngineBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineBodyDeath); }
			
			//e n g i n e  head animations

			inline Animation *getEngineHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineHeadDefault); }
			
			inline Animation *getEngineHeadStartAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineHeadStart); }
			
			inline Animation *getEngineHeadStopAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineHeadStop); }
			
			inline Animation *getEngineHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineHeadDamage); }
			
			inline Animation *getEngineHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EngineHeadDeath); }

			//f u e l t a n k  body animations

			inline Animation *getFuelBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankBodyDefault); }

			inline Animation *getFuelBodyReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankBodyReserve); }
			
			inline Animation *getFuelBodyEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankBodyEmpty); }
			
			inline Animation *getFuelBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankBodyDamage); }
			
			//f u e l t a n k  head animations
			
			inline Animation *getFuelHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankHeadDefault); }
			
			inline Animation *getFuelHeadReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankHeadReserve);	}
			
			inline Animation *getFuelHeadEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankHeadEmpty); }
			
			inline Animation *getFuelHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_FuelTankHeadDamage); }

			//e n e r g y t a n k  body animations
			
			inline Animation *getEnergyTankBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankBodyDefault); }
			
			inline Animation *getEnergyTankBodyReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankBodyReserve); }
			
			inline Animation *getEnergyTankBodyEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankBodyEmpty); }
			
			inline Animation *getEnergyTankBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankBodyDamage); }
			
			//e n e r g y t a n k  head animations
			
			inline Animation *getEnergyTankHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankHeadDefault); }
			
			inline Animation *getEnergyTankHeadReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankHeadReserve); }
			
			inline Animation *getEnergyTankHeadEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankHeadEmpty); }
			
			inline Animation *getEnergyTankHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_EnergyTankHeadDamage); }

			//l i g h t i n g  e q u i p m e n t  body animations
			
			inline Animation *getLightingEquipmentBodyLightDafaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentBodyLightDefault); }
			
			inline Animation *getLightingEquipmentBodyLightOnAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentBodyLightOn); }
			
			inline Animation *getLightingEquipmentBodyLightOffAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentBodyLightOff); }
			
			inline Animation *getLightingEquipmentBodyLightDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentBodyLightDamage); }
			
			inline Animation *getLightingEquipmentBodyLightDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentBodyLightDeath); }
			
			//l i g h t i n g  e q u i p m e n t  head animations
			
			inline Animation *getLightingEquipmentHeadLightDafaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentHeadLightDefault); }
			
			inline Animation *getLightingEquipmentHeadLightOnAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentHeadLightOn); }
			
			inline Animation *getLightingEquipmentHeadLightOffAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentHeadLightOff); }
			
			inline Animation *getLightingEquipmentHeadLightDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentHeadLightDamage); }
			
			inline Animation *getLightingEquipmentHeadLightDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_LightingEquipmentHeadLightDeath); }
			
			//g u n  body animations
			
			inline Animation *getGunBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunDefalt); }

			inline Animation *getGunBodyShootAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunShoot); }
			
			inline Animation *getGunBodyAmmoLoadingAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunAmmoLoading); }
			
			inline Animation *getGunBodyAmmoEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunAmmoEmpty); }
			
			inline Animation *getGunBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunDamage); }
			
			inline Animation *getGunBodyServiceAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunService); }
			
			inline Animation *getGunBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_BodyGunDeath); }
			
			//g u n  head animations
			
			inline Animation *getGunHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunDefalt); }
			
			inline Animation *getGunHeadShootAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunShoot); }
			
			inline Animation *getGunHeadAmmoLoadingAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunAmmoLoading); }
			
			inline Animation *getGunHeadAmmoEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunAmmoEmpty); }
			
			inline Animation *getGunHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunDamage); }
			
			inline Animation *getGunHeadServiceAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunService); }
			
			inline Animation *getGunHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_weapon_handle_HeadGunDeath); }

			//a m m o  body animations

			inline Animation *getAmmoDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_AmmoDefault); }

			inline Animation *getAmmoReserveAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_AmmoReserve); }

			inline Animation *getAmmoEmptyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_AmmoEmpty); }

			inline Animation *getAmmoDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_AmmoDamage); }

			//w i n d t u r b i n e  body animations
			
			inline Animation *getWindTurbineBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineBodyDefault); }
			
			inline Animation *getWindTurbineBodyDamagetAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineBodyDamage); }
			
			inline Animation *getWindTurbineBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineBodyDeath); }
			
			//w i n d t u r b i n e  head animations
			
			inline Animation *getWindTurbineHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineHeadDefault); }
			
			inline Animation *getWindTurbineHeadCargoOpenAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineHeadCargoOpen); }
			
			inline Animation *getWindTurbineHeadCargoCloseAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineHeadCargoClose); }
			
			inline Animation *getWindTurbineHeadUpdateEnergyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineHeadUpdateEnergy); }
			
			inline Animation *getWindTurbineHeadDamagetAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineHeadDamage); }
			
			inline Animation *getWindTurbineHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindTurbineHeadDeath); }


			//s o l a r c e l l  body animations
			
			inline Animation *getSolarCellBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellBodyDefault); }
			
			inline Animation *getSolarCellBodyUpdateEnergyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellBodyUpdateEnergy); }
			
			inline Animation *getSolarCellBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellBodyDamage); }
			
			inline Animation *getSolarCellBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellBodyDeath); }
			
			////s o l a r c e l l  head animations
			
			inline Animation *getSolarCellHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellHeadDefault); }
			
			inline Animation *getSolarCellHeadUpdateEnergyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellHeadUpdateEnergy); }
			
			inline Animation *getSolarCellHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellHeadDamage); }
			
			inline Animation *getSolarCellHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_SolarCellHeadDeath); }
			
			//w i n d p o w e r s t a t i o n  body animations
			
			inline Animation *getWindPowerStationBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationBodyDefault); }
			
			inline Animation *getWindPowerStationBodyUpdateEnergyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationBodyUpdateEnergy); }
			
			inline Animation *getWindPowerStationBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationBodyDamage); }
			
			inline Animation *getWindPowerStationBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationBodyDeath); }
			
			//w i n d p o w e r s t a t i o n  head animations
			
			inline Animation *getWindPowerStationHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationHeadDefault); }
			
			inline Animation *getWindPowerStationHeadUpdateEnergyAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationHeadUpdateEnergy); }
			
			inline Animation *getWindPowerStationHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationHeadDamage); }
			
			inline Animation *getWindPowerStationHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_equipment_handle_WindPowerStationHeadDeath); }

			//p o w e r r e l a y s t a t i on  body animatios

			inline Animation *getPowerRelayStationBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_PowerRelayStationDefault); }

			inline Animation *getPowerRelayStationBodyUpdateConnectionAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_PowerRelayStationUpdateConnection); }
			
			inline Animation *getPowerRelayStationBodyDisconnectAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_PowerRelayStationDisconnect); }
			
			inline Animation *getPowerRelayStationBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_PowerRelayStationDamage); }
			
			inline Animation *getPowerRelayStationBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_PowerRelayStationDeath); }
			
			//p o w e r r e l a y s t a t i on  head animatios
			
			inline Animation *getPowerRelayStationHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_PowerRelayStationDefault); }
			
			inline Animation *getPowerRelayStationHeadUpdateConnectionAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_PowerRelayStationUpdateConnection); }
			
			inline Animation *getPowerRelayStationHeadDisconnectAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_PowerRelayStationDisconnect); }
			
			inline Animation *getPowerRelayStationHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_PowerRelayStationDamage); }
			
			inline Animation *getPowerRelayStationHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_PowerRelayStationDeath); }

			//c o m m u n i c a t i o n  body animations
			
			inline Animation *getCommunicationBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationDefault); }
			
			inline Animation *getCommunicationBodySearchAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationSearch); }
			
			inline Animation *getCommunicationBodyLoginAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationLogin); }
			
			inline Animation *getCommunicationBodyAuthorizationAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationAuthorization); }
			
			inline Animation *getCommunicationBodyUpdateAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationUpdate); }
			
			inline Animation *getCommunicationBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationDamage); }
			
			inline Animation *getCommunicationBodyDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_CommunicationDeath); }
			
			//c o m m u n i c a t i o n  head animations
			
			inline Animation *getCommunicationHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationDefault); }
			
			inline Animation *getCommunicationHeadSearchAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationSearch); }
			
			inline Animation *getCommunicationHeadLoginAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationLogin); }
			
			inline Animation *getCommunicationHeadAuthorizationAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationAuthorization); }
			
			inline Animation *getCommunicationHeadUpdateAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationUpdate); }
			
			inline Animation *getCommunicationHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationDamage); }
			
			inline Animation *getCommunicationHeadDeathAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_CommunicationDeath); }

			//s l o t s r a t e  body animations
			
			inline Animation *getSlotsRateBody_0_Anim()
			{ return getAnim(EAnimHandler::anim_handle_body_SlotsRate_0); }
			
			inline Animation *getSlotsRateBody_1_Anim()
			{ return getAnim(EAnimHandler::anim_handle_body_SlotsRate_1); }
			
			inline Animation *getSlotsRateBody_2_Anim()
			{ return getAnim(EAnimHandler::anim_handle_body_SlotsRate_2); }
			
			inline Animation *getSlotsRateBody_3_Anim()
			{ return getAnim(EAnimHandler::anim_handle_body_SlotsRate_3); }
			
			inline Animation *getSlotsRateBody_4_Anim()
			{ return getAnim(EAnimHandler::anim_handle_body_SlotsRate_4); }
			
			//s l o t s r a t e  head animations
			
			inline Animation *getSlotsRateHead_0_Anim()
			{ return getAnim(EAnimHandler::anim_handle_head_SlotsRate_0); }
			
			inline Animation *getSlotsRateHead_1_Anim()
			{ return getAnim(EAnimHandler::anim_handle_head_SlotsRate_1); }
			
			inline Animation *getSlotsRateHead_2_Anim()
			{ return getAnim(EAnimHandler::anim_handle_head_SlotsRate_2); }
			
			inline Animation *getSlotsRateHead_3_Anim()
			{ return getAnim(EAnimHandler::anim_handle_head_SlotsRate_3); }
			
			inline Animation *getSlotsRateHead_4_Anim()
			{ return getAnim(EAnimHandler::anim_handle_head_SlotsRate_4); }

			//a i r c o n d i t i o n i n g  body animations
			
			inline Animation *getAirconditioningBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_airconditioning_default); }
			
			inline Animation *getAirconditioningBodyHeatingtAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_airconditioning_heating); }
			
			inline Animation *getAirconditioningBodyCoolingAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_airconditioning_cooling); }
			
			inline Animation *getAirconditioningBodyIneffectiveAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_airconditioning_ineffective);	}
			
			inline Animation *getAirconditioningBodyDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_airconditioning_damage); }
			
			//a i r c o n d i t i o n i n g  head animations
			
			inline Animation *getAirconditioningHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_airconditioning_default); }
			
			inline Animation *getAirconditioningHeadHeatingtAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_airconditioning_heating); }
			
			inline Animation *getAirconditioningHeadCoolingAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_airconditioning_cooling); }
			
			inline Animation *getAirconditioningHeadIneffectiveAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_airconditioning_ineffective);	}
			
			inline Animation *getAirconditioningHeadDamageAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_airconditioning_damage); }

			//t h e r m a l i n s u l a t i o n  body animations
			
			inline Animation *getThermalInsulationBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_thermalinsulation_default); }
			
			inline Animation *getThermalInsulationBodyDamagetAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_thermalinsulation_damage); }
			
			//t h e r m a l i n s u l a t i o n  head animations
			
			inline Animation *getThermalInsulationHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_thermalinsulation_default); }
			
			inline Animation *getThermalInsulationHeadDamagetAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_thermalinsulation_damage); }

			//v e n t i l a t o r  body animations
			
			inline Animation *getVentilatorBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ventilator_default); }
			
			inline Animation *getVentilatorBodyDamagetAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_ventilator_damage); }
			
			//v e n t i l a t o r  head animations
			
			inline Animation *getVentilatorHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ventilator_default); }
			
			inline Animation *getVentilatorHeadDamagetAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_ventilator_damage); }

			//b a t t e r y  body animations
			
			inline Animation *getBatteryBodyDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_battery_default); }
			
			inline Animation *getBatteryBodyOperateAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_battery_operate); }
			
			inline Animation *getBatteryBodyExhaustedAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_battery_exhausted); }
			
			inline Animation *getBatteryBodyDamagetAnim()
			{ return getAnim(EAnimHandler::anim_handle_body_battery_damage); }
			
			//b a t t e r y  head animations
			
			inline Animation *getBatteryHeadDefaultAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_battery_default); }
			
			inline Animation *getBatteryHeadOperateAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_battery_operate); }
			
			inline Animation *getBatteryHeadExhaustedAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_battery_exhausted); }
			
			inline Animation *getBatteryHeadDamagetAnim()
			{ return getAnim(EAnimHandler::anim_handle_head_battery_damage); }

			///
			///Metoda sprawdza nazwy animacji i wstawia animacje do zestawu animacji
			///
			///@param xml - referencja na obiekt klasy Xml
			///
			///@param *root - wskaźnik na węzeł dokumentu xml
			///
			void parse(Xml & xml, rapidxml::xml_node<> *root = 0);

			///
			///Metoda zwraca stała referencję na wektor przechowujący zestawy animacji
			///
			inline const std::vector<NameAnimPairTranslator> & getAnims() const { return m_anims; }

		private:

			std::string m_animset_name; //nazwa zestawu
			std::vector<NameAnimPairTranslator> m_anims; //kontener przechowujący animacje

			static int m_anim_handle_number; //uchwyt animacji
			static std::string m_anim_handle_names[]; //tablica stringów przechowująca nazwy animacji
			
		};

	}//namespace animation
}//namespace rendering
#endif//H_ANIM_SET_JACK
