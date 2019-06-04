//  ____________________________________________________________
// | EActorSpawnState.h - wyliczenie typów stanów ruchu obiektu |
// | Jack Flower - April 2015                                   |
// |____________________________________________________________|
//


#ifndef H_E_ACTOR_SPAWN_STATE_JACK
#define H_E_ACTOR_SPAWN_STATE_JACK

///
///Wyliczenie stanów behawioralnych obiektu (procesy życiowe, trwanie)
///
enum class EActorSpawnState
{
	SPAWN_STATE_SPAWNING, //obiekt się dopiero rodzi, odradza
	SPAWN_STATE_ALIVE, //obiekt jest żywy
	SPAWN_STATE_ASLEEP, //obiekt jest we śnie (ogłuszony, nieprzytmny, zahipnotyzowany)
	SPAWN_STATE_DYING //obiekt w trakcie umierania (śmierci)
};
#endif//H_E_ACTOR_SPAWN_STATE_JACK
