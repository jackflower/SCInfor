//  _________________________________________
// | CPhysicsData.cpp - class implementation |
// | Jack Flower - May 2016                  |
// |_________________________________________|
//

#include "CPhysicsData.h"

namespace physics
{
	RTTI_IMPL_NOPARENT(CPhysicsData);

	//Konstruktor
	CPhysicsData::CPhysicsData()
	:
		m_weight				(0.0f),
		m_position				(0.0f, 0.0f),
		m_old_position			(0.0f, 0.0f),
		m_velocity				(0.0f, 0.0f),
		m_altitude				(1.0f),
		m_init_height			(0.0f),
		m_stored_scale_body		(0.0f, 0.0f),
		m_stored_scale_head		(0.0f, 0.0f),
		m_rotation_uniform		(0.0f),
		m_rotation_body			(0.0f),
		m_rotation_head			(0.0f)
	{
	}

	//Konstruktor kopiuj¹cy
	CPhysicsData::CPhysicsData(const CPhysicsData & CPhysicsDataCopy)
	:
		m_weight				(CPhysicsDataCopy.m_weight),
		m_position				(CPhysicsDataCopy.m_position),
		m_old_position			(CPhysicsDataCopy.m_old_position),
		m_velocity				(CPhysicsDataCopy.m_velocity),
		m_altitude				(CPhysicsDataCopy.m_altitude),
		m_init_height			(CPhysicsDataCopy.m_init_height),
		m_stored_scale_body		(CPhysicsDataCopy.m_stored_scale_body),
		m_stored_scale_head		(CPhysicsDataCopy.m_stored_scale_head),
		m_rotation_uniform		(CPhysicsDataCopy.m_rotation_uniform),
		m_rotation_body			(CPhysicsDataCopy.m_rotation_body),
		m_rotation_head			(CPhysicsDataCopy.m_rotation_head)
	{
	}

	//Destruktor wirtualny
	CPhysicsData::~CPhysicsData()
	{
		m_weight				= 0.0f;
		m_position.x			= 0.0f;
		m_position.y			= 0.0f;
		m_old_position.x		= 0.0f;
		m_old_position.y		= 0.0f;
		m_velocity.x			= 0.0f;
		m_velocity.y			= 0.0f;
		m_altitude				= 0.0f;
		m_init_height			= 0.0f;
		m_stored_scale_body.x	= 1;
		m_stored_scale_body.y	= 1;
		m_stored_scale_head.x	= 1;
		m_stored_scale_head.y	= 1;
		m_rotation_uniform		= 0.0f;
		m_rotation_body			= 0.0f;
		m_rotation_head			= 0.0f;
	}

	//Metoda zwraca wagê
	const float CPhysicsData::getWeight() const
	{
		return m_weight;
	}

	//Metoda ustawia wagê
	void CPhysicsData::setWeight(float weight)
	{
		if (weight < 0) return;
		m_weight = weight;
	}

