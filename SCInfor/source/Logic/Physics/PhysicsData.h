//  ________________________________________
// | PhysicsData.h - class definition       |
// | Jack Flower - May 2016                 |
// |________________________________________|
//

#ifndef H_PHYSICS_DATA_JACK
#define H_PHYSICS_DATA_JACK

#include "../../RTTI/RTTI.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace physics
{
	///
	///Klasa bazowa reprezentująca fizykę
	///
	class PhysicsData
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		PhysicsData();

		///
		///Konstruktor kopiujący
		///
		///@param PhysicsDataCopy - stała referencja na obiekt klasy PhysicsData
		///
		PhysicsData(const PhysicsData & PhysicsDataCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~PhysicsData();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca wagę
		///
		const float getWeight() const;

		///
		///Metoda ustawia wagę
		///
		///@param weight - waga
		///
		void setWeight(float weight);

		///
		///Metoda zwraca pozycję obiektu
		///
		const sf::Vector2f & getPosition() const;

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param x - współrzędna x obiektu
		///
		///@param y - współrzędna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizować m_old_position
		///
		void setPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param vector - stała referenacja na obiekt klasy sf::Vector2f
		///
		///@param change_old_position - flaga, czy aktualizować m_old_position
		///
		void setPosition(const sf::Vector2f & new_value, bool change_old_position = false);

		///
		///Metoda zwraca pozycję przed aktualizacją logiki m_old_position
		///
		const sf::Vector2f & getOldPosition() const;

		///
		///Metoda zwraca pozycję przed aktualizacją logiki m_old_position
		///
		///@param old_position - stała referencja na obiekt klasy sf::Vector2f
		//
		void setOldPosition(const sf::Vector2f & old_position);

		///
		///Metoda ustawia pozycję obiektu
		///
		///@param x - współrzędna x obiektu
		///
		///@param y - współrzędna y obiektu
		///
		///@param change_old_position - flaga, czy aktualizować m_old_position
		///
		void setOldPosition(float x, float y, bool change_old_position = false);

		///
		///Metoda zwraca prędkość obiektu
		///
		const sf::Vector2f & getVelocity() const;

		///
		///Metoda ustawia prędkość obiektu
		///
		///@param velocity - stała referencja na obiekt klasy sf::Vector2f
		///
		void setVelocity(const sf::Vector2f & velocity);

		///
		///Metoda zwraca wartość pułapu obiektu
		///
		const float getAltitude() const;

		///
		///Metoda ustawia wartość pułapu obiektu
		///
		///@param altitude - wartość pułapu obiektu
		///
		void setAltitude(float altitude);

		///
		///Metoda zwraca zapamiętaną skalę (body)
		///
		const sf::Vector2f & getStoredScaleBody() const;

		///
		///Metoda ustawia zapamiętaną skalę (body)
		///
		///@param stored_scale_X - wartość X
		///
		///@param stored_scale_Y - wartość Y
		///
		void setStoredScaleBody(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiętaną skalę (body)
		///
		///@param stored_scale_vector - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setStoredScaleBody(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda zwraca zapamiętaną skalę (head)
		///
		const sf::Vector2f & getStoredScaleHead() const;

		///
		///Metoda ustawia zapamiętaną skalę (head)
		///
		///@param stored_scale_X - wartość X
		///
		///@param stored_scale_Y - wartość Y
		///
		void setStoredScaleHead(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiętaną skalę (head)
		///
		///@param stored_scale_vector - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setStoredScaleHead(const sf::Vector2f & stored_scale_vector);

		///
		///Metoda ustawia zapamiętaną skalę (body and head)
		///
		///@param stored_scale_X - wartość X
		///
		///@param stored_scale_Y - wartość Y
		///
		void setStoredScale(float stored_scale_X, float stored_scale_Y);

		///
		///Metoda ustawia zapamiętaną skalę (body and head)
		///
		///@param stored_scale - wektor skali - stała referencja na obiekt klasy sf::Vector2f
		///
		void setStoredScale(const sf::Vector2f & stored_scale);

		///
		///Metoda ustawia zapamiętaną skalę
		///
		///@param stored_uniform - jednolita wartość skalująca w osi x i y
		///
		void setStoredScale(float stored_uniform);

		///
		///Metoda zwraca wartość obrotu obiektu w stopniach (body and head)
		///
		const float getRotation() const;

		///
		///Metoda ustawia wartość obrotu obiektu w stopniach (body and head)
		///
		///@param rotation_uniform - wartość obrotu obiektu (body and head)
		///
		void setRotation(float rotation_uniform);

		///
		///Metoda zwraca wartość obrotu obiektu w stopniach (body)
		///
		const float getRotationBody() const;

		///
		///Metoda ustawia wartość obrotu obiektu w stopniach (body)
		///
		///@param rotation_body - wartość obrotu obiektu (body)
		///
		void setRotationBody(float rotation_body);

		///
		///Metoda zwraca wartość obrotu obiektu w stopniach (head)
		///
		const float getRotationHead() const;

		///
		///Metoda ustawia wartość obrotu obiektu w stopniach (head)
		///
		///@param rotation_head - wartość obrotu obiektu (head)
		///
		void setRotationHead(float rotation_head);

		///
		///Metoda obraca obiekt o zadany kąt (body)
		///
		///@param angle - wartość obrotu
		///
		void rotateBody(float angle);

		///
		///Metoda obraca obiekt o zadany kąt (head)
		///
		///@param angle - wartość obrotu
		///
		void rotateHead(float angle);

		///
		///Metoda obraca obiekt o zadany kąt (body and head)
		///
		///@param angle - wartość obrotu
		///
		void rotate(float angle);

	protected:

		float m_weight; //waga obiektu w kilogramach SI
		sf::Vector2f m_position; //wektor pozycji
		sf::Vector2f m_old_position; //wektor pozycji (przed aktualizacją)
		sf::Vector2f m_velocity; //wektor prędkości obiektu
		float m_altitude; //wartość pułapu obiektu względem podłoża
		float m_init_height; //wyliczona wirtualna wysokość obiektu
		sf::Vector2f m_stored_scale_body; //zapamiętana skala - pole pomocniczne - body
		sf::Vector2f m_stored_scale_head; //zapamiętana skala - pole pomocniczne - head
		float m_rotation_uniform; //wartość obrotu (body and head)
		float m_rotation_body; //wartość obrotu (body)
		float m_rotation_head; //wartość obrotu (head)

		//docelowo pogrupować funkcjonalności
		//fizyka do wrapper'a sf::Transformable
		sf::Transformable m_transformable_data;	//opakowanie skali i rotacji (na razie nieaktywowane)...
		//przygotować opakowanie sf::Transformable,
		//w których będą przechowywane dane transformacji:
		//	position
		//	rotation
		//	origin
		//	scale
		//odpowiednio dla składowych Physical (obiekt składa się z elementów)

	};
}//namespace physics
#endif//H_PHYSICS_DATA_JACK
