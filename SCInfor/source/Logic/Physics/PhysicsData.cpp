//  ________________________________________
// | PhysicsData.cpp - class implementation |
// | Jack Flower - May 2016                 |
// |________________________________________|
//

#include "PhysicsData.h"

namespace physics
{
	RTTI_IMPL_NOPARENT(PhysicsData);

	//Konstruktor
	PhysicsData::PhysicsData()
	:
		m_weight(0.0f),
		m_position(0.0f, 0.0f),
		m_old_position(0.0f, 0.0f),
		m_velocity(0.0f, 0.0f),
		m_altitude(1.0f),
		m_init_height(0.0f),
		m_stored_scale_body(0.0f, 0.0f),
		m_stored_scale_head(0.0f, 0.0f),
		m_rotation_uniform(0.0f),
		m_rotation_body(0.0f),
		m_rotation_head(0.0f)
	{
	}

	//Konstruktor kopiujący
	PhysicsData::PhysicsData(const PhysicsData & PhysicsDataCopy)
	:
		m_weight(PhysicsDataCopy.m_weight),
		m_position(PhysicsDataCopy.m_position),
		m_old_position(PhysicsDataCopy.m_old_position),
		m_velocity(PhysicsDataCopy.m_velocity),
		m_altitude(PhysicsDataCopy.m_altitude),
		m_init_height(PhysicsDataCopy.m_init_height),
		m_stored_scale_body(PhysicsDataCopy.m_stored_scale_body),
		m_stored_scale_head(PhysicsDataCopy.m_stored_scale_head),
		m_rotation_uniform(PhysicsDataCopy.m_rotation_uniform),
		m_rotation_body(PhysicsDataCopy.m_rotation_body),
		m_rotation_head(PhysicsDataCopy.m_rotation_head)
	{
	}

	//Destruktor wirtualny
	PhysicsData::~PhysicsData()
	{
		m_weight = 0.0f;
		m_position.x = 0.0f;
		m_position.y = 0.0f;
		m_old_position.x = 0.0f;
		m_old_position.y = 0.0f;
		m_velocity.x = 0.0f;
		m_velocity.y = 0.0f;
		m_altitude = 0.0f;
		m_init_height = 0.0f;
		m_stored_scale_body.x = 1;
		m_stored_scale_body.y = 1;
		m_stored_scale_head.x	= 1;
		m_stored_scale_head.y	= 1;
		m_rotation_uniform		= 0.0f;
		m_rotation_body			= 0.0f;
		m_rotation_head			= 0.0f;
	}

	//Metoda zwraca typ obiektu /RTTI/
	const std::string PhysicsData::getType() const
	{
		return rtti.getNameClass();
	}

	//Metoda zwraca wagę
	const float PhysicsData::getWeight() const
	{
		return m_weight;
	}

	//Metoda ustawia wagę
	void PhysicsData::setWeight(float weight)
	{
		if (weight < 0) return;
		m_weight = weight;
	}

	//Metoda zwraca pozycję obiektu
	const sf::Vector2f & PhysicsData::getPosition() const
	{
		return m_position;
	}

	//Metoda ustawia pozycję obiektu
	void PhysicsData::setPosition(float x, float y, bool change_old_position)
	{
		//zakładamy, że body and head ma współny uchwyt
		m_position.x = x;	//aktualizacja pola w klasie (wektor pozycji - x)
		m_position.y = y;	//aktualizacja pola w klasie (wektor pozycji - y)

		if (change_old_position)
			m_old_position = m_position;
	}

	//Metoda ustawia pozycję obiektu
	void PhysicsData::setPosition(const sf::Vector2f & new_value, bool change_old_position)
	{
		//zakładamy, że body and head ma współny uchwyt
		m_position = new_value;	//aktualizacja pola w klasie (wektor pozycji)

		if (change_old_position)
			m_old_position = m_position;
	}

	//Metoda zwraca pozycję przed aktualizacją logiki m_old_position
	const sf::Vector2f & PhysicsData::getOldPosition() const
	{
		return m_old_position;
	}

	//Metoda zwraca pozycję przed aktualizacją logiki m_old_position
	void PhysicsData::setOldPosition(const sf::Vector2f & old_position)
	{
		m_old_position = old_position;
	}

	//Metoda ustawia pozycję obiektu
	void PhysicsData::setOldPosition(float x, float y, bool change_old_position)
	{
		m_old_position.x = x;
		m_old_position.y = y;
	}

