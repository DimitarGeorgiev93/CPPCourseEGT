#include "TextureManager.h"

#include <ctime>
//int TextureManager::x = 0;
//int TextureManager::y = 0;
//int TextureManager::speed = 5; // starting speed
//bool TextureManager::position = true;


bool TextureManager::loadTexture(const char* fileName, std::string id, SDL_Renderer* ren) {
	SDL_Surface* tempSurface = IMG_Load(fileName);
	if (tempSurface == 0)
		return false;  // if something went wrong
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	if (tex != 0) {
		textureMap[id] = tex;
		//visibility[id] = false;
		return true;
	}

	return false; // if something goes wrong
}

void TextureManager::drawTexture(std::string id, int x, int y, int width, int height, SDL_Renderer* ren, SDL_RendererFlip flip) 
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TextureManager::updateRBG(int x, int y)
{	
	srand(time(NULL));
	int temp = rand() % (x + y +1);
	rbg[1] = rand() % (x +1);
	rbg[2] = rand() % ( y + 1);
}

int TextureManager::getRBG1()
{
	return rbg[0];
}
int TextureManager::getRBG2()
{
	return rbg[1];
}
int TextureManager::getRBG3()
{
	return rbg[2];
}


//void TextureManager::toggleVisibility(std::string id)
//{
//	if (visibility[id] == true) {
//		visibility[id] = false;
//	}
//	else visibility[id] = true;
//}


//void TextureManager::drawOneFrameFromTexture(std::string id, int x, int y,int width, int height, int currentRow, int currentFrame,SDL_Renderer* ren,SDL_RendererFlip flip)
//{
//	SDL_Rect srcRect;
//	SDL_Rect destRect;
//	srcRect.x = width * currentFrame;
//	srcRect.y = height * (currentRow - 1);
//	srcRect.w = destRect.w = width;
//	srcRect.h = destRect.h = height;
//	destRect.x = x;
//	destRect.y = y;
//
//	SDL_RenderCopyEx(ren, textureMap[id], &srcRect, &destRect, 0, 0, flip);
//}

TextureManager* TextureManager::instance = 0;