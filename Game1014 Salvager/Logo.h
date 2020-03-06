#pragma once

#include "Classes.h"

class Logo: public SPRITE
{

public:

	Logo()
	{

		m_rSrc.x = 0;
		m_rSrc.y = 0;
		m_rSrc.w = 500;
		m_rSrc.h = 300;

		m_rDst.x = 524/2;
		m_rDst.y = 468/2;
		m_rDst.w = 500;
		m_rDst.h = 300;

	}

private:

};
