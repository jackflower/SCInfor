//  ________________________________________
// | Drawable.cpp - interface implementtion |
// | Jack Flower - August 2012              |
// |________________________________________|
//

#include "Drawable.h"
#include "../Drawable/DrawableManager.h"

namespace rendering
{
	namespace drawable
	{
		RTTI_IMPL_NOPARENT(Drawable);

		//Konstruktor domyślny
		Drawable::Drawable()
		:
			m_visible(true),
			m_can_draw(true),
			m_layer_vector_index(-1), //na wszelki wypadek wstawiamy -1, aby warstwa nie była ustawiona
			m_layer_index(-1) //na wszelki wypadek wstawiamy -1, aby warstwa nie była ustawiona
		{
		}

		//Konstruktor kopiujący
		Drawable::Drawable(const Drawable & DrawableCopy)
		:
			m_visible(DrawableCopy.m_visible),
			m_layer_vector_index(DrawableCopy.m_layer_vector_index),
			m_layer_index(DrawableCopy.m_layer_index)
		{
		}

		//Wirtualny destruktor
		Drawable::~Drawable()
		{
			if (m_layer_vector_index >= 0) //jeśli w kontenerze, na warstwach są jakieś obiekty
				gDrawableManager.unregisterDrawable(this); //wyrejestrowujemy je
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string Drawable::getType() const
		{
			return rtti.getNameClass();
		}

		//Metoda zwraca flagę, czy obiekt można rysować
		const bool Drawable::getCanDraw() const
		{
			return m_can_draw;
		}

		//Metoda ustawia flagę, czy obiekt można rysować
		const void Drawable::setCanDraw(bool can_draw)
		{
			m_can_draw = can_draw;
		}

		//Metoda zwraca flagę, czy obiekt jest widoczny
		const bool Drawable::getVisible() const
		{
			return m_visible;
		}

		//Metoda ustawia flage, czy obiekt jest widoczny
		const void Drawable::setVisible(bool visible)
		{
			m_visible = visible;
		}

		//Metoda zwraca indeks warstwy, na której ma być renderowany obiekt
		const int Drawable::getLayerIndex() const
		{
			return m_layer_index;
		}

		//Metoda ustawia indeks warstwy, na której ma być renderowany obiekt
		const void Drawable::setLayerIndex(int layer_index)
		{
			m_layer_index = layer_index;
		}
	}//namespace drawable
}//namespace rendering
