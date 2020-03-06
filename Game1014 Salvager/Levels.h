#pragma once

#include "EnemyHazard.h"
#include "Timer.h"
//#include "Font.h"

#define levels 3
#define totalHazards 15

class Levels {

public:
	
	EnemyHazard hazards[levels][totalHazards];
	Levels();
	//void levelChange(Font &m_Font, Timer &m_Timer, bool &m_bWin, bool &m_bGame, int &m_currLvl);

private:

};