#pragma once
#include <SDL.h>
#include <SDL_image.h> //png, jpeg, etc
#include "TextureManager.h"
#include "Shapes.h"



class Game {
public:
	
	
	Game();
	~Game();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void handleEvents();
	void update();
	//void update1(); // задача 1
	void render(); 
	void clean(); 

	bool isRunning();
private:
	void limitFPS(Uint32);
	int getRand() const;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	bool running;

	SDL_Texture* texture = NULL;
	SDL_Rect sourceRectangle; 
	SDL_Rect destinationRectangle; 

	int currentFrame; 
};