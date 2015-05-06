#include <SDL.h>
#include <iostream>
const int wWidth = 1600;
const int wHeight = 900;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image. SDL error type:\n" << path.c_str() << SDL_GetError();
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
};
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};
SDL_Surface* gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];
SDL_Surface* gCurrentSurface = NULL;
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL could not INIT_EVERYTHING! SDL error type: \n" << SDL_GetError() << "\n";
	}
	else
	{
		std::cout << "Initializing engine.\n";
		gWindow = SDL_CreateWindow("Catch the alien", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wWidth, wHeight, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			std::cout << "SDL could not CreateWindow. SDL error type: \n" << SDL_GetError() << "\n";
			success = false;
		}
		else
			std::cout << "Initializing window.\n";
			gScreenSurface = SDL_GetWindowSurface(gWindow);
	}
	return success;
}
bool hideCursor()
{
	SDL_ShowCursor(SDL_DISABLE);
	return 0;
}
bool loadMedia()
{
	std::cout << "Loading assets...\n";
	bool success = true;
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("mainMenu.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		std::cout << "Failed to load mainMenu.bmp\n";
		success = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("mainMenuUp.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		std::cout << "Failed to load mainMenuUp.bmp\n";
		success = false;
	}
	gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] = loadSurface("mainMenuDown.bmp");
	if (gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		std::cout << "Failed to load mainMenuDown.bmp\n";
		success = false;
	}
	return success;
}
void close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}
