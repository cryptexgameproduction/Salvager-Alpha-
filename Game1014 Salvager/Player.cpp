#include "Player.h"

Player::Player()
{
	m_rSrc.x = 0;	m_rDst.x = 450;
	m_rSrc.y = 0;	m_rDst.y = 650;
	m_rSrc.w = 32;	m_rDst.w = 50;
	m_rSrc.h = 32;	m_rDst.h = 64;
	m_speed = 5;		m_iRad = (m_rDst.w + m_rDst.h - 30) / 4;
	m_iLife = 5;	m_iSavedY = 150;
	m_pPlayerShipSurface = IMG_Load("Assets/player_ship_1.png");
}

Player::~Player()
{
}

void Player::movex(int m)
{
	m_rDst.x += m * m_speed;
}

void Player::movey(int m)
{
	m_rDst.y += m * m_speed;
}

void Player::animation()
{
	if (m_delayCtr == m_maxDelay)
	{

		if (m_frameCounter < m_maxFrame)
		{

			m_rSrc.x = 32 * m_frameCounter;
			m_frameCounter++;
		}
		else if (m_frameCounter == m_maxFrame)
		{
			m_frameCounter = 0;
		}
		m_delayCtr = 0;
	}
	m_delayCtr++;
}

int Player::returnLife() {

	return m_iLife;

}

void Player::setLife() {

	m_iLife -= 1;

}

int Player::getSavedY()
{
	return m_iSavedY;
}

void Player::setSavedY(int y)
{
	m_iSavedY = y;
}

void Player::reset() {

	m_iLife = 5;
	m_rDst.x = 0;
	m_rDst.y = 150;
	m_iSavedY = 150;

}