//  ___________________________________________________
// | NameAnimPairTranslator.cpp - class implementation |
// | Jack Flower - March 2012                          |
// |___________________________________________________|
//

#include "NameAnimPairTranslator.h"
#include "Animation.h"

namespace rendering
{
	namespace animation
	{
		RTTI_IMPL_NOPARENT(NameAnimPairTranslator);

		//Konstruktor domyślny
		NameAnimPairTranslator::NameAnimPairTranslator(void)
		:
			m_animation_name(""),
			p_animation(nullptr),
			m_is_ready(false)
		{
		}
		
		//Konstruktor kopiujący
		NameAnimPairTranslator::NameAnimPairTranslator(const NameAnimPairTranslator & NameAnimPairTranslatorCopy)
		:
			m_animation_name(NameAnimPairTranslatorCopy.m_animation_name),
			p_animation(NameAnimPairTranslatorCopy.p_animation),
			m_is_ready(NameAnimPairTranslatorCopy.m_is_ready)
		{
		}

		//Konstruktor przenoszący
		NameAnimPairTranslator::NameAnimPairTranslator(NameAnimPairTranslator && other)
		:
			m_animation_name(other.m_animation_name),
			p_animation(other.p_animation),
			m_is_ready(other.m_is_ready)
		{
			//zerujemy składowe obiektu źródłowego...
			other.m_animation_name = "";
			other.m_is_ready = false;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_animation = nullptr;
		}

		//Konstruktor parametryczny
		NameAnimPairTranslator::NameAnimPairTranslator(const std::string & animation_name)
		:
			m_animation_name(animation_name),
			p_animation(nullptr),
			m_is_ready(false)
		{
		}

		//Destruktor
		NameAnimPairTranslator::~NameAnimPairTranslator(void)
		{
			m_animation_name = "";
			p_animation = nullptr;
			m_is_ready = false;
		}

		//Przeciążony operator przypisania kopiowania
		NameAnimPairTranslator & NameAnimPairTranslator::operator=(const NameAnimPairTranslator & copy)
		{
			if (this != &copy)
			{
				m_animation_name = copy.m_animation_name;
				m_is_ready = copy.m_is_ready;

				//zwalaniamy dane pod wskaźnikiem
				delete p_animation;
				//tworzymy nowy obiekt na podstawie obiektu źródłowego
				p_animation = new Animation(*copy.p_animation);
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		NameAnimPairTranslator & NameAnimPairTranslator::operator=(NameAnimPairTranslator && other)
		{
			if (this != & other)
			{
				m_animation_name = other.m_animation_name;
				m_is_ready = other.m_is_ready;

				//zwalaniamy dane pod wskaźnikiem
				delete p_animation;
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				p_animation = other.p_animation;
				//zwalniamy wskaźnik na dane obiektu źródłowego tak,
				//aby destruktor nie zwalniał pamięci wielokrotnie
				other.p_animation = nullptr;

				//zerowanie obiektu źródłowego
				other.m_animation_name = "";
				other.m_is_ready = false;
			}
			return *this;
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string NameAnimPairTranslator::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca wskaźnik na animację
		Animation *NameAnimPairTranslator::getAnimation() const
		{
			return p_animation;
		}

		//Metoda wstawia animację do słownika
		void NameAnimPairTranslator::setAnimation(Animation *p_anim)
		{
			p_animation = p_anim;
			m_is_ready = true;
		}

		//Metoda zwraca referencję na nazwę animacji
		std::string & NameAnimPairTranslator::getAnimationName()
		{
			return m_animation_name;
		}

		//Metoda zwraca flagę, czy obiekt jest gotowy do użycia
		const bool NameAnimPairTranslator::getReady() const
		{
			return m_is_ready;
		}

	}//namespace animation
}//namespace rendering
