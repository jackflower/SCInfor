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
		///Klasa bazowa reprezentuje publiczny inreface dla obieków renderowalnych
		///
		class IDrawable
		{
			RTTI_DECL;

		public:
			
			///
			///Konstruktor domyœlny
			///
			IDrawable();

			///
			///Konstruktor kopiuj¹cy
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
			///Metoda zwraca flagê, czy obiekt mo¿na rysowaæ
			///
			const bool getCanDraw() const;

			///
			///Metoda ustawia flagê, czy obiekt mo¿na rysowaæ
			///
			///@param can_draw - flaga, czy obiekt mo¿na rysowaæ
			///
			const void setCanDraw(bool can_draw);

			///
			///Metoda zwraca flagê, czy obiekt jest widoczny
			///
			const bool getVisible() const;

			///
			///Metoda ustawia flagê, czy obiekt jest widoczny
			///
			///@param visible - flaga, czy obiekt ma byæ widoczny
			///
			const void setVisible(bool visible);

			///
			///Metoda zwraca indeks warstwy, na której ma byæ renderowany obiekt
			///
			const int GetLayerIndex() const;

			///
			///Metoda ustawia indeks warstwy, na której ma byæ renderowany obiekt
			///
			///@param layer_index - indeks warstwy, na której ma byæ renderowany obiekt
			///
			const void SetLayerIndex(int layer_index);

			///
			///Witrualna abstrakcyjna metoda renderuj¹ca - interfejs
			///
			///@param *renderWindow - wskaŸnik na okno renderingu
			///
			virtual void draw(sf::RenderWindow* renderWindow) = 0;

		protected:

			bool	m_can_draw;	//flaga okreœlaj¹cy, czy mo¿na rysowaæ ten obiekt
								//pod modyfikatorem protected:
								//aby klasy bazowe implementuj¹ce wirtualn¹ metodê
								//virtual void draw(sf::RenderWindow* renderWindow) = 0;
								//mog³y w zale¿noœci od tego pola zarz¹dzaæ rysowaniem obiektów

		private:

			///
			///Deklaracja przyjaŸni (klasa CDrawableManager jest przyjacielem tej klasy)
			///
			friend class CDrawableManager;

			bool	m_visible;				//flaga okreœlajaca, czy obiekt jest widoczny
			int		m_layer_index;			//indeks warstwy, na której ma byæ renderowany obiekt
			int		m_layer_vector_index;	//indeks w kontenerze, okreœlaj¹cy, czy obiekt znajduje siê na prawid³owej warstwie
		    
		};
	}//using  namespace drawable;
}//namespace rendering
#endif //H_IDRAWABLE_JACK
