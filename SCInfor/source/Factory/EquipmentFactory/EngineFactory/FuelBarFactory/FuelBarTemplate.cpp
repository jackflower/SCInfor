//  ____________________________________________
// | FuelBarTemplate.cpp - class implementation |
// | Jack Flower - November 2014                |
// |____________________________________________|
//

#include "FuelBarTemplate.h"

namespace factory
{
	RTTI_IMPL(FuelBarTemplate, Resource);

	//Konstruktor
	FuelBarTemplate::FuelBarTemplate()
	:
		Resource{},//konstruktor klasy bazowej
		m_templ_fuelbar_name{},
		m_templ_thickness{ 0.0f },
		m_templ_size{ 0.0f, 0.0f },
		m_templ_position_offset{ 0.0f, 0.0f }
	{
	}

	//Destruktor
	FuelBarTemplate::~FuelBarTemplate()
	{
		//~Resource()
		m_templ_fuelbar_name = "";
		m_templ_thickness = 0.0f;
		m_templ_size.x = 0.0f;
		m_templ_size.y = 0.0f;
		m_templ_position_offset.x = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string FuelBarTemplate::getType() const
	{
		return rtti.getNameClass();
	}

	//Wirtualna metoda zwalniająca zasób
	void FuelBarTemplate::drop()
	{
		delete this;
	}

	//Wirtualna metoda ładująca dane
	bool FuelBarTemplate::load(const std::string & name)
	{
		Xml xml(name, "root");
		return load(xml);
	}

	//Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
	bool FuelBarTemplate::load(Xml & xml)
	{
		//ładowanie danych configuracji paska paliwa
		if (xml_node<> *node = xml.getChild(xml.getRootNode(), "fuelbar_config"))
		{
			m_templ_fuelbar_name = xml.getString(node, "bar_fuelbar_name");
			m_templ_thickness = xml.getFloat(node, "bar_thickness");
			m_templ_size.x = xml.getFloat(node, "bar_size_x");
			m_templ_size.y = xml.getFloat(node, "bar_size_y");
			m_templ_position_offset.x = xml.getFloat(node, "bar_position_offset_x");
			m_templ_position_offset.y = xml.getFloat(node, "bar_position_offset_y");
			m_templ_color.r = xml.getInt(node, "bar_color_red");
			m_templ_color.g = xml.getInt(node, "bar_color_green");
			m_templ_color.b = xml.getInt(node, "bar_color_blue");
			m_templ_color.a = xml.getInt(node, "bar_color_alpha");
		}

		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda tworzy obiekt klasy FuelBar
	FuelBar* FuelBarTemplate::create(std::wstring id)
	{
		FuelBar *fuelbar = gPhysicalManager.createFuelBar(id);
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
