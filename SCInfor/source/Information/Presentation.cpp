//  _________________________________________
// | Presentation.cpp - class implementation |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#include "Presentation.h"
#include "../Rendering/Drawable/DrawableManager.h"
#include "../Factory/InformationFactory/PresentationTemplate.h"

namespace information
{
	namespace presentation
	{
		RTTI_IMPL(Presentation, BaseInformation);

		//Chroniony konstruktor domyślny - używany wyłącznie przez InfoManager
		Presentation::Presentation(const std::wstring & uniqueId)
		:
			BaseInformation(uniqueId),//konstruktor klasy bazowej
			p_hud_static_text_front(NULL),
			p_hud_static_text_back(NULL),
			m_tranformable(),
			m_font_name(""),
			m_color_front(),
			m_color_back(),
			m_font_size(1),
			m_string(""),
			m_use_under(true),
			m_offset(0.0f, 0.0f),
			p_template(NULL)
		{
		}

		//Chroniony konstruktor kopiujący
		Presentation::Presentation(const Presentation & PresentationCopy)
		:
			BaseInformation(PresentationCopy),//konstruktor kopiujący klasy bazowej
			p_hud_static_text_front(PresentationCopy.p_hud_static_text_front),
			p_hud_static_text_back(PresentationCopy.p_hud_static_text_back),
			m_tranformable(PresentationCopy.m_tranformable),
			m_font_name(PresentationCopy.m_font_name),
			m_color_front(PresentationCopy.m_color_front),
			m_color_back(PresentationCopy.m_color_back),
			m_font_size(PresentationCopy.m_font_size),
			m_string(PresentationCopy.m_string),
			m_use_under(PresentationCopy.m_use_under),
			m_offset(PresentationCopy.m_offset),
			p_template(PresentationCopy.p_template)
		{
		}

		//Chroniony destruktor wirtualny - używany wyłącznie przez InfoManager
		Presentation::~Presentation(void)
		{
			//~BaseInformation()
			if (p_hud_static_text_front != NULL)
				gDrawableManager.destroyDrawable(p_hud_static_text_front);

			if (p_hud_static_text_back != NULL)
				gDrawableManager.destroyDrawable(p_hud_static_text_back);

			//m_tranformable
			m_font_name = "";
			//m_color_front
			//m_color_back
			//m_font_size
			m_string = "";
			m_use_under = false;
			m_offset.x = 0.0f;
			m_offset.y = 0.0f;
			p_template = NULL;
		}
		
		//Metoda zwraca kolor
		const sf::Color & Presentation::getColorFront() const
		{
			return m_color_front;
		}

		//Metoda ustawia kolor - front
		void Presentation::setColorFront(const sf::Color & color_front)
		{
			m_color_front = color_front;
			
			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->setColor(m_color_front);
		}

		//Metoda ustawia kolor - front
		void Presentation::setColorFront(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)
		{
			m_color_front.r = red;
			m_color_front.g = green;
			m_color_front.b = blue;
			m_color_front.a = alpha;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->setColor(m_color_front);
		}

		//Metoda zwraca kolor - back
		const sf::Color & Presentation::getColorBack() const
		{
			return m_color_back;
		}

		//Metoda ustawia kolor - back
		void Presentation::setColorBack(const sf::Color & color_back)
		{
			m_color_back = color_back;

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setColor(m_color_back);
			}
		}

