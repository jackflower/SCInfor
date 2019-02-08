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
	///Klasa reprezentuje klasê bazow¹ dla obiektów znajduj¹cych siê na mapie (np. pod³o¿e)
	///
	class CMapPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CMapPhysicalManager;

		//Aby uzyskaæ obiekt CMapPhysicalManager, nale¿y wywo³aæ CMapPhysicalManager::CreateMapPhysical();

	protected:

		///
		///Chroniony konstruktor domyœlny - u¿ywany wy³¹cznie przez CMapPhysicalManager
		///
		///@param & uniqueId - unikalny identyfikator (nadawany w CMapPhysicalManager)
		///
		CMapPhysical(const std::wstring& uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CMapWorkCopy - parametr - obiekt klasy CMapPhysical
		///
		CMapPhysical(const CMapPhysical &CMapPhysicalCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CMapPhysicalManager
		///
		virtual ~CMapPhysical();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca unikaln¹ nazwê obiektu klasy CMapPhysical
		///
		const std::wstring & GetUniqueId() const;

		///
		///Metoda ustawia flagê dla obiektów gotowych do destrukcji
		///
		void MarkForDelete();

		///
		///Metoda zwraca nazwê znacznika pod³o¿a na mapie (odczytany z xml)
		///
		const std::string & getCode() const;

		///
		///Metoda ustawia nazwê znacznika pod³o¿a na mapie (dotyczy xml)
		///
		///@param &code - nazwê znacznika pod³o¿a na mapie - sta³a refrrencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca pozycjê pod³o¿a
		///
		const sf::Vector2f & getPosition() const;

		///
		///Metoda ustawia pozycjê pod³o¿a na mapie
		///
		///@param x - sk³adowa x pod³o¿a na mapie
		///
		///@param y - sk³adowa y pod³o¿a na mapie
		///
		void setPosition(float x, float y);

		///
		///Metoda ustawia pozycjê pod³o¿a na mapie
		///
		///@param & map_physical_position - wektor pozycji - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f & map_physical_position);

		///
		///Metoda zwraca skalê
		///
		const sf::Vector2f& getScale() const;
		
		///
		///Metoda ustawia skalê
		///
		///@param x - wspó³rzêdna x wektora
		///
		///@param y - wspó³rzêdna y wektora
		///
		void setScale(float x, float y);

		///
		///Metoda ustawia skalê
		///
		///@param & scale - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skalê
		///
		///@param factors - jednolita wartoœæ skaluj¹ca w osi x i y
		///
		void setScale(float factors);

		///
		///Metoda ustawia skalê w stosunku do obecnej skali
		///
		///@param factorX - wspó³czynnik w osi x
		///
		///@param factorY - spó³czynnik w osi y
		///
		void scale(float factorX, float factorY);
			
		///
		///Metoda ustawia skalê w stosunku do obecnej skali
		///
		///@param &factor - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void scale(const sf::Vector2f & factor);

		///
		///Metoda zwraca wspó³rzêdne punktu uchwytu obiektu
		///
		const sf::Vector2f& getOrigin() const;

		///
		///Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
		///
		///@param x - wspó³rzêdna x
		///
		///@param y - wspó³rzêdna y
		///
		void setOrigin(float x, float y);

		///
		///Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
		///
		///@param &origin - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void setOrigin(const sf::Vector2f & origin);

		///
		///Metoda zwraca wartoœæ obrotu
		///
		float getRotation() const;
		
		///
		///Metoda ustawia wartoœæ obrotu
		///
		///@param rotation_value - wartoœæ obrotu
		///
		void setRotation(float rotation_value);

		///
		///Metoda obraca wartoœæ obrotu
		///
		///@param angle - wartoœæ obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & getSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - sta³a referencja na obiekto klasy sf::Vector2f
		///
		void setSize(const sf::Vector2f & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - sk³adowa x
		///
		///@param y - sk³adowa y
		///
		void setSize(float x, float y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void setSize(float uniform);

		///
		///Metoda ustawia widocznoœæ pod³o¿a na mapie
		///
		///@param visible - flaga, czy pod³o¿e ma byæ widczne na mapie
		///
		void setVisible(bool visible);

		///
		///Metoda ustawia grafikê na teksturê
		///
		///@param & image_name - nazwa - sta³a referencja na obiekt klasy std::string
		///
		void setImage(const std::string & image_name);

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokoœæ tekstury (obiektu) w pikselach
		///
		///@param height - wysokoœæ tekstury (obiektu) w pikselach
		///
		///@param color - & color - sta³a referencja na obiekt klasy sf::Color
		///
		void setImage(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokoœæ tekstury (obiektu) w pikselach
		///
		///@param height - wysokoœæ tekstury (obiektu) w pikselach
		///
		///@param r - sk³adowa red koloru
		///
		///@param g - sk³adowa green koloru
		///
		///@param b - sk³adowa blue koloru
		///
		///@param a - sk³adowa alpha koloru
		///
		void setImage(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a);

		///
		///Metoda ustawia animacjê
		///
		///@param & animation_name - nazwa aniamacji - sta³a referncja na obiekt kasy std::string
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
		///Metoda zwraca flagê okreœlaj¹c¹ filtr wyg³adzaj¹cy teksturê
		///
		const bool getSmooth() const;

		///
		///Metoda ustawia flagê okreœlaj¹c¹ filtr wyg³adzaj¹cy teksturê
		///
		///@param smooth - flaga okreœlaj¹ca filtr wyg³adzaj¹cy teksturê
		///
		void setSmooth(bool smooth);

		///
		///Metoda zwraca wskaŸnik na obiekt klasy MapPhysicalTemplate
		///
		inline MapPhysicalTemplate *GetTemplate() const { return p_template; }

		///
		///Metoda ustawia wskaŸnik na obiekt klasy MapPhysicalTemplate
		///
		///@param *p_template - wskaŸnik na obiekt klasy MapPhysicalTemplate
		///
		inline void SetTemplate(MapPhysicalTemplate* p_template_param) { p_template = p_template_param; }

		///
		///Metoda zwraca wskaŸnik na obiekt klasy CDisplayable
		///
		CDisplayable* GetDisplayable();

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		std::wstring			m_unique_id;				//unikalny identyfikator (nadawany w CMapPhysicalManager)
		std::string				m_code;						//nazwa kodu dla typu pod³o¿a (obiektu fabrycznego)
		CDisplayable*			p_displayable;				//wskaŸnik na graficzn¹ reprezentacjê obiektu
		sf::Vector2f			m_map_physical_position;	//pozycja pod³o¿a (podobnie jak kafle)
		sf::Vector2f			m_scale;					//skala obiektu
		sf::Vector2f			m_origin;					//opakowanie wspó³rzêdnych uchwytu (hot point) obiektu
		float					m_rotation;					//wartoœæ obrotu obiektu
		sf::Vector2f			m_size;						//wektor wielkoœci obiektu (niezale¿nie od rozmiaru tekstury)
		std::string				m_displayable_type;			//typ graficznej reprezentacji obiektu
		MapPhysicalTemplate*	p_template;					//wskaŸnik na wzorzec - obiekt klasy CMapPhysical jak i te¿ pochodne tej klasy
		CTexture*				p_synthetic_texture;		//wskaŸnik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
		sf::Image*				p_synthetic_image;			//wskaŸnik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
		bool					m_smooth;					//flaga okreœlaj¹ca filtr wyg³adzaj¹cy teksturê

	private:

		int						m_mapphysical_manager_index;//wyliczony indeks w CMapPhysicalManager
		bool					m_ready_for_destruction;	//flaga ustawia obiekty gotowe do destrukcji

		//prywatna metoda sprawdza, czy trzeba utworzyæ
		//obiekt klasy CDisplayable (body), np. gdy chcemy
		//dodaæ obrazek, animacjê, syntetyk, etc...
		void checkDisplayable();
	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_JACK
