//  _________________________________________
// | AnimationFrame.h - class implementation |
// | Jack Flower - March 2012                |
// |_________________________________________|
//

#include "AnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(AnimationFrame);

		//Konstruktor domyślny
		AnimationFrame::AnimationFrame()
			:
			m_texture_name(),
			m_rectangle(0, 0, 0, 0)
		{
		}

		//Konstruktor paramtryczny
		AnimationFrame::AnimationFrame(const std::string & texture_name, const sf::IntRect & rectangle)
			:
			m_texture_name(texture_name),
			m_rectangle(rectangle)
		{
		}

		//Konstruktor kopiujący
		AnimationFrame::AnimationFrame(const AnimationFrame & AnimationFrameCopy)
			:
			m_texture_name(AnimationFrameCopy.m_texture_name),
			m_rectangle(AnimationFrameCopy.m_rectangle)
		{
		}

		//Konstruktor przenoszący
		AnimationFrame::AnimationFrame(AnimationFrame && other)
		:
			m_texture_name(""),
			m_rectangle()
		{
			// kopiujemy dane z obiektu źródłowego
			m_texture_name = other.m_texture_name;
			m_rectangle = other.m_rectangle;
			//zwalniamy obiekt źródłowy
			other.m_texture_name = "";
			other.m_rectangle.left = 0;
			other.m_rectangle.top = 0;
			other.m_rectangle.width = 0;
			other.m_rectangle.height = 0;
		}

		//Przeciążony operator przypisania kopiowania
		AnimationFrame & AnimationFrame::operator=(const AnimationFrame & copy)
		{
			if (this != &copy)
			{
				//zwalniamy dane pod wskaźnikiem
				//	delete p_pointer;
				//tworzymy nowy obiekt
				//	p_texture = new Object();

				//kopiujemy dane z obiektu źródłowego
				m_texture_name = copy.m_texture_name;
				m_rectangle = copy.m_rectangle;
			}
			return *this;
		}

		///
		///Przeciążony operator przypisania przenoszenia
		///
		///@param other -  referencja do r-wartości
		///
		AnimationFrame & AnimationFrame::operator=(AnimationFrame && other)
		{
			if (this != & other)
			{
				//zwalniamy dane pod wskaźnikiem
				//delete p_pointer;
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				//p_pointer = other.p_pointer;

				//kopiujemy dane z obiektu źródłowego
				m_texture_name = other.m_texture_name;
				m_rectangle = other.m_rectangle;

				//zwalniamy wskaźnik na dane obiektu źródłowego tak,
				//aby destruktor nie zwalniał pamięci wielokrotnie
				//zerowanie obiektu źródłowego
				//other.p_pointer = nullptr;

				//zwalniamy obiekt źródłowy
				other.m_texture_name = "";
				other.m_rectangle.left = 0;
				other.m_rectangle.top = 0;
				other.m_rectangle.width = 0;
				other.m_rectangle.height = 0;
			}
			return *this;
		}

		//Destruktor
		AnimationFrame::~AnimationFrame()
		{
			m_texture_name = "";
			m_rectangle.left = 0;
			m_rectangle.top = 0;
			m_rectangle.width = 0;
			m_rectangle.height = 0;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string AnimationFrame::getType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca stałą referencję na nazwę tekstury
		const std::string & AnimationFrame::getTextureName() const
		{
			return m_texture_name;
		}

		//Metoda ustawia nazwę tekstury std::string
		void AnimationFrame::setTextureName(const std::string & texture_name)
		{
			m_texture_name = texture_name;
		}

		//Metoda zwraca stałą referencję na prostokątny obszar tekstury sf::IntRect
		const sf::IntRect & AnimationFrame::getImageRectangle() const
		{
			return m_rectangle;
		}
	}//namespace animation
}//namespace rendering
