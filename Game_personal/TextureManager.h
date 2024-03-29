#pragma once

#include "Game.h"
#include <map>
#include <string>


class TextureManager {
public:
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* renderer);
	void drawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawOneFrameFromTexture(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	static void moveLeftOnButtonPress();

	static TextureManager* Instance() {
		if (instance == 0) {
			instance = new TextureManager();
			return instance;
		}
		else return instance;
	};
	static int x, y;
private:
	std::map<std::string, SDL_Texture*> textureMap;
	TextureManager() {};
	static TextureManager* instance;


};