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
enum EActorBasicState
{
	UNIT_DEFAULT,	//obiekt siê dopiero rodzi, stan pierwotny, pocz¹tkowy (iddle)
	UNIT_MOVE,		//obiekt przenieszcza siê
	UNIT_ATTACK,	//obiekt atakuje
	UNIT_DEFENSE,	//obiekt broni siê
	UNIT_DAMAGE,	//obiekt jest we œnie (og³uszony, nieprzytomny, zahipnotyzowany)
	UNIT_DEATH		//obiekt w trakcie umierania (œmierci)
};
#endif//H_E_ACTOR_BASIC_STATE_JACK
