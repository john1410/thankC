#pragma once
#include "GameManager.h"
class GameObject
{
public:
	GameObject(const char* textureSheet , int x , int y);
	GameObject(const char* textureSheet, int x, int y , int h , int w);
	~GameObject();

	void update();
	void render();
	void renderex(double angle, SDL_RendererFlip sdf= SDL_FLIP_NONE);
	void setPos(int x, int y);
	void setScale(int h, int w);
	void setRatio(float r);
	double move(int vel , double angle);
	int getx() { return xpos; }
	int gety() { return ypos; }
private:
	int xpos;
	int ypos;
	int height;
	int width;
	float ratio;
	SDL_Rect srcRect, destRect;
	SDL_Texture * objTexture;
};

