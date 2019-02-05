// _____________________________________________
//| CFuelBarTemplate.cpp - class implementation |
//| Jack Flower - November 2014                 |
//|_____________________________________________|
//

#include "CFuelBarTemplate.h"

namespace factory
{
	RTTI_IMPL(CFuelBarTemplate, IResource);

	//Konstruktor
	CFuelBarTemplate::CFuelBarTemplate(void)
	:
		IResource					(),//konstruktor klasy bazowej
		m_templ_fuelbar_name		(),
		m_templ_thickness			(0.0f),
		m_templ_size				(0.0f, 0.0f),
		m_templ_position_offset		(0.0f, 0.0f)

	{
	}

	//Destruktor
	CFuelBarTemplate::~CFuelBarTemplate(void)
	{
		//IResource not edit
		m_templ_fuelbar_name		= "";
		m_templ_thickness			= 0.0f;
		m_templ_size.x				= 0.0f;
		m_templ_size.y				= 0.0f;
		m_templ_position_offset.x	= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string CFuelBarTemplate::GetType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniaj¹ca zasób
	void CFuelBarTemplate::Drop()
	{
		delete this;
	}

	//Wirtualna metoda ³aduj¹ca dane
	bool CFuelBarTemplate::Load(const std::string &name)
	{
		CXml xml(name, "root");
		return Load(xml);
	}

	//Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
	bool CFuelBarTemplate::Load(CXml &xml)
	{
		//³adowanie danych configuracji paska paliwa
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "fuelbar_config"))
		{
			m_templ_fuelbar_name = xml.GetString(node, "bar_fuelbar_name");
			m_templ_thickness = xml.GetFloat(node, "bar_thickness");
			m_templ_size.x = xml.GetFloat(node, "bar_size_x");
			m_templ_size.y = xml.GetFloat(node, "bar_size_y");
			m_templ_position_offset.x = xml.GetFloat(node, "bar_position_offset_x");
			m_templ_position_offset.y = xml.GetFloat(node, "bar_position_offset_y");
			m_templ_color.r = xml.GetInt(node, "bar_color_red");
			m_templ_color.g = xml.GetInt(node, "bar_color_green");
			m_templ_color.b = xml.GetInt(node, "bar_color_blue");
			m_templ_color.a = xml.GetInt(node, "bar_color_alpha");
		}

		//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelBar
	FuelBar* CFuelBarTemplate::Create(std::wstring id)
	{
		FuelBar* fuelbar = gPhysicalManager.CreateFuelBar(id);
		Fill(fuelbar);
		return fuelbar;
	}

	//Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
	void CFuelBarTemplate::Fill(FuelBar *p_fuelbar)
	{
		if(p_fuelbar)
		{
			p_fuelbar->setFuelBarName(m_templ_fuelbar_name);
			p_fuelbar->setThickness(m_templ_thickness);
			p_fuelbar->setBarSize(m_templ_size);
			p_fuelbar->setBarPositionOffset(m_templ_position_offset);
			p_fuelbar->SetColor(m_templ_color);
		}
	}
}//namespace factory