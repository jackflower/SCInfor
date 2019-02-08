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
	///Klasa reprezentuje opakowanie danych dla obiekt�w (physicals),
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
		///Konstruktor kopiuj�cy
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
		///Metoda zwraca nazw� znacznika obiektu na mapie
		///
		const std::string & GetCode() const;

		///
		///Metoda ustawia nazw� znacznika obiektu na mapie
		///
		///@param & code - nazw� znacznika - sta�a referencja na obiekt klasy std::string
		///
		void SetCode(const std::string & code);

		///
		///Metoda zwraca nazw�, kt�r� nadajemy obiektowi
		///
		const std::string & GetName() const;

		///
		///Metoda ustawia nazw�, kt�r� nadajemy obiektowi
		///
		///@param & name - nazwa, kt�r� nadajemy obiektowi - sta�a referencja na obiekt klasy std::string
		///
		void SetName(const std::string & name);

		///
		///Metoda zwraca wska�nik na wzorzec produkcyjny
		///
		PhysicalTemplate* GetTemplate() const;

		///
		///Metoda ustawia wska�nik na wzorzec produkcyjny
		///
		///@param *template_param - wska�nik na wzorzec produkcyjny
		///
		void SetTemplate(PhysicalTemplate* template_param);

		///
		///Metoda zwraca pozycj� obietu - sk�adowa X (plik xml operuje body)
		///
		const float GetXPosition() const;

		///
		///Metoda ustawia pozycj� obietu - sk�adowa X (plik xml operuje body)
		///
		///@param m_x_position - pozycja obiektu - sk�adowa X
		///
		void SetXPosition(float x_position);
	
		///
		///Metoda zwraca pozycj� obietu - sk�adowa Y (plik xml operuje body)
		///
		const float GetYPosition() const;

		///
		///Metoda ustawia pozycj� obietu - sk�adowa Y (plik xml operuje body)
		///
		///@param m_y_position - pozycja obiektu - sk�adowa Y
		///
		void SetYPosition(float y_position);

		///
		///Metoda zwraca obr�t obiektu - body
		///
		const float GetRotationBody() const;

		///
		///Metoda ustawia obr�t obiektu - body
		///
		///@param  - rotation_body warto�� obrotu
		///
		void SetRotationBody(float rotation_body);

		///
		///Metoda zwraca obr�t obiektu - head
		///
		const float GetRotationHead() const;

		///
		///Metoda ustawia obr�t obiektu - head
		///
		///@param rotation_head - warto�� obrotu
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
        std::string			m_name;				//nazwa, kt�r� nadajemy obiektowi
        PhysicalTemplate*	p_templ;			//wska�nik na wzorzec produkcyjny
        float				m_x_position;		//sk�adowa pozycji x na mapie
        float				m_y_position;		//sk�adowa pozycji y na mapie
		float				m_rotation_body;	//warto�� obrotu pocz�tkowego body
		float				m_rotation_head;	//warto�� obrotu pocz�tkowego head
		int					m_uniqueId;			//unikalny indeks
		bool				m_smooth;			//flaga filtru grafiki - smooth
		static int			nextId;				//generator warto�ci unikalnej przy tworzeniu obiektu
    };

}//namespace mapengine
#endif //H_MAP_OBJECT_DESCRIPTOR_JACK
