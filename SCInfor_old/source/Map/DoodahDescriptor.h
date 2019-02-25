//  _____________________________________________
// | DoodahDescriptor.h - class definition       |
// | Jack Flower April 2013                      |
// |_____________________________________________|
//

#ifndef H_DOODAH_DESCRIPTOR_JACK
#define H_DOODAH_DESCRIPTOR_JACK

#include <string>
#include "../RTTI/RTTI.h"

namespace mapengine
{
	///
	///Klasa reprezentuje opakowanie danych dla obiektów dekoracyjnych
	///umieszczonych na mapie (wczytywane z xml)
	///
	class DoodahDescriptor
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		DoodahDescriptor();

		///
		///Konstruktor kopiujący
		///
		///@param DoodahDescriptorCopy - obiekt klasy DoodahDescriptor
		///
		DoodahDescriptor(const DoodahDescriptor & DoodahDescriptorCopy);

		///
		///Destruktor
		///
		~DoodahDescriptor();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda tworzy obiekt mapy
		///
		void create();

		///
		///Metoda zwraca flagę, czy dany obiekt mam być wczytywany, czy pomijany w przypadku wczytywania mapy
		///
        bool coreMapObject() const
		{
			return false;
		}

		//metody pomocnicze - hermetyzacja
		inline const std::string getFileName() const { return m_file_name; }
		inline void setFileName(const std::string& file_name) { m_file_name = file_name; }
		inline const std::string getAnimationName() const { return m_anim; }
		inline void setAnimationName(const std::string& anima) { m_anim = anima; }
		inline const float getXPosition() const { return m_x_position; }
		inline void setXPosition(float x_parameter) { m_x_position = x_parameter; }
		inline const float getYPosition() const { return m_y_position; }
		inline void setYPosition(float y_parameter) { m_y_position = y_parameter; }
		inline const float getScale() const { return m_scale; }
		inline void setScale(float scale) { m_scale = scale; }
		inline const float getRotation() const { return m_rotation; }
		inline void setRotation(float rotation) { m_rotation = rotation; }
		inline const int getZIndex() const { return m_zindex; }
		inline void setZIndex(int zindex) { m_zindex = zindex; }
		inline const int getUniqueId() const { return m_uniqueId; }

	private:

		std::string m_file_name; //nazwa pliku
        std::string m_anim; //nazwa animacji
		float m_x_position;	//składowa pozycji x na mapie
		float m_y_position;	//składowa pozycji y na mapie
		float m_scale; //skalda
		float m_rotation; //wartość obrotu
		int m_zindex; //warstwa, na której obiekt będzie renderowany
		int m_uniqueId; //unikalny indeks
		static int nextId; //generator wartości unikalnej przy towrzeniu obiektu
	};
}//namespace mapengine
#endif //H_DOODAH_DESCRIPTOR_JACK
