#pragma once
#include "Game.h"
#include <string>
#include <map>


class TextureManager {

public:
	bool loadTexture(const char* fileName, std::string id, SDL_Renderer* ren); 
	void drawTexture(std::string id,int x, int y,int width, int height,SDL_Renderer* ren,SDL_RendererFlip flip = SDL_FLIP_NONE);
	//void drawOneFrameFromTexture(std::string id,int x, int y,int width, int height,int currentRow, int currentFrame,SDL_Renderer* ren,SDL_RendererFlip flip = SDL_FLIP_NONE);

	static TextureManager* Instance()
	{
		if (instance == 0)
		{
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}
	void updateRBG(int,int);
	int getRBG1();
	int getRBG2();
	int getRBG3();
private:
	std::map<std::string, SDL_Texture*> textureMap;
	//std::map<std::string, bool> visibility; //helper map for invisible/visible
	TextureManager() {}
	static TextureManager* instance;
	int rbg[3] = { 0,0,0 };
};