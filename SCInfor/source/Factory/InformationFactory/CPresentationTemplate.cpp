//  __________________________________________________
// | CPresentationTemplate.cpp - class implementation |
// | Jack Flower - April 2015                         |
// |__________________________________________________|
//

#include "CPresentationTemplate.h"
#include "../../Information/CInfoManager.h"
#include "../../Utilities/StringUtils/StringUtils.h"
#include "../../Utilities/CharsetTools/CCharSetManager.h"

using namespace charsettools;

namespace factory
{
	RTTI_IMPL(CPresentationTemplate, IResource);
	
	//Konstruktor
	CPresentationTemplate::CPresentationTemplate(void)
	:
		IResource				(),//konstruktor klasy bazowej
		m_templ_filename		(""),
		m_templ_type			(""),
		m_templ_tranformable	(),
		m_templ_font_name		(""),
		m_templ_color_front		(),
		m_templ_color_back		(),
		m_templ_font_size		(1),
		m_templ_string			(""),
		m_templ_wide_string		(),
		m_templ_use_under		(false),
		m_templ_offset			(0.0f, 0.0f)
	{
	}

	//Destruktor wirtualny
	CPresentationTemplate::~CPresentationTemplate(void)
	{
		//IResource				not edit
		m_templ_filename		= "";
		m_templ_type			= "";
		//m_templ_tranformable	not edit
		m_templ_font_name		= "";
		//m_templ_color_front	not edit
		//m_templ_color_back	not edit
		m_templ_font_size		= 0;
		m_templ_string			= "";
		m_templ_wide_string		= L"";
		m_templ_use_under		= false;
		m_templ_offset.x		= 0.0f;
		m_templ_offset.y		= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CPresentationTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CPresentationTemplate::drop()
	{
		delete this;
	}

	//Metoda ³aduj¹ca dane
	bool CPresentationTemplate::load(const std::string &name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CPresentationTemplate::load(CXml &xml)
	{
		//nazwa pliku xml
		m_templ_filename = xml.GetFilename();

		//typ obiektu
		if (xml_node<> *node = xml.GetRootNode())
			m_templ_type = xml.GetString(node, "type");

		//reprezentacja graficzna
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "presentation_configuration"))
		{
			m_templ_font_name = xml.GetString(node, "font_name");
			m_templ_color_front.r = xml.GetInt(node, "color_front_r");
			m_templ_color_front.g = xml.GetInt(node, "color_front_g");
			m_templ_color_front.b = xml.GetInt(node, "color_front_b");
			m_templ_color_front.a = xml.GetInt(node, "color_front_a");
			m_templ_color_back.r = xml.GetInt(node, "color_back_r");
			m_templ_color_back.g = xml.GetInt(node, "color_back_g");
			m_templ_color_back.b = xml.GetInt(node, "color_back_b");
			m_templ_color_back.a = xml.GetInt(node, "color_back_a");
			m_templ_font_size = xml.GetInt(node, "font_size");
			m_templ_string = xml.GetString(node, "string");
			m_templ_use_under = xml.GetBool(node, "use_under");
			m_templ_offset.x = xml.GetFloat(node, "offset_x");
			m_templ_offset.y = xml.GetFloat(node, "offset_y");
		}
		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy CActor
	CPresentation* CPresentationTemplate::create(std::wstring id)
	{
		CPresentation* presentation = gInfoManager.CreatePresentation(id);
		fill(presentation);
		return presentation;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CPresentationTemplate::fill(CPresentation *presentation)
	{
		//ustawienie kompletnego wzorca
		presentation->SetTemplate(this);
		presentation->setUseUnder(m_templ_use_under);
		presentation->SetFont(m_templ_font_name);
		presentation->setColorFront(m_templ_color_front);
		presentation->setColorBack(m_templ_color_back);
		presentation->SetFontSize(m_templ_font_size);
		m_templ_wide_string = gCharSetManager.ReinterpretFromUTF8(m_templ_string);
		presentation->SetString(m_templ_wide_string);
		presentation->setOffset(m_templ_offset);
	}
}//namespace factory
