//  _____________________________________________
// | CDrawableManager.h - class definition       |
// | Jack Flower - August 2012                   |
// |_____________________________________________|
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
		class IDrawable;
	}
	namespace displayable
	{
		class CDisplayable;
		class CHudStaticText;
	}
	namespace primitives
	{
		class CRectangle;
	}
}

using namespace sf;
using namespace listener;
using namespace rendering::displayable;
using namespace rendering::primitives;

#define gDrawableManager CDrawableManager::GetSingleton()

namespace rendering
{
	namespace drawable
	{

		//Funkcja pomocnicza - sprawdza, czy indeks warstwy jest poprawny
		bool IsCorrectZIndex(int z_index);

		///
		///Klasa reprezentuje kontener wraz z funkcjonalnoúciπ na obiekty rysowalne
		///
		class CDrawableManager: public CSingleton<CDrawableManager>, IFrameListener
		{

		public:

			///
			///Konstruktor domyúlny
			///
			CDrawableManager();

			///
			///Destruktor
			///
			~CDrawableManager();

			///
			///Metoda tworzy obiekt klasy CDisplayable i zwraca wskaünik na ten obiekt
			///
			///@param z_index - warstwa renderingu
			///
			CDisplayable* CreateDisplayable(int z_index = Z_PHYSICAL_BODY);

			///
			///Metoda tworzy obiekt klasy CRectangle i zwraca wskaünik na ten obiekt
			///
			///@param z_index - warstwa renderingu
			///
			CRectangle* CreateRectangle(int z_index = Z_PHYSICAL_INFO_STATUS_BAR);

			///
			///Metoda tworzy obiekt klasy CHudStaticText i zwraca wskaünik na ten obiekt
			///
			///@param z_index - warstwa renderingu
			///
			CHudStaticText* CreateHudStaticText(int z_index = Z_INFORMATION_FRONT);

			///
			///Metoda rejestruje obiekt
			///
			///@param *drawable - wskaünik na obiekt klasy IDrawable
			///
			///@param z_index - indeks warstwy renderingu
			///
			void RegisterDrawable(IDrawable* drawable, int z_index);

			///
			///Metoda wyrejstrowuje obiekt - bez usuwania
			///
			///@param *drawable - wskaünik na obiekt klasy IDrawable
			///
			void UnregisterDrawable(IDrawable *drawable);

			///
			///Metoda usuwa obiekt z kontenera
			///
			///@param *drawable - wskaünik na interfejs IDrawable
			///
			void DestroyDrawable(IDrawable* drawable);

			///
			///Wirtualna metoda aktualizujπca obiekty w kontenerze
			///
			///@param secondsPassed - czas
			///
			virtual void frameStarted(float secondsPassed) {};

			///
			///Metoda renderujπca obiekt klasy CDisplayable
			///
			///Metoda void DrawFrame(sf::RenderWindow* render);
			///
			///wywo≥uje w kontenerze ich metody wirtualne
			///
			///virtual Draw(sf::RenderWindow* render);
			///
			///@render render - parametr drawable
			///
			void DrawFrame(sf::RenderWindow* render = NULL);

			///
			///Wirtualny interfejs - implementacja
			///
			virtual void Cleanup();

		private:

			typedef std::vector< IDrawable* > DrawableList;		//kontener (vector)
			typedef std::vector< DrawableList > DrawableLists;	//kontener (vector) kontenerÛw (wektorÛw)

			DrawableLists m_layers;								//wektor przechowujπcy wektory
		};
	}//namespace drawable
}//namespace rendering
#endif //H_DRAWABLE_MANAGER_JACK
