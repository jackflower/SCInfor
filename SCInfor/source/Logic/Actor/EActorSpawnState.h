//  ____________________________________________________________
// | EActorSpawnState.h - wyliczenie typ�w stan�w ruchu obiektu |
// | Jack Flower - April 2015                                   |
// |____________________________________________________________|
//


#ifndef H_E_ACTOR_SPAWN_STATE_JACK
#define H_E_ACTOR_SPAWN_STATE_JACK

///
///Wyliczenie stan�w behawioralnych obiektu (procesy �yciowe, trwanie)
///
enum EActorSpawnState
{
	SPAWN_STATE_SPAWNING,	//obiekt si� dopiero rodzi, odradza
	SPAWN_STATE_ALIVE,		//obiekt jest �ywy
	SPAWN_STATE_ASLEEP,		//obiekt jest we �nie (og�uszony, nieprzytmny, zahipnotyzowany)
	SPAWN_STATE_DYING		//obiekt w trakcie umierania (�mierci)
};
#endif//H_E_ACTOR_SPAWN_STATE_JACK
