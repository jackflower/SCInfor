//  __________________________________________
// | ActorController.h - class definition     |
// | Jack Flower April 2015                   |
// |__________________________________________|
//

#ifndef H_ACTOR_CONTROLLER_JACK
#define H_ACTOR_CONTROLLER_JACK

//#include <string>
#include "../../RTTI/RTTI.h"

///
///Forward declaration
///
namespace logic
{
	class Actor;
}

namespace logic
{

	///
	///Klasa reprezentuje mechanizm sterowania obiektem
	///
	class ActorController
	{
		RTTI_DECL;

	public:

		///
		///Konstruktor
		///
		///@param *actor - wskaźnik na obiekt klasy Actor
		///
		ActorController(Actor *actor);

		///
		///Destruktor wirtualny
		///
		virtual ~ActorController();

		///
		///Metoda zwraca typ obiektu /RTTI/
		///
		const std::string getType() const;

		///
		///Metoda ustawia stan i prędkość obiekty
		///
		///@param speed - prędkość
		///
		void setSpeed(float speed);

		///
		///Metoda ustawia stan i wykonuje obrót
		///
		///@param rotation - obrót
		///
		void turnBy(float rotation);
		
		///
		///Metoda zwraca wartość obrotu obiektu
		///
		const float getTrueRot() const;
		
		///
		///Metoda ustawia wartość obrotu obiektu
		///
		///@param true_rotation - wartość obrotu obiektu
		///
		void setTrueRot(float true_rotation);

		///
		///Metoda ustawia stan i wykonuje strafe
		///
		///@param strafe - wartość
		///
		void setStrafe(int strafe);

		///
		///Metoda ustawia kierunek ruchu
		///
		///@param move - kierunek ruchu
		///
		void setMove(int move);	

		///
		///Wirtualan metoda aktualizująca obiekt
		///
		///@param dt - czas
		///
		virtual void update(float dt);

		//metoda informująca o otrzymaniu obrażeń z danego źródła
		//wywoływana przez Actor, może służyć do realizacji
		//"grrr, zaatakuję gracza, który mnie zaatakował"
		//virtual void GotDamageFrom(float dmg, EffectSourcePtr source);
		//2015-04-11
		//description:
		//mechanizm obrażeń i skutków z tego wynikających
		//to do...

	protected:

		Actor *p_actor; //wskaźnik na obiekt klasy Actor
		int m_strafe; //aktor się ostrzeliwuje, trwa wymiana ognia...
		int m_move; //kierunek ruchu
		float m_true_rot; //aktualna wartość obrotu obiektu
	};
}//namespace logic
#endif//H_ACTOR_CONTROLLER_JACK
