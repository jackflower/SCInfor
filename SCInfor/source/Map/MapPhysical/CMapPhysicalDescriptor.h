//  ___________________________________________________
// | CMapPhysicalDescriptor.h - class definition       |
// | Jack Flower - March 2015                          |
// |___________________________________________________|
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
	///Klasa reprezentuje opakowanie danych dla obiekt�w (CMapPhysical),
	///umieszczonych na mapie (plik xml)
	///
	class CMapPhysicalDescriptor
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CMapPhysicalDescriptor();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CMapPhysicalDescriptorCopy - sta�a referencja n aobiekt klasy CMapPhysicalDescriptor
		///
		CMapPhysicalDescriptor(const CMapPhysicalDescriptor & CMapPhysicalDescriptorCopy);

		///
		///Destruktor
		///
		~CMapPhysicalDescriptor();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda tworzy obiekt mapy
		///
		void create();

		///
		///Metoda zwraca wska�nik na wzorzec fabryczny obiektu
		///
		MapPhysicalTemplate* GetTemplate() const;

		///
		///Metoda ustawia wska�nik na wzorzec fabryczny obiektu
		///
		///@param * template_param - wska�nik na wzorzec
		///
		void SetTemplate(MapPhysicalTemplate* template_param);

		///
		///Metoda zwraca unikalny identyfikator (nadawany w CMapPhysicalManager)
		///
		const int GetUniqueId() const;

		///
		///Metoda zwraca referencj� na nazw� kodu dla typu pod�o�a zapisanego w pliku xml
		///
		const std::string & GetCode() const;
		
		///
		///Metoda zwraca nazw� kodu dla typu pod�o�a zapisanego w pliku xml
		///
		///@param & code - nazw� kodu dla typu pod�o�a zapisanego w pliku xml - sta�a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca referencj� na nazw� w�asn� obiektu nadawan� na poziomie wpisu w pliku xml
		///
		const std::string & GetName() const;

		///
		///Metoda ustawia nazw� w�asn� obiektu nadawan� na poziomie wpisu w pliku xml
		///
		///@param & name - nazw� w�asn� obiektu - sta�a referencja na obiekt klasy std::string
		///
		void SetName(const std::string & name);

		///
		///Metoda zwraca pozycj� obiektu
		///
		const sf::Vector2f & GetPosition() const;

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param & position - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetPosition(const sf::Vector2f & position);

		///
		///Metoda ustawia na pozycj� obiektu
		///
		///@param position_x - sk�adowa X pozycji
		///
		///@param position_y - sk�adowa Y pozycji
		///
		void SetPosition(float position_x, float position_y);

		///
		///Metoda zwraca skal�
		///
		const sf::Vector2f & GetScale() const;
		
		///
		///Metoda ustawia skal�
		///
		///@param x - wsp�rz�dna x wektora
		///
		///@param y - wsp�rz�dna y wektora
		///
		void SetScale(float x, float y);

		///
		///Metoda ustawia skal�
		///
		///@param & scale - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skal�
		///
		///@param factors - jednolita warto�� skaluj�ca w osi x i y
		///
		void SetScale(float factors);

		///
		///Metoda zwraca warto�� obrotu
		///
		float GetRotation() const;
		
		///
		///Metoda ustawia warto�� obrotu
		///
		///@param rotation_value - warto�� obrotu
		///
		void SetRotation(float rotation_value);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & GetSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - sta�a referencja na obiekto klasy sf::Vector2f
		///
		void SetSize(const sf::Vector2f & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - sk�adowa x
		///
		///@param y - sk�adowa y
		///
		void SetSize(float x, float y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void SetSize(float uniform);

		///
		///Metoda zwraca flag� okre�laj�c� filtr wyg�adzaj�cy tekstur�
		///
		const bool GetSmooth() const;

		///
		///Metoda ustawia flag� okre�laj�c� filtr wyg�adzaj�cy tekstur�
		///
		///@param smooth - flaga okre�laj�ca filtr wyg�adzaj�cy tekstur�
		///
		void SetSmooth(bool smooth);

		///
		///Metoda zwraca flag� okre�laj�c� czy obiekt jest widoczny
		///
		const bool GetVisible() const;

		///
		///Metoda ustawia flag� okre�laj�c� czy obiekt b�dzie widoczny
		///
		///@param visible - flaga okre�laj�ca czy obiekt b�dzie widoczny
		///
		void SetVisible(bool visible);

	private:

		MapPhysicalTemplate*	p_template;		//wska�nik na wzorzec - obiekt klasy CMapPhysical jak i te� pochodne tej klasy
		int						m_unique_id;	//unikalny identyfikator (nadawany w CMapPhysicalManager)
		std::string				m_code;			//nazwa kodu dla typu pod�o�a (nazwa w tablicy 2D - zapisanej w pliku xml)
		std::string				m_name;			//nazwa w�asna obiektu, kt�r� nadajemy obiektowi na poziomie wpisu w pliku xml
		sf::Vector2f			m_position;		//pozycja obiektu
		sf::Vector2f			m_scale;		//skala obiektu
		float					m_rotation;		//warto�� obrotu obiektu
		sf::Vector2f			m_size;			//wektor wielko�ci obiektu (niezale�nie od rozmiaru tekstury)
		bool					m_smooth;		//flaga okre�laj�ca filtr wyg�adzaj�cy tekstur�
		bool					m_visible;		//flaga okre�laj�ca czy obiekt b�dzie widoczny

		static int				nextId;			//generator warto�ci unikalnej przy tworzeniu obiektu
	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_DESCRIPTOR_JACK
