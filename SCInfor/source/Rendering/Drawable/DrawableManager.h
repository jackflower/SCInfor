//  ____________________________________________
// | DrawableManager.h - class definition       |
// | Jack Flower - August 2012                  |
// |____________________________________________|
//

#ifndef H_DRAWABLE_MANAGER_JACK
#define H_DRAWABLE_MANAGER_JACK

#include <vector>
#include "../../Game/Listener/IFrameListener.h"
#include "../../Utilities/Singleton/CSingleton.h"
#include "Layers.h"

///
///Forward declaration
///
namespace sf
{
	class RenderWindow;
}

///
///Forward declaration
///
namespace rendering
{
	namespace drawable
	{
		class Drawable;
	}
	namespace displayable
	{
		class Displayable;
		class HudStaticText;
	}
	namespace primitives
	{
		class Rectangle;
	}
}

using namespace sf;
using namespace listener;
using namespace rendering::displayable;
using namespace rendering::primitives;

#define gDrawableManager DrawableManager::GetSingleton()

namespace rendering
{
	namespace drawable
	{

		//Funkcja pomocnicza - sprawdza, czy indeks warstwy jest poprawny
		bool isCorrectZIndex(int z_index);

		///
		///Klasa reprezentuje kontener wraz z funkcjonalnością na obiekty rysowalne
		///
		class DrawableManager: public CSingleton<DrawableManager>, IFrameListener
		{

		public:

			///
			///Konstruktor domyślny
			///
			DrawableManager();

			///
			///Destruktor
			///
			~DrawableManager();

			///
			///Metoda tworzy obiekt klasy Displayable i zwraca wskaźnik na ten obiekt
			///
			///@param z_index - warstwa renderingu
			///
			Displayable *createDisplayable(int z_index = Z_PHYSICAL_BODY);

			///
			///Metoda tworzy obiekt klasy Rectangle i zwraca wskaźnik na ten obiekt
			///
			///@param z_index - warstwa renderingu
			///
			Rectangle *createRectangle(int z_index = Z_PHYSICAL_INFO_STATUS_BAR);

			///
			///Metoda tworzy obiekt klasy HudStaticText i zwraca wskaźnik na ten obiekt
			///
			///@param z_index - warstwa renderingu
			///
			HudStaticText *createHudStaticText(int z_index = Z_INFORMATION_FRONT);

			///
			///Metoda rejestruje obiekt
			///
			///@param *drawable - wskaźnik na obiekt klasy Drawable
			///
			///@param z_index - indeks warstwy renderingu
			///
			void registerDrawable(Drawable *drawable, int z_index);

			///
			///Metoda wyrejstrowuje obiekt - bez usuwania
			///
			///@param *drawable - wskaźnik na obiekt klasy Drawable
			///
			void unregisterDrawable(Drawable *drawable);

			///
			///Metoda usuwa obiekt z kontenera
			///
			///@param *drawable - wskaźnik na interfejs Drawable
			///
			void destroyDrawable(Drawable *drawable);

			///
			///Wirtualna metoda aktualizująca obiekty w kontenerze
			///
			///@param secondsPassed - czas
			///
			virtual void frameStarted(float secondsPassed) {};

			///
			///Metoda renderująca obiekt klasy Displayable
			///
			///Metoda void DrawFrame(sf::RenderWindow* render);
			///
			///wywołuje w kontenerze ich metody wirtualne
			///
			///virtual draw(sf::RenderWindow* render);
			///
			///@render render - parametr drawable
			///
			void drawFrame(sf::RenderWindow * render = NULL);

			///
			///Wirtualny interfejs - implementacja
			///
			virtual void cleanup();

		private:

			typedef std::vector<Drawable*> DrawableList; //kontener (vector)
			typedef std::vector<DrawableList> DrawableLists; //kontener (vector) kontenerów (wektorów)

			DrawableLists m_layers; //wektor przechowujący wektory
		};
	}//namespace drawable
}//namespace rendering
#endif //H_DRAWABLE_MANAGER_JACK
