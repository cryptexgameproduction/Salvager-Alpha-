#pragma once

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class SPRITE
{

public:

	SDL_Rect m_rSrc;
	SDL_Rect m_rDst;

	const SDL_Rect*getSource()
	{

		return &m_rSrc;

	}

	const SDL_Rect*getDes()
	{

		return &m_rDst;

	}

private:

};