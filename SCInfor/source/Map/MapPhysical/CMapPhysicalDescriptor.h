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
	///Klasa reprezentuje opakowanie danych dla obiektów (CMapPhysical),
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
		///Konstruktor kopiuj¹cy
		///
		///@param & CMapPhysicalDescriptorCopy - sta³a referencja n aobiekt klasy CMapPhysicalDescriptor
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
		///Metoda zwraca wskaŸnik na wzorzec fabryczny obiektu
		///
		MapPhysicalTemplate* GetTemplate() const;

		///
		///Metoda ustawia wskaŸnik na wzorzec fabryczny obiektu
		///
		///@param * template_param - wskaŸnik na wzorzec
		///
		void SetTemplate(MapPhysicalTemplate* template_param);

		///
		///Metoda zwraca unikalny identyfikator (nadawany w CMapPhysicalManager)
		///
		const int GetUniqueId() const;

		///
		///Metoda zwraca referencjê na nazwê kodu dla typu pod³o¿a zapisanego w pliku xml
		///
		const std::string & GetCode() const;
		
		///
		///Metoda zwraca nazwê kodu dla typu pod³o¿a zapisanego w pliku xml
		///
		///@param & code - nazwê kodu dla typu pod³o¿a zapisanego w pliku xml - sta³a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca referencjê na nazwê w³asn¹ obiektu nadawan¹ na poziomie wpisu w pliku xml
		///
		const std::string & GetName() const;

		///
		///Metoda ustawia nazwê w³asn¹ obiektu nadawan¹ na poziomie wpisu w pliku xml
		///
		///@param & name - nazwê w³asn¹ obiektu - sta³a referencja na obiekt klasy std::string
		///
		void SetName(const std::string & name);

		///
		///Metoda zwraca pozycjê obiektu
		///
		const sf::Vector2f & GetPosition() const;

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param & position - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetPosition(const sf::Vector2f & position);

		///
		///Metoda ustawia na pozycjê obiektu
		///
		///@param position_x - sk³adowa X pozycji
		///
		///@param position_y - sk³adowa Y pozycji
		///
		void SetPosition(float position_x, float position_y);

		///
		///Metoda zwraca skalê
		///
		const sf::Vector2f & GetScale() const;
		
		///
		///Metoda ustawia skalê
		///
		///@param x - wspó³rzêdna x wektora
		///
		///@param y - wspó³rzêdna y wektora
		///
		void SetScale(float x, float y);

		///
		///Metoda ustawia skalê
		///
		///@param & scale - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetScale(const sf::Vector2f & scale);

		///
		///Metoda ustawia skalê
		///
		///@param factors - jednolita wartoœæ skaluj¹ca w osi x i y
		///
		void SetScale(float factors);

		///
		///Metoda zwraca wartoœæ obrotu
		///
		float GetRotation() const;
		
		///
		///Metoda ustawia wartoœæ obrotu
		///
		///@param rotation_value - wartoœæ obrotu
		///
		void SetRotation(float rotation_value);

		///
		///Metoda zwraca rozmiar obiektu
		///
		const sf::Vector2f & GetSize() const;

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@para size - rozmiar - sta³a referencja na obiekto klasy sf::Vector2f
		///
		void SetSize(const sf::Vector2f & size);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@param x - sk³adowa x
		///
		///@param y - sk³adowa y
		///
		void SetSize(float x, float y);

		///
		///Metoda ustawia rozmiar obiektu
		///
		///@uniform - rozmiar
		///
		void SetSize(float uniform);

		///
		///Metoda zwraca flagê okreœlaj¹c¹ filtr wyg³adzaj¹cy teksturê
		///
		const bool GetSmooth() const;

		///
		///Metoda ustawia flagê okreœlaj¹c¹ filtr wyg³adzaj¹cy teksturê
		///
		///@param smooth - flaga okreœlaj¹ca filtr wyg³adzaj¹cy teksturê
		///
		void SetSmooth(bool smooth);

		///
		///Metoda zwraca flagê okreœlaj¹c¹ czy obiekt jest widoczny
		///
		const bool GetVisible() const;

		///
		///Metoda ustawia flagê okreœlaj¹c¹ czy obiekt bêdzie widoczny
		///
		///@param visible - flaga okreœlaj¹ca czy obiekt bêdzie widoczny
		///
		void SetVisible(bool visible);

	private:

		MapPhysicalTemplate*	p_template;		//wskaŸnik na wzorzec - obiekt klasy CMapPhysical jak i te¿ pochodne tej klasy
		int						m_unique_id;	//unikalny identyfikator (nadawany w CMapPhysicalManager)
		std::string				m_code;			//nazwa kodu dla typu pod³o¿a (nazwa w tablicy 2D - zapisanej w pliku xml)
		std::string				m_name;			//nazwa w³asna obiektu, któr¹ nadajemy obiektowi na poziomie wpisu w pliku xml
		sf::Vector2f			m_position;		//pozycja obiektu
		sf::Vector2f			m_scale;		//skala obiektu
		float					m_rotation;		//wartoœæ obrotu obiektu
		sf::Vector2f			m_size;			//wektor wielkoœci obiektu (niezale¿nie od rozmiaru tekstury)
		bool					m_smooth;		//flaga okreœlaj¹ca filtr wyg³adzaj¹cy teksturê
		bool					m_visible;		//flaga okreœlaj¹ca czy obiekt bêdzie widoczny

		static int				nextId;			//generator wartoœci unikalnej przy tworzeniu obiektu
	};
}//namespace mapengine
#endif//H_MAP_PHYSICAL_DESCRIPTOR_JACK
