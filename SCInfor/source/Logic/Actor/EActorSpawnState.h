//  ____________________________________________________________
// | EActorSpawnState.h - wyliczenie typów stanów ruchu obiektu |
// | Jack Flower - April 2015                                   |
// |____________________________________________________________|
//


#ifndef H_E_ACTOR_SPAWN_STATE_JACK
#define H_E_ACTOR_SPAWN_STATE_JACK

///
///Wyliczenie stanów behawioralnych obiektu (procesy ¿yciowe, trwanie)
///
enum EActorSpawnState
{
	SPAWN_STATE_SPAWNING,	//obiekt siê dopiero rodzi, odradza
	SPAWN_STATE_ALIVE,		//obiekt jest ¿ywy
	SPAWN_STATE_ASLEEP,		//obiekt jest we œnie (og³uszony, nieprzytmny, zahipnotyzowany)
	SPAWN_STATE_DYING		//obiekt w trakcie umierania (œmierci)
};
#endif//H_E_ACTOR_SPAWN_STATE_JACK
