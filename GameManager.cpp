#include "pch.h"
#include "GameManager.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Player.h"

Player * player;
Map * map;
int cnt = 0;

SDL_Renderer* GameManager::renderer = nullptr;
SDL_Event GameManager::event;
GameManager::GameManager()
{
}


GameManager::~GameManager()
{
}

void GameManager::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) 
{
	cnt = 0;
	int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) 
	{
		std::cout << "Subsystems has been Initialized" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) std::cout << "Window has been Created " << std::endl;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			std::cout << "Renderer has been Created" << std::endl;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	player = new Player("Asset/tank.png",  0 , 9*HEIGHT , 256 , 256);
	player->getobj()->setRatio(0.25);
	player->initialize_Bullet("Asset/bullet.png", 0, 0, 8, 8);
	map = new Map("Asset/ground2.png");
	map->loadRandomMap();
}

void GameManager::handleEvents()
{
	//arrow right 79 , arrow left 80
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.scancode == 80) {
			player->setIsMoving(true);
			player->setVelocity(-1);
		}
		if (event.key.keysym.scancode == 79) {
			player->setIsMoving(true);
			player->setVelocity(1);
		}
		break;
	case SDL_KEYUP:
		if (event.key.keysym.scancode == 80) {
			player->setIsMoving(false);
			player->setVelocity(0);
		}
		if (event.key.keysym.scancode == 79) {
			player->setIsMoving(false);
			player->setVelocity(0);
		}
		break;
	default:
		break;
	}
}

void GameManager::update() 
{
	player->update();
}
void GameManager::render()
{
	SDL_RenderClear(renderer);
	map->renderMap();
	player->render();
	SDL_RenderPresent(renderer);
}

void GameManager::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game has been Cleaned" << std::endl;
}


