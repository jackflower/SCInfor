#//  ___________________________________________________________
// | EActorBasicState.h - wyliczenie typów stanów ruchu obiektu |
// | Jack Flower - May 2016                                     |
// |____________________________________________________________|
//


#ifndef H_E_ACTOR_BASIC_STATE_JACK
#define H_E_ACTOR_BASIC_STATE_JACK

///
///Wyliczenie stanów obiektu - podstawowe wytyczne dla reprezentacji graficznej
///
enum class EActorBasicState
{
	UNIT_DEFAULT, //obiekt się dopiero rodzi, stan pierwotny, początkowy (iddle)
	UNIT_MOVE, //obiekt przenieszcza się
	UNIT_ATTACK, //obiekt atakuje
	UNIT_DEFENSE, //obiekt broni się
	UNIT_DAMAGE, //obiekt jest we śnie (ogłuszony, nieprzytomny, zahipnotyzowany)
	UNIT_DEATH //obiekt w trakcie umierania (śmierci)
};
#endif//H_E_ACTOR_BASIC_STATE_JACK
