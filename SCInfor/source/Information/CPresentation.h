//  __________________________________________
// | CPresentation.h - class definition       |
// | Jack Flower - April 2015                 |
// |__________________________________________|
//

#ifndef H_PRESENTATION_JACK
#define H_PRESENTATION_JACK

#include "IInformation.h"
#include "../Rendering/Displayable/CHudStaticText.h"

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
		///Klasa reprezentuje graficzn� reprezentacj� informacji
		///
		class CPresentation : public IInformation
		{
			RTTI_DECL;

			///
			///Deklaracja przyja�ni
			///
			friend class CInfoManager;
		
			//Aby uzyska� obiekt CPresentation, nale�y wywo�a� CInfoManager::CreatePresentation();

		protected:
			
			///
			///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CInfoManager
			///
			///@param & uniqueId - unikalny identyfikator (nadawany w CInfoManager)
			///
			CPresentation(const std::wstring& uniqueId);

			///
			///Chroniony konstruktor kopiuj�cy
			///
			///@param CPresentationCopy - parametr - obiekt klasy CPresentation
			///
			CPresentation(const CPresentation &CPresentationCopy);

			///
			///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CInfoManager
			///
			virtual ~CPresentation(void);

		public:

			///
			///Metoda zwraca kolor - front
			///
			const sf::Color& getColorFront() const;

			///
			///Metoda ustawia kolor - front
			///
			///@param &color_front - kolor - referencja na obiekt klasy sf::Color
			///
			void setColorFront(const sf::Color& color_front);

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
			const sf::Color& getColorBack() const;

			///
			///Metoda ustawia kolor - back
			///
			///@param &color_back - kolor - referencja na obiekt klasy sf::Color
			///
			void setColorBack(const sf::Color& color_back);

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
			///Metoda ustawia czcionk� graficzn� tekstu dla obiektu klasy sf::String
			///
			///@param &font - sta�a referencja na obiekt klasy std::string
			///
			void SetFont(const std::string& font);

			///
			///Metoda ustawia czcionk� graficzn� tekstu dla obiektu klasy sf::String
			///
			///@param &font - sta�a referencja na obiekt klasy std::string
			///
			///@param size - romiar czcionki
			///
			void SetFont(const std::string& font, unsigned size);
			
			///
			///Metoda zwraca rozmiar czcionki graficznej tekstu
			///
			const unsigned GetFontSize() const;

			///
			///Metoda ustawia rozmiar czcionki graficznej tekstu
			///
			///@param size - rozmiar czcionki graficznej
			///
			void SetFontSize(unsigned size);

			///
			///Metoda zwraca �a�cuch znak�w
			///
			const sf::String & GetString() const;

			///
			///Metoda ustawia �a�cuch znak�w
			///
			///@param & string - sta�a referencja na obiekt klasy std::string
			///
			void SetString(const sf::String & string);

			///
			///Metoda zwraca pozycj� obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycj� obiektu
			///
			///@param & positon - sta�a referecnaj na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f &position);

			///
			///Metoda ustawia pozycj� obiektu
			///
			///@param x - wsp�rz�dna X
			///
			///@param y - wsp�rz�dna Y
			///
			void setPosition(float x, float y);

			///
			///Metoda zwraca obr�t obiektu
			///
			float getRotation() const;

			///
			///Metoda ustawia obr�t obiektu
			///
			///@param angle - k�t obrotu
			///
			void setRotation(float angle);

			///
			///Metoda obraca obiekt zadany k�t
			///
			///@param angle - k�t obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca wektor skali obiektu
			///
			const sf::Vector2f& getScale() const;

			///
			///Metoda ustawia skal� obiektu
			///
			///@param &factors - wektor wsp�czynika skali - sta�a referncja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f& factors);

			///
			///Metoda ustawia skal� obiektu
			///
			///@param factorXt - wsp�czynnik X
			///
			///@param factorY - wsp�czynnik Y
			///
			void setScale(float factorX, float factorY);
		
			///
			///Metoda skaluje obiekt
			///
			///@param &factor - wsp�czynnik skali
			///
			void scale(const sf::Vector2f& factor);

			///
			///Metoda skaluje obiekt
			///
			///@param factorX - wsp�czynnik X
			///
			///@param factorY - wsp�czynnik Y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda zwraca origin obiektu
			///
			const sf::Vector2f& getOrigin() const;

			///
			///Metoda ustawia origin obiektu
			///
			///@param &origin - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f& origin);

			///
			///Metoda ustawia origin obiektu
			///
			///@param x - wsp�rz�dna X
			///
			///@param y - wsp�rz�dna Y
			///
			void setOrigin(float x, float y);

			///
			///Metoda zwraca flag�, czy obiekt posiada efekt 3D
			///
			const bool getUseUnder() const;

			///
			///Metoda ustawia flag�, czy obiekt posiada efekt 3D
			///
			///@param use_under - flaga, czy obiekt posiada efekt 3D
			///
			void setUseUnder(bool use_under);

			///
			///Metoda zwraca wektor efektu 3D
			///
			const sf::Vector2f &getOffset() const;

			///
			///Metoda ustawia wektor efektu 3D
			///
			///@param &offset - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void setOffset(const sf::Vector2f &offset);

			///
			///Metoda ustawia wektor efektu 3D
			///
			///@param x - wsp�rz�dna X
			///
			///@param y - wsp�rz�dna Y
			///
			void setOffset(float x, float y);

			///
			///Metoda zwraca wska�nik na obiekt klasy PresentationTemplate
			///
			inline PresentationTemplate *GetTemplate() const { return p_template; }

			///
			///Metoda ustawia wska�nik na obiekt klasy PresentationTemplate
			///
			///@param *p_template - wska�nik na obiekt klasy PresentationTemplate
			///
			inline void SetTemplate(PresentationTemplate* p_template_param) { p_template = p_template_param; }

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			CHudStaticText*			p_hud_static_text_front;	//wska�nik na obiekt klasy CHudStaticText - front
			CHudStaticText*			p_hud_static_text_back;		//wska�nik na obiekt klasy CHudStaticText - back
			sf::Transformable		m_tranformable;				//opakowanie danych do transformacji geometrycznej
			std::string				m_font_name;				//nazwa czcionki
			sf::Color				m_color_front;				//kolor front
			sf::Color				m_color_back;				//kolor back
			unsigned				m_font_size;				//rozmiar czcionki	(front and back)
			sf::String				m_string;					//�a�cych znak�w	(front = back)
			bool					m_use_under;				//flaga okre�la, czy obiekt posiada efekt 3D
			sf::Vector2f			m_offset;					//wektor dla efektu 3D
			PresentationTemplate*	p_template;				//wska�nik na wzorzec

			//prywatna metoda sprawdza, czy trzeba utworzy� obiekt klasy CHudStaticText
			void checkHudStaticTextFront();
			//prywatna metoda sprawdza, czy trzeba utworzy� obiekt klasy CHudStaticText
			void checkHudStaticTextBack();
			
		};
	}//namespace presentation
}//namespace information
#endif//H_PRESENTATION_JACK
