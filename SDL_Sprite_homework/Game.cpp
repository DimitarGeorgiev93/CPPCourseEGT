#include "Game.h"

int c = 1;
Game::Game()
{
	this->window = nullptr;
	this->renderer = nullptr;
	this->running = true;
	this->currentFrame = 0;
	//adventurer = new Adventurer("assets/images/ss1.png","adventurer");
	adventurer = new Adventurer("assets/images/ss2.png", "adventurer");
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window != 0) {

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer != 0) {
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				
				//TextureManager::Instance()->loadTexture("assets/ss1.png","png", renderer);
				TextureManager::Instance()->loadTexture( adventurer->getPath(), adventurer->getid(), renderer);
				adventurer->setUpdateRate(8);
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	this->running = true;

	return true;
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	int ww, wh;
	SDL_GetWindowSize(window, &ww, &wh);

	
	/*TextureManager::Instance()->drawOneFrameFromTexture("adventurer", ww/2 - 16 , wh/2 - 16 , 32, 32, 
		this->adventurer->getSpriteSheetRow(), currentFrame, renderer, this->adventurer->getRenderFlip());*/
	TextureManager::Instance()->drawOneFrameFromTexture("adventurer", ww/2-48, wh / 2 - 48, 96, 96,
		this->adventurer->getSpriteSheetRow(), currentFrame, renderer, this->adventurer->getRenderFlip());

	SDL_RenderPresent(renderer);
	
}

void Game::update()
{

	currentFrame = int(((SDL_GetTicks()/100)%this->adventurer->getUpdateRate()));
	SDL_Delay(100);
	std::cout << "currentImage " << currentFrame;
		std::cout << "currentRow " << this->adventurer->getSpriteSheetRow() << std::endl;
	if (currentFrame == 7) {
		adventurer->setSpriteSheetRow(c);
		c ++;
	} 
	if (c == 9) c = 1;
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		//case SDL_KEYDOWN:
			//int ww, wh;
			//SDL_GetWindowSize(window, &ww, &wh);
			//
			//if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
			//	adventurer->setSpriteSheetRow(2);
			//	adventurer->setUpdateRate(8);
			//	//adventurer->setRenderFlip(0);
			//	if (TextureManager::y < 185) {
			//		TextureManager::y += 5;
			//	}
			//	//dRectFont1.y -= 5;
			//}
			//if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
			//	adventurer->setSpriteSheetRow(2);
			//	adventurer->setUpdateRate(8);
			//	//adventurer->setRenderFlip(0);
			//	if (TextureManager::y > -195) {
			//		TextureManager::y -= 5;
			//	}
			//	/*std::cout << "Attack" << std::endl;
			//	adventurer->setSpriteSheetRow( rand()%3 + 3);
			//	adventurer->setUpdateRate(10);*/
			//}
			//if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
			//	//dRectFont1.x -= 5;
			//	adventurer->setSpriteSheetRow(2);
			//	adventurer->setUpdateRate(8);
			//	adventurer->setRenderFlip(1);
			//	if (TextureManager::x > -295) {
			//		TextureManager::x -= 5;
			//	}
			//}
			//if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
			//	//dRectFont1.x += 5;
			//	adventurer->setSpriteSheetRow(2);
			//	adventurer->setUpdateRate(8);
			//	adventurer->setRenderFlip(0);
			//	if(TextureManager::x < 295) {
			//		TextureManager::x += 5;
			//	}
			//}
			//break;
		default:
			//adventurer->setSpriteSheetRow(1);
			adventurer->setUpdateRate(8);
			break;
		}
	}
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::isRunning()
{
	return this->running;
}

void Game::loadAndPlaySound()
{
	SoundManager::Instance()->load("assets/sounds/rf-16.mp3", "bg_music", 1);
	/*SoundManager::Instance()->load("assets/gamer-213.wav", "game_over", 0);
	SoundManager::Instance()->load("assets/noti-212.wav", "notification", 0);
	SoundManager::Instance()->load("assets/woosh-89.wav", "woosh", 0);
	SoundManager::Instance()->load("assets/switch-15.mp3", "switch", 0);*/

	SoundManager::Instance()->playMusic("bg_music", -1, 5000);
	//SoundManager::Instance()->playSound("game_over",-1,0);
	//SoundManager::Instance()->playSound("woosh", -1, 0);
	//SoundManager::Instance()->playSound("switch", -1, 0);
	//SoundManager::Instance()->playSound("notification", -1, 0);
}


