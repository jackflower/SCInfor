//  _________________________________________________
// | CMapObjectDescriptor.h - class definition       |
// | Jack Flower April 2013                          |
// |_________________________________________________|
//

#ifndef H_MAP_OBJECT_DESCRIPTOR_JACK
#define H_MAP_OBJECT_DESCRIPTOR_JACK

#include <string>
#include "../../Factory/PhysicalTemplate.h"

namespace factory
{
	///
	///Forward declaration
	///
	class PhysicalTemplate;
}

namespace mapengine
{
	///
	///Klasa reprezentuje opakowanie danych dla obiektów (physicals),
	///umieszczonych na mapie (wczytywane z xml)
	///
    class CMapObjectDescriptor
	{
		RTTI_DECL;

    public:

		///
		///Konstruktor
		///
		CMapObjectDescriptor();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param &CMapObjectDescriptorCopy - obiekt klasy CMapObjectDescriptor
		///
		CMapObjectDescriptor(const CMapObjectDescriptor& CMapObjectDescriptorCopy);

		///
		///Destruktor
		///
		~CMapObjectDescriptor();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda tworzy obiekt mapy
		///
		void create();

		///
		///Metoda zwraca nazwê znacznika obiektu na mapie
		///
		const std::string & GetCode() const;

		///
		///Metoda ustawia nazwê znacznika obiektu na mapie
		///
		///@param & code - nazwê znacznika - sta³a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca nazwê, któr¹ nadajemy obiektowi
		///
		const std::string & GetName() const;

		///
		///Metoda ustawia nazwê, któr¹ nadajemy obiektowi
		///
		///@param & name - nazwa, któr¹ nadajemy obiektowi - sta³a referencja na obiekt klasy std::string
		///
		void SetName(const std::string & name);

		///
		///Metoda zwraca wskaŸnik na wzorzec produkcyjny
		///
		PhysicalTemplate* GetTemplate() const;

		///
		///Metoda ustawia wskaŸnik na wzorzec produkcyjny
		///
		///@param *template_param - wskaŸnik na wzorzec produkcyjny
		///
		void SetTemplate(PhysicalTemplate* template_param);

		///
		///Metoda zwraca pozycjê obietu - sk³adowa X (plik xml operuje body)
		///
		const float GetXPosition() const;

		///
		///Metoda ustawia pozycjê obietu - sk³adowa X (plik xml operuje body)
		///
		///@param m_x_position - pozycja obiektu - sk³adowa X
		///
		void SetXPosition(float x_position);
	
		///
		///Metoda zwraca pozycjê obietu - sk³adowa Y (plik xml operuje body)
		///
		const float GetYPosition() const;

		///
		///Metoda ustawia pozycjê obietu - sk³adowa Y (plik xml operuje body)
		///
		///@param m_y_position - pozycja obiektu - sk³adowa Y
		///
		void SetYPosition(float y_position);

		///
		///Metoda zwraca obrót obiektu - body
		///
		const float GetRotationBody() const;

		///
		///Metoda ustawia obrót obiektu - body
		///
		///@param  - rotation_body wartoœæ obrotu
		///
		void SetRotationBody(float rotation_body);

		///
		///Metoda zwraca obrót obiektu - head
		///
		const float GetRotationHead() const;

		///
		///Metoda ustawia obrót obiektu - head
		///
		///@param rotation_head - wartoœæ obrotu
		///
		void SetRotationHead(float rotation_head);
		
		///
		///Metoda zwraca flaga filtru grafiki - smooth
		///
		const bool GetSmooth() const;
		
		///
		///Metoda ustawia flaga filtru grafiki - smooth
		///
		///@param smooth - filtr grafiki
		///
		void SetSmooth(bool smooth);

		inline const int GetUniqueId() const { return m_uniqueId; }

	private:

		std::string			m_code;				//nazwa obiektu fabrycznego (template) w pliku xml
        std::string			m_name;				//nazwa, któr¹ nadajemy obiektowi
        PhysicalTemplate*	p_templ;			//wskaŸnik na wzorzec produkcyjny
        float				m_x_position;		//sk³adowa pozycji x na mapie
        float				m_y_position;		//sk³adowa pozycji y na mapie
		float				m_rotation_body;	//wartoœæ obrotu pocz¹tkowego body
		float				m_rotation_head;	//wartoœæ obrotu pocz¹tkowego head
		int					m_uniqueId;			//unikalny indeks
		bool				m_smooth;			//flaga filtru grafiki - smooth
		static int			nextId;				//generator wartoœci unikalnej przy tworzeniu obiektu
    };

}//namespace mapengine
#endif //H_MAP_OBJECT_DESCRIPTOR_JACK
