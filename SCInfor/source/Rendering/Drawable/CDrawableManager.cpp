//  _____________________________________________
// | CDrawableManager.cpp - class implementation |
// | Jack Flower - August 2012                   |
// |_____________________________________________|
//

#include "CDrawableManager.h"
#include "IDrawable.h"
#include "../Displayable/Displayable.h"
#include "../Displayable/Rectangle.h"
#include "../Displayable/HudStaticText.h"
#include "../../Game/Game.h"

template<> CDrawableManager* CSingleton<CDrawableManager>::m_singleton = 0;

using namespace game;

namespace rendering
{
	namespace drawable
	{
		//Konstruktor domyœlny
		CDrawableManager::CDrawableManager()
		{
			fprintf(stderr,"CDrawableManager::CDrawableManager()\n");
			m_layers.resize(Z_MAX + 1);
			gGame.addFrameListener(this);
		}

		//Destruktor
		CDrawableManager::~CDrawableManager()
		{
			fprintf(stderr,"CDrawableManager::~CDrawbleManager()\n");
		    
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
			Cleanup();
		}

		//Metoda tworzy obiekt klasy Displayable i zwraca wskaŸnik na ten obiekt
		Displayable* CDrawableManager::CreateDisplayable(int z_index)
		{
			if (!IsCorrectZIndex(z_index)) return NULL;

			Displayable* displayable = new Displayable();
			RegisterDrawable(displayable, z_index);

			return displayable;
		}

		//Metoda tworzy obiekt klasy Rectangle i zwraca wskaŸnik na ten obiekt
		Rectangle* CDrawableManager::CreateRectangle(int z_index)
		{
			if (!IsCorrectZIndex(z_index)) return NULL;

			Rectangle* rectangle = new Rectangle();
			RegisterDrawable(rectangle, z_index);

			return rectangle;
		}

		//Metoda tworzy obiekt klasy HudStaticText i zwraca wskaŸnik na ten obiekt
		HudStaticText* CDrawableManager::CreateHudStaticText(int z_index)
		{
			if (!IsCorrectZIndex(z_index)) return NULL;

			HudStaticText* hudstatictext = new HudStaticText();
			RegisterDrawable(hudstatictext, z_index);

			return hudstatictext;
		}

		//Metoda rejestruje obiekt
		void CDrawableManager::RegisterDrawable(IDrawable* drawable, int z_index)
		{
			if (!IsCorrectZIndex(z_index)) return;
			if (drawable == NULL) return;

			if (drawable->m_layer_index >= 0)
				UnregisterDrawable(drawable);
			m_layers[z_index].push_back(drawable);
			drawable->m_layer_index = z_index;
			drawable->m_layer_vector_index = (int)(m_layers[z_index].size()-1);
		}

		//Metoda wyrejstrowuje obiekt - bez usuwania
		void CDrawableManager::UnregisterDrawable(IDrawable *drawable)
		{
			if ((drawable == NULL) || (drawable->m_layer_index < 0) || (drawable->m_layer_vector_index < 0))
				return;
			int zi = drawable->m_layer_index, vi = drawable->m_layer_vector_index;
			m_layers[zi][vi] = m_layers[zi][m_layers[zi].size()-1];
			m_layers[zi][vi]->m_layer_vector_index = vi;
			m_layers[zi].pop_back();
			drawable->m_layer_index = -1;
			drawable->m_layer_vector_index = -1;
		}

		//Metoda usuwa obiekt z kontenera
		void CDrawableManager::DestroyDrawable(IDrawable* drawable)
		{
			if (drawable != NULL)
			{
				UnregisterDrawable(drawable);
				delete drawable;
				fprintf(stderr, "CDrawableManager::DestroyDrawable: destroy drawable\n");
			}
			else
				fprintf(stderr, "warning: CDrawableManager::DestroyDrawable: tried to destroy null drawable\n");
		}

		//Metoda renderuj¹ca obiekt klasy Displayable
		void CDrawableManager::DrawFrame(sf::RenderWindow* render)
		{
			if (render == NULL)
				render = gGame.getRenderWindow();

			for (DrawableLists::reverse_iterator it1 = m_layers.rbegin(); it1 != m_layers.rend(); it1++ )
			{
				const DrawableList& list = (*it1);
				for (DrawableList::const_iterator it2 = list.begin() ; it2 != list.end() ; it2++)
				{
					IDrawable* drawable = (*it2);
					if (drawable->getVisible())
						drawable->draw(render);
				} 
			}
		}

		//Funkcja pomocnicza - sprawdza, czy indeks warstwy jest poprawny
		bool IsCorrectZIndex(int z_index)
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
		void CDrawableManager::Cleanup()
		{
			fprintf(stderr, "CDrawableManager::::Cleanup()\n");
			fprintf(stderr, "CDrawableManager::::Cleanup() done...\n");
		}

	}//namespace drawable
}//namespace rendering
