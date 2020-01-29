#pragma once
#include "GameObject.h"
#include "Bullet.h"
#define ammo 5
class Player
{
public:
	Player(const char* textureSheet, int x, int y, int h, int w);
	~Player();
	void setIsMoving(bool im) { isMoving = im; }
	bool getIsMoving() { return isMoving; }
	int getVelocity() { return velocity; }
	void setVelocity(int v) { velocity = v; }
	GameObject* getobj() { return obj; }
	void render();
	void update();
	void initialize_Bullet(const char* textureSheet, int x, int y, int h, int w);
	void fire(double ang);
private:
	bool isMoving;
	double angle=0;
	int velocity = 0;
	int fired = 0;
	GameObject *obj;
	Bullet *bullet;
	Bullet *bullets[ammo];
};