	//Metoda zwraca pozycjê obiektu
	const sf::Vector2f & CPhysicsData::GetPosition() const
	{
		return m_position;
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysicsData::SetPosition(float x, float y, bool change_old_position)
	{
		//zak³adamy, ¿e body and head ma wspó³ny uchwyt
		m_position.x = x;	//aktualizacja pola w klasie (wektor pozycji - x)
		m_position.y = y;	//aktualizacja pola w klasie (wektor pozycji - y)

		if (change_old_position)
			m_old_position = m_position;
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysicsData::SetPosition(const sf::Vector2f & new_value, bool change_old_position)
	{
		//zak³adamy, ¿e body and head ma wspó³ny uchwyt
		m_position = new_value;	//aktualizacja pola w klasie (wektor pozycji)

		if (change_old_position)
			m_old_position = m_position;
	}

	//Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
	const sf::Vector2f & CPhysicsData::GetOldPosition() const
	{
		return m_old_position;
	}

	//Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
	void CPhysicsData::SetOldPosition(const sf::Vector2f & old_position)
	{
		m_old_position = old_position;
	}

	//Metoda ustawia pozycjê obiektu
	void CPhysicsData::SetOldPosition(float x, float y, bool change_old_position)
	{
		m_old_position.x = x;
		m_old_position.y = y;
	}

	//Metoda zwraca prêdkoœæ obiektu
	const sf::Vector2f & CPhysicsData::GetVelocity() const
	{
		return m_velocity;
	}

	//Metoda ustawia prêdkoœæ obiektu
	void CPhysicsData::SetVelocity(const sf::Vector2f & velocity)
	{
		m_velocity = velocity;
	}

	//Metoda zwraca wartoœæ pu³apu obiektu
	const float CPhysicsData::GetAltitude() const
	{
		return m_altitude;
	}

	//Metoda ustawia wartoœæ pu³apu obiektu
	void CPhysicsData::SetAltitude(float altitude)
	{
		if (altitude < 0) return;
		m_altitude = altitude;
	}

	//Metoda zwraca zapamiêtan¹ skalê (body)
	const sf::Vector2f & CPhysicsData::GetStoredScaleBody() const
	{
		return m_stored_scale_body;
	}

	//Metoda ustawia zapamiêtan¹ skalê (body)
	void CPhysicsData::SetStoredScaleBody(float stored_scale_X, float stored_scale_Y)
	{
		m_stored_scale_body.x = stored_scale_X;
		m_stored_scale_body.y = stored_scale_Y;
	}

	//Metoda ustawia zapamiêtan¹ skalê (body)
	void CPhysicsData::SetStoredScaleBody(const sf::Vector2f & stored_scale_vector)
	{
		m_stored_scale_body = stored_scale_vector;
	}

	//Metoda zwraca zapamiêtan¹ skalê (body)
	const sf::Vector2f & CPhysicsData::GetStoredScaleHead() const
	{
		return m_stored_scale_head;
	}

	//Metoda ustawia zapamiêtan¹ skalê (head)
	void CPhysicsData::SetStoredScaleHead(float stored_scale_X, float stored_scale_Y)
	{
		m_stored_scale_head.x = stored_scale_X;
		m_stored_scale_head.y = stored_scale_Y;
	}

	//Metoda ustawia zapamiêtan¹ skalê (head)
	void CPhysicsData::SetStoredScaleHead(const sf::Vector2f & stored_scale_vector)
	{
		m_stored_scale_head = stored_scale_vector;
	}

	//Metoda ustawia zapamiêtan¹ skalê (body and head)
	void CPhysicsData::SetStoredScale(float stored_scale_X, float stored_scale_Y)
	{
		m_stored_scale_body.x = stored_scale_X;
		m_stored_scale_body.y = stored_scale_Y;

		m_stored_scale_head.x = stored_scale_X;
		m_stored_scale_head.y = stored_scale_Y;
	}

	//Metoda ustawia zapamiêtan¹ skalê (body and head)
	void CPhysicsData::SetStoredScale(const sf::Vector2f & stored_scale)
	{
		m_stored_scale_body = stored_scale;
		m_stored_scale_head = stored_scale;
	}

	//Metoda ustawia zapamiêtan¹ skalê
	void CPhysicsData::SetStoredScale(float stored_uniform)
	{
		m_stored_scale_body.x = stored_uniform;
		m_stored_scale_head.y = stored_uniform;
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach
	const float CPhysicsData::GetRotation() const
	{
		return m_rotation_uniform;
		//m_rotation_uniform;		//wartoœæ obrotu (body and head)
		//m_rotation_body;			//wartoœæ obrotu (body)
		//m_rotation_head;			//wartoœæ obrotu (head)
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (body and head)
	void CPhysicsData::SetRotation(float rotation)
	{
		//zapamiêtujê rotacjê
		m_rotation_uniform = rotation;
		//body
		SetRotationBody(m_rotation_uniform);
		//head
		SetRotationHead(m_rotation_uniform);
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach (body)
	const float CPhysicsData::GetRotationBody() const
	{
		return m_rotation_body;
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (body)
	void CPhysicsData::SetRotationBody(float rotation_body)
	{
		m_rotation_body = rotation_body;
	}

	//Metoda zwraca wartoœæ obrotu obiektu w stopniach (head)
	const float CPhysicsData::GetRotationHead() const
	{
		return m_rotation_head;
	}

	//Metoda ustawia wartoœæ obrotu obiektu w stopniach (head)
	void CPhysicsData::SetRotationHead(float rotation_head)
	{
		m_rotation_head = rotation_head;
	}

	//Metoda obraca obiekt o zadany k¹t (body)
	void CPhysicsData::RotateBody(float angle)
	{
		m_rotation_body = angle;
	}

	//Metoda obraca obiekt o zadany k¹t (head)
	void CPhysicsData::RotateHead(float angle)
	{
		m_rotation_head = angle;
	}

	//Metoda obraca obiekt o zadany k¹t (body and head)
	void CPhysicsData::Rotate(float angle)
	{
		RotateBody(angle);
		RotateHead(angle);
	}

}//namespace physics
