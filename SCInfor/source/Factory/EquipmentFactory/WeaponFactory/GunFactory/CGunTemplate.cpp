//  _________________________________________
// | CGunTemplate.cpp - class implementation |
// | Jack Flower June 2014.                  |
// |_________________________________________|
//

#include "CGunTemplate.h"
#include "../../../../ResourceManager/CResourceManager.h"
#include "../../../../Rendering/Animations/CAnimSet.h"
#include "../../../../Rendering/Displayable/CDisplayable.h"
#include "../../../../Utilities/Random/CRandom.h"

using namespace resource;
using namespace rendering::animation;

namespace factory
{

	RTTI_IMPL(CGunTemplate, CActorTemplate);

	//Konstruktor
	CGunTemplate::CGunTemplate(void)
	:
		CActorTemplate						(),//konstruktor klasy bazowej
		m_templ_ammo_data					(),
		p_templ_ammo						(NULL),
		m_templ_time_ammo_load_delay		(0.0f),
		m_templ_time_shot					(0.0f),
		m_templ_range_shot					(0.0f),
		m_templ_bullet_speed				(0.0f),
		m_templ_barrel_count				(0),
		m_templ_target_altitude				(0.0f),
		m_templ_explosion_emiter			(0.0f, 0.0f),
		m_templ_ammo_time_delayed			(0.0f),
		m_templ_limit_amount_damage			(0),
		m_templ_damage						()
	{
	}

	//Destruktor wirtualny
	CGunTemplate::~CGunTemplate(void)
	{
		//CActorTemplate					not edit
		//m_templ_ammo_data					not edit
		p_templ_ammo						= NULL;
		m_templ_time_ammo_load_delay		= 0.0f;
		m_templ_time_shot					= 0.0f;
		m_templ_range_shot					= 0.0f;
		m_templ_bullet_speed				= 0.0f;
		m_templ_barrel_count				= 0;
		m_templ_target_altitude				= 0.0f;
		m_templ_explosion_emiter.x			= 0.0f;
		m_templ_explosion_emiter.y			= 0.0f;
		m_templ_ammo_time_delayed			= 0.0f;
		m_templ_limit_amount_damage			= 0;
		//m_templ_damage					not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CGunTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CGunTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CGunTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
	bool CGunTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CActor
		if (!CActorTemplate::Load(xml)) return false;

		//³adowanie modu³u prezentacji magazynka z amunicj¹
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "gun_data"))
		{
			//flaga, czy obiekt posiada magazynek z amunicj¹
			//m_templ_use_ammo = xml.GetBool(node, "use_ammo");
			m_templ_ammo_data.setUseEquipment(xml.GetBool(node, "use_ammo"));
			//zapisujê do zmiennej nazwê pliku z konfiguracj¹ ammo
			std::string ammo_filename_tmp = xml.GetString(node, "ammo_filename");
			//emitery dla obiektu klasy Ammo
			m_templ_ammo_data.setEmiter(xml.GetFloat(node, "ammo_emiter_x"), xml.GetFloat(node, "ammo_emiter_y"));

			if (m_templ_ammo_data.getUseEquipment())
				p_templ_ammo = (CAmmoTemplate*)gResourceManager.GetPhysicalTemplate(ammo_filename_tmp);
	
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

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CGun
	CGun* CGunTemplate::Create(std::wstring id)
	{
		CGun* gun = gPhysicalManager.CreateGun(id);
		Fill(gun);
		return gun;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CGunTemplate::Fill(CGun *p_gun)
	{
		if(p_gun)
		{
			CActorTemplate::Fill(p_gun);
			
			//pola tej klasy wzorca
			p_gun->setAmmoTransformed(m_templ_ammo_data.getTransformed());
			p_gun->SetTimeAmmoLoadDelay(m_templ_time_ammo_load_delay);
			p_gun->SetTimeShot(m_templ_time_shot);
			p_gun->SetRangeShot(m_templ_range_shot);
			p_gun->SetBulletSpeed(m_templ_bullet_speed);
			p_gun->SetBarrelCount(m_templ_barrel_count);
			p_gun->SetTargetAltitude(m_templ_target_altitude);
			p_gun->SetExplosionEmiter(m_templ_explosion_emiter);
			p_gun->SetAmmoTimeDelayed(m_templ_ammo_time_delayed);
			p_gun->setLimitAmountDamage(m_templ_limit_amount_damage);
			//damage
			p_gun->setDamage(m_templ_damage);

			//decorate	
			p_gun->setSmoothing(true);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_gun)
			{
				p_gun->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetGunBodyDefaultAnim() != NULL)
					p_gun->SetAnimationBody(p_templ_animations->GetGunBodyDefaultAnim());

				//head
				if (p_templ_animations->GetGunHeadDefaultAnim() != NULL)
					p_gun->SetAnimationHead(p_templ_animations->GetGunHeadDefaultAnim());
			}

			//jeœli obiekt posiada ammo (magazynek z amunicj¹)
			if (m_templ_ammo_data.getUseEquipment())
			{
				if (p_gun)
				{
					//pobieramy sk³adow¹ ammo i wzorzec wype³nia wskaŸnik danymi
					p_gun->setAmmo(p_templ_ammo->Create(L""));
					//przekazanie wskaŸnikowi na klasê Ammo informacji o wzorcu
					p_gun->getAmmo()->SetTemplate(p_templ_ammo);
					//decorator
					p_gun->getAmmo()->setSmoothing(true);
				}
			}
		}
	}
}//namespace factory
