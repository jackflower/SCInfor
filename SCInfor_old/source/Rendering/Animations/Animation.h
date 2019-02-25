//  ______________________________________
// | Animation.h - class definition       |
// | Jack Flower - March 2012             |
// |______________________________________|
// 

#ifndef H_ANIMATION_JACK
#define H_ANIMATION_JACK

#include <vector>
#include "TimedAnimationFrame.h"
#include "../../RTTI/RTTI.h"

namespace rendering
{
	namespace animation
	{
		///
		///Klasa reprezentuje pojemnik na animacje
		///
		class Animation
		{
			RTTI_DECL;

		public:

			///
			///Konstruktor domyślny
			///
			Animation();

			///
			///Konstruktor kopiujący
			///
			///@param AnimationCopy - parametr - obiekt klasy Animation
			///
			Animation(const Animation & AnimationCopy);

			///
			///Konstruktor przenoszący
			///
			///@param other = referencja do r-wartości
			///
			Animation(Animation && other);

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param copy - stała referencja na obiekt klasy Animation
			///
			Animation & operator=(const Animation & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param other -  referencja do r-wartości
			///
			Animation & operator=(Animation && other);

			///
			///Destruktor
			///
			~Animation();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca referencję na nazwę animacji
			///
			const std::string & getAnimationName() const;

			///
			///Metoda ustawia na nazwę animacji
			///
			///@param name - nazwa animacji - stała referencja na obiekt klasy std::string
			///
			const void setAnimationName(const std::string & anim_name);

			///
			///Metoda zwraca czas równy całkowitej długości trwania wszystkich klatek animacji (kumulacja)
			///
			float totalLength();

		private:

			std::string m_animation_name; //nazwa animacji

		public:

			std::vector<TimedAnimationFrame> m_frames;	//wektor przechowujący klatki animacji
		};
	}//namespace animation
}//namespace rendering
#endif//H_ANIMATION_JACK
