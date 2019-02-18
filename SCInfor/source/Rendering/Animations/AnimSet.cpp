//  ____________________________________
// | AnimSet.cpp - class implementation |
// |  Jack Flower - March 2012          |
// |____________________________________|
//

#include "AnimSet.h"
#include "AnimationManager.h"
#include "Animation.h"
#include "CNameAnimPairTranslator.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(AnimSet);

		//Rejestracja wpisów tablicy słownika parsującego std::string na uchwyt (enum - wyliczenie)
		//takimi mnemonikami posługiwać się w plikach xml
		std::string AnimSet::m_anim_handle_names[] = 
		{
			//p h y s i c a l
			//body animations names
			"default_body",
			"move_body",
			"death_body",
			//head animations names
			"default_head",
			"shot_head",
			"ammo_loading_head",
			"death_head",

			//a c t o r
			//body animations names
			"unit_default_body",
			"unit_move_body",
			"unit_attack_body",
			"unit_defense_body",
			"unit_damage_body",
			"unit_death_body",
			//head animations names
			"unit_default_head",
			"unit_move_head",
			"unit_attack_head",
			"unit_defense_head",
			"unit_damage_head",
			"unit_death_head",


			//r o b o t
			//body animations robot names
			"robot_body_default",
			//head animations robot names
			"robot_head_default",
			"robot_head_attack_open",
			"robot_head_attack",
			"robot_head_attack_close",
			"robot_head_defense_open",
			"robot_head_defense",
			"robot_head_defense_close",
			"robot_head_damage",
			"robot_head_death",

			//e n e r g y
			//body animations energy names
			"energy_body_default",
			"energy_body_reserve",
			"energy_body_empty",
			"energy_body_damage",
			"energy_body_death",
			//head animations energy names
			"energy_head_default",
			"energy_head_reserve",
			"energy_head_empty",
			"energy_head_damage",
			"energy_head_death",

			//e n g i n e
			//body animations engine names
			"engine_body_default",
			"engine_body_start",
			"engine_body_stop",
			"engine_body_damage",
			"engine_body_death",
			//head animations engine names
			"engine_head_default",
			"engine_head_start",
			"engine_head_stop",
			"engine_head_damage",
			"engine_head_death",

			//f u e l t a n k
			//body animations fuel names
			"fueltank_body_default",
			"fueltank_body_reserve",
			"fueltank_body_empty",
			"fueltank_body_damage",
			//head animations fuel names
			"fueltank_head_default",
			"fueltank_head_reserve",
			"fueltank_head_empty",
			"fuetankl_head_damage",

			//e n e r g y t a n k
			//body animations energytank names
			"energytank_body_default",
			"energytank_body_reserve",
			"energytank_body_empty",
			"energytank_body_damage",
			//head animations energytank names
			"energytank_head_default",
			"energytank_head_reserve",
			"energytank_head_empty",
			"energytank_head_damage",

			//l i g h t i n g  e q u i p m e n t
			//body animations lightingequipment names
			"lighting_equipment_body_light_default",
			"lighting_equipment_body_light_on",
			"lighting_equipment_body_light_off",
			"lighting_equipment_body_light_damage",
			"lighting_equipment_body_light_death",
			//head animations lightingequipment names
			"lighting_equipment_head_light_default",
			"lighting_equipment_head_light_on",
			"lighting_equipment_head_light_off",
			"lighting_equipment_head_light_damage",
			"lighting_equipment_head_light_death",
			
			//g u n
			//body animations gun names
			"gun_body_default",
			"gun_body_shoot",
			"gun_body_ammo_loading",
			"gun_body_ammo_empty",
			"gun_body_damage",
			"gun_body_service",
			"gun_body_death",
			//head animations gun names
			"gun_head_default",
			"gun_head_shoot",
			"gun_head_ammo_loading",
			"gun_head_ammo_empty",
			"gun_head_damage",
			"gun_head_service",
			"gun_head_death",
			
			//a m m o
			//body animations ammo names
			"ammo_default",
			"ammo_reserve",
			"ammo_empty",
			"ammo_damage",
			//head animations ammo names
			//
			//
			//
			//

			//w i n d t u r b i n e
			//body animations turbine names
			"windturbine_body_default",			//animacja łopatek turbiny - normalna praca
			"windturbine_body_damage",			//animacja łopatek turbiny - uszkodzone (naprawa)
			"windturbine_body_death",			//animacja łopatek turbiny - trwale uszkodzone
			//body animations turbine names
			"windturbine_head_default",			//animacja standardwej pracy turbiny
			"windturbine_head_cargo_open",		//animacja otwierania luku (zależy od warunków pogodowych - wiatr)
			"windturbine_head_cargo_close",		//animacja zamykania luku (zależy od warunków pogodowych - wiatr)
			"windturbine_head_update_energy",	//animacja pracy turbiny - wytwarzanie energii
			"windturbine_head_damage",			//animacja informująca, że turbina jest jest uszkodzona (naprawa)
			"windturbine_head_death",			//animacja informująca, że turbina jest jest trwale uszkodzona

			//s o l a r c e l l
			//body animations solarcell names
			"solarcell_body_default",
			"solarcell_body_update_energy",
			"solarcell_body_damage",
			"solarcell_body_death",
			//head animations solarcell names
			"solarcell_head_default",
			"solarcell_head_update_energy",
			"solarcell_head_damage",
			"solarcell_head_death",

			//w i n d p o w e r s t a t i o n
			//body animations windpowerstation names
			"windpowerstation_body_default",
			"windpowerstation_body_update_energy",
			"windpowerstation_body_damage",
			"windpowerstation_body_death",
			//head animations windpowerstation names
			"windpowerstation_head_default",
			"windpowerstation_head_update_energy",
			"windpowerstation_head_damage",
			"windpowerstation_head_death",

			//p o w e r r e l a y s t a t i on
			//body animations powerrelaystation names
			"powerrelaystation_body_default",
			"powerrelaystation_body_updateconnection",
			"powerrelaystation_body_disconnect",
			"powerrelaystation_body_damage",
			"powerrelaystation_body_death",
			//head animations powerrelaystation handlers
			"powerrelaystation_head_default",
			"powerrelaystation_head_updateconnection",
			"powerrelaystation_head_disconnect",
			"powerrelaystation_head_damage",
			"powerrelaystation_head_death",

			//c o m m u n i c a t i o n
			//body animations communication handlers
			"communication_body_default",
			"communication_body_search",
			"communication_body_login",
			"communication_body_authorization",
			"communication_body_update",
			"communication_body_damage",
			"communication_body_death",
			//head animations communication handlers
			"communication_head_default",
			"communication_head_search",
			"communication_head_login",
			"communication_head_authorization",
			"communication_head_update",
			"communication_head_damage",
			"communication_head_death",
				
			//s l o t s r a t e
			//body animations slotsrate handlers
			"slots_rate_body_0",
			"slots_rate_body_1",
			"slots_rate_body_2",
			"slots_rate_body_3",
			"slots_rate_body_4",
			//head animations slotsrate handlers
			"slots_rate_head_0",
			"slots_rate_head_1",
			"slots_rate_head_2",
			"slots_rate_head_3",
			"slots_rate_head_4",

			//a i r c o n d i t i o n i n g
			//body animations airconditioning handlers
			"airconditioning_body_default",				//animacja startowa dopóki urządzenie się nie włączy
			"airconditioning_body_heating",				//klimatyzator nagrzewa
			"airconditioning_body_cooling",				//klimatyzator schładza
			"airconditioning_body_ineffective",			//klimatyzator jest nieefektywny - temperaturaotoczenia poza zakresem
			"airconditioning_body_damage",				//uszkodzenie
			//head animations airconditioning handlers
			"airconditioning_head_default",
			"airconditioning_head_heating",
			"airconditioning_head_cooling",
			"airconditioning_head_ineffective",
			"airconditioning_head_damage",

			//t h e r m a l i n s u l a t i o n
			//body animations thermalinsulation handlers
			"thermalinsulation_body_default",
			"thermalinsulation_body_damage",
			//head animations thermalinsulation handlers
			"thermalinsulation_head_default",
			"thermalinsulation_head_damage",

			//v e n t i l a t o r
			//body animations ventilator handlers
			"ventilator_body_default",
			"ventilator_body_damage",
			//head animations ventilator handlers
			"ventilator_head_default",
			"ventilator_head_damage",

			//b a t t e r y
			//body animations battery handlers
			"battery_body_default",
			"battery_body_operate",
			"battery_body_exhausted",
			"battery_body_damage",
			//head animations battery handlers
			"battery_head_default",
			"battery_head_operate",
			"battery_head_exhausted",
			"battery_head_damage"
		};

		//Nadanie wartości stałej składowej statycznej - obliczenie ile wpisów ma tablica m_anim_handle_names[]
		int AnimSet::m_anim_handle_number = sizeof(AnimSet::m_anim_handle_names) / sizeof(std::string);

		//Konstruktor domyślny
		AnimSet::AnimSet()
		:
			m_animset_name(""),
			m_anims()
		{
			m_anims.resize(m_anim_handle_number);
		}

		//Konstruktor kopiujący
		AnimSet::AnimSet(const AnimSet & AnimSetCopy)
		:
			m_animset_name(AnimSetCopy.m_animset_name),
			m_anims(AnimSetCopy.m_anims)
		{
			m_anims.resize(m_anim_handle_number);
		}

		//Konstruktor przenoszący
		AnimSet::AnimSet(AnimSet && other)
		:
			m_animset_name(other.m_animset_name),
			m_anims(other.m_anims)
		{
			//zerujemy składowe obiektu źródłowego...
			other.m_animset_name = "";
			other.m_anims.clear();
		}

		//Destruktor
		AnimSet::~AnimSet()
		{
			m_animset_name = "";
			m_anim_handle_number = 0;
			m_anims.clear();
		}

		//Przeciążony operator przypisania kopiowania
		AnimSet & AnimSet::operator=(const AnimSet & copy)
		{
			if (this != &copy)
			{
				m_animset_name = copy.m_animset_name;
				m_anims = copy.m_anims;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		AnimSet & AnimSet::operator=(AnimSet && other)
		{
			if (this != &other)
			{
				m_animset_name = other.m_animset_name;
				m_anims = other.m_anims;

				//zerowanie obiektu źródłowego
				other.m_animset_name = "";
				other.m_anims.clear();
			}
			return *this;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string AnimSet::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca nazwę zestawu animacji
		const std::string AnimSet::getAnimSetName() const
		{
			return m_animset_name;
		}

		//Metoda ustawia nazwę zestawu animacji
		void AnimSet::setAnimSetName(const std::string & animset_name)
		{
			m_animset_name = animset_name;
		}

		//Metoda parsuje uchwyt animacji na podstawie nazwy lub int
		int AnimSet::parseAnimHandle(std::string & handle_input)
		{
			//sprawdzam, czy w tablicy znajduje się podany parametr (uchwyt)
			for (int i = 0; i < m_anim_handle_number; i++)
				if (m_anim_handle_names[i] == handle_input)
				return i;
			
			//sprawdzamy, czy parametr jest liczbą
			int tmp;
			//sprawdzam, czy w tablicy znajduje się podany parametr (jako liczba) (uchwyt)
			if (sscanf(handle_input.c_str(),"%d", &tmp) == 1)
				return m_anim_handle_number + tmp;
			//w przypadku, gdy w tablicy nie znaleziono podanego parametru (uchwytu) zwracamy kod błędu
			return -1;
		}

		//Metoda ustawia animację
		void AnimSet::setAnimation(int anim_handle, Animation *p_anim)
		{
			if ((anim_handle < 0) || (p_anim == NULL)) return;
			if ((unsigned int)anim_handle >= m_anims.size()) m_anims.resize(anim_handle + 1);
			m_anims[anim_handle] = CNameAnimPairTranslator(p_anim->getAnimationName());
			m_anims[anim_handle].SetAnim(p_anim);
		}

		//Metoda ustawia animację
		void AnimSet::setAnimation(int anim_handle, std::string & anim_name)
		{
			if (anim_handle < 0) return;
			if ((unsigned int) anim_handle >= m_anims.size()) m_anims.resize(anim_handle + 1);
			m_anims[anim_handle] = CNameAnimPairTranslator(anim_name);
		}

		//Metoda zwraca nazwę animacji na podstawie uchwytu
		std::string *AnimSet::getAnimName(int anim_handle)
		{
			if ((anim_handle < 0) || ((unsigned int) anim_handle >= m_anims.size()))
				return NULL;
			return &m_anims[anim_handle].GetAnimationName();
		}

		//Metoda zwraca wskaźnik na animację na podstawie parametru - uchwytu
		Animation *AnimSet::getAnim(int anim_handle)
		{
			//nieprawidłowy uchwyt zwraca NULL
			if ((anim_handle < 0) || ((unsigned int) anim_handle >= m_anims.size()))
				return NULL;
			//jeśli animacja pod indeksem (uchwyt-parametr) nie jest gotowa (wgrana)
			if (!m_anims[anim_handle].GetReady())
			{
				//ustawiamy animację na pobraną w menadżera animacji
				m_anims[anim_handle].SetAnim(gAnimationManager.getAnimation(m_anims[anim_handle].GetAnimationName()));
			}
			return m_anims[anim_handle].GetAnimation();//zwracamy z wzrorca już gotową animację (wskaźnik)
		}

		//Metoda sprawdza nazwy animacji i wstawia animacje do zestawu animacji
		void AnimSet::parse(CXml & xml, rapidxml::xml_node<> *root)
		{
			std::string tmp;//zmienna na odczytaną nazwę animacji i odczytany typ animacji z zestawu
			for (xml_node<> *node = xml.GetChild(root, "anim"); node; node=xml.GetSibling(node, "anim") )
			{
				tmp = xml.GetString(node, "type");	//odczytuję typ animacji z zestawu
				int a_handle = parseAnimHandle(tmp);//sprawdzam, czy odczytany typ animacji istnieje (zamiana na uchwyt)
				if (a_handle < 0) continue;			//kontynuacja, gdy nie ma typu (zostanie to i tak zapisane pod takim kluczem)
				tmp = xml.GetString(node, "name");	//odczyt nazwy animacji z zestawu
				setAnimation(a_handle, tmp);		//ustawienie animacji (uchwyt, nazwa animacji)
													//i zapis do wektora
			}
		}
	}//namespace animation
}//namespace rendering
