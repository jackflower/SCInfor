//  _________________________________________
// | Presentation.h - class definition       |
// | Jack Flower - April 2015                |
// |_________________________________________|
//

#ifndef H_PRESENTATION_JACK
#define H_PRESENTATION_JACK

#include "BaseInformation.h"
#include "../Rendering/Displayable/HudStaticText.h"

namespace factory
{
	class PresentationTemplate;
}

using namespace rendering::displayable;

namespace information
{
	namespace presentation
	{
		///
		///Klasa reprezentuje graficzną reprezentację informacji
		///
		class Presentation : public BaseInformation
		{
			RTTI_DECL;

			///
			///Deklaracja przyjaźni
			///
			friend class InfoManager;
		
			//Aby uzyskać obiekt Presentation, należy wywołać InfoManager::CreatePresentation();

		protected:
			
			///
			///Chroniony konstruktor domyślny - używany wyłącznie przez InfoManager
			///
			///@param uniqueId - unikalny identyfikator (nadawany w InfoManager)
			///
			Presentation(const std::wstring & uniqueId);

			///
			///Chroniony konstruktor kopiujący
			///
			///@param PresentationCopy - parametr - obiekt klasy Presentation
			///
			Presentation(const Presentation & PresentationCopy);

			///
			///Chroniony destruktor wirtualny - używany wyłącznie przez InfoManager
			///
			virtual ~Presentation(void);

		public:

			///
			///Metoda zwraca kolor - front
			///
			const sf::Color & getColorFront() const;

			///
			///Metoda ustawia kolor - front
			///
			///@param color_front - kolor - referencja na obiekt klasy sf::Color
			///
			void setColorFront(const sf::Color & color_front);

			///
			///Metoda ustawia kolor - front
			///
			/// @param red   komponent Red (zakres [0, 255])
			///
			/// @param green komponent Green (zakres [0, 255])
			//
			/// @param blue  komponent Blue (zakres [0, 255])
			///
			/// @param alpha komponent Alpha (zakres [0, 255]) - opcjonalenie
			///
			void setColorFront(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha = 255);

			///
			///Metoda zwraca kolor - back
			///
			const sf::Color & getColorBack() const;

			///
			///Metoda ustawia kolor - back
			///
			///@param color_back - kolor - referencja na obiekt klasy sf::Color
			///
			void setColorBack(const sf::Color & color_back);

			///
			///Metoda ustawia kolor - back
			///
			/// @param red   komponent Red (zakres [0, 255])
			///
			/// @param green komponent Green (zakres [0, 255])
			//
			/// @param blue  komponent Blue (zakres [0, 255])
			///
			/// @param alpha komponent Alpha (zakres [0, 255]) - opcjonalenie
			///
			void setColorBack(sf::Uint8 red, sf::Uint8 green, sf::Uint8 blue, sf::Uint8 alpha = 255);

			///
			///Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
			///
			///@param font - stała referencja na obiekt klasy std::string
			///
			void setFont(const std::string & font);

			///
			///Metoda ustawia czcionkę graficzną tekstu dla obiektu klasy sf::String
			///
			///@param font - stała referencja na obiekt klasy std::string
			///
			///@param size - romiar czcionki
			///
			void setFont(const std::string & font, unsigned size);
			
			///
			///Metoda zwraca rozmiar czcionki graficznej tekstu
			///
			const unsigned GetFontSize() const;

			///
			///Metoda ustawia rozmiar czcionki graficznej tekstu
			///
			///@param size - rozmiar czcionki graficznej
			///
			void setFontSize(unsigned size);

			///
			///Metoda zwraca łańcuch znaków
			///
			const sf::String & getString() const;

			///
			///Metoda ustawia łańcuch znaków
			///
			///@param string - stała referencja na obiekt klasy std::string
			///
			void setString(const sf::String & string);

			///
			///Metoda zwraca pozycję obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param positon - stała referecnaj na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & position);

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param x - współrzędna X
			///
			///@param y - współrzędna Y
			///
			void setPosition(float x, float y);

			///
			///Metoda zwraca obrót obiektu
			///
			float getRotation() const;

			///
			///Metoda ustawia obrót obiektu
			///
			///@param angle - kąt obrotu
			///
			void setRotation(float angle);

			///
			///Metoda obraca obiekt zadany kąt
			///
			///@param angle - kąt obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca wektor skali obiektu
			///
			const sf::Vector2f & getScale() const;

			///
			///Metoda ustawia skalę obiektu
			///
			///@param factors - wektor współczynika skali - stała referncja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & factors);

			///
			///Metoda ustawia skalę obiektu
			///
			///@param factorX - współczynnik X
			///
			///@param factorY - współczynnik Y
			///
			void setScale(float factorX, float factorY);
		
			///
			///Metoda skaluje obiekt
			///
			///@param factor - współczynnik skali
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda skaluje obiekt
			///
			///@param factorX - współczynnik X
			///
			///@param factorY - współczynnik Y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda zwraca origin obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia origin obiektu
			///
			///@param origin - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda ustawia origin obiektu
			///
			///@param x - współrzędna X
			///
			///@param y - współrzędna Y
			///
			void setOrigin(float x, float y);

			///
			///Metoda zwraca flagę, czy obiekt posiada efekt 3D
			///
			const bool getUseUnder() const;

			///
			///Metoda ustawia flagę, czy obiekt posiada efekt 3D
			///
			///@param use_under - flaga, czy obiekt posiada efekt 3D
			///
			void setUseUnder(bool use_under);

			///
			///Metoda zwraca wektor efektu 3D
			///
			const sf::Vector2f & getOffset() const;

			///
			///Metoda ustawia wektor efektu 3D
			///
			///@param offset - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOffset(const sf::Vector2f & offset);

			///
			///Metoda ustawia wektor efektu 3D
			///
			///@param x - współrzędna X
			///
			///@param y - współrzędna Y
			///
			void setOffset(float x, float y);

			///
			///Metoda zwraca wskaźnik na obiekt klasy PresentationTemplate
			///
			inline PresentationTemplate *getTemplate() const
			{
				return p_template;
			}

			///
			///Metoda ustawia wskaźnik na obiekt klasy PresentationTemplate
			///
			///@param *p_template - wskaźnik na obiekt klasy PresentationTemplate
			///
			inline void setTemplate(PresentationTemplate* p_template_param)
			{
				p_template = p_template_param;
			}

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			HudStaticText *p_hud_static_text_front;	//wskaźnik na obiekt klasy HudStaticText - front
			HudStaticText *p_hud_static_text_back; //wskaźnik na obiekt klasy HudStaticText - back
			sf::Transformable m_tranformable; //opakowanie danych do transformacji geometrycznej
			std::string m_font_name; //nazwa czcionki
			sf::Color m_color_front; //kolor front
			sf::Color m_color_back; //kolor back
			unsigned m_font_size; //rozmiar czcionki	(front and back)
			sf::String m_string; //łańcych znaków (front = back)
			bool m_use_under; //flaga określa, czy obiekt posiada efekt 3D
			sf::Vector2f m_offset; //wektor dla efektu 3D
			PresentationTemplate *p_template; //wskaźnik na wzorzec

			//prywatna metoda sprawdza, czy trzeba utworzyć obiekt klasy HudStaticText
			void checkHudStaticTextFront();
			//prywatna metoda sprawdza, czy trzeba utworzyć obiekt klasy HudStaticText
			void checkHudStaticTextBack();
			
		};
	}//namespace presentation
}//namespace information
#endif//H_PRESENTATION_JACK
