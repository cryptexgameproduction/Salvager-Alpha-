#include "Levels.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
Levels::Levels()
{

	hazards[0][0] = EnemyHazard(100, 0, 1024);
	hazards[0][1] = EnemyHazard(300, 100, 950);
	hazards[0][2] = EnemyHazard(500, 200, 720);
	hazards[0][3] = EnemyHazard(700, 300, 500);
	hazards[0][4] = EnemyHazard(600, 400, 658);
	hazards[0][5] = EnemyHazard(700, 500, 812);
	hazards[0][6] = EnemyHazard(652, 600, 568);
	hazards[0][7] = EnemyHazard(125, 700, 125);
	hazards[0][8] = EnemyHazard(193, 800, 689);
	hazards[0][9] = EnemyHazard(265, 900, 623);
	hazards[0][10] = EnemyHazard(724, 1000, 768);
	hazards[0][11] = EnemyHazard(245, 400, 301);
	hazards[0][12] = EnemyHazard(356, 400, 925);
	hazards[0][13] = EnemyHazard(498, 400, 866);
	hazards[0][14] = EnemyHazard(999, 400, 834);
	hazards[0][15] = EnemyHazard(888, 400, 468);

	/*if(totalHazards < 2)
	{
		totalHazards;
	}
	for (int i = 0; i < 500; i++)
	{*/

		//int num = srand(time(-1);
		//int num1 = srand(time(10));
		//int num2 = srand(time(20));
		//hazards[0][i++] = EnemyHazard(num, num1, num2);
	
	
}

//void Levels::levelChange(Font &m_Font, Timer &m_Timer, bool &m_bWin, bool &m_bGame, int &m_currLvl)
//{
//	if (m_bGame)
//	{
//
//		if (m_currLvl < 2)
//		{
//
//			m_currLvl++;
//
//		}
//
//		else
//		{
//			
//			m_bWin = true;
//			m_bGame = false;
//			m_Timer.stop();
//
//		}
//
//
//	}
//}
