#pragma once

#include "fstream"
#include "Sprite.h"
#include "Background.h"
#include "Player.h"
#include "EnemyHazard.h"
#include "Levels.h"
#include "Assets.h"
#include "SoundManager.h"
#include "Timer.h"
#include "Collision.h"

#define FPS 60

class Engine
{

public:

	Engine() :m_iFps(FPS), m_bGotTick(false) {}
	~Engine() {}

	bool init(const char*title, int xpos, int ypos, int width, int height, int flags);

	bool running();
	bool tick();
	void update();
	void render();
	void clean();
	void pause();
	void handleEvents();
	void nextLevel();
	void backgroundMovement();
	void mainMenu();
	void endMenu();
	void gameMenu();
	void scoreMenu();
	void move();
	void resetLevel();
	void freeSurface();
	void getTexture();
	void destroyTexture();

	static Engine* I()
	{

		static Engine* instance = new Engine();
		return instance;

	}

private:

	int m_iFps, m_iCurrLvl;
	int m_iHighScore;

	int m_iESpawn, // The enemy spawn frame timer properties.
		m_iESpawnMax;

	bool m_bRunning, m_bMain, m_bGotTick, m_bPause, m_bWin, m_bGame, m_bLose, m_bScore;
	bool m_bUp, m_bDown, m_bLeft, m_bRight;
	string m_sCurrScoreText;
	Logo m_Logo;
	TeamLogo m_TeamLogo;
	Win m_Win;
	Lose m_Lose;
	Paused m_Paused;
	Player m_Player;
	Levels m_Levels;
	Music m_Music;
	Timer m_Timer;
	EnemyHazard m_Enemy;
	Collision m_Collision;
	Life m_PlayerLife[5] = { Life(30, 40), Life(60, 40), Life(90, 40), Life(120, 40), Life(150, 40) };


	Background m_pBackground;
	Background m_Backgrounds[2] = {  Background(0, 0),Background(0, 768) };

	//SDL pointers
	SDL_Window*m_pWindow;
	SDL_Renderer*m_pRenderer;

	//Texture pointers
	SDL_Texture*m_pBackgroundTexture;
	SDL_Texture*m_pPlayerShipTexture; 
	SDL_Texture*m_pEnemyTexture;
	SDL_Texture*m_pLogoTexture;
	SDL_Surface* m_pLifeSurface;
	SDL_Texture* m_pLifeTexture;
	SDL_Texture* m_pTeamLogoTexture;
	SDL_Texture*m_pPauseTexture;
	SDL_Texture*m_pWinTexture;
	SDL_Texture*m_pLoseTexture;
};

