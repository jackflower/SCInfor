//  __________________________________________
// | CPresentation.cpp - class implementation |
// | Jack Flower - April 2015                 |
// |__________________________________________|
//

#include "CPresentation.h"
#include "../Rendering/Drawable/CDrawableManager.h"
#include "../Factory/InformationFactory/PresentationTemplate.h"

namespace information
{
	namespace presentation
	{
		RTTI_IMPL(CPresentation, IInformation);

		//Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CInfoManager
		CPresentation::CPresentation(const std::wstring& uniqueId)
		:
			IInformation			(uniqueId),//konstruktor klasy bazowej
			p_hud_static_text_front	(NULL),
			p_hud_static_text_back	(NULL),
			m_tranformable			(),
			m_font_name				(""),
			m_color_front			(),
			m_color_back			(),
			m_font_size				(1),
			m_string				(""),
			m_use_under				(true),
			m_offset				(0.0f, 0.0f),
			p_template				(NULL)
		{
		}

		//Chroniony konstruktor kopiuj¹cy
		CPresentation::CPresentation(const CPresentation &CPresentationCopy)
		:
			IInformation			(CPresentationCopy),//konstruktor kopiuj¹cy klasy bazowej
			p_hud_static_text_front	(CPresentationCopy.p_hud_static_text_front),
			p_hud_static_text_back	(CPresentationCopy.p_hud_static_text_back),
			m_tranformable			(CPresentationCopy.m_tranformable),
			m_font_name				(CPresentationCopy.m_font_name),
			m_color_front			(CPresentationCopy.m_color_front),
			m_color_back			(CPresentationCopy.m_color_back),
			m_font_size				(CPresentationCopy.m_font_size),
			m_string				(CPresentationCopy.m_string),
			m_use_under				(CPresentationCopy.m_use_under),
			m_offset				(CPresentationCopy.m_offset),
			p_template				(CPresentationCopy.p_template)
		{
		}

		//Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CInfoManager
		CPresentation::~CPresentation(void)
		{
			if (p_hud_static_text_front != NULL)
				gDrawableManager.DestroyDrawable(p_hud_static_text_front);

			if (p_hud_static_text_back != NULL)
				gDrawableManager.DestroyDrawable(p_hud_static_text_back);

			//sf::Transformable		not edit
			m_font_name				= "";
			//sf::Color				not edit
			//sf::Color				not edit
			//unsigned				not edit
			m_string				= "";
			m_use_under				= false;
			m_offset.x				= 0.0f;
			m_offset.y				= 0.0f;
			p_template				= NULL;
		}
		
		//Metoda zwraca kolor
		const sf::Color& CPresentation::getColorFront() const
		{
			return m_color_front;
		}

		//Metoda ustawia kolor - front
		void CPresentation::setColorFront(const sf::Color& color_front)
		{
			m_color_front = color_front;
			
			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->setColor(m_color_front);
		}

		//Metoda ustawia kolor - front
		void CPresentation::setColorFront(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)
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
		const sf::Color& CPresentation::getColorBack() const
		{
			return m_color_back;
		}

		//Metoda ustawia kolor - back
		void CPresentation::setColorBack(const sf::Color& color_back)
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
		void CPresentation::setColorBack(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha)
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

		//Metoda ustawia czcionkê graficzn¹ tekstu dla obiektu klasy sf::String
		void CPresentation::SetFont(const std::string& font)
		{
			m_font_name = font;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->SetFont(font);
			
			if(m_use_under)									//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();					//sprawdzam czy mam obiekt drawable
				if(p_hud_static_text_back)					//jeœli wskaŸnik zosta³ zainicjowany
					p_hud_static_text_back->SetFont(font);	//ustawiam czcionkê
			}
		}

		//Metoda zwraca rozmiar czcionki graficznej tekstu
		const unsigned CPresentation::GetFontSize() const
		{
			return m_font_size;
		}

