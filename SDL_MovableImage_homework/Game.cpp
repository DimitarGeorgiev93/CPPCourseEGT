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

				TextureManager::Instance()->loadTexture("assets/1.png", "1", renderer); 
				//TextureManager::Instance()->loadTexture("assets/2.png", "2", renderer);
				//TextureManager::Instance()->loadTexture("assets/3.png", "3", renderer);
				//TextureManager::Instance()->loadTexture("assets/4.png", "4", renderer);
				TextureManager::x = width / 2 - 200;
				TextureManager::y = height / 2 - 150;
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
	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh); //what is the size of this window

	/*if (TextureManager::x == 0 && TextureManager::y == 0) {
		TextureManager::x = ww / 2 - 200;
		TextureManager::y = wh / 2 - 150;
	}*/

	TextureManager::Instance()->drawTexture("1", TextureManager::x, TextureManager::y, 400, 300, renderer, SDL_FLIP_NONE);

	//TextureManager::Instance()->drawTexture("2", ww/2, 0, 400, 300, renderer, SDL_FLIP_NONE);
	//TextureManager::Instance()->drawTexture("3", 0, wh/2, 400, 300, renderer, SDL_FLIP_NONE);
	//TextureManager::Instance()->drawTexture("4", ww/2, wh/2, 400, 300, renderer, SDL_FLIP_NONE);



	////draw 2 lines
	//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	//SDL_RenderDrawLine(renderer, 0, wh / 2, ww, wh / 2);
	//SDL_RenderDrawLine(renderer, ww/2, 0, ww/2, wh);


	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT: 
			running = false; 
			break; 
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&TextureManager::x, &TextureManager::y);
			TextureManager::x -= 200;
			TextureManager::y -= 150;
			break;
		case SDL_KEYDOWN:
			int ww, wh;
			SDL_GetWindowSize(window, &ww, &wh);
			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN && TextureManager::y + 1 + 300 <= wh) {
				TextureManager::y += 1;
				std::cout << "y: " << TextureManager::y << std::endl;
				break;
			} else if (event.key.keysym.scancode == SDL_SCANCODE_UP && TextureManager::y - 1  >= 0) {
				TextureManager::y -= 1;
				std::cout << "y: " << TextureManager::y << std::endl;
				break;
			} else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT && TextureManager::x - 1  >= 0) {
				TextureManager::x -= 1;
				std::cout << "x: " << TextureManager::x << std::endl;
				break;
			} else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT && TextureManager::x + 1 + 400 <= ww) {
				TextureManager::x += 1;
				std::cout << "x: " << TextureManager::x << std::endl;
				break;
			}
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