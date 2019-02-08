//  _________________________________________
// | AmmoTemplate.cpp - class implementation |
// | Jack Flower June 2014                   |
// |_________________________________________|
//

#include "AmmoTemplate.h"
#include "../../../../Utilities/EntityTranslator/CEntityTranslator.h"

namespace factory
{

	RTTI_IMPL(AmmoTemplate, ActorTemplate);

	//Konstruktor
	AmmoTemplate::AmmoTemplate(void)
	:
		ActorTemplate(),//konstruktor klasy bazowej
		m_templ_caliber(),
		m_templ_ammo_state(EAmmoState::AMMO_DEFAULT),
		m_templ_ammo(0),
		m_templ_ammo_capacity(0),
		m_templ_percentage_reserve_ammo(0.0f),
		m_templ_reserve_ammo(0)
	{
	}

	//Destruktor wirtualny
	AmmoTemplate::~AmmoTemplate(void)
	{
		//ActorTemplate
		//m_templ_caliber
		m_templ_ammo_state = EAmmoState::AMMO_DEFAULT;
		m_templ_ammo = 0;
		m_templ_ammo_capacity = 0;
		m_templ_percentage_reserve_ammo	= 0.0f;
		m_templ_reserve_ammo = 0;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string AmmoTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void AmmoTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool AmmoTemplate::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml ładuje wspólne cechy CActor
	bool AmmoTemplate::load(CXml & xml)
	{
		//ładowanie danych klasy bazowej CActor
		if (!ActorTemplate::load(xml)) return false;

		//dane amunicji
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "ammo_data"))
		{
			m_templ_ammo_capacity = xml.GetInt(node, "ammo_capacity");
			m_templ_ammo = xml.GetInt(node, "ammo");
			//parsowanie logiki na poziomie ładowania danych (nadgorliwość)
			if (m_templ_ammo > m_templ_ammo_capacity)
				m_templ_ammo = m_templ_ammo_capacity;
			m_templ_percentage_reserve_ammo = xml.GetFloat(node, "percentage_reserve_ammo");
			m_templ_caliber.setName(xml.GetString(node, "caliber_name"));
			m_templ_caliber.setCaliber(xml.GetFloat(node, "caliber"));
			m_templ_caliber.setCaliberType(gEntityTranslator.TranslateToCaliberEntity(xml.GetString(node, "e_caliber")));
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Ammo
	Ammo* AmmoTemplate::create(std::wstring id)
	{
		Ammo* ammo = gPhysicalManager.CreateAmmo(id);
		fill(ammo);
		return ammo;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void AmmoTemplate::fill(Ammo *p_ammo)
	{
		if(p_ammo)
		{
			ActorTemplate::fill(p_ammo);

			p_ammo->setAmmoCapacity(m_templ_ammo_capacity);	//k o n i e c z n i e  najpierw pojemność
			p_ammo->setAmmo(m_templ_ammo); //bo ta metoda waliduje...
			p_ammo->setPercentageReserveAmmo(m_templ_percentage_reserve_ammo);
			p_ammo->setCaliberName(m_templ_caliber.getName());
			p_ammo->setCaliber(m_templ_caliber.getCaliber());
			p_ammo->setCaliberType(m_templ_caliber.getCaliberType());
			//obliczam ilość amunicji w magazynku dla rezerwy
			m_templ_reserve_ammo = int(m_templ_ammo_capacity * m_templ_percentage_reserve_ammo);
			p_ammo->setReserveAmmo(m_templ_reserve_ammo);
			//decorator
			p_ammo->setSmoothing(true);
		}
	}
}//namespace factory
