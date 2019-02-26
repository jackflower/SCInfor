//  ________________________________________________
// | MapPhysicalTemplate.h - class definition       |
// | Jack Flower - March 2015                       |
// |________________________________________________|


#ifndef H_MAP_PHYSICAL_TEMPLATE_JACK
#define H_MAP_PHYSICAL_TEMPLATE_JACK

#include "../../ResourceManager/Resource.h"
#include "../../Map/MapPhysical/MapPhysical.h"
#include "../../Logic/MapPhysicalManager.h"
#include "../../XML/Xml.h"
#include "../../RTTI/RTTI.h"
#include <string>

using namespace xml;
using namespace resource;
using namespace mapengine;
using namespace logic;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec fabryczny dla obiektów logicznych i posiadających 
	///reprezentację graficzną, które mogą być zarządzane i umieszczone na mapie
	///
	class MapPhysicalTemplate : public Resource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		MapPhysicalTemplate();

		///
		///Konstruktor kopiujący
		///
		///@param - MapPhysicalTemplateCopy - stała referencja na obiekt klasy MapPhysicalTemplate
		///
		MapPhysicalTemplate(const MapPhysicalTemplate & MapPhysicalTemplateCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~MapPhysicalTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Wirtualna metoda zwalniająca zasób
		///
		void drop();

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
		///Wirtualna metoda tworzenie obiektów pochodnych klasy MapPhysical
		///
		///implementowana przez w pełni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual MapPhysical *create(std::wstring id = L"");

		///
		///Wirtualna metoda wypełniająca wskazany obiekt danymi tej klasy
		///
		///@param *mapphysical - wskaźnik na obiekt klasy MapPhysical
		///
		virtual void fill(MapPhysical *mapphysical);

		///
		///Metoda zwraca nazwę pliku zasobu
		///
		const std::string & getFilename() const;

		///
		///Metoda ustawia nazwę pliku zasobu
		///
		///@param templ_filename - nazwa pliku - stała referencja na obiekt klasy std::string
		///
		void setFilename(const std::string & templ_filename);

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
		///
		const std::string getTypeName() const;

		///
		///Metoda ustawia typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
		///
		///@param templ_type - typ obiektu odczytanego z xml'a - stała referencja na obiekt klasy std::string
		///
		void setTypeName(const std::string & templ_type);

		///
		///Metoda zwraca nazwę kodu dla typu podłoża
		///
		const std::string getCode() const;

		///
		///Metoda ustawia nazwę kodu dla typu podłoża
		///
		///@param templ_code - typ podłoża - stała referencja na obiekt klasy std::string
		///
		void setCode(const std::string & templ_code);

		///
		///Metoda zwraca typ reprezentacji graficznej obiektu
		///
		const std::string getDisplayableType() const;

		///
		///Metoda ustawia typ reprezentacji graficznej obiektu
		///
		///@param templ_displayable_type - typ reprezentacji graficznej - stała referencja na obiekt klasy std::string
		///
		void setDisplayableType(const std::string & templ_displayable_type);

	protected:

		std::string	 m_templ_filename; //nazwa pliku xml
		std::string	 m_templ_type; //typ obiektu odczytanego z xml'a, na podstawie którego ResourceManager tworzy zasób
		std::string	 m_templ_code; //nazwa kodu dla typu podłoża (nazwa w tablicy 2D - zapisanej w pliku xml)
		std::string m_templ_displayable_type; //typ graficznej reprezentacji obiektu
		//graficzna reprezentacja obiektu
		std::string m_texture_name; //nazwa dla tektury
		unsigned m_texture_width; //szerokość tekstury w pikselach
		unsigned m_texture_height; //wysokość tekstury w pikselach
		sf::Color m_color; //kolor obiektu
		std::string	 m_animation_name; //nazwa dla animacji
		sf::Vector2f m_templ_scale; //skala obiektu
		float m_templ_rotation; //wartość obrotu obiektu
		sf::Vector2f m_templ_size; //wektor wielkości obiektu (niezależnie od rozmiaru tekstury)
		bool m_templ_smooth; //flaga określająca filtr wygładzający teksturę

		//czekam na klasę, czekam na nazwę...
		//CGroundPhysicsTemplate*		p_templ_physicsground			//dane wzorca obiektu CGroundPhysics

	};
}//namespace factory
#endif//H_MAP_PHYSICAL_TEMPLATE_JACK