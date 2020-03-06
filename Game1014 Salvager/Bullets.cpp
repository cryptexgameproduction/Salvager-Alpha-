#include "Bullets.h"

PlayerBullet::PlayerBullet() {
	rect_.w = ENEMY_BULLETWIDTH;
	rect.h = ENEMY_BULLET_HEIGHT;
}
PlayerBullet::~PlayerBullet() {}


void PlayerBullet::HandleMove(int x_border, int yborder) {

	// this case bullet is straight forward

	rect.y -= 20;
	if (rect_.y > y_border) {
		ismove = false;
	}

}