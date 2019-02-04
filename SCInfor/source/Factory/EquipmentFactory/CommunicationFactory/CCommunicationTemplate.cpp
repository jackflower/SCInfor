//  ___________________________________________
// | CCommunication.cpp - class implementation |
// | Jack Flower - July 2015                   |
// |___________________________________________|
//

#include "CCommunicationTemplate.h"
#include "../../../Rendering/Animations/CAnimSet.h"
#include "../../../ResourceManager/CResourceManager.h"

using namespace resource;

namespace factory
{
	RTTI_IMPL(CCommunicationTemplate, CActorTemplate);

	//Konstruktor
	CCommunicationTemplate::CCommunicationTemplate()
	:
		CActorTemplate				(),//konstruktor klasy bazowej
		m_templ_communication_name	(),
		m_templ_range				(0.0f),
		m_templ_reset_duration		(0.0f),
		m_templ_login				(),
		m_templ_password			()
	{
	}

	//Destruktor wirtualny
	CCommunicationTemplate::~CCommunicationTemplate()
	{
		//CActorTemplate	not edit
		m_templ_communication_name	= "";
		m_templ_range				= 0.0f;
		m_templ_reset_duration		= 0.0f;
		m_templ_login				= "";
		m_templ_password			= "";
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CCommunicationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób - implementacje w klasach pochodnych
	void CCommunicationTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CCommunicationTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root" );
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml
	bool CCommunicationTemplate::Load(CXml &xml)
	{
		//sprawdzamy, czy mo¿na za³adowaæ dane z klasy bazowej CActorTemplate
		if (!CActorTemplate::Load(xml)) return false;

		//dane obiektu
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "communication_config"))
		{
			m_templ_communication_name = xml.GetString(node, "communication_name");
			m_templ_range = xml.GetFloat(node,"range");
			m_templ_reset_duration = xml.GetFloat(node, "reset_duration");
			m_templ_login = xml.GetString(node, "login");
			m_templ_password = xml.GetString(node, "password");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CPowerStation
	CCommunication* CCommunicationTemplate::Create(std::wstring id)
	{
		CCommunication* communication = gPhysicalManager.CreateCommunication(id);
		Fill(communication);
		return communication;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CCommunicationTemplate::Fill(CCommunication *p_communication)
	{
		if(p_communication)
		{
			CActorTemplate::Fill(p_communication);

			//przekazanie zestawu animacji do obiektu, który jest wype³niany danymi wzorca
			if (p_templ_animations)
			{
				p_communication->SetAnimSet(p_templ_animations);

				//body
				if (p_templ_animations->GetCommunicationBodyDefaultAnim() != NULL)
					p_communication->SetAnimationBody(p_templ_animations->GetCommunicationBodyDefaultAnim());

				//head
				if (p_templ_animations->GetCommunicationHeadDefaultAnim() != NULL)
					p_communication->SetAnimationHead(p_templ_animations->GetCommunicationHeadDefaultAnim());
			}

			//pola tej klasy wzorca
			p_communication->SetCommunicationName(m_templ_communication_name);
			p_communication->setRange(m_templ_range);
			p_communication->setResetDuration(m_templ_reset_duration);
			p_communication->getLoginModule().setLogin(m_templ_login);
			p_communication->getLoginModule().setPassword(m_templ_password);
			//decorate
			p_communication->setSmoothing(true);
		}
	}
}//namespace factory
