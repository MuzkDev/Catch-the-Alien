#include <iostream>
#include <SDL.h>
using namespace std;
int main(int argc, char* args[]) {
	const int screenWidth = 1600;
	const int screenHeight = 900;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		cout << "SDL could not be initialized. Error type:%s\n", SDL_GetError();
		cin.get();
	}
	window = SDL_CreateWindow("Catch the alien", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		cout << "Window could not be created. Error type: %s\n", SDL_GetError();
		cin.get();
	};
	SDL_Delay(5000);
	SDL_DestroyWindow(window);
	SDL_Quit;
	return 0;
}