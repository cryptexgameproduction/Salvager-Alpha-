#include "Engine.h"

#include <chrono>

using namespace chrono;

bool Engine::init(const char*title, int xpos, int ypos, int width, int height, int flags)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{

		cout << "SDL INIT SUCCESS" << endl;
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (m_pWindow != 0)
		{

			cout << "Window Creation Successful" << endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{

				cout << "Renderer Creation successful" << endl;
				IMG_Init(IMG_INIT_PNG);

				TTF_Init();

				if (TTF_Init() == -1) 
				{
					std::cout << "TTF_Init: %s\n", TTF_GetError();
					exit(2);
				}
				else 
				{
					std::cout << "TTF Loaded" << endl;
				}

				getTexture();
				freeSurface();


				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					std::cout << "Error: " << Mix_GetError() << std::endl; // Upon failure, Displays this Error.
				}
			}

			else
			{

				cout << "Renderer Failed" << endl;

				return false;

			}

		}

		else
		{

			cout << "WINDOW CREATION Failed" << endl;

			return false;

		}

	}

	else
	{

		cout << "SDL SYSTEMS Failed" << endl;

		return false;

	}

	cout << "Everything worked" << endl;

	m_Music.BaseMusic();
	m_bWin = false;
	m_bScore = false;
	m_bLose = false;
	m_bRunning = true;

	// Render main screen first
	m_bMain = true;

	// Setting Current Level to 0
	m_iCurrLvl = 0;
	// Game paused.
	m_bPause = false;

	return true;

}

bool Engine::running()
{

	return m_bRunning;

}

bool Engine::tick()
//Timer
{
	auto duration = steady_clock::now().time_since_epoch();
	auto count = duration_cast<microseconds>(duration).count();

	int tick = 1000000 / m_iFps;

	if (count % tick < 100) // Drops duplicate frames.
	{

		if (m_bGotTick == false)
		{

			m_bGotTick = true;
			return true;

		}

		return false;

	}

	else m_bGotTick = false;

	return false;
}

void Engine::update() // Player, Enemy, Background : update
{
	if (m_bMain) 
	{
		backgroundMovement();
	}

	if (m_bScore) 
	{
		backgroundMovement();
	}
	//Everything pauses
	if (!m_bPause && m_bGame)
	{
		backgroundMovement();

		m_sCurrScoreText = to_string(int(m_Timer.get_ticks() / 1000.f));


		m_Collision.hazardCollision(m_Player, m_Levels, m_iCurrLvl, m_Music, m_Timer, m_bLose, m_bGame);
		nextLevel();
		move();

		m_Player.animation();

		for (int i = 0; i < totalHazards; i++)
		{

			if (m_Levels.hazards[m_iCurrLvl][i].alive == true)
			{

				m_Levels.hazards[m_iCurrLvl][i].EnemyAnimation();
			}

		}

	}
}


void Engine::render()
//Renders based on boolean
{

	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, m_pBackgroundTexture, m_Backgrounds[0].getSource(), m_Backgrounds[0].getDes());
	SDL_RenderCopy(m_pRenderer, m_pBackgroundTexture, m_Backgrounds[1].getSource(), m_Backgrounds[1].getDes());
	SDL_RenderCopy(m_pRenderer, m_pTeamLogoTexture, m_TeamLogo.getSource(), m_TeamLogo.getDes());

	if (m_bMain)
	{
		mainMenu();
	}

	if (m_bWin || m_bLose)
	{
		endMenu();
	}

	if (m_bScore)
	{
		scoreMenu();
	}
	//Renders the game
	if (m_bGame)
	{
		gameMenu();
	}

	SDL_RenderPresent(m_pRenderer);

}

void Engine::handleEvents()
//Key Down/Up Events
{

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{

		switch (event.type)
		{

		case SDL_QUIT:

			m_bRunning = false;
			break;

		case SDL_KEYDOWN:

			switch (event.key.keysym.sym)
			{

			case SDLK_ESCAPE:

				if (m_bMain || m_bLose || m_bWin || m_bGame )
				{
					m_bRunning = false;
				}

				break;
			case'r':
			case 'R':

				if (m_bWin || m_bLose)
				{
					resetLevel();
					m_bLose = false;
					m_bWin = false;
					m_bMain = true;
					break;
				}

				if (m_bMain)
				{
					m_bMain = false;
					m_bGame = true;
					m_Timer.start();
					break;
				}

				if (m_bScore)
				{
					m_bScore = false;
					m_bGame = true;
					m_Timer.start();
					break;
				}
				break;
			case'w':
			case 'W':

				if (!m_bUp)
				{

					m_bUp = true;

				}

				break;

			case'a':
			case 'A':

				if (!m_bLeft)
				{

					m_bLeft = true;

				}

				break;

			case's':
			case 'S':
				if (m_bMain)
				{
					m_bScore = true;
					m_bMain = false;
					break;
				}

				if (m_bScore) 
				{
					m_bScore = false;
					m_bMain = true;
					break;
				}

				if (m_bGame && !m_bDown)
				{

					m_bDown = true;

				}

				break;

			case'd':
			case 'D':

				if (!m_bRight)
				{

					m_bRight = true;

				}

				break;
			

				// Pause
			case'p':
			case'P':

				pause();

				break;
			}
			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{

			case'w':
			case 'W':
				m_bUp = false;

				break;

			case'a':
			case 'A':

				m_bLeft = false;

				break;

			case's':
			case 'S':

				m_bDown = false;

				break;

			case'd':
			case 'D':

				m_bRight = false;

				break;

			}

			break;

		}
	}
}

