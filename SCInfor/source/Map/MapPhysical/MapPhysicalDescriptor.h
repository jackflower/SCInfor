//  __________________________________________________
// | MapPhysicalDescriptor.h - class definition       |
// | Jack Flower - March 2015                         |
// |__________________________________________________|
//

#ifndef H_MAP_PHYSICAL_DESCRIPTOR_JACK
#define H_MAP_PHYSICAL_DESCRIPTOR_JACK

#include "../../Factory/PhysicalTemplate.h"

namespace factory
{
	///
	///Forward declaration
	///
	class MapPhysicalTemplate;
}

using namespace factory;

namespace mapengine
{
	///
	///Klasa reprezentuje opakowanie danych dla obiektów (MapPhysical),
	///umieszczonych na mapie (plik xml)
	///
	class MapPhysicalDescriptor
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		MapPhysicalDescriptor();

		///
		///Konstruktor kopiujący
		///
		///@param MapPhysicalDescriptorCopy - stała referencja n aobiekt klasy MapPhysicalDescriptor
		///
		MapPhysicalDescriptor(const MapPhysicalDescriptor & MapPhysicalDescriptorCopy);

		///
		///Destruktor
		///
		~MapPhysicalDescriptor();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda tworzy obiekt mapy
		///
		void create();

		///
		///Metoda zwraca wskaźnik na wzorzec fabryczny obiektu
		///
		MapPhysicalTemplate *getTemplate() const;

		///
		///Metoda ustawia wskaźnik na wzorzec fabryczny obiektu
		///
		///@param *template_param - wskaźnik na wzorzec
		///
		void setTemplate(MapPhysicalTemplate *template_param);

		///
		///Metoda zwraca unikalny identyfikator (nadawany w MapPhysicalManager)
		///
		const int getUniqueId() const;

		///
		///Metoda zwraca referencję na nazwę kodu dla typu podłoża zapisanego w pliku xml
		///
		const std::string & getCode() const;
		
		///
		///Metoda zwraca nazwę kodu dla typu podłoża zapisanego w pliku xml
		///
		///@param code - nazwę kodu dla typu podłoża zapisanego w pliku xml - stała referencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca referencję na nazwę własną obiektu nadawaną na poziomie wpisu w pliku xml
		///
		const std::string & getName() const;

		///
		///Metoda ustawia nazwę własną obiektu nadawaną na poziomie wpisu w pliku xml
		///
		///@param name - nazwę własną obiektu - stała referencja na obiekt klasy std::string
		///
		void setName(const std::string & name);

		///
		///Metoda zwraca pozycję obiektu
		///
		const sf::Vector2f & getPosition() const;

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param position - stała referencja na obiekt klasy sf::Vector2f
		///
		void setPosition(const sf::Vector2f & position);

		///
		///Metoda ustawia na pozycję obiektu
		///
		///@param position_x - składowa X pozycji
		///
		///@param position_y - składowa Y pozycji
		///
		void setPosition(float position_x, float position_y);

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
		///Metoda zwraca flagę określającą czy obiekt jest widoczny
		///
		const bool getVisible() const;

		///
		///Metoda ustawia flagę określającą czy obiekt będzie widoczny
		///
		///@param visible - flaga określająca czy obiekt będzie widoczny
		///
		void setVisible(bool visible);

	private:

		MapPhysicalTemplate *p_template; //wskaźnik na wzorzec - obiekt klasy MapPhysical jak i też pochodne tej klasy
		int m_unique_id; //unikalny identyfikator (nadawany w MapPhysicalManager)
		std::string m_code; //nazwa kodu dla typu podłoża (nazwa w tablicy 2D - zapisanej w pliku xml)
		std::string m_name; //nazwa własna obiektu, którą nadajemy obiektowi na poziomie wpisu w pliku xml
		sf::Vector2f m_position; //pozycja obiektu
		sf::Vector2f m_scale; //skala obiektu
		float m_rotation; //wartość obrotu obiektu
		sf::Vector2f m_size; //wektor wielkości obiektu (niezależnie od rozmiaru tekstury)
		bool m_smooth; //flaga określająca filtr wygładzający teksturę
		bool m_visible; //flaga określająca czy obiekt będzie widoczny

		static int nextId; //generator wartości unikalnej przy tworzeniu obiektu
	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_DESCRIPTOR_JACK
