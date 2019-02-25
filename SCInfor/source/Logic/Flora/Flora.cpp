//  __________________________________
// | Flora.cpp - class implememtation |
// | Jack Flower - March 2014         |
// |__________________________________|
//

#include "Flora.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Weather/CWeather.h"

using namespace rendering::drawable;
using namespace weather;

namespace logic
{
	//Chroniony konstruktor domyślny
	Flora::Flora(const std::wstring & uniqueId)
	:
		Actor(uniqueId),//konstruktor klasy bazowej
		m_rotation_speed_body(0.0f),
		m_rotation_speed_head(0.0f)
	{
		setZIndexBody(Z_FLORA_BODY);
		setZIndexShadowBody(Z_FLORA_SHADOW_BODY);
		setZIndexHead(Z_FLORA_HEAD);
		setZIndexShadowHead(Z_FLORA_SHADOW_HEAD);
	}

	//Chroniony konstruktor kopiujący
	Flora::Flora(const Flora & FloraCopy)
	:
		Actor(FloraCopy),//konstruktor kopiujący klasy bazowej
		m_rotation_speed_body(FloraCopy.m_rotation_speed_body),
		m_rotation_speed_head(FloraCopy.m_rotation_speed_head)
	{
		setZIndexBody(Z_FLORA_BODY);
		setZIndexShadowBody(Z_FLORA_SHADOW_BODY);
		setZIndexHead(Z_FLORA_HEAD);
		setZIndexShadowHead(Z_FLORA_SHADOW_HEAD);
	}


	//Destruktor wirtualny
	Flora::~Flora(void)
	{
		m_rotation_speed_body = 0.0f;
		m_rotation_speed_head = 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string Flora::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca prędkość rotacji body
	const float Flora::getRotationSpeedBody() const
	{
		return m_rotation_speed_body;
	}

	//Metoda ustawia prędkość rotacji body
	void Flora::setRotationSpeedBody(float rotation_speed_body)
	{
		m_rotation_speed_body = rotation_speed_body;
	}

	//Metoda zwraca prędkość rotacji head
	const float Flora::getRotationSpeedHead() const
	{
		return m_rotation_speed_head;
	}

	//Metoda ustawia prędkość rotacji head
	void Flora::setRotationSpeedHead(float rotation_speed_head)
	{
		m_rotation_speed_head = rotation_speed_head;
	}

	//Wirtualna metoda aktualizująca obiekt
	void Flora::update(float dt)
	{
		updateShadow(dt);	//aktualizacja shadow engine

		rotateBody(m_rotation_speed_body * gWeather.GetWindSpeed());
		rotateHead(m_rotation_speed_head * gWeather.GetWindSpeed());
		//AI flora: To Do...
	}
}//namespace logic
