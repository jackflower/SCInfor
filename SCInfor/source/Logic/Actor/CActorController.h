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
		///@param *actor - wskaŸnik na obiekt klasy CActor
		///
		CActorController(CActor *actor);

		///
		///Destruktor wirtualny
		///
		virtual ~CActorController();

		///
		///Metoda ustawia stan i prêdkoœæ obiekty
		///
		///@param speed - prêdkoœæ
		///
		void SetSpeed(float speed);

		///
		///Metoda ustawia stan i wykonuje obrót
		///
		///@param rotation - obrót
		///
		void TurnBy(float rotation);
		
		///
		///Metoda zwraca wartoœæ obrotu obiektu
		///
		const float GetTrueRot() const;
		
		///
		///Metoda ustawia wartoœæ obrotu obiektu
		///
		///@param true_rotation - wartoœæ obrotu obiektu
		///
		void SetTrueRot(float true_rotation);// { m_true_rot = true_rotation; }

		///
		///Metoda ustawia stan i wykonuje strafe
		///
		///@param strafe  -wartoœæ
		///
		void SetStrafe(int strafe);

		///
		///Metoda ustawia kierunek ruchu
		///
		///@param move - kierunek ruchu
		///
		void SetMove(int move);	

		///
		///Wirtualan metoda aktualizuj¹ca obiekt
		///
		///@param dt - czas
		///
		virtual void Update(float dt);

		//metoda informuj¹ca o otrzymaniu obra¿eñ z danego Ÿród³a
		//wywo³ywana przez CActor, mo¿e s³u¿yæ do realizacji
		//"grrr, zaatakujê gracza, który mnie zaatakowa³"
		//virtual void GotDamageFrom(float dmg, EffectSourcePtr source);
		//2015-04-11
		//description:
		//mechanizm obra¿eñ i skutków z tego wynikaj¹cych
		//to do...

	protected:

		CActor*		p_actor;	//wskaŸnik na obiekt klasy CActor
		int			m_strafe;	//aktor siê ostrzeliwuje, trwa wymiana ognia...
		int			m_move;		//kierunek ruchu
		float		m_true_rot;	//aktualna wartoœæ obrotu obiektu
	};
}//namespace logic
#endif//H_ACTOR_CONTROLLER_JACK
