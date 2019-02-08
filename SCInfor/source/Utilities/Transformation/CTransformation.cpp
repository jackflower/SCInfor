//  ____________________________________________
// | CTransformation.cpp - class implementation |
// | Jack Flower - May 2016                     |
// |____________________________________________|
//

#include "CTransformation.h"
#include "../../Logic/Actor/Actor.h"
#include "../../Rendering/Displayable/CDisplayable.h"
#include "../Utilities/Utilities.h"

using namespace rendering::displayable;

namespace transformation
{
	RTTI_IMPL_NOPARENT(CTransformation);//nie podajemy klas z biblioteki
	
	//Konstruktor
	CTransformation::CTransformation()
	:
		m_initial	(0.0f, 0.0f),
		m_offset	(0.0f, 0.0f),
		m_emiter	(0.0f, 0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CTransformation::CTransformation(const CTransformation & CTransformationCopy)
	:
		m_initial	(CTransformationCopy.m_initial),
		m_offset	(CTransformationCopy.m_offset),
		m_emiter	(CTransformationCopy.m_emiter)
	{
	}

	//Destruktor wurtualny
	CTransformation::~CTransformation()
	{
		m_initial.x	= 0.0f;
		m_initial.y = 0.0f;
		m_offset.x	= 0.0f;
		m_offset.y	= 0.0f;
		m_emiter.x	= 0.0f;
		m_emiter.y	= 0.0f;
	}

	//Metoda zwraca po³o¿enie przed transformacj¹
	const sf::Vector2f & CTransformation::getInitial() const
	{
		return m_initial;
	}

	//Metoda ustawia po³o¿enie przed transformacj¹
	void CTransformation::setInitial(sf::Vector2f & initial)
	{
		m_initial = initial;
	}

	//Metoda ustawia po³o¿enie przed transformacj¹
	void CTransformation::setInitial(float initial_x, float initial_y)
	{
		m_initial.x = initial_x;
		m_initial.y = initial_y;
	}

	//Metoda zwraca referencjê wektora przesuniêcia
	const sf::Vector2f & CTransformation::getOffset() const
	{
		return m_offset;
	}

	//Metoda ustawia wektor przesuniêcia
	void CTransformation::setOffset(sf::Vector2f & offset)
	{
		m_offset = offset;
	}

	//Metoda ustawia wektor przesuniêcia
	void CTransformation::setOffset(float offset_x, float offset_y)
	{
		m_offset.x = offset_x;
		m_offset.y = offset_y;
	}

	//Metoda zwraca referencjê na wektora po³o¿enia emitera
	const sf::Vector2f & CTransformation::getEmiter() const
	{
		return m_emiter;
	}

	//Metoda ustawia wektor po³o¿enia emitera
	void CTransformation::setEmiter(sf::Vector2f & emiter)
	{
		m_emiter = emiter;
	}

	//Metoda ustawia wektor po³o¿enia emitera
	void CTransformation::setEmiter(float emiter_x, float emiter_y)
	{
		m_emiter.x = emiter_x;
		m_emiter.y = emiter_y;
	}

	//Metoda dokonuje transformacji skali, pozycji, obrotu
	void CTransformation::Transform(Actor * p_parent, Actor * p_child)
	{
		//transformacja opiera siê na zainicjowanych wskaŸnikach
		//obiektów drawowalnych, zatem trzeba sprawdziæ ten warunek
		if (!p_child->GetDisplayableBody()) return;
		if (!p_parent->GetDisplayableBody()) return;

		//obiekt p_child znajduje siê na czêœci body w³aœciciela p_parent
		//dlatego wszystkie obliczenia (aktualizacja po³o¿enie)
		//wszystkie obliczenia (transformacja) liczone s¹ wzglêdem czêœci body
	
		if (p_parent != NULL)
		{
			if (p_child != NULL)
			{
				//pobieramy wartoœæ obrotu w³aœciciela (body)
				p_child->SetRotationBody(p_parent->GetRotationBody());
				
				//pobieramy skalê w³aœciciela
				p_child->SetScale(p_parent->GetScaleBody());

				//ustawiam wektor przesuniêcia wzglêdem w³aœciciela (body)
				m_offset.x = p_parent->GetDisplayableBody()->getLocalBounds().width * 0.5f * p_parent->GetScaleBody().x + (m_emiter.x * p_parent->GetScaleBody().x);
				m_offset.y = p_parent->GetDisplayableBody()->getLocalBounds().height * 0.5f * p_parent->GetScaleBody().y + (m_emiter.y * p_parent->GetScaleBody().y);

				//wyliczam pozycjê pocz¹tkow¹ uwzglêdniaj¹c przesuniêcie (body)
				m_initial.x = p_parent->GetDisplayableBody()->getPosition().x + (m_offset.x * -cos(p_parent->GetRotationBody() * (float)RADIANS_PER_DEGREE) + m_offset.y * -sin(p_parent->GetRotationBody() * (float)RADIANS_PER_DEGREE));
				m_initial.y = p_parent->GetDisplayableBody()->getPosition().y + (m_offset.x * -sin(p_parent->GetRotationBody() * (float)RADIANS_PER_DEGREE) - m_offset.y * -cos(p_parent->GetRotationBody() * (float)RADIANS_PER_DEGREE));

				//przekazujê wyliczon¹ pozycjê do child
				p_child->SetPosition(m_initial.x, m_initial.y);
			}
		}
	}
}//namespace transformation
