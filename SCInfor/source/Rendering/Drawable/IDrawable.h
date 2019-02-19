//  _________________________________________
// | IDrawable.h - interface defition        |
// | Jack Flower - August 2012               |
// |_________________________________________|
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
		///Klasa bazowa reprezentuje publiczny inreface dla obiek�w renderowalnych
		///
		class IDrawable
		{
			RTTI_DECL;

		public:
			
			///
			///Konstruktor domy�lny
			///
			IDrawable();

			///
			///Konstruktor kopiuj�cy
			///
			///@param IDrawableCopy - obiekt klasy IDrawable
			///
			IDrawable(const IDrawable& IDrawableCopy);

			///
			///Wirtualny destruktor
			///
			virtual ~IDrawable();

			///
			///Metoda zwraca typ obiektu /RTTI/
			///
			const std::string GetType() const;

			///
			///Metoda zwraca flag�, czy obiekt mo�na rysowa�
			///
			const bool getCanDraw() const;

			///
			///Metoda ustawia flag�, czy obiekt mo�na rysowa�
			///
			///@param can_draw - flaga, czy obiekt mo�na rysowa�
			///
			const void setCanDraw(bool can_draw);

			///
			///Metoda zwraca flag�, czy obiekt jest widoczny
			///
			const bool getVisible() const;

			///
			///Metoda ustawia flag�, czy obiekt jest widoczny
			///
			///@param visible - flaga, czy obiekt ma by� widoczny
			///
			const void setVisible(bool visible);

			///
			///Metoda zwraca indeks warstwy, na kt�rej ma by� renderowany obiekt
			///
			const int GetLayerIndex() const;

			///
			///Metoda ustawia indeks warstwy, na kt�rej ma by� renderowany obiekt
			///
			///@param layer_index - indeks warstwy, na kt�rej ma by� renderowany obiekt
			///
			const void SetLayerIndex(int layer_index);

			///
			///Witrualna abstrakcyjna metoda renderuj�ca - interfejs
			///
			///@param *renderWindow - wska�nik na okno renderingu
			///
			virtual void draw(sf::RenderWindow* renderWindow) = 0;

		protected:

			bool	m_can_draw;	//flaga okre�laj�cy, czy mo�na rysowa� ten obiekt
								//pod modyfikatorem protected:
								//aby klasy bazowe implementuj�ce wirtualn� metod�
								//virtual void draw(sf::RenderWindow* renderWindow) = 0;
								//mog�y w zale�no�ci od tego pola zarz�dza� rysowaniem obiekt�w

		private:

			///
			///Deklaracja przyja�ni (klasa CDrawableManager jest przyjacielem tej klasy)
			///
			friend class CDrawableManager;

			bool	m_visible;				//flaga okre�lajaca, czy obiekt jest widoczny
			int		m_layer_index;			//indeks warstwy, na kt�rej ma by� renderowany obiekt
			int		m_layer_vector_index;	//indeks w kontenerze, okre�laj�cy, czy obiekt znajduje si� na prawid�owej warstwie
		    
		};
	}//using  namespace drawable;
}//namespace rendering
#endif //H_IDRAWABLE_JACK
