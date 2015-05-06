#include "Init.h"
#include "createCursor.h"
#include <iostream>
#include <SDL.h>


int main(int argc, char* args[])
{
	if (!init())
	{
		std::cout << "Failed to initialize.\n";
	}
	else
	{ 
		if (!loadMedia())
		{
			std::cout << "Failed to load media.\n";
		}
		else
		{
			bool quit = false;
			std::cout << "Hiding cursor.\n";
			if (hideCursor())
			{
				std::cout << "Failed to hide cursor.\n";
			}
			else if (!createCursor())
			{
				std::cout << "Failed to create cursor.\n";
			}
			std::cout << "Initializing user input.\n";
			SDL_Event eventHandler;
			gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			while (!quit)
			{
				while (SDL_PollEvent(&eventHandler) != 0)
				{
					if (eventHandler.type == SDL_QUIT)
					{
						quit = true;
					}

					else if ( eventHandler.type == SDL_KEYDOWN )
						switch (eventHandler.key.keysym.sym)
					{
						case SDLK_UP:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							break;
						case SDLK_DOWN:
							gCurrentSurface = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							break;
					}
				}
				SDL_BlitSurface(gCurrentSurface, NULL, gScreenSurface, NULL);
				createCursor();
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return 0;
}
