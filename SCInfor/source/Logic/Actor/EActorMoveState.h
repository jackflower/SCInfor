//  ___________________________________________________________
// | EActorMoveState.h - wyliczenie typów stanów ruchu obiektu |
// | Jack Flower - April 2015                                  |
// |___________________________________________________________|
//


#ifndef H_E_ACTOR_MOVE_STATE_JACK
#define H_E_ACTOR_MOVE_STATE_JACK

///
///Wyliczenie stanów ruchu obiektu
///
enum class EActorMoveState
{
	MOVE_STATE_STANDING, //obiekt nie porusza się, stoi
	MOVE_STATE_WALKING, //obiekt porusza się, idzie, spaceruje, jest w ruchu
	MOVE_STATE_TURNING, //obiekt obraca się, wykonuje obrót
	MOVE_STATE_STRAFING	//obiekt ostrzeliwuje się, trwa wymiana ognia...
};
#endif//H_E_ACTOR_MOVE_STATE_JACK
