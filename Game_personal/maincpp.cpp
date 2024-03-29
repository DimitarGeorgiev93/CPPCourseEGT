#include "Game.h"
#include <iostream>


using namespace std;

Game* game = NULL;
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 400;

int TextureManager::x = 0;
int TextureManager::y = 0;

int main(int argc, char* argv[]) {
	game = new Game();
	game->init("my new game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
	
	game->loadAndPlaySound();

	while (game->isRunning()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}