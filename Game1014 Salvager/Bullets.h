#ifndef PLAYER_BULLETS
#define PLAYER_BULLETS
#pragma once

#include "Sprite.h"
//here you object class #include "BaseObject.hpp"


const int PLAYER_BULLET_WIDTH = 5;
const int PLAYER_BULLET_HEIGHT = 5;

class PlayerBullet : public Sprite //public BaseObject <==>here you object class
{
public:
	PlayerBullet();
	~PlayerBullet();
	void HandleMove(const int x_border, const int y_border);
	bool GetIsMove() { return ismove; };
	void SetBulletType(int type) { bullettype = type; };
	int GetBulletType() { return bullettype; };
private:
	bool ismove = 1;
	int bullettype = 0;
};
#endif // PLAYER_BULLETS