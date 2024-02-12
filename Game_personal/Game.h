#pragma once
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "TextureManager.h"
#include "SoundManager.h"
#include "Adventurer.h"
//#include "Shapes.h"

class Game {
public:
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool isRunning() ;
	void loadAndPlaySound();

	void zad1();
private:
	Adventurer* adventurer;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	int currentFrame;

	/*SDL_Texture* texture = NULL;
	SDL_Rect sourceRectangle;
	SDL_Rect destinationRectangle;*/
};