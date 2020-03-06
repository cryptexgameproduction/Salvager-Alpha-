#pragma once

#include "Classes.h"

class LevelChange : public SPRITE
{

public:

	LevelChange() {

	}

	LevelChange(int x, int y, int w, int h)
	{

		m_rDst.x = x;
		m_rDst.y = y;
		m_rDst.w = w;
		m_rDst.h = h;

	}

private:


};
