#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
class GameManager
{
public:
	GameManager();
	~GameManager();
	void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }
	static SDL_Event event;
	static SDL_Renderer *renderer;
private:
	bool isRunning;
	SDL_Window *window;
};

