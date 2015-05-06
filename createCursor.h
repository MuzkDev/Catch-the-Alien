#include <SDL.h>
#include <iostream>

bool createCursor()
{
	SDL_Surface *cursorSurface = NULL;
	SDL_Surface *SDL_DisplayFormat(SDL_Surface *cursorSurface);
	if (!loadSurface("egunCursor.bmp"))
	{
		std::cout << "SDL could not load egunCursor bitmap data. SDL error type: \n" << SDL_GetError() << "\n";
	}
	else 
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		SDL_Rect DestR;
		DestR.x = x;
		DestR.y = y-11;
		cursorSurface = loadSurface("egunCursor.bmp");
		SDL_BlitSurface(cursorSurface, NULL, gScreenSurface, &DestR);
	}
		return true;
}