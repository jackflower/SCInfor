//  __________________________________________________
// | CAmmoTemplateTemplate.cpp - class implementation |
// | Jack Flower June 2014                            |
// |__________________________________________________|
//

#include "CAmmoTemplate.h"
#include "../../../../Utilities/EntityTranslator/CEntityTranslator.h"

namespace factory
{

	RTTI_IMPL(CAmmoTemplate, CActorTemplate);

	//Konstruktor
	CAmmoTemplate::CAmmoTemplate(void)
	:
		CActorTemplate					(),//konstruktor klasy bazowej
		//m_templ_caliber				not edit
		m_templ_ammo_state				(EAmmoState::AMMO_DEFAULT),
		m_templ_ammo					(0),
		m_templ_ammo_capacity			(0),
		m_templ_percentage_reserve_ammo	(0.0f),
		m_templ_reserve_ammo			(0)
	{
	}

	//Destruktor wirtualny
	CAmmoTemplate::~CAmmoTemplate(void)
	{
		//CActorTemplate				not edit
		//m_templ_caliber				not edit
		m_templ_ammo_state				= EAmmoState::AMMO_DEFAULT;
		m_templ_ammo					= 0;
		m_templ_ammo_capacity			= 0;
		m_templ_percentage_reserve_ammo	= 0.0f;
		m_templ_reserve_ammo			= 0;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CAmmoTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CAmmoTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CAmmoTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml ³aduje wspólne cechy CActor
	bool CAmmoTemplate::Load(CXml &xml)
	{
		//³adowanie danych klasy bazowej CActor
		if (!CActorTemplate::Load(xml)) return false;

		//dane amunicji
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ammo_data"))
		{
			m_templ_ammo_capacity = xml.GetInt(node, "ammo_capacity");
			m_templ_ammo = xml.GetInt(node, "ammo");
			//parsowanie logiki na poziomie ³adowania danych (nadgorliwoœæ)
			if (m_templ_ammo > m_templ_ammo_capacity)
				m_templ_ammo = m_templ_ammo_capacity;
			m_templ_percentage_reserve_ammo = xml.GetFloat(node, "percentage_reserve_ammo");
			m_templ_caliber.setName(xml.GetString(node, "caliber_name"));
			m_templ_caliber.setCaliber(xml.GetFloat(node, "caliber"));
			m_templ_caliber.setCaliberType(gEntityTranslator.TranslateToCaliberEntity(xml.GetString(node, "e_caliber")));
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CAmmo
	CAmmo* CAmmoTemplate::Create(std::wstring id)
	{
		CAmmo* ammo = gPhysicalManager.CreateAmmo(id);
		Fill(ammo);
		return ammo;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CAmmoTemplate::Fill(CAmmo *p_ammo)
	{
		if(p_ammo)
		{
			CActorTemplate::Fill(p_ammo);

			p_ammo->setAmmoCapacity(m_templ_ammo_capacity);	//k o n i e c z n i e  najpierw pojemnoœæ
			p_ammo->setAmmo(m_templ_ammo);					//bo ta metoda waliduje...
			p_ammo->setPercentageReserveAmmo(m_templ_percentage_reserve_ammo);
			p_ammo->setCaliberName(m_templ_caliber.getName());
			p_ammo->setCaliber(m_templ_caliber.getCaliber());
			p_ammo->setCaliberType(m_templ_caliber.getCaliberType());
			//obliczam iloœæ amunicji w magazynku dla rezerwy
			m_templ_reserve_ammo = int(m_templ_ammo_capacity * m_templ_percentage_reserve_ammo);
			p_ammo->setReserveAmmo(m_templ_reserve_ammo);
			//decorator
			p_ammo->setSmoothing(true);
		}
	}
}//namespace factory
