#include "EnemyHazard.h"


EnemyHazard::EnemyHazard() {

	m_pEnemySurface = IMG_Load("Assets/New_Enemy.png");
}

EnemyHazard::~EnemyHazard()
{
}

EnemyHazard::EnemyHazard(int x, int y, int dL)
{
	alive = true;
	speed = 3;

	
	//SDL Rects
	m_rSrc.x = 0;	m_rDst.x = x;
	m_rSrc.y = 0;	m_rDst.y = y;
	m_rSrc.w = 30;	m_rDst.w = 62;
	m_rSrc.h = 32;	m_rDst.h = 70;

	m_iRad = (m_rDst.w + m_rDst.h ) / 6;

	m_pEnemySurface = IMG_Load("Assets/New_Enemy.png");


	resetX = x;
	resetY = y;

}

void EnemyHazard::animation()
{
	m_rDst.y += 1.5 * speed;

	if (m_rDst.y >= 800)
	{
		m_rDst.y = resetY- 700;
		
	}


}

void EnemyHazard::EnemyAnimation()
{
	
	if (delayCtr == delayMax)
	{

		if (frameCtr < frameMax)
		{

			m_rSrc.x = 32 * frameCtr;
			frameCtr++;

		}

		else if (frameCtr == frameMax)
		{

			frameCtr = 0;

		}

		delayCtr = 0;

	}

	delayCtr++;
}

void EnemyHazard::reset()
{

	alive = true;
	m_rDst.x = resetX;
	m_rDst.y = resetY;

	

}