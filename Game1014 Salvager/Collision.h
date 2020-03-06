#pragma once
#include "Sprite.h"
#include "Levels.h"
#include "Player.h"
#include "SoundManager.h"
#include "Timer.h"

class Collision {
public:
	Collision();
	~Collision();
	void hazardCollision(Player &m_Player, Levels &m_Levels, int &m_currLvl, Music &m_Music, Timer &m_Timer, bool &m_bLose, bool &m_bGame);
	bool circleCollision(double x1, double x2, double y1, double y2, double r1, double r2);
private:
};