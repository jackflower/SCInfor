//  ______________________________________________
// | CDoodahDescriptor.h - class definition       |
// | Jack Flower April 2013                       |
// |______________________________________________|
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
	class CDoodahDescriptor
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CDoodahDescriptor();

		///
		///Konstruktor kopiuj¹cy
		///
		///@param &CDoodahDescriptorCopy - obiekt klasy CDoodahDescriptor
		///
		CDoodahDescriptor(const CDoodahDescriptor& CDoodahDescriptorCopy);

		///
		///Destruktor
		///
		~CDoodahDescriptor();

		///
		///Metoda tworzy obiekt mapy
		///
		void Create();

		///
		///Metoda zwraca flagê, czy dany obiekt mam byæ wczytywany, czy pomijany w przypadku wczytywania mapy
		///
        bool CoreMapObject() const  { return false; }

		//metody pomocnicze - hermetyzacja
		inline const std::string GetFileName() const { return m_file_name; }
		inline void SetFileName(const std::string& file_name) { m_file_name = file_name; }
		inline const std::string GetAnimationName() const { return m_anim; }
		inline void SetAnimationName(const std::string& anima) { m_anim = anima; }
		inline const float GetXPosition() const { return m_x_position; }
		inline void SetXPosition(float x_parameter) { m_x_position = x_parameter; }
		inline const float GetYPosition() const { return m_y_position; }
		inline void SetYPosition(float y_parameter) { m_y_position = y_parameter; }
		inline const float GetScale() const { return m_scale; }
		inline void SetScale(float scale) { m_scale = scale; }
		inline const float GetRotation() const { return m_rotation; }
		inline void SetRotation(float rotation) { m_rotation = rotation; }
		inline const int GetZIndex() const { return m_zindex; }
		inline void SetZIndex(int zindex) { m_zindex = zindex; }
		inline const int GetUniqueId() const { return m_uniqueId; }

	private:

		std::string		m_file_name;	//nazwa pliku
        std::string		m_anim;			//nazwa animacji
		float			m_x_position;	//sk³adowa pozycji x na mapie
		float			m_y_position;	//sk³adowa pozycji y na mapie
		float			m_scale;		//skalda
		float			m_rotation;		//wartoœæ obrotu
		int				m_zindex;		//warstwa, na której obiekt bêdzie renderowany
		int				m_uniqueId;		//unikalny indeks
		static int		nextId;			//generator wartoœci unikalnej przy towrzeniu obiektu
	};
}//namespace mapengine
#endif //H_DOODAH_DESCRIPTOR_JACK
