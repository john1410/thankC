#pragma once
#include "GameManager.h"
#include "GameObject.h"
#define HEIGHT 8
#define WIDTH 8
#define W 800/WIDTH
#define H 640/HEIGHT
class Map
{
public:
	Map(const char * texturesheet);
	~Map();
	void loadMap(); //only once at the start of the game;
	void renderMap();
	void loadRandomMap();
	static int LL[W]; // x and y coordinate give x get y;
private:
	GameObject *ground;

};

