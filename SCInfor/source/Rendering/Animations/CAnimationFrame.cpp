//  __________________________________________
// | CAnimationFrame.h - class implementation |
// | Jack Flower - March 2012                 |
// |__________________________________________|
//

#include "CAnimationFrame.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(CAnimationFrame);

		//Konstruktor domy�lny
		CAnimationFrame::CAnimationFrame(void)
		:
			m_texture_name	(),
			m_rectangle		(0,0,0,0)
		{
		}
		
		//Konstruktor paramtryczny
		CAnimationFrame::CAnimationFrame(const std::string& texture_name, const sf::IntRect& rectangle)
		:
			m_texture_name	(texture_name),
			m_rectangle		(rectangle)
		{
		}

		//Konstruktor kopiuj�cy
		CAnimationFrame::CAnimationFrame(const CAnimationFrame& CAnimationFrameCopy)
		:
			m_texture_name	(CAnimationFrameCopy.m_texture_name),
			m_rectangle		(CAnimationFrameCopy.m_rectangle)
		{
		}

		//Destruktor
		CAnimationFrame::~CAnimationFrame(void)
		{
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string CAnimationFrame::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca sta�� referencj� na nazw� tekstury
		const std::string& CAnimationFrame::GetTextureName() const
		{
			return m_texture_name;
		}

		//Metoda zwraca sta�� referencj� na prostok�tny obszar tekstury sf::IntRect
		const sf::IntRect& CAnimationFrame::GetImageRectangle() const
		{
			return m_rectangle;
		}
	}//namespace animation
}//namespace rendering