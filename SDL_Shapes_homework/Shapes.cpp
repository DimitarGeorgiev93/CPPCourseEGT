#include "Shapes.h"

//const double pi = 3.14;

void Shapes::drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) { // Midpoint Circle Algorithm
	const int diameter = radius * 2;
	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y) {
		SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
		SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
		SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);
		if (error <= 0) {
			y++;
			error += ty;
			ty += 2;
		}
		if (error > 0) {
			x--;
			tx += 2;
			error += tx - diameter;
		}
	}
}

void Shapes::drawPentagon(SDL_Renderer* renderer, int centerX, int centerY, int side)
{
	

	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

	double r = side / (2 * sin(M_PI / 5));
	std::pair<int, int> points[5];

	// Calculate coordinates of the first point (starting from the positive x-axis direction)
	points[0].first = centerX + r;
	points[0].second = centerY;

	// Calculate coordinates of the other points by rotating around the center
	
	for (int i = 1; i < 5; ++i) {
		double angle = (2 * M_PI / 5) * i;
		points[i].first = centerX + r * cos(angle);
		points[i].second = centerY + r * sin(angle);
	}

	SDL_RenderDrawLine(renderer, points[0].first, points[0].second, points[1].first, points[1].second);
	SDL_RenderDrawLine(renderer, points[1].first, points[1].second, points[2].first, points[2].second);
	SDL_RenderDrawLine(renderer, points[2].first, points[2].second, points[3].first, points[3].second);
	SDL_RenderDrawLine(renderer, points[3].first, points[3].second, points[4].first, points[4].second);
	SDL_RenderDrawLine(renderer, points[4].first, points[4].second, points[0].first, points[0].second);

}

void Shapes::drawHexagon(SDL_Renderer* renderer, int centerX, int centerY, int side)
{
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);

	double r = side / (2 * sin(M_PI / 5));
	std::pair<int, int> points[6];

	// Calculate coordinates of the first point (starting from the positive x-axis direction)
	points[0].first = centerX + r;
	points[0].second = centerY;

	// Calculate coordinates of the other points by rotating around the center

	for (int i = 1; i < 6; ++i) {
		double angle = (M_PI / 3) * i;
		points[i].first = centerX + r * cos(angle);
		points[i].second = centerY + r * sin(angle);
	}

	SDL_RenderDrawLine(renderer, points[0].first, points[0].second, points[1].first, points[1].second);
	SDL_RenderDrawLine(renderer, points[1].first, points[1].second, points[2].first, points[2].second);
	SDL_RenderDrawLine(renderer, points[2].first, points[2].second, points[3].first, points[3].second);
	SDL_RenderDrawLine(renderer, points[3].first, points[3].second, points[4].first, points[4].second);
	SDL_RenderDrawLine(renderer, points[4].first, points[4].second, points[5].first, points[5].second);
	SDL_RenderDrawLine(renderer, points[5].first, points[5].second, points[0].first, points[0].second);
}

void Shapes::drawRectangle(SDL_Renderer* renderer, int centerX, int centerY, int width, int heigth, int borderW)
{
	SDL_Rect rect1 = {centerX, centerY , width, heigth};
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect1);

	SDL_Rect rect2 = { centerX + borderW, centerY + borderW ,width - (borderW * 2), heigth - (borderW * 2) };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect2);
}

void Shapes::drawElipse(SDL_Renderer* renderer, double centerX, double centerY, double a, double b)
{
	//..
}

