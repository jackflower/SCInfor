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
		class CAnimation;

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
			void SetAnimation(int anim_handle, CAnimation *p_anim);

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
			CAnimation *GetAnim(int anim_handle);
	    
			//metody pomocnicze
			
			//p h y s i c a l
			//body animations
			inline CAnimation *GetDefaultAnimBody				()	{ return GetAnim(anim_handle_body_Default);			}
			inline CAnimation *GetMoveAnimBody					()	{ return GetAnim(anim_handle_body_Move);			}
			inline CAnimation *GetDeathAnimBody					()	{ return GetAnim(anim_handle_body_Death);			}
			//head animations
			inline CAnimation *GetDefaultAnimHead				()	{ return GetAnim(anim_handle_head_Default);			}
			inline CAnimation *GetShotAnimHead					()	{ return GetAnim(anim_handle_head_Shot);			}
			inline CAnimation *GetAmmoLoadingAnimHead			()	{ return GetAnim(anim_handle_head_Ammo_Loading);	}
			inline CAnimation *GetDeathAnimHead					()	{ return GetAnim(anim_handle_head_Death);			}
			
			//a c t o r
			//body animations
			inline CAnimation *GetUnitBodyDefaultAnim			() { return GetAnim(anim_handle_body_ActorDefault);		}
			inline CAnimation *GetUnitBodyMovetAnim				() { return GetAnim(anim_handle_body_ActorMove);		}
			inline CAnimation *GetUnitBodyAttackAnim			() { return GetAnim(anim_handle_body_ActorAttack);		}
			inline CAnimation *GetUnitBodyDefenseAnim			() { return GetAnim(anim_handle_body_ActorDefense);		}
			inline CAnimation *GetUnitBodyDamageAnim			() { return GetAnim(anim_handle_body_ActorDamage);		}
			inline CAnimation *GetUnitBodyDeathAnim				() { return GetAnim(anim_handle_body_ActorDeath);		}
			//head animations
			inline CAnimation *GetUnitHeadDefaultAnim			() { return GetAnim(anim_handle_head_ActorDefault);		}
			inline CAnimation *GetUnitHeadMovetAnim				() { return GetAnim(anim_handle_head_ActorMove);		}
			inline CAnimation *GetUnitHeadAttackAnim			() { return GetAnim(anim_handle_head_ActorAttack);		}
			inline CAnimation *GetUnitHeadDefenseAnim			() { return GetAnim(anim_handle_head_ActorDefense);		}
			inline CAnimation *GetUnitHeadDamageAnim			() { return GetAnim(anim_handle_head_ActorDamage);		}
			inline CAnimation *GetUnitHeadDeathAnim				() { return GetAnim(anim_handle_head_ActorDeath);		}

			//r o b o t
			//body animations
			inline CAnimation *GetRobotBodyDefaultAnim			() { return GetAnim(anim_handle_body_RobotDefault);			}
			//head animations
			inline CAnimation *GetRobotHeadDefaultAnim			() { return GetAnim(anim_handle_head_RobotDefault);			}
			inline CAnimation *GetRobotHeadAttackOpenAnim		() { return GetAnim(anim_handle_head_RobotAttackOpen);		}
			inline CAnimation *GetRobotHeadAttackAnim			() { return GetAnim(anim_handle_head_RobotAttack);			}
			inline CAnimation *GetRobotHeadAttackCloseAnim		() { return GetAnim(anim_handle_head_RobotAttackClose);		}
			inline CAnimation *GetRobotHeadDefenseOpenAnim		() { return GetAnim(anim_handle_head_RobotDefenseOpen);		}
			inline CAnimation *GetRobotHeadDefenseAnim			() { return GetAnim(anim_handle_head_RobotDefense);			}
			inline CAnimation *GetRobotHeadDefenseCloseAnim		() { return GetAnim(anim_handle_head_RobotDefenseClose);	}
			inline CAnimation *GetRobotHeadDamageAnim			() { return GetAnim(anim_handle_head_RobotDamage);			}
			inline CAnimation *GetRobotHeadDeathAnim			() { return GetAnim(anim_handle_head_RobotDeath);			}

			//e n e r g y
			//animation energy (energy)
			//body
			inline CAnimation *GetEnergyBodyDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyDefault);	}
			inline CAnimation *GetEnergyBodyReserveAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyReserve);	}
			inline CAnimation *GetEnergyBodyEmptyAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyEmpty);	}
			inline CAnimation *GetEnergyBodyDamageAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyDamage);	}
			inline CAnimation *GetEnergyBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_EnergyBodyDeath);	}
			//head
			inline CAnimation *GetEnergyHeadDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadDefault);	}
			inline CAnimation *GetEnergyHeadReserveAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadReserve);	}
			inline CAnimation *GetEnergyHeadEmptyAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadEmpty);	}
			inline CAnimation *GetEnergyHeadDamageAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadDamage);	}
			inline CAnimation *GetEnergyHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_EnergyHeadDeath);	}

			//e n g i n e
			//animation engine
			//body
			inline CAnimation *GetEngineBodyDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyDefault);	}
			inline CAnimation *GetEngineBodyStartAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyStart);	}
			inline CAnimation *GetEngineBodyStopAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyStop);		}
			inline CAnimation *GetEngineBodyDamageAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyDamage);	}
			inline CAnimation *GetEngineBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_EngineBodyDeath);	}
			//head
			inline CAnimation *GetEngineHeadDefaultAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadDefault);	}
			inline CAnimation *GetEngineHeadStartAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadStart);	}
			inline CAnimation *GetEngineHeadStopAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadStop);		}
			inline CAnimation *GetEngineHeadDamageAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadDamage);	}
			inline CAnimation *GetEngineHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_EngineHeadDeath);	}

			//f u e l t a n k
			//animation fueltank
			//body
			inline CAnimation *GetFuelBodyDefaultAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankBodyDefault);	}
			inline CAnimation *GetFuelBodyReserveAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankBodyReserve);	}
			inline CAnimation *GetFuelBodyEmptyAnim				()	{ return GetAnim(anim_equipment_handle_FuelTankBodyEmpty);		}
			inline CAnimation *GetFuelBodyDamageAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankBodyDamage);		}
			//head
			inline CAnimation *GetFuelHeadDefaultAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankHeadDefault);	}
			inline CAnimation *GetFuelHeadReserveAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankHeadReserve);	}
			inline CAnimation *GetFuelHeadEmptyAnim				()	{ return GetAnim(anim_equipment_handle_FuelTankHeadEmpty);		}
			inline CAnimation *GetFuelHeadDamageAnim			()	{ return GetAnim(anim_equipment_handle_FuelTankHeadDamage);		}

			//e n e r g y t a n k
			//animation energytank
			//body
			inline CAnimation *GetEnergyTankBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyDefault);		}
			inline CAnimation *GetEnergyTankBodyReserveAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyReserve);		}
			inline CAnimation *GetEnergyTankBodyEmptyAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyEmpty);		}
			inline CAnimation *GetEnergyTankBodyDamageAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankBodyDamage);		}
			//head
			inline CAnimation *GetEnergyTankHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadDefault);		}
			inline CAnimation *GetEnergyTankHeadReserveAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadReserve);		}
			inline CAnimation *GetEnergyTankHeadEmptyAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadEmpty);		}
			inline CAnimation *GetEnergyTankHeadDamageAnim		()	{ return GetAnim(anim_equipment_handle_EnergyTankHeadDamage);		}

			//l i g h t i n g  e q u i p m e n t
			//animation lightingequipment
			//body
			inline CAnimation *GetLightingEquipmentBodyLightDafaultAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightDefault);	}
			inline CAnimation *GetLightingEquipmentBodyLightOnAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightOn);		}
			inline CAnimation *GetLightingEquipmentBodyLightOffAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightOff);		}
			inline CAnimation *GetLightingEquipmentBodyLightDamageAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightDamage);	}
			inline CAnimation *GetLightingEquipmentBodyLightDeathAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentBodyLightDeath);	}
			//head
			inline CAnimation *GetLightingEquipmentHeadLightDafaultAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightDefault);	}
			inline CAnimation *GetLightingEquipmentHeadLightOnAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightOn);		}
			inline CAnimation *GetLightingEquipmentHeadLightOffAnim		()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightOff);		}
			inline CAnimation *GetLightingEquipmentHeadLightDamageAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightDamage);	}
			inline CAnimation *GetLightingEquipmentHeadLightDeathAnim	()	{ return GetAnim(anim_equipment_handle_LightingEquipmentHeadLightDeath);	}
			
			//g u n
			//animation gun
			//body
			inline CAnimation *GetGunBodyDefaultAnim		()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunDefalt);		}
			inline CAnimation *GetGunBodyShootAnim			()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunShoot);		}
			inline CAnimation *GetGunBodyAmmoLoadingAnim	()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunAmmoLoading);	}
			inline CAnimation *GetGunBodyAmmoEmptyAnim		()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunAmmoEmpty);	}
			inline CAnimation *GetGunBodyDamageAnim			()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunDamage);		}
			inline CAnimation *GetGunBodyServiceAnim		()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunService);		}
			inline CAnimation *GetGunBodyDeathAnim			()	{ return GetAnim(anim_equipment_weapon_handle_BodyGunDeath);		}
			//head
			inline CAnimation *GetGunHeadDefaultAnim		()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunDefalt);		}
			inline CAnimation *GetGunHeadShootAnim			()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunShoot);		}
			inline CAnimation *GetGunHeadAmmoLoadingAnim	()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunAmmoLoading);	}
			inline CAnimation *GetGunHeadAmmoEmptyAnim		()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunAmmoEmpty);	}
			inline CAnimation *GetGunHeadDamageAnim			()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunDamage);		}
			inline CAnimation *GetGunHeadServiceAnim		()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunService); }
			inline CAnimation *GetGunHeadDeathAnim			()	{ return GetAnim(anim_equipment_weapon_handle_HeadGunDeath);		}

			//a m m o
			//animation ammo
			inline CAnimation *GetAmmoDefaultAnim				()	{ return GetAnim(anim_equipment_handle_AmmoDefault);	}
			inline CAnimation *GetAmmoReserveAnim				()	{ return GetAnim(anim_equipment_handle_AmmoReserve);	}
			inline CAnimation *GetAmmoEmptyAnim					()	{ return GetAnim(anim_equipment_handle_AmmoEmpty);		}
			inline CAnimation *GetAmmoDamageAnim				()	{ return GetAnim(anim_equipment_handle_AmmoDamage);		}

			//w i n d t u r b i n e
			//animation windturbine
			//body
			inline CAnimation *GetWindTurbineBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineBodyDefault);			}
			inline CAnimation *GetWindTurbineBodyDamagetAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineBodyDamage);			}
			inline CAnimation *GetWindTurbineBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindTurbineBodyDeath);			}
			//head
			inline CAnimation *GetWindTurbineHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadDefault);			}
			inline CAnimation *GetWindTurbineHeadCargoOpenAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadCargoOpen);		}
			inline CAnimation *GetWindTurbineHeadCargoCloseAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadCargoClose);		}
			inline CAnimation *GetWindTurbineHeadUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadUpdateEnergy);	}
			inline CAnimation *GetWindTurbineHeadDamagetAnim		()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadDamage);			}
			inline CAnimation *GetWindTurbineHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindTurbineHeadDeath);			}

			//s o l a r c e l l
			//animation solarcell
			//body
			inline CAnimation *GetSolarCellBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellBodyDefault);		}
			inline CAnimation *GetSolarCellBodyUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_SolarCellBodyUpdateEnergy);	}
			inline CAnimation *GetSolarCellBodyDamageAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellBodyDamage);		}
			inline CAnimation *GetSolarCellBodyDeathAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellBodyDeath);			}
			//head
			inline CAnimation *GetSolarCellHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellHeadDefault);		}
			inline CAnimation *GetSolarCellHeadUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_SolarCellHeadUpdateEnergy);	}
			inline CAnimation *GetSolarCellHeadDamageAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellHeadDamage);		}
			inline CAnimation *GetSolarCellHeadDeathAnim		()	{ return GetAnim(anim_equipment_handle_SolarCellHeadDeath);			}

			//w i n d p o w e r s t a t i o n
			//animation windpowerstation
			//body
			inline CAnimation *GetWindPowerStationBodyDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyDefault);		}
			inline CAnimation *GetWindPowerStationBodyUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyUpdateEnergy);	}
			inline CAnimation *GetWindPowerStationBodyDamageAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyDamage);			}
			inline CAnimation *GetWindPowerStationBodyDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindPowerStationBodyDeath);			}
			//head
			inline CAnimation *GetWindPowerStationHeadDefaultAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadDefault);		}
			inline CAnimation *GetWindPowerStationHeadUpdateEnergyAnim	()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadUpdateEnergy);	}
			inline CAnimation *GetWindPowerStationHeadDamageAnim		()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadDamage);			}
			inline CAnimation *GetWindPowerStationHeadDeathAnim			()	{ return GetAnim(anim_equipment_handle_WindPowerStationHeadDeath);			}

			//p o w e r r e l a y s t a t i on
			//animation powerrelaystation
			//body
			inline CAnimation *GetPowerRelayStationBodyDefaultAnim				() { return GetAnim(anim_handle_body_PowerRelayStationDefault);				}
			inline CAnimation *GetPowerRelayStationBodyUpdateConnectionAnim		() { return GetAnim(anim_handle_body_PowerRelayStationUpdateConnection);	}
			inline CAnimation *GetPowerRelayStationBodyDisconnectAnim			() { return GetAnim(anim_handle_body_PowerRelayStationDisconnect);			}
			inline CAnimation *GetPowerRelayStationBodyDamageAnim				() { return GetAnim(anim_handle_body_PowerRelayStationDamage);				}
			inline CAnimation *GetPowerRelayStationBodyDeathAnim				() { return GetAnim(anim_handle_body_PowerRelayStationDeath);				}
			//head
			inline CAnimation *GetPowerRelayStationHeadDefaultAnim				() { return GetAnim(anim_handle_head_PowerRelayStationDefault);				}
			inline CAnimation *GetPowerRelayStationHeadUpdateConnectionAnim		() { return GetAnim(anim_handle_head_PowerRelayStationUpdateConnection);	}
			inline CAnimation *GetPowerRelayStationHeadDisconnectAnim			() { return GetAnim(anim_handle_head_PowerRelayStationDisconnect);			}
			inline CAnimation *GetPowerRelayStationHeadDamageAnim				() { return GetAnim(anim_handle_head_PowerRelayStationDamage);				}
			inline CAnimation *GetPowerRelayStationHeadDeathAnim				() { return GetAnim(anim_handle_head_PowerRelayStationDeath);				}

			//c o m m u n i c a t i o n
			//animation communication
			//body
			inline CAnimation *GetCommunicationBodyDefaultAnim			() { return GetAnim(anim_handle_body_CommunicationDefault);			}
			inline CAnimation *GetCommunicationBodySearchAnim			() { return GetAnim(anim_handle_body_CommunicationSearch);			}
			inline CAnimation *GetCommunicationBodyLoginAnim			() { return GetAnim(anim_handle_body_CommunicationLogin);			}	
			inline CAnimation *GetCommunicationBodyAuthorizationAnim	() { return GetAnim(anim_handle_body_CommunicationAuthorization);	}
			inline CAnimation *GetCommunicationBodyUpdateAnim			() { return GetAnim(anim_handle_body_CommunicationUpdate);			}
			inline CAnimation *GetCommunicationBodyDamageAnim			() { return GetAnim(anim_handle_body_CommunicationDamage);			}
			inline CAnimation *GetCommunicationBodyDeathAnim			() { return GetAnim(anim_handle_body_CommunicationDeath);			}
			//head
			inline CAnimation *GetCommunicationHeadDefaultAnim			() { return GetAnim(anim_handle_head_CommunicationDefault);			}
			inline CAnimation *GetCommunicationHeadSearchAnim			() { return GetAnim(anim_handle_head_CommunicationSearch);			}
			inline CAnimation *GetCommunicationHeadLoginAnim			() { return GetAnim(anim_handle_head_CommunicationLogin);			}
			inline CAnimation *GetCommunicationHeadAuthorizationAnim	() { return GetAnim(anim_handle_head_CommunicationAuthorization);	}
			inline CAnimation *GetCommunicationHeadUpdateAnim			() { return GetAnim(anim_handle_head_CommunicationUpdate);			}
			inline CAnimation *GetCommunicationHeadDamageAnim			() { return GetAnim(anim_handle_head_CommunicationDamage);			}
			inline CAnimation *GetCommunicationHeadDeathAnim			() { return GetAnim(anim_handle_head_CommunicationDeath);			}

			//s l o t s r a t e
			//animation slotsrate
			//body
			inline CAnimation *GetSlotsRateBody_0_Anim					() { return GetAnim(anim_handle_body_SlotsRate_0); }
			inline CAnimation *GetSlotsRateBody_1_Anim					() { return GetAnim(anim_handle_body_SlotsRate_1); }
			inline CAnimation *GetSlotsRateBody_2_Anim					() { return GetAnim(anim_handle_body_SlotsRate_2); }
			inline CAnimation *GetSlotsRateBody_3_Anim					() { return GetAnim(anim_handle_body_SlotsRate_3); }
			inline CAnimation *GetSlotsRateBody_4_Anim					() { return GetAnim(anim_handle_body_SlotsRate_4); }
			//head
			inline CAnimation *GetSlotsRateHead_0_Anim					() { return GetAnim(anim_handle_head_SlotsRate_0); }
			inline CAnimation *GetSlotsRateHead_1_Anim					() { return GetAnim(anim_handle_head_SlotsRate_1); }
			inline CAnimation *GetSlotsRateHead_2_Anim					() { return GetAnim(anim_handle_head_SlotsRate_2); }
			inline CAnimation *GetSlotsRateHead_3_Anim					() { return GetAnim(anim_handle_head_SlotsRate_3); }
			inline CAnimation *GetSlotsRateHead_4_Anim					() { return GetAnim(anim_handle_head_SlotsRate_4); }

			//a i r c o n d i t i o n i n g
			//animation airconditioning
			//body
			inline CAnimation *GetAirconditioningBodyDefaultAnim		() { return GetAnim(anim_handle_body_airconditioning_default);		}
			inline CAnimation *GetAirconditioningBodyHeatingtAnim		() { return GetAnim(anim_handle_body_airconditioning_heating);		}
			inline CAnimation *GetAirconditioningBodyCoolingAnim		() { return GetAnim(anim_handle_body_airconditioning_cooling);		}
			inline CAnimation *GetAirconditioningBodyIneffectiveAnim	() { return GetAnim(anim_handle_body_airconditioning_ineffective);	}
			inline CAnimation *GetAirconditioningBodyDamageAnim			() { return GetAnim(anim_handle_body_airconditioning_damage);		}
			//head
			inline CAnimation *GetAirconditioningHeadDefaultAnim		() { return GetAnim(anim_handle_head_airconditioning_default);		}
			inline CAnimation *GetAirconditioningHeadHeatingtAnim		() { return GetAnim(anim_handle_head_airconditioning_heating);		}
			inline CAnimation *GetAirconditioningHeadCoolingAnim		() { return GetAnim(anim_handle_head_airconditioning_cooling);		}
			inline CAnimation *GetAirconditioningHeadIneffectiveAnim	() { return GetAnim(anim_handle_head_airconditioning_ineffective);	}
			inline CAnimation *GetAirconditioningHeadDamageAnim			() { return GetAnim(anim_handle_head_airconditioning_damage);		}

			//t h e r m a l i n s u l a t i o n
			//animation thermalinsulation
			//body
			inline CAnimation *GetThermalInsulationBodyDefaultAnim		() { return GetAnim(anim_handle_body_thermalinsulation_default);	}
			inline CAnimation *GetThermalInsulationBodyDamagetAnim		() { return GetAnim(anim_handle_body_thermalinsulation_damage);		}
			//head
			inline CAnimation *GetThermalInsulationHeadDefaultAnim		() { return GetAnim(anim_handle_head_thermalinsulation_default);	}
			inline CAnimation *GetThermalInsulationHeadDamagetAnim		() { return GetAnim(anim_handle_head_thermalinsulation_damage);		}

			//v e n t i l a t o r
			//animation thermalinsulation
			//body
			inline CAnimation *GetVentilatorBodyDefaultAnim		() { return GetAnim(anim_handle_body_ventilator_default);	}
			inline CAnimation *GetVentilatorBodyDamagetAnim		() { return GetAnim(anim_handle_body_ventilator_damage);	}
			//head
			inline CAnimation *GetVentilatorHeadDefaultAnim		() { return GetAnim(anim_handle_head_ventilator_default);	}
			inline CAnimation *GetVentilatorHeadDamagetAnim		() { return GetAnim(anim_handle_head_ventilator_damage);	}

			//b a t t e r y
			//animation battery
			//body
			inline CAnimation *GetBatteryBodyDefaultAnim	() { return GetAnim(anim_handle_body_battery_default);		}
			inline CAnimation *GetBatteryBodyOperateAnim	() { return GetAnim(anim_handle_body_battery_operate);		}
			inline CAnimation *GetBatteryBodyExhaustedAnim	() { return GetAnim(anim_handle_body_battery_exhausted);	}
			inline CAnimation *GetBatteryBodyDamagetAnim	() { return GetAnim(anim_handle_body_battery_damage);		}
			//head
			inline CAnimation *GetBatteryHeadDefaultAnim	() { return GetAnim(anim_handle_head_battery_default);		}
			inline CAnimation *GetBatteryHeadOperateAnim	() { return GetAnim(anim_handle_head_battery_operate);		}
			inline CAnimation *GetBatteryHeadExhaustedAnim	() { return GetAnim(anim_handle_head_battery_exhausted);	}
			inline CAnimation *GetBatteryHeadDamagetAnim	() { return GetAnim(anim_handle_head_battery_damage);		}

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
