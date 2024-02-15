#pragma once
#include"Game.h"

class Shapes
{
public:
	static void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius);
	static void drawPentagon(SDL_Renderer* renderer, int centerX, int centerY, int side);
	static void drawHexagon(SDL_Renderer* renderer, int centerX, int centerY, int side);
	static void drawRectangle(SDL_Renderer* renderer, int centerX, int centerY, int width, int heigth, int borderW);
	static void drawElipse(SDL_Renderer* renderer, double centerX, double centerY, double a, double b);
};

