//  ____________________________________________
// | DrawableManager.cpp - class implementation |
// | Jack Flower - August 2012                  |
// |____________________________________________|
//

#include "DrawableManager.h"
#include "Drawable.h"
#include "../Displayable/Displayable.h"
#include "../Displayable/Rectangle.h"
#include "../Displayable/HudStaticText.h"
#include "../../Game/Game.h"

template<> DrawableManager* Singleton<DrawableManager>::m_singleton = 0;

using namespace game;

namespace rendering
{
	namespace drawable
	{
		//Konstruktor domyślny
		DrawableManager::DrawableManager()
		{
			fprintf(stderr,"DrawableManager::DrawableManager()\n");
			m_layers.resize(Z_MAX + 1);
			gGame.addFrameListener(this);
		}

		//Destruktor
		DrawableManager::~DrawableManager()
		{
			fprintf(stderr,"DrawableManager::~CDrawbleManager()\n");
		    
			for (DrawableLists::iterator it1 = m_layers.begin(); it1 != m_layers.end(); it1++)
			{
				DrawableList& list = (*it1);
				for (DrawableList::iterator it2 = list.begin(); it2 != list.end(); it2++)
				{
					delete ( *it2 );
				}
				(*it1).clear();
			}
			m_layers.clear();
			cleanup();
		}

		//Metoda tworzy obiekt klasy Displayable i zwraca wskaźnik na ten obiekt
		Displayable *DrawableManager::createDisplayable(int z_index)
		{
			if (!isCorrectZIndex(z_index)) return nullptr;

			Displayable* displayable = new Displayable();
			registerDrawable(displayable, z_index);

			return displayable;
		}

		//Metoda tworzy obiekt klasy Rectangle i zwraca wskaźnik na ten obiekt
		Rectangle *DrawableManager::createRectangle(int z_index)
		{
			if (!isCorrectZIndex(z_index)) return nullptr;

			Rectangle* rectangle = new Rectangle();
			registerDrawable(rectangle, z_index);

			return rectangle;
		}

		//Metoda tworzy obiekt klasy HudStaticText i zwraca wskaźnik na ten obiekt
		HudStaticText *DrawableManager::createHudStaticText(int z_index)
		{
			if (!isCorrectZIndex(z_index)) return nullptr;

			HudStaticText* hudstatictext = new HudStaticText();
			registerDrawable(hudstatictext, z_index);

			return hudstatictext;
		}

		//Metoda rejestruje obiekt
		void DrawableManager::registerDrawable(Drawable* drawable, int z_index)
		{
			if (!isCorrectZIndex(z_index)) return;
			if (drawable == nullptr) return;

			if (drawable->m_layer_index >= 0)
				unregisterDrawable(drawable);
			m_layers[z_index].push_back(drawable);
			drawable->m_layer_index = z_index;
			drawable->m_layer_vector_index = (int)(m_layers[z_index].size()-1);
		}

		//Metoda wyrejstrowuje obiekt - bez usuwania
		void DrawableManager::unregisterDrawable(Drawable *drawable)
		{
			if ((drawable == nullptr) || (drawable->m_layer_index < 0) || (drawable->m_layer_vector_index < 0))
				return;
			int zi = drawable->m_layer_index, vi = drawable->m_layer_vector_index;
			m_layers[zi][vi] = m_layers[zi][m_layers[zi].size()-1];
			m_layers[zi][vi]->m_layer_vector_index = vi;
			m_layers[zi].pop_back();
			drawable->m_layer_index = -1;
			drawable->m_layer_vector_index = -1;
		}

		//Metoda usuwa obiekt z kontenera
		void DrawableManager::destroyDrawable(Drawable* drawable)
		{
			if (drawable != nullptr)
			{
				unregisterDrawable(drawable);
				delete drawable;
				fprintf(stderr, "DrawableManager::destroyDrawable: destroy drawable\n");
			}
			else
				fprintf(stderr, "warning: DrawableManager::destroyDrawable: tried to destroy null drawable\n");
		}

		//Metoda renderująca obiekt klasy Displayable
		void DrawableManager::drawFrame(sf::RenderWindow* render)
		{
			if (render == nullptr)
				render = gGame.getRenderWindow();

			for (DrawableLists::reverse_iterator it1 = m_layers.rbegin(); it1 != m_layers.rend(); it1++ )
			{
				const DrawableList& list = (*it1);
				for (DrawableList::const_iterator it2 = list.begin() ; it2 != list.end() ; it2++)
				{
					Drawable* drawable = (*it2);
					if (drawable->getVisible())
						drawable->draw(render);
				} 
			}
		}

		//Funkcja pomocnicza - sprawdza, czy indeks warstwy jest poprawny
		bool isCorrectZIndex(int z_index)
		{
			if (z_index > Z_MAX)
			{
				fprintf(stderr, "warning, z_index > Z_MAX; returning null\n");
				return false;
			}
			if (z_index < 0)
			{
				fprintf(stderr, "warning, z_index > Z_MAX; returning null\n");
				return false;
			}
			return true;
		}

		//Wirtualny interfejs - implementacja
		void DrawableManager::cleanup()
		{
			fprintf(stderr, "DrawableManager::::cleanup()\n");
			fprintf(stderr, "DrawableManager::::cleanup() done...\n");
		}

	}//namespace drawable
}//namespace rendering