	//Metoda zwraca prędkość obiektu
	const sf::Vector2f & PhysicsData::getVelocity() const
	{
		return m_velocity;
	}

	//Metoda ustawia prędkość obiektu
	void PhysicsData::setVelocity(const sf::Vector2f & velocity)
	{
		m_velocity = velocity;
	}

	//Metoda zwraca wartość pułapu obiektu
	const float PhysicsData::getAltitude() const
	{
		return m_altitude;
	}

	//Metoda ustawia wartość pułapu obiektu
	void PhysicsData::setAltitude(float altitude)
	{
		if (altitude < 0) return;
		m_altitude = altitude;
	}

	//Metoda zwraca zapamiętaną skalę (body)
	const sf::Vector2f & PhysicsData::getStoredScaleBody() const
	{
		return m_stored_scale_body;
	}

	//Metoda ustawia zapamiętaną skalę (body)
	void PhysicsData::setStoredScaleBody(float stored_scale_X, float stored_scale_Y)
	{
		m_stored_scale_body.x = stored_scale_X;
		m_stored_scale_body.y = stored_scale_Y;
	}

	//Metoda ustawia zapamiętaną skalę (body)
	void PhysicsData::setStoredScaleBody(const sf::Vector2f & stored_scale_vector)
	{
		m_stored_scale_body = stored_scale_vector;
	}

	//Metoda zwraca zapamiętaną skalę (body)
	const sf::Vector2f & PhysicsData::getStoredScaleHead() const
	{
		return m_stored_scale_head;
	}

	//Metoda ustawia zapamiętaną skalę (head)
	void PhysicsData::setStoredScaleHead(float stored_scale_X, float stored_scale_Y)
	{
		m_stored_scale_head.x = stored_scale_X;
		m_stored_scale_head.y = stored_scale_Y;
	}

	//Metoda ustawia zapamiętaną skalę (head)
	void PhysicsData::setStoredScaleHead(const sf::Vector2f & stored_scale_vector)
	{
		m_stored_scale_head = stored_scale_vector;
	}

	//Metoda ustawia zapamiętaną skalę (body and head)
	void PhysicsData::setStoredScale(float stored_scale_X, float stored_scale_Y)
	{
		m_stored_scale_body.x = stored_scale_X;
		m_stored_scale_body.y = stored_scale_Y;

		m_stored_scale_head.x = stored_scale_X;
		m_stored_scale_head.y = stored_scale_Y;
	}

	//Metoda ustawia zapamiętaną skalę (body and head)
	void PhysicsData::setStoredScale(const sf::Vector2f & stored_scale)
	{
		m_stored_scale_body = stored_scale;
		m_stored_scale_head = stored_scale;
	}

	//Metoda ustawia zapamiętaną skalę
	void PhysicsData::setStoredScale(float stored_uniform)
	{
		m_stored_scale_body.x = stored_uniform;
		m_stored_scale_head.y = stored_uniform;
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach
	const float PhysicsData::getRotation() const
	{
		return m_rotation_uniform;
		//m_rotation_uniform;		//wartość obrotu (body and head)
		//m_rotation_body;			//wartość obrotu (body)
		//m_rotation_head;			//wartość obrotu (head)
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (body and head)
	void PhysicsData::setRotation(float rotation)
	{
		//zapamiętuję rotację
		m_rotation_uniform = rotation;
		//body
		setRotationBody(m_rotation_uniform);
		//head
		setRotationHead(m_rotation_uniform);
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach (body)
	const float PhysicsData::getRotationBody() const
	{
		return m_rotation_body;
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (body)
	void PhysicsData::setRotationBody(float rotation_body)
	{
		m_rotation_body = rotation_body;
	}

	//Metoda zwraca wartość obrotu obiektu w stopniach (head)
	const float PhysicsData::getRotationHead() const
	{
		return m_rotation_head;
	}

	//Metoda ustawia wartość obrotu obiektu w stopniach (head)
	void PhysicsData::setRotationHead(float rotation_head)
	{
		m_rotation_head = rotation_head;
	}

	//Metoda obraca obiekt o zadany kąt (body)
	void PhysicsData::rotateBody(float angle)
	{
		m_rotation_body = angle;
	}

	//Metoda obraca obiekt o zadany kąt (head)
	void PhysicsData::rotateHead(float angle)
	{
		m_rotation_head = angle;
	}

	//Metoda obraca obiekt o zadany kąt (body and head)
	void PhysicsData::rotate(float angle)
	{
		rotateBody(angle);
		rotateHead(angle);
	}

}//namespace physics
