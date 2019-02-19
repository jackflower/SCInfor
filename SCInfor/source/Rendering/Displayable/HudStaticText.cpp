//  __________________________________________
// | HudStaticText.cpp - class implementation |
// | Jack Flower October 2012                 |
// |__________________________________________|
//

#include "HudStaticText.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace rendering::drawable;

namespace rendering
{
	namespace displayable
	{
		RTTI_IMPL(HudStaticText, IDrawable);

		//Konstruktor
		HudStaticText::HudStaticText()
		:
			IDrawable(),//konstruktor klasy bazowej
			p_text(NULL),
			m_color(),
			p_font(NULL),
			m_font_size(1),
			m_string(),
			m_tranformable()
		{
			p_text = new sf::Text();
		}

		//Destruktor wirtualny
		HudStaticText::~HudStaticText()
		{
			delete p_text;
			p_text = NULL;
			//m_color
			//p_font
			m_font_size = 0;
			m_string = "";
			//m_tranformable
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string HudStaticText::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca wskaźnik na obiekt klasy sf::Text
		const sf::Text *HudStaticText::getText() const
		{
			return p_text;
		}

		//Metoda zwraca kolor
		const sf::Color & HudStaticText::getColor() const
		{
			return m_color;
		}

		//Metoda ustawia kolor
		void HudStaticText::setColor(const sf::Color & color)
		{
			m_color = color;
			p_text->setFillColor(color);
		}

		//Metoda ustawia kolor
		void HudStaticText::setColor(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)
		{
			m_color.r = red;
			m_color.g = green;
			m_color.b = blue;
			m_color.a = alpha;
			p_text->setFillColor(m_color);
		}

		//Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
		void HudStaticText::setFont(const std::string & font)
		{
			p_font = gResourceManager.GetFont(font);
			p_text->setFont(*p_font);
		}

		//Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
		void HudStaticText::setFont(const std::string & font, unsigned int size)
		{
			p_font = gResourceManager.GetFont(font);
			p_text->setFont(*p_font);
			if (m_font_size != size)//nie ma sensu kopiowanie danych, gdy są takie same
				p_text->setCharacterSize(m_font_size);
		}

		//Metoda ustawia rozmiar czcionki graficznej tekstu
		void HudStaticText::setFontSize(unsigned int size)
		{
			if (m_font_size != size)//nie ma sensu kopiowanie danych, gdy są takie same
			{
				m_font_size = size;
				p_text->setCharacterSize(m_font_size);
			}
		}

		//Metoda ustawia łańcuch znaków
		void HudStaticText::setString(const sf::String & string)
		{
			if (m_string != string)//nie ma sensu kopiowanie danych, gdy są takie same
			{
				m_string = string;
				p_text->setString(m_string);
			}
		}

		//Metoda zwraca pozycję obiektu
		const sf::Vector2f & HudStaticText::getPosition() const
		{
			return m_tranformable.getPosition();
		}
			
		//Metoda ustawia pozycję obiektu
		void HudStaticText::setPosition(const sf::Vector2f & position)
		{
			m_tranformable.setPosition(position);
			if(p_text)
				p_text->setPosition(position);
		}

		//Metoda ustawia pozycję obiektu
		void HudStaticText::setPosition(float x, float y)
		{
			m_tranformable.setPosition(x, y);
			if(p_text)
				p_text->setPosition(x, y);
		}
		
		//Metoda zwraca obrót obiektu
		float HudStaticText::getRotation() const
		{
			return m_tranformable.getRotation();
		}

		//Metoda ustawia obrót obiektu
		void HudStaticText::setRotation(float angle)
		{
			m_tranformable.setRotation(angle);
			if(p_text)
				p_text->setRotation(angle);
		}
		
		//Metoda obraca obiekt zadany kąt
		void HudStaticText::rotate(float angle)
		{
			m_tranformable.rotate(angle);
			if(p_text)
				p_text->rotate(angle);
		}

		//Metoda zwraca wektor skali obiektu
		const sf::Vector2f & HudStaticText::getScale() const
		{
			return m_tranformable.getScale();
		}

		//Metoda ustawia skalę obiektu
		void HudStaticText::setScale(const sf::Vector2f & factors)
		{
			m_tranformable.setScale(factors);
			if(p_text)
				p_text->setScale(factors);
		}

		//Metoda ustawia skalę obiektu
		void HudStaticText::setScale(float factorX, float factorY)
		{
			m_tranformable.setScale(factorX, factorY);
			if(p_text)
				p_text->setScale(factorX, factorY);
		}
	
		//Metoda skaluje obiekt
		void HudStaticText::scale(const sf::Vector2f & factor)
		{
			m_tranformable.scale(factor);
			if(p_text)
				p_text->scale(factor);
		}

		//Metoda skaluje obiekt
		void HudStaticText::scale(float factorX, float factorY)
		{
			m_tranformable.scale(factorX, factorY);
			if(p_text)
				p_text->scale(factorX, factorY);
		}

		//Metoda zwraca origin obiektu
		const sf::Vector2f & HudStaticText::getOrigin() const
		{
			return m_tranformable.getOrigin();
		}

		//Metoda ustawia origin obiektu
		void HudStaticText::setOrigin(const sf::Vector2f & origin)
		{
			m_tranformable.setOrigin(origin);
			if(p_text)
				p_text->setOrigin(origin);
		}

		//Metoda ustawia origin obiektu
		void HudStaticText::setOrigin(float x, float y)
		{
			m_tranformable.setOrigin(x, y);
			if(p_text)
				p_text->setOrigin(x, y);
		}

		//Wirtualna metoda renderująca obiekt klasy HudStaticText
		void HudStaticText::draw( sf::RenderWindow *renderWindow )
		{
			if(m_can_draw == false)	return;	//jeśli flaga nie pozwala - nie rysujemy obiektu - return
			
			//future...
			//obiekt (ang. Head-Up Display)
			//jego transformacja - względem kamer
			//zoom, position, center, defauit view, etc...
			renderWindow->draw(*p_text);
		}
	} //namespace displayable
}//namespace rendering
