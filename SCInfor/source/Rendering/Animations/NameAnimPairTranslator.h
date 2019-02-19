//  ___________________________________________________
// | NameAnimPairTranslator.h - class definition       |
// | Jack Flower - March 2012                          |
// |___________________________________________________|
//

#ifndef H_NAME_ANIM_PAIR_TRANSLATOR_JACK
#define H_NAME_ANIM_PAIR_TRANSLATOR_JACK

#include <string>
#include "../../RTTI/RTTI.h"

namespace rendering
{
	namespace animation
	{
		///
		///Forward declaration
		///
		class Animation;

		///
		///Klasa reprezentuje mechanizm zamiany nazwy animacji na jej wskaźnik
		///
		class NameAnimPairTranslator
		{
			RTTI_DECL;

		public:
			
			///
			///Konstruktor domyślny
			///
			NameAnimPairTranslator(void);

			///
			///Konstruktor kopiujący
			///
			///@param NameAnimPairTranslatorCopy - parametr - obiekt klasy NameAnimPairTranslator
			///
			NameAnimPairTranslator(const NameAnimPairTranslator & NameAnimPairTranslatorCopy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			NameAnimPairTranslator(NameAnimPairTranslator && other);

			///
			///Konstruktor parametryczny
			///
			///@param m_animation_name - stała referencja na nazwę animacji
			///
			NameAnimPairTranslator(const std::string & animation_name);
			
			///
			///Destruktor
			///
			~NameAnimPairTranslator(void);

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy NameAnimPairTranslator
			///
			NameAnimPairTranslator & operator=(const NameAnimPairTranslator & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			NameAnimPairTranslator & operator=(NameAnimPairTranslator && other);

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca wskaźnik na animację
			///
			Animation *getAnimation() const;

			///
			///Metoda wstawia animację do słownika
			///
			///@param *p_anim - wskaźnik na animację
			///
			void setAnimation(Animation *p_anim);

			///
			///Metoda zwraca referencję na nazwę animacji
			///
			std::string & getAnimationName();

			///
			///Metoda zwraca flagę, czy obiekt jest gotowy do użycia
			///
			const bool getReady() const;

		private:

			std::string m_animation_name; //nazwa animacji
			Animation *p_animation; //wskaźnik na animację
			bool m_is_ready; //flaga, czy wskaźnik
							 //na animację (p_animation) jest zainicjowany,
						     //czy animacja jest gotowa do użycia
		};
	}//namespace animation
}//namespace rendering
#endif //H_NAME_ANIM_PAIR_TRANSLATOR_JACK