		//Metoda ustawia czcionkê graficzn¹ tekstu dla obiektu klasy sf::String
		void CPresentation::SetFont(const std::string &font, unsigned int size)
		{
			m_font_name = font;
			m_font_size = size;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
			{
				p_hud_static_text_front->SetFont(font);
				p_hud_static_text_front->SetFontSize(size);
			}

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
				{
					p_hud_static_text_back->SetFont(font);
					p_hud_static_text_back->SetFontSize(size);
				}
			}
		}

		//Metoda ustawia rozmiar czcionki graficznej tekstu
		void CPresentation::SetFontSize(unsigned int size)
		{
			m_font_size = size;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->SetFontSize(m_font_size);

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->SetFontSize(m_font_size);
			}
		}

		//Metoda zwraca ³añcuch znaków
		const sf::String & CPresentation::GetString() const
		{
			return m_string;
		}

		//Metoda ustawia ³añcuch znaków
		void CPresentation::SetString(const sf::String & string)
		{
			m_string = string;

			checkHudStaticTextFront();
			if(p_hud_static_text_front)
				p_hud_static_text_front->SetString(m_string);

			if(m_use_under)	//czy obiekt ma efekt 3D
			{
				checkHudStaticTextBack();
				if(p_hud_static_text_back)
					p_hud_static_text_back->SetString(m_string);
			}
		}

		//Metoda zwraca pozycjê obiektu
		const sf::Vector2f & CPresentation::getPosition() const
		{
			return m_tranformable.getPosition();
		}

		//Metoda ustawia pozycjê obiektu
		void CPresentation::setPosition(const sf::Vector2f &position)
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

		//Metoda ustawia pozycjê obiektu
		void CPresentation::setPosition(float x, float y)
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
		float CPresentation::getRotation() const
		{
			return m_tranformable.getRotation();
		}

		//Metoda ustawia obrót obiektu
		void CPresentation::setRotation(float angle)
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
		
		//Metoda obraca obiekt zadany k¹t
		void CPresentation::rotate(float angle)
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
		const sf::Vector2f& CPresentation::getScale() const
		{
			return m_tranformable.getScale();
		}

		//Metoda ustawia skalê obiektu
		void CPresentation::setScale(const sf::Vector2f& factors)
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

		//Metoda ustawia skalê obiektu
		void CPresentation::setScale(float factorX, float factorY)
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
		void CPresentation::scale(const sf::Vector2f& factor)
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
		void CPresentation::scale(float factorX, float factorY)
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
		const sf::Vector2f& CPresentation::getOrigin() const
		{
			return m_tranformable.getOrigin();
		}

		//Metoda ustawia origin obiektu
		void CPresentation::setOrigin(const sf::Vector2f& origin)
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
		void CPresentation::setOrigin(float x, float y)
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

		//Metoda zwraca flagê, czy obiekt posiada efekt 3D
		const bool CPresentation::getUseUnder() const
		{
			return m_use_under;
		}

		//Metoda ustawia flagê, czy obiekt posiada efekt 3D
		void CPresentation::setUseUnder(bool use_under)
		{
			m_use_under = use_under;
		}

		//Metoda zwraca wektor efektu 3D
		const sf::Vector2f &CPresentation::getOffset() const
		{
			return m_offset;
		}

		//Metoda ustawia wektor efektu 3D
		void CPresentation::setOffset(const sf::Vector2f &offset)
		{
			m_offset = offset;
		}

		//Metoda ustawia wektor efektu 3D
		void CPresentation::setOffset(float x, float y)
		{
			m_offset.x = x;
			m_offset.y = y;
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void CPresentation::update(float dt)
		{
			//
		}


		//implementajca metod private:

		//prywatna metoda sprawdza, czy trzeba utworzyæ obiekt klasy CHudStaticText
		void CPresentation::checkHudStaticTextFront()
		{
			if (!p_hud_static_text_front)
				p_hud_static_text_front = gDrawableManager.CreateHudStaticText(Z_INFORMATION_FRONT);
		}

		//prywatna metoda sprawdza, czy trzeba utworzyæ obiekt klasy CHudStaticText
		void CPresentation::checkHudStaticTextBack()
		{
			if (!p_hud_static_text_back)
				p_hud_static_text_back = gDrawableManager.CreateHudStaticText(Z_INFORMATION_BACK);
		}

	}//namespace presentation
}//namespace information
