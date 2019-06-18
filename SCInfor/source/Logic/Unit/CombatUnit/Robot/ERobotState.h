//  _______________________________________________________________________
// | ERobotState.h - enumeration of states robot - fighting machine moving |
// | Jack Flower - June 2016                                               |
// |_______________________________________________________________________|
//

#ifndef H_E_ROBOT_STATE_JACK
#define H_E_ROBOT_STATE_JACK

///
///Wyliczenie stanów obiektu
///
enum class ERobotState
{
	ROBOT_DEFAULT, //stan normalny
	ROBOT_ATTACK_PREPARE, //przygotowanie do ataku (head open)
	ROBOT_ATTACK_DURING, //stan ataku
	ROBOT_ATTACK_TERMINATE, //zakończenie ataku (head close)
	ROBOT_DEFENSE_PREPARE, //przygotowanie do obrony (head open)
	ROBOT_DEFENSE_DURING, //stan obrony
	ROBOT_DEFENSE_TERMINATE, //zakończenie obrony (head close)
	ROBOT_DAMAGE, //uszkodzenia
	ROBOT_DEATH
};

#endif//H_E_ROBOT_STATE_JACK
