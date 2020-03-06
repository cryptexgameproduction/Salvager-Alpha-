#pragma once

#include "Sprite.h"

class EnemyHazard : public Sprite
{

public:

	bool left, right, alive;
	int rightLimit;
	int leftLimit;
	int resetX, resetY;
	SDL_Surface * m_pEnemySurface;
	EnemyHazard();
	~EnemyHazard();
	EnemyHazard(int x, int y, int dL);

	void animation();
	void EnemyAnimation();
	void reset();

private:

	int speed;
	int frameCtr = 0;
	int frameMax = 4;
	int delayCtr = 0;
	int delayMax = 8;
};
