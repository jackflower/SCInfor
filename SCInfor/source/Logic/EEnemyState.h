//  _________________________________________
// | EEnemyState.h - Wyliczenie stan�w wroga |
// | Jack Flower - April 2015                |
// |_________________________________________|
//


#ifndef H_E_ENEMY_STATE_JACK
#define H_E_ENEMY_STATE_JACK

///
///Wyliczenie stan�w obiektu
///
enum EEnemyState
{ 
	ENEMY_STATE_NORMAL,		//stan normalny
	ENEMY_STATE_TURN,		//stan wykonywania obrotu
	ENEMY_STATE_WAYPOINT	//w�dr�wka w kierunku puntu na mapie
};

#endif//H_E_ENEMY_STATE_JACK
//