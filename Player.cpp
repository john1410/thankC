#include "pch.h"
#include "Player.h"
#include <cmath>


Player::Player(const char * textureSheet, int x, int y, int h, int w) {
	obj = new GameObject(textureSheet, x, y, h, w);
 }
void Player::update() {
	if (isMoving) {
		angle = obj->move(velocity , angle);
	}
	obj->update();
	
}
void Player::render() {
	obj->renderex(angle);
}
void Player::fire(double ang) {
	if (fired < ammo) {
		bullets[fired++] = new Bullet("Asset/bullet.png", obj->getx(), obj->gety(), 8, 8, sin(ang), cos(ang));

	}
}





