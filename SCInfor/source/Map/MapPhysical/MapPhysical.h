//  ________________________________________
// | MapPhysical.h - class definition       |
// | Jack Flower - March 2015               |
// |________________________________________|
//

#ifndef H_MAP_PHYSICAL_JACK
#define H_MAP_PHYSICAL_JACK

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include "../../RTTI/RTTI.h"
#include "../../ResourceManager/RTexture.h"
#include "../../Rendering/Displayable/Displayable.h"

///
///Forward declaration
///
namespace rendering
{
	namespace displayable
	{
		class Displayable;
	}
}

namespace factory
{
	class MapPhysicalTemplate;
}
namespace logic
{
	class MapPhysicalManager;
}

using namespace rendering;
using namespace rendering::displayable;
using namespace factory;
using namespace logic;

namespace mapengine
{
	///
	///Klasa reprezentuje klasę bazową dla obiektów znajdujących się na mapie (np. podłoże)
	///
	class MapPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class MapPhysicalManager;

		//Aby uzyskać obiekt MapPhysicalManager, należy wywołać MapPhysicalManager::CreateMapPhysical();

	protected:

		///
		///Chroniony konstruktor domyślny - używany wyłącznie przez MapPhysicalManager
		///
		///@param uniqueId - unikalny identyfikator (nadawany w MapPhysicalManager)
		///
		MapPhysical(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param MapWorkCopy - parametr - obiekt klasy MapPhysical
		///
		MapPhysical(const MapPhysical & MapPhysicalCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez MapPhysicalManager
		///
		virtual ~MapPhysical();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca unikalną nazwę obiektu klasy MapPhysical
		///
		const std::wstring & getUniqueId() const;

		///
		///Metoda ustawia flagę dla obiektów gotowych do destrukcji
		///
		void markForDelete();

		///
		///Metoda zwraca nazwę znacznika podłoża na mapie (odczytany z xml)
		///
		const std::string & getCode() const;

		///
		///Metoda ustawia nazwę znacznika podłoża na mapie (dotyczy xml)
		///
		///@param code - nazwę znacznika podłoża na mapie - stała refrrencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca pozycję podłoża
		///
		const sf::Vector2f & getPosition() const;

		///
		///Metoda ustawia pozycję podłoża na mapie
		///
		///@param x - składowa x podłoża na mapie
		///
		///@param y - składowa y podłoża na mapie
		///
		void setPosition(float x, float y);

		///
		///Metoda ustawia pozycję podłoża na mapie
		///
		///@param map_physical_position - wektor pozycji - stała referencja na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f & map_physical_position);

		///
		///Metoda zwraca skalę
		///
		const sf::Vector2f & getScale() const;
		
		///
		///Metoda ustawia skalę
		///
		///@param x - współrzędna x wektora
		///
		///@param y - współrzędna y wektora
		///
		void setScale(float x, float y);

		///
		///Metoda ustawia skalę
		///
		///@param scale - stała referencja na obiekt klasy sf::Vector2f
		///
		void setScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skalę
		///
		///@param factors - jednolita wartość skalująca w osi x i y
		///
		void setScale(float factors);

		///
		///Metoda ustawia skalę w stosunku do obecnej skali
		///
		///@param factorX - współczynnik w osi x
		///
		///@param factorY - spółczynnik w osi y
		///
		void scale(float factorX, float factorY);
			
		///
		///Metoda ustawia skalę w stosunku do obecnej skali
		///
		///@param factor - stała referencja na obiekt klasy sf::Vector2f
		///
		void scale(const sf::Vector2f & factor);

		///
		///Metoda zwraca współrzędne punktu uchwytu obiektu
		///
		const sf::Vector2f & getOrigin() const;

		///
		///Metoda ustawia współrzędne punktu uchwytu obiektu
		///
		///@param x - współrzędna x
		///
		///@param y - współrzędna y
		///
		void setOrigin(float x, float y);

		///
		///Metoda ustawia współrzędne punktu uchwytu obiektu
		///
		///@param origin - stała referencja na obiekt klasy sf::Vector2f
		///
		void setOrigin(const sf::Vector2f & origin);

		///
		///Metoda zwraca wartość obrotu
		///
		float getRotation() const;
		
		///
		///Metoda ustawia wartość obrotu
		///
		///@param rotation_value - wartość obrotu
		///
		void setRotation(float rotation_value);

		///
		///Metoda obraca wartość obrotu
		///
		///@param angle - wartość obrotu
		///
		void rotate(float angle);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & getSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - stała referencja na obiekto klasy sf::Vector2f
		///
		void setSize(const sf::Vector2f & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - składowa x
		///
		///@param y - składowa y
		///
		void setSize(float x, float y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void setSize(float uniform);

		///
		///Metoda ustawia widoczność podłoża na mapie
		///
		///@param visible - flaga, czy podłoże ma być widczne na mapie
		///
		void setVisible(bool visible);

		///
		///Metoda ustawia grafikę na teksturę
		///
		///@param image_name - nazwa - stała referencja na obiekt klasy std::string
		///
		void setImage(const std::string & image_name);

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokość tekstury (obiektu) w pikselach
		///
		///@param height - wysokość tekstury (obiektu) w pikselach
		///
		///@param color - & color - stała referencja na obiekt klasy sf::Color
		///
		void setImage(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

		///
		///Metoda generuje obraz tekstury
		///
		///@param width - szerokość tekstury (obiektu) w pikselach
		///
		///@param height - wysokość tekstury (obiektu) w pikselach
		///
		///@param r - składowa red koloru
		///
		///@param g - składowa green koloru
		///
		///@param b - składowa blue koloru
		///
		///@param a - składowa alpha koloru
		///
		void setImage(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a);

		///
		///Metoda ustawia animację
		///
		///@param animation_name - nazwa aniamacji - stała referncja na obiekt kasy std::string
		///
		void setAnimation(const std::string & animation_name);

		///
		///Metoda zwraca stałą referencję na typ reprezentacji graficznej obiektu
		///
		const std::string & getMapPhysicalDisplayableType() const;
			
		///
		///Metoda ustawia typ reprezentacji graficznej obiektu
		///
		///@param displayable_type - stała referencja na typ reprezentacji graficznej obiektu
		///
		void setMapPhysicalDisplayableType(const std::string & displayable_type);

		///
		///Metoda zwraca flagę określającą filtr wygładzający teksturę
		///
		const bool getSmooth() const;

		///
		///Metoda ustawia flagę określającą filtr wygładzający teksturę
		///
		///@param smooth - flaga określająca filtr wygładzający teksturę
		///
		void setSmooth(bool smooth);

		///
		///Metoda zwraca wskaźnik na obiekt klasy MapPhysicalTemplate
		///
		MapPhysicalTemplate *getTemplate() const;

		///
		///Metoda ustawia wskaźnik na obiekt klasy MapPhysicalTemplate
		///
		///@param *p_template - wskaźnik na obiekt klasy MapPhysicalTemplate
		///
		void setTemplate(MapPhysicalTemplate *p_template_param);

		///
		///Metoda zwraca wskaźnik na obiekt klasy Displayable
		///
		Displayable *getDisplayable();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

	protected:

		std::wstring m_unique_id; //unikalny identyfikator (nadawany w MapPhysicalManager)
		std::string m_code; //nazwa kodu dla typu podłoża (obiektu fabrycznego)
		Displayable *p_displayable; //wskaźnik na graficzną reprezentację obiektu
		sf::Vector2f m_map_physical_position; //pozycja podłoża (podobnie jak kafle)
		sf::Vector2f m_scale; //skala obiektu
		sf::Vector2f m_origin; //opakowanie współrzędnych uchwytu (hot point) obiektu
		float m_rotation; //wartość obrotu obiektu
		sf::Vector2f m_size; //wektor wielkości obiektu (niezależnie od rozmiaru tekstury)
		std::string m_displayable_type; //typ graficznej reprezentacji obiektu
		MapPhysicalTemplate *p_template; //wskaźnik na wzorzec - obiekt klasy MapPhysical jak i też pochodne tej klasy
		RTexture *p_synthetic_texture; //wskaźnik na obiekt klasy RTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
		sf::Image *p_synthetic_image; //wskaźnik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
		bool m_smooth; //flaga określająca filtr wygładzający teksturę

	private:

		int m_mapphysical_manager_index; //wyliczony indeks w MapPhysicalManager
		bool m_ready_for_destruction; //flaga ustawia obiekty gotowe do destrukcji

		//prywatna metoda sprawdza, czy trzeba utworzyć
		//obiekt klasy Displayable (body), np. gdy chcemy
		//dodać obrazek, animację, syntetyk, etc...
		void checkDisplayable();
	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_JACK
