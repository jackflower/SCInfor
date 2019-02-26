//  _________________________________________________
// | InformationTemplate.h - class definition        |
// | Jack Flower - April 2015                        |
// |_________________________________________________|
//

#ifndef H_PRESENTATION_TEMPLATE_JACK
#define H_PRESENTATION_TEMPLATE_JACK

#include "../../ResourceManager/Resource.h"
#include "../../Information/Presentation.h"
#include "../../XML/Xml.h"
#include "../../RTTI/RTTI.h"
#include <string>

using namespace resource;
using namespace xml;
using namespace information::presentation;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec dla obiektu klasy Presentation
	///
	class PresentationTemplate : public Resource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PresentationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~PresentationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		virtual void drop();

		///
		///Metoda ładująca dane
		///
		///@param name - stała referencja na std::string
		///
		bool load(const std::string & name);

		///
		///Wirtualna metoda ładująca dane z xml wywoływana przez implementacje klas potomnych
		///
		///@param xml - referencja na obiekt klasy Xml
		///
		virtual bool load(Xml & xml);

		///
		///Wirtualna metoda tworzenie obiektów pochodnych klasy Presentation
		///
		///implementowana przez w pełni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual Presentation *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *information - wskaźnik na obiekt klasy Information
		///
		virtual void fill(Presentation *presentation);

		///
		///Metoda zwraca nazwę pliku zasobu
		///
		inline const std::string & getFilename() const
		{
			return m_templ_filename;
		}

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
		///
		inline const std::string & getTypeName() const
		{
			return m_templ_type;
		}

		///
		///Metoda zwraca referencję na obiekt klasy sf::Transformable
		///
		inline const sf::Transformable getTransformable() const
		{
			return m_templ_tranformable;
		}
		
		///
		///Metoda ustawia referencję na obiekt klasy sf::Transformable
		///
		///@param templ_tranformable - stała referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformable(const sf::Transformable & templ_tranformable)
		{
			m_templ_tranformable = templ_tranformable;
		}

		///
		///Metoda zaraca stałą referencję na obiekt klasy sf::Color - front
		///
		inline const sf::Color & getColorFront() const
		{
			return m_templ_color_front;
		}

		///
		///Metoda ustawia kolor obiektu - front
		///
		///
		///@param color_front - stała referencja na obiekt klasy sf::Color
		///
		inline void setColorFront(const sf::Color & color_front)
		{
			m_templ_color_front = color_front;
		}

		///
		///Metoda zaraca stałą referencję na obiekt klasy sf::Color - back
		///
		inline const sf::Color & getColorBack() const
		{
			return m_templ_color_back;
		}

		///
		///Metoda ustawia kolor obiektu - back
		///
		///@param color_back - stała referencja na obiekt klasy sf::Color
		///
		inline void setColorBack(const sf::Color & color_back)
		{
			m_templ_color_back = color_back;
		}

		///
		///Metoda zwraca rozmiar czcionki
		///
		inline const unsigned getFontSize() const
		{
			return m_templ_font_size;
		}

		///
		///Metoda ustawia rozmiar czcionki
		///
		///@param font_size - rozmiar czcionki
		///
		inline void setFontSize(const unsigned font_size)
		{
			m_templ_font_size = font_size;
		}

		///
		///Metoda zwraca łańcuch znaków
		///
		inline const std::string & getString() const
		{
			return m_templ_string;
		}

		///
		///Metoda ustawia łańcuch znaków
		///
		///@param string - stała referencja na obiekt klasy std::string
		///
		inline void setString(const std::string & string)
		{
			m_templ_string = string;
		}

		///
		///Metoda zwraca łańcuch znaków
		///
		inline const std::wstring & getWString() const
		{
			return m_templ_wide_string;
		}

		///
		///Metoda ustawia łańcuch znaków
		///
		///@param string - stała referencja na obiekt klasy sf::String
		///
		inline void setWString(const std::wstring & string)
		{
			m_templ_wide_string = string;
		}

		///
		///Metoda zaraca flagę, czy obiekt posiada efekt 3D znaków
		///
		inline const bool getUseUnder() const
		{
			return m_templ_use_under;
		}

		///
		///Metoda ustawia flagę, czy obiekt posiada efekt 3D znaków
		///
		///@param use_under - flaga określa, czy obiekt posiada efekt 3D
		///
		inline void setUseUnder(const bool use_under)
		{
			m_templ_use_under = use_under;
		}

		///
		///Metoda zaraca wektor dla efektu 3D
		///
		inline const sf::Vector2f & getOffset() const
		{
			return m_templ_offset;
		}

		///
		///Metoda ustawia wektor dla efektu 3D
		///
		///@param templ_offset - stała referencja na obiekt klasy sf::Vector2f
		///
		inline void setOffset(const sf::Vector2f & templ_offset)
		{
			m_templ_offset = templ_offset;
		}

		///
		///Metoda zwraca nazwę czcionki
		///
		inline const std::string & getFontName() const
		{
			return m_templ_font_name;
		}

		///
		///Metoda ustawia nazwę czcionki
		///
		///@param templ_offset - stała referencja na obiekt klasy std::string
		///
		inline void setFontName(const std::string & font_name)
		{
			m_templ_font_name = font_name;
		}

	protected:

		std::string m_templ_filename; //nazwa pliku xml
		std::string m_templ_type; //typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
		sf::Transformable m_templ_tranformable;	//opakowanie danych do transformacji geometrycznej
		std::string m_templ_font_name; //nazwa czcionki
		sf::Color m_templ_color_front; //kolor front
		sf::Color m_templ_color_back; //kolor back
		unsigned m_templ_font_size; //rozmiar czcionki	(front and back)
		std::string m_templ_string; //łańcych znaków	(front = back)
		std::wstring m_templ_wide_string; //łańcych znaków	(front = back) - UTF-8 (bez BOM)
		bool m_templ_use_under; //flaga określa, czy obiekt posiada efekt 3D
		sf::Vector2f m_templ_offset; //wektor dla efektu 3D

	private:
	};
}//namespace factory
#endif//H_PRESENTATION_TEMPLATE_JACK
