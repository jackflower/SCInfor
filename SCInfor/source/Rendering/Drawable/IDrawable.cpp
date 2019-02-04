//  _________________________________________
// | IDrawable.cpp - interface implementtion |
// | Jack Flower - August 2012               |
// |_________________________________________|
//

#include "IDrawable.h"
#include "../Drawable/CDrawableManager.h"

namespace rendering
{
	namespace drawable
	{
		RTTI_IMPL_NOPARENT(IDrawable);

		//Konstruktor domy�lny
		IDrawable::IDrawable()
		:
			m_visible				(true),
			m_can_draw				(true),
			m_layer_vector_index	(-1),	//na wszelki wypadek wstawiamy -1, aby warstwa nie by�a ustawiona
			m_layer_index			(-1)	//na wszelki wypadek wstawiamy -1, aby warstwa nie by�a ustawiona
		{
		}

		//Konstruktor kopiuj�cy
		IDrawable::IDrawable(const IDrawable& IDrawableCopy)
		:
			m_visible				(IDrawableCopy.m_visible),
			m_layer_vector_index	(IDrawableCopy.m_layer_vector_index),
			m_layer_index			(IDrawableCopy.m_layer_index)
		{
		}

		//Wirtualny destruktor
		IDrawable::~IDrawable()
		{
			if (m_layer_vector_index >= 0)					//je�li w kontenerze, na warstwach s� jakie� obiekty
				gDrawableManager.UnregisterDrawable(this);	//wyrejestrowujemy je
		}

		//Metoda zwraca typ obiektu /RTTI/
		const std::string IDrawable::GetType() const
		{
			return rtti.GetNameClass();
		}

		//Metoda zwraca flag�, czy obiekt mo�na rysowa�
		const bool IDrawable::getCanDraw() const
		{
			return m_can_draw;
		}

		//Metoda ustawia flag�, czy obiekt mo�na rysowa�
		const void IDrawable::setCanDraw(bool can_draw)
		{
			m_can_draw = can_draw;
		}

		//Metoda zwraca flag�, czy obiekt jest widoczny
		const bool IDrawable::getVisible() const
		{
			return m_visible;
		}

		//Metoda ustawia flage, czy obiekt jest widoczny
		const void IDrawable::setVisible(bool visible)
		{
			m_visible = visible;
		}

		//Metoda zwraca indeks warstwy, na kt�rej ma by� renderowany obiekt
		const int IDrawable::GetLayerIndex() const
		{
			return m_layer_index;
		}

		//Metoda ustawia indeks warstwy, na kt�rej ma by� renderowany obiekt
		const void IDrawable::SetLayerIndex(int layer_index)
		{
			m_layer_index = layer_index;
		}
	}//namespace drawable
}//namespace rendering
