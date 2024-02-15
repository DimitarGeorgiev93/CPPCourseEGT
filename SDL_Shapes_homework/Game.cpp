#include "Game.h"
#include <iostream>

Game::Game() {
	this->window = NULL;
	this->renderer = NULL;
	this->running = true;
	this->sourceRectangle.x = this->sourceRectangle.y = this->sourceRectangle.w = this->sourceRectangle.h = 0;
	this->destinationRectangle.x = this->destinationRectangle.y = this->destinationRectangle.w = this->destinationRectangle.h = 0;
	this->currentFrame = NULL;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) { 
		std::cout << "SDL init success\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window != 0) //window init success
		{
			std::cout << "window creation success\n";
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) //renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

				TextureManager::Instance()->loadTexture("assets/X.jpg", "X", renderer); 
			}
			else {
				std::cout << "renderer init failed\n";
				return false;
			}
		}
		else {
			std::cout << "window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init fail\n";
		return false;
	}
	std::cout << "init success\n";
	running = true;
	return true;
}

void Game::render() { 
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // set window color
	SDL_RenderClear(renderer);


	//TextureManager::Instance()->drawTexture("X", 0+ TextureManager::x, 0 + TextureManager::y, 50, 50, renderer, SDL_FLIP_NONE);
	

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); //what is the size of this window

	//Коментирайте дадената функция за да не рисува фигурата
	// 
	//draw a circle:
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
	Shapes::drawCircle(renderer, ww / 2, wh / 2, wh / 2 - 10);
	//SDL_RenderPresent(renderer);

	//draw a pentagon
	Shapes::drawPentagon(renderer,ww/2,wh/2, wh / 2 - 10);
	//SDL_RenderPresent(renderer);

	//draw a hexagon
	Shapes::drawHexagon(renderer, ww / 2, wh / 2, wh / 2 +50);
	//SDL_RenderPresent(renderer);

	//draw a rectangle with a border
	Shapes::drawRectangle(renderer, ww / 4, wh / 4, ww / 2, wh / 2, 25);
	SDL_RenderPresent(renderer);

	//draw a elipse
	// WIP
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: 
			running = false; 
			break; 
		default: 
			break;
		}
	}
}

void Game::limitFPS(Uint32 startingTick) {
	if ((1000 / 30) > SDL_GetTicks() - startingTick) {
		SDL_Delay((1000  / 30 ) - (SDL_GetTicks() - startingTick ));
	}
}

int Game::getRand() const
{
	srand(time(NULL));
	return (rand() % 20) + 5;
}

void Game::update() 
{
	/*int w, h;
	SDL_GetWindowSize(window,&w, &h);

	if (TextureManager::position == true) {
		if (destinationRectangle.x+ TextureManager::x < w - 50) {
			TextureManager::x +=  TextureManager::speed;
		}
		else if (destinationRectangle.x + TextureManager::x >= w - 50) {
			TextureManager::position = false;
			int temp = getRand();
			std::cout << temp << std::endl;
			TextureManager::speed = temp;
		}
	}
	else {
		if (destinationRectangle.x + TextureManager::x > 0) {
			TextureManager::x -= TextureManager::speed;
		}
		else if (destinationRectangle.x + TextureManager::x <= 0) {
			TextureManager::position = true;
			int temp = getRand();
			std::cout << temp << std::endl;
			TextureManager::speed = temp;
		}
	}
	int tick = SDL_GetTicks();
	limitFPS(tick);*/
	//we can set currentFrame to achieve the animation effect
	//currentFrame = int(((SDL_GetTicks() / 1000) % 5)); //if we replace 200 with 100 it will be 2x faster // % 5 - so many frames (in Sprite-Sheet.jpg there are 5 (per line))

}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning() {
	return Game::running;
}

Game::~Game() {
	delete window;
	delete renderer;
}