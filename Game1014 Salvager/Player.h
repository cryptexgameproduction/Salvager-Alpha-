#pragma once

#include "Sprite.h"

class Player : public Sprite
{
public:

	Player();
	~Player();
	int returnLife();

	//move functions
	void movex(int m);
	void movey(int m);
	void animation();
	SDL_Surface* m_pPlayerShipSurface;

	void setLife();
	int getSavedY();
	void setSavedY(int y);
	void reset();

private:

	int m_speed;
	int m_frameCounter = 0;
	int m_maxFrame = 3;
	int m_delayCtr = 0;
	int m_maxDelay = 8;
	int m_iLife;
	int m_iSavedY;

};
class Life : public Sprite
{
public:
	Life(int x, int y)
	{
		m_rSrc.x = m_rSrc.y = 0;
		m_rSrc.w = 135, m_rSrc.h = 120;
		m_rDst.x = x, m_rDst.y = y;
		m_rDst.w = 40, m_rDst.h = 35;
	}
	~Life(){}
};
