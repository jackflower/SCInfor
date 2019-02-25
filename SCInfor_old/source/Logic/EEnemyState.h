//  _________________________________________
// | EEnemyState.h - Wyliczenie stanów wroga |
// | Jack Flower - April 2015                |
// |_________________________________________|
//


#ifndef H_E_ENEMY_STATE_JACK
#define H_E_ENEMY_STATE_JACK

///
///Wyliczenie stanów obiektu
///
enum EEnemyState
{ 
	ENEMY_STATE_NORMAL,		//stan normalny
	ENEMY_STATE_TURN,		//stan wykonywania obrotu
	ENEMY_STATE_WAYPOINT	//wędrówka w kierunku puntu na mapie
};

#endif//H_E_ENEMY_STATE_JACK
//