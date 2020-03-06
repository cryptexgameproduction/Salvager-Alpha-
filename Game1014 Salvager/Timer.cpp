#include "Timer.h"
Timer::Timer()
{
	//Initializing the variables
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start()
{
	//Starting timer
	started = true;

	//Unpausing timer
	paused = false;

	//Getting the current clock time.
	startTicks = SDL_GetTicks();
}

void Timer::stop()
{
	//Stopping timer
	started = false;

	//Unpause the timer
	paused = false;
}

int Timer::get_ticks()
{
	// Timer 
	if (started == true)
	{
		//If the timer is paused
		if (paused == true)
		{
			//Return the number of ticks when the timer was paused
			return pausedTicks;
		}

		else
		{
			//Return the current time minus the start time
			return SDL_GetTicks() - startTicks;
		}
	}

	//Timer stops
	return 0;
}


void Timer::pause()
{
	//If the timer is running and is not  paused
	if ((started == true) && (paused == false))
	{
		//Pause the timer
		paused = true;

		//Calculate the paused ticks
		pausedTicks = SDL_GetTicks() - startTicks;
	}
}

void Timer::unpause()
{
	//If the timer is paused
	if (paused == true)
	{
		//Unpause the timer
		paused = false;

		//Reset the starting ticks
		startTicks = SDL_GetTicks() - pausedTicks;

		//Reset the paused ticks
		pausedTicks = 0;
	}
}

bool Timer::is_started()
{
	return started;
}

bool Timer::is_paused()
{
	return paused;
}