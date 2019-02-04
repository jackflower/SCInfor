//  _________________________________
// | CBar.cpp - class implementation |
// | Jack Flower December 2012       |
// |_________________________________|
//

#include <SFML/Graphics.hpp>
#include "CBar.h"

namespace displayable
{
	RTTI_IMPL(CBar, CDisplayable);

	//Konstruktor domyœlny
	CBar::CBar()
	:
		CDisplayable	(),					//konstruktor klasy bazowej
		m_bar_name		(),
		m_value			(),
		m_thickness		(1.0f),
		m_vector_offset	(0.0f, 0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CBar::CBar(const CBar& CBarCopy)
	:
		CDisplayable	(CBarCopy),			//konstruktor kopiuj¹cy klasy bazowej
		m_bar_name		(CBarCopy.m_bar_name),
		m_value			(CBarCopy.m_value),
		m_thickness		(CBarCopy.m_thickness),
		m_vector_offset	(CBarCopy.m_vector_offset)
	{
	}

	//Destruktor wirtualny
	CBar::~CBar()
	{
		m_bar_name		= "";
		m_value			= 0.0f;
		m_thickness		= 0.0f;
	}

	//Metoda zwraca wartoœæ zasobu obiektu
	const float CBar::GetValue() const
	{
		return m_value ;
	}

	//Metoda ustawia wartoœæ zasobu obiekty
	const void CBar::SetValue(float value)
	{
		if (m_value < 0) return;
			m_value = value;
	}

	//Metoda pobiera gruboœæ paska
	const float CBar::GetThickness() const
	{
		return m_thickness;
	}

	//Metoda ustawia gruboœæ paska
	const void CBar::SetThickness(float thickness)
	{
		m_thickness = thickness;
	}

	//Metoda zwraca wektor kalibracji po³o¿enia obiektu
	sf::Vector2f& CBar::GetVectorOffset()
	{
		return m_vector_offset;
	}

	////Metoda ³aduje dane
	//const void CBar::LoadData(const std::string &name)
	//{
	//	SBar* p_bar = gTemplateManagerWork.GetBarStructure(name);
	//	
	//	m_bar_name					= p_bar->s_bar_name;
	//	m_thickness					= p_bar->s_bar_thickness;
	//	m_vector_offset.x			= p_bar->s_vector_offset_x;
	//	m_vector_offset.y			= p_bar->s_vector_offset_y;
	//	SetColor
	//		(
	//			sf::Color
	//				(
	//					p_bar->s_bar_color_red,
	//					p_bar->s_bar_color_green,
	//					p_bar->s_bar_color_blue,
	//					p_bar->s_bar_color_alpha
	//				)
	//		);
	//}


	////Metoda ³aduj¹ca dane
	//bool CBar::Load(const std::string &name)
	//{
	//	CXml xml(name, "root" );
	//	return Load(xml);
	//}

	/////Metoda ³aduj¹ca dane z xml
	//bool CBar::Load(CXml &xml)
	//{
	//	//typ obiektu
	//	if (xml_node<> *node = xml.GetRootNode())
	//		m_bar_name = xml.GetString(node, "type");

	//	//pola konfiguracyjne paska energii
	//	if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "bar_config"))
	//	{
	//		m_thickness = xml.GetFloat(node, "bar_thickness");
	//		m_vector_offset.x = xml.GetFloat(node, "vector_offset_x");
	//		m_vector_offset.y = xml.GetFloat(node, "vector_offset_y");
	//		SetColor
	//		(
	//			sf::Color
	//				(
	//					xml.GetInt(node, "bar_color_red"),
	//					xml.GetInt(node, "bar_color_green"),
	//					xml.GetInt(node, "bar_color_blue"),
	//					xml.GetInt(node, "bar_color_alpha")
	//				)
	//		);
	//	}
	//	//wszystkie podklasy sprawdzaj¹, czy xml jest poprawny
	//	return true;
	//}

	//Metoda rysujaca obiekt
	void CBar::Draw(sf::RenderWindow* render)
	{
		if(m_can_draw == false)		//jeœli flaga nie pozwala - nie rysujemy obiektu - return
			return;

		if (m_sprite && m_value)	//rendering tylko wtedy, gdy wartoœæ zasobu jest dodatnia
									//oraz wskaŸnik jest zainicjowany
			render->draw(*m_sprite);
	}
}//namespace displayable
