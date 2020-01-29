#include "pch.h"
#include "TextureManager.h"


SDL_Texture* TextureManager::loadTexture(const char* filename)
{
	SDL_Surface* surfaceTemp = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(GameManager::renderer , surfaceTemp);
	SDL_FreeSurface(surfaceTemp);
	return texture;
}
void TextureManager::draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(GameManager::renderer,tex, &src, &dest);
}
