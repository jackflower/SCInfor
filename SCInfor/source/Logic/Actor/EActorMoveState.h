//  ___________________________________________________________
// | EActorMoveState.h - wyliczenie typ�w stan�w ruchu obiektu |
// | Jack Flower - April 2015                                  |
// |___________________________________________________________|
//


#ifndef H_E_ACTOR_MOVE_STATE_JACK
#define H_E_ACTOR_MOVE_STATE_JACK

///
///Wyliczenie stan�w ruchu obiektu
///
enum EActorMoveState
{
	MOVE_STATE_STANDING,	//obiekt nie porusza si�, stoi
	MOVE_STATE_WALKING,		//obiekt porusza si�, idzie, spaceruje, jest w ruchu
	MOVE_STATE_TURNING,		//obiekt obraca si�, wykonuje obr�t
	MOVE_STATE_STRAFING		//obiekt ostrzeliwuje si�, trwa wymiana ognia...
};
#endif//H_E_ACTOR_MOVE_STATE_JACK
