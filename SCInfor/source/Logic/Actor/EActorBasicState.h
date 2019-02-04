#//  ___________________________________________________________
// | EActorBasicState.h - wyliczenie typ�w stan�w ruchu obiektu |
// | Jack Flower - May 2016                                     |
// |____________________________________________________________|
//


#ifndef H_E_ACTOR_BASIC_STATE_JACK
#define H_E_ACTOR_BASIC_STATE_JACK

///
///Wyliczenie stan�w obiektu - podstawowe wytyczne dla reprezentacji graficznej
///
enum EActorBasicState
{
	UNIT_DEFAULT,	//obiekt si� dopiero rodzi, stan pierwotny, pocz�tkowy (iddle)
	UNIT_MOVE,		//obiekt przenieszcza si�
	UNIT_ATTACK,	//obiekt atakuje
	UNIT_DEFENSE,	//obiekt broni si�
	UNIT_DAMAGE,	//obiekt jest we �nie (og�uszony, nieprzytomny, zahipnotyzowany)
	UNIT_DEATH		//obiekt w trakcie umierania (�mierci)
};
#endif//H_E_ACTOR_BASIC_STATE_JACK
