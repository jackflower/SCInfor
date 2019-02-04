//  _________________________________________________
// | CInformationTemplate.cpp - class implementation |
// | Jack Flower - April 2015                        |
// |_________________________________________________|
//

#include "CInformationTemplate.h"
#include "../../Information/CInfoManager.h"
#include "../../Information/CInformation.h"
#include "../../Utilities/StringUtils/StringUtils.h"

using namespace infologic;

template<> CInformationTemplate* CSingleton<CInformationTemplate>::m_singleton = 0;

namespace factory
{
	RTTI_IMPL(CInformationTemplate, IResource);

	//Konstruktor
	CInformationTemplate::CInformationTemplate(void)
	:
		IResource						(),//konstruktor klasy bazowej
		m_templ_filename				(""),
		m_templ_type					(""),
		p_templ_digit_displayable		(NULL),
		p_templ_mask_displayable		(NULL),
		m_templ_texture_digit_name		(""),
		m_templ_texture_mask_name		(""),
		m_templ_tranformable_digit		(),
		m_templ_tranformable_mask		()
	{
	}

	//Destruktor
	CInformationTemplate::~CInformationTemplate(void)
	{
		//IResource						not edit
		m_templ_filename				= "";
		m_templ_type					= "";
		p_templ_digit_displayable		= NULL;
		p_templ_mask_displayable		= NULL;
		m_templ_texture_digit_name		= "";
		m_templ_texture_mask_name		= "";
		//m_templ_tranformable_digit	not edit
		//m_templ_tranformable_mask		not edit
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CInformationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CInformationTemplate::Drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CInformationTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CInformationTemplate::Load(CXml &xml)
	{
		//nazwa pliku xml
		m_templ_filename = xml.GetFilename();

		//typ obiektu
		if (xml_node<> *node = xml.GetRootNode())
			m_templ_type = xml.GetString(node, "type");

		//reprezentacja graficzna - tekstury
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "graphics_configuration"))
		{
			m_templ_texture_digit_name = xml.GetString(node, "texture_digit_name");
			m_templ_texture_mask_name = xml.GetString(node, "texture_mask_name");
		}

		//transformacja geometryczna
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "scale"))
		{
			m_templ_tranformable_digit.setScale(xml.GetFloat(node, "scale_digit_x"),xml.GetFloat(node, "scale_digit_y"));
			m_templ_tranformable_mask.setScale(xml.GetFloat(node, "scale_mask_x"),xml.GetFloat(node, "scale_mask_y"));
		}
		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CActor
	CInformation* CInformationTemplate::Create(std::wstring id)
	{
		CInformation* information = gInfoManager.CreateInformation(id);
		Fill(information);
		return information;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CInformationTemplate::Fill(CInformation *information)
	{
		//ustawienie kompletnego wzorca
		information->SetTemplate(this);

		//próba przekazania tekstur
		information->SetTextureDigit(m_templ_texture_digit_name);
		information->SetTextureMask(m_templ_texture_mask_name);

		//próba przekazania danych transformacji geometrycznych
		information->setTransformableDigit(m_templ_tranformable_digit);
		information->setTransformableMask(m_templ_tranformable_mask);
	}
}//namespace factory
