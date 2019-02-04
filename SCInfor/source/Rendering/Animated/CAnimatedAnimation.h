//  _______________________________________________
// | CAnimatedAnimation.h - class definition       |
// | Jack Flower - March 2009                      |
// | update May 2017                               |
// |_______________________________________________|
//

#ifndef H_ANIMATED_ANIMATION_JACK
#define H_ANIMATED_ANIMATION_JACK

#include "CAnimatedFrame.h"
#include <vector>

namespace animated
{

	///
	///Klasa reprezentuje animacj�
	///
	class CAnimatedAnimation
	{
	public:

		///
		///Konstruktor domy�lny
		///
		CAnimatedAnimation(void);

		///
		///Konstruktor parametryczny
		///
		///@param texture - tekstura
		///
		///@param width_frame - szeroko�� klatki animacji
		///
		///@param height_frame - wysoko�� klatki animacji
		///
		CAnimatedAnimation(const sf::Texture & texture, int width_frame, int height_frame);

		///
		///Konstruktor kopiuj�cy
		///
		///@param & copy - sta�a referencja na obiekt klasy CAnimatedAnimation
		///
		CAnimatedAnimation(const CAnimatedAnimation & copy);

		///
		///Destruktor
		///
		virtual ~CAnimatedAnimation(void);

		///
		///Metoda zwraca ilo�� obiek�w klasy CAnimFrame w wektorze
		///
		unsigned int Size() const;

		///
		///Deklaracja operatora dla obiektu klasy CAnimatedFrame
		///
		CAnimatedFrame & operator [] (unsigned N);

		///
		///Metoda dodaje do wektora obiekty klasy CAnimFrame
		///
		///@param texture - tekstura
		///
		///@param width_frame - szeroko�� klatki animacji
		///
		///@param height_frame - wysoko�� klatki animacji
		///
		bool SetAnimationFramesFromAtlasTexture(const sf::Texture & texture, int width_frame, int height_frame);

		///
		///Metoda dodaje do wektora obiekt klasy CAnimFrame
		///
		///@param & texture - tekstura
		///
		///@param & rectangle - obszar prostok�tny
		///
		void SetSingleAnimationFrameTexture(const sf::Texture & texture, const sf::IntRect & rectangle );

		///
		///Metoda usuwa z wektora obiekt klasy CAnimFrame o podanym indeksie
		///
		///@param index - indeks klatki do usuni�cia
		///
		void DeleteAnimFrame(int index);

		///
		///Metoda usuwa z wektora wszystkie elementy
		///
		void ClearAllAnimFrame();
	
		///
		///Metoda zwraca z wektora szeroko�� klatki animacji o podanym indeksie
		///
		///@param animframe_index - indeks klatki animacji
		///
		int const GetAnimFrameWidth(int animframe_index);
	
		///
		///Metoda zwraca z wektora wysoko�� klatki animacji o podanym indeksie
		///
		///@param animframe_index - indeks klatki animacji
		///
		int const GetAnimFrameHeight(int animframe_index);

	private:

		std::vector<CAnimatedFrame> m_frame; //kontener na klatki animacji

		//metoda wstawia do wektora pojedynczy obiekt klasy CAnimatedFrame
		void pushFrame(const CAnimatedFrame & new_frame);
	};
}//namespace animated
#endif //H_ANIMATED_ANIMATION_JACK
