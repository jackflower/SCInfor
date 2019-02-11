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
	///Klasa bazowa reprezentuj¹ca fizykê
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
		///Konstruktor kopiuj¹cy
		///
		///@param & CPhysicsDataCopy - sta³a referencja na obiekt klasy CPhysicsData
		///
		CPhysicsData(const CPhysicsData & CPhysicsDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CPhysicsData();

		///
		///Metoda zwraca wagê
		///
		const float getWeight() const;

		///
		///Metoda ustawia wagê
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metoda zwraca pozycjê obiektu
		///
		const sf::Vector2f & GetPosition() const;

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param x - wspó³rzêdna x obiektu
		///
		///@param y - wspó³rzêdna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowaæ m_old_position
		///
		void SetPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param &vector - sta³a referenacja na obiekt klasy sf::Vector2f
		///
		///@param change_old_position - flaga, czy aktualizowaæ m_old_position
		///
		void SetPosition(const sf::Vector2f& new_value, bool change_old_position = false);

		///
		///Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
		///
		const sf::Vector2f & GetOldPosition() const;

		///
		///Metoda zwraca pozycjê przed aktualizacj¹ logiki m_old_position
		///
		void SetOldPosition(const sf::Vector2f & old_position);

		///
		///Metoda ustawia pozycjê obiektu
		///
		///@param x - wspó³rzêdna x obiektu
		///
		///@param y - wspó³rzêdna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizowaæ m_old_position
		///
		void SetOldPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda zwraca prêdkoœæ obiektu
		///
		const sf::Vector2f & GetVelocity() const;

		///
		///Metoda ustawia prêdkoœæ obiektu
		///
		///@param velocity - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetVelocity(const sf::Vector2f & velocity);

		///
		///Metoda zwraca wartoœæ pu³apu obiektu
		///
		const float GetAltitude() const;

		///
		///Metoda ustawia wartoœæ pu³apu obiektu
		///
		///@param altitude - wartoœæ pu³apu obiektu
		///
		void SetAltitude(float altitude);

		///
		///Metoda zwraca zapamiêtan¹ skalê (body)
		///
		const sf::Vector2f & GetStoredScaleBody() const;

		///
		///Metoda ustawia zapamiêtan¹ skalê (body)
		///
		///@param stored_scale_X - wartoœæ X
		///
		///@param stored_scale_Y - wartoœæ Y
		///
		void SetStoredScaleBody(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiêtan¹ skalê (body)
		///
		///@param & stored_scale_vector - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleBody(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda zwraca zapamiêtan¹ skalê (head)
		///
		const sf::Vector2f & GetStoredScaleHead() const;

		///
		///Metoda ustawia zapamiêtan¹ skalê (head)
		///
		///@param stored_scale_X - wartoœæ X
		///
		///@param stored_scale_Y - wartoœæ Y
		///
		void SetStoredScaleHead(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiêtan¹ skalê (head)
		///
		///@param & stored_scale_vector - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScaleHead(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda ustawia zapamiêtan¹ skalê (body and head)
		///
		///@param stored_scale_X - wartoœæ X
		///
		///@param stored_scale_Y - wartoœæ Y
		///
		void SetStoredScale(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiêtan¹ skalê (body and head)
		///
		///@param & stored_scale - wektor skali - sta³a referencja na obiekt klasy sf::Vector2f
		///
		void SetStoredScale(const sf::Vector2f & stored_scale);

		///
		///Metoda ustawia zapamiêtan¹ skalê
		///
		///@param stored_uniform - jednolita wartoœæ skaluj¹ca w osi x i y
		///
		void SetStoredScale(float stored_uniform);

		///
		///Metoda zwraca wartoœæ obrotu obiektu w stopniach (body and head)
		///
		const float GetRotation() const;

		///
		///Metoda ustawia wartoœæ obrotu obiektu w stopniach (body and head)
		///
		///@param rotation_uniform - wartoœæ obrotu obiektu (body and head)
		///
		void SetRotation(float rotation_uniform);

		///
		///Metoda zwraca wartoœæ obrotu obiektu w stopniach (body)
		///
		const float GetRotationBody() const;

		///
		///Metoda ustawia wartoœæ obrotu obiektu w stopniach (body)
		///
		///@param rotation_body - wartoœæ obrotu obiektu (body)
		///
		void SetRotationBody(float rotation_body);

		///
		///Metoda zwraca wartoœæ obrotu obiektu w stopniach (head)
		///
		const float GetRotationHead() const;

		///
		///Metoda ustawia wartoœæ obrotu obiektu w stopniach (head)
		///
		///@param rotation_head - wartoœæ obrotu obiektu (head)
		///
		void SetRotationHead(float rotation_head);

		///
		///Metoda obraca obiekt o zadany k¹t (body)
		///
		///@param angle - wartoœæ obrotu
		///
		void RotateBody(float angle);

		///
		///Metoda obraca obiekt o zadany k¹t (head)
		///
		///@param angle - wartoœæ obrotu
		///
		void RotateHead(float angle);

		///
		///Metoda obraca obiekt o zadany k¹t (body and head)
		///
		///@param angle - wartoœæ obrotu
		///
		void Rotate(float angle);

	protected:

		float				m_weight;				//waga obiektu w kilogramach SI
		sf::Vector2f		m_position;				//wektor pozycji
		sf::Vector2f		m_old_position;			//wektor pozycji (przed aktualizacj¹)
		sf::Vector2f		m_velocity;				//wektor prêdkoœci obiektu
		float				m_altitude;				//wartoœæ pu³apu obiektu wzglêdem pod³o¿a
		float				m_init_height;			//wyliczona wirtualna wysokoœæ obiektu
		sf::Vector2f		m_stored_scale_body;	//zapamiêtana skala - pole pomocniczne - body
		sf::Vector2f		m_stored_scale_head;	//zapamiêtana skala - pole pomocniczne - head
		float				m_rotation_uniform;		//wartoœæ obrotu (body and head)
		float				m_rotation_body;		//wartoœæ obrotu (body)
		float				m_rotation_head;		//wartoœæ obrotu (head)

		//docelowo pogrupowaæ funkcjonalnoœci
		//fizyka do wrapper'a sf::Transformable
		sf::Transformable	m_transformable_data;	//opakowanie skali i rotacji (na razie nieaktywowane)...
		//przygotowaæ opakowanie sf::Transformable,
		//w których bêd¹ przechowywane dane transformacji:
		//	position
		//	rotation
		//	origin
		//	scale
		//odpowiednio dla sk³adowych Physical (obiekt sk³ada siê z elementów)

	};
}//namespace physics
#endif//H_PHYSICS_DATA_JACK
