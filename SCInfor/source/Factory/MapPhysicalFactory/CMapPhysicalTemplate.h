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
	///Klasa reprezentuje wzorzec fabryczny dla obiekt�w logicznych i posiadaj�cych 
	///reprezentacj� graficzn�, kt�re mog� by� zarz�dzane i umieszczone na mapie
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
		///Konstruktor kopiuj�cy
		///
		///@param - CMapPhysicalTemplateCopy - sta�a referencja na obiekt klasy CMapPhysicalTemplate
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
		///Wirtualna metoda zwalniaj�ca zas�b
		///
		void Drop();

		///
		///Metoda �aduj�ca dane
		///
		///@param &name - sta�a referencja na std::string
		///
		bool Load(const std::string &name);

		///
		///Wirtualna metoda �aduj�ca dane z xml wywo�ywana przez implementacje klas potomnych
		///
		///@param &xml - referencja na obiekt klasy CXml
		///
		virtual bool Load(CXml &xml);

		///
		///Wirtualna metoda tworzenie obiekt�w pochodnych klasy CMapPhysical
		///
		///implementowana przez w pe�ni konkretne podklasy
		///
		///@param id - nazwa identyfikatora - obiekt klasy std::wstring
		///
		virtual CMapPhysical* Create(std::wstring id = L"");

		///
		///Wirtualna metoda wype�niaj�ca wskazany obiekt danymi tej klasy
		///
		///@param *mapphysical - wska�nik na obiekt klasy CMapPhysical
		///
		virtual void Fill(CMapPhysical *mapphysical);

		///
		///Metoda zwraca nazw� pliku zasobu
		///
		const std::string& GetFilename() const;

		///
		///Metoda ustawia nazw� pliku zasobu
		///
		///@param templ_filename - nazwa pliku - sta�a referencja na obiekt klasy std::string
		///
		void setFilename(const std::string& templ_filename);

		///
		///Metoda zwraca typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		///
		const std::string getType() const;

		///
		///Metoda ustawia typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		///
		///@param templ_type - typ obiektu odczytanego z xml'a - sta�a referencja na obiekt klasy std::string
		///
		void setType(const std::string& templ_type);

		///
		///Metoda zwraca nazw� kodu dla typu pod�o�a
		///
		const std::string getCode() const;

		///
		///Metoda ustawia nazw� kodu dla typu pod�o�a
		///
		///@param templ_code - typ pod�o�a - sta�a referencja na obiekt klasy std::string
		///
		void setCode(const std::string& templ_code);

		///
		///Metoda zwraca typ reprezentacji graficznej obiektu
		///
		const std::string getDisplayableType() const;

		///
		///Metoda ustawia typ reprezentacji graficznej obiektu
		///
		///@param templ_displayable_type - typ reprezentacji graficznej - sta�a referencja na obiekt klasy std::string
		///
		void setDisplayableType(const std::string& templ_displayable_type);

	protected:

		std::string		m_templ_filename;			//nazwa pliku xml
		std::string		m_templ_type;				//typ obiektu odczytanego z xml'a, na podstawie kt�rego CResourceManager tworzy zas�b
		std::string		m_templ_code;				//nazwa kodu dla typu pod�o�a (nazwa w tablicy 2D - zapisanej w pliku xml)
		std::string		m_templ_displayable_type;	//typ graficznej reprezentacji obiektu
		//graficzna reprezentacja obiektu
		std::string		m_texture_name;				//nazwa dla tektury
		unsigned		m_texture_width;			//szeroko�� tekstury w pikselach
		unsigned		m_texture_height;			//wysoko�� tekstury w pikselach
		sf::Color		m_color;					//kolor obiektu
		std::string		m_animation_name;			//nazwa dla animacji
		sf::Vector2f	m_templ_scale;				//skala obiektu
		float			m_templ_rotation;			//warto�� obrotu obiektu
		sf::Vector2f	m_templ_size;				//wektor wielko�ci obiektu (niezale�nie od rozmiaru tekstury)
		bool			m_templ_smooth;				//flaga okre�laj�ca filtr wyg�adzaj�cy tekstur�

		//czekam na klas�, czekam na nazw�...
		//CGroundPhysicsTemplate*		p_templ_physicsground			//dane wzorca obiektu CGroundPhysics

	};
}//namespace factory
#endif//H_MAP_PHYSICAL_TEMPLATE_JACK