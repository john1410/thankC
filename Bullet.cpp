#include "pch.h"
#include "Bullet.h"
#include "Map.h"
#define G -2


Bullet::Bullet(const char* textureSheet, int x, int y, int h, int w, double xv, double yv)
{
	obj = new GameObject(textureSheet, x, y, h, w);
	xvelcoity = xv;
	yvelocity = yv;
}


Bullet::~Bullet()
{
}

void Bullet::update() {
	int x = obj->getx();
	int y = obj->gety();
	if (y < Map::LL[x / WIDTH]) {
		finished = false;
	}
	obj->setPos(x + xvelcoity, y + yvelocity - G * (x / xvelcoity));
	obj->update();
}
void Bullet::render() {
	obj->render();
}
