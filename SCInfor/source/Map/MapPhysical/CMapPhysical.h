//  _________________________________________
// | CMapPhysical.h - class definition       |
// | Jack Flower - March 2015                |
// |_________________________________________|
//

#ifndef H_MAP_PHYSICAL_JACK
#define H_MAP_PHYSICAL_JACK

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "../../RTTI/RTTI.h"
#include "../../ResourceManager/CTexture.h"
#include "../../Rendering/Displayable/CDisplayable.h"

///
///Forward declaration
///
namespace rendering
{
	namespace displayable
	{
		class CDisplayable;
	}
}

namespace factory
{
	class MapPhysicalTemplate;
}
namespace logic
{
	class CMapPhysicalManager;
}

using namespace rendering;
using namespace rendering::displayable;
using namespace factory;
using namespace logic;

namespace mapengine
{
	///
	///Klasa reprezentuje klas� bazow� dla obiekt�w znajduj�cych si� na mapie (np. pod�o�e)
	///
	class CMapPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CMapPhysicalManager;

		//Aby uzyska� obiekt CMapPhysicalManager, nale�y wywo�a� CMapPhysicalManager::CreateMapPhysical();

	protected:

		///
		///Chroniony konstruktor domy�lny - u�ywany wy��cznie przez CMapPhysicalManager
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CMapPhysicalManager)
		///
		CMapPhysical(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CMapWorkCopy - parametr - obiekt klasy CMapPhysical
		///
		CMapPhysical(const CMapPhysical &CMapPhysicalCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CMapPhysicalManager
		///
		virtual ~CMapPhysical();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca unikaln� nazw� obiektu klasy CMapPhysical
		///
		const std::wstring & GetUniqueId() const;

		///
		///Metoda ustawia flag� dla obiekt�w gotowych do destrukcji
		///
		void MarkForDelete();

		///
		///Metoda zwraca nazw� znacznika pod�o�a na mapie (odczytany z xml)
		///
		const std::string & getCode() const;

		///
		///Metoda ustawia nazw� znacznika pod�o�a na mapie (dotyczy xml)
		///
		///@param &code - nazw� znacznika pod�o�a na mapie - sta�a refrrencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca pozycj� pod�o�a
		///
		const sf::Vector2f & getPosition() const;

		///
		///Metoda ustawia pozycj� pod�o�a na mapie
		///
		///@param x - sk�adowa x pod�o�a na mapie
		///
		///@param y - sk�adowa y pod�o�a na mapie
		///
		void setPosition(float x, float y);

		///
		///Metoda ustawia pozycj� pod�o�a na mapie
		///
		///@param & map_physical_position - wektor pozycji - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f & map_physical_position);

		///
		///Metoda zwraca skal�
		///
		const sf::Vector2f& getScale() const;
		
		///
		///Metoda ustawia skal�
		///
		///@param x - wsp�rz�dna x wektora
		///
		///@param y - wsp�rz�dna y wektora
		///
		void setScale(float x, float y);

		///
		///Metoda ustawia skal�
		///
		///@param & scale - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skal�
		///
		///@param factors - jednolita warto�� skaluj�ca w osi x i y
		///
		void setScale(float factors);

		///
		///Metoda ustawia skal� w stosunku do obecnej skali
		///
		///@param factorX - wsp�czynnik w osi x
		///
		///@param factorY - sp�czynnik w osi y
		///
		void scale(float factorX, float factorY);
			
		///
		///Metoda ustawia skal� w stosunku do obecnej skali
		///
		///@param &factor - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void scale(const sf::Vector2f & factor);

		///
		///Metoda zwraca wsp�rz�dne punktu uchwytu obiektu
		///
		const sf::Vector2f& getOrigin() const;

		///
		///Metoda ustawia wsp�rz�dne punktu uchwytu obiektu
		///
		///@param x - wsp�rz�dna x
		///
		///@param y - wsp�rz�dna y
		///
		void setOrigin(float x, float y);

		///
		///Metoda ustawia wsp�rz�dne punktu uchwytu obiektu
		///
		///@param &origin - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void setOrigin(const sf::Vector2f & origin);

		///
		///Metoda zwraca warto�� obrotu
		///
		float getRotation() const;
		
		///
		///Metoda ustawia warto�� obrotu
		///
		///@param rotation_value - warto�� obrotu
		///
		void setRotation(float rotation_value);

		///
		///Metoda obraca warto�� obrotu
		///
		///@param angle - warto�� obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & getSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - sta�a referencja na obiekto klasy sf::Vector2f
		///
		void setSize(const sf::Vector2f & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - sk�adowa x
		///
		///@param y - sk�adowa y
		///
		void setSize(float x, float y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void setSize(float uniform);

		///
		///Metoda ustawia widoczno�� pod�o�a na mapie
		///
		///@param visible - flaga, czy pod�o�e ma by� widczne na mapie
		///
		void setVisible(bool visible);

		///
		///Metoda ustawia grafik� na tekstur�
		///
		///@param & image_name - nazwa - sta�a referencja na obiekt klasy std::string
		///
		void setImage(const std::string & image_name);

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szeroko�� tekstury (obiektu) w pikselach
		///
		///@param height - wysoko�� tekstury (obiektu) w pikselach
		///
		///@param color - & color - sta�a referencja na obiekt klasy sf::Color
		///
		void setImage(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szeroko�� tekstury (obiektu) w pikselach
		///
		///@param height - wysoko�� tekstury (obiektu) w pikselach
		///
		///@param r - sk�adowa red koloru
		///
		///@param g - sk�adowa green koloru
		///
		///@param b - sk�adowa blue koloru
		///
		///@param a - sk�adowa alpha koloru
		///
		void setImage(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a);

		///
		///Metoda ustawia animacj�
		///
		///@param & animation_name - nazwa aniamacji - sta�a referncja na obiekt kasy std::string
		///
		void setAnimation(const std::string & animation_name);

		///
		///Metoda zwraca typ reprezentacji graficznej obiektu
		///
		const std::string getMapPhysicalDisplayableType() const;
			
		///
		///Metoda ustawia typ reprezentacji graficznej obiektu
		///
		///@param displayable_type - typ reprezentacji graficznej obiektu
		///
		void setMapPhysicalDisplayableType(const std::string displayable_type);

		///
		///Metoda zwraca flag� okre�laj�c� filtr wyg�adzaj�cy tekstur�
		///
		const bool getSmooth() const;

		///
		///Metoda ustawia flag� okre�laj�c� filtr wyg�adzaj�cy tekstur�
		///
		///@param smooth - flaga okre�laj�ca filtr wyg�adzaj�cy tekstur�
		///
		void setSmooth(bool smooth);

		///
		///Metoda zwraca wska�nik na obiekt klasy MapPhysicalTemplate
		///
		inline MapPhysicalTemplate *GetTemplate() const { return p_template; }

		///
		///Metoda ustawia wska�nik na obiekt klasy MapPhysicalTemplate
		///
		///@param *p_template - wska�nik na obiekt klasy MapPhysicalTemplate
		///
		inline void SetTemplate(MapPhysicalTemplate* p_template_param) { p_template = p_template_param; }

		///
		///Metoda zwraca wska�nik na obiekt klasy CDisplayable
		///
		CDisplayable* GetDisplayable();

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		std::wstring			m_unique_id;				//unikalny identyfikator (nadawany w CMapPhysicalManager)
		std::string				m_code;						//nazwa kodu dla typu pod�o�a (obiektu fabrycznego)
		CDisplayable*			p_displayable;				//wska�nik na graficzn� reprezentacj� obiektu
		sf::Vector2f			m_map_physical_position;	//pozycja pod�o�a (podobnie jak kafle)
		sf::Vector2f			m_scale;					//skala obiektu
		sf::Vector2f			m_origin;					//opakowanie wsp�rz�dnych uchwytu (hot point) obiektu
		float					m_rotation;					//warto�� obrotu obiektu
		sf::Vector2f			m_size;						//wektor wielko�ci obiektu (niezale�nie od rozmiaru tekstury)
		std::string				m_displayable_type;			//typ graficznej reprezentacji obiektu
		MapPhysicalTemplate*	p_template;					//wska�nik na wzorzec - obiekt klasy CMapPhysical jak i te� pochodne tej klasy
		CTexture*				p_synthetic_texture;		//wska�nik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
		sf::Image*				p_synthetic_image;			//wska�nik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
		bool					m_smooth;					//flaga okre�laj�ca filtr wyg�adzaj�cy tekstur�

	private:

		int						m_mapphysical_manager_index;//wyliczony indeks w CMapPhysicalManager
		bool					m_ready_for_destruction;	//flaga ustawia obiekty gotowe do destrukcji

		//prywatna metoda sprawdza, czy trzeba utworzy�
		//obiekt klasy CDisplayable (body), np. gdy chcemy
		//doda� obrazek, animacj�, syntetyk, etc...
		void checkDisplayable();
	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_JACK