void Engine::clean()
//Cleans the program
{

	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyWindow(m_pWindow);
	destroyTexture();
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

}

void Engine::pause()
//Pause Game
{

	if (m_bGame && !m_bPause)
	{

		m_bPause = true;
		m_Timer.pause();

	}

	else
	{

		m_bPause = false;
		m_Timer.unpause();
	}
}

void Engine::nextLevel()
{

}

void Engine::backgroundMovement()
{

	m_Backgrounds[0].sideScroll();
	m_Backgrounds[1].sideScroll();
}

void Engine::mainMenu()
{
	SDL_RenderCopy(m_pRenderer, m_pLogoTexture, m_Logo.getSource(), m_Logo.getDes());

}

void Engine::endMenu()
{
	if (m_bWin) {
		SDL_RenderCopy(m_pRenderer, m_pWinTexture, m_Win.getSource(), m_Win.getDes());
	}
	if (m_bLose) {
		SDL_RenderCopy(m_pRenderer, m_pLoseTexture, m_Lose.getSource(), m_Lose.getDes());
	}
}

void Engine::gameMenu()
{

	SDL_RenderCopy(m_pRenderer, m_pPlayerShipTexture, m_Player.getSource(), m_Player.getDes());

	for (int i = 0; i < totalHazards; i++)
	{

		if (m_Levels.hazards[m_iCurrLvl][i].alive == true)
		{

			SDL_RenderCopy(m_pRenderer, m_pEnemyTexture, m_Levels.hazards[m_iCurrLvl][i].getSource(), m_Levels.hazards[m_iCurrLvl][i].getDes());
		}

	}
	for (int i = 0; i < m_Player.returnLife(); i++)
	{
		SDL_RenderCopy(m_pRenderer, m_pLifeTexture, m_PlayerLife[i].getSource(), m_PlayerLife[i].getDes());
	}

	if (m_bPause) 
	{
		SDL_RenderCopy(m_pRenderer, m_pPauseTexture, m_Paused.getSource(), m_Paused.getDes());
	}

}

void Engine::scoreMenu()
{

}


void Engine::move()
{
	if (m_bUp == true && m_Player.m_rDst.y > 0)
	{
		m_Player.movey(-1);
	}

	if (m_bDown == true && m_Player.m_rDst.y < 735 )
	{
		m_Player.movey(1);
	}

	if (m_bLeft == true && m_Player.m_rDst.x > 0)
	{
		m_Player.movex(-1);
	}

	if (m_bRight == true && m_Player.m_rDst.x < 990 )
	{
		m_Player.movex(1);
	}
}

void Engine::resetLevel() // Resetting level

{
	m_Timer.stop();
	m_bMain = true;
	m_bGame = false;
	m_iCurrLvl = 0;

	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 5; j++)
		{

			m_Levels.hazards[i][j].reset();

		}
	}
}

void Engine::freeSurface()
{
	SDL_FreeSurface(m_Player.m_pPlayerShipSurface);
	SDL_FreeSurface(m_pBackground.m_pBackgroundSurface);
	SDL_FreeSurface(m_Enemy.m_pEnemySurface);
	SDL_FreeSurface(m_Logo.m_pLogoSurface);
	SDL_FreeSurface(m_TeamLogo.m_pTeamLogoSurface);
	SDL_FreeSurface(m_pLifeSurface);
	SDL_FreeSurface(m_Paused.m_pPauseSurface);
	SDL_FreeSurface(m_Win.m_pWinSurface);
	SDL_FreeSurface(m_Lose.m_pLoseSurface);
}

void Engine::getTexture()
{
	m_pBackgroundTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pBackground.m_pBackgroundSurface);
	m_pPlayerShipTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Player.m_pPlayerShipSurface);
	m_pEnemyTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Enemy.m_pEnemySurface);
	m_pLogoTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Logo.m_pLogoSurface);
	m_pTeamLogoTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_TeamLogo.m_pTeamLogoSurface);
	m_pLifeSurface = IMG_Load("Assets/Life.png");
	m_pLifeTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pLifeSurface);
	m_pPauseTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Paused.m_pPauseSurface);
	m_pWinTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Win.m_pWinSurface);
	m_pLoseTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_Lose.m_pLoseSurface);
}

void Engine::destroyTexture()
{
	SDL_DestroyTexture(m_pBackgroundTexture);
	SDL_DestroyTexture(m_pPlayerShipTexture);
	SDL_DestroyTexture(m_pEnemyTexture);
	SDL_DestroyTexture(m_pLifeTexture);
	SDL_DestroyTexture(m_pLogoTexture);
	SDL_DestroyTexture(m_pTeamLogoTexture);
	SDL_DestroyTexture(m_pPauseTexture);
	SDL_DestroyTexture(m_pWinTexture);
	SDL_DestroyTexture(m_pLoseTexture);
}

