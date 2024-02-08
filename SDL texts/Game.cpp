//Game.cpp
#include "Game.h"
#include <iostream>

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
	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, clicableTexture, NULL, &clicableRect);
	//std::cout << clicableRect.x << " " << clicableRect.y << " " << clicableRect.w << " " << clicableRect.h << std::endl;
	/*SDL_RenderCopy(renderer, textTextureFont1, NULL, &dRectFont1);
	SDL_RenderCopy(renderer, textTextureFont2, NULL, &dRectFont2);
	SDL_RenderCopy(renderer, textTextureFont1Wrapped, NULL, &dRectFont1Wrapped);
	SDL_RenderCopy(renderer, textTextureFont2Wrapped, NULL, &dRectFont2Wrapped);*/

	SDL_RenderPresent(renderer);
}

void Game::handleEvents() {
	SDL_Event event;
	int msx, msy;
	int msxUp, msyUp;
	int msxD, msyD;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			
			//std::cout << "mouse button down\n";
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msxD, &msyD);
				mouseDownX = msxD;
				mouseDownY = msyD;
				//if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONUP) {
				//	SDL_GetMouseState(&mouseDownX, &mouseDownY);	
				//	/*isClickable(msx, msy);
				//	std::cout << "mouse button up\n" << msx << " " << msy << "\n";*/
				//}
				/*if (isClickableTextureClicked(clicableTexture)) {
					std::cout << " YOU DID IT " << std::endl;
				}*/
				//std::cout << "mouse button down\n" << msx << " " << msy << "\n";
			}
			break;
		case SDL_MOUSEBUTTONUP:
			//int msxUp, msyUP;
			//std::cout << "mouse button down\n";
			if (event.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&msxUp, &msyUp);
				
				if (isClickableTextureClicked(clicableTexture, &clicableRect, mouseDownX, mouseDownY, msxUp, msyUp) == true) {
					std::cout << " YOU DID IT " << std::endl;
				}
				/*isClickable(msx, msy);
				std::cout << "mouse button up\n" << msx << " " << msy << "\n";*/
			}
			//isClickableTextureClicked(clicableTexture, &clicableRect, msxD, msyD, msxUp, msyUp);
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_DOWN) {
				dRectFont1.y += 5;
			}
			
			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
				dRectFont1.y += 5;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
				dRectFont1.x -= 5;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
				dRectFont1.y -= 5;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
				dRectFont1.x += 5;
			}
			break;
		case SDL_MOUSEMOTION:
			//std::cout << event.motion.x  << " " << event.motion.y << "\n";
			//dRectFont2.x = event.motion.x - dRectFont2.w / 2;
			//dRectFont2.y = event.motion.y - dRectFont2.h/2;
			break;
		default: 
			break;
		}
	}
}

void Game::update() {

}

void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::tft_init()
{
	if (TTF_Init() == -1) {
		return false;
	}
	TTF_Font* font1 = TTF_OpenFont("fonts/Arcade.ttf",48);
	TTF_Font* font2 = TTF_OpenFont("fonts/segoepr.ttf", 72);

	if (font1 == nullptr || font2 == nullptr) {
		return false;
	}

	SDL_Surface* tempSurfaceText = TTF_RenderText_Blended(font1,"Hello World!", {0,0,255,255});
	textTextureFont1 = SDL_CreateTextureFromSurface(renderer,tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended(font2, "Hello World!", { 0,255,0,255 });
	textTextureFont2 = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended_Wrapped(font1,"Hello World!\n this wrpas the text", { 0,0,255,255 }, 300);
	textTextureFont1Wrapped = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);

	tempSurfaceText = TTF_RenderText_Blended_Wrapped(font2, "Hello World!\n this wrpas the text", { 0,255,0,255 }, 500);
	textTextureFont2Wrapped = SDL_CreateTextureFromSurface(renderer, tempSurfaceText);


	tempSurfaceText = TTF_RenderText_Blended(font1, "CLICK", { 0,0,255,255 });
	clicableTexture = SDL_CreateTextureFromSurface (renderer, tempSurfaceText);

	int tw, th;
	SDL_QueryTexture(textTextureFont1, 0,0,&tw,&th);
	dRectFont1 = {10,10, tw,th};

	SDL_QueryTexture(textTextureFont2, 0, 0, &tw, &th);
	dRectFont2 = { 10,320, tw,th };

	SDL_QueryTexture(textTextureFont1Wrapped, 0, 0, &tw, &th);
	dRectFont1Wrapped = { 650,10, tw,th };
	SDL_QueryTexture(textTextureFont2Wrapped, 0, 0, &tw, &th);
	dRectFont2Wrapped = { 650,320, tw,th };

	SDL_QueryTexture(clicableTexture,0,0,&tw,&th);
	int ww, wh;
	SDL_GetWindowSize(window,&ww,&wh);
	clicableRect = {(ww-tw)/2, (wh- th)/2 , tw,th};

	SDL_FreeSurface(tempSurfaceText);
	TTF_CloseFont(font1);
	TTF_CloseFont(font2);

	return true;
}

bool Game::isRunning() {
	return Game::running;
}

bool Game::isClickableTextureClicked(SDL_Texture* clicable, SDL_Rect* rec, int xDown, int yDown, int xUp, int yUp)
{
	int tw, th;
	SDL_QueryTexture(clicable, 0,0,&tw, &th);

	if (xDown >= rec->x && xDown <= (rec->x + tw) && (xUp > rec->x && xUp < (rec->x + tw)) && (yDown >= rec->y && (yDown >= rec->y - th)) && (yUp >= rec->y && (yUp >= rec->y - th))){
		return true;
	}

	return false;
}

//bool Game::isClickable( int x, int y)
//{
//	return x >= clicableRect.x && x <= clicableRect.x + clicableRect.w && y >= clicableRect.y && x <= clicableRect.y + clicableRect.h;
//}

Game::Game() {
	Game::window = NULL;
	Game::renderer = NULL;
	Game::running = true;
	//Game::r
}

Game::~Game() {
	delete window;
	delete renderer;
}