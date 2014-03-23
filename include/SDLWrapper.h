#ifndef INCLUDE_SDL_H
#define INCLUDE_SDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class SDLWrapper{
	public:
		static bool initialize();
		static void close();
};

#endif // INCLUDE_SDL_H 
