//  _________________________________________________
// | PresentationTemplate.cpp - class implementation |
// | Jack Flower - April 2015                        |
// |_________________________________________________|
//

#include "PresentationTemplate.h"
#include "../../Information/InfoManager.h"
#include "../../Utilities/StringUtils/StringUtils.h"
#include "../../Utilities/CharsetTools/CCharSetManager.h"

using namespace charsettools;

namespace factory
{
	RTTI_IMPL(PresentationTemplate, Resource);
	
	//Konstruktor
	PresentationTemplate::PresentationTemplate(void)
	:
		Resource{},//konstruktor klasy bazowej
		m_templ_filename{ "" },
		m_templ_type{ "" },
		m_templ_tranformable{},
		m_templ_font_name{ "" },
		m_templ_color_front{},
		m_templ_color_back{},
		m_templ_font_size{ 1 },
		m_templ_string{ "" },
		m_templ_wide_string{},
		m_templ_use_under{ false },
		m_templ_offset{ 0.0f, 0.0f }
	{
	}

	//Destruktor wirtualny
	PresentationTemplate::~PresentationTemplate(void)
	{
		//~Resource()
		m_templ_filename = "";
		m_templ_type = "";
		m_templ_tranformable;
		m_templ_font_name = "";
		m_templ_color_front;
		m_templ_color_back;
		m_templ_font_size = 0;
		m_templ_string = "";
		m_templ_wide_string = L"";
		m_templ_use_under = false;
		m_templ_offset.x = 0.0f;
		m_templ_offset.y = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PresentationTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void PresentationTemplate::drop()
	{
		delete this;
	}

	//Metoda ładująca dane
	bool PresentationTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool PresentationTemplate::load(Xml & xml)
	{
		//nazwa pliku xml
		m_templ_filename = xml.getFilename();

		//typ obiektu
		if (xml_node<> *node = xml.getRootNode())
			m_templ_type = xml.getString(node, "type");

		//reprezentacja graficzna
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "presentation_configuration"))
		{
			m_templ_font_name = xml.getString(node, "font_name");
			m_templ_color_front.r = xml.getInt(node, "color_front_r");
			m_templ_color_front.g = xml.getInt(node, "color_front_g");
			m_templ_color_front.b = xml.getInt(node, "color_front_b");
			m_templ_color_front.a = xml.getInt(node, "color_front_a");
			m_templ_color_back.r = xml.getInt(node, "color_back_r");
			m_templ_color_back.g = xml.getInt(node, "color_back_g");
			m_templ_color_back.b = xml.getInt(node, "color_back_b");
			m_templ_color_back.a = xml.getInt(node, "color_back_a");
			m_templ_font_size = xml.getInt(node, "font_size");
			m_templ_string = xml.getString(node, "string");
			m_templ_use_under = xml.getBool(node, "use_under");
			m_templ_offset.x = xml.getFloat(node, "offset_x");
			m_templ_offset.y = xml.getFloat(node, "offset_y");
		}
		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy Actor
	Presentation *PresentationTemplate::create(std::wstring id)
	{
		Presentation *presentation = gInfoManager.createPresentation(id);
		fill(presentation);
		return presentation;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void PresentationTemplate::fill(Presentation *presentation)
	{
		//ustawienie kompletnego wzorca
		presentation->setTemplate(this);
		presentation->setUseUnder(m_templ_use_under);
		presentation->setFont(m_templ_font_name);
		presentation->setColorFront(m_templ_color_front);
		presentation->setColorBack(m_templ_color_back);
		presentation->setFontSize(m_templ_font_size);
		m_templ_wide_string = gCharSetManager.ReinterpretFromUTF8(m_templ_string);
		presentation->setString(m_templ_wide_string);
		presentation->setOffset(m_templ_offset);
	}
}//namespace factory
