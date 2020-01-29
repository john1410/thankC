#include "pch.h"
#include "GameManager.h"
#include "TextureManager.h"


GameManager *gm = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;


	gm = new GameManager();
	gm->init("tank" , SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , 800 , 640 , false);

	while (gm->running())
	{
		frameStart = SDL_GetTicks();

		gm->handleEvents();
		gm->update();
		gm->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	gm->clean();
	return 0;
}