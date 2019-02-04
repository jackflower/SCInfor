//  _________________________________________________
// | CMapPhysicalTemplate.h - class definition       |
// | Jack Flower - March 2015                        |
// |_________________________________________________|


#ifndef H_MAP_PHYSICAL_TEMPLATE_JACK
#define H_MAP_PHYSICAL_TEMPLATE_JACK

#include "../../ResourceManager/IResource.h"
#include "../../Map/MapPhysical/CMapPhysical.h"
#include "../../Logic/CMapPhysicalManager.h"
#include "../../XML/CXml.h"
#include "../../RTTI/RTTI.h"
#include <string>

using namespace xml;
using namespace resource;
using namespace mapengine;
using namespace logic;

namespace factory
{
	///
	///Klasa reprezentuje wzorzec fabryczny dla obiektów logicznych i posiadaj¹cych 
	///reprezentacjê graficzn¹, które mog¹ byæ zarz¹dzane i umieszczone na mapie
	///
	class CMapPhysicalTemplate : public IResource
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CMapPhysicalTemplate();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param - CMapPhysicalTemplateCopy - sta³a referencja na obiekt klasy CMapPhysicalTemplate
		///
		CMapPhysicalTemplate(const CMapPhysicalTemplate & CMapPhysicalTemplateCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CMapPhysicalTemplate();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Wirtualna metoda zwalniaj¹ca zasób
		///
		void Drop();

		///
		///Metoda ³aduj¹ca dane
		///
		///@param &name - sta³a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda ³aduj¹ca dane z xml wywo³ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiektów pochodnych klasy CMapPhysical
		///
		///implementowana przez w pe³ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CMapPhysical* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype³niaj¹ca wskazany obiekt danymi tej klasy
		///
		///@param *mapphysical - wskaŸnik na obiekt klasy CMapPhysical
		///
		virtual void Fill(CMapPhysical *mapphysical);

		///
		///Metoda zwraca nazwê pliku zasobu
		///
		const std::string& GetFilename() const;

		///
		///Metoda ustawia nazwê pliku zasobu
		///
		///@param templ_filename - nazwa pliku - sta³a referencja na obiekt klasy std::string
		///
		void setFilename(const std::string& templ_filename);

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		///
		const std::string getType() const;

		///
		///Metoda ustawia typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		///
		///@param templ_type - typ obiektu odczytanego z xml'a - sta³a referencja na obiekt klasy std::string
		///
		void setType(const std::string& templ_type);

		///
		///Metoda zwraca nazwê kodu dla typu pod³o¿a
		///
		const std::string getCode() const;

		///
		///Metoda ustawia nazwê kodu dla typu pod³o¿a
		///
		///@param templ_code - typ pod³o¿a - sta³a referencja na obiekt klasy std::string
		///
		void setCode(const std::string& templ_code);

		///
		///Metoda zwraca typ reprezentacji graficznej obiektu
		///
		const std::string getDisplayableType() const;

		///
		///Metoda ustawia typ reprezentacji graficznej obiektu
		///
		///@param templ_displayable_type - typ reprezentacji graficznej - sta³a referencja na obiekt klasy std::string
		///
		void setDisplayableType(const std::string& templ_displayable_type);

	protected:

		std::string		m_templ_filename;			//nazwa pliku xml
		std::string		m_templ_type;				//typ obiektu odczytanego z xml'a, na podstawie którego CResourceManager tworzy zasób
		std::string		m_templ_code;				//nazwa kodu dla typu pod³o¿a (nazwa w tablicy 2D - zapisanej w pliku xml)
		std::string		m_templ_displayable_type;	//typ graficznej reprezentacji obiektu
		//graficzna reprezentacja obiektu
		std::string		m_texture_name;				//nazwa dla tektury
		unsigned		m_texture_width;			//szerokoœæ tekstury w pikselach
		unsigned		m_texture_height;			//wysokoœæ tekstury w pikselach
		sf::Color		m_color;					//kolor obiektu
		std::string		m_animation_name;			//nazwa dla animacji
		sf::Vector2f	m_templ_scale;				//skala obiektu
		float			m_templ_rotation;			//wartoœæ obrotu obiektu
		sf::Vector2f	m_templ_size;				//wektor wielkoœci obiektu (niezale¿nie od rozmiaru tekstury)
		bool			m_templ_smooth;				//flaga okreœlaj¹ca filtr wyg³adzaj¹cy teksturê

		//czekam na klasê, czekam na nazwê...
		//CGroundPhysicsTemplate*		p_templ_physicsground			//dane wzorca obiektu CGroundPhysics

	};
}//namespace factory
#endif//H_MAP_PHYSICAL_TEMPLATE_JACK