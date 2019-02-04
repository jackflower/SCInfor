//  ___________________________________________
// | CActorController.h - class definition     |
// | Jack Flower April 2015                    |
// |___________________________________________|
//

#ifndef H_ACTOR_CONTROLLER_JACK
#define H_ACTOR_CONTROLLER_JACK

#include <string>
#include "../../RTTI/RTTI.h"

///
///Forward declaration
///
namespace logic
{
	class CActor;
}

namespace logic
{

	///
	///Klasa reprezentuje mechanizm sterowania obiektem
	///
	class CActorController
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		///@param *actor - wska�nik na obiekt klasy CActor
		///
		CActorController(CActor *actor);

		///
		///Destruktor wirtualny
		///
		virtual ~CActorController();

		///
		///Metoda ustawia stan i pr�dko�� obiekty
		///
		///@param speed - pr�dko��
		///
		void SetSpeed(float speed);

		///
		///Metoda ustawia stan i wykonuje obr�t
		///
		///@param rotation - obr�t
		///
		void TurnBy(float rotation);
		
		///
		///Metoda zwraca warto�� obrotu obiektu
		///
		const float GetTrueRot() const;
		
		///
		///Metoda ustawia warto�� obrotu obiektu
		///
		///@param true_rotation - warto�� obrotu obiektu
		///
		void SetTrueRot(float true_rotation);// { m_true_rot = true_rotation; }

		///
		///Metoda ustawia stan i wykonuje strafe
		///
		///@param strafe  -warto��
		///
		void SetStrafe(int strafe);

		///
		///Metoda ustawia kierunek ruchu
		///
		///@param move - kierunek ruchu
		///
		void SetMove(int move);	

		///
		///Wirtualan metoda aktualizuj�ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

		//metoda informuj�ca o otrzymaniu obra�e� z danego �r�d�a
		//wywo�ywana przez CActor, mo�e s�u�y� do realizacji
		//"grrr, zaatakuj� gracza, kt�ry mnie zaatakowa�"
		//virtual void GotDamageFrom(float dmg, EffectSourcePtr source);
		//2015-04-11
		//description:
		//mechanizm obra�e� i skutk�w z tego wynikaj�cych
		//to do...

	protected:

		CActor*		p_actor;	//wska�nik na obiekt klasy CActor
		int			m_strafe;	//aktor si� ostrzeliwuje, trwa wymiana ognia...
		int			m_move;		//kierunek ruchu
		float		m_true_rot;	//aktualna warto�� obrotu obiektu
	};
}//namespace logic
#endif//H_ACTOR_CONTROLLER_JACK
