#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Adventurer
{
public:
	Adventurer(char const* path, char const* id);

	void setSpriteSheetRow(int);
	const char* getPath() const;
	const char* getid() const;
	int getSpriteSheetRow() const;
	int getUpdateRate() const;
	void setUpdateRate(int);

	SDL_RendererFlip getRenderFlip() const;
	void setRenderFlip( int );
private:
	const char* path;
	const char* id;
	int spriteSheetRow;
	int updateRate;
	int renderFlip;
};

