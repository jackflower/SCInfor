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
	///Klasa reprezentuje opakowanie danych dla obiekt�w dekoracyjnych
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
		///Konstruktor kopiuj�cy
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
		///Metoda zwraca flag�, czy dany obiekt mam by� wczytywany, czy pomijany w przypadku wczytywania mapy
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
		float			m_x_position;	//sk�adowa pozycji x na mapie
		float			m_y_position;	//sk�adowa pozycji y na mapie
		float			m_scale;		//skalda
		float			m_rotation;		//warto�� obrotu
		int				m_zindex;		//warstwa, na kt�rej obiekt b�dzie renderowany
		int				m_uniqueId;		//unikalny indeks
		static int		nextId;			//generator warto�ci unikalnej przy towrzeniu obiektu
	};
}//namespace mapengine
#endif //H_DOODAH_DESCRIPTOR_JACK
