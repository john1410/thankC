#include "pch.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Map.h"
#include <cmath>

GameObject::GameObject(const char * textureSheet ,  int x , int y)
{
	objTexture = TextureManager::loadTexture(textureSheet);
	xpos = x;
	ypos = y;
	ratio = 1.0;
}

GameObject::GameObject(const char * textureSheet, int x, int y , int h , int w)
{
	objTexture = TextureManager::loadTexture(textureSheet);
	xpos = x;
	ypos = y;
	height = h;
	width = w;
	ratio = 1.0;
}


GameObject::~GameObject()
{
}
void GameObject::setPos(int x, int y) {
	xpos = x;
	ypos = y;
}
void GameObject::setScale(int h, int w) {
	height = h;
	width = w;
}
void GameObject::setRatio(float r) {
	ratio = r;
}
void GameObject::update()
{

	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = (int)(height*ratio);
	destRect.w = (int)(width*ratio);

}
void GameObject::render()
{
	SDL_RenderCopy(GameManager::renderer, objTexture, &srcRect, &destRect);
}
void GameObject::renderex(double angle , SDL_RendererFlip sdf)
{
	SDL_Point * center = new SDL_Point();
	center->x = destRect.x + destRect.w / 2;
	center->y = destRect.y + destRect.h / 2;
	SDL_RenderCopyEx(GameManager::renderer, objTexture, &srcRect, &destRect , angle , NULL ,sdf );
}
double GameObject::move(int vel , double angle) {
	xpos += vel;
	if ((xpos - vel)/WIDTH < (xpos+WIDTH/2)/WIDTH) {
		ypos = (Map::LL[xpos / WIDTH] - 8)*HEIGHT;
		angle = atan(Map::LL[xpos/WIDTH] - Map::LL[(xpos - 1)/WIDTH]) * 180 / 3.1415;
	}
	return angle;
}

