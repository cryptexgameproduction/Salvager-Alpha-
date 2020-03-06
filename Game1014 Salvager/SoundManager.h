#pragma once
#include "SDL_mixer.h"

class Music
{
public:
	Mix_Music* BGM;
	Mix_Chunk* collide;
	bool IsMusicOn = false;
	Music() {}
	~Music() {}

	void BaseMusic()
	{
		//SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); // Initializes Mixer to use Music
		BGM = Mix_LoadMUS("Assets/Music/GSS_Cinatit.mp3"); // Loads Music File
		Mix_PlayMusic(BGM, -1); // Loops the Music so it constantly plays
		Mix_VolumeMusic(10); // Volume for Music
	}

	void hurtSound()
	{
		collide = Mix_LoadWAV("Assets/Music/hit.wav");
		Mix_PlayChannel(1, collide, 0);
		Mix_VolumeChunk(collide, 10);
	}

	void MuteMusic()
	{
		if (IsMusicOn == false)
		{
			Mix_VolumeMusic(0);
			IsMusicOn = true;
		}
		else if (IsMusicOn)
		{
			Mix_VolumeMusic(10);
			IsMusicOn = false;
		}
	}

	void ExitMusic()
	{
		BGM = nullptr;
		Mix_Quit(); // Stops Music as game is closed
	}
};