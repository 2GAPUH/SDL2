#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define Pi 3.14

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

void DeInit(int error)
{
	if (ren != NULL) SDL_DestroyRenderer(ren);
	if (win != NULL) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}

void Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != NULL)
	{
		printf_s("Can't init SDL2! Error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}

	win = SDL_CreateWindow("It's work!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (win == NULL)
	{
		printf_s("Can't create Window! Error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL)
	{
		printf_s("Can't create renderer! Error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
}

//Принимает смещение по иксу, игрику считая от центра окна и размер оси
void DrawAxis(int xOffset, int yOffset, double size = 1)
{
	//Draw ordinate
	SDL_RenderDrawLine(ren, WINDOW_WIDTH / 2 + xOffset, WINDOW_HEIGHT / 2 + yOffset, WINDOW_WIDTH / 2 + xOffset, int((WINDOW_HEIGHT / 2) + 100 * size) + yOffset);
	SDL_RenderDrawLine(ren, WINDOW_WIDTH / 2 + xOffset, WINDOW_HEIGHT / 2 + yOffset, WINDOW_WIDTH / 2 + xOffset, int((WINDOW_HEIGHT / 2) - 100 * size) + yOffset);

	//Draw abscissa
	SDL_RenderDrawLine(ren, WINDOW_WIDTH / 2 + xOffset, WINDOW_HEIGHT / 2 + yOffset, int((WINDOW_WIDTH / 2) + 100 * size) + xOffset, WINDOW_HEIGHT / 2 + yOffset);
	SDL_RenderDrawLine(ren, WINDOW_WIDTH / 2 + xOffset, WINDOW_HEIGHT / 2 + yOffset, int((WINDOW_WIDTH / 2) - 100 * size) + xOffset, WINDOW_HEIGHT / 2 + yOffset);
}


//Принимает смещение по иксу, игрику считая от центра окна и размер окружности
void DrawCircle(int xOffset, int yOffset, double size = 1)
{
	double x, y;
	int r = 150 * size;
	for (double i = 0; i < 360; i+= 0.01/size)
	{
		x = r * cos(i);
		y = r * sin(i);
		SDL_RenderDrawPoint(ren, x + WINDOW_WIDTH/2 + xOffset, y+ WINDOW_HEIGHT /2 + yOffset);
	}
}

//Принимает смещение по иксу, игрику считая от центра окна и размер окружности
void DrawFillCircle(int xOffset, int yOffset, double size = 1)
{
	double x, y;
	int r = 150 * size;
	for (double i = 0; i < 360; i += 0.03 / size)
	{
		x = r * cos(i);
		y = r * sin(i);
		SDL_RenderDrawLine(ren, x + WINDOW_WIDTH / 2 + xOffset, y + WINDOW_HEIGHT / 2 + yOffset, -x + WINDOW_WIDTH / 2 + xOffset, -y + WINDOW_HEIGHT / 2 + yOffset);
		//SDL_RenderDrawPoint(ren, x + WINDOW_WIDTH / 2 + xOffset, y + WINDOW_HEIGHT / 2 + yOffset);
	}
}


int main(int argc, char* argv[])
{
	int xOffset = 0, yOffset = 0;

	Init();

	SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);
	SDL_RenderClear(ren);
	SDL_RenderPresent(ren);



	SDL_RenderPresent(ren);

	system("pause");

	DeInit(0);

	return 0;
}