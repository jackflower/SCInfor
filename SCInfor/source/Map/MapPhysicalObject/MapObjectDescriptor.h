//  ________________________________________________
// | MapObjectDescriptor.h - class definition       |
// | Jack Flower April 2013                         |
// |________________________________________________|
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
    class MapObjectDescriptor
	{
		RTTI_DECL;

    public:

		///
		///Konstruktor
		///
		MapObjectDescriptor();

		///
		///Konstruktor kopiujący
		///
		///@param MapObjectDescriptorCopy - obiekt klasy MapObjectDescriptor
		///
		MapObjectDescriptor(const MapObjectDescriptor & MapObjectDescriptorCopy);

		///
		///Destruktor
		///
		~MapObjectDescriptor();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda tworzy obiekt mapy
		///
		void create();

		///
		///Metoda zwraca nazwę znacznika obiektu na mapie
		///
		const std::string & getCode() const;

		///
		///Metoda ustawia nazwę znacznika obiektu na mapie
		///
		///@param code - nazwę znacznika - stała referencja na obiekt klasy std::string
		///
		void setCode(const std::string & code);

		///
		///Metoda zwraca nazwę, którą nadajemy obiektowi
		///
		const std::string & getName() const;

		///
		///Metoda ustawia nazwę, którą nadajemy obiektowi
		///
		///@param name - nazwa, którą nadajemy obiektowi - stała referencja na obiekt klasy std::string
		///
		void setName(const std::string & name);

		///
		///Metoda zwraca wskaźnik na wzorzec produkcyjny
		///
		PhysicalTemplate *getTemplate() const;

		///
		///Metoda ustawia wskaźnik na wzorzec produkcyjny
		///
		///@param *template_param - wskaźnik na wzorzec produkcyjny
		///
		void setTemplate(PhysicalTemplate *template_param);

		///
		///Metoda zwraca pozycję obietu - składowa X (plik xml operuje body)
		///
		const float getXPosition() const;

		///
		///Metoda ustawia pozycję obietu - składowa X (plik xml operuje body)
		///
		///@param m_x_position - pozycja obiektu - składowa X
		///
		void setXPosition(float x_position);
	
		///
		///Metoda zwraca pozycję obietu - składowa Y (plik xml operuje body)
		///
		const float getYPosition() const;

		///
		///Metoda ustawia pozycję obietu - składowa Y (plik xml operuje body)
		///
		///@param m_y_position - pozycja obiektu - składowa Y
		///
		void setYPosition(float y_position);

		///
		///Metoda zwraca obrót obiektu - body
		///
		const float getRotationBody() const;

		///
		///Metoda ustawia obrót obiektu - body
		///
		///@param  - rotation_body wartość obrotu
		///
		void setRotationBody(float rotation_body);

		///
		///Metoda zwraca obrót obiektu - head
		///
		const float getRotationHead() const;

		///
		///Metoda ustawia obrót obiektu - head
		///
		///@param rotation_head - wartość obrotu
		///
		void setRotationHead(float rotation_head);
		
		///
		///Metoda zwraca flaga filtru grafiki - smooth
		///
		const bool getSmooth() const;
		
		///
		///Metoda ustawia flaga filtru grafiki - smooth
		///
		///@param smooth - filtr grafiki
		///
		void setSmooth(bool smooth);

		const int getUniqueId() const;

	private:

		std::string m_code; //nazwa obiektu fabrycznego (template) w pliku xml
        std::string m_name; //nazwa, którą nadajemy obiektowi
        PhysicalTemplate *p_templ; //wskaźnik na wzorzec produkcyjny
        float m_x_position; //składowa pozycji x na mapie
        float m_y_position; //składowa pozycji y na mapie
		float m_rotation_body; //wartość obrotu początkowego body
		float m_rotation_head; //wartość obrotu początkowego head
		int m_uniqueId; //unikalny indeks
		bool m_smooth; //flaga filtru grafiki - smooth
		static int nextId; //generator wartości unikalnej przy tworzeniu obiektu
    };

}//namespace mapengine
#endif //H_MAP_OBJECT_DESCRIPTOR_JACK
