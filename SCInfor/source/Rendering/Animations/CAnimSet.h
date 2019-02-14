//  _____________________________________
// | CAnimSet.h - class definition       |
// | Jack Flower - March 2012            |
// |_____________________________________|
//

#ifndef H_ANIM_SET_JACK
#define H_ANIM_SET_JACK

#include <vector>
#include "EAnimHandler.h"
#include "../../XML/CXml.h"
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
		class CNameAnimPairTranslator;

		///
		///Klasa reprezentuje zestaw animacji obiektu
		///
		class CAnimSet
		{
			RTTI_DECL;

		public:
	    
			///
			///Konstruktor domyœlny
			///
			CAnimSet();

			///
			///Destruktor
			///
			~CAnimSet();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca nazwê zestawu animacji
			///
			const std::string GetAnimSetName() const;

			///
			///Metoda ustawia nazwê zestawu animacji
			///
			///@param &animset_name - sta³a referencja na std::string
			///
			void SetAnimSetName(const std::string &animset_name);

			///
			///Metoda parsuje uchwyt animacji na podstawie nazwy lub int
			///
			///@param &handle_input - nazwa - referencja na obiekt klasy std::string
			///
			static int ParseAnimHandle(std::string &handle_input);

			///
			///Metoda ustawia animacjê
			///
			///@param anim_handle - uchwyt animacji
			///
			///@param *p_anim - wskaŸnik na animacjê
			///
			void SetAnimation(int anim_handle, Animation *p_anim);

			///
			///Metoda ustawia animacjê
			///
			///@param anim_handle - uchwyt animacji
			///
			///@param &anim_name - nazwa animacji referencja na obiekt std::string
			///
			void SetAnimation(int anim_handle, std::string &anim_name);
	    
			///
			///Metoda zwraca nazwê animacji na podstawie uchwytu
			///
			///@param anim_handle - uchwyt animacji
			///
			std::string *GetAnimName(int anim_handle);

			///
			///Metoda zwraca wskaŸnik na animacjê na podstawie parametru - uchwytu
			///
			///@param anim_handle - uchwyt animacji
			///
			Animation *GetAnim(int anim_handle);
	    
			//metody pomocnicze
			
			//p h y s i c a l
			//body animations
			inline Animation *GetDefaultAnimBody				()	{ return GetAnim(anim_handle_body_Default);			}
			inline Animation *GetMoveAnimBody					()	{ return GetAnim(anim_handle_body_Move);			}
			inline Animation *GetDeathAnimBody					()	{ return GetAnim(anim_handle_body_Death);			}
			//head animations
			inline Animation *GetDefaultAnimHead				()	{ return GetAnim(anim_handle_head_Default);			}
			inline Animation *GetShotAnimHead					()	{ return GetAnim(anim_handle_head_Shot);			}
			inline Animation *GetAmmoLoadingAnimHead			()	{ return GetAnim(anim_handle_head_Ammo_Loading);	}
			inline Animation *GetDeathAnimHead					()	{ return GetAnim(anim_handle_head_Death);			}
			
			//a c t o r
			//body animations
			inline Animation *GetUnitBodyDefaultAnim			() { return GetAnim(anim_handle_body_ActorDefault);		}
			inline Animation *GetUnitBodyMovetAnim				() { return GetAnim(anim_handle_body_ActorMove);		}
			inline Animation *GetUnitBodyAttackAnim			() { return GetAnim(anim_handle_body_ActorAttack);		}
			inline Animation *GetUnitBodyDefenseAnim			() { return GetAnim(anim_handle_body_ActorDefense);		}
			inline Animation *GetUnitBodyDamageAnim			() { return GetAnim(anim_handle_body_ActorDamage);		}
			inline Animation *GetUnitBodyDeathAnim				() { return GetAnim(anim_handle_body_ActorDeath);		}
			//head animations
			inline Animation *GetUnitHeadDefaultAnim			() { return GetAnim(anim_handle_head_ActorDefault);		}
			inline Animation *GetUnitHeadMovetAnim				() { return GetAnim(anim_handle_head_ActorMove);		}
			inline Animation *GetUnitHeadAttackAnim			() { return GetAnim(anim_handle_head_ActorAttack);		}
			inline Animation *GetUnitHeadDefenseAnim			() { return GetAnim(anim_handle_head_ActorDefense);		}
			inline Animation *GetUnitHeadDamageAnim			() { return GetAnim(anim_handle_head_ActorDamage);		}
			inline Animation *GetUnitHeadDeathAnim				() { return GetAnim(anim_handle_head_ActorDeath);		}

			//r o b o t
			//body animations
			inline Animation *GetRobotBodyDefaultAnim			() { return GetAnim(anim_handle_body_RobotDefault);			}
			//head animations
			inline Animation *GetRobotHeadDefaultAnim			() { return GetAnim(anim_handle_head_RobotDefault);			}
			inline Animation *GetRobotHeadAttackOpenAnim		() { return GetAnim(anim_handle_head_RobotAttackOpen);		}
			inline Animation *GetRobotHeadAttackAnim			() { return GetAnim(anim_handle_head_RobotAttack);			}
			inline Animation *GetRobotHeadAttackCloseAnim		() { return GetAnim(anim_handle_head_RobotAttackClose);		}
			inline Animation *GetRobotHeadDefenseOpenAnim		() { return GetAnim(anim_handle_head_RobotDefenseOpen);		}
			inline Animation *GetRobotHeadDefenseAnim			() { return GetAnim(anim_handle_head_RobotDefense);			}
			inline Animation *GetRobotHeadDefenseCloseAnim		() { return GetAnim(anim_handle_head_RobotDefenseClose);	}
			inline Animation *GetRobotHeadDamageAnim			() { return GetAnim(anim_handle_head_RobotDamage);			}
			inline Animation *GetRobotHeadDeathAnim			() { return GetAnim(anim_handle_head_RobotDeath);			}

			//e n e r g y
			//animation energy (energy)
			//body
			inline Animation *GetEnergyBodyDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyDefault);	}
			inline Animation *GetEnergyBodyReserveAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyReserve);	}
			inline Animation *GetEnergyBodyEmptyAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyEmpty);	}
			inline Animation *GetEnergyBodyDamageAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyDamage);	}
			inline Animation *GetEnergyBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyDeath);	}
			//head
			inline Animation *GetEnergyHeadDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadDefault);	}
			inline Animation *GetEnergyHeadReserveAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadReserve);	}
			inline Animation *GetEnergyHeadEmptyAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadEmpty);	}
			inline Animation *GetEnergyHeadDamageAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadDamage);	}
			inline Animation *GetEnergyHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadDeath);	}

			//e n g i n e
			//animation engine
			//body
			inline Animation *GetEngineBodyDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyDefault);	}
			inline Animation *GetEngineBodyStartAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyStart);	}
			inline Animation *GetEngineBodyStopAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyStop);		}
			inline Animation *GetEngineBodyDamageAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyDamage);	}
			inline Animation *GetEngineBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyDeath);	}
			//head
			inline Animation *GetEngineHeadDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadDefault);	}
			inline Animation *GetEngineHeadStartAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadStart);	}
			inline Animation *GetEngineHeadStopAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadStop);		}
			inline Animation *GetEngineHeadDamageAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadDamage);	}
			inline Animation *GetEngineHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadDeath);	}

			//f u e l t a n k
			//animation fueltank
			//body
			inline Animation *GetFuelBodyDefaultAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankBodyDefault);	}
			inline Animation *GetFuelBodyReserveAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankBodyReserve);	}
			inline Animation *GetFuelBodyEmptyAnim				()	{ return GetAnim(anim_equipment_handle_FuelTankBodyEmpty);		}
			inline Animation *GetFuelBodyDamageAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankBodyDamage);		}
			//head
			inline Animation *GetFuelHeadDefaultAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankHeadDefault);	}
			inline Animation *GetFuelHeadReserveAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankHeadReserve);	}
			inline Animation *GetFuelHeadEmptyAnim				()	{ return GetAnim(anim_equipment_handle_FuelTankHeadEmpty);		}
			inline Animation *GetFuelHeadDamageAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankHeadDamage);		}

			//e n e r g y t a n k
			//animation energytank
			//body
			inline Animation *GetEnergyTankBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyDefault);		}
			inline Animation *GetEnergyTankBodyReserveAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyReserve);		}
			inline Animation *GetEnergyTankBodyEmptyAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyEmpty);		}
			inline Animation *GetEnergyTankBodyDamageAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyDamage);		}
			//head
			inline Animation *GetEnergyTankHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadDefault);		}
			inline Animation *GetEnergyTankHeadReserveAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadReserve);		}
			inline Animation *GetEnergyTankHeadEmptyAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadEmpty);		}
			inline Animation *GetEnergyTankHeadDamageAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadDamage);		}

			//l i g h t i n g  e q u i p m e n t
			//animation lightingequipment
			//body
			inline Animation *GetLightingEquipmentBodyLightDafaultAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightDefault);	}
			inline Animation *GetLightingEquipmentBodyLightOnAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightOn);		}
			inline Animation *GetLightingEquipmentBodyLightOffAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightOff);		}
			inline Animation *GetLightingEquipmentBodyLightDamageAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightDamage);	}
			inline Animation *GetLightingEquipmentBodyLightDeathAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightDeath);	}
			//head
			inline Animation *GetLightingEquipmentHeadLightDafaultAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightDefault);	}
			inline Animation *GetLightingEquipmentHeadLightOnAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightOn);		}
			inline Animation *GetLightingEquipmentHeadLightOffAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightOff);		}
			inline Animation *GetLightingEquipmentHeadLightDamageAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightDamage);	}
			inline Animation *GetLightingEquipmentHeadLightDeathAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightDeath);	}
			
			//g u n
			//animation gun
			//body
			inline Animation *GetGunBodyDefaultAnim		()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunDefalt);		}
			inline Animation *GetGunBodyShootAnim			()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunShoot);		}
			inline Animation *GetGunBodyAmmoLoadingAnim	()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunAmmoLoading);	}
			inline Animation *GetGunBodyAmmoEmptyAnim		()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunAmmoEmpty);	}
			inline Animation *GetGunBodyDamageAnim			()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunDamage);		}
			inline Animation *GetGunBodyServiceAnim		()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunService);		}
			inline Animation *GetGunBodyDeathAnim			()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunDeath);		}
			//head
			inline Animation *GetGunHeadDefaultAnim		()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunDefalt);		}
			inline Animation *GetGunHeadShootAnim			()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunShoot);		}
			inline Animation *GetGunHeadAmmoLoadingAnim	()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunAmmoLoading);	}
			inline Animation *GetGunHeadAmmoEmptyAnim		()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunAmmoEmpty);	}
			inline Animation *GetGunHeadDamageAnim			()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunDamage);		}
			inline Animation *GetGunHeadServiceAnim		()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunService); }
			inline Animation *GetGunHeadDeathAnim			()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunDeath);		}

			//a m m o
			//animation ammo
			inline Animation *GetAmmoDefaultAnim				()	{ return GetAnim(anim_equipment_handle_AmmoDefault);	}
			inline Animation *GetAmmoReserveAnim				()	{ return GetAnim(anim_equipment_handle_AmmoReserve);	}
			inline Animation *GetAmmoEmptyAnim					()	{ return GetAnim(anim_equipment_handle_AmmoEmpty);		}
			inline Animation *GetAmmoDamageAnim				()	{ return GetAnim(anim_equipment_handle_AmmoDamage);		}

			//w i n d t u r b i n e
			//animation windturbine
			//body
			inline Animation *GetWindTurbineBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineBodyDefault);			}
			inline Animation *GetWindTurbineBodyDamagetAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineBodyDamage);			}
			inline Animation *GetWindTurbineBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindTurbineBodyDeath);			}
			//head
			inline Animation *GetWindTurbineHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadDefault);			}
			inline Animation *GetWindTurbineHeadCargoOpenAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadCargoOpen);		}
			inline Animation *GetWindTurbineHeadCargoCloseAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadCargoClose);		}
			inline Animation *GetWindTurbineHeadUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadUpdateEnergy);	}
			inline Animation *GetWindTurbineHeadDamagetAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadDamage);			}
			inline Animation *GetWindTurbineHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadDeath);			}

			//s o l a r c e l l
			//animation solarcell
			//body
			inline Animation *GetSolarCellBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellBodyDefault);		}
			inline Animation *GetSolarCellBodyUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_SolarCellBodyUpdateEnergy);	}
			inline Animation *GetSolarCellBodyDamageAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellBodyDamage);		}
			inline Animation *GetSolarCellBodyDeathAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellBodyDeath);			}
			//head
			inline Animation *GetSolarCellHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellHeadDefault);		}
			inline Animation *GetSolarCellHeadUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_SolarCellHeadUpdateEnergy);	}
			inline Animation *GetSolarCellHeadDamageAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellHeadDamage);		}
			inline Animation *GetSolarCellHeadDeathAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellHeadDeath);			}

			//w i n d p o w e r s t a t i o n
			//animation windpowerstation
			//body
			inline Animation *GetWindPowerStationBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyDefault);		}
			inline Animation *GetWindPowerStationBodyUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyUpdateEnergy);	}
			inline Animation *GetWindPowerStationBodyDamageAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyDamage);			}
			inline Animation *GetWindPowerStationBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyDeath);			}
			//head
			inline Animation *GetWindPowerStationHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadDefault);		}
			inline Animation *GetWindPowerStationHeadUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadUpdateEnergy);	}
			inline Animation *GetWindPowerStationHeadDamageAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadDamage);			}
			inline Animation *GetWindPowerStationHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadDeath);			}

			//p o w e r r e l a y s t a t i on
			//animation powerrelaystation
			//body
			inline Animation *GetPowerRelayStationBodyDefaultAnim				() { return GetAnim(anim_handle_body_PowerRelayStationDefault);				}
			inline Animation *GetPowerRelayStationBodyUpdateConnectionAnim		() { return GetAnim(anim_handle_body_PowerRelayStationUpdateConnection);	}
			inline Animation *GetPowerRelayStationBodyDisconnectAnim			() { return GetAnim(anim_handle_body_PowerRelayStationDisconnect);			}
			inline Animation *GetPowerRelayStationBodyDamageAnim				() { return GetAnim(anim_handle_body_PowerRelayStationDamage);				}
			inline Animation *GetPowerRelayStationBodyDeathAnim				() { return GetAnim(anim_handle_body_PowerRelayStationDeath);				}
			//head
			inline Animation *GetPowerRelayStationHeadDefaultAnim				() { return GetAnim(anim_handle_head_PowerRelayStationDefault);				}
			inline Animation *GetPowerRelayStationHeadUpdateConnectionAnim		() { return GetAnim(anim_handle_head_PowerRelayStationUpdateConnection);	}
			inline Animation *GetPowerRelayStationHeadDisconnectAnim			() { return GetAnim(anim_handle_head_PowerRelayStationDisconnect);			}
			inline Animation *GetPowerRelayStationHeadDamageAnim				() { return GetAnim(anim_handle_head_PowerRelayStationDamage);				}
			inline Animation *GetPowerRelayStationHeadDeathAnim				() { return GetAnim(anim_handle_head_PowerRelayStationDeath);				}

			//c o m m u n i c a t i o n
			//animation communication
			//body
			inline Animation *GetCommunicationBodyDefaultAnim			() { return GetAnim(anim_handle_body_CommunicationDefault);			}
			inline Animation *GetCommunicationBodySearchAnim			() { return GetAnim(anim_handle_body_CommunicationSearch);			}
			inline Animation *GetCommunicationBodyLoginAnim			() { return GetAnim(anim_handle_body_CommunicationLogin);			}	
			inline Animation *GetCommunicationBodyAuthorizationAnim	() { return GetAnim(anim_handle_body_CommunicationAuthorization);	}
			inline Animation *GetCommunicationBodyUpdateAnim			() { return GetAnim(anim_handle_body_CommunicationUpdate);			}
			inline Animation *GetCommunicationBodyDamageAnim			() { return GetAnim(anim_handle_body_CommunicationDamage);			}
			inline Animation *GetCommunicationBodyDeathAnim			() { return GetAnim(anim_handle_body_CommunicationDeath);			}
			//head
			inline Animation *GetCommunicationHeadDefaultAnim			() { return GetAnim(anim_handle_head_CommunicationDefault);			}
			inline Animation *GetCommunicationHeadSearchAnim			() { return GetAnim(anim_handle_head_CommunicationSearch);			}
			inline Animation *GetCommunicationHeadLoginAnim			() { return GetAnim(anim_handle_head_CommunicationLogin);			}
			inline Animation *GetCommunicationHeadAuthorizationAnim	() { return GetAnim(anim_handle_head_CommunicationAuthorization);	}
			inline Animation *GetCommunicationHeadUpdateAnim			() { return GetAnim(anim_handle_head_CommunicationUpdate);			}
			inline Animation *GetCommunicationHeadDamageAnim			() { return GetAnim(anim_handle_head_CommunicationDamage);			}
			inline Animation *GetCommunicationHeadDeathAnim			() { return GetAnim(anim_handle_head_CommunicationDeath);			}

			//s l o t s r a t e
			//animation slotsrate
			//body
			inline Animation *GetSlotsRateBody_0_Anim					() { return GetAnim(anim_handle_body_SlotsRate_0); }
			inline Animation *GetSlotsRateBody_1_Anim					() { return GetAnim(anim_handle_body_SlotsRate_1); }
			inline Animation *GetSlotsRateBody_2_Anim					() { return GetAnim(anim_handle_body_SlotsRate_2); }
			inline Animation *GetSlotsRateBody_3_Anim					() { return GetAnim(anim_handle_body_SlotsRate_3); }
			inline Animation *GetSlotsRateBody_4_Anim					() { return GetAnim(anim_handle_body_SlotsRate_4); }
			//head
			inline Animation *GetSlotsRateHead_0_Anim					() { return GetAnim(anim_handle_head_SlotsRate_0); }
			inline Animation *GetSlotsRateHead_1_Anim					() { return GetAnim(anim_handle_head_SlotsRate_1); }
			inline Animation *GetSlotsRateHead_2_Anim					() { return GetAnim(anim_handle_head_SlotsRate_2); }
			inline Animation *GetSlotsRateHead_3_Anim					() { return GetAnim(anim_handle_head_SlotsRate_3); }
			inline Animation *GetSlotsRateHead_4_Anim					() { return GetAnim(anim_handle_head_SlotsRate_4); }

			//a i r c o n d i t i o n i n g
			//animation airconditioning
			//body
			inline Animation *GetAirconditioningBodyDefaultAnim		() { return GetAnim(anim_handle_body_airconditioning_default);		}
			inline Animation *GetAirconditioningBodyHeatingtAnim		() { return GetAnim(anim_handle_body_airconditioning_heating);		}
			inline Animation *GetAirconditioningBodyCoolingAnim		() { return GetAnim(anim_handle_body_airconditioning_cooling);		}
			inline Animation *GetAirconditioningBodyIneffectiveAnim	() { return GetAnim(anim_handle_body_airconditioning_ineffective);	}
			inline Animation *GetAirconditioningBodyDamageAnim			() { return GetAnim(anim_handle_body_airconditioning_damage);		}
			//head
			inline Animation *GetAirconditioningHeadDefaultAnim		() { return GetAnim(anim_handle_head_airconditioning_default);		}
			inline Animation *GetAirconditioningHeadHeatingtAnim		() { return GetAnim(anim_handle_head_airconditioning_heating);		}
			inline Animation *GetAirconditioningHeadCoolingAnim		() { return GetAnim(anim_handle_head_airconditioning_cooling);		}
			inline Animation *GetAirconditioningHeadIneffectiveAnim	() { return GetAnim(anim_handle_head_airconditioning_ineffective);	}
			inline Animation *GetAirconditioningHeadDamageAnim			() { return GetAnim(anim_handle_head_airconditioning_damage);		}

			//t h e r m a l i n s u l a t i o n
			//animation thermalinsulation
			//body
			inline Animation *GetThermalInsulationBodyDefaultAnim		() { return GetAnim(anim_handle_body_thermalinsulation_default);	}
			inline Animation *GetThermalInsulationBodyDamagetAnim		() { return GetAnim(anim_handle_body_thermalinsulation_damage);		}
			//head
			inline Animation *GetThermalInsulationHeadDefaultAnim		() { return GetAnim(anim_handle_head_thermalinsulation_default);	}
			inline Animation *GetThermalInsulationHeadDamagetAnim		() { return GetAnim(anim_handle_head_thermalinsulation_damage);		}

			//v e n t i l a t o r
			//animation thermalinsulation
			//body
			inline Animation *GetVentilatorBodyDefaultAnim		() { return GetAnim(anim_handle_body_ventilator_default);	}
			inline Animation *GetVentilatorBodyDamagetAnim		() { return GetAnim(anim_handle_body_ventilator_damage);	}
			//head
			inline Animation *GetVentilatorHeadDefaultAnim		() { return GetAnim(anim_handle_head_ventilator_default);	}
			inline Animation *GetVentilatorHeadDamagetAnim		() { return GetAnim(anim_handle_head_ventilator_damage);	}

			//b a t t e r y
			//animation battery
			//body
			inline Animation *GetBatteryBodyDefaultAnim	() { return GetAnim(anim_handle_body_battery_default);		}
			inline Animation *GetBatteryBodyOperateAnim	() { return GetAnim(anim_handle_body_battery_operate);		}
			inline Animation *GetBatteryBodyExhaustedAnim	() { return GetAnim(anim_handle_body_battery_exhausted);	}
			inline Animation *GetBatteryBodyDamagetAnim	() { return GetAnim(anim_handle_body_battery_damage);		}
			//head
			inline Animation *GetBatteryHeadDefaultAnim	() { return GetAnim(anim_handle_head_battery_default);		}
			inline Animation *GetBatteryHeadOperateAnim	() { return GetAnim(anim_handle_head_battery_operate);		}
			inline Animation *GetBatteryHeadExhaustedAnim	() { return GetAnim(anim_handle_head_battery_exhausted);	}
			inline Animation *GetBatteryHeadDamagetAnim	() { return GetAnim(anim_handle_head_battery_damage);		}

			///
			///Metoda sprawdza nazwy animacji i wstawia animacje do zestawu animacji
			///
			///@param &xml - referencja na obiekt klasy CXml
			///
			///@param *root - wskaŸnik na wêze³ dokumentu xml
			///
			void Parse(CXml &xml, rapidxml::xml_node<> *root = 0);

			///
			///Metoda zwraca sta³a referencjê na wektor przechowuj¹cy zestawy animacji
			///
			inline const std::vector<CNameAnimPairTranslator> &GetAnims() const { return m_anims; }

		private:

			std::string								m_animset_name;			//nazwa zestawu
			static int								m_anim_handle_number;	//uchwyt animacji
			static std::string						m_anim_handle_names[];	//tablica stringów przechowuj¹ca nazwy animacji
			std::vector<CNameAnimPairTranslator>	m_anims;				//kontener przechowuj¹cy animacje
		};

	}//namespace animation
}//namespace rendering
#endif//H_ANIM_SET_JACK
