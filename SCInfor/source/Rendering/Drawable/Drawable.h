//  ________________________________________
// | Drawable.h - interface defition        |
// | Jack Flower - August 2012              |
// |________________________________________|
// 

#ifndef H_IDRAWABLE_JACK
#define H_IDRAWABLE_JACK

#include "../../RTTI/RTTI.h"

namespace sf
{
	///
	///Forward declaration
	///
    class RenderWindow;
}
namespace rendering
{
	namespace drawable
	{
		///
		///Klasa bazowa reprezentuje publiczny inreface dla obieków renderowalnych
		///
		class Drawable
		{
			RTTI_DECL;

		public:
			
			///
			///Konstruktor domyślny
			///
			Drawable();

			///
			///Konstruktor kopiujący
			///
			///@param DrawableCopy - obiekt klasy Drawable
			///
			Drawable(const Drawable & DrawableCopy);

			///
			///Wirtualny destruktor
			///
			virtual ~Drawable();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string getType() const;

			///
			///Metoda zwraca flagę, czy obiekt można rysować
			///
			const bool getCanDraw() const;

			///
			///Metoda ustawia flagę, czy obiekt można rysować
			///
			///@param can_draw - flaga, czy obiekt można rysować
			///
			const void setCanDraw(bool can_draw);

			///
			///Metoda zwraca flagę, czy obiekt jest widoczny
			///
			const bool getVisible() const;

			///
			///Metoda ustawia flagę, czy obiekt jest widoczny
			///
			///@param visible - flaga, czy obiekt ma być widoczny
			///
			const void setVisible(bool visible);

			///
			///Metoda zwraca indeks warstwy, na której ma być renderowany obiekt
			///
			const int getLayerIndex() const;

			///
			///Metoda ustawia indeks warstwy, na której ma być renderowany obiekt
			///
			///@param layer_index - indeks warstwy, na której ma być renderowany obiekt
			///
			const void setLayerIndex(int layer_index);

			///
			///Witrualna abstrakcyjna metoda renderująca - interfejs
			///
			///@param *renderWindow - wskaźnik na okno renderingu
			///
			virtual void draw(sf::RenderWindow *renderWindow) = 0;

		protected:

			bool	m_can_draw;	//flaga określający, czy można rysować ten obiekt
								//pod modyfikatorem protected:
								//aby klasy bazowe implementujące wirtualną metodę
								//virtual void draw(sf::RenderWindow* renderWindow) = 0;
								//mogły w zależności od tego pola zarządzać rysowaniem obiektów

		private:

			///
			///Deklaracja przyjaźni (klasa DrawableManager jest przyjacielem tej klasy)
			///
			friend class DrawableManager;

			bool m_visible; //flaga określajaca, czy obiekt jest widoczny
			int	m_layer_index; //indeks warstwy, na której ma być renderowany obiekt
			int	m_layer_vector_index; //indeks w kontenerze, określający, czy obiekt znajduje się na prawidłowej warstwie
		    
		};
	}//using  namespace drawable;
}//namespace rendering
#endif //H_IDRAWABLE_JACK
