/*
 ____________________________________
| CBullet.h - definicja klasy.       |
| Jack Flower - March 2013.          |
|____________________________________|

*/

#ifndef H_BULLET_JACK
#define H_BULLET_JACK

#include "../Physical/CPhysical.h"
#include "../Actor/Actor.h"

namespace logic
{
	///
	///Klasa reprezentuje funkcjonalnoœæ pocisku
	///
	class CBullet : public Actor//CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyjaŸni
		///
		friend class CPhysicalManager;
		
		//Aby uzyskaæ obiekt CBullet, nale¿y wywo³aæ CPhysicalManager::CreateCBullet();
		
	protected:

		///
		///Chroniony konstruktor domyœlny
		///
		CBullet(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj¹cy
		///
		///@param CBulletCopy - parametr - obiekt klasy CBullet
		///
		CBullet(const CBullet & CBulletCopy);

		///
		///Chroniony destruktor wirtualny - u¿ywany wy³¹cznie przez CPhysicalManager
		///
		virtual ~CBullet();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca prêdkoœæ pocisku
		///
		const float GetSpeed() const;

		///
		///Metoda ustawia prêdkoœæ pocisku
		///
		///@param speed - prêdkoœæ pocisku
		///
		void SetSpeed(float speed);

		///
		///Metoda zwraca dystans do pokonania przez pocisk
		///
		const float GetDistance() const;// { return m_distance; }

		///
		///Metoda ustawia dystans do pokonania przez pocisk
		///
		///@param distance - dystans do pokonania
		///
		void SetDistance(float distance);

		///
		///Metoda zwraca po³o¿enia emitera pocisku wzglêdem w³aœciciela
		///
		const sf::Vector2f& GetBulletEmiter() const;

		///
		///Metoda ustawia po³o¿enia emitera pocisku wzglêdem w³aœciciela
		///
		///@param bullet_emiter_x - wspó³rzedna X emitera pocisku wzglêdem w³aœciciela
		///
		///@param bullet_emiter_y - wspó³rzedna Y emitera pocisku wzglêdem w³aœciciela
		///
		void SetBulletEmiter(float bullet_emiter_x, float bullet_emiter_y);

		///
		///Metoda ustawia po³o¿enia emitera pocisku wzglêdem w³aœciciela
		///
		///@param bullet_emiter - wektor emitera pocisku wzglêdem w³aœciciela
		///
		void SetBulletEmiter(sf::Vector2f bullet_emiter);

		///
		///Metoda zwraca wektor kierunku
		///
		const sf::Vector2f& GetVectorMove() const;

		///
		///Metoda ustawia wektor kierunku - wspó³rzêdne
		///
		///@param vector_move_x - wspó³rzêdna X
		///
		///@param vector_move_y - wspó³rzêdna Y
		///
		void SetVectorMove(float vector_move_x, float vector_move_y);

		///
		///Metoda ustawia wektor kierunku - wektor
		///
		///@param vector_move - wektor kierunku
		///
		void SetVectorMove(sf::Vector2f vector_move);

		///
		///Metoda zwraca czas destrukcji pocisku
		///
		const float GetDestructionTime() const;

		///
		///Metoda ustawia czas destrukcji pocisku
		///
		///@param desctruction_time - czas destrukcji pocisku
		///
		void SetDestructionTime(float destruction_time);

		///
		///Metoda zwraca funkcjonalnoœæ ataku pocisku
		///
		const float GetBulletForce() const;

		///
		///Metoda ustawia funkcjonalnoœæ ataku pocisku
		///
		///@param bullet_force - funkcjonalnoœæ ataku pocisku
		///
		void SetBulletForce(float bullet_force);

		///
		///Metoda zwraca po³o¿enie celu - wektor, do którego pod¹¿a pocisk
		///
		const sf::Vector2f &GetTarget() const;

		///
		///Metoda ustawia po³o¿enie celu - wektor, do którego pod¹¿a pocisk
		///
		///@param &target - sta³a referencja na wektor, do którego pod¹¿a pocisk
		///
		void SetTarget(sf::Vector2f& target);

		///
		///Metoda ustawia po³o¿enie celu - wspó³rzêdne X, Y, do którego pod¹¿a pocisk
		///
		///@param target_x - wspó³rzêdna X, do którego pod¹¿a pocisk
		///
		///@param target_y - wspó³rzêdna Y, do którego pod¹¿a pocisk
		///
		void SetTarget(float target_x, float target_y);

		///
		///Metoda zwraca drogê pokonan¹ przez pocisk
		///
		float GetRoad(float _road);

		///
		///Metoda ustawia drogê pokonan¹ przez pocisk
		///
		///@param road - droga przebyta przez pocisk
		///
		void SetRoad(float road);

		///
		///Metoda zwraca prêdkoœæ pocisku wystrzelonego z dzia³a
		///
		const float GetBulletSpeed() const;

		///
		///Metoda ustawia prêdkoœæ pocisku wystrzelonego z dzia³a
		///
		///@param bullet_speed - prêdkoœæ pocisku wystrzelonego z dzia³a
		///
		void SetBulletSpeed(float bullet_speed);

		///
		///Metoda tworzy eksplozjê - wymaga implementacji
		///
		void Explode();

		///
		///Wirtualna metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		///
		///Metoda testowa
		///
		void Test();

		//uporz¹dkowac kolejnosæ metod:


	protected:

		//jeden wielki bajzel - uporz¹dkowaæ!

		float			m_speed;				//prêdkoœæ pocisku
		float			m_distance;				//dystans do pokonania przez pocisk bez kolizji
		float			m_half_distance;		//po³owa pystansu do pokonania przez pocisk opadanie cienia /optymalizacja/
		sf::Vector2f	m_bullet_emiter;		//wektor po³o¿enia emitera pocisku wzglêdem w³aœciciela
		sf::Vector2f	m_vector_move;			//wektor kierunku
		float			m_destruction_time;		//czas do destrukcji pocisku
		sf::Vector2f	m_target;				//po³o¿enie celu, do którego pod¹¿a pocisk
		float			m_bullet_force;			//si³a destrukcji pocisku - obra¿enia przy trafieniu
		float			m_road;					//przebyta droga
		float			m_caliber;				//kaliber pocisku		[potrzebne]
		float			m_bullet_weight;		//waga jednego pocisku	[nie - bo to ju¿ odziedziczone]
		//zmiana, dziedziczymy po Actor (nie mam wagi i innych bajerów)...
		//2019-02-08 mia³em razcjê, w³aœnie powy¿sze wprowadzi³em w ¿ycie...

		
		//poni¿ej - czeka mnie bardzo czasoch³onna analiza...
		//zabra³em to z klasy Gun
		float			m_bullet_speed;				//prêdkoœæ pocisku - przenieœæ do CBullet (to pocisk posiada wiedzê, jaki jest "szybki")

//
//		float			m_range;							//zasiêg strza³u pobierany od w³aœciciela dzia³a (CRobot-Gun)
//		sf::Vector2f	m_initial;							//po³o¿enie pocz¹tkowe pocisku
//	[ok]		sf::Vector2f	m_target;							//po³o¿enie celu, do którego pod¹¿a pocisk
//	[ok]		float			m_speed;							//prêdkoœæ pocisku
//	[ok]		sf::Vector2f	m_bullet_emiter;					//wektor po³o¿enia emitera pocisku wzglêdem lufy
//	[ok]		sf::Vector2f	m_vector_move;						//wektor kierunku
//	[ok]		float			m_distance;							//dystans do pokonania przez pocisk
//	[ok]		float			m_half_distance;					//po³owa pystansu do pokonania przez pocisk /optymalizacja/
//	[ok]		float			m_road;								//przebyta droga
//		bool			m_bullet_in_distance;				//flaga, czy pocisk pokona³ dystans
//		float			m_destruction_time;					//czas destrukcji pocisku równy pe³nemu obiegowi animacji
//		CPausableClock	m_destruction_clock;				//zegar pocisku
//		bool			m_destruction_enabled;				//flaga, czy pocisk dokona³ autodestrukcji
//		bool			m_explosion_enabled;				//flaga, czy pocisk eksplodowa³
//		sf::Vector2f	m_bullet_offset;					//przesuniêcie wektora pocisku
//		CForce			m_bullet_force;						//funkcjonalnoœæ ataku pocisku
//		float			m_bullet_shocks_range;				//zasiêg ra¿enia od³amków pocisku po eksplozji bez kolizji z celem
//		bool			m_bullet_check_collision;			//flaga, czy pocisk ma sprawdzaæ kolizjê
//		CRobot*			p_bullet_parent;					//wskaŸnik na w³aœciciela pocisku
//		float			m_target_altitude;					//apogeum pu³apu - apogeum wysokoœci
															//jak¹ mo¿e osi¹gn¹æ pocisk w czasie
															//lotu balistycznego (max)


	private:

	};
}//namespace logic
#endif//H_BULLET_JACK
