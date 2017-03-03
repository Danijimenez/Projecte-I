#include "include/SDL.h"
#include <stdlib.h>
#include <iostream>

#pragma comment( lib, "lib/SDL2.lib")
#pragma comment(lib, "lib/SDL2main.lib")

using namespace std;

int main(int argc, char*  args[]) {

	SDL_Window* win = NULL;
	SDL_Renderer* render = NULL;
	SDL_Rect MyRect;

	SDL_Init(SDL_INIT_VIDEO);

	win = SDL_CreateWindow("Prueba con cubo azul", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(render, 255, 0, 0, 255);

	SDL_RenderClear(render);

		MyRect.x = 50;
		MyRect.y = 50;
		MyRect.w = 300;
		MyRect.h = 300;

		SDL_SetRenderDrawColor(render, 0, 0, 255, 255);

		SDL_RenderFillRect(render, &MyRect);

		SDL_RenderPresent(render);
		while (1 == 1) {

		}
		SDL_Delay(5000);
		SDL_DestroyWindow(win);
		SDL_Quit();


	return EXIT_SUCCESS;
}