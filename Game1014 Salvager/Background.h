#pragma once

#include "Sprite.h"

class Background : public Sprite
{

public:

	Background();
	~Background();
	Background(int x, int y);
	void sideScroll();
	SDL_Surface* m_pBackgroundSurface;

private:

	int temp = 0;

};
