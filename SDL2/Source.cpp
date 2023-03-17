#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

SDL_Window* win = 0;
SDL_Renderer* ren = 0;

void DeInit(int error)
{
	if (ren != 0) SDL_DestroyRenderer(ren);
	if (win != 0) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}

void Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
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

int main(int argc, char* argv[])
{
	Init();

	system("pause");

	DeInit(0);

	return 0;
}