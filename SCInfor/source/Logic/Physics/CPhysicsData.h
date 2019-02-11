//  _________________________________________
// | CPhysicsData.h - class definition       |
// | Jack Flower - May 2016                  |
// |_________________________________________|
//

#ifndef H_PHYSICS_DATA_JACK
#define H_PHYSICS_DATA_JACK

#include "../../RTTI/RTTI.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace physics
{
	///
	///Klasa bazowa reprezentuj�ca fizyk�
	///
	class CPhysicsData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		CPhysicsData();

		///
		///Konstruktor kopiuj�cy
		///
		///@param & CPhysicsDataCopy - sta�a referencja na obiekt klasy CPhysicsData
		///
		CPhysicsData(const CPhysicsData & CPhysicsDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CPhysicsData();

		///
		///Metoda zwraca wag�
		///
		const float getWeight() const;

		///
		///Metoda ustawia wag�
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metoda zwraca pozycj� obiektu
		///
		const sf::Vector2f & GetPosition() const;

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param x - wsp�rz�dna x obiektu
		///
		///@param y - wsp�rz�dna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowa� m_old_position
		///
		void SetPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param &vector - sta�a referenacja na obiekt klasy sf::Vector2f
		///
		///@param change_old_position - flaga, czy aktualizowa� m_old_position
		///
		void SetPosition(const sf::Vector2f& new_value, bool change_old_position = false);

		///
		///Metoda zwraca pozycj� przed aktualizacj� logiki m_old_position
		///
		const sf::Vector2f & GetOldPosition() const;

		///
		///Metoda zwraca pozycj� przed aktualizacj� logiki m_old_position
		///
		void SetOldPosition(const sf::Vector2f & old_position);

		///
		///Metoda ustawia pozycj� obiektu
		///
		///@param x - wsp�rz�dna x obiektu
		///
		///@param y - wsp�rz�dna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowa� m_old_position
		///
		void SetOldPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda zwraca pr�dko�� obiektu
		///
		const sf::Vector2f & GetVelocity() const;

		///
		///Metoda ustawia pr�dko�� obiektu
		///
		///@param velocity - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetVelocity(const sf::Vector2f & velocity);

		///
		///Metoda zwraca warto�� pu�apu obiektu
		///
		const float GetAltitude() const;

		///
		///Metoda ustawia warto�� pu�apu obiektu
		///
		///@param altitude - warto�� pu�apu obiektu
		///
		void SetAltitude(float altitude);

		///
		///Metoda zwraca zapami�tan� skal� (body)
		///
		const sf::Vector2f & GetStoredScaleBody() const;

		///
		///Metoda ustawia zapami�tan� skal� (body)
		///
		///@param stored_scale_X - warto�� X
		///
		///@param stored_scale_Y - warto�� Y
		///
		void SetStoredScaleBody(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapami�tan� skal� (body)
		///
		///@param & stored_scale_vector - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleBody(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda zwraca zapami�tan� skal� (head)
		///
		const sf::Vector2f & GetStoredScaleHead() const;

		///
		///Metoda ustawia zapami�tan� skal� (head)
		///
		///@param stored_scale_X - warto�� X
		///
		///@param stored_scale_Y - warto�� Y
		///
		void SetStoredScaleHead(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapami�tan� skal� (head)
		///
		///@param & stored_scale_vector - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleHead(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda ustawia zapami�tan� skal� (body and head)
		///
		///@param stored_scale_X - warto�� X
		///
		///@param stored_scale_Y - warto�� Y
		///
		void SetStoredScale(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapami�tan� skal� (body and head)
		///
		///@param & stored_scale - wektor skali - sta�a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScale(const sf::Vector2f & stored_scale);

		///
		///Metoda ustawia zapami�tan� skal�
		///
		///@param stored_uniform - jednolita warto�� skaluj�ca w osi x i y
		///
		void SetStoredScale(float stored_uniform);

		///
		///Metoda zwraca warto�� obrotu obiektu w stopniach (body and head)
		///
		const float GetRotation() const;

		///
		///Metoda ustawia warto�� obrotu obiektu w stopniach (body and head)
		///
		///@param rotation_uniform - warto�� obrotu obiektu (body and head)
		///
		void SetRotation(float rotation_uniform);

		///
		///Metoda zwraca warto�� obrotu obiektu w stopniach (body)
		///
		const float GetRotationBody() const;

		///
		///Metoda ustawia warto�� obrotu obiektu w stopniach (body)
		///
		///@param rotation_body - warto�� obrotu obiektu (body)
		///
		void SetRotationBody(float rotation_body);

		///
		///Metoda zwraca warto�� obrotu obiektu w stopniach (head)
		///
		const float GetRotationHead() const;

		///
		///Metoda ustawia warto�� obrotu obiektu w stopniach (head)
		///
		///@param rotation_head - warto�� obrotu obiektu (head)
		///
		void SetRotationHead(float rotation_head);

		///
		///Metoda obraca obiekt o zadany k�t (body)
		///
		///@param angle - warto�� obrotu
		///
		void RotateBody(float angle);

		///
		///Metoda obraca obiekt o zadany k�t (head)
		///
		///@param angle - warto�� obrotu
		///
		void RotateHead(float angle);

		///
		///Metoda obraca obiekt o zadany k�t (body and head)
		///
		///@param angle - warto�� obrotu
		///
		void Rotate(float angle);

	protected:

		float				m_weight;				//waga obiektu w kilogramach SI
		sf::Vector2f		m_position;				//wektor pozycji
		sf::Vector2f		m_old_position;			//wektor pozycji (przed aktualizacj�)
		sf::Vector2f		m_velocity;				//wektor pr�dko�ci obiektu
		float				m_altitude;				//warto�� pu�apu obiektu wzgl�dem pod�o�a
		float				m_init_height;			//wyliczona wirtualna wysoko�� obiektu
		sf::Vector2f		m_stored_scale_body;	//zapami�tana skala - pole pomocniczne - body
		sf::Vector2f		m_stored_scale_head;	//zapami�tana skala - pole pomocniczne - head
		float				m_rotation_uniform;		//warto�� obrotu (body and head)
		float				m_rotation_body;		//warto�� obrotu (body)
		float				m_rotation_head;		//warto�� obrotu (head)

		//docelowo pogrupowa� funkcjonalno�ci
		//fizyka do wrapper'a sf::Transformable
		sf::Transformable	m_transformable_data;	//opakowanie skali i rotacji (na razie nieaktywowane)...
		//przygotowa� opakowanie sf::Transformable,
		//w kt�rych b�d� przechowywane dane transformacji:
		//	position
		//	rotation
		//	origin
		//	scale
		//odpowiednio dla sk�adowych Physical (obiekt sk�ada si� z element�w)

	};
}//namespace physics
#endif//H_PHYSICS_DATA_JACK
