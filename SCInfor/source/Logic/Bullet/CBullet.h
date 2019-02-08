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
	///Klasa reprezentuje funkcjonalno�� pocisku
	///
	class CBullet : public Actor//CPhysical
	{
		RTTI_DECL;

		///
		///Deklaracja przyja�ni
		///
		friend class CPhysicalManager;
		
		//Aby uzyska� obiekt CBullet, nale�y wywo�a� CPhysicalManager::CreateCBullet();
		
	protected:

		///
		///Chroniony konstruktor domy�lny
		///
		CBullet(const std::wstring & uniqueId);

		///
		///Chroniony konstruktor kopiuj�cy
		///
		///@param CBulletCopy - parametr - obiekt klasy CBullet
		///
		CBullet(const CBullet & CBulletCopy);

		///
		///Chroniony destruktor wirtualny - u�ywany wy��cznie przez CPhysicalManager
		///
		virtual ~CBullet();

	public:

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string GetType() const;

		///
		///Metoda zwraca pr�dko�� pocisku
		///
		const float GetSpeed() const;

		///
		///Metoda ustawia pr�dko�� pocisku
		///
		///@param speed - pr�dko�� pocisku
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
		///Metoda zwraca po�o�enia emitera pocisku wzgl�dem w�a�ciciela
		///
		const sf::Vector2f& GetBulletEmiter() const;

		///
		///Metoda ustawia po�o�enia emitera pocisku wzgl�dem w�a�ciciela
		///
		///@param bullet_emiter_x - wsp�rzedna X emitera pocisku wzgl�dem w�a�ciciela
		///
		///@param bullet_emiter_y - wsp�rzedna Y emitera pocisku wzgl�dem w�a�ciciela
		///
		void SetBulletEmiter(float bullet_emiter_x, float bullet_emiter_y);

		///
		///Metoda ustawia po�o�enia emitera pocisku wzgl�dem w�a�ciciela
		///
		///@param bullet_emiter - wektor emitera pocisku wzgl�dem w�a�ciciela
		///
		void SetBulletEmiter(sf::Vector2f bullet_emiter);

		///
		///Metoda zwraca wektor kierunku
		///
		const sf::Vector2f& GetVectorMove() const;

		///
		///Metoda ustawia wektor kierunku - wsp�rz�dne
		///
		///@param vector_move_x - wsp�rz�dna X
		///
		///@param vector_move_y - wsp�rz�dna Y
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
		///Metoda zwraca funkcjonalno�� ataku pocisku
		///
		const float GetBulletForce() const;

		///
		///Metoda ustawia funkcjonalno�� ataku pocisku
		///
		///@param bullet_force - funkcjonalno�� ataku pocisku
		///
		void SetBulletForce(float bullet_force);

		///
		///Metoda zwraca po�o�enie celu - wektor, do kt�rego pod��a pocisk
		///
		const sf::Vector2f &GetTarget() const;

		///
		///Metoda ustawia po�o�enie celu - wektor, do kt�rego pod��a pocisk
		///
		///@param &target - sta�a referencja na wektor, do kt�rego pod��a pocisk
		///
		void SetTarget(sf::Vector2f& target);

		///
		///Metoda ustawia po�o�enie celu - wsp�rz�dne X, Y, do kt�rego pod��a pocisk
		///
		///@param target_x - wsp�rz�dna X, do kt�rego pod��a pocisk
		///
		///@param target_y - wsp�rz�dna Y, do kt�rego pod��a pocisk
		///
		void SetTarget(float target_x, float target_y);

		///
		///Metoda zwraca drog� pokonan� przez pocisk
		///
		float GetRoad(float _road);

		///
		///Metoda ustawia drog� pokonan� przez pocisk
		///
		///@param road - droga przebyta przez pocisk
		///
		void SetRoad(float road);

		///
		///Metoda zwraca pr�dko�� pocisku wystrzelonego z dzia�a
		///
		const float GetBulletSpeed() const;

		///
		///Metoda ustawia pr�dko�� pocisku wystrzelonego z dzia�a
		///
		///@param bullet_speed - pr�dko�� pocisku wystrzelonego z dzia�a
		///
		void SetBulletSpeed(float bullet_speed);

		///
		///Metoda tworzy eksplozj� - wymaga implementacji
		///
		void Explode();

		///
		///Wirtualna metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		///
		///Metoda testowa
		///
		void Test();

		//uporz�dkowac kolejnos� metod:


	protected:

		//jeden wielki bajzel - uporz�dkowa�!

		float			m_speed;				//pr�dko�� pocisku
		float			m_distance;				//dystans do pokonania przez pocisk bez kolizji
		float			m_half_distance;		//po�owa pystansu do pokonania przez pocisk opadanie cienia /optymalizacja/
		sf::Vector2f	m_bullet_emiter;		//wektor po�o�enia emitera pocisku wzgl�dem w�a�ciciela
		sf::Vector2f	m_vector_move;			//wektor kierunku
		float			m_destruction_time;		//czas do destrukcji pocisku
		sf::Vector2f	m_target;				//po�o�enie celu, do kt�rego pod��a pocisk
		float			m_bullet_force;			//si�a destrukcji pocisku - obra�enia przy trafieniu
		float			m_road;					//przebyta droga
		float			m_caliber;				//kaliber pocisku		[potrzebne]
		float			m_bullet_weight;		//waga jednego pocisku	[nie - bo to ju� odziedziczone]
		//zmiana, dziedziczymy po Actor (nie mam wagi i innych bajer�w)...
		//2019-02-08 mia�em razcj�, w�a�nie powy�sze wprowadzi�em w �ycie...

		
		//poni�ej - czeka mnie bardzo czasoch�onna analiza...
		//zabra�em to z klasy Gun
		float			m_bullet_speed;				//pr�dko�� pocisku - przenie�� do CBullet (to pocisk posiada wiedz�, jaki jest "szybki")

//
//		float			m_range;							//zasi�g strza�u pobierany od w�a�ciciela dzia�a (CRobot-Gun)
//		sf::Vector2f	m_initial;							//po�o�enie pocz�tkowe pocisku
//	[ok]		sf::Vector2f	m_target;							//po�o�enie celu, do kt�rego pod��a pocisk
//	[ok]		float			m_speed;							//pr�dko�� pocisku
//	[ok]		sf::Vector2f	m_bullet_emiter;					//wektor po�o�enia emitera pocisku wzgl�dem lufy
//	[ok]		sf::Vector2f	m_vector_move;						//wektor kierunku
//	[ok]		float			m_distance;							//dystans do pokonania przez pocisk
//	[ok]		float			m_half_distance;					//po�owa pystansu do pokonania przez pocisk /optymalizacja/
//	[ok]		float			m_road;								//przebyta droga
//		bool			m_bullet_in_distance;				//flaga, czy pocisk pokona� dystans
//		float			m_destruction_time;					//czas destrukcji pocisku r�wny pe�nemu obiegowi animacji
//		CPausableClock	m_destruction_clock;				//zegar pocisku
//		bool			m_destruction_enabled;				//flaga, czy pocisk dokona� autodestrukcji
//		bool			m_explosion_enabled;				//flaga, czy pocisk eksplodowa�
//		sf::Vector2f	m_bullet_offset;					//przesuni�cie wektora pocisku
//		CForce			m_bullet_force;						//funkcjonalno�� ataku pocisku
//		float			m_bullet_shocks_range;				//zasi�g ra�enia od�amk�w pocisku po eksplozji bez kolizji z celem
//		bool			m_bullet_check_collision;			//flaga, czy pocisk ma sprawdza� kolizj�
//		CRobot*			p_bullet_parent;					//wska�nik na w�a�ciciela pocisku
//		float			m_target_altitude;					//apogeum pu�apu - apogeum wysoko�ci
															//jak� mo�e osi�gn�� pocisk w czasie
															//lotu balistycznego (max)


	private:

	};
}//namespace logic
#endif//H_BULLET_JACK
