#include "Adventurer.h"

Adventurer::Adventurer(char const* path, char const* id)
{
	this->path = path;
	this->id = id;
	this->spriteSheetRow = 1;
	this->updateRate = 13;
	this->renderFlip = SDL_FLIP_NONE;
}

void Adventurer::setSpriteSheetRow(int spriteSheetRow)
{
	this->spriteSheetRow = spriteSheetRow;
}

const char* Adventurer::getPath() const
{
	if (this->path != nullptr) return this->path;
	else return nullptr; 
}

const char* Adventurer::getid() const
{
	return this->id;
}

int Adventurer::getSpriteSheetRow() const
{
	return this->spriteSheetRow;
}

int Adventurer::getUpdateRate() const
{
	return this->updateRate;
}

void Adventurer::setUpdateRate(int updateRate)
{
	this->updateRate = updateRate;
}

SDL_RendererFlip Adventurer::getRenderFlip() const
{
	return SDL_RendererFlip(this->renderFlip);
}

void Adventurer::setRenderFlip(int renderFlip)
{
	this->renderFlip = renderFlip % 2;
}
