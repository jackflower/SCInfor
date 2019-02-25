//  ________________________________
// | Bar.cpp - class implementation |
// | Jack Flower December 2012      |
// |________________________________|
//

#include <SFML/Graphics.hpp>
#include "Bar.h"

namespace displayable
{
	RTTI_IMPL(Bar, Displayable);

	//Konstruktor domyślny
	Bar::Bar()
	:
		Displayable(), //konstruktor klasy bazowej
		m_bar_name(),
		m_value(),
		m_thickness(1.0f),
		m_vector_offset(0.0f, 0.0f)
	{
	}

	//Konstruktor kopiujący
	Bar::Bar(const Bar & BarCopy)
	:
		Displayable (BarCopy), //konstruktor kopiujący klasy bazowej
		m_bar_name (BarCopy.m_bar_name),
		m_value(BarCopy.m_value),
		m_thickness(BarCopy.m_thickness),
		m_vector_offset	(BarCopy.m_vector_offset)
	{
	}

	//Konstruktor przenoszący
	Bar::Bar(Bar && other)
	:
		Displayable(other),//konstruktor przenoszący klasy bazowej
		m_bar_name(other.m_bar_name),
		m_value(other.m_value),
		m_thickness(other.m_thickness),
		m_vector_offset(other.m_vector_offset)
	{
		// kopiujemy dane z obiektu źródłowego
		m_bar_name = other.m_animation_name;
		m_value = other.m_value;
		m_thickness = other.m_thickness;
		m_vector_offset = other.m_vector_offset;
		//zwalniamy obiekt źródłowy
		other.m_bar_name = "";
		other.m_value = 0.0f;
		other.m_thickness = 0.0f;
		other.m_vector_offset.x = 0.0f;
		other.m_vector_offset.y = 0.0f;
	}

	//Destruktor wirtualny
	Bar::~Bar()
	{
		//~Displayable
		m_bar_name = "";
		m_value = 0.0f;
		m_thickness = 0.0f;
		m_vector_offset.x = 0.0f;
		m_vector_offset.y = 0.0f;
	}

	//Przeciążony operator przypisania kopiowania
	Bar & Bar::operator=(const Bar & copy)
	{
		if (this != & copy)
		{
			m_bar_name = copy.m_bar_name;
			m_value = copy.m_value;
			m_thickness = copy.m_thickness;
			m_vector_offset = copy.m_vector_offset;
		}
		return *this;
	}

	//Przeciążony operator przypisania przenoszenia
	Bar & Bar::operator=(Bar && other)
	{
		if (this != & other)
		{
			//przepisujemy dane do składowych ze źródła
			m_bar_name = other.m_bar_name;
			m_value = other.m_value;
			m_thickness = other.m_thickness;
			m_vector_offset = other.m_vector_offset;

			//zerowanie obiektu źródłowego
			other.m_bar_name = "";
			other.m_value = 0.0f;
			other.m_thickness = 0.0f;
			other.m_vector_offset.x = 0.0f;
			other.m_vector_offset.y = 0.0f;
		}
		return *this;
	}

	//Metoda zwraca wartość zasobu obiektu
	const float Bar::getValue() const
	{
		return m_value ;
	}

	//Metoda ustawia wartość zasobu obiekty
	const void Bar::setValue(float value)
	{
		if (m_value < 0) return;
			m_value = value;
	}

	//Metoda pobiera grubość paska
	const float Bar::getThickness() const
	{
		return m_thickness;
	}

	//Metoda ustawia grubość paska
	const void Bar::setThickness(float thickness)
	{
		m_thickness = thickness;
	}

	//Metoda zwraca wektor kalibracji położenia obiektu
	sf::Vector2f & Bar::getVectorOffset()
	{
		return m_vector_offset;
	}

	//Metoda ładująca dane
	bool Bar::load(const std::string & name)
	{
		CXml xml(name, "root" );
		return load(xml);
	}

	///Metoda ładująca dane z xml
	bool Bar::load(CXml & xml)
	{
		//typ obiektu
		if (xml_node<> *node = xml.GetRootNode())
			m_bar_name = xml.GetString(node, "type");

		//pola konfiguracyjne paska energii
		if (xml_node<> *node = xml.GetChild(xml.GetRootNode(), "bar_config"))
		{
			m_thickness = xml.GetFloat(node, "bar_thickness");
			m_vector_offset.x = xml.GetFloat(node, "vector_offset_x");
			m_vector_offset.y = xml.GetFloat(node, "vector_offset_y");
			setColor
			(
				sf::Color
					(
						xml.GetInt(node, "bar_color_red"),
						xml.GetInt(node, "bar_color_green"),
						xml.GetInt(node, "bar_color_blue"),
						xml.GetInt(node, "bar_color_alpha")
					)
			);
		}
		//wszystkie podklasy sprawdzają, czy xml jest poprawny
		return true;
	}

	//Metoda rysujaca obiekt
	void Bar::draw(sf::RenderWindow *render)
	{
		if(m_can_draw == false)	//jeśli flaga nie pozwala - nie rysujemy obiektu - return
			return;

		if (m_sprite && m_value) //rendering tylko wtedy, gdy wartość zasobu jest dodatnia
								 //oraz wskaźnik jest zainicjowany
			render->draw(*m_sprite);
	}
}//namespace displayable
