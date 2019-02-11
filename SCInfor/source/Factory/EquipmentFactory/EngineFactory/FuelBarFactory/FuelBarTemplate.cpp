//  ____________________________________________
// | FuelBarTemplate.cpp - class implementation |
// | Jack Flower - November 2014                |
// |____________________________________________|
//

#include "FuelBarTemplate.h"

namespace factory
{
	RTTI_IMPL(FuelBarTemplate, IResource);

	//Konstruktor
	FuelBarTemplate::FuelBarTemplate()
	:
		IResource(),//konstruktor klasy bazowej
		m_templ_fuelbar_name(),
		m_templ_thickness(0.0f),
		m_templ_size(0.0f, 0.0f),
		m_templ_position_offset(0.0f, 0.0f)

	{
	}

	//Destruktor
	FuelBarTemplate::~FuelBarTemplate()
	{
		//IResource
		m_templ_fuelbar_name= "";
		m_templ_thickness = 0.0f;
		m_templ_size.x = 0.0f;
		m_templ_size.y = 0.0f;
		m_templ_position_offset.x = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FuelBarTemplate::getType() const
	{
		return rtti.GetNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void FuelBarTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool FuelBarTemplate::load(const std::string &name)
	{
		CXml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool FuelBarTemplate::load(CXml &xml)
	{
		//ładowanie danych configuracji paska paliwa
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

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelBar
	FuelBar* FuelBarTemplate::create(std::wstring id)
	{
		FuelBar* fuelbar = gPhysicalManager.CreateFuelBar(id);
		fill(fuelbar);
		return fuelbar;
	}

	//Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
	void FuelBarTemplate::fill(FuelBar *p_fuelbar)
	{
		if(p_fuelbar)
		{
			p_fuelbar->setFuelBarName(m_templ_fuelbar_name);
			p_fuelbar->setThickness(m_templ_thickness);
			p_fuelbar->setBarSize(m_templ_size);
			p_fuelbar->setBarPositionOffset(m_templ_position_offset);
			p_fuelbar->setColor(m_templ_color);
		}
	}
}//namespace factory
