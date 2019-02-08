//  ___________________________________
// | CFlora.cpp - class implememtation |
// | Jack Flower - March 2014          |
// |___________________________________|
//

#include "CFlora.h"
#include "../../Rendering/Drawable/Layers.h"
#include "../../Weather/CWeather.h"

using namespace rendering::drawable;
using namespace weather;

namespace logic
{
	//Chroniony konstruktor domyœlny
	CFlora::CFlora(const std::wstring& uniqueId)
	:
		Actor					(uniqueId),//konstruktor klasy bazowej
		m_rotation_speed_body	(0.0f),
		m_rotation_speed_head	(0.0f)
	{
		SetZIndexBody(Z_FLORA_BODY);
		SetZIndexShadowBody(Z_FLORA_SHADOW_BODY);
		SetZIndexHead(Z_FLORA_HEAD);
		SetZIndexShadowHead(Z_FLORA_SHADOW_HEAD);
	}

	//Destruktor wirtualny
	CFlora::~CFlora(void)
	{
		m_rotation_speed_body	= 0.0f;
		m_rotation_speed_head	= 0.0f;
	}

	//Metoda zwraca prêdkoœæ rotacji body
	const float CFlora::getRotationSpeedBody() const
	{
		return m_rotation_speed_body;
	}

	//Metoda ustawia prêdkoœæ rotacji body
	void CFlora::setRotationSpeedBody(float rotation_speed_body)
	{
		m_rotation_speed_body = rotation_speed_body;
	}

	//Metoda zwraca prêdkoœæ rotacji head
	const float CFlora::getRotationSpeedHead() const
	{
		return m_rotation_speed_head;
	}

	//Metoda ustawia prêdkoœæ rotacji head
	void CFlora::setRotationSpeedHead(float rotation_speed_head)
	{
		m_rotation_speed_head = rotation_speed_head;
	}

	//Wirtualna metoda aktualizuj¹ca obiekt
	void CFlora::update(float dt)
	{
		UpdateShadow(dt);	//aktualizacja shadow engine

		RotateBody(m_rotation_speed_body * gWeather.GetWindSpeed());
		RotateHead(m_rotation_speed_head * gWeather.GetWindSpeed());
		//AI flora: To Do...
	}
}//namespace logic