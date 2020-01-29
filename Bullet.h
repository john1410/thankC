#pragma once
#include "GameManager.h"
#include "GameObject.h"
class Bullet
{
public:
	Bullet(const char* textureSheet, int x, int y, int h, int w , double xv , double yv);
	~Bullet();
	void update();
	void render();
	bool getFinished() { return finished; }
private:
	double xvelcoity;
	double yvelocity;
	bool finished;
	GameObject *obj;
};

