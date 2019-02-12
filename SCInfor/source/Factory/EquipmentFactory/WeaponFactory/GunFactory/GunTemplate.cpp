//  ________________________________________
// | GunTemplate.cpp - class implementation |
// | Jack Flower June 2014.                 |
// |________________________________________|
//

#include "GunTemplate.h"
#include "../../../../ResourceManager/CResourceManager.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../Rendering/Displayable/CDisplayable.h"
#include "../../../../Utilities/Random/CRandom.h"

using namespace resource;
using namespace rendering::animation;

namespace factory
{

	RTTI_IMPL(GunTemplate, ActorTemplate);

	//Konstruktor
	GunTemplate::GunTemplate(void)
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_ammo_data(),
		p_templ_ammo(NULL),
		m_templ_time_ammo_load_delay(0.0f),
		m_templ_time_shot(0.0f),
		m_templ_range_shot(0.0f),
		m_templ_bullet_speed(0.0f),
		m_templ_barrel_count(0),
		m_templ_target_altitude(0.0f),
		m_templ_explosion_emiter(0.0f, 0.0f),
		m_templ_ammo_time_delayed(0.0f),
		m_templ_limit_amount_damage(0),
		m_templ_damage()
	{
	}

	//Destruktor wirtualny
	GunTemplate::~GunTemplate(void)
	{
		//ActorTemplate
		//m_templ_ammo_data
		p_templ_ammo = NULL;
		m_templ_time_ammo_load_delay = 0.0f;
		m_templ_time_shot = 0.0f;
		m_templ_range_shot = 0.0f;
		m_templ_bullet_speed = 0.0f;
		m_templ_barrel_count = 0;
		m_templ_target_altitude = 0.0f;
		m_templ_explosion_emiter.x = 0.0f;
		m_templ_explosion_emiter.y = 0.0f;
		m_templ_ammo_time_delayed = 0.0f;
		m_templ_limit_amount_damage = 0;
		//m_templ_damage
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string GunTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void GunTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool GunTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml ładuje wspólne cechy Actor
	bool GunTemplate::load(CXml & xml)
	{
		//ładowanie danych klasy bazowej Actor
		if (!ActorTemplate::load(xml)) return false;

		//ładowanie modułu prezentacji magazynka z amunicją
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "gun_data"))
		{
			//flaga, czy obiekt posiada magazynek z amunicją
			//m_templ_use_ammo = xml.GetBool(node, "use_ammo");
			m_templ_ammo_data.setUseEquipment(xml.GetBool(node, "use_ammo"));
			//zapisuję do zmiennej nazwę pliku z konfiguracją ammo
			std::string ammo_filename_tmp = xml.GetString(node, "ammo_filename");
			//emitery dla obiektu klasy Ammo
			m_templ_ammo_data.setEmiter(xml.GetFloat(node, "ammo_emiter_x"), xml.GetFloat(node, "ammo_emiter_y"));

			if (m_templ_ammo_data.getUseEquipment())
				p_templ_ammo = (AmmoTemplate*)gResourceManager.GetPhysicalTemplate(ammo_filename_tmp);
	
			m_templ_time_ammo_load_delay = xml.GetFloat(node, "time_ammo_load_delay");
			m_templ_time_shot = xml.GetFloat(node, "time_shot");
			m_templ_range_shot = xml.GetFloat(node, "range_shot");
			m_templ_bullet_speed = xml.GetFloat(node, "bullet_speed");
			m_templ_barrel_count = xml.GetInt(node, "barrel_count");
			m_templ_target_altitude = xml.GetFloat(node, "target_altitude");
			m_templ_explosion_emiter.x = xml.GetFloat(node, "explosion_emiter_x");
			m_templ_explosion_emiter.y = xml.GetFloat(node, "explosion_emiter_y");
			m_templ_ammo_time_delayed = xml.GetFloat(node, "ammo_time_delayed");
			m_templ_limit_amount_damage = xml.GetInt(node, "limit_amount_damage");
			//damage
			m_templ_damage.setDamageRange(xml.GetFloat(node, "reliability_range_first"), xml.GetFloat(node, "reliability_range_second"));
			m_templ_damage.setDurationDamage(xml.GetFloat(node, "duration_damage"));
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Gun
	Gun *GunTemplate::create(std::wstring id)
	{
		Gun *gun = gPhysicalManager.createGun(id);
		fill(gun);
		return gun;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void GunTemplate::fill(Gun *p_gun)
	{
		if(p_gun)
		{
			ActorTemplate::fill(p_gun);
			
			//pola tej klasy wzorca
			p_gun->setAmmoTransformed(m_templ_ammo_data.getTransformed());
			p_gun->setTimeAmmoLoadDelay(m_templ_time_ammo_load_delay);
			p_gun->setTimeShot(m_templ_time_shot);
			p_gun->setRangeShot(m_templ_range_shot);
			p_gun->setBulletSpeed(m_templ_bullet_speed);
			p_gun->setBarrelCount(m_templ_barrel_count);
			p_gun->setTargetAltitude(m_templ_target_altitude);
			p_gun->setExplosionEmiter(m_templ_explosion_emiter);
			p_gun->setAmmoTimeDelayed(m_templ_ammo_time_delayed);
			p_gun->setLimitAmountDamage(m_templ_limit_amount_damage);
			//damage
			p_gun->setDamage(m_templ_damage);

			//decorate	
			p_gun->setSmoothing(true);

			//przekazanie zestawu animacji do obiektu, który jest wypełniany danymi wzorca
			if (p_gun)
			{
				p_gun->setAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetGunBodyDefaultAnim() != NULL)
					p_gun->setAnimationBody(p_templ_animations->GetGunBodyDefaultAnim());

				//head
				if (p_templ_animations->GetGunHeadDefaultAnim() != NULL)
					p_gun->setAnimationHead(p_templ_animations->GetGunHeadDefaultAnim());
			}

			//jeśli obiekt posiada ammo (magazynek z amunicją)
			if (m_templ_ammo_data.getUseEquipment())
			{
				if (p_gun)
				{
					//pobieramy składową ammo i wzorzec wypełnia wskaźnik danymi
					p_gun->setAmmo(p_templ_ammo->create(L""));
					//przekazanie wskaźnikowi na klasę Ammo informacji o wzorcu
					p_gun->getAmmo()->setTemplate(p_templ_ammo);
					//decorator
					p_gun->getAmmo()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
