//  __________________________________________________
// | CInformationTemplate.h - class definition        |
// | Jack Flower - April 2015                         |
// |__________________________________________________|
//

#ifndef H_PRESENTATION_TEMPLATE_JACK
#define H_PRESENTATION_TEMPLATE_JACK

#include "../../ResourceManager/IResource.h"
#include "../../Information/CPresentation.h"
#include "../../XML/CXml.h"
#include "../../RTTI/RTTI.h"
#include <string>

using namespace resource;
using namespace xml;
using namespace information::presentation;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec dla obiektu klasy CPresentation
	///
	class CPresentationTemplate : public IResource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPresentationTemplate();

		///
		///Destruktor wirtualny
		///
		virtual ~CPresentationTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		virtual void drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiekt�w pochodnych klasy CPresentation
		///
		///implementowana przez w pe�ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CPresentation* create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *information - wska�nik na obiekt klasy CInformation
		///
		virtual void fill(CPresentation *presentation);

		///
		///Metoda zwraca nazw� pliku zasobu
		///
		inline const std::string& GetFilename() const
		{
			return m_templ_filename;
		}

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		///
		inline const std::string& GetTypeName() const
		{
			return m_templ_type;
		}

		///
		///Metoda zwraca referencj� na obiekt klasy sf::Transformable
		///
		inline const sf::Transformable getTransformable() const
		{
			return m_templ_tranformable;
		}
		
		///
		///Metoda ustawia referencj� na obiekt klasy sf::Transformable
		///
		///@param & templ_tranformable - sta�a referencja na obiekt klasy sf::Transformable
		///
		inline void setTransformable(const sf::Transformable & templ_tranformable)
		{
			m_templ_tranformable = templ_tranformable;
		}

		///
		///Metoda zaraca sta�� referencj� na obiekt klasy sf::Color - front
		///
		inline const sf::Color & getColorFront() const
		{
			return m_templ_color_front;
		}

		///
		///Metoda ustawia kolor obiektu - front
		///
		///
		///@param &color_front - sta�a referencja na obiekt klasy sf::Color
		///
		inline void setColorFront(const sf::Color & color_front)
		{
			m_templ_color_front = color_front;
		}

		///
		///Metoda zaraca sta�� referencj� na obiekt klasy sf::Color - back
		///
		inline const sf::Color & getColorBack() const
		{
			return m_templ_color_back;
		}

		///
		///Metoda ustawia kolor obiektu - back
		///
		///@param & color_back - sta�a referencja na obiekt klasy sf::Color
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
		///Metoda zwraca �a�cuch znak�w
		///
		inline const std::string & getString() const
		{
			return m_templ_string;
		}

		///
		///Metoda ustawia �a�cuch znak�w
		///
		///@param & string - sta�a referencja na obiekt klasy std::string
		///
		inline void setString(const std::string & string)
		{
			m_templ_string = string;
		}

		///
		///Metoda zwraca �a�cuch znak�w
		///
		inline const std::wstring & getWString() const
		{
			return m_templ_wide_string;
		}

		///
		///Metoda ustawia �a�cuch znak�w
		///
		///@param & string - sta�a referencja na obiekt klasy sf::String
		///
		inline void setWString(const std::wstring & string)
		{
			m_templ_wide_string = string;
		}

		///
		///Metoda zaraca flag�, czy obiekt posiada efekt 3D znak�w
		///
		inline const bool getUseUnder() const
		{
			return m_templ_use_under;
		}

		///
		///Metoda ustawia flag�, czy obiekt posiada efekt 3D znak�w
		///
		///@param use_under - flaga okre�la, czy obiekt posiada efekt 3D
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
		///@param &templ_offset - sta�a referencja na obiekt klasy sf::Vector2f
		///
		inline void setOffset(const sf::Vector2f & templ_offset)
		{
			m_templ_offset = templ_offset;
		}

		///
		///Metoda zwraca nazw� czcionki
		///
		inline const std::string & getFontName() const
		{
			return m_templ_font_name;
		}

		///
		///Metoda ustawia nazw� czcionki
		///
		///@param &templ_offset - sta�a referencja na obiekt klasy std::string
		///
		inline void setFontName(const std::string & font_name)
		{
			m_templ_font_name = font_name;
		}

	protected:

		std::string			m_templ_filename;		//nazwa pliku xml
		std::string			m_templ_type;			//typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		sf::Transformable	m_templ_tranformable;	//opakowanie danych do transformacji geometrycznej
		std::string			m_templ_font_name;		//nazwa czcionki
		sf::Color			m_templ_color_front;	//kolor front
		sf::Color			m_templ_color_back;		//kolor back
		unsigned			m_templ_font_size;		//rozmiar czcionki	(front and back)
		std::string			m_templ_string;			//�a�cych znak�w	(front = back)
		std::wstring		m_templ_wide_string;	//�a�cych znak�w	(front = back) - UTF-8 (bez BOM)
		bool				m_templ_use_under;		//flaga okre�la, czy obiekt posiada efekt 3D
		sf::Vector2f		m_templ_offset;			//wektor dla efektu 3D

	private:
	};
}//namespace factory
#endif//H_PRESENTATION_TEMPLATE_JACK
