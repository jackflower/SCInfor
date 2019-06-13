//  ___________________________________
// | Bullet.h - class definition       |
// | Jack Flower - March 2013          |
// |___________________________________|
//

#ifndef H_BULLET_JACK
#define H_BULLET_JACK

#include "../Physical/Physical.h"
#include "../Actor/Actor.h"
#include "../../Equipment/Weapon/Caliber.h"

using namespace equipment::weapon;

namespace logic
{
	///
	///Klasa reprezentuje funkcjonalność pocisku
	///
	class Bullet : public Actor
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaźni
		///
		friend class PhysicalManager;
		
		//Aby uzyskać obiekt Bullet, należy wywołać PhysicalManager::CreateCBullet();
		
	protected:

		///
		///Chroniony konstruktor domyślny
		///
		Bullet(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiujący
		///
		///@param BulletCopy - parametr - obiekt klasy Bullet
		///
		Bullet(const Bullet & BulletCopy);

		///
		///Chroniony destruktor wirtualny - używany wyłącznie przez PhysicalManager
		///
		virtual ~Bullet();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda zwraca dystans do pokonania przez pocisk
		///
		const float getDistance() const;

		///
		///Metoda ustawia dystans do pokonania przez pocisk
		///
		///@param distance - dystans do pokonania
		///
		void setDistance(float distance);

		///
		///Metoda zwraca położenia emitera pocisku względem właściciela
		///
		const sf::Vector2f & getBulletEmiter() const;

		///
		///Metoda ustawia położenia emitera pocisku względem właściciela
		///
		///@param bullet_emiter_x - współrzedna X emitera pocisku względem właściciela
		///
		///@param bullet_emiter_y - współrzedna Y emitera pocisku względem właściciela
		///
		void setBulletEmiter(float bullet_emiter_x, float bullet_emiter_y);

		///
		///Metoda ustawia położenia emitera pocisku względem właściciela
		///
		///@param bullet_emiter - referencja na wektor emitera pocisku względem właściciela
		///
		void setBulletEmiter(sf::Vector2f & bullet_emiter);

		///
		///Metoda zwraca wektor kierunku
		///
		const sf::Vector2f & getVectorMove() const;

		///
		///Metoda ustawia wektor kierunku - współrzędne
		///
		///@param vector_move_x - współrzędna X
		///
		///@param vector_move_y - współrzędna Y
		///
		void setVectorMove(float vector_move_x, float vector_move_y);

		///
		///Metoda ustawia wektor kierunku - wektor
		///
		///@param vector_move - wektor kierunku referencja na obiekt klasy sf::Vector2f
		///
		void setVectorMove(sf::Vector2f & vector_move);

		///
		///Metoda zwraca czas destrukcji pocisku
		///
		const float getDestructionTime() const;

		///
		///Metoda ustawia czas destrukcji pocisku
		///
		///@param desctruction_time - czas destrukcji pocisku
		///
		void setDestructionTime(float destruction_time);

		///
		///Metoda zwraca położenie celu - wektor, do którego podąża pocisk
		///
		const sf::Vector2f & getTarget() const;

		///
		///Metoda ustawia położenie celu - wektor, do którego podąża pocisk
		///
		///@param target - referencja na wektor, do którego podąża pocisk
		///
		void setTarget(sf::Vector2f & target);

		///
		///Metoda zwraca funkcjonalność ataku pocisku
		///
		const float getBulletForce() const;

		///
		///Metoda ustawia funkcjonalność ataku pocisku
		///
		///@param bullet_force - funkcjonalność ataku pocisku
		///
		void setBulletForce(float bullet_force);

		///
		///Metoda ustawia położenie celu - współrzędne X, Y, do którego podąża pocisk
		///
		///@param target_x - współrzędna X, do którego podąża pocisk
		///
		///@param target_y - współrzędna Y, do którego podąża pocisk
		///
		void setTarget(float target_x, float target_y);

		///
		///Metoda zwraca drogę pokonaną przez pocisk
		///
		const float getRoad();

		///
		///Metoda ustawia drogę pokonaną przez pocisk
		///
		///@param road - droga przebyta przez pocisk
		///
		void setRoad(float road);

		///
		///Metoda tworzy eksplozję - wymaga implementacji
		///
		void explode();

		///
		///Wirtualna metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		///
		///Metoda testowa
		///
		void Test();

	protected:

		//
		//wymagana analizy
		//
		//2019-06-14
		// propozycje:
		//	-	klasa pocisku - zwykły pocisk podlegający prawom fizyki Newtona
		//	-	klasa pocisk_extra (np. rakieta, samonaprowadzjący się, inne)
		//
		//Klasa wymaga analizy od postaw
		// - dane fizyki pobrać z klas bazowych
		// - sprawdzić, co znajduje się w opakowaniu
		//   dotyczącym cech technicznych

		//prawdopodobnie te składowe pozostaną
		float m_distance; //dystans do pokonania przez pocisk bez kolizji
		float m_half_distance; //połowa pystansu do pokonania przez pocisk opadanie cienia /optymalizacja/
		sf::Vector2f m_bullet_emiter; //wektor położenia emitera pocisku względem właściciela
		sf::Vector2f m_vector_move; //wektor kierunku
		float m_destruction_time; //czas do destrukcji pocisku
		sf::Vector2f m_target; //położenie celu, do którego podąża pocisk
		float m_bullet_force; //siła destrukcji pocisku - obrażenia przy trafieniu
		//docelowo klasa Force, Damage, etc...
		float m_road; //przebyta droga
		Caliber m_caliber; //kaliber pocisku

		//poniższa funkcjonalność - wymaga analizy

		// sf::Vector2f	m_initial; //położenie początkowe pocisku
		// bool m_bullet_in_distance; //flaga, czy pocisk pokonał dystans
		// float m_destruction_time; //czas destrukcji pocisku równy pełnemu obiegowi animacji
		// CPausableClock m_destruction_clock; //zegar pocisku
		// bool m_destruction_enabled; //flaga, czy pocisk dokonał autodestrukcji
		// bool m_explosion_enabled; //flaga, czy pocisk eksplodował
		// sf::Vector2f	m_bullet_offset; //przesunięcie wektora pocisku
		// CForce m_bullet_force; //funkcjonalność ataku pocisku
		// float m_bullet_shocks_range; //zasięg rażenia odłamków pocisku po eksplozji bez kolizji z celem
		// bool m_bullet_check_collision; //flaga, czy pocisk ma sprawdzać kolizję
		// Robot *p_bullet_parent; //wskaźnik na właściciela pocisku
		// float m_target_altitude; //apogeum pułapu - apogeum wysokości
									//jaką może osiągnąć pocisk w czasie
									//lotu balistycznego (max)
	private:

	};
}//namespace logic
#endif//H_BULLET_JACK
