#include "Assets.h"

Logo::Logo()
{
	m_pLogoSurface = IMG_Load("Assets/Menu.png");
	//Source
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 450;
	m_rSrc.h = 382;
	//Destination
	m_rDst.x = 574 / 2;
	m_rDst.y = 386 / 2;
	m_rDst.w = 450;
	m_rDst.h = 382;


}

TeamLogo::TeamLogo()
{

	m_pTeamLogoSurface = IMG_Load("Assets/cellblock_d_logo.png");
	//Source
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 850;
	m_rSrc.h = 500;
	//Destination
	m_rDst.x = 800;
	m_rDst.y = 620;
	m_rDst.w = 250;
	m_rDst.h = 150;
}


Paused::Paused()
{
	m_pPauseSurface = IMG_Load("Assets/Paused.png");
	//Source
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 978;
	m_rSrc.h = 150;
	//Destination
	m_rDst.x = 781;
	m_rDst.y = 25;
	m_rDst.w = 446 / 2;
	m_rDst.h = 165 / 2;
}

Win::Win()
{
	m_pWinSurface = IMG_Load("Assets/win.png");
	//Source
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 460;
	m_rSrc.h = 373;
	//Destination
	m_rDst.x = 564 / 2;
	m_rDst.y = 391 / 2;
	m_rDst.w = 460;
	m_rDst.h = 373;
}

Lose::Lose() 
{
	m_pLoseSurface = IMG_Load("Assets/Game_Over.png");
	//Source
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 1108;
	m_rSrc.h = 163;
	//Destination
	m_rDst.x = 564 / 2;
	m_rDst.y = 391 / 2;
	m_rDst.w = 450;
	m_rDst.h = 163;
}

Bullets::Bullets()
{
	m_pPlayerBullets = IMG_Load("Assets/Bullets");
	//Source
	m_rSrc.x = 0;
	m_rSrc.y = 0;
	m_rSrc.w = 446;
	m_rSrc.h = 165;
	//Destination
	m_rDst.x = 781;
	m_rDst.y = 25;
	m_rDst.w = 446 / 2;
	m_rDst.h = 165 / 2;
}
