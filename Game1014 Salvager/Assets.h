#pragma once

#include "Sprite.h"

class Logo : public Sprite
{

public:

	Logo();
	SDL_Surface* m_pLogoSurface;

private:
};


class TeamLogo : public Sprite
{

public:

	TeamLogo();
	SDL_Surface* m_pTeamLogoSurface;

private:
};

class Paused : public Sprite
{
public:
	Paused();
	SDL_Surface* m_pPauseSurface;
private:

};

class Bullets : public Sprite
{
public:
	Bullets();
	SDL_Surface* m_pPlayerBullets;
};

class Win : public Sprite
{
public:
	Win();
	SDL_Surface* m_pWinSurface;
};

class Lose : public Sprite
{
public:
	Lose();
	SDL_Surface* m_pLoseSurface;
};