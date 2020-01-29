#include "pch.h"
#include "Map.h"
#include <time.h>
#include <cmath>

int Map::LL[W];
Map::Map(const char *texturesheet)
{
	ground = new GameObject(texturesheet, 0, 0);
	ground->setScale(HEIGHT, WIDTH);
	
}


Map::~Map()
{
}

void Map::loadMap() {

}
void Map::loadRandomMap() {
	std::cout << "In random map" << std::endl;
	LL[0] = 20+rand() % H;
	int dif = 1;
	for (int i = 1;i < W;) {
		int nextPos = rand() % H;
		if (abs(nextPos - LL[i - 1]) <= dif && nextPos < H) {
			LL[i++] = nextPos;
			std::cout << "(" << i << " , " << LL[i-1] << ")" << std::endl;
		}
		//std::cout << LL[i - 1] << std::endl;
	}
	//srand(time(NULL));
	std::cout << "h : " << H << " w : " << W << " rand : " << rand() % H << std::endl;
	std::cout << "Load Random Map completed" << std::endl;
	
}
//TODO : check for load*Map
void Map::renderMap() {
	for (int i = 0;i < W;i++) {
		ground->setPos(i*WIDTH, LL[i]*HEIGHT);
		ground->update();
		double angle = 0;
		if (i != 0)
			angle = atan(LL[i] - LL[i-1]) * 180 / 3.1415;
		ground->renderex(angle);
	}
	//std::cout << "--------end of draw-----------" << std::endl;
}