		//Metoda ustawia kolor - back
		void Presentation::setColorBack(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)
		{
			m_color_back.r = red;
			m_color_back.g = green;
			m_color_back.b = blue;
			m_color_back.a = alpha;

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setColor(m_color_back);
			}
		}

		//Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
		void Presentation::setFont(const std::string & font)
		{
			m_font_name = font;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->setFont(font);
			
			if(m_use_under) //czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack(); //sprawdzam czy mam obiekt drawable
				if(p_hud_static_text_back) //jeśli wskaźnik został zainicjowany
					p_hud_static_text_back->setFont(font); //ustawiam czcionkę
			}
		}

		//Metoda zwraca rozmiar czcionki graficznej tekstu
		const unsigned Presentation::GetFontSize() const
		{
			return m_font_size;
		}

		//Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
		void Presentation::setFont(const std::string & font, unsigned int size)
		{
			m_font_name = font;
			m_font_size = size;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
			{
				p_hud_static_text_front->setFont(font);
				p_hud_static_text_front->setFontSize(size);
			}

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
				{
					p_hud_static_text_back->setFont(font);
					p_hud_static_text_back->setFontSize(size);
				}
			}
		}

		//Metoda ustawia rozmiar czcionki graficznej tekstu
		void Presentation::setFontSize(unsigned int size)
		{
			m_font_size = size;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->setFontSize(m_font_size);

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setFontSize(m_font_size);
			}
		}

		//Metoda zwraca łańcuch znaków
		const sf::String & Presentation::getString() const
		{
			return m_string;
		}

		//Metoda ustawia łańcuch znaków
		void Presentation::setString(const sf::String & string)
		{
			m_string = string;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->setString(m_string);

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setString(m_string);
			}
		}

		//Metoda zwraca pozycję obiektu
		const sf::Vector2f & Presentation::getPosition() const
		{
			return m_tranformable.getPosition();
		}

		//Metoda ustawia pozycję obiektu
		void Presentation::setPosition(const sf::Vector2f &position)
		{
			m_tranformable.setPosition(position);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setPosition(position);
			
			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setPosition(position.x + m_offset.x, position.y + m_offset.y);
			}
		}

		//Metoda ustawia pozycję obiektu
		void Presentation::setPosition(float x, float y)
		{
			m_tranformable.setPosition(x, y);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setPosition(x, y);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setPosition(x + m_offset.x, y + m_offset.y);
			}
		}

		//Metoda zwraca obrót obiektu
		float Presentation::getRotation() const
		{
			return m_tranformable.getRotation();
		}

		//Metoda ustawia obrót obiektu
		void Presentation::setRotation(float angle)
		{
			m_tranformable.setRotation(angle);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setRotation(angle);
			
			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setRotation(angle);
			}
		}
		
		//Metoda obraca obiekt zadany kąt
		void Presentation::rotate(float angle)
		{
			m_tranformable.rotate(angle);
			if(p_hud_static_text_front)
				p_hud_static_text_front->rotate(angle);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->rotate(angle);
			}
		}

		//Metoda zwraca wektor skali obiektu
		const sf::Vector2f & Presentation::getScale() const
		{
			return m_tranformable.getScale();
		}

		//Metoda ustawia skalę obiektu
		void Presentation::setScale(const sf::Vector2f & factors)
		{
			m_tranformable.setScale(factors);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setScale(factors);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setScale(factors);
			}
		}

		//Metoda ustawia skalę obiektu
		void Presentation::setScale(float factorX, float factorY)
		{
			m_tranformable.setScale(factorX, factorY);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setScale(factorX, factorY);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setScale(factorX, factorY);
			}
		}
	
		//Metoda skaluje obiekt
		void Presentation::scale(const sf::Vector2f & factor)
		{
			m_tranformable.scale(factor);
			if(p_hud_static_text_front)
				p_hud_static_text_front->scale(factor);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->scale(factor);
			}
		}

		//Metoda skaluje obiekt
		void Presentation::scale(float factorX, float factorY)
		{
			m_tranformable.scale(factorX, factorY);
			if(p_hud_static_text_front)
				p_hud_static_text_front->scale(factorX, factorY);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->scale(factorX, factorY);
			}
		}

		//Metoda zwraca origin obiektu
		const sf::Vector2f & Presentation::getOrigin() const
		{
			return m_tranformable.getOrigin();
		}

		//Metoda ustawia origin obiektu
		void Presentation::setOrigin(const sf::Vector2f & origin)
		{
			m_tranformable.setOrigin(origin);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setOrigin(origin);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setOrigin(origin);
			}
		}

		//Metoda ustawia origin obiektu
		void Presentation::setOrigin(float x, float y)
		{
			m_tranformable.setOrigin(x, y);
			if(p_hud_static_text_front)
				p_hud_static_text_front->setOrigin(x, y);

			if(m_use_under)//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->setOrigin(x, y);
			}
		}

		//Metoda zwraca flagę, czy obiekt posiada efekt 3D
		const bool Presentation::getUseUnder() const
		{
			return m_use_under;
		}

		//Metoda ustawia flagę, czy obiekt posiada efekt 3D
		void Presentation::setUseUnder(bool use_under)
		{
			m_use_under = use_under;
		}

		//Metoda zwraca wektor efektu 3D
		const sf::Vector2f & Presentation::getOffset() const
		{
			return m_offset;
		}

		//Metoda ustawia wektor efektu 3D
		void Presentation::setOffset(const sf::Vector2f & offset)
		{
			m_offset = offset;
		}

		//Metoda ustawia wektor efektu 3D
		void Presentation::setOffset(float x, float y)
		{
			m_offset.x = x;
			m_offset.y = y;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Presentation::update(float dt)
		{
			//
		}


		//implementajca metod private:

		//prywatna metoda sprawdza, czy trzeba utworzyć obiekt klasy HudStaticText
		void Presentation::checkHudStaticTextFront()
		{
			if (!p_hud_static_text_front)
				p_hud_static_text_front = gDrawableManager.createHudStaticText(Z_INFORMATION_FRONT);
		}

		//prywatna metoda sprawdza, czy trzeba utworzyć obiekt klasy HudStaticText
		void Presentation::checkHudStaticTextBack()
		{
			if (!p_hud_static_text_back)
				p_hud_static_text_back = gDrawableManager.createHudStaticText(Z_INFORMATION_BACK);
		}

	}//namespace presentation
}//namespace information
